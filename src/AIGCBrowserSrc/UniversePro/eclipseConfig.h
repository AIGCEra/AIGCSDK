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
 * Copyright (c) 2000, 2010 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/

#ifndef ECLIPSE_CONFIG_H
#define ECLIPSE_CONFIG_H

/* Configuration file reading utilities */

/**
 * Reads a configuration file for the corresponding
 * program argument.
 * e.g if the program argument contains "c:/folder/eclipse.exe"
 * then the config file "c:/folder/eclipse.ini" will be parsed.
 * On a Unix like platform, for a program argument "/usr/eclipse/eclipse"
 * should correspond a configuration file "/usr/eclipse/eclipse.ini"
 *
 * This method will call readConfigFile to read the actual ini file
 *
 * This method will use getIniFile with a value for consoleLauncher that
 * is determined at compile time.  Clients who are not the actual
 * win32 console executable should instead use getIniFile and readConfigFile.
 *
 * Returns 0 if success.
 */
extern int readIniFile(_TCHAR* program, int *argc, _TCHAR ***argv);

/**
 * Return the path to the launcher ini file for the corresponding program 
 * argument. On win32, an "eclipsec.exe' console launcher can use the "eclipse.ini"
 * ini file.
 * consoleLauncher : whether or not we are using the win32 "eclipsec" console launcher
 *                   has no affect on other platforms 
 */
extern _TCHAR* getIniFile(_TCHAR* program, int consoleLauncher);

/**
 * Reads the given configuration file 
 * The argument argv refers to a newly allocated array of strings.
 * The first entry is the program name to mimic the expectations
 * from a typical argv list.
 * The last entry of that array is NULL. 
 * Each non NULL entry in that array must be freed by the caller 
 * as well as the array itself, using freeConfig().
 * The argument argc contains the number of string allocated.
 *
 * Returns 0 if success.
 */
extern int readConfigFile( _TCHAR * config_file, int *argc, _TCHAR ***argv );
/**
 * Free the memory allocated by readConfigFile().
 */
extern void freeConfig(_TCHAR **args);

#endif /* ECLIPSE_CONFIG_H */
