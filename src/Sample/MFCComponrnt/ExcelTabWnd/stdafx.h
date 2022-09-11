// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently


#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE
#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#include <afxwin.h>
#include <afxpriv.h>
#include "resource.h"
#include <atlbase.h>

using namespace ATL;
#include "../CommonFile/CommonUniverse.h"
using namespace CommonUniverse;
