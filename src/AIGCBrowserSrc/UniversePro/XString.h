/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202108220001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser;
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

#ifndef XSTRING_H
#define XSTRING_H

// find
TCHAR * _tcsistr(const TCHAR * str, const TCHAR * substr);
int _tcsccnt(const TCHAR *str, TCHAR ch);

// removal
TCHAR * _tcscrem(TCHAR *str, TCHAR ch);
TCHAR * _tcsicrem(TCHAR *str, TCHAR ch);
TCHAR * _tcsstrrem(TCHAR *str, const TCHAR *substr);
TCHAR * _tcsistrrem(TCHAR *str, const TCHAR *substr);

// replace
TCHAR * _tcscrep(TCHAR *str, TCHAR chOld, TCHAR chNew);
TCHAR * _tcsicrep(TCHAR *str, TCHAR chOld, TCHAR chNew);
int     _tcsistrrep(const TCHAR * lpszStr, 
					const TCHAR * lpszOld, 
					const TCHAR * lpszNew, 
					TCHAR * lpszResult);

// trim
TCHAR *_tcsltrim(TCHAR *str, const TCHAR *targets);
TCHAR *_tcsrtrim(TCHAR *str, const TCHAR *targets);
TCHAR *_tcstrim(TCHAR *str, const TCHAR *targets);

// copy
TCHAR *_tcsnzdup(const TCHAR *str, size_t count);
TCHAR *_tcszdup(const TCHAR * str);

#endif //XSTRING_H
