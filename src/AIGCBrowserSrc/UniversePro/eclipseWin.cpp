/*******************************************************************************
 * Copyright (c) 2000, 2010 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *     Kevin Cornell (Rational Software Corporation)
 *     Holger Voormann - fix for bug 384950 (http://eclip.se/384950)
 *******************************************************************************/
 /********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web pages,
 *    which are composed of standard DOM elements and binary components supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet based
 *    on modern javscript/Web technology.
// Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 *******************************************************************************/

 //Bug 498758 - Move launcher to Java 6 

#include "stdafx.h"
#include "UniverseApp.h"
#include "Cosmos.h"
#include "eclipseOS.h"
#include "eclipseUtil.h"
#include "eclipseCommon.h"
#include "eclipseJNI.h"
#include "eclipseShm.h"
#include "EclipsePlus\EclipseAddin.h"

#include <windows.h>
#include <commctrl.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#ifdef __MINGW32__
#include <stdlib.h>
#endif
#pragma comment(lib,"Version.lib")
extern HWND topWindow;

/* Global Variables */
_TCHAR* defaultVM = (_TCHAR*)_T("javaw.exe");
_TCHAR* consoleVM = (_TCHAR*)_T("java.exe");
_TCHAR* vmLibrary = (_TCHAR*)_T("jvm.dll");
_TCHAR* shippedVMDir = (_TCHAR*)_T("jre\\bin\\");

/* Define local variables for communicating with running eclipse instance. */
static HANDLE	_mutex;
static UINT		findWindowTimeout = 1000;
static UINT_PTR findWindowTimerId = 97;
static UINT		timerCount = 0;
static UINT		openFileTimeout = 60;
static _TCHAR** openFilePath;

/* Define the window system arguments for the Java VM. */
static _TCHAR* argVM[] = { NULL };

/* Define local variables for running the JVM and detecting its exit. */
static HANDLE  jvmProcess = 0;
static JavaResults* jvmResults = NULL;
static UINT    jvmExitTimeout = 100;
static UINT_PTR jvmExitTimerId = 99;

static void CALLBACK findWindowProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);
static void CALLBACK  detectJvmExit(HWND hwnd, UINT uMsg, UINT id, DWORD dwTime);
_TCHAR* checkVMRegistryKey(HKEY jrekey, _TCHAR* subKeyName);
static void adjustSearchPath(_TCHAR* vmLibrary);
static _TCHAR* findLib(_TCHAR* command);

/* define default locations in which to find the jvm shared library
 * these are paths relative to the java exe, the shared library is
 * for example jvmLocations[0] + dirSeparator + vmLibrary */
#define MAX_LOCATION_LENGTH 25 /* none of the jvmLocations strings should be longer than this */ 
static const _TCHAR* jvmLocations[] = { _T("j9vm"), _T("..\\jre\\bin\\j9vm"),
										 _T("client"), _T("..\\jre\\bin\\client"),
										 _T("server"), _T("..\\jre\\bin\\server"),
										 _T("classic"), _T("..\\jre\\bin\\classic"),
										 _T("jrockit"), _T("..\\jre\\bin\\jrockit"),
										 NULL };

/* for detecting sun vms */
typedef struct {
	WORD language;
	WORD codepage;
} TRANSLATIONS;

#define PRODUCT_VERSION_KEY _T_ECLIPSE("\\StringFileInfo\\%04x%04x\\ProductVersion")

static void sendOpenFileMessage(HWND window) {
	_TCHAR* id{};
	UINT msg;
	int index = 0;
	int size = 0;
	DWORD wParam;
#ifdef _WIN64
	DWORDLONG lParam;
#else
	DWORD lParam;
#endif

	/* what's the longest path? */
	while (openFilePath[index] != NULL) {
		int length = _tcslen(openFilePath[index++]);
		if (size <= length)
			size = length + 1;
	}
	createSharedData(&id, size * sizeof(_TCHAR));
	_stscanf(id, _T_ECLIPSE("%lx_%lx"), (unsigned long*)&wParam, (unsigned long*)&lParam);
	msg = RegisterWindowMessage(_T("SWT_OPENDOC"));

	index = 0;
	for (index = 0; openFilePath[index] != NULL; index++) {
		/* SendMessage does not return until the message has been processed */
		setSharedData(id, openFilePath[index]);
		SendMessage(window, msg, wParam, lParam);
	}
	destroySharedData(id);
	free(id);
	SetForegroundWindow(window);
}

static HWND findSWTMessageWindow() {
	HWND window = NULL;
	_TCHAR* windowTitle, * windowPrefix, * name;

	windowPrefix = (_TCHAR*)_T("SWT_Window_");
	name = getOfficialName();
	windowTitle = (_TCHAR*)malloc((_tcslen(windowPrefix) + _tcslen(name) + 1) * sizeof(_TCHAR));
	_stprintf(windowTitle, _T_ECLIPSE("%s%s"), windowPrefix, name);
	window = FindWindow(NULL, windowTitle);
	free(windowTitle);
	return window;
}

static void CALLBACK findWindowProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime) {
	HWND window = findSWTMessageWindow();
	if (window != NULL) {
		sendOpenFileMessage(window);
		ReleaseMutex(_mutex);
		CloseHandle(_mutex);
		KillTimer(hwnd, findWindowTimerId);
		return;
	}

	/* no window yet, set timer to try again later */
	if (timerCount++ >= openFileTimeout) {
		KillTimer(hwnd, findWindowTimerId);
		ReleaseMutex(_mutex);
		CloseHandle(_mutex);
	}
}

/* return > 0 if we successfully send a message to another eclipse instance */
int reuseWorkbench(_TCHAR** filePath, int timeout) {
	_TCHAR* mutexPrefix = (_TCHAR*)_T("SWT_Mutex_");
	_TCHAR* mutexName, * name;
	DWORD 	  lock;
	HWND 	  window = NULL;

	/* store for later */
	openFilePath = filePath;
	openFileTimeout = timeout;

	name = getOfficialName();
	mutexName = (_TCHAR*)malloc((_tcslen(mutexPrefix) + _tcslen(name) + 1) * sizeof(_TCHAR));
	_stprintf(mutexName, _T_ECLIPSE("%s%s"), mutexPrefix, name);
	_mutex = CreateMutex(NULL, FALSE, mutexName);
	free(mutexName);
	if (_mutex == NULL) return -1;

	//wait for timeout seconds
	lock = WaitForSingleObject(_mutex, timeout * 1000);
	if (lock != WAIT_OBJECT_0) {
		/* failed to get the lock before timeout, We won't be reusing an existing eclipse. */
		CloseHandle(_mutex);
		return 0;
	}

	/* we have the mutex, look for the SWT window */
	window = findSWTMessageWindow();
	if (window != NULL) {
		sendOpenFileMessage(window);
		ReleaseMutex(_mutex);
		CloseHandle(_mutex);
		return 1; /* success! */
	}

	/* no window, set a timer to look again later */
	if (initWindowSystem(0, NULL, 0) == 0)
		SetTimer(topWindow, findWindowTimerId, findWindowTimeout, (TIMERPROC)findWindowProc);

	return 0;
}

/* Show the Splash Window
 *
 * Open the bitmap, insert into the splash window and display it.
 *
 */

int showSplash(const _TCHAR* featureImage)
{
	static int splashing = 0;
	HBITMAP hBitmap = 0;
	BITMAP  bmp;
	HDC     hDC;
	int     depth;
	int     x, y;
	int     width, height;
	int     dpiX, scaledWidth, scaledHeight;

	if (splashing) {
		/*splash screen is already showing, do nothing */
		return 0;
	}

	if (featureImage == NULL)
		return -1;

	/* if Java was started first and is calling back to show the splash, we might not
	 * have initialized the window system yet
	 */

	initWindowSystem(0, NULL, 1);

	/* Load the bitmap for the feature. */
	hDC = GetDC(NULL);
	depth = GetDeviceCaps(hDC, BITSPIXEL) * GetDeviceCaps(hDC, PLANES);

	/* fetch screen DPI and round it to 100% multiples,
	this implementation needs to be kept in sync with org.eclipse.swt.internal.DPIUtil#setDeviceZoom(int) */
	dpiX = GetDeviceCaps(hDC, LOGPIXELSX);
	dpiX = ((int)((dpiX + 24) / 96)) * 96;

	ReleaseDC(NULL, hDC);
	if (featureImage != NULL)
		hBitmap = (HBITMAP)LoadImage(NULL, featureImage, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	/* If the bitmap could not be found, return an error. */
	if (hBitmap == 0)
		return ERROR_FILE_NOT_FOUND;

	GetObject(hBitmap, sizeof(BITMAP), &bmp);

	/* reload scaled up image when zoom > 100% */
	if (dpiX > 96) {
		/* calculate scaled-up bounds */
		scaledWidth = dpiX * bmp.bmWidth / 96;
		scaledHeight = dpiX * bmp.bmHeight / 96;

		hBitmap = (HBITMAP)LoadImage(NULL, featureImage, IMAGE_BITMAP, scaledWidth, scaledHeight, LR_LOADFROMFILE);

		/* If the bitmap could not be found, return an error. */
		if (hBitmap == 0)
			return ERROR_FILE_NOT_FOUND;

		GetObject(hBitmap, sizeof(BITMAP), &bmp);
	}

	/* figure out position */
	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);
	x = (width - bmp.bmWidth) / 2;
	y = (height - bmp.bmHeight) / 2;

	/* Centre the splash window and display it. */
	SetWindowPos(topWindow, 0, x, y, bmp.bmWidth, bmp.bmHeight, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
	SendMessage(topWindow, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
	ShowWindow(topWindow, SW_SHOW);
	BringWindowToTop(topWindow);
	splashing = 1;

	/* Process messages */
	//dispatchMessages();
	return 0;
}

void dispatchMessages() {
	MSG     msg;

	if (topWindow == 0)
		return;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

jlong getSplashHandle() {
	return (jlong)topWindow;
}

void takeDownSplash() {
	if (topWindow != NULL) {
		DestroyWindow(topWindow);
		dispatchMessages();
		topWindow = 0;
	}
}

/* Get the window system specific VM args */
_TCHAR** getArgVM(_TCHAR* vm)
{
	return argVM;
}

/* Local functions */

_TCHAR* findVMLibrary(_TCHAR* command) {
	_TCHAR* lib = findLib(command);
	if (lib != NULL) {
		adjustSearchPath(lib);
	}
	return lib;
}

void adjustSearchPath(_TCHAR* vmLib) {
	_TCHAR** paths;
	_TCHAR* cwd = NULL;
	_TCHAR* path = NULL, * newPath = NULL;
	_TCHAR* c;
	int i, length;
	int needAdjust = 0, freePath = 0;

	paths = getVMLibrarySearchPath(vmLib);

	/* bug 325902 - add current working dir to the end of the search path */
	length = GetCurrentDirectory(0, NULL);
	cwd = (_TCHAR*)malloc((length + 1) * sizeof(_TCHAR));
	GetCurrentDirectory(length, cwd);
	cwd[length - 1] = pathSeparator;
	cwd[length] = 0;

	/* first call to GetEnvironmentVariable tells us how big to make the buffer */
	length = GetEnvironmentVariable(_T("PATH"), path, 0);
	if (length > 0) {
		_TCHAR* current[] = { cwd, NULL };
		path = (_TCHAR*)malloc(length * sizeof(_TCHAR));
		GetEnvironmentVariable(_T("PATH"), path, length);
		needAdjust = !containsPaths(path, paths) || !containsPaths(path, current);
		freePath = 1;
	}
	else {
		path = (_TCHAR*)_T("");
		freePath = 0;
		needAdjust = 1;
	}

	if (needAdjust) {
		c = concatStrings(paths);
		newPath = (_TCHAR*)malloc((_tcslen(c) + length + 1 + _tcslen(cwd) + 1) * sizeof(_TCHAR));
		_stprintf(newPath, _T("%s%s%c%s"), c, path, pathSeparator, cwd);
		SetEnvironmentVariable(_T("PATH"), newPath);
		free(c);
		free(newPath);
	}

	for (i = 0; paths[i] != NULL; i++)
		free(paths[i]);
	free(paths);
	free(cwd);
	if (freePath)
		free(path);
}
/*
 * Find the VM shared library starting from the java executable
 */
static _TCHAR* findLib(_TCHAR* command) {
	int i, j;
	size_t pathLength;
	struct _stat stats;
	_TCHAR* path;				/* path to resulting jvm shared library */
	_TCHAR* location;			/* points to begining of jvmLocations section of path */

	/* for looking in the registry */
	HKEY jreKey = NULL;
	DWORD length = MAX_PATH;
	_TCHAR keyName[MAX_PATH];
	_TCHAR* jreKeyName;

	if (command != NULL) {
		location = lastDirSeparator(command) + 1;

		/*check first to see if command already points to the library */
		if (isVMLibrary(command)) {
			if (_tstat(command, &stats) == 0 && (stats.st_mode & S_IFREG) != 0)
				return command; 	/* exists */
			return NULL; /* doesn't exist */
		}

		pathLength = (size_t)(location - command);
		path = (_TCHAR*)malloc((pathLength + MAX_LOCATION_LENGTH + 1 + _tcslen(vmLibrary) + 1) * sizeof(_TCHAR));
		_tcsncpy(path, command, pathLength);
		location = &path[pathLength];

		/*
		 * We are trying base/jvmLocations[*]/vmLibrary
		 * where base is the directory containing the given java command, normally jre/bin
		 */
		i = -1;
		while (jvmLocations[++i] != NULL) {
			_stprintf(location, _T_ECLIPSE("%s%c%s"), jvmLocations[i], dirSeparator, vmLibrary);
			if (_tstat(path, &stats) == 0 && (stats.st_mode & S_IFREG) != 0)
			{	/* found it */
				return path;
			}
		}

		/* if command is eclipse/jre, don't look in registry */
		location = (_TCHAR*)malloc((_tcslen(getProgramDir()) + _tcslen(shippedVMDir) + 1) * sizeof(_TCHAR));
		_stprintf(location, _T_ECLIPSE("%s%s"), getProgramDir(), shippedVMDir);
		if (_tcsncmp(command, location, _tcslen(location)) == 0) {
			free(location);
			return NULL;
		}
		free(location);
	}

	/* Not found yet, try the registry, we will use the first vm >= 1.6 */
	jreKeyName = (_TCHAR*)_T("Software\\JavaSoft\\Java Runtime Environment");
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, jreKeyName, 0, KEY_READ, &jreKey) == ERROR_SUCCESS) {
		if (RegQueryValueEx(jreKey, _T_ECLIPSE("CurrentVersion"), NULL, NULL, (LPBYTE)&keyName, &length) == ERROR_SUCCESS) {
			path = checkVMRegistryKey(jreKey, keyName);
			if (path != NULL) {
				RegCloseKey(jreKey);
				return path;
			}
		}
		j = 0;
		length = MAX_PATH;
		while (RegEnumKeyEx(jreKey, j++, keyName, &length, 0, 0, 0, 0) == ERROR_SUCCESS) {
			/*look for a 1.6+ vm*/
			if (_tcsncmp(_T("1.6"), keyName, 3) <= 0) {
				path = checkVMRegistryKey(jreKey, keyName);
				if (path != NULL) {
					RegCloseKey(jreKey);
					return path;
				}
			}
		}
		RegCloseKey(jreKey);
	}
	return NULL;
}

/*
 * Read the subKeyName subKey of jreKey and look to see if it has a Value
 * "RuntimeLib" which points to a jvm library we can use
 *
 * Does not close jreKey
 */
_TCHAR* checkVMRegistryKey(HKEY jreKey, _TCHAR* subKeyName) {
	_TCHAR value[MAX_PATH];
	HKEY subKey = NULL;
	DWORD length = MAX_PATH;
	_TCHAR* result = NULL;
	struct _stat stats;

	if (RegOpenKeyEx(jreKey, subKeyName, 0, KEY_READ, &subKey) == ERROR_SUCCESS) {
		/*The RuntimeLib value should point to the library we want*/
		if (RegQueryValueEx(subKey, _T("RuntimeLib"), NULL, NULL, (LPBYTE)&value, &length) == ERROR_SUCCESS) {
			if (_tstat(value, &stats) == 0 && (stats.st_mode & S_IFREG) != 0)
			{	/*library exists*/
				result = _tcsdup(value);
			}
		}
		else if (RegQueryValueEx(subKey, _T("JavaHome"), NULL, NULL, (LPBYTE)&value, &length) == ERROR_SUCCESS) {
			//if (_tstat( value, &stats ) == 0 /*&& (stats.st_mode & S_IFREG) != 0*/)
			{
				result = _tcsdup(value);
			}
		}
		RegCloseKey(subKey);
	}
	return result;
}

static _TCHAR* buildCommandLine(_TCHAR* program, _TCHAR* args[])
{
	int   index, slash;
	size_t length = 0;
	_TCHAR* commandLine, * ch, * space;

	/*
	* Build the command line. Any argument with spaces must be in
	* double quotes in the command line.
	*/
	if (program != NULL)
		length = _tcslen(program) + 1;
	for (index = 0; args[index] != NULL; index++)
	{
		/* String length plus space character */
		length += _tcslen(args[index]) + 1;
		/* Quotes + potential escaping '\' */
		if (_tcschr(args[index], _T(' ')) != NULL) length += 3;
	}

	commandLine = ch = (_TCHAR*)malloc((length + 1) * sizeof(_TCHAR));
	if (program != NULL) {
		_tcscpy(ch, program);
		ch += _tcslen(program);
		*ch++ = _T(' ');
	}
	for (index = 0; args[index] != NULL; index++)
	{
		space = _tcschr(args[index], _T(' '));
		if (space != NULL) *ch++ = _T('\"');
		_tcscpy(ch, args[index]);
		ch += _tcslen(args[index]);
		if (space != NULL) {
			if (*(ch - 1) == _T('\\')) {
				/* escape a trailing unescaped '\' or it will escape our closing '"' and mess things up */
				slash = 1;
				while (*(ch - 1 - slash) == _T('\\')) slash++;
				if (slash % 2) *ch++ = _T('\\');
			}
			*ch++ = _T('\"');
		}
		*ch++ = _T(' ');
	}
	*ch = _T('\0');
	return commandLine;
}
void restartLauncher(_TCHAR* program, _TCHAR* args[])
{
	_TCHAR* commandLine = buildCommandLine(program, args);

	{
		STARTUPINFO    si;
		PROCESS_INFORMATION  pi;
		GetStartupInfo(&si);
		if (CreateProcess(NULL, commandLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
			CloseHandle(pi.hThread);
		}
	}
	free(commandLine);
}

JavaResults* launchJavaVM(_TCHAR* args[])
{
	MSG msg;
	_TCHAR* commandLine;
	jvmProcess = 0;
	commandLine = buildCommandLine(NULL, args);
	jvmResults = (JavaResults*)malloc(sizeof(JavaResults));
	memset(jvmResults, 0, sizeof(JavaResults));

	/*
	* Start the Java virtual machine. Use CreateProcess() instead of spawnv()
	* otherwise the arguments cannot be freed since spawnv() segments fault.
	*/
	{
		STARTUPINFO    si;
		PROCESS_INFORMATION  pi;
		GetStartupInfo(&si);
		if (CreateProcess(NULL, commandLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
			CloseHandle(pi.hThread);
			jvmProcess = pi.hProcess;
		}
		else {
			jvmResults->launchResult = errno;
		}
	}

	free(commandLine);

	if (jvmProcess)
	{
		/* Set a timer to detect JVM process termination. */
		SetTimer(topWindow, jvmExitTimerId, jvmExitTimeout, (TIMERPROC)detectJvmExit);

		/* Process messages until the JVM terminates.
		   This launcher process must continue to process events until the JVM exits
		   or else Windows 2K will hang if the desktop properties (e.g., background) are
		   changed by the user. Windows does a SendMessage() to every top level window
		   process, which blocks the caller until the process responds. */
		while (jvmProcess != 0)
		{
			GetMessage(&msg, NULL, 0, 0);
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		/* Kill the timer. */
		KillTimer(topWindow, jvmExitTimerId);
	}

	/* Return the exit code from the JVM. */
	return jvmResults;
}

/* Detect JVM Process Termination */
static void CALLBACK detectJvmExit(HWND hwnd, UINT uMsg, UINT id, DWORD dwTime)
{
	DWORD   exitCode;

	/* If the JVM process has terminated */
	if (!GetExitCodeProcess((HANDLE)jvmProcess, &exitCode) ||
		exitCode != STILL_ACTIVE)
	{
		/* Save the JVM exit code. This should cause the loop in launchJavaVM() to exit. */
		jvmResults->runResult = exitCode;
		jvmProcess = 0;
	}
}

void processVMArgs(_TCHAR** vmargs[]) {
	/* nothing yet */
}

JavaResults* startJavaVM(_TCHAR* libPath, _TCHAR* vmArgs[], _TCHAR* progArgs[], _TCHAR* jarFile)
{
	return startJavaJNI(libPath, vmArgs, progArgs, jarFile);
}

int isModularVM(_TCHAR* javaVM, _TCHAR* jniLib) {
	_TCHAR* vm = (jniLib != NULL) ? jniLib : javaVM;
	int result = 0;
	DWORD infoSize;
	DWORD handle;
	void* info;

	_TCHAR* versionKey, * version, * majorVersion = NULL;
	int versionSize;

	if (vm == NULL)
		return 0;

	infoSize = GetFileVersionInfoSize(vm, &handle);
	if (infoSize > 0) {
		info = malloc(infoSize);
		if (GetFileVersionInfo(vm, 0, infoSize, info)) {
			TRANSLATIONS* translations;
			int translationsSize;
			VerQueryValue(info, _T_ECLIPSE("\\VarFileInfo\\Translation"), (LPVOID*)&translations, (PUINT)&translationsSize);

			/* this size is only right because %04x is 4 characters */
			versionKey = (_TCHAR*)malloc((_tcslen(PRODUCT_VERSION_KEY) + 1) * sizeof(_TCHAR));
			_stprintf(versionKey, PRODUCT_VERSION_KEY, translations[0].language, translations[0].codepage);
			VerQueryValue(info, versionKey, (LPVOID*)&version, (PUINT)&versionSize);
			if (versionSize >= 1) {
				majorVersion = _tcstok(version, _T(".-"));
				if ((majorVersion != NULL) && (_tcstol(majorVersion, NULL, 10) >= 9)) {
					result = 1;
				}
			}
			free(versionKey);
		}
		free(info);
	}
	return result;
}
