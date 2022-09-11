/********************************************************************************
*					Tangram Wizard - version 1.0.0							*
*********************************************************************************
* Copyright (C) 2002-2020 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS
* OUTLINED IN THE GPL LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.webruntime.com
*
*
********************************************************************************/

// dllmain.cpp : Implementation of DllMain.

// CTangramApp:
// See dllmain.cpp for the implementation of this class
//

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "dllmain.h"

//Add by TangramTeam:
#include "WebView.h"
#include "cosmosForm.h"

CTangramApp theApp;

BOOL CTangramApp::InitInstance()
{
	m_mapDOMObj[_T("webview")] = RUNTIME_CLASS(CWebView);
	m_mapDOMObj[_T("cosmosformview")] = RUNTIME_CLASS(CCosmosFormView);
	return __super::InitInstance();
}
