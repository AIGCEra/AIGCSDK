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

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently
//VS:NJVYC-BMHX2-G77MM-4XJMR-6Q8QF

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit
#define ISOLATION_AWARE_ENABLED 1
#define COMMERCIAL
#define MAX_BUF_LEN 65535
#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS
#define TMSCHEMA_H // this excludes the deprecated tmschema.h without dependency on _WIN32_WINNT macro
#define _CRT_SECURE_NO_WARNINGS
#define OpenSourceWebRT

#include <afxwin.h>         
#include <afxext.h>         // MFC extensions
#include <afxpriv.h>
#include <afxole.h>
#include <Uxtheme.h>
#include <vssym32.h>
#include <Shlobj.h>

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "resource.h"
#include <atlbase.h>
#include <atlimage.h>
#include <afxdisp.h>        // MFC Automation classes

#include "mscoree.h"

#define XHTMLHTML
#define XHTMLTOOLTIPS
#define XHTMLXML
#define XHTMLDRAGDROP
#define XHTMLTREE_DEMO		
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#include "inc.h"
#include "msaddndr.h"

#include <afxcview.h>
#include <afxdlgs.h>
#include <atlwin.h>
#include "vbe6ext.h"
//#include <afxcontrolbars.h>     // MFC support for ribbons and control bars
//#include <afxmdiclientareawnd.h>

#include "json/json2xml.hpp"

using namespace ATL;
using namespace Office;

#include "CommonUniverse.h"
#include "TangramXmlParse.h"
using namespace std;
using namespace ATL;
using namespace CommonUniverse;
#pragma comment(lib, "imagehlp.lib")

#pragma warning (disable : 4786)
#pragma warning (disable : 4312)
#pragma warning (disable : 4311)
#pragma warning (disable : 4244)
#pragma warning( disable : 4278 )
#pragma warning( disable : 4146 )
#pragma warning( disable : 4526 )

#define IfFailGo(x) { hr=(x); if (FAILED(hr)) goto Error; }
#define IfFailGoCheck(x, p) { hr=(x); if (FAILED(hr)) goto Error; if(!p) {hr = E_FAIL; goto Error; } }

#pragma comment (lib, "wininet.lib")
#pragma comment (lib, "urlmon.lib")


using namespace std;

#include <ppl.h>
#include <ppltasks.h>
using namespace concurrency;

class CBKWnd;
class CXobj;
class CWPFView;
class CXobjWnd;
class CSpaceTelescope;
class CNucleus;
class CHelperWnd;
class CEclipseWnd;
class CUniverse;
class CXobjEvents;
class CTangramTabCtrl;
class CWebRTAppCtrl;
class CTangramListView;
class CWebRTEvent;
class CNuclei;
class CCloudMDIFrame;
class CXobjCollection;
class CTangramHtmlTreeWnd;

typedef vector<CXobj*> CXobjVector;

#define FORCE_EXPLICIT_DTE_NAMESPACE
#define FORCE_EXPLICIT_PRJ_NAMESPACE

const _TCHAR * JNI_GetStringChars(JNIEnv *env, jstring str);
void JNI_ReleaseStringChars(JNIEnv *env, jstring s, const _TCHAR* data);

void DefaultExceptionProcess(JNIEnv *env);
void DefaultExceptionProcessEx(JNIEnv *env, _TCHAR* errorInfo);

void ThrowComFail(JNIEnv *env, const char* desc, jint hr);
SAFEARRAY *extractSA(JNIEnv *env, jobject arg);
void setSA(JNIEnv *env, jobject arg, SAFEARRAY *sa, int copy);
SAFEARRAY *copySA(SAFEARRAY *psa);