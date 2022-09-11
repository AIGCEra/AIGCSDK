/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202110220001
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

// CosmosHelper.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "CosmosHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWebRTApp

BEGIN_MESSAGE_MAP(CWebRTApp, CWinAppEx)
END_MESSAGE_MAP()


// CWebRTApp construction

CWebRTApp::CWebRTApp() noexcept
{
}

// The one and only CWebRTApp object

CWebRTApp theApp;


// CWebRTApp initialization

BOOL CWebRTApp::InitInstance()
{
	WebRTInit(_T(""));
	return true;
}

int CWebRTApp::ExitInstance()
{
	AfxOleTerm(FALSE);
	return CWinApp::ExitInstance();
}

// CWebRTApp message handlers
