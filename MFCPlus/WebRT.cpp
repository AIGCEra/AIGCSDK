/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202112150001 *
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 *
 * Web Runtime is a new, subversive and Internet Oriented Development Technology
 * for Windows Desktop Software. Its core idea is that, relying on the
 *open-source project of Chromium, developers are allowed to use their familiar
 *software development technology to realize the Main Process of their
 *application system as the Browser Process of Modern Web Browser. Because the
 *Main Process is realized by the developers themselves, the application system
 *developed in this way is completely different from modern web browser. This
 *kind of application will integrate the infrastructure of modern web browser as
 *a part of the system model, the application system contains not only the
 *browser window inherent in the browser, but also other desktop elements
 *oriented to the application, such as WinForms, Java and other mature software
 *elements.
 *
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web
 *pages, which are composed of standard DOM elements and binary components
 *supported by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet
 *based on modern javscript/Web technology.
 *
 * Built-in Full-Featured Modern Web Browser Subsystem
 *		Since the main process of the application system is essentially
 *a Browser Process, the application system can naturally create a new browser
 *window. The difference with standard browsers is that we allow the browser
 *window to be a child window of other windows. in sub-window model, we see a
 *brand-new scene: a multi-tab browser sub-window, we think this structure is
 *more suitable for organizing specific applications. Of course, the application
 *system fully supports the creation of an independent browser window as a part
 *of the complete application system, and the browser window serves as a natural
 *extension of the ecological chain to ensure the richness and diversity of the
 *application system content. DOM Plus: Because a large number of mature binary
 *components that conform to industry standards have formed a wealth of software
 *asset accumulation, web runtime allows developers to regard these existing
 *accumulation as new DOM elements and then become a part of web pages, this
 *starting point eventually forms "DOM Plus". DOM plus is a natural extension of
 *standard DOM for desktop applications, similar to the extension from "real
 *number system" to "complex number system" in mathematical theory. Undoubtedly,
 * for the development of mathematics, from "real number system" to "complex
 *number system" is a huge leap, which can be said to be a decisive change in
 *the development of modern mathematics. We hope that the evolution from "DOM"
 *to "DOM plus" will have a similar effect, which is bound to be a huge change
 *from desktop software to Internet desktop software. Different from earlier IE,
 *based on the sandbox mechanism of Modern Web Browser, we let these binary
 *elements run in the Browser Process, completely isolated from the Browser's
 *Renderer Process. This makes full use of the security mechanisms of modern
 * browsers and also takes into account the accumulation of mature software
 *component technologies. Based on such considerations, existing development
 *technologies such as .NET, COM, Java, etc. can be fully applied to Internet
 *software development.
 *
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 * In the Internet era, because the web software model has broken through the
 * limitations of local computers, this makes the software system based on
 * Internet services popular and makes desktop software appear to be dwarfed.
 * With the development of Internet technology, software content service is a
 * key topic that many software infrastructures must face, this topic further
 * highlights the dilemma of the current desktop software structure: on the one
 * hand, a large number of software component assets have been formed, on the
 * other hand, Internet services clearly represent the trend of software
 *development. Therefore, how to properly adapt the desktop software to the
 *development of the contemporary Internet is a very urgent problem and a basic
 *problem that today's desktop software must face. We know that the presentation
 *of web software needs a modern web browser, an indisputable fact is that a
 *desktop Internet web browser is also a desktop software, but because its
 *content relies on Web pages, it is almost recognized as being out of the ranks
 *of desktop software. In the age of the Internet, the difference between the
 *Desktop Software System supported by binary components and the Browser
 *Application Architecture supported by the content of Web pages has become more
 *and more prominent, and it can be said that the two are gradually moving away.
 *How Desktop Software finds its most suitable position has always been an
 *interesting topic, but there has been no proper solution. Although CEF and
 *Electron are very popular, they cannot fundamentally solve the key problem of
 *desktop software connecting to the Internet. Web Runtime tries to consider
 *this issue from a new perspective, due to the needs of Internet content
 *security and rendering, Internet giants have formed a unique Sandbox-Based
 *Multi-Process Architecture for the basic framework of the Web Browser, which
 *makes the browser structure completely different from other desktop software
 *systems in most cases. The Sandbox-Based Multi-Process Architecture indeed
 *solves many problems caused by the Internet, and it also makes the Browser
 *series and traditional desktop software form an increasingly clear difference.
 * We believe that handling this difference is the key to solving the problem of
 *Desktop Software adapting to the Internet. If we take Web Browser as the
 *smallest Desktop Software, for example, let's imagine that we use the basic
 *structure of the Web Browser as the initial structure of other desktop
 *software, what will happen? the problem will become clearer and clearer. We
 * know that in modern browser architecture, the tasks of rendering and
 *displaying web content are completed by the Render Process and GPU Process.
 *The responsibility of the Browser Process seems to be to provide a content
 *"viewport" for Web Content and "auxiliary facilities" around the web content,
 *such as tab strip, toolbar, etc. The key to the difference between Desktop
 *Software and Internet Web Browsers seems to be here. Since Chromium, Mozilla
 *and other such types of projects only focus on the Browser Architecture
 *itself, the restrictions that must be formed around the Browser Architecture
 * also appear in Chromium, for example, because Chromium is a Browser Project,
 *the implementation of the Browser Process is strictly limited to the C++
 *language level due to the project itself, from this we can see that the
 *technical constraints on the browser process are one of the key reason to the
 *huge difference between desktop software and browser software, if this
 *constraint can be broken and developers are allowed to reconstruct the Browser
 *Process while retaining the responsibility of the Browser Process, the
 *situation will be completely different. According to this thinking principle,
 * the problem will be how to use the existing Desktop Software Development
 *Technology to reconstruct the Browser Process of Web Browser Multi-Process
 *Architecture. This consideration seems to be a blind spot in the software
 *industry today, since the vast majority of software teams believe that only
 *the Browser Architecture requires the Process Separation of Browser, Renderer,
 *GPU and others, this has led to a clear difference between the software
 *structure of the browser team and the desktop software team. In order to
 * fundamentally solve the basic problem of desktop software adapting to the
 *Modern Internet, we should unify the core structure of the Browser
 *Infrastructure and the Desktop Software Infrastructure. Recognizing this, the
 *problem will become concise. We just need to consider, what conditions do
 *developers need to build their own browser process? Thanks to Google’s
 *open-source project Chromium, we can compile the Browser Process
 * Infrastructure of modern browsers into a set of dynamic link libraries, based
 *on this, today’s developers are provided with a concise use of their familiar
 *technical framework (such as .Net, Java) to construct their own Browser
 *Process according to their own wishes, therefore a new desktop software
 *construction mode appears.
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
	CWebRTImpl* g_pWebRTImpl = nullptr;

	class CWebRTProxy : public IWebRTDelegate {
	public:
		CWebRTProxy() {};
		virtual ~CWebRTProxy() {
			if (m_pJVMenv) {
				try {
					OutputDebugString(
						_T("\n\n***************For MFC Developer***************\n")
						_T("***************Exit Eclipse JVM from MFC***************\n\n"));
					m_pJVMenv->CallStaticVoidMethod(systemClass, exitMethod, 0);
					OutputDebugString(
						_T("\n\n***************For MFC Developer***************\n")
						_T("***************end Exit Eclipse JVM from ")
						_T("CLR***************\n\n"));
				}
				catch (...) {
					OutputDebugString(
						_T("\n\n***************For MFC Developer catch***************\n")
						_T("***************end Exit Eclipse JVM from ")
						_T("MFC***************\n\n"));
				}
				if (m_pJVMenv->ExceptionOccurred()) {
					OutputDebugString(
						_T("\n\n***************For MFC Developer ")
						_T("ExceptionOccurred***************\n")
						_T("***************end Exit Eclipse JVM from ")
						_T("MFC***************\n\n"));
					m_pJVMenv->ExceptionDescribe();
					m_pJVMenv->ExceptionClear();
				}
			}
		}

		// IWebRTDelegate:
		virtual bool OnAppIdle(BOOL& bIdle, LONG lCount) {
			return true;
		}

		virtual bool DoIdleWork() {
			if (g_pWebRTImpl && g_pWebRTImpl->m_hMainWnd &&
				::IsWindow(g_pWebRTImpl->m_hMainWnd) == false)
				g_pWebRTImpl->m_hMainWnd = NULL;
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
			if (g_pWebRTImpl->m_hMainWnd) {
				switch (nIndex) {
				case 0:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pWebRTImpl->m_hMainWnd, GCLP_HICON));
					break;
				case 1:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pWebRTImpl->m_hMainWnd, GCLP_HICONSM));
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

	CWebRTApp::CWebRTApp() {
		m_strExeName = _T("");
		m_strProviderID = _T("");
	}

	CWebRTApp::~CWebRTApp() {
		if (m_pWebRTImpl) {
			m_pWebRTImpl->InserttoDataMap(0, m_strProviderID, nullptr);
			m_pWebRTImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
	}

	int CWebRTApp::Run() {
		if (g_pWebRTImpl) {
			g_pWebRTImpl->Run();
		}
		return 0;
	};

	bool CWebRTApp::WebRTInit(CString strID) {
		HMODULE hModule = ::GetModuleHandle(L"webrt.dll");
		if (hModule == nullptr)
			hModule = ::LoadLibrary(L"webrt.dll");
		if (hModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
				m_szBuffer) == S_OK) {
				CString strChromeRTFilePath = CString(m_szBuffer);
				strChromeRTFilePath += _T("\\WebRT\\webrt.dll");
				if (::PathFileExists(strChromeRTFilePath)) {
					hModule = ::LoadLibrary(strChromeRTFilePath);
				}
			}
			if (hModule == nullptr)
				hModule = ::LoadLibrary(L"webrt.dll");
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
		hModule = ::LoadLibrary(strTangramDll);
		if (hModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pWebRTImpl = m_pWebRTImpl = _pWebRTImplFunction(&g_pWebRT);

			m_strProviderID += _T("host");
			m_strProviderID.MakeLower();

			m_pWebRTImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
			g_pWebRTImpl->InserttoDataMap(0, m_strProviderID,
				static_cast<IUniverseAppProxy*>(this));
			g_pWebRTImpl->InserttoDataMap(1, m_strProviderID,
				static_cast<IWebRTWindowProvider*>(this));
			if (g_pWebRTImpl->m_nAppType != APP_BROWSER &&
				g_pWebRTImpl->m_nAppType != APP_BROWSER_ECLIPSE)
				::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
					(WPARAM)m_pWebRTImpl->m_pWebRTDelegate,
					g_pWebRTImpl->m_nAppType);
			m_pWebRTImpl->m_pUniverseAppProxy = this;
		}
		return true;
	}

	CXobjProxy* CWebRTApp::OnXobjInit(IXobj* pNewNode) {
		CComBSTR bstrName("");
		pNewNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pNewNode->get_NameAtWindowPage(&bstrName2);
		return nullptr;
	}

	CNucleusProxy* CWebRTApp::OnNucleusCreated(INucleus* pNewFrame) {
		__int64 h = 0;
		pNewFrame->get_HWND(&h);
		CComBSTR bstrName("");
		pNewFrame->get_Name(&bstrName);
		return nullptr;
	}

	CNucleiProxy* CWebRTApp::OnNucleiCreated(INuclei* pNuclei) {
		CNucleiProxy* pNucleiProxy = nullptr;
		__int64 h = 0;
		pNuclei->get_Handle(&h);
		if (h) {
			if (pNucleiProxy)
				pNucleiProxy->m_bAutoDelete = false;
		}
		return pNucleiProxy;
	}
	bool CWebRTApp::InitApp() {
		if (m_bBuiltInBrowser)
			return false;
		if (ProcessAppType(m_bCrashReporting) == false)
			return false;
		return true;
	}

	BOOL CWebRTApp::InitApplication() {
		if (WebRTInit(_T("")))
			return ProcessAppType(m_bCrashReporting);
		else
			return false;
	}

	bool CWebRTApp::ProcessAppType(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(m_strExeName + _T(".app.html")) == false) &&
			(::PathFileExists(m_strExeName + _T(".html")) == false);
		if (bWin32)
			return true;
		if (m_pWebRTImpl) {
			switch (m_pWebRTImpl->m_nAppType) {
			case APP_WIN32:
				return true;
				break;
			case APP_BROWSER:
			case APP_BROWSER_ECLIPSE: {
				m_pWebRTImpl->m_hMainWnd = NULL;
				HMODULE hModule = ::GetModuleHandle(L"webrt.dll");
				if (hModule == nullptr)
					hModule = ::LoadLibrary(L"webrt.dll");
				if (hModule == nullptr) {
					TCHAR m_szBuffer[MAX_PATH];
					if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
						m_szBuffer) == S_OK) {
						CString strChromeRTFilePath = CString(m_szBuffer);
						strChromeRTFilePath += _T("\\WebRT\\webrt.dll");
						if (::PathFileExists(strChromeRTFilePath)) {
							hModule = ::LoadLibrary(strChromeRTFilePath);
						}
					}
					if (hModule == nullptr)
						hModule = ::LoadLibrary(L"webrt.dll");
				}
				if (hModule) {
					typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
					_InitApp _pInitAppFunction;
					_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
					if (_pInitAppFunction != NULL) {
						m_bBuiltInBrowser = true;
						_pInitAppFunction(bCrashReporting, m_pWebRTImpl->m_pWebRTDelegate);
						return false;
					}
				}
			} break;
			case APP_ECLIPSE:
				if (g_pWebRT && !m_pWebRTImpl->m_bIsEclipseInit) {
					g_pWebRT->InitEclipseApp();
					return false;
				}
				break;
			}
		}
		return true;
	}

	BOOL CWebRTApp::IsBrowserModel(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(m_strExeName + _T(".app.html")) == false) &&
			(::PathFileExists(m_strExeName + _T(".html")) == false);
		if (bWin32 == false) {
			HMODULE hModule = ::GetModuleHandle(L"webrt.dll");
			if (hModule == nullptr)
				hModule = ::LoadLibrary(L"webrt.dll");
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
		if (g_pWebRTImpl) {
			g_pWebRTImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
	}

	bool CWebRTWindowProviderApp::WebRTInit(CString strID) {
		strID.Trim();
		if (strID == _T(""))
			strID = _T("views");
		if (g_pWebRTImpl == nullptr) {
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
				g_pWebRTImpl = _pWebRTFunction(&pWebRT);
				m_strProviderID.MakeLower();
				g_pWebRTImpl->InserttoDataMap(
					1, m_strProviderID, static_cast<IWebRTWindowProvider*>(this));
				return true;
			}
		}
		return false;
	}
}  // namespace CommonUniverse
