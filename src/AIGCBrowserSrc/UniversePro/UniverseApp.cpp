/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202112150001           *
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 *
 * Web Runtime is a new, subversive and Internet Oriented Development Technology
 * for Windows Desktop Software. Its core idea is that, relying on the open-source
 * project of Chromium, developers are allowed to use their familiar software
 * development technology to realize the Main Process of their application system
 * as the Browser Process of Modern Web Browser. Because the Main Process is realized
 * by the developers themselves, the application system developed in this way is
 * completely different from modern web browser. This kind of application will
 * integrate the infrastructure of modern web browser as a part of the system model,
 * the application system contains not only the browser window inherent in the browser,
 * but also other desktop elements oriented to the application, such as WinForms, Java
 * and other mature software elements.
 *
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
 *
 * Built-in Full-Featured Modern Web Browser Subsystem
 *		Since the main process of the application system is essentially a Browser
 * Process, the application system can naturally create a new browser window. The
 * difference with standard browsers is that we allow the browser window to be a child
 * window of other windows. in sub-window model, we see a brand-new scene: a multi-tab
 * browser sub-window, we think this structure is more suitable for organizing specific
 * applications. Of course, the application system fully supports the creation of an
 * independent browser window as a part of the complete application system, and the browser
 * window serves as a natural extension of the ecological chain to ensure the richness
 * and diversity of the application system content.
 * DOM Plus:
 *		Because a large number of mature binary components that conform to industry
 * standards have formed a wealth of software asset accumulation, web runtime allows
 * developers to regard these existing accumulation as new DOM elements and then become
 * a part of web pages, this starting point eventually forms "DOM Plus". DOM plus is a
 * natural extension of standard DOM for desktop applications, similar to the extension
 * from "real number system" to "complex number system" in mathematical theory. Undoubtedly,
 * for the development of mathematics, from "real number system" to "complex number system"
 * is a huge leap, which can be said to be a decisive change in the development of modern
 * mathematics. We hope that the evolution from "DOM" to "DOM plus" will have a similar
 * effect, which is bound to be a huge change from desktop software to Internet desktop software.
 *		Different from earlier IE, based on the sandbox mechanism of Modern Web Browser,
 * we let these binary elements run in the Browser Process, completely isolated from the
 * Browser's Renderer Process. This makes full use of the security mechanisms of modern
 * browsers and also takes into account the accumulation of mature software component
 * technologies. Based on such considerations, existing development technologies such as
 * .NET, COM, Java, etc. can be fully applied to Internet software development.
 *
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

 // UniverseApp.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "UniverseApp.h" 
#include <VersionHelpers.h> 
#include <shellscalingapi.h>
//#include <ntddk.h>

#include "fm20.h"
#include "EclipsePlus\EclipseAddin.h"

#include "XobjWnd.h"
#include "Xobj.h"
#include "WinNucleus.h"
#include "WPFView.h"
#include <io.h>
#include <stdio.h>

#include "TangramListView.h"
#include "Psapi.h"

#include "chromium\WebPage.h"
#include "chromium\BrowserWnd.h"
#include "DpiUtil.h"
#include "DpiUtil.cpp"

// Description  : the unique App object
CUniverse theApp;
CSpaceTelescope* g_pSpaceTelescope = nullptr;

void CHelperWnd::OnFinalMessage(HWND hWnd)
{
	CWindowImpl::OnFinalMessage(hWnd);
	auto it = g_pSpaceTelescope->m_mapRemoteCosmos.find(m_strID);
	if (it != g_pSpaceTelescope->m_mapRemoteCosmos.end())
	{
		ULONG dw = it->second->Release();
		while (dw)
			dw = it->second->Release();
		g_pSpaceTelescope->m_mapRemoteCosmos.erase(m_strID);
	}

	delete this;
}

CUniverse::CUniverse()
{
	m_bHostCLR = false;
	m_bAppStarting = true;
	m_strCosmosVer = _T("");
}

CUniverse::~CUniverse()
{
	if (g_pSpaceTelescope)
		delete g_pSpaceTelescope;

	OutputDebugString(_T("******************************Exit CUniverse******************************\n"));
}

BOOL CUniverse::InitInstance()
{
	OutputDebugString(_T("******* Start CUniverse::InitInstance()*************\n"));
	TCHAR m_szBuffer[MAX_PATH];
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
	CString path = m_szBuffer;
	int nPos = path.ReverseFind('\\');
	CString strName = path.Mid(nPos + 1);
	nPos = strName.Find(_T("."));
	CString strExeName = strName.Left(nPos);
	strExeName.MakeLower();
	if (strExeName == _T("regsvr32"))
		return true;
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(2925);

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	::OleInitialize(NULL);

	m_bHostCLR = (BOOL)::GetModuleHandle(_T("mscoreei.dll"));

#ifndef _WIN64
	{
		new CComObject < CSpaceTelescope >;
		g_pSpaceTelescope->m_strExeName = strExeName;
		g_pSpaceTelescope->m_dwThreadID = ::GetCurrentThreadId();
		if (g_pSpaceTelescope->m_hCBTHook == nullptr)
			g_pSpaceTelescope->m_hCBTHook = SetWindowsHookEx(WH_CBT, CUniverse::CBTProc, NULL, g_pSpaceTelescope->m_dwThreadID);
		theApp.SetHook(g_pSpaceTelescope->m_dwThreadID);
	}
#else
	new CComObject < CSpaceTelescope >;
	g_pSpaceTelescope->m_strExeName = strExeName;
	g_pSpaceTelescope->m_dwThreadID = ::GetCurrentThreadId();
	if (g_pSpaceTelescope->m_hCBTHook == nullptr)
		g_pSpaceTelescope->m_hCBTHook = SetWindowsHookEx(WH_CBT, CUniverse::CBTProc, NULL, g_pSpaceTelescope->m_dwThreadID);
	g_pSpaceTelescope->m_bEnableProcessFormTabKey = true;
	theApp.SetHook(g_pSpaceTelescope->m_dwThreadID);
	if (g_pSpaceTelescope->m_hForegroundIdleHook == NULL)
		g_pSpaceTelescope->m_hForegroundIdleHook = SetWindowsHookEx(WH_FOREGROUNDIDLE, CUniverse::ForegroundIdleProc, NULL, ::GetCurrentThreadId());
#endif	

	if (g_pSpaceTelescope)
	{
		WNDCLASS wndClass{};
		wndClass.style = CS_DBLCLKS;
		wndClass.lpfnWndProc = ::DefWindowProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = AfxGetInstanceHandle();
		wndClass.hIcon = 0;
		wndClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
		wndClass.hbrBackground = 0;
		wndClass.lpszMenuName = NULL;
		wndClass.lpszClassName = _T("Universe GridWindow Class");

		RegisterClass(&wndClass);

		wndClass.lpszClassName = _T("WebRT Process Info");
		RegisterClass(&wndClass);

		g_pSpaceTelescope->m_lpszSplitterClass = wndClass.lpszClassName;

		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		//wndClass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
		wndClass.lpszClassName = L"Cosmos Xobj Class";

		RegisterClass(&wndClass);

		wndClass.lpfnWndProc = CosmosMsgWndProc;
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.lpszClassName = L"Tangram Message Window Class";

		RegisterClass(&wndClass);

		wndClass.lpfnWndProc = CosmosExtendedWndProc;
		wndClass.lpszClassName = L"Chrome Extended Window Class";

		RegisterClass(&wndClass);

		g_pSpaceTelescope->m_strExeName = strExeName;
		g_pSpaceTelescope->m_dwThreadID = ::GetCurrentThreadId();
		g_pSpaceTelescope->CosmosLoad();
		theApp.SetHook(g_pSpaceTelescope->m_dwThreadID);
		if (::GetModuleHandle(_T("msenv.dll")))
			g_pSpaceTelescope->Init();
		else
		{
			//#ifdef _WIN64
			g_pSpaceTelescope->m_strStartupURL = _T("");
			int nPos = path.ReverseFind('.');
			int nPos2 = path.ReverseFind('\\');
			CString strPath = path.Left(nPos + 1);
			CString strInitWebPage = strPath + _T("app.html");
			CString strInitWebPage2 = strPath + _T(".html");
			CString strInitEclipse = strPath + _T("eclipse");
			bool bSupportBrowser = (::PathFileExists(strInitWebPage) && !::PathIsDirectory(strInitWebPage));
			BOOL bWin32Model = bSupportBrowser && ::PathFileExists(strInitWebPage2) && !::PathIsDirectory(strInitWebPage2);
			bool bSupportEclipse = (::PathFileExists(strInitEclipse) && !::PathIsDirectory(strInitEclipse));
			CString strPath2 = path.Left(nPos2 + 1) + _T("AIGCAgent.dll");
			BOOL bHasChromeRT = (bWin32Model == false) && ::PathFileExists(strPath2) && !::PathIsDirectory(strPath2);
			if (bWin32Model == false)
			{
				if (bHasChromeRT == false)
				{
					TCHAR m_szBuffer[MAX_PATH];
					if (SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer) == S_OK) {
						CString strChromeRTFilePath = CString(m_szBuffer);
						strChromeRTFilePath += _T("\\Tangram\\AIGCBrowser\\AIGCAgent.dll");
						if (::PathFileExists(strChromeRTFilePath)) {
							bHasChromeRT = true;;
						}
					}
				}
				if (!bSupportBrowser)
				{
					strInitWebPage = _T("");
				}
			}
			if (bSupportEclipse)
			{
				g_pSpaceTelescope->m_bEclipse = false;
				CString strplugins = g_pSpaceTelescope->m_strAppPath + _T("plugins\\");
				if (::PathIsDirectory(strplugins)) {
					CString strPath = strplugins + _T("*.jar");
					_wfinddata_t fd;
					fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
					intptr_t pf = _wfindfirst(strPath, &fd);
					if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
						g_pSpaceTelescope->m_bEclipse = true;
					}
					else {
						while (!_wfindnext(pf, &fd)) {
							if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
								g_pSpaceTelescope->m_bEclipse = true;
								break;
							}
						}
					}
					_findclose(pf);
				}
				bSupportEclipse = g_pSpaceTelescope->m_bEclipse;
			}
			if (bHasChromeRT && bSupportBrowser && bSupportEclipse)
			{
				g_pSpaceTelescope->m_strStartupURL = strInitWebPage;
				g_pSpaceTelescope->m_strStartView = strInitEclipse;
				g_pSpaceTelescope->m_nAppType = APP_BROWSER_ECLIPSE;
			}
			if (g_pSpaceTelescope->m_strStartupURL == _T(""))
			{
				if (bSupportEclipse)
				{
					g_pSpaceTelescope->m_nAppType = APP_ECLIPSE;
					g_pSpaceTelescope->m_strStartupURL = strInitEclipse;
				}
				else
				{
					if (!bSupportBrowser)
					{
						strPath = strPath + _T("win32");
						if (::PathFileExists(strPath) && !::PathIsDirectory(strPath))
						{
							g_pSpaceTelescope->m_nAppType = APP_WIN32;
							g_pSpaceTelescope->m_strStartupURL = strPath;
						}
						else if (bHasChromeRT)
						{
							g_pSpaceTelescope->m_nAppType = APP_BROWSER;
							g_pSpaceTelescope->m_strStartupURL = _T("");
						}
					}
				}
			}
			else {
				g_pSpaceTelescope->m_nAppType = APP_BROWSER;
			}
			g_pSpaceTelescope->Init();
			if (bHasChromeRT && !g_pSpaceTelescope->m_bIsWin7) {
				DPI_AWARENESS_CONTEXT dpiAwarenessContext = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
				DpiUtil::SetProcessDpiAwarenessContext(dpiAwarenessContext);
			}
		}
	}
	return true;
}

int CUniverse::ExitInstance()
{
	ATLTRACE(_T("Begin Tangram ExitInstance :%p\n"), this);
	if (g_pSpaceTelescope) {
		g_pSpaceTelescope->ExitInstance();
	}
	AfxOleTerm(FALSE);
	ATLTRACE(_T("End Tangram ExitInstance :%p\n"), this);

	return CWinApp::ExitInstance();
}

LRESULT CUniverse::ForegroundIdleProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (g_pSpaceTelescope->m_pWebRTDelegate)
	{
		g_pSpaceTelescope->m_pWebRTDelegate->ForegroundIdleProc();
	}
	for (auto& it : g_pSpaceTelescope->m_mapWebRTAppProxy)
		it.second->OnForegroundIdleProc();
	if (g_pSpaceTelescope && g_pSpaceTelescope->m_pMessagePumpForUI && g_pSpaceTelescope->m_pMessagePumpForUI->m_bStartRun)
		g_pSpaceTelescope->m_pMessagePumpForUI->OnAppIdle();
	return CallNextHookEx(g_pSpaceTelescope->m_hForegroundIdleHook, nCode, wParam, lParam);
}

LRESULT CALLBACK CUniverse::CosmosMsgWndProc(_In_ HWND hWnd, UINT msg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		if (hWnd == g_pSpaceTelescope->m_hCosmosWnd)
		{
			if (g_pSpaceTelescope->m_dwEnumTopWndThreadID != -1)
				::PostAppMessage(g_pSpaceTelescope->m_dwEnumTopWndThreadID, WM_COSMOSMSG, 1, 0);
			g_pSpaceTelescope->m_pActiveAppProxy = nullptr;
			if (g_pSpaceTelescope->m_pCLRProxy)
			{
				if (g_pSpaceTelescope->m_pWebRTAppProxy)
					g_pSpaceTelescope->m_pWebRTAppProxy->OnWebRTClose(CosmosCloseState::StartClose);
				g_pSpaceTelescope->m_pCLRProxy->CosmosAction(CComBSTR("<begin_quit_eclipse/>"), nullptr);
			}

			if (::IsWindow(g_pSpaceTelescope->m_hHostBrowserWnd))
			{
				::SendMessage(g_pSpaceTelescope->m_hHostBrowserWnd, WM_CLOSE, 0, 0);
			}
			if (g_pSpaceTelescope->m_hForegroundIdleHook)
				UnhookWindowsHookEx(g_pSpaceTelescope->m_hForegroundIdleHook);
		}
		break;
	}
	break;
	case WM_WINFORMCREATED:
	{
		LRESULT l = ::SendMessage((HWND)wParam, WM_HUBBLE_DATA, 0, 20190214);
		if (l == 0)
		{
			CCloudWinForm* pWnd = new CCloudWinForm();
			g_pSpaceTelescope->m_hFormNodeWnd = NULL;
			HWND hWnd = (HWND)wParam;
			g_pSpaceTelescope->m_hFormNodeWnd = hWnd;
			if (::GetWindowLong(hWnd, GWL_EXSTYLE) & WS_EX_MDICHILD)
			{
				HWND hPWnd = ::GetParent(::GetParent(g_pSpaceTelescope->m_hFormNodeWnd));
				auto it = g_pSpaceTelescope->m_mapWinForm.find(hPWnd);
				if (it != g_pSpaceTelescope->m_mapWinForm.end())
				{
					pWnd->m_pMDIParent = it->second;
					pWnd->m_pMDIParent->m_mapMDIChild[hWnd] = pWnd;
					pWnd->m_pBrowser = it->second->m_pBrowser;
					pWnd->m_pOwnerHtmlWnd = it->second->m_pOwnerHtmlWnd;
				}
			}
			pWnd->SubclassWindow((HWND)wParam);
			//if (g_pSpaceTelescope->m_hMainWnd == NULL && ::GetParent(hWnd) == NULL)
			//	g_pSpaceTelescope->m_hMainWnd = hWnd;
			::PostMessage(g_pSpaceTelescope->m_hFormNodeWnd, WM_WINFORMCREATED, 0, 0);
		}
	}
	break;
	case WM_COSMOSMSG:
		switch (lParam)
		{
		case 20240416:
		{
			HWND hDlg = (HWND)wParam;
			if (::IsWindow(hDlg) && g_pSpaceTelescope->m_pMainWnd == NULL)
			{
				g_pSpaceTelescope->m_pMainWnd = new CWebRuntimeWnd();
				g_pSpaceTelescope->m_pMainWnd->SubclassWindow(hDlg);
			}
		}
		break;
		case 20240409:
		{
			g_pSpaceTelescope->m_bIsProcessCmdforNewOrOpen = wParam ? false : true;
		}
		break;
		case 20240324:
		{
			if (g_pSpaceTelescope->m_pCLRProxy) {
				HWND hTopWnd = ::GetAncestor((HWND)wParam, GA_ROOT);
				if (hTopWnd == NULL)
					hTopWnd = (HWND)wParam;
				g_pSpaceTelescope->m_pCLRProxy->ResetMenuStripState(hTopWnd);
				EnumThreadWindows(g_pSpaceTelescopeImpl->m_dwThreadID, CSpaceTelescope::EnumPopupMenuWndProc, (LPARAM)hTopWnd);
			}
		}
		break;
		case TANGRAM_CHROME_APP_INIT:
		{
			if (g_pSpaceTelescope->m_nAppType == APP_BROWSER_ECLIPSE || g_pSpaceTelescope->m_bEclipse)
			{
				IWebRTCLRImpl* pProxy = g_pSpaceTelescope->m_pCLRProxy;
				g_pSpaceTelescope->InitEclipseApp();
				if (pProxy)
				{
					pProxy->CosmosAction(CComBSTR("EndInitEclipseApp"), nullptr);
				}
			}
			else if (g_pSpaceTelescope->m_hMainWnd == NULL && g_pSpaceTelescope->m_pUniverseAppProxy)
				g_pSpaceTelescope->m_hMainWnd = g_pSpaceTelescope->m_pUniverseAppProxy->InitWebRTApp();
		}
		break;
		case 10001000:
		{
			if (g_pSpaceTelescope->m_nAppID != 9 && g_pSpaceTelescope->m_bEclipse == false && g_pSpaceTelescope->m_bOfficeApp == false)
			{
				::PostMessage(g_pSpaceTelescope->m_hCosmosWnd, WM_HUBBLE_APPQUIT, 0, 0);
			}
		}
		break;
		case 20240220:
		{
			switch (wParam) {
			case 0:
			{
				::PostMessageW(hWnd, WM_COSMOSMSG, 1, 20240220);
			}
			break;
			case 1:
			{
				::PostMessageW(hWnd, WM_COSMOSMSG, 2, 20240220);
				//auto t = create_task([hWnd]()
				//	{
				//		while (1)
				//		{
				//			Sleep(500);
				//			if (::GetModuleHandle(_T("mfc140u.dll")) || ::GetModuleHandle(_T("mfc140ud.dll")))
				//				::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT, 0, 0);
				//			else
				//				::PostAppMessage(g_pSpaceTelescope->m_dwThreadID, WM_CHROMEAPPINIT, 0, 0);
				//			break;
				//		}
				//		return;
				//	});
			}
			break;
			case 2:
			{
				HMODULE hModule = ::GetModuleHandle(_T("WebRTHelper.dll"));
				DWORD dw = ::FreeLibrary(hModule);
				while (dw)
					dw = ::FreeLibrary(hModule);
				if (::GetModuleHandle(_T("WebRTHelper.dll")) == NULL) {
					::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT, 1, 1);
				}
			}
			break;
			}
		}
		break;
		case 20240221:
		{
			switch (wParam) {
			case 0:
			{
				if (g_pSpaceTelescope->m_pCLRProxy == NULL)
					g_pSpaceTelescope->LoadCLR();
				::PostMessageW(hWnd, WM_COSMOSMSG, 1, 20240221);

			}
			break;
			case 1:
			{
				if (g_pSpaceTelescope->m_pCLRProxy)
				{
					::PostMessageW(hWnd, WM_COSMOSMSG, 2, 20240221);
					//auto t = create_task([hWnd]()
					//	{
					//		while (1)
					//		{
					//			Sleep(500);
					//			::PostMessageW(hWnd, WM_COSMOSMSG, 3, 20240221);
					//			break;
					//		}
					//		return;
					//	});
					//g_pSpaceTelescope->m_pCLRProxy->CosmosAction(CComBSTR("startclrapp"), nullptr);
				}
			}
			break;
			case 2:
			{
				HMODULE hModule = ::GetModuleHandle(_T("WebRTHelper.dll"));
				DWORD dw = ::FreeLibrary(hModule);
				while (dw)
					dw = ::FreeLibrary(hModule);
				if (::GetModuleHandle(_T("WebRTHelper.dll")) == NULL) {
					::PostMessageW(hWnd, WM_COSMOSMSG, 3, 20240221);
				}
			}
			break;
			case 3:
			{
				g_pSpaceTelescope->m_pCLRProxy->CosmosAction(CComBSTR("startclrapp"), nullptr);
			}
			break;
			}
		}
		break;
		case 20240222:
		{
			switch (wParam) {
			case 0:
			{
				::PostMessageW(hWnd, WM_COSMOSMSG, 1, 20240222);
			}
			break;
			case 1:
			{
				::PostMessageW(hWnd, WM_COSMOSMSG, 2, 20240222);
			}
			break;
			case 2:
			{
				HMODULE hModule = ::GetModuleHandle(_T("WebRTHelper.dll"));
				DWORD dw = ::FreeLibrary(hModule);
				while (dw)
					dw = ::FreeLibrary(hModule);
				if (::GetModuleHandle(_T("WebRTHelper.dll")) == NULL) {
					::ShowWindow(g_pSpaceTelescope->m_hMainWnd, SW_SHOWNORMAL);
					::BringWindowToTop(g_pSpaceTelescope->m_hMainWnd);
					g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(NULL, _T("chrome://newtab|"));
				}
			}
			break;
			}
		}
		break;
		case 20240223:
		{
			HMODULE hModule = ::GetModuleHandle(_T("WebRTHelper.dll"));
			DWORD dw = ::FreeLibrary(hModule);
			while (dw)
				dw = ::FreeLibrary(hModule);
			if (::GetModuleHandle(_T("WebRTHelper.dll")) == NULL) {
				::ShowWindow(g_pSpaceTelescope->m_hMainWnd, SW_SHOWNORMAL);
				::BringWindowToTop(g_pSpaceTelescope->m_hMainWnd);
				HWND hBrowser = g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(NULL, _T("chrome://newtab|"));
				::BringWindowToTop(hBrowser);
			}
		}
		break;
		default:
			break;
		}
		return 1;
		break;
	case WM_HUBBLE_APPQUIT:
	{
		if (g_pSpaceTelescope->m_bEclipse == false && g_pSpaceTelescope->m_bOfficeApp == false)
		{
			TRACE(_T("======== WM_HUBBLE_APPQUIT=========\n"));
			if (g_pSpaceTelescope->m_mapBrowserWnd.size())
			{
				g_pSpaceTelescope->m_bChromeNeedClosed = true;
				auto it = g_pSpaceTelescope->m_mapBrowserWnd.begin();
				((CBrowser*)it->second)->SendMessageW(WM_CLOSE, 0, 0);
			}
			if (g_pSpaceTelescope->m_mapMDIParent.size() == 0)
			{
				::PostAppMessage(::GetCurrentThreadId(), WM_QUIT, 0, 0);
			}
		}
	}
	break;
	case WM_ECLIPSEWORKBENCHCREATED:
	{
		HWND hEclipseWorkBench = (HWND)lParam;
		if (wParam || ::IsMenu(::GetMenu(hEclipseWorkBench)))
		{
			auto it = g_pSpaceTelescope->m_mapWorkBenchWnd.find(hEclipseWorkBench);
			if (it == g_pSpaceTelescope->m_mapWorkBenchWnd.end())
			{
				if (g_pSpaceTelescope->m_hEclipseHideWnd == nullptr)
				{
					for (auto& it : g_pSpaceTelescope->m_vecEclipseHideTopWnd)
					{
						::GetWindowText(it, g_pSpaceTelescope->m_szBuffer, MAX_PATH);
						CString strText = CString(g_pSpaceTelescope->m_szBuffer);
						if (strText.CompareNoCase(_T("PartRenderingEngine's limbo")) == 0)
						{
							g_pSpaceTelescope->m_hEclipseHideWnd = it;
							::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, 0, 20191117);
							break;
						}
					}
				}

				CEclipseWnd* pEclipseWnd = new CComObject<CEclipseWnd>;
				HWND hParent = GetWindow(hEclipseWorkBench, GW_CHILD);
				HWND hClient = GetWindow(hParent, GW_CHILD);
				pEclipseWnd->m_hClient = hClient;
				if (hClient)
					::SetWindowLongPtr(pEclipseWnd->m_hClient, GWLP_ID, AFX_IDW_PANE_FIRST);

				g_pSpaceTelescope->m_mapWorkBenchWnd[hEclipseWorkBench] = pEclipseWnd;
				pEclipseWnd->SubclassWindow(hEclipseWorkBench);
				::PostMessage(hEclipseWorkBench, WM_COSMOSMSG, 19820911, 0);
				pEclipseWnd->CreatePage(true);
			}
		}
	}
	break;
	}

	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK CUniverse::CosmosExtendedWndProc(_In_ HWND hWnd, UINT msg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (msg)
	{
	case WM_BROWSERLAYOUT:
	{
		if (lParam == 0)
		{
			HWND m_hChildWnd = (HWND)wParam;
			if (::IsWindow(m_hChildWnd))
			{
				RECT rc;
				::GetClientRect(hWnd, &rc);
				::SetWindowPos(m_hChildWnd, HWND_BOTTOM, 0, 0, rc.right, rc.bottom, /*SWP_NOREDRAW*/SWP_FRAMECHANGED | SWP_NOACTIVATE);
				::SendMessage(hWnd, WM_SETREDRAW, 1, 0);
			}
		}
		if (lParam == 100)
		{
			HWND m_hBrowserWnd = (HWND)wParam;
			if (::IsWindow(m_hBrowserWnd))
			{
				PostMessage(m_hBrowserWnd, WM_BROWSERLAYOUT, 0, 7);
				//RECT rc;
				//::GetClientRect(m_hBrowserWnd, &rc);
				//::SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, rc.right, rc.bottom, /*SWP_NOREDRAW*/SWP_FRAMECHANGED | SWP_NOACTIVATE);
				//::SendMessage(hWnd, WM_SETREDRAW, 1, 0);
			}
		}
	}
	break;
	case WM_WINDOWPOSCHANGED:
	{
		HWND m_hChildWnd = (HWND)::GetWindowLongPtr(hWnd, GWLP_USERDATA);
		if (::IsWindow(m_hChildWnd) && ::IsWindowVisible(hWnd))
		{
			RECT rc;
			::GetClientRect(m_hChildWnd, &rc);
			WINDOWPOS* lpwndpos = (WINDOWPOS*)lParam;
			if (rc.right != lpwndpos->cx || rc.bottom != lpwndpos->cy)
				::SetWindowPos(m_hChildWnd, HWND_BOTTOM, 0, 0, lpwndpos->cx, lpwndpos->cy, /**/SWP_FRAMECHANGED | SWP_NOREDRAW | SWP_NOACTIVATE);
		}
	}
	break;
	case WM_HUBBLE_DATA:
	{
		switch (lParam)
		{
		case 20200203:
		{
			LRESULT lRes = ::DefWindowProc(hWnd, msg, wParam, lParam);
			CWebView* m_pHtmlWnd = (CWebView*)::GetWindowLongPtr(hWnd, GWLP_USERDATA);
			if (m_pHtmlWnd->m_pChromeRenderFrameHost)
			{
				IPCMsg* pMsg = (IPCMsg*)wParam;
				m_pHtmlWnd->m_pChromeRenderFrameHost->SendCosmosMessage(pMsg);
				g_pSpaceTelescope->m_pCurrentIPCMsg = nullptr;
			}
		}
		break;
		default:
			break;
		}
	}
	break;
	}

	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

std::wstring CUniverse::json_to_xml(wstring& jsonStr) {
	return g_pSpaceTelescope->Json2Xml(jsonStr, true);
}

extern HWND    topWindow;
//bool bChromeRTApp = false;
//typedef bool(__stdcall* _IsBrowserModel)(bool bSupportCrashReporting, void*);

LRESULT CUniverse::CBTProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (g_pSpaceTelescope == nullptr)
		return 0;
	LRESULT hr = CallNextHookEx(g_pSpaceTelescope->m_hCBTHook, nCode, wParam, lParam);
	HWND hWnd = (HWND)wParam;
	switch (nCode)
	{
	case HCBT_CREATEWND:
	{
		//if (bChromeRTApp == false) {
		//	HMODULE hModuleAgent = ::GetModuleHandle(_T("AIGCAgent.dll"));
		//	if (hModuleAgent) {
		//		_IsBrowserModel FuncIsBrowserModel;
		//		FuncIsBrowserModel =
		//			(_IsBrowserModel)GetProcAddress(hModuleAgent, "IsBrowserModel");
		//		if (FuncIsBrowserModel != NULL) {
		//			bool bRet = FuncIsBrowserModel(false, nullptr);
		//			if (bRet)
		//				bChromeRTApp = true;
		//		}
		//	}
		//}
		CBT_CREATEWND* pCreateWnd = (CBT_CREATEWND*)lParam;
		HWND hPWnd = pCreateWnd->lpcs->hwndParent;
		DWORD dwID = (DWORD)pCreateWnd->lpcs->hMenu;
		if (dwID == AFX_IDW_PANE_FIRST) {
			if ((::GetWindowLong(hPWnd, GWL_EXSTYLE) & WS_EX_MDICHILD) || ::GetParent(hPWnd) == NULL)
				::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)hWnd, 20210110);
			break;
		}
		::GetClassName(hWnd, g_pSpaceTelescope->m_szBuffer, MAX_PATH);
		CString strClassName = g_pSpaceTelescope->m_szBuffer;
		memset(g_pSpaceTelescope->m_szBuffer, 0, sizeof(g_pSpaceTelescope->m_szBuffer));
		//if (bChromeRTApp&&strClassName.Find(_T("Afx:") == 0)) {
		//	//if (UnhookWindowsHookEx(g_hCBTHook))
		//	//	//::MessageBox(NULL, L"", L"", MB_OK);
		//	return S_FALSE;
		//}

		if (strClassName.Find(_T("Afx:ControlBar:")) == 0)
		{
			if (dwID != -1)
			{
				WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
				HANDLE hHandle = ::GetProp(hPWnd, _T("WebRTFrameWndInfo"));
				if (hHandle == 0)
				{
					pWebRTFrameWndInfo = new WebRTFrameWndInfo();
					::SetProp(hPWnd, _T("WebRTFrameWndInfo"), pWebRTFrameWndInfo);
					g_pSpaceTelescope->m_mapWebRTFrameWndInfo[hPWnd] = pWebRTFrameWndInfo;
				}
				else
				{
					pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
				}
				if (pWebRTFrameWndInfo->m_hClient == NULL)
					pWebRTFrameWndInfo->m_hClient = hWnd;
				pWebRTFrameWndInfo->m_mapCtrlBarWnd[dwID] = hWnd;
			}
			break;
		}
		else if (strClassName.Find(_T("SysTreeView32")) == 0 || strClassName.Find(_T("SysTabControl32")) == 0 || strClassName.Find(_T("SysListView32")) == 0)
		{
			::PostMessage(hWnd, WM_XOBJCREATED, 0, 20210108);
			CWnd* pWnd = CWnd::FromHandlePermanent(hPWnd);
			if (pWnd == nullptr)
			{
				CWebRTWnd* _pWnd = new CWebRTWnd();
				_pWnd->SubclassWindow(hPWnd);
				_pWnd->m_hClient = hWnd;
			}
			if (strClassName.Find(_T("SysTreeView32")) == 0)
			{
				CWebRTTreeCtrl* pCtrl = new CWebRTTreeCtrl();
				pCtrl->SubclassWindow(hWnd);
			}
			else if (strClassName.Find(_T("SysListView32")) == 0)
			{
				CWebRTListCtrl* pCtrl = new CWebRTListCtrl();
				pCtrl->SubclassWindow(hWnd);
			}
			else if (strClassName.Find(_T("SysTabControl32")) == 0)
			{
				CWebRTTabCtrl* pCtrl = new CWebRTTabCtrl();
				pCtrl->SubclassWindow(hWnd);
			}
			break;
		}
		else if (strClassName.Find(_T("#32770")) == 0)
		{
			if (hPWnd == NULL)
			{
				::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)hWnd, 20210919);
			}
			else if (hPWnd && (pCreateWnd->lpcs->style & WS_CHILD)) {
				::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)hWnd, 20210110);
			}
			break;
		}

		if (strClassName == _T("Chrome_RenderWidgetHostHWND"))
		{
			if (g_pSpaceTelescope->m_bCreatingDevTool)
				::PostMessage(hPWnd, WM_COSMOSMSG, 0, (LPARAM)hWnd);
			break;
		}
		if (strClassName == _T("SWT_Window0"))
		{
			if (::IsMenu(::GetMenu(hPWnd)))
				::SendMessage(g_pSpaceTelescope->m_hCosmosWnd, WM_ECLIPSEWORKBENCHCREATED, 1, (LPARAM)hPWnd);
			else if (hPWnd == nullptr)
			{
				if (g_pSpaceTelescope->m_hEclipseHideWnd == nullptr)
					g_pSpaceTelescope->m_vecEclipseHideTopWnd.push_back(hWnd);
				::PostMessage(g_pSpaceTelescope->m_hCosmosWnd, WM_ECLIPSEWORKBENCHCREATED, 0, (LPARAM)hWnd);
			}
			break;
		}
		else if (HIWORD(pCreateWnd->lpcs->lpszClass))
		{
			LPCTSTR lpszName = pCreateWnd->lpcs->lpszName;
			g_pSpaceTelescope->WindowCreated(strClassName, lpszName, hPWnd, hWnd);
			if (g_pSpaceTelescope->m_pCLRProxy)
			{
				g_pSpaceTelescope->m_pCLRProxy->WindowCreated(strClassName, lpszName, hPWnd, hWnd);
			}
			break;
		}
		if ((pCreateWnd->lpcs->style & WS_CHILD) == 0)
		{
			LRESULT lRes = ::SendMessage(hWnd, WM_QUERYAPPPROXY, 0, 0);
			if (lRes > 0)
			{
				g_pSpaceTelescope->m_pActiveAppProxy = (IUniverseAppProxy*)lRes;
			}
		}
	}
	break;
	case HCBT_DESTROYWND:
	{
		if (g_pSpaceTelescope->m_bMainWndNotFound) {
			if (!::GetParent(hWnd))
			{
				::PostAppMessage(g_pSpaceTelescope->m_dwThreadID, WM_COSMOSMSG, 0, 20240321);
			}
		}
		HANDLE hData = RemoveProp(hWnd, _T("WebRTInfo"));
		if (hData)
		{
			WebRTInfo* pInfo = (WebRTInfo*)hData;
			delete pInfo;
		}
		if (g_pSpaceTelescope == nullptr)
			break;
		if (g_pSpaceTelescope->m_bOfficeApp)
			g_pSpaceTelescope->WindowDestroy(hWnd);
		else if (g_pSpaceTelescope->m_pCLRProxy)
			g_pSpaceTelescope->m_pCLRProxy->WindowDestroy(hWnd);
		if (g_pSpaceTelescope->m_mapXobj.size())
		{
			auto itXobj = g_pSpaceTelescope->m_mapXobj.find(hWnd);
			if (itXobj != g_pSpaceTelescope->m_mapXobj.end())
			{
				g_pSpaceTelescope->m_mapXobj.erase(itXobj);
			}
		}
		auto it1 = g_pSpaceTelescope->m_mapUIData.find(hWnd);
		if (it1 != g_pSpaceTelescope->m_mapUIData.end())
			g_pSpaceTelescope->m_mapUIData.erase(it1);
		it1 = g_pSpaceTelescope->m_mapCtrlTag.find(hWnd);
		if (it1 != g_pSpaceTelescope->m_mapCtrlTag.end())
			g_pSpaceTelescope->m_mapCtrlTag.erase(it1);

		auto it4 = g_pSpaceTelescope->m_mapWebRTFrameWndInfo.find(hWnd);
		if (it4 != g_pSpaceTelescope->m_mapWebRTFrameWndInfo.end())
		{
			delete it4->second;
			g_pSpaceTelescope->m_mapWebRTFrameWndInfo.erase(it4);
		}
		if (hWnd == g_pSpaceTelescope->m_hMainWnd && g_pSpaceTelescope->m_nAppType != APP_BROWSER_ECLIPSE && g_pSpaceTelescope->m_nAppType != APP_ECLIPSE)
		{
			if (theApp.m_bHostCLR && g_pSpaceTelescope->m_nAppType == APP_BROWSERAPP)
				g_pSpaceTelescope->m_nAppType = APP_BROWSER;
			if (::IsWindow(g_pSpaceTelescope->m_hCosmosWnd)) {
				::SetParent(g_pSpaceTelescope->m_hCosmosWnd, hWnd);
				//	::DestroyWindow(g_pSpaceTelescope->m_hCosmosWnd);
			}
			if (theApp.m_bHostCLR && g_pSpaceTelescope->m_nAppType == 0)
				::PostQuitMessage(20191116);
		}
		if (g_pSpaceTelescope->m_pMainWnd && hWnd == g_pSpaceTelescope->m_pMainWnd->m_hWnd)
		{
			if (::IsWindow(g_pSpaceTelescope->m_hCosmosWnd)) {
				::SetParent(g_pSpaceTelescope->m_hCosmosWnd, hWnd);
				//	::DestroyWindow(g_pSpaceTelescope->m_hCosmosWnd);
			}
			::PostQuitMessage(20191116);
		}
	}
	break;
	case HCBT_MINMAX:
		switch (lParam)
		{
		case SW_MINIMIZE:
		{
			if (::GetWindowLong(hWnd, GWL_EXSTYLE) & WS_EX_MDICHILD)
				::SendMessage(hWnd, WM_MDICHILDMIN, 0, 0);
		}
		break;
		case SW_RESTORE:
		case SW_MAXIMIZE:
		{
			::PostMessage(hWnd, WM_COSMOSMSG, 1, 20200115);
		}
		break;
		}
		break;
	case HCBT_ACTIVATE:
	{
		g_pSpaceTelescope->m_hActiveWnd = hWnd;
		if (g_pSpaceTelescope->m_pCLRProxy)
		{
			g_pSpaceTelescope->m_bWinFormActived = g_pSpaceTelescope->m_pCLRProxy->IsWinForm(hWnd);
			if (g_pSpaceTelescope->m_bWinFormActived)
			{
				g_pSpaceTelescope->m_pNucleus = nullptr;
			}
		}
		LRESULT lRes = ::SendMessage(hWnd, WM_QUERYAPPPROXY, 0, 0);
		if (lRes > 0)
		{
			g_pSpaceTelescope->m_pActiveAppProxy = (IUniverseAppProxy*)lRes;
			auto it = g_pSpaceTelescope->m_mapWorkBenchWnd.find(hWnd);
			if (it != g_pSpaceTelescope->m_mapWorkBenchWnd.end())
			{
				CEclipseWnd* pWnd = (CEclipseWnd*)it->second;
				g_pSpaceTelescope->m_pActiveAppProxy->OnActiveMainFrame(::GetParent(pWnd->m_hClient));
			}
			else
			{
				g_pSpaceTelescope->m_pActiveAppProxy->OnActiveMainFrame(hWnd);
			}
		}
		else
			g_pSpaceTelescope->m_pActiveAppProxy = nullptr;
	}
	break;
	}
	return hr;
}

static const int kMsgHaveWork = WM_USER + 1;

LRESULT CALLBACK CUniverse::GetMessageProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	LPMSG lpMsg = (LPMSG)lParam;
	DWORD dwID = ::GetCurrentThreadId();
	CommonThreadInfo* pThreadInfo = g_pSpaceTelescope->GetThreadInfo(dwID);
	if (lpMsg->message == WM_TIMER)
	{
		return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
	}
	if (nCode >= 0)
	{
		switch (wParam)
		{
		case PM_NOREMOVE:
		{
			switch (lpMsg->message)
			{
			case kMsgHaveWork:
			{
				ATLTRACE(_T("kMsgHaveWork\n"));
			}
			break;
			case WM_QUIT:
			{
				if (::GetCurrentThreadId() == g_pSpaceTelescope->m_dwThreadID)
				{
					if (::IsWindow(g_pSpaceTelescope->m_hCosmosWnd))
						::DestroyWindow(g_pSpaceTelescope->m_hCosmosWnd);
				}
				if (g_pSpaceTelescope->m_mapMDTWindow.size() > 1)
				{
					while (g_pSpaceTelescope->m_mapMDTWindow.size())
					{
						auto it = g_pSpaceTelescope->m_mapMDTWindow.begin();
						it->second->DestroyWindow();
						if (g_pSpaceTelescope->m_mapMDTWindow.size() == 1)
							break;
					}
				}
				if (g_pSpaceTelescope->m_pWebRTAppProxy)
					g_pSpaceTelescope->m_pWebRTAppProxy->OnWebRTClose(CosmosCloseState::ProcessQuit);
			}
			break;
			default:
				break;
			}
		}
		break;
		case PM_REMOVE:
		{
			if (g_pSpaceTelescope && g_pSpaceTelescope->m_bHostMsgLoop && g_pSpaceTelescope->m_pMessagePumpForUI)
				g_pSpaceTelescope->m_pMessagePumpForUI->OnProcessNextWindowsMessage(lpMsg);
			switch (lpMsg->message)
			{
			case WM_SYSKEYDOWN:
			{
				if (::GetAsyncKeyState(VK_MENU) < 0 &&
					g_pSpaceTelescope->m_pWebRTDelegate &&
					g_pSpaceTelescope->m_pWebRTDelegate->OnUniversePreTranslateMessage(lpMsg))
				{
					return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
				}
			}
			break;
			case WM_KEYDOWN:
			{
				CXobjWnd* pWnd = nullptr;
				CWPFView* pView = nullptr;
				if (g_pSpaceTelescope->m_bOMNIBOXPOPUPVISIBLE && lpMsg->wParam == VK_RETURN)
				{
					g_bRecturnPressed = true;
				}
				if (g_pSpaceTelescope->m_pActiveXobj)
				{
					if (g_pSpaceTelescope->m_pActiveXobj->m_nViewType != Grid)
					{
						if (g_pSpaceTelescope->m_pActiveXobj->m_nViewType == TangramWPFCtrl)
							pView = (CWPFView*)g_pSpaceTelescope->m_pActiveXobj->m_pHostWnd;
						else
							pWnd = (CXobjWnd*)g_pSpaceTelescope->m_pActiveXobj->m_pHostWnd;
						if (pWnd && ::IsChild(pWnd->m_hWnd, lpMsg->hwnd) == false)
						{
							g_pSpaceTelescope->m_pActiveXobj = nullptr;
							if (lpMsg->wParam != VK_TAB)
								break;
							else if (g_pSpaceTelescope->m_bWinFormActived == false)
							{
								if (pWnd->m_bBKWnd)
								{
									if (pWnd->PreTranslateMessage(lpMsg))
									{
										lpMsg->hwnd = NULL;
										lpMsg->lParam = 0;
										lpMsg->wParam = 0;
										lpMsg->message = 0;
										break;
									}
								}
								else if (pView)
								{
									if (pView->PreTranslateMessage(lpMsg))
									{
										lpMsg->hwnd = NULL;
										lpMsg->lParam = 0;
										lpMsg->wParam = 0;
										lpMsg->message = 0;
										break;
									}
								}
								else
									g_pSpaceTelescope->m_pNucleus = nullptr;
							}
						}
					}
				}

				switch (lpMsg->wParam)
				{
				case VK_TAB:
					if (g_pSpaceTelescope->m_bWinFormActived && g_pSpaceTelescope->m_bEnableProcessFormTabKey && g_pSpaceTelescope->m_pCLRProxy->ProcessFormMsg(g_pSpaceTelescope->m_hActiveWnd, lpMsg, 0))
					{
						break;
					}
					if (/*g_pSpaceTelescope->m_pNucleus &&*/ g_pSpaceTelescope->m_pActiveXobj && pWnd && pWnd->PreTranslateMessage(lpMsg))
					{
						lpMsg->hwnd = NULL;
						lpMsg->lParam = 0;
						lpMsg->wParam = 0;
						lpMsg->message = 0;
					}
					else
					{
						HWND hwnd = lpMsg->hwnd;
						if ((pView && pView->PreTranslateMessage(lpMsg))/*|| IsDialogMessage(lpMsg->hwnd, lpMsg)*/)
						{
							::DispatchMessage(lpMsg);
							TranslateMessage(lpMsg);
							lpMsg->hwnd = NULL;
							lpMsg->lParam = 0;
							lpMsg->wParam = 0;
							lpMsg->message = 0;
						}
						else
						{
							if (g_pSpaceTelescope->m_pBrowserFactory)
							{
								TRACE(_T("======== CUniverse=========:%x,MSG:%x\n"), lpMsg->hwnd, lpMsg->message);
								if (g_pSpaceTelescope->m_pActiveHtmlWnd)
								{
									HWND hWnd = ::GetParent(::GetParent(g_pSpaceTelescope->m_pActiveHtmlWnd->m_hWnd));
									if (hWnd && ::IsChild(hWnd, lpMsg->hwnd))
									{
										TranslateMessage(lpMsg);
										::DispatchMessage(lpMsg);
										lpMsg->hwnd = NULL;
										lpMsg->lParam = 0;
										lpMsg->wParam = 0;
										lpMsg->message = 0;
										return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
									}
									else
									{
										if (((__int64)g_pSpaceTelescope->m_pUniverseAppProxy) > 1)
										{
											if (g_pSpaceTelescope->m_pWebRTDelegate->OnUniversePreTranslateMessage(lpMsg))
											{
												return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
											}
										}
									}
								}
								else
								{
									if (((__int64)g_pSpaceTelescope->m_pUniverseAppProxy) > 1)
									{
										if (g_pSpaceTelescope->m_pWebRTDelegate->OnUniversePreTranslateMessage(lpMsg))
										{
											return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
										}
									}
								}
							}
							if (pWnd && pWnd->PreTranslateMessage(lpMsg))
							{
								::DispatchMessage(lpMsg);
								TranslateMessage(lpMsg);
								lpMsg->hwnd = NULL;
								lpMsg->lParam = 0;
								lpMsg->wParam = 0;
								lpMsg->message = 0;
							}

							//g_pSpaceTelescope->ProcessMsg(lpMsg);
						}
						if (((__int64)g_pSpaceTelescope->m_pActiveAppProxy) > 1)
							g_pSpaceTelescope->m_pActiveAppProxy->UniversePreTranslateMessage(lpMsg);
						//else if (((__int64)g_pSpaceTelescope->m_pUniverseAppProxy) > 1)
						//{
						//	g_pSpaceTelescope->m_pUniverseAppProxy->UniversePreTranslateMessage(lpMsg);
						//}
					}
					break;
				case VK_PRIOR:
				case VK_NEXT:
				case VK_HOME:
				case VK_END:
				case VK_LEFT:
				case VK_UP:
				case VK_RIGHT:
				case VK_DOWN:
				case VK_BACK:
					if (g_pSpaceTelescope->m_bWinFormActived && g_pSpaceTelescope->m_bEnableProcessFormTabKey && g_pSpaceTelescope->m_pCLRProxy->ProcessFormMsg(g_pSpaceTelescope->m_hActiveWnd, lpMsg, 0))
					{
						TranslateMessage(lpMsg);
						::DispatchMessage(lpMsg);
						lpMsg->hwnd = NULL;
						lpMsg->lParam = 0;
						lpMsg->wParam = 0;
						lpMsg->message = 0;
						return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
						break;
					}
					if (g_pSpaceTelescope->m_pNucleus && g_pSpaceTelescope->m_pActiveXobj && pWnd && pWnd->PreTranslateMessage(lpMsg))
					{
						if (g_pSpaceTelescope->m_pCLRProxy && g_pSpaceTelescope->m_pCLRProxy->IsWinForm(pWnd->m_hWnd))
						{
							//TranslateMessage(lpMsg);
							::DispatchMessage(lpMsg);
							//lpMsg->hwnd = NULL;
							//lpMsg->lParam = 0;
							//lpMsg->wParam = 0;
							//lpMsg->message = 0;
							return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
						}
						lpMsg->hwnd = NULL;
						lpMsg->lParam = 0;
						lpMsg->wParam = 0;
						lpMsg->message = 0;
						return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
					}
					if (pView)
					{
						TranslateMessage(lpMsg);
						::DispatchMessage(lpMsg);
						lpMsg->hwnd = NULL;
						lpMsg->lParam = 0;
						lpMsg->wParam = 0;
						lpMsg->message = 0;
					}
					if (g_pSpaceTelescope->m_pWebRTDelegate)
					{
						if (g_pSpaceTelescope->m_pWebRTDelegate->OnUniversePreTranslateMessage(lpMsg))
							break;
					}
					break;
				case VK_DELETE:
					if (g_pSpaceTelescope->m_pActiveXobj)
					{
						if (g_pSpaceTelescope->m_pActiveXobj->m_nViewType == ActiveX)
						{
							pWnd->PreTranslateMessage(lpMsg);
							lpMsg->hwnd = NULL;
							lpMsg->wParam = 0;
							break;
						}
						DispatchMessage(lpMsg);
						lpMsg->hwnd = NULL;
						lpMsg->wParam = 0;
					}

					break;
				case VK_RETURN:
				{
					if (g_pSpaceTelescope->m_pWebRTDelegate)
					{
						if (g_pSpaceTelescope->m_pWebRTDelegate->OnUniversePreTranslateMessage(lpMsg))
							break;
					}
					if (g_pSpaceTelescope->m_pNucleus && g_pSpaceTelescope->m_pActiveXobj)
					{
						if (pWnd && ::IsChild(pWnd->m_hWnd, lpMsg->hwnd) == false)
						{
							g_pSpaceTelescope->m_pActiveXobj = nullptr;
							g_pSpaceTelescope->m_pNucleus = nullptr;
						}
						else if (pWnd)
						{
							TranslateMessage(lpMsg);
							lpMsg->hwnd = NULL;
							lpMsg->lParam = 0;
							lpMsg->wParam = 0;
							lpMsg->message = 0;
							break;
						}
					}
					if (g_pSpaceTelescope->m_bOfficeApp)
						return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
					TranslateMessage(lpMsg);
					if (g_pSpaceTelescope->m_strExeName != _T("devenv"))
					{
						DispatchMessage(lpMsg);
						lpMsg->hwnd = NULL;
						lpMsg->lParam = 0;
						lpMsg->wParam = 0;
						lpMsg->message = 0;
						return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
					}
				}
				break;
				//case 0x41://Ctrl+A
				//case 0x43://Ctrl+C
				//case 0x56://Ctrl+V
				//case 0x58://Ctrl+X
				//case 0x5a://Ctrl+Z
				default:
					if (::GetKeyState(VK_CONTROL) < 0|| ::GetKeyState(VK_MENU) < 0)  // control or alt pressed
					{
						if (g_pSpaceTelescope->m_pActiveXobj && pWnd && !::IsWindow(pWnd->m_hWnd))
						{
							g_pSpaceTelescope->m_pActiveXobj = nullptr;
						}
						if (g_pSpaceTelescope->m_pActiveXobj)
						{
							HWND hWnd = nullptr;
							if (pWnd)
								hWnd = pWnd->m_hWnd;
							else if (pView)
								hWnd = pView->m_hWnd;
							if ((g_pSpaceTelescope->m_pActiveXobj->m_nViewType == ActiveX || g_pSpaceTelescope->m_pActiveXobj->m_strID.CompareNoCase(TGM_NUCLEUS) == 0))
							{
								if (pWnd)
									pWnd->PreTranslateMessage(lpMsg);
								lpMsg->hwnd = NULL;
								lpMsg->wParam = 0;
								break;
							}
							if (pView)
							{
								TranslateMessage(lpMsg);
								::DispatchMessage(lpMsg);
								lpMsg->hwnd = NULL;
								lpMsg->lParam = 0;
								lpMsg->wParam = 0;
								lpMsg->message = 0;
								break;
							}
							if (g_pSpaceTelescope->m_pActiveHtmlWnd)
							{
								HWND hwnd = lpMsg->hwnd;
								HWND hWnd = ::GetParent(::GetParent(g_pSpaceTelescope->m_pActiveHtmlWnd->m_hWnd));
								if (hWnd)
								{
									TranslateMessage(lpMsg);
									::DispatchMessage(lpMsg);
									lpMsg->hwnd = NULL;
									lpMsg->lParam = 0;
									lpMsg->wParam = 0;
									lpMsg->message = 0;
									return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
								}
							}
							TranslateMessage(lpMsg);
							lpMsg->wParam = 0;
						}
					}
					else
					{
						::TranslateMessage(lpMsg);
						lpMsg->hwnd = NULL;
						lpMsg->lParam = 0;
						lpMsg->wParam = 0;
						lpMsg->message = 0;
					}
					break;
				}
			}
			break;
			case WM_POWERBROADCAST:
			{
				switch (lpMsg->wParam)
				{
				case PBT_APMRESUMEAUTOMATIC:
				{
					OutputDebugString(_T("------------------UniverseAppObj PBT_APMRESUMEAUTOMATIC------------------------\n"));
					//HWND hWnd = lpMsg->hwnd;
					for (auto& it : g_pSpaceTelescope->m_mapBrowserWnd)
					{
						if (::IsWindowVisible(it.first))
						{
							CBrowser* pWnd = (CBrowser*)it.second;
							if (pWnd)
							{
								HWND hWnd = pWnd->m_pBrowser->GetActiveWebContentWnd();
								if (::IsWindowVisible(hWnd) == false)
								{
									auto it1 = g_pSpaceTelescope->m_mapWebView.find(hWnd);
									if (it1 != g_pSpaceTelescope->m_mapWebView.end())
									{
										pWnd->m_pVisibleWebView = (CWebView*)it1->second;
										ATLTRACE(_T("WebPage HWND %x, WM_POWERBROADCAST\n"), hWnd);
										it1->second->m_pChromeRenderFrameHost->ShowWebPage(true);
										if (pWnd->m_pVisibleWebView->m_hExtendWnd)
										{
											ATLTRACE(_T("WebPageExtend HWND %x, WM_POWERBROADCAST\n"), pWnd->m_pVisibleWebView->m_hExtendWnd);
											::SetParent(pWnd->m_pVisibleWebView->m_hExtendWnd, pWnd->m_hWnd);
										}
									}
									::PostMessage(hWnd, WM_COSMOSMSG, 20200131, 0);
									::PostMessage(it.first, WM_BROWSERLAYOUT, 2, 7);
								}
							}
						}
						ATLTRACE(_T("HWND %x, WM_POWERBROADCAST\n"), it.first);
						if (g_pSpaceTelescope->m_bIsDlgApp)
						{
							::RedrawWindow(g_pSpaceTelescope->m_hMainWnd, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);//| RDW_UPDATENOW ;
							//::InvalidateRect(g_pSpaceTelescope->m_hMainWnd, nullptr, true);
							ATLTRACE(_T("HWND %x, WM_POWERBROADCAST: DlgApp\n"), g_pSpaceTelescope->m_hMainWnd);
						}
					}
					for (auto& it : g_pSpaceTelescope->m_mapThreadInfo)
					{
						if (it.second)
						{
							for (auto& it2 : it.second->m_mapGalaxy)
							{
								it2.second->HostPosChanged();
								for (auto& it3 : it2.second->m_mapWPFView)
								{
									::SetWindowLongPtr(it3.second->m_hWnd, GWLP_USERDATA, 1963);
								}
							}
						}
					}
				}
				break;
				}
			}
			break;
			case WM_HUBBLE_INIT:
			{
				if (lpMsg->wParam == 20191005)
					g_pSpaceTelescope->Init();
			}
			break;
			case WM_MOUSEMOVE:
			{
				if (lpMsg->hwnd == topWindow || ::IsChild(topWindow, lpMsg->hwnd))
				{
					static CPoint PrePoint = CPoint(0, 0);
					if (MK_LBUTTON == lpMsg->wParam)
					{
						CPoint point = CPoint(GET_X_LPARAM(lpMsg->lParam), GET_Y_LPARAM(lpMsg->lParam));
						if (point != PrePoint)
						{
							CPoint ptTemp = point - PrePoint;
							CRect rcWindow;
							::GetWindowRect(topWindow, &rcWindow);
							rcWindow.OffsetRect(ptTemp.x, ptTemp.y);
							::MoveWindow(topWindow, rcWindow.left, rcWindow.top, rcWindow.Width(), rcWindow.Height(), true);
						}
						PrePoint = point;
					}
					break;
				}
				if ((long)(g_pSpaceTelescope->m_pActiveAppProxy) > 1)
				{
					g_pSpaceTelescope->m_pActiveAppProxy->MouseMoveProxy(lpMsg->hwnd);
				}
				else if (g_pSpaceTelescope->m_pUniverseAppProxy)
				{
					g_pSpaceTelescope->m_pUniverseAppProxy->MouseMoveProxy(lpMsg->hwnd);
				}
				if (g_pSpaceTelescope->m_pWebRTDelegate)
				{
					if (g_pSpaceTelescope->m_pWebRTDelegate->OnUniversePreTranslateMessage(lpMsg))
						break;
				}
				if ((long)(g_pSpaceTelescope->m_pActiveAppProxy) > 1)
					g_pSpaceTelescope->m_pActiveAppProxy->UniversePreTranslateMessage(lpMsg);
				else if (g_pSpaceTelescope->m_pUniverseAppProxy)
					g_pSpaceTelescope->m_pUniverseAppProxy->UniversePreTranslateMessage(lpMsg);
			}
			break;
			case WM_NCLBUTTONDOWN:
			case WM_NCRBUTTONDOWN:
			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
			case WM_LBUTTONUP:
				//case WM_POINTERDOWN:
				//case WM_POINTERUP:
			case WM_SETWNDFOCUSE:
			{
				g_pSpaceTelescope->ProcessMsg(lpMsg);
				if (lpMsg->message == WM_LBUTTONDOWN ||
					lpMsg->message == WM_RBUTTONDOWN ||
					lpMsg->message == WM_NCLBUTTONDOWN ||
					lpMsg->message == WM_NCRBUTTONDOWN)
				{
					::SendMessage(g_pSpaceTelescope->m_hCosmosWnd, WM_COSMOSMSG, (WPARAM)lpMsg->hwnd, 20240324);
				}
				if (g_pSpaceTelescope->m_pActiveWinFormWnd)
				{
					g_pSpaceTelescope->m_pCLRProxy->ProcessFormMsg(g_pSpaceTelescope->m_pActiveWinFormWnd->m_hWnd, lpMsg, 0);
				}
				if ((long)(g_pSpaceTelescope->m_pActiveAppProxy) > 1)
					g_pSpaceTelescope->m_pActiveAppProxy->UniversePreTranslateMessage(lpMsg);
				else if (g_pSpaceTelescope->m_pUniverseAppProxy)
					g_pSpaceTelescope->m_pUniverseAppProxy->UniversePreTranslateMessage(lpMsg);
				if (g_pSpaceTelescope->m_pWebRTDelegate)
				{
					if (g_pSpaceTelescope->m_pWebRTDelegate->OnUniversePreTranslateMessage(lpMsg))
						break;
				}
				return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
			}
			break;
			case WM_MDICHILDMIN:
				::BringWindowToTop(lpMsg->hwnd);
				break;
			case WM_CHROMEAPPINIT:
			{
				if (lpMsg->lParam == APP_WIN32 ||
					lpMsg->lParam == APP_ECLIPSE)
					break;
				TCHAR m_szBuffer[MAX_PATH];
				//HMODULE hProxyModule = ::GetModuleHandle(_T("WebRTHelper.dll"));
				typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting);
				_InitApp FuncInitApp;
				HMODULE hModule = g_pSpaceTelescope->m_hWebRTProxyModel;
				if (hModule == nullptr)
				{
					CString strAIGCAgentPath = _T("");
					if (SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer) == S_OK) {
						strAIGCAgentPath = CString(m_szBuffer);
						strAIGCAgentPath += _T("\\Tangram\\AIGCBrowser\\AIGCAgent.dll");
						if (::PathFileExists(strAIGCAgentPath)) {
							hModule = g_pSpaceTelescope->m_hWebRTProxyModel = ::LoadLibrary(strAIGCAgentPath);
						}
					}
					if (hModule == nullptr)/* && hProxyModule)*/ {
						::GetModuleFileName(::GetModuleHandle(_T("universe.dll")), m_szBuffer, MAX_PATH);
						strAIGCAgentPath = m_szBuffer;
						int nPos = strAIGCAgentPath.ReverseFind('\\');
						strAIGCAgentPath = strAIGCAgentPath.Left(nPos + 1) + _T("AIGCAgent.dll");
						hModule = g_pSpaceTelescopeImpl->m_hWebRTProxyModel = ::LoadLibrary(strAIGCAgentPath);
					}
					if (hModule == nullptr)
						hModule = ::LoadLibrary(L"AIGCAgent.dll");
					g_pSpaceTelescope->m_hWebRTProxyModel = hModule;
				}
				if (hModule) {
					FuncInitApp = (_InitApp)GetProcAddress(hModule, "InitApp");
					if (FuncInitApp != NULL) {
						if (g_pSpaceTelescope->m_pUniverseAppProxy) {
							HWND hWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(MainWnd, NULL);
							if (::IsWindow(hWnd))
							{
								g_pSpaceTelescope->m_hMainWnd = hWnd;
							}
						}

						FuncInitApp(false);
						::PostQuitMessage(0);
					}
				}
			}
			break;
			case WM_CHROMEAPPINIT + 512:
			{
				if (VirtualFreeEx((HANDLE)lpMsg->wParam, (LPVOID)lpMsg->lParam, 0, /*MEM_DECOMMIT | */MEM_RELEASE) == false) {
					DWORD dw = GetLastError();
					CString strInfo = _T("");
					strInfo.Format(_T("VirtualFreeEx Free Action failed, ErrorCode:%d"), dw);
					::MessageBox(NULL, strInfo, _T("Tangram"), MB_OK);
				}
			}
			break;
			case WM_CHROMEDEVTOOLMSG:
			{
				switch (lpMsg->wParam)
				{
				case 1:
				{
					g_pSpaceTelescope->m_bCreatingDevTool = true;
					auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(::GetActiveWindow());
					if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
					{
						ATLTRACE(_T("\n"));
					}
				}
				break;
				}
			}
			break;
			case WM_COSMOSMSG:
			{
				switch (lpMsg->lParam)
				{
				case 20240603:
				{
					HWND hBrowser = (HWND)lpMsg->wParam;
					if (::IsWindow(hBrowser)) {
						//DWORD dwStyleEx = ::GetWindowLongPtr(hBrowser, GWL_EXSTYLE) | WS_EX_TOPMOST;
						//::SetWindowLongPtr(hBrowser, GWL_EXSTYLE, dwStyleEx);
						auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
						if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
						{
							CBrowser* pBrower = (CBrowser*)it->second;
							pBrower->ModifyStyleEx(NULL, WS_EX_TOPMOST);
						}
					}
				}
				break;
				case 20240301:
				{
					if (g_pSpaceTelescope->m_pCLRProxy)
						g_pSpaceTelescope->m_pCLRProxy->CosmosAction(CComBSTR("MainFormLoad"), nullptr);
				}
				break;
				case 20220815:
				{
					CWebViewImpl* pWebView = (CWebViewImpl*)lpMsg->wParam;
					if (pWebView)
					{
						if (pWebView->m_pSession == nullptr)
							pWebView->m_pSession = g_pSpaceTelescope->CreateCloudSession(pWebView);
						pWebView->m_pSession->InsertString(_T("msgID"), _T("NEWTABPAGE"));
						pWebView->m_pSession->SendMessage();
					}
				}
				break;
				case 20210919:
				{
					HWND hWnd = (HWND)lpMsg->wParam;
					if (hWnd == g_pSpaceTelescope->m_hMainWnd)
					{
						g_pSpaceTelescope->m_bIsDlgApp = true;
						g_pSpaceTelescope->m_pMainWnd = new CWebRuntimeWnd();
						g_pSpaceTelescope->m_pMainWnd->SubclassWindow(hWnd);
					}
				}
				break;
				case 20210913:
				{
					HWND hForm = (HWND)lpMsg->wParam;
					if (::IsWindow(hForm) &&
						(!(::GetWindowLongPtr(hForm, GWL_STYLE) & WS_CHILD) || (::GetWindowLong(hForm, GWL_EXSTYLE) & WS_EX_MDICHILD)))
					{
						g_pSpaceTelescope->m_pCLRProxy->ProcessFormWorkState(hForm, 2);
					}
				}
				break;
				case 20210530:
				{
					TRACE(_T("************WM_DPICHANGED************\n"));
					HWND hTop = ::GetAncestor((HWND)lpMsg->wParam, GA_ROOT);
					::RedrawWindow((HWND)lpMsg->wParam, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_UPDATENOW);
				}
				break;
				//case 20210503:
				//{
				//	HWND hWnd = NULL;
				//	if (g_pSpaceTelescope->m_mapMDTWindow.size())
				//	{
				//		auto it = g_pSpaceTelescope->m_mapMDTWindow.begin();
				//		hWnd = it->first;
				//	}
				//	else
				//	{
				//		if (g_pSpaceTelescope->m_mapMDIParent.size())
				//		{
				//			auto it = g_pSpaceTelescope->m_mapMDIParent.begin();
				//			hWnd = it->first;
				//		}
				//	}
				//	if (hWnd)
				//		g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(QueryType::QueryDestroy, hWnd);
				//}
				//break;
				case 20210418:
				{
					HWND hWebView = (HWND)lpMsg->wParam;
					::PostMessage(hWebView, WM_COSMOSMSG, 20210411, 1);
				}
				break;
				case 20210411:
				{
					HWND hWebView = (HWND)lpMsg->wParam;
					::PostMessage(hWebView, WM_COSMOSMSG, 20210411, 0);
				}
				break;
				case 20210309:
				{
					HWND hClient = (HWND)lpMsg->wParam;
					for (auto& it : g_pSpaceTelescope->m_mapSizingBrowser)
					{
						if (::IsWindow(it.first))
						{
							it.second->m_bSZMode = false;
							SendMessage(it.first, WM_BROWSERLAYOUT, 0, 7);
						}
					}
					g_pSpaceTelescope->m_mapSizingBrowser.erase(g_pSpaceTelescope->m_mapSizingBrowser.begin(), g_pSpaceTelescope->m_mapSizingBrowser.end());
					g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(QueryType::RecalcLayout, hClient);
				}
				break;
				case 20230727:
				{
					NucleusInfo* pInfo = (NucleusInfo*)lpMsg->wParam;

					CXobj* pParent = (CXobj*)pInfo->m_pParentDisp;
					if (pParent) {
						CNucleus* pNucleus = (CNucleus*)g_pSpaceTelescope->GetNucleus(pInfo->m_hCtrlHandle);
						pParent->m_mapSubFrame[pInfo->m_strCtrlName] = pNucleus;
					}
				}
				break;
				case 20240327:
				{
					ProcessInfo* pProcessInfo = (ProcessInfo*)lpMsg->wParam;
					if (pProcessInfo && g_pSpaceTelescopeImpl->m_pWebRTMainDllLoader) {
						g_pSpaceTelescopeImpl->m_pWebRTMainDllLoader->ExtendWinApp(pProcessInfo->processHandle, pProcessInfo->processProxyPath, pProcessInfo->nDelaySecond, pProcessInfo->nDelaySecond2);
						delete pProcessInfo;
					}
				}
				break;
				case 20240329:
				{
					ProcessInfo* pProcessInfo = (ProcessInfo*)lpMsg->wParam;
					DWORD dwProcess = pProcessInfo->processID;
					DWORD mainThreadID = pProcessInfo->threadID;
					HWND hCosmosWnd = pProcessInfo->hCosmosWnd;
					delete pProcessInfo;
					auto it = g_pSpaceTelescope->m_mapProcessInfo2.find(dwProcess);
					if (it != g_pSpaceTelescope->m_mapProcessInfo2.end()) {
						HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcess);
						if (hProcess)
						{
							TCHAR m_szBuffer[MAX_PATH] = { 0 };
							memset(m_szBuffer, 0, sizeof(m_szBuffer));
							::GetModuleFileName(::GetModuleHandle(_T("universe.dll")), m_szBuffer, MAX_PATH);
							CString strWebRTPath = m_szBuffer;
							CString strWinAppProxy = CString(m_szBuffer);
							int nPos = strWinAppProxy.ReverseFind('\\');
							strWinAppProxy = strWinAppProxy.Left(nPos + 1) + _T("WebRTHelper.dll");
							if (g_pSpaceTelescopeImpl->m_pWebRTMainDllLoader) {
								TCHAR  szPathName[MAX_PATH] = { 0 };
								memset(szPathName, 0, sizeof(szPathName));
								DWORD dwPathNameSize = sizeof(szPathName);
								QueryFullProcessImageName(hProcess, 0, szPathName, &dwPathNameSize);
								CString strAppPath = szPathName;
								CString _strAppPath = szPathName;

								strAppPath.MakeLower();
								CString strExeName = _T("");
								int nPos = -1;
								nPos = strAppPath.ReverseFind('\\');
								if (nPos != -1)
									strExeName = strAppPath.Mid(nPos + 1);
								nPos = strExeName.ReverseFind('.');
								strExeName = strExeName.Left(nPos);
								strExeName.MakeLower();
								CString strConfigFile = _T("");
								CTangramXmlParse m_Parse;
								bool bCfgLoaded = false;
								CString strCfgFile = strAppPath + _T(".tangram");
								auto itCfg = g_pSpaceTelescope->m_mapProcessConfig.find(strAppPath);
								if (itCfg != g_pSpaceTelescope->m_mapProcessConfig.end())
									strConfigFile = itCfg->second;
								else {
									CString strProductName = strExeName;
									CString strCompanyPathName = strExeName + _T(" team");
									if (::PathFileExists(strCfgFile)) {
										if (m_Parse.LoadFile(strCfgFile)) {
											strProductName = m_Parse.attr(_T("productname"), _T(""));
											if (strProductName == _T(""))
												strProductName = strExeName;
											strCompanyPathName = m_Parse.attr(_T("companypathname"), _T(""));
											if (strCompanyPathName == _T(""))
												strCompanyPathName = strExeName + _T(" team");
											strProductName.MakeLower();
											strCompanyPathName.MakeLower();
										}
									}
									else
									{
										strProductName.MakeLower();
										strCompanyPathName.MakeLower();
										CString strXml = _T("<") + strExeName + _T(" />");
										m_Parse.LoadXml(strXml);
										m_Parse.put_attr(_T("companypathname"), strCompanyPathName);
										m_Parse.put_attr(_T("productname"), strProductName);
										bCfgLoaded = true;
										m_Parse.SaveFile(strCfgFile);
									}

									strConfigFile = g_pSpaceTelescope->BuildConfigDataFile(strExeName, strProductName, strCompanyPathName);

									if (!::PathFileExists(strConfigFile)) {
										m_Parse.SaveFile(strConfigFile);
									}
									g_pSpaceTelescope->m_mapProcessConfig[strAppPath] = strConfigFile;
								}
								if (bCfgLoaded == false)
									bCfgLoaded = m_Parse.LoadFile(strConfigFile);
								if (bCfgLoaded) {
									hCosmosWnd = (HWND)m_Parse.attrInt64(_T("cosmoswindowhandle"), 0);
									if (!::IsWindow(hCosmosWnd)) {
										//if (!m_Parse.attrBool(_T("CompatibilityWin10"), false)) {
										//	int nState = g_pSpaceTelescope->IsAppCompatibilityWin10(strAppPath);
										//	if (nState < 2) {
										//		CString cmd = g_pSpaceTelescope->m_strAppPath + _T("AIGCSDK\\mt.exe -nologo -manifest ");
										//		cmd += g_pSpaceTelescope->m_strAppPath + _T("AIGCSDK\\");
										//		CString strInfo = _T("The Current Application: \"") + _strAppPath + _T("\" will be restarted for adding Its Compatibility with Windows 10.");
										//		::MessageBox(NULL, strInfo, L"AIGC WebBrowser", MB_OK);
										//		cmd += nState == 1 ? _T("aigc2.manifest -outputresource:") : _T("aigc.manifest -updateresource:");
										//		cmd += _strAppPath;
										//		DWORD  dwExitCode = ERROR_NOT_SUPPORTED;
										//		::TerminateProcess(hProcess, 0);
										//		WaitForSingleObject(hProcess, INFINITE);
										//		GetExitCodeProcess(hProcess, &dwExitCode);
										//		CloseHandle(hProcess);
										//		Sleep(1000);
										//		g_pSpaceTelescope->ExecCmd(cmd, true);
										//		if (g_pSpaceTelescope->IsAppCompatibilityWin10(strAppPath) > 1) {
										//			m_Parse.put_attr(_T("CompatibilityWin10"), true);
										//			m_Parse.SaveFile(strConfigFile);
										//		}
										//		STARTUPINFO  si;
										//		PROCESS_INFORMATION process_info;
										//		ZeroMemory(&si, sizeof(si));
										//		si.cb = sizeof(si);
										//		BOOL  bReturnVal = CreateProcess(_strAppPath,
										//			NULL,
										//			NULL,           // Process handle not inheritable
										//			NULL,           // Thread handle not inheritable
										//			FALSE,          // Set handle inheritance to FALSE
										//			NORMAL_PRIORITY_CLASS,              // No creation flags
										//			NULL,           // Use parent's environment block
										//			NULL,           // Use parent's starting directory 
										//			&si,            // Pointer to STARTUPINFO structure
										//			&process_info);
										//		break;
										//	}
										//}
										m_Parse.put_attr(_T("CompatibilityWin10"), true);
										m_Parse.put_attr(_T("mainThreadID"), (_int64)mainThreadID);
										m_Parse.put_attr(_T("webrtpath"), strWebRTPath);
										m_Parse.SaveFile(strConfigFile);
										int nDelaySecond = m_Parse.attrInt(_T("delaytime"), 500);
										int nDelaySecond2 = m_Parse.attrInt(_T("delaytime2"), 1000);
										g_pSpaceTelescope->m_pWebRTMainDllLoader->ExtendWinApp(hProcess, strWinAppProxy, nDelaySecond, nDelaySecond2);
									}
								}
							}
						}
					}
				}
				break;
				case 20240402:
				{
					if (g_pSpaceTelescope->m_pUniverseAppProxy->AttachWebRT() && ::PathFileExists(g_pSpaceTelescope->m_strAppName + _T(".app.html"))) {
						g_pSpaceTelescope->m_strStartupURL = g_pSpaceTelescope->m_strAppName + _T(".app.html");
					}
				}
				break;
				case 20240401:
					g_pSpaceTelescope->StartBrowserService();
					break;
				case 20240321:
				{
					if (g_pSpaceTelescope->m_hMainWnd == NULL)
						g_pSpaceTelescope->GetMainWnd(g_pSpaceTelescope->m_nMainClientID, g_pSpaceTelescope->m_strAppProxyID);
				}
				break;
				case 20210110:
				{
					if (g_pSpaceTelescope->m_pUniverseAppProxy)
					{
						HWND hClient = (HWND)lpMsg->wParam;
						DWORD _dwID = ::GetWindowLongPtr(hClient, GWLP_ID);
						if (_dwID != AFX_IDW_PANE_FIRST)
							break;

						HWND hWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(DocView, hClient);
						if (::IsWindow(hWnd))
						{
							auto it = g_pSpaceTelescope->m_mapNuclei.find(hWnd);
							if (it != g_pSpaceTelescope->m_mapNuclei.end())
								break;
							CCloudMDTFrame* pFrameWnd = nullptr;
							CCloudMDIChild* pWnd = nullptr;
							CCloudMDIFrame* pMDIParent = nullptr;
							CNuclei* pNuclei = nullptr;
							WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(hWnd, _T("WebRTFrameWndInfo"));
							if (pWebRTFrameWndInfo)
							{
								switch (pWebRTFrameWndInfo->m_nFrameType)
								{
								case 1:
								{
									pFrameWnd = g_pSpaceTelescope->AttachCloudMDTFrame(hWnd, true);
									if (pFrameWnd)
										pFrameWnd->m_hMDTClient = hClient;
								}
								break;
								case 3:
								{
									HWND hFrame = ::GetParent(::GetParent(hWnd));
									auto itMdiParent = g_pSpaceTelescope->m_mapMDIParent.find(hFrame);
									if (itMdiParent != g_pSpaceTelescope->m_mapMDIParent.end())
									{
										pMDIParent = itMdiParent->second;
										auto it = pMDIParent->m_mapMDIChild.find(hWnd);
										if (it != pMDIParent->m_mapMDIChild.end())
											pWnd = it->second;
										else
										{
											pWnd = new CCloudMDIChild();
											pWnd->m_hMDIChildClient = hClient;
											pWnd->SubclassWindow(hWnd);
											pWnd->m_pParent = pMDIParent;
											pWnd->m_pParent->m_mapMDIChild[hWnd] = pWnd;
										}
										pMDIParent->m_bCreateNewDoc = true;
										if (pMDIParent->m_pHostBrowser)
										{
											if (pMDIParent->m_pHostBrowser->m_pVisibleWebView)
											{
												pMDIParent->m_pHostBrowser->m_pVisibleWebView->m_bCanShow = false;
											}
											pMDIParent->m_pHostBrowser->m_bSZMode = true;
											pMDIParent->m_pHostBrowser->OpenURL(CComBSTR(g_pSpaceTelescope->m_strStartupURL), BrowserWndOpenDisposition::SWITCH_TO_TAB, CComBSTR(""), CComBSTR(""));
										}
									}
								}
								break;
								}

								if (pWebRTFrameWndInfo->bControlBarProessed)
									break;
								if (pWebRTFrameWndInfo->m_nFrameType != 2)
								{
									CString strKey = g_pSpaceTelescope->m_pUniverseAppProxy->m_strCreatingDOCID;
									g_pSpaceTelescope->m_pUniverseAppProxy->m_strCreatingDOCID = _T("");
									if (strKey == _T("")) {
										if (pWebRTFrameWndInfo->m_nFrameType == 1)
											strKey = _T("defaultframe");
										else
											strKey = _T("default");
									}
									CString strTemplate = _T("");
									if (pMDIParent)
									{
										auto it = pMDIParent->m_mapDocTemplate.find(strKey);
										if (it != pMDIParent->m_mapDocTemplate.end())
										{
											strTemplate = it->second;
										}
									}
									else
									{
										auto it = g_pSpaceTelescope->m_mapDocTemplate.find(strKey);
										if (it != g_pSpaceTelescope->m_mapDocTemplate.end())
										{
											strTemplate = it->second;
										}
									}
									if (strTemplate != _T(""))
									{
										CTangramXmlParse m_Parse;
										if (m_Parse.LoadXml(strTemplate))
										{
											// add 20240527 for MDT App:
											CString strUrl = m_Parse.attr(_T("url"), _T(""));
											if (strUrl != _T("")) {
												if (pFrameWnd && g_pSpaceTelescope->m_pBrowserFactory) {
													g_pSpaceTelescope->m_pCreatingFrameWnd = pFrameWnd;
													CString str = _T("<host popup='true'><url></url></host>");
													CTangramXmlParse m_Parse;
													if (m_Parse.LoadXml(str)) {
														CTangramXmlParse* pParse = nullptr;
														m_Parse[_T("url")].put_text(strUrl);
													}
													HWND hHostBrowserWnd = g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(g_pSpaceTelescope->m_hCosmosWnd, m_Parse.xml());
												}
											}
											else {
												if (pWnd)
												{
													theApp.m_bAppStarting = true;
													if (pWnd->m_strDocTemplateKey == _T(""))
														pWnd->m_strDocTemplateKey = strKey;
													int nViewSize = pWnd->m_mapView.size();
													IXobj* _pXobj = nullptr;
													pNuclei = new CComObject<CNuclei>();
													pNuclei->m_hWnd = hWnd;
													g_pSpaceTelescope->m_mapNuclei[hWnd] = pNuclei;
													for (auto& it2 : g_pSpaceTelescope->m_mapWebRTAppProxy)
													{
														CNucleiProxy* pWebRTProxy = it2.second->OnNucleiCreated(pNuclei);
														if (pWebRTProxy)
															pNuclei->m_mapNucleiProxy[it2.second] = pWebRTProxy;
													}
													//for MDIChild Client Region:
													CTangramXmlParse* pClients = m_Parse.GetChild(_T("clients"));
													if (pClients == NULL) {
														CTangramXmlParse* pClient = m_Parse.GetChild(_T("client"));
														if (pClient)
														{
															int nClientIndex = pClient->attrInt(_T("clientid"));
															if (nViewSize > 0)
																nClientIndex = nClientIndex % nViewSize;
															__int64 nClientHandle = (__int64)pWnd->m_hMDIChildClient;
															if (nClientIndex) {
																auto it = pWnd->m_mapView.find(nClientIndex);
																if (it != pWnd->m_mapView.end())
																	nClientHandle = (__int64)it->second;
															}
															INucleus* pGalaxy = nullptr;
															pNuclei->CreateNucleus(CComVariant((__int64)hWnd), CComVariant((__int64)nClientHandle), CComBSTR(""), &pGalaxy);
															if (pGalaxy) {
																CNucleus* pNucleus = (CNucleus*)pGalaxy;
																if (pNucleus->m_pWebViewWnd == nullptr)
																	pNucleus->m_pWebViewWnd = g_pSpaceTelescope->m_pHtmlWndCreated;
																if (pWnd->m_pMDIChildNucleus == nullptr)
																	pWnd->m_pMDIChildNucleus = pNucleus;
																pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pClient->xml()), &_pXobj);
															}
														}
													}
													else {
														int nCount = pClients->GetCount();
														if (nCount) {
															for (int i = 0; i < nCount; i++) {
																CTangramXmlParse* pClient = pClients->GetChild(i);
																if (pClient)
																{
																	int nClientIndex = pClient->attrInt(_T("clientid"));
																	if (nViewSize > 0)
																		nClientIndex = nClientIndex % nViewSize;
																	auto it = pWnd->m_mapView.find(nClientIndex);
																	if (it != pWnd->m_mapView.end()) {
																		INucleus* pGalaxy = g_pSpaceTelescope->GetNucleus(it->second);;
																		pNuclei->CreateNucleus(CComVariant((__int64)hWnd), CComVariant((__int64)it->second), CComBSTR(""), &pGalaxy);
																		if (pGalaxy) {
																			CNucleus* pNucleus = (CNucleus*)pGalaxy;
																			if (pNucleus->m_pWebViewWnd == nullptr)
																				pNucleus->m_pWebViewWnd = g_pSpaceTelescope->m_pHtmlWndCreated;
																			if (pWnd->m_pMDIChildNucleus == nullptr)
																				pWnd->m_pMDIChildNucleus = pNucleus;
																			pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pClient->xml()), &_pXobj);
																			if (_pXobj) {
																				CTangramXmlParse* pCtrlItemsXmlParse = pClient->GetChild(_T("ctrlitems"));
																				if (pCtrlItemsXmlParse)
																				{
																					int nCount = pCtrlItemsXmlParse->GetCount();
																					for (int i = 0; i < nCount; i++)
																					{
																						CTangramXmlParse* pChild = pCtrlItemsXmlParse->GetChild(i);
																						//CString strName = pChild->name().MakeLower();
																						int nID = pChild->attrInt(_T("ctrlid"), 0);
																						HWND hDlgItem = ::GetDlgItem(it->second, nID);
																						if (::IsWindow(hDlgItem))
																						{
																							INucleus* pGalaxy = g_pSpaceTelescope->GetNucleus(hDlgItem);
																							if (pGalaxy == NULL) {
																								pNuclei->CreateNucleus(CComVariant((LONGLONG)it->second), CComVariant((LONGLONG)hDlgItem), CComBSTR(L"default"), &pGalaxy);
																								if (pGalaxy)
																								{
																									IXobj* pXobj = nullptr;
																									pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pChild->xml()), &pXobj);
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
													pMDIParent->m_pActiveMDIChild = pWnd;
													pWnd->m_hMDIChildClient = hClient;
													pWnd->m_pMDIChildNucleus->m_nGalaxyType = GalaxyType::MDIChildGalaxy;
													pWnd->m_strKey = strKey;
													pWnd->m_pMDIChildNucleus->m_strDocTemplateID = strKey;
													CString strAppName = _T("");
													auto itName = pMDIParent->m_mapDocAppName.find(strKey);
													if (itName != pMDIParent->m_mapDocAppName.end())
														strAppName = itName->second;
													CString strDefaultName = _T("");
													itName = pMDIParent->m_mapDocDefaultName.find(strKey);
													if (itName != pMDIParent->m_mapDocDefaultName.end())
														strDefaultName = itName->second;
													g_pSpaceTelescope->m_pUniverseAppProxy->SetFrameCaption(pWnd->m_hWnd, strDefaultName, strAppName);														CTangramXmlParse* pClient = m_Parse.GetChild(_T("hostpage"));
													bool bProcessWebPage = false;
													if (pClient == nullptr)
														bProcessWebPage = true;
													if (pClient && pMDIParent->m_pMDINucleus && pMDIParent->m_pMDINucleus->m_pWebViewWnd)
													{
														if (pMDIParent->m_pHostBrowser && pMDIParent->m_pHostBrowser->m_pVisibleWebView != pMDIParent->m_pMDINucleus->m_pWebViewWnd) {
															bProcessWebPage = false;
														}
														else if (pMDIParent->m_pMDINucleus->m_pWebViewWnd->m_pNucleus->m_strCurrentKey != strKey)
														{
															pMDIParent->m_pMDINucleus->m_pWebViewWnd->ObserveViewport(strKey, pClient->xml());
															bProcessWebPage = true;
														}
													}
													::PostMessage(pMDIParent->m_hWnd, WM_COSMOSMSG, (WPARAM)pWnd, 20210202);
												}
											}
										}
									}
								}
							}

						}
					}
				}
				break;
				case 20210111:
				{
					if (g_pSpaceTelescope->m_pUniverseAppProxy)
					{
						HWND hClient = (HWND)lpMsg->wParam;
						HWND hWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(DocView, hClient);
						if (::IsWindow(hWnd))
						{
							auto it = g_pSpaceTelescope->m_mapNuclei.find(hWnd);
							if (it != g_pSpaceTelescope->m_mapNuclei.end())
								break;
							CCloudMDTFrame* pFrameWnd = nullptr;
							WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(hWnd, _T("WebRTFrameWndInfo"));
							if (pWebRTFrameWndInfo)
							{
								switch (pWebRTFrameWndInfo->m_nFrameType)
								{
								case 1:
								{
									if (g_pSpaceTelescope->m_mapMDTWindow.size() > 1)
										break;
									auto it = g_pSpaceTelescope->m_mapMDTWindow.find(hWnd);
									if (it != g_pSpaceTelescope->m_mapMDTWindow.end()) {
										pFrameWnd = it->second;
										pFrameWnd->m_hMDTClient = hClient;
										auto task = create_task([pFrameWnd]()
											{
												Sleep(500);
												::PostAppMessage(g_pSpaceTelescope->m_dwThreadID, WM_COSMOSMSG, (WPARAM)pFrameWnd, 20240315);
												return 0;
											});
									}
								}
								break;
								case 4:
								{
									pFrameWnd = g_pSpaceTelescope->AttachCloudMDTFrame(hWnd, true);
									if (pFrameWnd)
									{
										pFrameWnd->m_hMDTClient = hClient;
									}
								}
								break;
								}
								if (pWebRTFrameWndInfo->m_nFrameType != 2)
								{
									CString strKey = g_pSpaceTelescope->m_pUniverseAppProxy->m_strCreatingDOCID;
									g_pSpaceTelescope->m_pUniverseAppProxy->m_strCreatingDOCID = _T("");
									if (strKey == _T(""))
										strKey = _T("default");
									CString strTemplate = _T("");
									auto it = g_pSpaceTelescope->m_mapDocTemplate.find(strKey);
									if (it != g_pSpaceTelescope->m_mapDocTemplate.end())
									{
										strTemplate = it->second;
										if (strTemplate != _T(""))
										{
											CTangramXmlParse m_Parse;
											if (m_Parse.LoadXml(strTemplate))
											{
												// add 20230707 for MDT App:
												if (pFrameWnd)
													g_pSpaceTelescope->m_pCreatingFrameWnd = pFrameWnd;
												CString strUrl = m_Parse.attr(_T("url"), _T(""));
												//::MessageBox(NULL, strUrl, L"", MB_OK);
												if (strUrl != _T("")) {
													if (pFrameWnd && g_pSpaceTelescope->m_pBrowserFactory) {
														CString str = _T("<host popup='true'><url></url></host>");
														CTangramXmlParse m_Parse;
														if (m_Parse.LoadXml(str)) {
															m_Parse[_T("url")].put_text(strUrl);
														}
														g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(g_pSpaceTelescope->m_hCosmosWnd, m_Parse.xml());
													}
												}
												else
													g_pSpaceTelescope->m_pHtmlWndCreated->ProcessMDTDocTemplate(strTemplate);
											}
										}
									}
								}
							}
						}
					}
				}
				break;
				case 20240315:
				{
					CCloudMDTFrame* pFrame = (CCloudMDTFrame*)lpMsg->wParam;
					if (pFrame)
					{
						CBrowser* pBrowser = pFrame->m_pBrowser;
						if (pBrowser && pBrowser->m_pParentXobj)
						{
							::SetParent(pBrowser->m_hWnd, pBrowser->m_pParentXobj->m_pHostWnd->m_hWnd);
							pBrowser->ShowWindow(SW_SHOW);
							RECT rc;
							::GetClientRect(pBrowser->m_pParentXobj->m_pHostWnd->m_hWnd, &rc);
							::SetWindowPos(pBrowser->m_hWnd, HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOREDRAW);
							for (auto& it : pFrame->m_mapView) {
								::PostMessage(it.second, WM_COSMOSMSG, 0, 20180115);
							}
						}
					}
				}
				break;
				case 20191114:
				{
					if (g_pSpaceTelescope->m_mapCreatingWorkBenchInfo.size())
					{
						g_pSpaceTelescope->InitEclipseApp();
					}
				}
				break;
				case 20201028:
				{
					if (g_pSpaceTelescope->m_hTempBrowserWnd)
					{
						g_pSpaceTelescope->m_hTempBrowserWnd = NULL;
					}
				}
				break;
				case 20191004:
				{
					if (g_pSpaceTelescope->m_pCLRProxy)
					{
						g_pSpaceTelescope->m_pCLRProxy->CosmosAction(CComBSTR("setmainform"), nullptr);
					}
				}
				break;
				case 20190511:
				{
					if (lpMsg->wParam && g_pSpaceTelescope->m_bEclipse == false)
						::DestroyWindow(g_pSpaceTelescope->m_hCosmosWnd);
				}
				break;
				case 20191117:
				{
					if (g_pSpaceTelescope->m_pUniverseAppProxy)
						g_pSpaceTelescope->m_pUniverseAppProxy->EclipseAppInit();
				}
				break;
				case 2019111701:
				{
					if (g_pSpaceTelescope->m_mapXobjForHtml.size())
					{
						for (auto& it : g_pSpaceTelescope->m_mapXobjForHtml)
						{
							it.first->put_URL(CComBSTR(it.second));
						}
						g_pSpaceTelescope->m_mapXobjForHtml.erase(g_pSpaceTelescope->m_mapXobjForHtml.begin(), g_pSpaceTelescope->m_mapXobjForHtml.end());
					}
				}
				break;
				case 20191022:
				{
					if (g_pSpaceTelescope->m_pCLRProxy == nullptr)
					{
						g_pSpaceTelescope->LoadCLR();
					}
					if (g_pSpaceTelescope->m_pCLRProxy)
					{
						g_pSpaceTelescope->m_pCLRProxy->CosmosAction(CComBSTR("startclrapp"), nullptr);
					}
				}
				break;
				}
			}
			break;
			case WM_CHROMEOMNIBOXPOPUPVISIBLE:
			{
				g_pSpaceTelescope->m_bOMNIBOXPOPUPVISIBLE = lpMsg->lParam ? true : false;
				auto it = g_pSpaceTelescope->m_mapBrowserWnd.find((HWND)lpMsg->wParam);
				if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
				{
					CWebView* pWnd = ((CBrowser*)it->second)->m_pVisibleWebView;
					if (pWnd && ::IsWindow(pWnd->m_hWnd) && pWnd->m_pNucleus)
					{
						IXobj* pXobj = nullptr;
						if (g_bRecturnPressed == false)
						{
							pWnd->m_pNucleus->Observe(lpMsg->lParam ? CComBSTR("__default__key__for__chrome__") : CComBSTR(pWnd->m_strCurKey), lpMsg->lParam ? CComBSTR(g_pSpaceTelescope->m_strDefaultXml) : CComBSTR(_T("")), &pXobj);
							::SendMessage(it->first, WM_BROWSERLAYOUT, 0, 4);
						}
						g_bRecturnPressed = false;
					}
				}
			}
			break;
			}
		}
		break;
		default:
			break;
		}
	}

	return CallNextHookEx(pThreadInfo->m_hGetMessageHook, nCode, wParam, lParam);
}

int CUniverse::Run()
{
	return CWinThread::Run();
}

void CUniverse::SetHook(DWORD ThreadID)
{
	CommonThreadInfo* pThreadInfo = g_pSpaceTelescope->GetThreadInfo(ThreadID);
	if (pThreadInfo && pThreadInfo->m_hGetMessageHook == NULL)
	{
		pThreadInfo->m_hGetMessageHook = SetWindowsHookEx(WH_GETMESSAGE, GetMessageProc, NULL, ThreadID);
	}
}

CString CUniverse::GetFileVer()
{
	DWORD dwHandle, InfoSize;
	CString strVersion;

	struct LANGANDCODEPAGE
	{
		WORD wLanguage;
		WORD wCodePage;
	}*lpTranslate;
	unsigned int cbTranslate = 0;

	TCHAR cPath[MAX_PATH] = { 0 };
	::GetModuleFileName(NULL, cPath, MAX_PATH);
	InfoSize = GetFileVersionInfoSize(cPath, &dwHandle);


	char* InfoBuf = new char[InfoSize];

	GetFileVersionInfo(cPath, 0, InfoSize, InfoBuf);
	VerQueryValue(InfoBuf, TEXT("\\VarFileInfo\\Translation"), (LPVOID*)&lpTranslate, &cbTranslate);

	TCHAR SubBlock[300] = { 0 };

	wsprintf(SubBlock, TEXT("\\StringFileInfo\\%04x%04x\\ProductVersion"), lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);

	TCHAR* lpBuffer = NULL;
	unsigned int dwBytes = 0;
	VerQueryValue(InfoBuf, SubBlock, (void**)&lpBuffer, &dwBytes);
	if (lpBuffer != NULL)
	{
		strVersion.Format(_T("%s"), (TCHAR*)lpBuffer);
	}

	delete[] InfoBuf;
	return strVersion;
}

JNIEXPORT void JNICALL Java_Tangram_Host_Tangram_InitTangram(JNIEnv* env, jobject obj, jobject jTangram, jobject jGalaxyCluster, jobject jGalaxy, jobject jWndXobj)
{
	jclass cls = env->GetObjectClass(obj);

	return;
}
