/*******************************************************************************
 * Copyright (c) 2006, 2009 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 * 	   Andrew Niefer
 *******************************************************************************/
 /********************************************************************************
  *           Web Runtime for Application - Version 1.0.0.202203120001           *
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
  * Use of this source code is governed by a BSD-style license that
  * can be found in the LICENSE file.
  *
  * CONTACT INFORMATION:
  * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
  * https://www.webruntime.com
  *******************************************************************************/

#include "stdafx.h"
#include "UniverseApp.h"
#include "Cosmos.h"
#include "eclipseJNI.h"
#include "eclipseCommon.h"
#include "eclipseOS.h"
#include "eclipseShm.h"
#include "WinNucleus.h"

#include <shlobj.h>
#include <stdlib.h>
#include <string.h>


static _TCHAR* failedToLoadLibrary = (_TCHAR *)_T_ECLIPSE("Failed to load the JNI shared library \"%s\".\n");
static _TCHAR* createVMSymbolNotFound = (_TCHAR*)_T_ECLIPSE("The JVM shared library \"%s\"\ndoes not contain the JNI_CreateJavaVM symbol.\n");
static _TCHAR* failedCreateVM = (_TCHAR*)_T_ECLIPSE("Failed to create the Java Virtual Machine.\n");
static _TCHAR* internalExpectedVMArgs = (_TCHAR*)_T_ECLIPSE("Internal Error, the JVM argument list is empty.\n");
static _TCHAR* mainClassNotFound = (_TCHAR*)_T_ECLIPSE("Failed to find a Main Class in \"%s\".\n");

/* local methods */
static jstring newJavaString(JNIEnv *env, _TCHAR * str);
static void registerNatives(JNIEnv *env);
static int shouldShutdown(JNIEnv *env);
static void JNI_ReleaseStringChars(JNIEnv *env, jstring s, const _TCHAR* data);
static const _TCHAR* JNI_GetStringChars(JNIEnv *env, jstring str);
//static void setLibraryLocation(JNIEnv *env, jobject obj);

static JavaVM * jvm = 0;
static JNIEnv *env = 0;

extern LPWSTR *szArglist;
JavaResults* results = NULL;

/* cache String class and methods to avoid looking them up all the time */
static jclass string_class = NULL;
#if !defined(UNICODE) && !defined(MACOSX)
static jmethodID string_getBytesMethod = NULL;
static jmethodID string_ctor = NULL;
#endif

/* JNI Callback methods */
void set_exit_data(JNIEnv * env, jobject obj, jstring id, jstring s) {
	const _TCHAR* data = NULL;
	const _TCHAR* sharedId = NULL;
	size_t length;

	if (s != NULL) {
		length = env->GetStringLength(s);
		if (!env->ExceptionOccurred()) {
			data = JNI_GetStringChars(env, s);
			if (data != NULL) {
				if (id != NULL) {
					sharedId = JNI_GetStringChars(env, id);
					if (sharedId != NULL) {
						setSharedData(sharedId, data);
						JNI_ReleaseStringChars(env, id, sharedId);
					}
				}
				else {
					exitData = (_TCHAR*)malloc((length + 1) * sizeof(_TCHAR*));
					_tcsncpy(exitData, data, length);
					exitData[length] = _T_ECLIPSE('\0');
				}
				JNI_ReleaseStringChars(env, s, data);
			}
		}
		if (data == NULL && sharedId == NULL) {
			env->ExceptionDescribe();
			env->ExceptionClear();
		}
	}
}

jstring tangram_extend(JNIEnv * env, jobject obj, jstring key, jstring data, jstring features) {
	const _TCHAR* _key = NULL;
	const _TCHAR* _data = NULL;
	const _TCHAR* _features = NULL;

	if (features != NULL) {
		_features = JNI_GetStringChars(env, features);
	}

	if (key != NULL) {
		_key = JNI_GetStringChars(env, key);
	}

	if (data != NULL) {
		_data = JNI_GetStringChars(env, data);
	}
	CString strRet = _T("");
	if (g_pSpaceTelescope)
	{
		CString strFeatures = _features;
		CString strKey = _key;
		CString strData = _data;
		strRet = g_pSpaceTelescope->tangram_for_eclipse(strKey, strData, strFeatures);
	}
	if (_features != NULL) {
		JNI_ReleaseStringChars(env, features, _features);
	}
	if (_key != NULL) {
		JNI_ReleaseStringChars(env, key, _key);
	}
	if (_data != NULL) {
		JNI_ReleaseStringChars(env, data, _data);
	}
	return newJavaString(env, strRet.GetBuffer());
}

void set_launcher_info(JNIEnv * env, jobject obj, jstring launcher, jstring name) {
	const _TCHAR* launcherPath = NULL;
	const _TCHAR* launcherName = NULL;

	if (launcher != NULL) {
		launcherPath = JNI_GetStringChars(env, launcher);
		if (launcherPath != NULL) {
			setProgramPath(_tcsdup(launcherPath));
			JNI_ReleaseStringChars(env, launcher, launcherPath);
		}
	}

	if (name != NULL) {
		launcherName = JNI_GetStringChars(env, name);
		if (launcherName != NULL) {
			setOfficialName(_tcsdup(launcherName));
			JNI_ReleaseStringChars(env, name, launcherName);
		}
	}
}

void update_splash(JNIEnv * env, jobject obj) {
	dispatchMessages();
}

jlong get_splash_handle(JNIEnv * env, jobject obj) {
	return getSplashHandle();
}

void show_splash(JNIEnv * env, jobject obj, jstring s) {
	const _TCHAR* data = NULL;

	//setLibraryLocation(env, obj);

	if (s != NULL) {
		data = JNI_GetStringChars(env, s);
		if (data != NULL) {
			showSplash(data);
			JNI_ReleaseStringChars(env, s, data);
		}
		else {
			env->ExceptionDescribe();
			env->ExceptionClear();
		}
	}
}

void  takedown_splash(JNIEnv * env, jobject obj) {
	takeDownSplash();
}

jstring get_os_recommended_folder(JNIEnv * env, jobject obj) {
#ifdef MACOSX
	return newJavaString(env, getFolderForApplicationData());
#else
	return NULL;
#endif
}

//static JNINativeMethod natives[] = 
//{
//	{ "_update_splash", "()V", (void *)&update_splash },
//	{ "_get_splash_handle", "()J", (void *)&get_splash_handle },
//	{ "_set_exit_data", "(Ljava/lang/String;Ljava/lang/String;)V", (void *)&set_exit_data },
//	{ "_set_launcher_info", "(Ljava/lang/String;Ljava/lang/String;)V", (void *)&set_launcher_info },
//	{ "_show_splash", "(Ljava/lang/String;)V", (void *)&show_splash },
//	{ "_takedown_splash", "()V", (void *)&takedown_splash },
//	{ "_get_os_recommended_folder", "()Ljava/lang/String;", (void *)&get_os_recommended_folder } 
//};

/*
 * On AIX we need the location of the eclipse shared library so that we
 * can find the libeclipse-motif.so library.  Reach into the JNIBridge
 * object to get the "library" field.
 */

void registerNatives(JNIEnv *env) {
	/*begin Add by Tangram Team*/
	if (g_pSpaceTelescope)
	{
		jclass systemClass = NULL;
		jmethodID loadMethod = NULL;
		systemClass = env->FindClass("java/lang/System");//java.lang.Runtime
		try
		{
			if (systemClass != NULL) {
				loadMethod = env->GetStaticMethodID(systemClass, "load", "(Ljava/lang/String;)V");
				if (loadMethod != NULL) {
					jstring jarFileString = newJavaString(env, eclipseLibrary);
					env->CallStaticVoidMethod(systemClass, loadMethod, jarFileString);
					if (jarFileString != NULL)
						env->DeleteLocalRef(jarFileString);
				}
			}
		}
		catch (...)
		{
		}
		if (env->ExceptionOccurred()) {
			env->ExceptionDescribe();
			env->ExceptionClear();
		}
	}
	/*end Add by Tangram Team*/
	jclass bridge = env->FindClass(g_pSpaceTelescope->m_strBridgeJavaClass);
	//jclass bridge = env->FindClass("org/eclipse/equinox/launcher/JNIBridge");
	if (bridge != NULL) {
		JNINativeMethod natives[7];
		natives[0] = { (char*)"_update_splash", (char*)"()V", (void *)&update_splash };
		natives[1] = { (char*)"_get_splash_handle", (char*)"()J", (void *)&get_splash_handle };
		natives[2] = { (char*)"_set_exit_data", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void *)&set_exit_data };
		natives[3] = { (char*)"_set_launcher_info", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void *)&set_launcher_info };
		natives[4] = { (char*)"_show_splash", (char*)"(Ljava/lang/String;)V", (void *)&show_splash };
		natives[5] = { (char*)"_takedown_splash", (char*)"()V", (void *)&takedown_splash };
		natives[6] = { (char*)"_get_os_recommended_folder", (char*)"()Ljava/lang/String;", (void *)&get_os_recommended_folder };
		env->RegisterNatives(bridge, natives, sizeof(natives) / sizeof(natives[0]));
	}
	if (env->ExceptionOccurred() != 0) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	//jclass tangramclass2 = env->FindClass("test/tangram");
	//if (tangramclass2 == nullptr)
	//	TRACE(_T("\n"));

	jclass tangramClass = env->FindClass("dev/tangram/TangramJava");
	if (tangramClass != NULL) {
		JNINativeMethod natives[] =
		{
			{ (char*)"_extend", (char*)"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void *)&tangram_extend }
		};

		env->RegisterNatives(tangramClass, natives, sizeof(natives) / sizeof(natives[0]));
	}
	if (env->ExceptionOccurred() != 0) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}

	g_pSpaceTelescope->InitJNIForTangram();
}


/* Get a _TCHAR* from a jstring, string should be released later with JNI_ReleaseStringChars */
static const _TCHAR * JNI_GetStringChars(JNIEnv *env, jstring str) {
	const _TCHAR * result = NULL;
#ifdef UNICODE
	/* GetStringChars is not null terminated, make a copy */
	const _TCHAR * stringChars = (_TCHAR *)env->GetStringChars(str, 0);
	int length = env->GetStringLength(str);
	_TCHAR * copy = (_TCHAR *)malloc((length + 1) * sizeof(_TCHAR));
	_tcsncpy(copy, stringChars, length);
	copy[length] = _T_ECLIPSE('\0');
	env->ReleaseStringChars(str, (const jchar *)stringChars);
	result = copy;
#elif MACOSX
	/* Use UTF on the Mac */
	result = env->GetStringUTFChars(env, str, 0);
#else
	/* Other platforms, use java's default encoding */
	_TCHAR* buffer = NULL;
	if (string_class == NULL)
		string_class = env->FindClass(env, "java/lang/String");
	if (string_class != NULL) {
		if (string_getBytesMethod == NULL)
			string_getBytesMethod = env->GetMethodID(env, string_class, "getBytes", "()[B");
		if (string_getBytesMethod != NULL) {
			jbyteArray bytes = env->CallObjectMethod(env, str, string_getBytesMethod);
			if (!env->ExceptionOccurred()) {
				jsize length = env->GetArrayLength(env, bytes);
				buffer = malloc((length + 1) * sizeof(_TCHAR*));
				env->GetByteArrayRegion(env, bytes, 0, length, (jbyte*)buffer);
				buffer[length] = 0;
			}
			env->DeleteLocalRef(env, bytes);
		}
	}
	if (buffer == NULL) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	result = buffer;
#endif
	return result;
}

/* Release the string that was obtained using JNI_GetStringChars */
static void JNI_ReleaseStringChars(JNIEnv *env, jstring s, const _TCHAR* data) {
#ifdef UNICODE
	free((_TCHAR*)data);
#elif MACOSX
	env->ReleaseStringUTFChars(env, s, data);
#else
	free((_TCHAR*)data);
#endif
}

static jstring newJavaString(JNIEnv *env, _TCHAR * str)
{
	jstring newString = NULL;
#ifdef UNICODE
	size_t length = _tcslen(str);
	newString = env->NewString((const jchar*)str, length);
#elif MACOSX
	newString = env->NewStringUTF(env, str);
#else
	size_t length = _tcslen(str);
	jbyteArray bytes = env->NewByteArray(env, length);
	if (bytes != NULL) {
		env->SetByteArrayRegion(env, bytes, 0, length, (jbyte *)str);
		if (!env->ExceptionOccurred()) {
			if (string_class == NULL)
				string_class = env->FindClass(env, "java/lang/String");
			if (string_class != NULL) {
				if (string_ctor == NULL)
					string_ctor = env->GetMethodID(env, string_class, "<init>", "([B)V");
				if (string_ctor != NULL) {
					newString = env->NewObject(env, string_class, string_ctor, bytes);
				}
			}
		}
		env->DeleteLocalRef(env, bytes);
	}
#endif
	if (newString == NULL) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	return newString;
}

static jobjectArray createRunArgs(JNIEnv *env, _TCHAR * args[]) {
	int index = 0, length = -1;
	jobjectArray stringArray = NULL;
	jstring string;

	/*count the number of elements first*/
	while (args[++length] != NULL);

	if (string_class == NULL)
		string_class = env->FindClass("java/lang/String");
	if (string_class != NULL) {
		stringArray = env->NewObjectArray(length, string_class, 0);
		if (stringArray != NULL) {
			for (index = 0; index < length; index++) {
				string = newJavaString(env, args[index]);
				if (string != NULL) {
					env->SetObjectArrayElement(stringArray, index, string);
					env->DeleteLocalRef(string);
				}
				else {
					env->DeleteLocalRef(stringArray);
					env->ExceptionDescribe();
					env->ExceptionClear();
					return NULL;
				}
			}
		}
	}
	if (stringArray == NULL) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	return stringArray;
}

JavaResults * startJavaJNI(_TCHAR* libPath, _TCHAR* vmArgs[], _TCHAR* progArgs[], _TCHAR* jarFile)
{
	int i;
	int numVMArgs = -1;
	void * jniLibrary;
	JNI_createJavaVM createJavaVM;
	JavaVMInitArgs init_args;
	JavaVMOption * options;

	/* JNI reflection */
	jclass mainClass = NULL;			/* The Main class to load */
	jobject mainObject = NULL;			/* An instantiation of the main class */
	jmethodID mainConstructor = NULL;	/* Main's default constructor Main() */
	jmethodID runMethod = NULL;			/* Main.run(String[]) */
	jobjectArray methodArgs = NULL;		/* Arguments to pass to run */

	results = (JavaResults *)malloc(sizeof(JavaResults));
	memset(results, 0, sizeof(JavaResults));

	jniLibrary = ::GetModuleHandle(_T("jvm.dll"));
	if (jniLibrary == NULL)
		jniLibrary = loadLibrary(libPath);
	if (jniLibrary == NULL) {
		results->launchResult = -1;
		results->errorMessage = (_TCHAR *)malloc((_tcslen(failedToLoadLibrary) + _tcslen(libPath) + 1) * sizeof(_TCHAR));
		_stprintf(results->errorMessage, failedToLoadLibrary, libPath);
		return results; /*error*/
	}

	createJavaVM = (JNI_createJavaVM)findSymbol(jniLibrary, (_TCHAR*)_T_ECLIPSE("JNI_CreateJavaVM"));
	if (createJavaVM == NULL) {
		results->launchResult = -2;
		results->errorMessage = (_TCHAR *)malloc((_tcslen(createVMSymbolNotFound) + _tcslen(libPath) + 1) * sizeof(_TCHAR));
		_stprintf(results->errorMessage, createVMSymbolNotFound, libPath);
		return results; /*error*/
	}

	/* count the vm args */
	while (vmArgs[++numVMArgs] != NULL) {}

	if (numVMArgs <= 0) {
		/*error, we expect at least the required vm arg */
		results->launchResult = -3;
		results->errorMessage = _tcsdup(internalExpectedVMArgs);
		return results;
	}

	options = (JavaVMOption *)malloc(numVMArgs * sizeof(JavaVMOption));
	for (i = 0; i < numVMArgs; i++) {
		OutputDebugString(vmArgs[i]);
		OutputDebugString(_T("\n"));
		//begin Add by Tangram Team
		int nIndex = -1;
		CString stroption = CString(vmArgs[i]);
		stroption = g_pSpaceTelescope->ConfigJavaVMInfo(stroption);
		if (stroption == _T(""))
			options[i].optionString = toNarrow(vmArgs[i]);
		else
		{
			options[i].optionString = toNarrow(stroption.GetBuffer());
			stroption.ReleaseBuffer();
		}
		options[i].extraInfo = 0;
		//end Add by Tangram Team
	}

#ifdef MACOSX
	init_args.version = JNI_VERSION_1_4;
#else		

	init_args.version = g_pSpaceTelescope->m_nJVMVersion;
#endif
	init_args.options = options;
	init_args.nOptions = numVMArgs;
	init_args.ignoreUnrecognized = JNI_TRUE;

	OutputDebugString(_T("begin createJavaVM\n"));
	if (createJavaVM(&jvm, &env, &init_args) == 0)
	{
		for (i = 0; i < numVMArgs; i++) {
			free(options[i].optionString);
		}
		free(options);
		OutputDebugString(_T("Success createJavaVM\n"));
		/*begin Add by Tangram Team*/
		if (g_pSpaceTelescope)
		{
			g_pSpaceTelescope->m_pWebRTDelegate->m_pJVM = jvm;
			g_pSpaceTelescope->m_pWebRTDelegate->m_pJVMenv = env;
			if (env)
			{
				g_pSpaceTelescope->m_pWebRTDelegate->systemClass = env->FindClass("java/lang/System");
				try
				{
					if (g_pSpaceTelescope->m_pWebRTDelegate->systemClass != nullptr)
					{
						g_pSpaceTelescope->m_pWebRTDelegate->exitMethod = env->GetStaticMethodID(g_pSpaceTelescope->m_pWebRTDelegate->systemClass, "exit", "(I)V");
						g_pSpaceTelescope->m_pWebRTDelegate->loadMethod = env->GetStaticMethodID(g_pSpaceTelescope->m_pWebRTDelegate->systemClass, "load", "(Ljava/lang/String;)V");
					}
				}
				catch (...)
				{
				}
				if (env->ExceptionOccurred()) {
					env->ExceptionDescribe();
					env->ExceptionClear();
				}
			}
		}
		/*end Add by Tangram Team*/
		registerNatives(env);
		USES_CONVERSION;
		char * mainClassName = W2A(g_pSpaceTelescope->InitEclipse(jarFile));

		if (mainClassName != NULL) {
			mainClass = env->FindClass(mainClassName);
			if (env->ExceptionOccurred()) {
				env->ExceptionDescribe();
				env->ExceptionClear();
			}
			if (mainClass == nullptr)
				mainClass = env->FindClass("org/eclipse/equinox/launcher/Main");
		}

		if (mainClass != NULL) {
			results->launchResult = -6; /* this will be reset to 0 below on success */
			mainConstructor = env->GetMethodID(mainClass, "<init>", "()V");
			if (mainConstructor != NULL) {
				mainObject = env->NewObject(mainClass, mainConstructor);
				if (mainObject != NULL) {
					runMethod = env->GetMethodID(mainClass, "run", "([Ljava/lang/String;)I");
					if (runMethod != NULL) {
						methodArgs = createRunArgs(env, progArgs);
						if (methodArgs != NULL) {
							results->launchResult = 0;
							results->runResult = env->CallIntMethod(mainObject, runMethod, methodArgs);
							env->DeleteLocalRef(methodArgs);
						}
					}
					env->DeleteLocalRef(mainObject);
				}
			}
		}
		else {
			results->launchResult = -5;
			results->errorMessage = (_TCHAR *)malloc((_tcslen(mainClassNotFound) + _tcslen(jarFile) + 1) * sizeof(_TCHAR));
			_stprintf(results->errorMessage, mainClassNotFound, jarFile);
			OutputDebugString(_T("Error mainClass\n"));
			OutputDebugString(results->errorMessage);
			OutputDebugString(_T("\n"));
		}
		if (env->ExceptionOccurred()) {
			env->ExceptionDescribe();
			env->ExceptionClear();
		}

	}
	else {
		results->launchResult = -4;
		results->errorMessage = _tcsdup(failedCreateVM);
		OutputDebugString(results->errorMessage);
		OutputDebugString(_T("\n"));
	}

	/* toNarrow allocated new strings, free them */
	//for (i = 0; i < numVMArgs; i++) {
	//	free(options[i].optionString);
	//}
	//free(options);
	return results;
}

void cleanupVM(int exitCode) {
	JNIEnv * localEnv = env;
	if (jvm == 0)
		return;

	if (secondThread)
		jvm->AttachCurrentThread((void**)&localEnv, NULL);
	else
		localEnv = env;
	if (localEnv == 0)
		return;

	/* we call System.exit() unless osgi.noShutdown is set */
	ATLTRACE(_T("before quit eclipse\n"));
	if (shouldShutdown(env)) {
		if (g_pSpaceTelescope)
		{
			ATLTRACE(_T("begin quit eclipse\n"));
			FreeLibrary((HMODULE)theApp.m_hInstance);
			return;
		}
	}
	//jvm->DestroyJavaVM();
}

static int shouldShutdown(JNIEnv * env) {
	jclass booleanClass = NULL;
	jmethodID method = NULL;
	jstring arg = NULL;
	jboolean result = 0;

	booleanClass = env->FindClass("java/lang/Boolean");
	if (booleanClass != NULL) {
		method = env->GetStaticMethodID(booleanClass, "getBoolean", "(Ljava/lang/String;)Z");
		if (method != NULL) {
			arg = newJavaString(env, (_TCHAR*)_T_ECLIPSE("osgi.noShutdown"));
			result = env->CallStaticBooleanMethod(booleanClass, method, arg);
			env->DeleteLocalRef(arg);
		}
	}
	if (env->ExceptionOccurred()) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	return (result == 0);
}


