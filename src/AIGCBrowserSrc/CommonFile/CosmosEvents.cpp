/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202101020004
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

#include "StdAfx.h"
#include "CosmosEvents.h"


_ATL_FUNC_INFO OpenComplete = {CC_STDCALL,VT_EMPTY,3,VT_I4,VT_BSTR,VT_I4|VT_BYREF};
_ATL_FUNC_INFO Initialize= { CC_STDCALL, VT_EMPTY, 2, VT_DISPATCH, VT_BSTR};
_ATL_FUNC_INFO Destroy = { CC_STDCALL, VT_EMPTY, 0, NULL };
_ATL_FUNC_INFO CosmosClose = { CC_STDCALL, VT_EMPTY, 0, NULL };
_ATL_FUNC_INFO TangramEvent = { CC_STDCALL, VT_EMPTY, 1, VT_I4 | VT_BYREF };
_ATL_FUNC_INFO NodeOpenComplete = { CC_STDCALL, VT_EMPTY, 0, NULL };
_ATL_FUNC_INFO XobjAddInCreated = {CC_STDCALL,VT_EMPTY,3,VT_DISPATCH,VT_BSTR,VT_BSTR};
_ATL_FUNC_INFO XobjAddInsCreated = {CC_STDCALL,VT_EMPTY,0,NULL};
_ATL_FUNC_INFO TabChange= {CC_STDCALL,VT_EMPTY,3,VT_DISPATCH,VT_I4,VT_I4};
_ATL_FUNC_INFO TabChange2= {CC_STDCALL,VT_EMPTY,2,VT_I4,VT_I4};
_ATL_FUNC_INFO MessageHandle = {CC_STDCALL,VT_EMPTY,5,VT_BSTR,VT_BSTR,VT_BSTR,VT_BSTR,VT_BSTR };
_ATL_FUNC_INFO IPCMsg2 = {CC_STDCALL,VT_EMPTY,4,VT_DISPATCH,VT_BSTR,VT_BSTR,VT_BSTR};
