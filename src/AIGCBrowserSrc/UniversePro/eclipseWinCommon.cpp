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

/*******************************************************************************
 * Copyright (c) 2006, 2009 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *     Andrew Niefer
 *******************************************************************************/
#include "stdafx.h"
#include "UniverseApp.h"
#include "Cosmos.h"

#include "eclipseCommon.h"
#include "eclipseOS.h"

#include <windows.h>
#include <stdlib.h>
#include <commctrl.h>

#define ECLIPSE_ICON  401

_TCHAR   dirSeparator  = _T('\\');
_TCHAR   pathSeparator = _T(';');

/* Global Main Window*/
HWND    topWindow = 0;

/* Define local variables for the main window. */
/*static WNDPROC oldProc;*/

static int initialized = 0;

/* Display a Message */
void displayMessage( _TCHAR* title, _TCHAR* message )
{
	if(!initialized)
		initWindowSystem(0, NULL, 0);
	MessageBox( topWindow, message, title, MB_OK );
}

/* Initialize Window System
 *
 * Create a pop window to display the bitmap image.
 *
 * Return the window handle as the data for the splash command.
 *
 */
int initWindowSystem( int* pArgc, _TCHAR* argv[], int showSplash )
{
	HINSTANCE module = GetModuleHandle(NULL);
	HICON icon = NULL;
	
	if(initialized)
		return 0;

	icon = LoadIcon(module, MAKEINTRESOURCE(ECLIPSE_ICON)); 
    if (icon == NULL) {
    	HMODULE hm = LoadLibraryEx(getProgramPath(), 0, LOAD_LIBRARY_AS_DATAFILE & 0x2 /*LOAD_LIBRARY_AS_IMAGE_RESOURCE*/);
    	if (hm != NULL)
    		icon = LoadIcon(hm, MAKEINTRESOURCE(ECLIPSE_ICON));
    }
    
    /* Create a window that has no decorations. */
	InitCommonControls();
    topWindow = CreateWindowEx ( icon != NULL ? 0 : WS_EX_TOOLWINDOW|WS_EX_TOPMOST,
		_T("STATIC"),
		getOfficialName(),
		SS_BITMAP | WS_POPUP | WS_CLIPCHILDREN,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		module,
		NULL);

    if (icon != NULL)
#ifdef _WIN64
    	SetClassLongPtr(topWindow, GCLP_HICON, (LONG_PTR)icon);
#else
    	SetClassLong(topWindow, GCL_HICON, (LONG)icon);
#endif

	initialized = 1;
	return 0;
}

/* Load the specified shared library
 */
void * loadLibrary( _TCHAR * library ){
	return LoadLibrary(library);
}

/* Unload the shared library
 */
void unloadLibrary( void * handle ){
	FreeLibrary((HMODULE)handle);
}
 
/* Find the given symbol in the shared library
 */
void * findSymbol( void * handle, _TCHAR * symbol ){
	char * str = NULL;
	void * result;
	
	str = toNarrow(symbol);
	result = GetProcAddress((HMODULE)handle, str);
	free(str);
	return result;
}

_TCHAR* resolveSymlinks( _TCHAR* path ) {
	/* no symlinks on windows */
	return path;
}
