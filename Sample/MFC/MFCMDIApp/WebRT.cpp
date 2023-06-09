/********************************************************************************
 *           AIGC for Desktop Application - Version 1.0.0.202203120001
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

#include "WebRT.h"
#include "TangramXmlParse.cpp"

IWebRT* g_pWebRT = nullptr;

namespace CommonUniverse {
	typedef IWebRT* (__stdcall* GetWebRT)();
	typedef CWebRTImpl* (__stdcall* GetWebRTImpl)(IWebRT**);
	typedef bool(__stdcall* _IsBrowserModel)(bool bSupportCrashReporting, void*);
	_IsBrowserModel FuncIsBrowserModel;
	CWebRTImpl* g_pSpaceTelescopeImpl = nullptr;

	class CWebRTProxy : public IWebRTDelegate {
	public:
		CWebRTProxy() {};
		virtual ~CWebRTProxy() {}

		// IWebRTDelegate:
		virtual bool OnAppIdle(BOOL& bIdle, LONG lCount) {
			return true;
		}

		virtual bool DoIdleWork() {
			if (g_pSpaceTelescopeImpl && g_pSpaceTelescopeImpl->m_hMainWnd &&
				::IsWindow(g_pSpaceTelescopeImpl->m_hMainWnd) == false)
				g_pSpaceTelescopeImpl->m_hMainWnd = NULL;
			return false;
		}

		virtual bool IsAppIdleMessage() {
			return false;
		}

		virtual void ProcessMsg(MSG* msg) {
			::TranslateMessage(msg);
			::DispatchMessage(msg);
		}

		virtual void ForegroundIdleProc() {
		}

		virtual bool OnUniversePreTranslateMessage(MSG* pMsg) {
			return TRUE;
		}

		virtual HICON GetAppIcon(int nIndex)
		{
			if (g_pSpaceTelescopeImpl->m_hMainWnd) {
				switch (nIndex) {
				case 0:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pSpaceTelescopeImpl->m_hMainWnd, GCLP_HICON));
					break;
				case 1:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pSpaceTelescopeImpl->m_hMainWnd, GCLP_HICONSM));
					break;
				}
			}
			else
			{
				TCHAR m_szBuffer[MAX_PATH];
				::GetModuleFileName(GetModuleHandle(NULL), m_szBuffer, MAX_PATH);
				SHFILEINFOW info;
				if (SHGetFileInfoW(m_szBuffer,
					FILE_ATTRIBUTE_NORMAL,
					&info,
					sizeof(info),
					SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
				{
					return info.hIcon;
				}
			}
			return NULL;
		}
	};

	CWebRTProxy theAppProxy;

	CAIGCApp::CAIGCApp() {
		m_strExeName = _T("");
		m_strProviderID = _T("");
	}

	CAIGCApp::~CAIGCApp() {
		if (m_pSpaceTelescopeImpl) {
			m_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID, nullptr);
			m_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
	}

	bool CAIGCApp::WebRTInit(CString strID) {
		HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
		if (hModule == nullptr)
			hModule = ::LoadLibrary(L"AIGCAgent.dll");
		if (hModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
				m_szBuffer) == S_OK) {
				CString strChromeRTFilePath = CString(m_szBuffer);
				strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
				if (::PathFileExists(strChromeRTFilePath)) {
					hModule = ::LoadLibrary(strChromeRTFilePath);
				}
			}
			if (hModule == nullptr)
				hModule = ::LoadLibrary(L"AIGCAgent.dll");
		}
		if (hModule) {
			BOOL isBrowserModel = false;
			FuncIsBrowserModel =
				(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
			if (FuncIsBrowserModel != NULL) {
				isBrowserModel = FuncIsBrowserModel(false, this);
				if (isBrowserModel)
					return false;
			}
		}

		TCHAR m_szBuffer[MAX_PATH];
		TCHAR szDriver[MAX_PATH] = { 0 };
		TCHAR szDir[MAX_PATH] = { 0 };
		TCHAR szExt[MAX_PATH] = { 0 };
		TCHAR szFile2[MAX_PATH] = { 0 };
		::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
		_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
		CString strTangramDll = szDriver;
		m_strExeName = szFile2;
		strTangramDll += szDir;
		strTangramDll += _T("universe.dll");
		HMODULE hModule2 = hModule;
		hModule = ::LoadLibrary(strTangramDll);
		if (hModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = m_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
			g_pSpaceTelescopeImpl->m_hWebRTProxyModel = hModule2;

			m_strProviderID += _T("host");
			m_strProviderID.MakeLower();

			m_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
			m_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
			g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
				static_cast<IUniverseAppProxy*>(this));
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
				static_cast<IWindowProvider*>(this));
			if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
				g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
				::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
					(WPARAM)m_pSpaceTelescopeImpl->m_pWebRTDelegate,
					g_pSpaceTelescopeImpl->m_nAppType);
		}
		return true;
	}

	CXobjProxy* CAIGCApp::OnXobjInit(IXobj* pNewNode) {
		CComBSTR bstrName("");
		pNewNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pNewNode->get_NameAtWindowPage(&bstrName2);
		return nullptr;
	}

	CNucleusProxy* CAIGCApp::OnNucleusCreated(INucleus* pNewFrame) {
		__int64 h = 0;
		pNewFrame->get_HWND(&h);
		CComBSTR bstrName("");
		pNewFrame->get_Name(&bstrName);
		return nullptr;
	}

	CNucleiProxy* CAIGCApp::OnNucleiCreated(INuclei* pNuclei) {
		CNucleiProxy* pNucleiProxy = nullptr;
		__int64 h = 0;
		pNuclei->get_Handle(&h);
		if (h) {
			if (pNucleiProxy)
				pNucleiProxy->m_bAutoDelete = false;
		}
		return pNucleiProxy;
	}

	BOOL CAIGCApp::InitApplication() {
		if (WebRTInit(_T("")))
			return ProcessAppType(m_bCrashReporting);
		else
			return false;
	}

	bool CAIGCApp::ProcessAppType(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(m_strExeName + _T(".app.html")) == false) &&
			(::PathFileExists(m_strExeName + _T(".html")) == false);
		if (bWin32)
			return true;
		if (m_pSpaceTelescopeImpl) {
			switch (m_pSpaceTelescopeImpl->m_nAppType) {
			case APP_WIN32:
				return true;
				break;
			case APP_BROWSER:
			case APP_BROWSER_ECLIPSE: {
				m_pSpaceTelescopeImpl->m_hMainWnd = NULL;
				HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
				if (hModule == nullptr)
					hModule = ::LoadLibrary(L"AIGCAgent.dll");
				if (hModule == nullptr) {
					TCHAR m_szBuffer[MAX_PATH];
					if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
						m_szBuffer) == S_OK) {
						CString strChromeRTFilePath = CString(m_szBuffer);
						strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
						if (::PathFileExists(strChromeRTFilePath)) {
							hModule = ::LoadLibrary(strChromeRTFilePath);
						}
					}
					if (hModule == nullptr)
						hModule = ::LoadLibrary(L"AIGCAgent.dll");
				}
				if (hModule) {
					typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
					_InitApp _pInitAppFunction;
					_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
					if (_pInitAppFunction != NULL) {
						m_bBuiltInBrowser = true;
						_pInitAppFunction(bCrashReporting, m_pSpaceTelescopeImpl->m_pWebRTDelegate);
						return false;
					}
				}
			} break;
			case APP_ECLIPSE:
				if (g_pWebRT && !m_pSpaceTelescopeImpl->m_bIsEclipseInit) {
					g_pWebRT->InitEclipseApp();
					return false;
				}
				break;
			}
		}
		return true;
	}

	BOOL CAIGCApp::IsBrowserModel(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(m_strExeName + _T(".app.html")) == false) &&
			(::PathFileExists(m_strExeName + _T(".html")) == false);
		if (bWin32 == false) {
			HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
			if (hModule == nullptr)
				hModule = ::LoadLibrary(L"AIGCAgent.dll");
			if (hModule) {
				m_bCrashReporting = bCrashReporting;
				FuncIsBrowserModel =
					(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
				if (FuncIsBrowserModel != NULL) {
					return FuncIsBrowserModel(bCrashReporting, this);
				}
			}
		}

		return false;
	};

	CWebRTWindowProviderApp::CWebRTWindowProviderApp() {
		m_hModule = NULL;
		m_strProviderID = _T("");
	}

	CWebRTWindowProviderApp::~CWebRTWindowProviderApp() {
		if (g_pSpaceTelescopeImpl) {
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
	}

	bool CWebRTWindowProviderApp::WebRTInit(CString strID) {
		strID.Trim();
		if (strID == _T(""))
			strID = _T("views");
		if (g_pSpaceTelescopeImpl == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			TCHAR szDriver[MAX_PATH] = { 0 };
			TCHAR szDir[MAX_PATH] = { 0 };
			TCHAR szExt[MAX_PATH] = { 0 };
			TCHAR szFile2[MAX_PATH] = { 0 };
			::GetModuleFileName(m_hModule, m_szBuffer, MAX_PATH);
			_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
			CString strDllName = szFile2;
			m_strProviderID = strDllName + _T(".") + strID;
			HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
			if (hModule) {
				typedef CWebRTImpl* (__stdcall* GetWebRTImpl)(IWebRT**);
				GetWebRTImpl _pWebRTFunction;
				_pWebRTFunction =
					(GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
				IWebRT* pWebRT = nullptr;
				g_pSpaceTelescopeImpl = _pWebRTFunction(&pWebRT);
				m_strProviderID.MakeLower();
				g_pSpaceTelescopeImpl->InserttoDataMap(
					1, m_strProviderID, static_cast<IWindowProvider*>(this));
				return true;
			}
		}
		return false;
	}
}  // namespace CommonUniverse
