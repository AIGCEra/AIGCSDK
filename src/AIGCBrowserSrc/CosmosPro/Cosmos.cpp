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

#include "StdAfx.h"
 //#include "dteinternal.h"
 //#include "dte.h"
#include "dllmain.h"
#include "GridCLREvent.h"
#include "Cosmos.h"
#include "Browser.h"

#ifdef _WIN32
#ifdef ReplaceText
#undef ReplaceText
#endif // ReplaceText
#endif // _WIN32

using namespace System::Threading;
using namespace System::Diagnostics;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;
using namespace System::IO::Compression;

namespace Universe
{
	Xobj^ XobjCollection::default::get(int iIndex)
	{
		IXobj* pXobj = nullptr;
		m_pXobjCollection->get_Item(iIndex, &pXobj);
		return theAppProxy._createObject<IXobj, Xobj>(pXobj);
	}

	Xobj::Xobj(IXobj* pXobj)
	{
		m_hWnd = NULL;
		m_pXobjEvent = new CWebRTXobjEvent();
		m_pXobjEvent->m_pXobj = pXobj;
		m_pXobjEvent->m_pXobjCLREvent = new CXobjCLREvent();
		m_pXobjCLREvent = m_pXobjEvent->m_pXobjCLREvent;
		m_pXobjEvent->m_pXobjCLREvent->m_pXobj = this;
		HRESULT hr = m_pXobjEvent->DispEventAdvise(pXobj);
		if (g_pSpaceTelescopeImpl)
			g_pSpaceTelescopeImpl->AttachXobj(m_pXobjEvent);
		m_pChildNodes = nullptr;
		SetNewNode(pXobj);
		LONGLONG nValue = (LONGLONG)pXobj;
		theAppProxy._insertObject(nValue, this);
		actionData = nullptr;
	}

	Xobj::~Xobj()
	{
		if (m_pChildNodes)
		{
			delete m_pChildNodes;
		}
		delete m_pXobjCLREvent;
		//LONGLONG nValue = (LONGLONG)m_pXobj;
		//theAppProxy._removeObject(nValue);
		SetNewNode(NULL);
	}

	XobjCollection^ Xobj::ChildNodes::get()
	{
		if (m_pChildNodes == nullptr)
		{
			CComPtr<IXobjCollection> pXobjs;

			m_pXobj->get_ChildNodes(&pXobjs);
			m_pChildNodes = gcnew XobjCollection(pXobjs);
		}
		return m_pChildNodes;
	}

	Nuclei^ Xobj::Nuclei::get()
	{
		INuclei* pNuclei = nullptr;
		m_pXobj->get_Nuclei(&pNuclei);

		if (pNuclei)
		{
			return theAppProxy._createObject<INuclei, Universe::Nuclei>(pNuclei);
		}
		return nullptr;
	}

	WebView^ Xobj::WebView::get()
	{
		if (m_pXobj) {
			IWebView* pWebView = nullptr;
			m_pXobj->get_WebView(&pWebView);
			if (pWebView)
			{
				LONGLONG hwnd = 0;
				pWebView->get_HostWnd(&hwnd);
				auto it = theAppProxy.m_mapChromeWebPage.find((HWND)hwnd);
				if (it != theAppProxy.m_mapChromeWebPage.end())
					return it->second;
			}
		}
		return nullptr;
	}

	WinNucleus^ Xobj::WinNucleus::get()
	{
		CComPtr<INucleus> _pGalaxy;
		m_pXobj->get_WinNucleus(&_pGalaxy);
		return theAppProxy._createObject<INucleus, Universe::WinNucleus>(_pGalaxy);
	}

	String^ Xobj::Caption::get()
	{
		if (m_pXobj)
		{
			CComBSTR bstrCap("");
			m_pXobj->get_Caption(&bstrCap);
			String^ strCap = marshal_as<String^>(bstrCap);
			return strCap;
		}
		return "";
	}

	String^ Xobj::URL::get()
	{
		if (m_pXobj)
		{
			::XobjType nType;
			m_pXobj->get_XobjType(&nType);
			CComBSTR bstrCap("");
			switch (nType)
			{
			case BlankView:
			{
				m_pXobj->get_URL(&bstrCap);
				return marshal_as<String^>(bstrCap);
			}
			break;
			case ActiveX:
			{
				CComVariant var;
				m_pXobj->get_XObject(&var);
			}
			break;
			default:
				break;
			}
		}
		return "";
	}

	void Xobj::URL::set(String^ newVal)
	{
		if (m_pXobj)
		{
			::XobjType nType;
			m_pXobj->get_XobjType(&nType);
			switch (nType)
			{
			case BlankView:
				if (nType == BlankView)
				{
					m_pXobj->put_URL(marshal_as<CComBSTR>(newVal));

				}
				break;
			case ActiveX:
			{
			}
			break;
			default:
				break;
			}
		}
	}

	void Xobj::Init()
	{
		LONGLONG h = 0;
		if (m_pXobj)
		{
			m_pXobj->get_Handle(&h);
			::SendMessage((HWND)h, WM_COSMOSMSG, 1, 0);
		}
	}

	Object^ Xobj::PlugIn::get(String^ strObjName)
	{
		Object^ pObj = nullptr;
		if (m_pXobj)
		{
			Xobj^ pRootXobj = this->RootXobj;
			if (pRootXobj->m_pPlugInDic == nullptr)
			{
				pRootXobj->m_pPlugInDic = gcnew Dictionary<String^, Object^>();
			}
			if (pRootXobj->m_pPlugInDic->TryGetValue(strObjName, pObj) == false)
			{
				IDispatch* pDisp = nullptr;
				LRESULT hr = m_pXobj->get_AxPlugIn(marshal_as<CComBSTR>(strObjName), &pDisp);
				if (SUCCEEDED(hr) && pDisp)
				{
					Object^ pObj = reinterpret_cast<Object^>(Marshal::GetObjectForIUnknown((System::IntPtr)(pDisp)));
					pRootXobj->m_pPlugInDic[strObjName] = pObj;
					return pObj;
				}
			}
		}
		return pObj;
	}

	void Xobj::Fire_OnTabChange(Xobj^ ActivePage, Xobj^ OldXobj)
	{
		OnTabChange(ActivePage, OldXobj);
	}

	Xobj^ WebRT::Observe(Control^ ctrl, String^ key, String^ strXobjXml)
	{
		if (ctrl != nullptr)
		{
			if (ctrl->Dock != DockStyle::Fill && ctrl->Dock != DockStyle::None)
				return nullptr;
			INucleus* pGalaxy = nullptr;
			theApp.m_pWebRT->GetNucleus((__int64)ctrl->Handle.ToPointer(), &pGalaxy);
			if (pGalaxy)
			{
				IXobj* pXobj = nullptr;
				CComBSTR bstrKey = marshal_as<CComBSTR>(key);
				CComBSTR bstrXml = marshal_as<CComBSTR>(strXobjXml);
				pGalaxy->Observe(bstrKey, bstrXml, &pXobj);
				if (pXobj)
					return theAppProxy._createObject<IXobj, Xobj>(pXobj);
				return nullptr;
			}
			HWND hTopWnd = nullptr;
			Control^ topCtrl = ctrl->TopLevelControl;
			if (topCtrl == nullptr)
			{
				hTopWnd = ::GetParent((HWND)ctrl->Handle.ToPointer());
			}
			else
			{
				if (topCtrl->GetType()->IsSubclassOf(Form::typeid))
				{
					Form^ pForm = (Form^)topCtrl;
					Form^ pForm2 = nullptr;
					if (pForm != nullptr && pForm->IsMdiContainer)
					{
						bool bMdiClientChild = false;
						int nCount = pForm->Controls->Count;
						String^ strName = L"";
						for (int i = nCount - 1; i >= 0; i--)
						{
							Control^ pCtrl = pForm->Controls[i];
							strName = pCtrl->GetType()->Name->ToLower();
							if (strName == L"mdiclient")
							{
								if (::IsChild((HWND)pCtrl->Handle.ToPointer(), (HWND)ctrl->Handle.ToPointer()))
								{
									bMdiClientChild = true;
								}
								break;
							}
						}
						if (bMdiClientChild)
						{
							Control^ parent = ctrl->Parent;
							while (!parent->GetType()->IsSubclassOf(Form::typeid))
							{
								parent = parent->Parent;
							}
							if (parent != nullptr)
								pForm2 = (Form^)parent;
						}
						else
						{
							pForm2 = pForm;
						}
					}
					else
						pForm2 = pForm;
					if (pForm2 != nullptr)
					{
						Nuclei^ thisGalaxyCluster = WebRT::CreateNucleusGroup(pForm2, pForm2);
						if (thisGalaxyCluster != nullptr)
						{
							WinNucleus^ thisGalaxy = thisGalaxyCluster->CreateNucleus(ctrl->Handle, ctrl->Name);
							return thisGalaxy->Observe(key, strXobjXml);
						}
					}
				}
				else
				{
					hTopWnd = ::GetParent((HWND)topCtrl->Handle.ToPointer());
				}
			}
			if (hTopWnd != nullptr)
			{
				HWND _hTopWnd = hTopWnd;
				Xobj^ pXobj = GetXobjFromHandle((IntPtr)hTopWnd);
				while (pXobj == nullptr)
				{
					hTopWnd = ::GetParent(hTopWnd);
					pXobj = GetXobjFromHandle((IntPtr)hTopWnd);
				}
				if (pXobj != nullptr)
				{
					INuclei* pINuclei = nullptr;
					pXobj->m_pXobj->get_Nuclei(&pINuclei);
					if (pINuclei)
					{
						String^ strName = ctrl->Name;
						CComBSTR bstrName = marshal_as<CComBSTR>(strName);
						Xobj^ _pRetXobj = nullptr;
						HWND hWnd = (HWND)ctrl->Handle.ToPointer();
						pINuclei->CreateNucleus(CComVariant((__int64)0), CComVariant((__int64)hWnd), bstrName, &pGalaxy);
						if (pGalaxy)
						{
							IXobj* pXobj = nullptr;
							CComBSTR bstrKey = marshal_as<CComBSTR>(key);
							CComBSTR bstrXml = marshal_as<CComBSTR>(strXobjXml);
							pGalaxy->Observe(bstrKey, bstrXml, &pXobj);
							if (pXobj)
								_pRetXobj = theAppProxy._createObject<IXobj, Xobj>(pXobj);
						}
						::InvalidateRect(hWnd, nullptr, true);
						return _pRetXobj;
					}
				}
				else
				{
					Nuclei^ thisGalaxyCluster = WebRT::CreateNucleusGroup((IntPtr)_hTopWnd);
					if (thisGalaxyCluster != nullptr)
					{
						WinNucleus^ thisGalaxy = thisGalaxyCluster->CreateNucleus(ctrl->Handle, ctrl->Name);
						return thisGalaxy->Observe(key, strXobjXml);
					}
				}
			}
		}
		return nullptr;
	}

	WebRT::WebRT()
	{
		m_pUniverseAppProxy = nullptr;
	}

	WebRT::WebRT(IWebRT* pWebRT)
	{
	}

	WebRT::~WebRT(void)
	{
		for each (KeyValuePair<String^, Object^> ^ dic in Universe::WebRT::m_pWebRTCLRObjDic)
		{
			if (dic->Value != nullptr)
			{
				Object^ value = dic->Value;
				delete value;
			}
		}
	}

	int WebRT::WebRTInit(String^ strInit)
	{
		CString strInfo = strInit;
		if (strInfo != _T(""))
		{
			__int64 nPointer = _wtoi64(strInfo);
			if (nPointer)
			{
				g_pSpaceTelescopeImpl = (CWebRTImpl*)nPointer;
				g_pSpaceTelescopeImpl->m_pCLRProxy = &theAppProxy;
				g_pSpaceTelescopeImpl->m_pWebRTAppProxy = static_cast<IUniverseAppProxy*>(&theApp);
				//20180817
				if (theApp.m_pWebRT == nullptr)
				{
					HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
					if (hModule) {
						typedef IWebRT* (__stdcall* GetWebRT)();
						GetWebRT _pWebRTFunction;
						_pWebRTFunction = (GetWebRT)GetProcAddress(hModule, "GetWebRT");
						if (_pWebRTFunction != NULL) {
							theApp.m_pWebRT = _pWebRTFunction();
						}
					}
				}
			}
			//CComVariant var;
			//HRESULT hr = theApp.m_pWebRT->get_AppKeyValue(CComBSTR("mainformdisp"), &var);
			//if (hr == S_OK) {
			//	
			//	IntPtr nDisp = (IntPtr)(IDispatch*)var.pdispVal;
			//	Object^ pStartObj = Marshal::GetObjectForIUnknown(nDisp);
			//	//g_pSpaceTelescopeImpl->m_mapValInfo.erase(it);
			//	if (pStartObj != nullptr) {
			//		Universe::WebRT::Run(pStartObj);
			//	}
			//}
			auto it = g_pSpaceTelescopeImpl->m_mapValInfo.find(_T("mainformdisp"));
			if (it != g_pSpaceTelescopeImpl->m_mapValInfo.end()) {
				IntPtr nDisp = (IntPtr)(IDispatch*)it->second.llVal;
				Object^ pStartObj = Marshal::GetObjectForIUnknown(nDisp);
				g_pSpaceTelescopeImpl->m_mapValInfo.erase(it);
				if (pStartObj != nullptr) {
					Universe::WebRT::Run(pStartObj);
				}
			}
		}
		return 0;
	}

	void WebRT::Run(Object^ MainObj) {
		if (MainObj == nullptr) {
			if (WebRT::WebRuntimeInit())
				return;
			if (g_pSpaceTelescopeImpl)
			{
				g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
				g_pSpaceTelescopeImpl->Run();
			}
			System::Windows::Forms::Application::Exit();
			return;
		}
		if (!theApp.m_bNativeApp) {
			if (WebRT::WebRuntimeInit())
				return;
		}
		if (MainObj->GetType()->IsSubclassOf(Form::typeid)) {
			Form^ Mainform = (Form^)MainObj;
			WebRT::MainForm::set((Form^)Mainform);
			if (theApp.m_bNativeApp)
			{
				GetWebRT();
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadFile(g_pSpaceTelescopeImpl->m_strConfigFile)) {
					CTangramXmlParse* pChild = m_Parse.GetChild(_T("initform"));
					if (pChild) {
						theAppProxy.m_strCurrentWinFormTemplate = pChild->xml();
						CString strFormID = pChild->attr(_T("objid"), _T(""));
						if (strFormID == _T("")) {

						}
						else {
							Object^ pObj = Universe::WebRT::CreateObject(marshal_as<String^>(strFormID));
							if (pObj && pObj->GetType()->IsSubclassOf(Form::typeid)) {
								if (pObj != nullptr)
								{
									if (pObj->GetType()->IsSubclassOf(Form::typeid))
									{
										CString strCaption = pChild->attr(_T("caption"), _T(""));
										Form^ thisForm = (Form^)pObj;
										if (pChild->attrBool(_T("mainwindow")))
											g_pSpaceTelescopeImpl->m_hMainWnd = (HWND)thisForm->Handle.ToPointer();
										if (strCaption != _T(""))
											thisForm->Text = marshal_as<String^>(strCaption);
										if (thisForm->IsMdiContainer)
										{
											CTangramXmlParse* pChild3 = pChild->GetChild(_T("mdichild"));
											if (pChild3)
											{
												int nCount = pChild3->GetCount();
												if (nCount)
												{
													//if (g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo)
													//{
													//	delete g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo;
													//	g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
													//}
													CMDIChildFormInfo* pInfo = new CMDIChildFormInfo();
													g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = pInfo;
													for (int i = 0; i < nCount; i++)
													{
														CString strName = pChild3->GetChild(i)->name().MakeLower();
														pChild3->GetChild(i)->put_attr(_T("mdichild"), true);
														pInfo->m_mapFormsInfo[strName] = pChild3->GetChild(i)->xml();
													}
												}
											}
											CString strBKPage = pChild->attr(_T("mdibkpageid"), _T(""));
											if (strBKPage != _T(""))
											{
												WebRT::CreateBKPage(thisForm, marshal_as<String^>(strBKPage));
											}
										}
										//thisForm->Show();
									}
								}
								WebRT::MainForm::set((Form^)pObj);
								Mainform = (Form^)pObj;
							}
						}
					}
				}
				Forms::Application::Run(Mainform);
			}
			else
			{
				if (g_pSpaceTelescopeImpl)
				{
					WebRT::MainForm::set((Form^)Mainform);
					g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
					g_pSpaceTelescopeImpl->Run();
				}
				Forms::Application::Exit();
			}
			return;
		}

		if (MainObj->GetType()->IsSubclassOf(System::Windows::Application::typeid)) {
			System::Windows::Application^ app = (System::Windows::Application^)MainObj;
			Object^ pWpfWndObj = nullptr;
			auto it = g_pSpaceTelescopeImpl->m_mapValInfo.find(_T("mainwpfwnddisp"));
			if (it != g_pSpaceTelescopeImpl->m_mapValInfo.end()) {
				IntPtr nDisp = (IntPtr)(IDispatch*)it->second.llVal;
				pWpfWndObj = Marshal::GetObjectForIUnknown(nDisp);
				g_pSpaceTelescopeImpl->m_mapValInfo.erase(it);
			}

			g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
			GetWebRT();
			if (pWpfWndObj)
				app->Run((System::Windows::Window^)pWpfWndObj);
			else
				app->Run();

			//HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
			//if (hModule == nullptr)
			//	hModule = ::LoadLibrary(L"AIGCAgent.dll");
			//if (hModule == nullptr) {
			//	TCHAR m_szBuffer[MAX_PATH];
			//	if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
			//		m_szBuffer) == S_OK) {
			//		CString strChromeRTFilePath = CString(m_szBuffer);
			//		strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
			//		if (::PathFileExists(strChromeRTFilePath)) {
			//			hModule = ::LoadLibrary(strChromeRTFilePath);
			//		}
			//	}
			//	if (hModule == nullptr)
			//		hModule = ::LoadLibrary(L"AIGCAgent.dll");
			//}
			//
			//if (hModule) {
			//	BOOL isBrowserModel = false;

			//	typedef bool(__stdcall* _IsBrowserModel)(bool bSupportCrashReporting, void*);
			//	_IsBrowserModel FuncIsBrowserModel;

			//	FuncIsBrowserModel =
			//		(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
			//	if (FuncIsBrowserModel != NULL) {
			//		isBrowserModel = FuncIsBrowserModel(false, &theApp);
			//		if (isBrowserModel) {
			//			app->Shutdown();
			//			return ;
			//		}
			//	}
			//	g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
			//	::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
			//		(WPARAM)&theApp,
			//		g_pSpaceTelescopeImpl->m_nAppType);
			//}
			if (!theApp.m_bNativeApp)
				app->Shutdown();
		}
		if (MainObj->GetType()->IsSubclassOf(ApplicationContext::typeid)) {
			ApplicationContext^ context = (ApplicationContext^)MainObj;
			if (theApp.m_bNativeApp)
			{
				GetWebRT();
				Forms::Application::Run(context);
			}
			else
			{
				if (g_pSpaceTelescopeImpl)
				{
					g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
					g_pSpaceTelescopeImpl->Run();
				}
				Forms::Application::Exit();
			}
		}
	}

	WebRT^ WebRT::GetWebRT()
	{
		if (theApp.m_pWebRT == nullptr)
		{
			HMODULE hModule = ::GetModuleHandle(L"universe.dll");
			if (hModule == nullptr) {
				TCHAR m_szBuffer[MAX_PATH];
				if (SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer) ==
					S_OK) {
					ATL::CString m_strProgramFilePath = ATL::CString(m_szBuffer);
					m_strProgramFilePath += _T("\\Tangram\\AIGCBrowser\\universe.dll");
					if (::PathFileExists(m_strProgramFilePath)) {
						hModule = ::LoadLibrary(m_strProgramFilePath);
					}
				}
			}
			if (hModule) {
				typedef CWebRTImpl* (__stdcall* GetWebRTImpl)(IWebRT**);
				GetWebRTImpl _pWebRTImplFunction;
				_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
				if (_pWebRTImplFunction != NULL) {
					g_pSpaceTelescopeImpl = _pWebRTImplFunction(&theApp.m_pWebRT);
					if (g_pSpaceTelescopeImpl->m_nAppType == 0)
						g_pSpaceTelescopeImpl->m_nAppType = APP_BROWSERAPP;
					if (g_pSpaceTelescopeImpl->m_pWebRTDelegate == nullptr)
					{
						g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theApp;
						g_pSpaceTelescopeImpl->m_pUniverseAppProxy = (IUniverseAppProxy*)&theApp;
					}
					g_pSpaceTelescopeImpl->m_pCLRProxy = &theAppProxy;
				}
			}
		}

		if (m_pWebRT == nullptr)
		{
			m_pWebRT = gcnew WebRT();
			if (g_pSpaceTelescopeImpl && g_pSpaceTelescopeImpl->m_strStartupURL == _T("")) {
				CString strURL = g_pSpaceTelescopeImpl->m_strAppPath + g_pSpaceTelescopeImpl->m_strExeName + _T(".app.html");
				if (::PathFileExists(strURL)) {
					g_pSpaceTelescopeImpl->m_strStartupURL = strURL;
					g_pSpaceTelescopeImpl->m_nAppType = APP_BROWSERAPP;
				}
			}

		}
		return m_pWebRT;
	}

	WebRT^ WebRT::InitWebRTApp(bool bSupportCrashReporting, CosmosAppType AppType)
	{
		if (m_pWebRT == nullptr)
			m_pWebRT = gcnew WebRT();
		if (theApp.m_bBrowserModeInit)
			return m_pWebRT;
		g_pSpaceTelescopeImpl->m_nAppType = (DWORD)AppType;
		//m_nAppType = AppType;
		switch (AppType)
		{
		case CosmosAppType::APPBROWSER:
			theApp.InitWebRTApp(bSupportCrashReporting);
			break;
		case CosmosAppType::APPBROWSERAPP:
			break;
		}
		return m_pWebRT;
	}

	bool WebRT::SupportCrashReporting::get()
	{
		return g_pSpaceTelescopeImpl->m_bIsSupportCrashReporting;
	}

	void WebRT::SupportCrashReporting::set(bool bSupportCrashReporting)
	{
		if (g_pSpaceTelescopeImpl->m_bIsSupportCrashReporting == false)
			g_pSpaceTelescopeImpl->m_bIsSupportCrashReporting = bSupportCrashReporting;
	}

	CosmosAppType WebRT::AppType::get()
	{
		DWORD _nType = g_pSpaceTelescopeImpl->m_nAppType;
		switch (_nType)
		{
		case APP_WIN32:
			return CosmosAppType::APPWIN32;
			break;
		case APP_BROWSER:
			return CosmosAppType::APPBROWSER;
			break;
		case APP_BROWSERAPP:
			return CosmosAppType::APPBROWSERAPP;
			break;
		default:
			break;
		}
		return CosmosAppType::APPOTHER;
	}

	void WebRT::AppType::set(CosmosAppType nType)
	{
		if (m_pWebRT == nullptr)
			m_pWebRT = gcnew WebRT();
		g_pSpaceTelescopeImpl->m_nAppType = (DWORD)nType;
	}

	System::Drawing::Icon^ WebRT::DefaultIcon::get()
	{
		if (Universe::WebRT::m_pDefaultIcon == nullptr)
		{
			Form^ _pForm = gcnew Form();
			Universe::WebRT::m_pDefaultIcon = _pForm->Icon;
		}
		return Universe::WebRT::m_pDefaultIcon;
	}

	bool WebRT::WebRuntimeInit()
	{
		if (IsWebRuntimeInit)
			return true;

		if (theApp.m_bNativeApp)
			return true;
		TCHAR m_szBuffer[MAX_PATH];
		::GetModuleFileName(::GetModuleHandle(_T("universe.dll")), m_szBuffer, MAX_PATH);
		CString strAIGCAgentPath = m_szBuffer;
		int nPos = strAIGCAgentPath.ReverseFind('\\');
		strAIGCAgentPath = strAIGCAgentPath.Left(nPos + 1) + _T("AIGCAgent.dll");
		if (::PathFileExists(strAIGCAgentPath))
			g_pSpaceTelescopeImpl->m_hWebRTProxyModel = ::LoadLibrary(strAIGCAgentPath);

		if (g_pSpaceTelescopeImpl->m_hWebRTProxyModel) {
			typedef bool(__stdcall* _IsChromeRunning)(bool bSupportCrashReporting);
			_IsChromeRunning FuncIsChromeRunning;
			FuncIsChromeRunning = (_IsChromeRunning)GetProcAddress(g_pSpaceTelescopeImpl->m_hWebRTProxyModel, "IsBrowserModel");
			if (FuncIsChromeRunning != NULL) {
				IsWebRuntimeInit = FuncIsChromeRunning(false);
				if (theAppProxy.m_bInitApp == false)
				{
					::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, 0, 20191022);
				}
			}
		}
		return IsWebRuntimeInit;
	}

	Browser^ WebRT::HostWebBrowser::get()
	{
		if (theApp.m_pWebRT)
		{
			IBrowser* pWebBrowser = nullptr;
			theApp.m_pWebRT->get_HostChromeBrowserWnd(&pWebBrowser);
			if (pWebBrowser)
			{
				auto it = theAppProxy.m_mapWebBrowser.find(pWebBrowser);
				if (it != theAppProxy.m_mapWebBrowser.end())
					return it->second;
			}
		}
		return nullptr;
	}

	WebRT^ WebRT::TangramCore::get()
	{
		return GetWebRT();
	}

	Form^ WebRT::MainForm::get()
	{
		return m_pMainForm;
	}

	void WebRT::MainForm::set(Form^ frm)
	{
		if (m_pMainForm == nullptr)
		{
			m_pMainForm = frm;
			if (m_pMainForm != nullptr)
			{
				::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, 0, 20191004);
			}
		}
		if (g_pSpaceTelescopeImpl)
			g_pSpaceTelescopeImpl->SetMainWnd((HWND)frm->Handle.ToPointer());
	}

	Xobj^ WebRT::CreatingXobj::get()
	{
		Object^ pRetObject = nullptr;
		if (theApp.m_pWebRT)
		{
			IXobj* pXobj = nullptr;
			theApp.m_pWebRT->get_CreatingXobj(&pXobj);
			if (pXobj)
				return theAppProxy._createObject<IXobj, Xobj>(pXobj);
		}
		return nullptr;
	}

	WebRT^ WebRT::RemoteTangram::get(String^ strID)
	{
		if (theApp.m_pWebRT)
		{
			IWebRT* pWebRT = nullptr;
			CComBSTR bstrID = marshal_as<CComBSTR>(strID);
			theApp.m_pWebRT->get_RemoteCosmos(bstrID, &pWebRT);
			if (pWebRT)
			{
				WebRT^ _pWebRT = theAppProxy._createObject<IWebRT, WebRT>(pWebRT);
				return _pWebRT;
			}
		}
		return nullptr;
	}

	String^ WebRT::WizData::get()
	{
		return Universe::WebRT::m_strWizData;
	}

	void WebRT::WizData::set(String^ strXml)
	{
		Universe::WebRT::m_strWizData = strXml;
	}

	String^ WebRT::AppKeyValue::get(String^ iIndex)
	{
		auto it = g_pSpaceTelescopeImpl->m_mapValInfo.find(marshal_as<CString>(iIndex));
		if (it != g_pSpaceTelescopeImpl->m_mapValInfo.end())
		{
			return marshal_as<String^>(it->second.bstrVal);
		}
		return L"";
	}

	void WebRT::AppKeyValue::set(String^ iIndex, String^ newVal)
	{
		theApp.m_pWebRT->put_AppKeyValue(marshal_as<CComBSTR>(iIndex), CComVariant(marshal_as<CComBSTR>(newVal)));
	}

	void WebRT::Fire_OnCloudAppIdle()
	{
		OnCloudAppIdle();
	}

	Object^ WebRT::Fire_OnGetSubObjForWebPage(Object^ SourceObj, String^ subObjName)
	{
		return OnGetSubObjForWebPage(SourceObj, subObjName);
	}

	void WebRT::Fire_OnBindCLRObjToWebPage(Object^ SourceObj, Universe::Wormhole^ eventSession, String^ eventName)
	{
		if (eventSession->isBindCLRObjToWebPage(SourceObj, eventName))
			return;
		Control^ pCtrl = (Control^)SourceObj;
		intptr_t nNode = eventSession->m_pWebRTSession->Getint64(L"xobj");
		if (nNode)
		{
			IXobj* pXobj = (IXobj*)nNode;
			Xobj^ thisNode = theAppProxy._createObject<IXobj, Xobj>(pXobj);
			if (thisNode != nullptr)
			{
				thisNode->Fire_OnBindCLRObjToWebPage(SourceObj, eventSession, eventName);
			}
		}
		OnBindCLRObjToWebPage(SourceObj, eventSession, eventName);
	}

	bool WebRT::Fire_OnAppInit()
	{
		if (IsAppInit == false)
		{
			IsAppInit = true;
			return OnAppInit();
		}
		return false;
	}

	void WebRT::Fire_OnClose()
	{
		OnClose();
	}

	Control^ WebRT::GetMDIClient(Form^ pForm)
	{
		if (pForm && pForm->IsMdiContainer)
		{
			String^ strTag = L"";
			Object^ tag = pForm->Tag;
			if (tag != nullptr)
				strTag = tag->ToString();

			CString _strTag = _T("");
			if (String::IsNullOrEmpty(strTag) == false)
				_strTag = marshal_as<CString>(strTag);
			if (_strTag == _T(""))
				_strTag = _T("default");
			int nCount = pForm->Controls->Count;
			String^ strName = L"";
			for (int i = nCount - 1; i >= 0; i--)
			{
				Control^ pCtrl = pForm->Controls[i];
				strName = pCtrl->GetType()->Name->ToLower();
				if (strName == L"mdiclient")
				{
					return pCtrl;
				}
			}
		}
		return nullptr;
	}

	void WebRT::CreateBKPage(Form^ form, String^ strID)
	{
		Control^ mdiclient = WebRT::GetMDIClient(form);
		if (mdiclient && String::IsNullOrEmpty(strID) == false)
		{
			::SendMessage((HWND)form->Handle.ToPointer(), WM_MDICLIENTCREATED, (WPARAM)mdiclient->Handle.ToInt64(), (LPARAM)LPCTSTR(marshal_as<CString>(strID)));
		}
	}

	Xobj^ WebRT::ExtendMDIClient(Form^ pForm, String^ strKey, String^ strXml)
	{
		Control^ mdiclient = WebRT::GetMDIClient(pForm);
		if (mdiclient)
		{
			Nuclei^ page = WebRT::CreateNucleusGroup(pForm, nullptr);
			WinNucleus^ frame = page->CreateNucleus(mdiclient, L"default");
			if (frame)
			{
				return frame->Observe(strKey, strXml);
			}
		}
		return nullptr;
	}

	Browser^ WebRT::GetHostBrowser(Object^ obj)
	{
		if (obj == nullptr)
		{
			return nullptr;
		}
		HWND hWnd = nullptr;
		if (obj->GetType()->IsSubclassOf(Control::typeid) || obj->GetType() == Control::typeid)
		{
			Control^ ctrl = (Control^)obj;
			hWnd = (HWND)(ctrl->Handle.ToPointer());
		}
		else if (obj->GetType()->IsSubclassOf(System::Windows::Media::Visual::typeid) ||
			obj->GetType() == System::Windows::Media::Visual::typeid)
		{
			System::Windows::Media::Visual^ vis = (System::Windows::Media::Visual^)obj;
			System::Windows::PresentationSource^ ps = System::Windows::Interop::HwndSource::FromVisual(vis);
			if (ps != nullptr)
			{
				System::Windows::Interop::HwndSource^ hwnd = (System::Windows::Interop::HwndSource^)ps;
				hWnd = (HWND)(hwnd->Handle.ToPointer());
				hWnd = ::GetParent(hWnd);
				if (::IsWindow(hWnd))
				{
					hWnd = ::GetParent(hWnd);
				}
			}
		}
		if (hWnd == nullptr)
		{
			return nullptr;
		}
		IXobj* pWndXobj = nullptr;
		WebRTInfo* pInfo = (WebRTInfo*)::GetProp(hWnd, _T("WebRTInfo"));
		if (pInfo)
			pWndXobj = pInfo->m_pXobj;
		if (pWndXobj == nullptr)
		{
			return nullptr;
		}
		INucleus* pGalaxy = pInfo->m_pNucleus;
		if (pGalaxy == nullptr)
		{
			return nullptr;
		}
		IBrowser* pBrowser = nullptr;
		pGalaxy->get_HostBrowser(&pBrowser);
		if (pBrowser == nullptr)
		{
			return nullptr;
		}
		auto it = theAppProxy.m_mapWebBrowser.find(pBrowser);
		if (it != theAppProxy.m_mapWebBrowser.end())
			return it->second;
		else
		{
			Browser^ _pBrowser = gcnew Browser(pBrowser);
			theAppProxy.m_mapWebBrowser[pBrowser] = _pBrowser;
			return _pBrowser;
		}
	}

	void WebRT::RegComponentForTangram(String^ strIDs, Assembly^ a)
	{
		if (a != nullptr /*&& String::IsNullOrEmpty(strIDs) == false*/)
		{
			strIDs = strIDs->ToLower();
			cli::array<Type^>^ pArray = a->GetExportedTypes();
			for each (Type ^ type in pArray)
			{
				if (type->IsSubclassOf(Control::typeid) || type->IsSubclassOf(System::Windows::FrameworkElement::typeid))
				{
					String^ strName = type->AssemblyQualifiedName->ToLower();
					String^ s = strName->Substring(0, strName->IndexOf(", version"))->Replace(" ", "");
					Type^ _pType = nullptr;
					if (String::IsNullOrEmpty(strIDs))
					{
						if (GetWebRT()->m_pWebRTCLRTypeDic->TryGetValue(s, _pType) == false)
							GetWebRT()->m_pWebRTCLRTypeDic->Add(s, type);
					}
					else if (strIDs->IndexOf(s) != -1)
					{
						if (GetWebRT()->m_pWebRTCLRTypeDic->TryGetValue(s, _pType) == false)
							GetWebRT()->m_pWebRTCLRTypeDic->Add(s, type);
					}
				}
			}
		}
	}

	Xobj^ WebRT::GetXobjFromHandle(IntPtr handle)
	{
		IXobj* pWndXobj = nullptr;
		WebRTInfo* pInfo = (WebRTInfo*)::GetProp((HWND)handle.ToPointer(), _T("WebRTInfo"));
		if (pInfo)
			pWndXobj = pInfo->m_pXobj;
		else
			return nullptr;
		//HRESULT hr = theApp.m_pWebRT->GetXobjFromHandle((LONGLONG)handle.ToPointer(), &pWndXobj);
		//if (hr != S_OK || pWndXobj == nullptr)
		//{
		//    return nullptr;
		//}
		return theAppProxy._createObject<IXobj, Xobj>(pWndXobj);
	}

	Xobj^ WebRT::GetXobjFromControl(Control^ ctrl)
	{
		if (ctrl == nullptr)
		{
			return nullptr;
		}
		IXobj* pWndXobj = nullptr;
		HWND hCtrl = (HWND)ctrl->Handle.ToPointer();
		auto it = g_pSpaceTelescopeImpl->m_mapXobj.find(hCtrl);
		if (it != g_pSpaceTelescopeImpl->m_mapXobj.end())
		{
			pWndXobj = it->second;
			return theAppProxy._createObject<IXobj, Xobj>(pWndXobj);
		}
		WebRTInfo* pInfo = (WebRTInfo*)::GetProp(hCtrl, _T("WebRTInfo"));
		if (pInfo)
			pWndXobj = pInfo->m_pXobj;
		else
			return nullptr;
		return theAppProxy._createObject<IXobj, Xobj>(pWndXobj);
	}

	Wormhole^ WebRT::GetWormholeFromObj(Object^ obj)
	{
		Universe::Wormhole^ pCloudSession = nullptr;
		bool bExists = Universe::WebRT::Wormholes->TryGetValue(obj, pCloudSession);
		if (bExists)
		{
			return pCloudSession;
		}
		return nullptr;
	}

	void WebRT::SendXmlMessage(Xobj^ sender, String^ strXml)
	{
		IWebView* pPage = nullptr;
		sender->m_pXobj->get_WebView(&pPage);
		if (pPage)
		{
			CComBSTR bstrXml = marshal_as<CComBSTR>(strXml);
			pPage->SendXmlMessage(sender->m_pXobj, bstrXml);
		}
	}

	void WebRT::BindObjToWebPage(IntPtr hWebPage, Object^ pObj, String^ strWebName)
	{
		HWND hWnd = (HWND)hWebPage.ToPointer();
		CWebViewImpl* pProxy = nullptr;
		auto it = theAppProxy.m_mapChromeWebPage.find(hWnd);
		if (it != theAppProxy.m_mapChromeWebPage.end())
		{
			pProxy = it->second->m_pProxy;
		}
		Universe::Wormhole^ pCloudSession = nullptr;
		CSession* pSession = nullptr;
		bool bExists = Universe::WebRT::Wormholes->TryGetValue(pObj, pCloudSession);
		if (bExists)
		{
			pSession = pCloudSession->m_pWebRTSession;
			Type^ pType = pObj->GetType();
			pCloudSession->InsertString(_T("msgID"), _T("BindCLRObject"));
			pCloudSession->InsertString(_T("objtype"), pType->FullName);
			pCloudSession->InsertString(_T("objID"), _T(".netobj"));
			pCloudSession->InsertString(_T("action"), _T("webbind"));
			pCloudSession->InsertString(_T("name@page"), strWebName);
			if (pType->IsSubclassOf(Control::typeid))
			{
				pCloudSession->InsertInt64(_T("hwnd"), ((Control^)pObj)->Handle.ToInt64());
			}
			pCloudSession->InsertInt64(_T("domhandle"), (__int64)pSession);
			pCloudSession->InsertLong(_T("autodelete"), 0);
			pCloudSession->m_pHostObj = pObj;
			theAppProxy.m_mapSession2Wormhole[pSession] = pCloudSession;
			pSession->SendMessage();
		}
		else if (g_pSpaceTelescopeImpl)
		{
			pSession = g_pSpaceTelescopeImpl->CreateCloudSession(pProxy);
			Type^ pType = pObj->GetType();
			pSession->InsertString(_T("msgID"), _T("BindCLRObject"));
			pSession->InsertString(_T("objtype"), pType->FullName);
			pSession->InsertString(_T("objID"), _T(".netobj"));
			pSession->InsertString(_T("action"), _T("webbind"));
			pSession->InsertString(_T("name@page"), strWebName);
			if (pType->IsSubclassOf(Control::typeid))
			{
				pSession->Insertint64(_T("hwnd"), ((Control^)pObj)->Handle.ToInt64());
			}
			pSession->Insertint64(_T("domhandle"), (__int64)pSession);
			pSession->InsertLong(_T("autodelete"), 0);
			if (pCloudSession == nullptr)
				pCloudSession = gcnew Wormhole(pSession);
			pCloudSession->m_pHostObj = pObj;
			theAppProxy.m_mapSession2Wormhole[pSession] = pCloudSession;
			pSession->SendMessage();
		}
	}

	List<String^>^ WebRT::FindFiles(String^ rootPath, String^ fileSpec, bool recursive)
	{
		List<String^>^ pFiles = gcnew List<String^>();
		CString strRootPath = marshal_as<CString>(rootPath);
		CString strFileSpec = marshal_as<CString>(fileSpec);
		wchar_t strSearch[MAX_PATH] = L"";
		::PathCombineW(strSearch, (LPCTSTR)strRootPath, (LPCTSTR)strFileSpec);
		_wfinddata_t fd;
		intptr_t pf = _wfindfirst(strSearch, &fd);
		if (pf != -1)
		{
			do
			{
				CString strFileName = fd.name;
				if (strFileName != _T(".."))
				{
					if (fd.attrib ^ FILE_ATTRIBUTE_DIRECTORY)
					{
						CString strFullName = rootPath + L"\\" + strFileName;
						String^ fullName = marshal_as<String^>(CComBSTR(strFullName));
						pFiles->Add(fullName);
					}
				}
			} while (!_wfindnext(pf, &fd));
		}
		return pFiles;
	}

	//Dictionary<String^, Type^>^ WebRT::InitAppFormTypeDic()
	//{
	//    if (m_pAppFormTypeDic == nullptr)
	//    {
	//        m_pAppFormTypeDic = gcnew Dictionary<String^, Type^>();
	//        CString filePath = System::Windows::Forms::Application::ExecutablePath->ToLower();
	//        int nPos = filePath.ReverseFind('.');
	//        CString strLib = filePath.Left(nPos).MakeLower();
	//        CString strAssemblys = _T("");
	//        String^ _strLib = marshal_as<String^>(filePath);
	//        String^ strAssemblyLib = L"";
	//        strLib = filePath.MakeLower();
	//        Assembly^ m_pDotNetAssembly = nullptr;
	//        try
	//        {
	//            m_pDotNetAssembly = Assembly::LoadFile(System::Windows::Forms::Application::ExecutablePath->ToLower());
	//            if (m_pDotNetAssembly == nullptr)
	//                return nullptr;
	//        }
	//        catch (ArgumentNullException ^ e)
	//        {
	//            Debug::WriteLine(L"WebRT InitAppFormTypeDic: " + e->Message);
	//        }
	//        catch (ArgumentException ^ e)
	//        {
	//            Debug::WriteLine(L"WebRT InitAppFormTypeDic: " + e->Message);
	//        }
	//        catch (FileNotFoundException ^ e)
	//        {
	//            Debug::WriteLine(L"WebRT InitAppFormTypeDic: " + e->Message);
	//        }
	//        catch (FileLoadException ^ e)
	//        {
	//            Debug::WriteLine(L"WebRT InitAppFormTypeDic: " + e->Message);
	//        }
	//        catch (BadImageFormatException ^ e)
	//        {
	//            Debug::WriteLine(L"WebRT InitAppFormTypeDic: " + e->Message);
	//        }
	//        finally
	//        {
	//            if (m_pDotNetAssembly != nullptr)
	//            {
	//                cli::array<Type^>^ pArray = m_pDotNetAssembly->GetExportedTypes();
	//                for each (Type ^ type in pArray)
	//                {
	//                    if (type->IsSubclassOf(Form::typeid))
	//                    {
	//                        Form^ m_pObj = nullptr;
	//                        try
	//                        {
	//                            m_pObj = (Form^)Activator::CreateInstance(type);
	//                            HICON hIcon = (HICON)m_pObj->Icon->Handle.ToPointer();
	//                            if (hIcon)
	//                            {
	//                                int nPos = filePath.ReverseFind('.');
	//                                CString strLib = filePath.Left(nPos).MakeLower();
	//                                CString strPath2 = strLib;
	//                                nPos = strPath2.ReverseFind('\\');
	//                                CString strPath = strPath2.Left(nPos + 1);
	//                                CString strNmae = strPath2.Mid(nPos + 1);
	//                                strPath2 = strPath;
	//                                strPath2 += marshal_as<CString>(type->FullName);
	//                                strPath2 += _T(" ");
	//                                strPath2 += strNmae;
	//                                strPath2 += _T(".ico");
	//                                //Write Icon to File Stream
	//                                System::IO::FileStream^ fs = gcnew System::IO::FileStream(marshal_as<String^>(strPath2), System::IO::FileMode::OpenOrCreate);
	//                                m_pObj->Icon->Save(fs);
	//                                fs->Close();
	//                                delete fs;
	//                            }
	//                        }
	//                        catch (Exception^)
	//                        {

	//                        }
	//                        finally
	//                        {
	//                            if (m_pObj && m_pObj->IsMdiContainer)
	//                            {
	//                                if (m_pAppMDIFormTypeDic == nullptr)
	//                                {
	//                                    m_pAppMDIFormTypeDic = gcnew Dictionary<String^, Type^>();
	//                                }
	//                                m_pAppMDIFormTypeDic[type->FullName] = type;
	//                            }
	//                            else
	//                            {
	//                                if (m_pObj && (m_pObj->FormBorderStyle == FormBorderStyle::FixedToolWindow || m_pObj->FormBorderStyle == FormBorderStyle::None || m_pObj->FormBorderStyle == FormBorderStyle::SizableToolWindow))
	//                                {
	//                                }
	//                                else
	//                                    m_pAppFormTypeDic[type->FullName] = type;
	//                            }
	//                            if (m_pObj)
	//                                m_pObj->Close();
	//                        }
	//                    }
	//                }
	//            }
	//        }
	//        if (m_pDotNetAssembly == nullptr)
	//        {
	//            return nullptr;
	//        }
	//    }
	//    return m_pAppFormTypeDic;
	//}

	//void WebRT::ExtractToDirectory(String^ strSRC, String^ strTarget)
	//{
	//}

	//void WebRT::ExportAllCLRObjInfo()
	//{
	//}

	String^ WebRT::AppDataPath::get()
	{
		BSTR bstrAppDataPath = g_pSpaceTelescopeImpl->m_strAppDataPath.AllocSysString();
		String^ strResult = marshal_as<String^>(bstrAppDataPath);
		::SysFreeString(bstrAppDataPath);
		return strResult;
	}

	String^ WebRT::AppCommonFormsPath::get()
	{
		return L"";
	}

	String^ WebRT::AppFormsPath::get()
	{
		return L"";
	}

	void WebRT::BindToCtrl(Control^ source, Control^ target, String^ strXmlData)
	{
		if (target != nullptr)
		{
			if (target->Dock == DockStyle::Fill || target->Dock == DockStyle::None)
			{
				CString strXml = strXmlData;

			}
		}
	}

	void WebRT::BindToCtrl(String^ ctrlID, String^ AssemblyQualifiedName, Control^ target, int nAnchor, String^ strXmlData)
	{
		if (target != nullptr)
		{
			if (target->Dock == DockStyle::Fill || target->Dock == DockStyle::None)
			{
				CString strXml = strXmlData;
			}
		}
	}

	Object^ WebRT::ActiveMethod(String^ strObjID, String^ strMethod, cli::array<Object^, 1>^ p)
	{
		Object^ pRetObj = nullptr;
		WebRT^ pApp = WebRT::GetWebRT();
		String^ strIndex = strObjID + L"|" + strMethod;
		MethodInfo^ mi = nullptr;
		Object^ pObj = nullptr;
		if (pApp->m_pWebRTCLRMethodDic->TryGetValue(strIndex, mi) == true)
		{
			try
			{
				pRetObj = mi->Invoke(pObj, p);
			}
			finally
			{
			}
			return pRetObj;
		}

		if (pApp->m_pWebRTCLRObjDic->TryGetValue(strObjID, pObj) == false)
		{
			pObj = CreateObject(strObjID);
			pApp->m_pWebRTCLRObjDic[strObjID] = pObj;
		}
		if (pObj != nullptr)
		{
			MethodInfo^ mi = nullptr;
			try
			{
				mi = pObj->GetType()->GetMethod(strMethod);
				pApp->m_pWebRTCLRMethodDic[strIndex] = mi;
			}
			catch (AmbiguousMatchException^ e)
			{
				Debug::WriteLine(L"WebRT::ActiveMethod GetMethod: " + e->Message);
			}
			catch (ArgumentNullException^ e)
			{
				Debug::WriteLine(L"WebRT::ActiveMethod GetMethod: " + e->Message);
			}
			finally
			{
				if (mi != nullptr)
				{
					try
					{
						pRetObj = mi->Invoke(pObj, p);
					}
					finally
					{
					}
				}
			}
		}

		return pRetObj;
	}

	void WebRT::CreateApplication(String^ appID, String^ strXml)
	{
		CComBSTR _strID = marshal_as<CComBSTR>(appID);
		CComBSTR _strXml = marshal_as<CComBSTR>(strXml);
		//if (appID->ToLower() == L"caswebagent.server.1")
		//{
		//    CComPtr<IWebRT> pApp;
		//    pApp.CoCreateInstance(_strID, nullptr, CLSCTX_SERVER);
		//    if (pApp)
		//    {
		//        DWORD dwID = ::GetCurrentProcessId();
		//        CString str = _T("");
		//        str.Format(_T("tangramprocess:%d"), dwID);
		//        CComVariant var;
		//        var.vt = VT_DISPATCH;
		//        var.pdispVal = (IDispatch*)theApp.m_pWebRT;
		//        pApp->put_AppKeyValue(CComBSTR(str), var);
		//    }
		//}
		//else
		{
			theApp.m_pWebRT->CreateApplication(_strID, _strXml);
		}
	}

	Object^ WebRT::ActiveObjectMethod(Object^ pObj, String^ strMethod, cli::array<Object^, 1>^ p)
	{
		Object^ pRetObj = nullptr;

		if (pObj != nullptr)
		{
			MethodInfo^ mi = nullptr;
			try
			{
				mi = pObj->GetType()->GetMethod(strMethod, gcnew cli::array<Type^, 1>(0));
			}
			catch (AmbiguousMatchException^ e)
			{
				Debug::WriteLine(L"WebRT::ActiveMethod GetMethod: " + e->Message);
			}
			catch (ArgumentNullException^ e)
			{
				Debug::WriteLine(L"WebRT::ActiveMethod GetMethod: " + e->Message);
			}
			finally
			{
				if (mi != nullptr)
				{
					try
					{
						pRetObj = mi->Invoke(pObj, p);
					}
					finally
					{
					}
				}
			}
		}

		return pRetObj;
	}

	Nuclei^ WebRT::CreateNucleusGroup(IntPtr nPageHandle)
	{
		LONGLONG hWnd = (LONGLONG)nPageHandle.ToInt64();
		INuclei* pNuclei = nullptr;
		theApp.m_pWebRT->CreateNucleusGroup(hWnd, &pNuclei);
		if (pNuclei)
		{
			Nuclei^ _pNuclei = theAppProxy._createObject<INuclei, Nuclei>(pNuclei);
			return _pNuclei;
		}
		return nullptr;
	}

	Nuclei^ WebRT::CreateNucleusGroup(Control^ ctrl, Object^ ExternalObj)
	{
		if (ctrl != nullptr)
		{
			if (theApp.m_pWebRT == nullptr)
				GetWebRT();
			LONGLONG hWnd = ctrl->Handle.ToInt64();
			INuclei* pNuclei = nullptr;
			theApp.m_pWebRT->CreateNucleusGroup(hWnd, &pNuclei);
			if (pNuclei)
			{
				Nuclei^ _pNuclei = theAppProxy._createObject<INuclei, Nuclei>(pNuclei);
				if (_pNuclei != nullptr && ExternalObj != nullptr)
				{
				}
				return _pNuclei;
			}
		}
		return nullptr;
	}

	Type^ WebRT::GetType(String^ strObjID)
	{
		if (String::IsNullOrEmpty(strObjID) == true)
			return nullptr;

		String^ m_strID = strObjID->ToLower()->Replace(L" ", L"");
		String^ strLib = nullptr;
		if (m_strID != L"")
		{
			Type^ pType = nullptr;
			WebRT^ pApp = WebRT::GetWebRT();
			Monitor::Enter(pApp->m_pWebRTCLRTypeDic);
			String^ strID = nullptr;
			if (pApp->m_pWebRTCLRTypeDic->TryGetValue(m_strID, pType) == false)
			{
				CString _strID = marshal_as<CString>(m_strID);
				int nIndex = _strID.Find(_T(","));
				if (nIndex != -1)
				{
					CString s1 = _strID.Mid(nIndex + 1);
					if (s1 == _T("host"))
					{
						CString s = _strID.Left(nIndex);
						_strID = _strID.Left(nIndex + 1) + g_pSpaceTelescopeImpl->m_strExeName;
						_strID.MakeLower();
					}
				}
				_strID = theApp.GetLibPathFromAssemblyQualifiedName(_strID);
				if (_strID != _T(""))
				{
					int nPos = _strID.Find(_T("|"));
					CString strObjName = _strID.Left(nPos);
					_strID = _strID.Mid(nPos + 1);
					nPos = _strID.Find(_T("|"));
					strID = marshal_as<String^>(_strID);
					CString strLibName = _strID.Left(nPos);
					strLib = marshal_as<String^>(_strID.Mid(nPos + 1));
					Assembly^ m_pDotNetAssembly = nullptr;
					bool bSystemObj = false;
					int nIndex = m_strID->IndexOf(L"system.windows.forms");;
					if (nIndex != -1)
					{
						bSystemObj = true;
						Control^ pObj = gcnew Control();
						m_pDotNetAssembly = pObj->GetType()->Assembly;
					}
					else
					{
						try
						{
							if (strLibName.CompareNoCase(_T("WebRT")) == 0)
								m_pDotNetAssembly = pApp->GetType()->Assembly;
							else
							{
								auto it = theAppProxy.m_mapAssembly.find(strLib);
								if (it != theAppProxy.m_mapAssembly.end())
									m_pDotNetAssembly = it->second;
								else
								{
									m_pDotNetAssembly = Assembly::LoadFile(strLib);
									theAppProxy.m_mapAssembly[strLib] = m_pDotNetAssembly;
								}
							}
						}
						catch (ArgumentNullException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject: " + e->Message);
						}
						catch (ArgumentException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject: " + e->Message);
						}
						catch (FileNotFoundException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject: " + e->Message);
						}
						catch (FileLoadException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject: " + e->Message);
						}
						catch (BadImageFormatException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject: " + e->Message);
						}
					}
					if (m_pDotNetAssembly != nullptr)
					{
						try
						{
							pType = m_pDotNetAssembly->GetType(marshal_as<String^>(strObjName), true, true);
						}
						catch (TypeLoadException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject Assembly->GetType: " + e->Message);
						}
						catch (ArgumentNullException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject Assembly->GetType: " + e->Message);
						}
						catch (ArgumentException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject Assembly->GetType: " + e->Message);
						}
						catch (FileNotFoundException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject Assembly->GetType: " + e->Message);
						}
						catch (FileLoadException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject Assembly->GetType: " + e->Message);
						}
						catch (BadImageFormatException^ e)
						{
							Debug::WriteLine(L"WebRT CreateObject Assembly->GetType: " + e->Message);
						}
						finally
						{
							if (pType != nullptr)
							{
								pApp->m_pWebRTCLRTypeDic->Add(m_strID, pType);
							}
						}
					}
				}
			}
			Monitor::Exit(pApp->m_pWebRTCLRTypeDic);
			if (pType)
			{
				return pType;
			}
		}
		return nullptr;
	}

	Browser^ WebRT::CreateBrowser(IntPtr ParentHandle, String^ strUrls)
	{
		HWND hPWnd = (HWND)ParentHandle.ToPointer();
		if (g_pSpaceTelescopeImpl->m_pBrowserFactory)
		{
			strUrls += L"|";
			strUrls = strUrls->Replace(L"||", L"|");
			CString strPath = g_pSpaceTelescopeImpl->m_strAppPath;

			strUrls = strUrls->Replace(L"host:", marshal_as<String^>(strPath));
			if (ParentHandle == (IntPtr)1)
			{
				hPWnd = g_pSpaceTelescopeImpl->m_hCosmosWnd;
			}

			HWND hWnd = g_pSpaceTelescopeImpl->m_pBrowserFactory->CreateBrowser(hPWnd, strUrls);
			IBrowser* pBrowser = (IBrowser*)::SendMessage(hWnd, WM_COSMOSMSG, 20190527, 0);
			auto it = theAppProxy.m_mapWebBrowser.find(pBrowser);
			if (it != theAppProxy.m_mapWebBrowser.end())
				return it->second;
			else
				return gcnew Browser(pBrowser);
		}
		return nullptr;
	}

	Form^ WebRT::CreateForm(IWin32Window^ parent, String^ strObjID)
	{
		Object^ m_pObj = nullptr;
		int nIndex = strObjID->IndexOf(L"<");
		if (nIndex == 0)
		{
			CTangramXmlParse m_Parse;
			CString strXml = strObjID;
			if (m_Parse.LoadXml(strXml) || m_Parse.LoadFile(strXml))
			{
				CString strType = m_Parse.attr(_T("type"), _T(""));
				if (strType.CompareNoCase(_T("winform")) == 0)
				{
					CString strID = m_Parse.attr(_T("objid"), _T(""));
					CString strName = m_Parse.name();
					if (strID != _T(""))
					{
						CTangramXmlParse* pChild3 = m_Parse.GetChild(_T("mdichild"));
						if (pChild3)
						{
							int nCount = pChild3->GetCount();
							if (nCount)
							{
								if (g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo)
								{
									delete g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo;
									g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
								}
								CMDIChildFormInfo* pInfo = new CMDIChildFormInfo();
								g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = pInfo;
								for (int i = 0; i < nCount; i++)
								{
									CString strName = pChild3->GetChild(i)->name().MakeLower();
									pChild3->GetChild(i)->put_attr(_T("mdichild"), true);
									pInfo->m_mapFormsInfo[strName] = pChild3->GetChild(i)->xml();
								}
							}
						}
						Object^ pObj = CreateObject(marshal_as<String^>(strID));
						if (pObj != nullptr)
						{
							if (pObj->GetType()->IsSubclassOf(Form::typeid))
							{
								Form^ thisForm = (Form^)pObj;
								thisForm->Show(parent);
							}
							return (Form^)pObj;
						}
					}
				}
			}
			return nullptr;
		}
		return nullptr;
	}

	Universe::Wormhole^ Universe::Xobj::Wormhole::get()
	{
		if (m_pXobj)
		{
			if (m_pSession == nullptr)
			{
				CSession* pSession = g_pSpaceTelescopeImpl->GetCloudSession(m_pXobj);
				if (pSession)
				{
					m_pSession = gcnew Universe::Wormhole(pSession);
					theAppProxy.m_mapSession2Wormhole[pSession] = m_pSession;
				}
			}
		}
		return m_pSession;
	}

	String^ WebRT::GetUIData(Control^ ctrl)
	{
		HWND hWnd = (HWND)ctrl->Handle.ToPointer();
		auto it = g_pSpaceTelescopeImpl->m_mapUIData.find(hWnd);
		if (it != g_pSpaceTelescopeImpl->m_mapUIData.end())
			return marshal_as<String^>(it->second);
		return L"";
	}

	String^ WebRT::GetCtrlTag(Control^ ctrl)
	{
		HWND hWnd = (HWND)ctrl->Handle.ToPointer();
		auto it = g_pSpaceTelescopeImpl->m_mapCtrlTag.find(hWnd);
		if (it != g_pSpaceTelescopeImpl->m_mapCtrlTag.end())
			return marshal_as<String^>(it->second);
		return L"";
	}

	Object^ WebRT::CreateObject(String^ strObjID)
	{
		Object^ m_pObj = nullptr;
		int nIndex = strObjID->IndexOf(L"<");
		if (nIndex == 0)
		{
			CTangramXmlParse m_Parse;
			CString strXml = strObjID;
			if (m_Parse.LoadXml(strXml) || m_Parse.LoadFile(strXml))
			{
				CString strType = m_Parse.attr(_T("type"), _T(""));
				if (strType.CompareNoCase(_T("winform")) == 0)
				{
					CString strID = m_Parse.attr(_T("objid"), _T(""));
					CString strName = m_Parse.name();
					if (strID != _T(""))
					{
						CTangramXmlParse* pChild3 = m_Parse.GetChild(_T("mdichild"));
						if (pChild3)
						{
							int nCount = pChild3->GetCount();
							if (nCount)
							{
								if (g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo)
								{
									delete g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo;
									g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = nullptr;
								}
								CMDIChildFormInfo* pInfo = new CMDIChildFormInfo();
								g_pSpaceTelescopeImpl->m_pCurMDIChildFormInfo = pInfo;
								for (int i = 0; i < nCount; i++)
								{
									CString strName = pChild3->GetChild(i)->name().MakeLower();
									pChild3->GetChild(i)->put_attr(_T("mdichild"), true);
									pInfo->m_mapFormsInfo[strName] = pChild3->GetChild(i)->xml();
								}
							}
						}
						Object^ pObj = CreateObject(marshal_as<String^>(strID));
						if (pObj != nullptr)
						{
							if (pObj->GetType()->IsSubclassOf(Form::typeid))
							{
								CString strCaption = m_Parse.attr(_T("caption"), _T(""));
								Form^ thisForm = (Form^)pObj;
								if (m_Parse.attrBool(_T("mainwindow")))
									g_pSpaceTelescopeImpl->m_hMainWnd = (HWND)thisForm->Handle.ToPointer();
								if (strCaption != _T(""))
									thisForm->Text = marshal_as<String^>(strCaption);
								if (thisForm->IsMdiContainer)
								{
									CString strBKPage = m_Parse.attr(_T("mdibkpageid"), _T(""));
									if (strBKPage != _T(""))
									{
										WebRT::CreateBKPage(thisForm, marshal_as<String^>(strBKPage));
									}
								}
								thisForm->Show();
							}
							return pObj;
						}
					}
				}
			}
			return nullptr;
		}
		Type^ pType = GetType(strObjID);
		if (pType)
		{
			try
			{
				m_pObj = (Object^)Activator::CreateInstance(pType);
			}
			catch (TypeLoadException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (ArgumentNullException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (ArgumentException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (NotSupportedException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (TargetInvocationException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (MethodAccessException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (InvalidComObjectException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (MissingMethodException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
			catch (COMException^ e)
			{
				Debug::WriteLine(L"WebRT CreateObject Activator::CreateInstance: " + e->Message);
			}
		}

		return m_pObj;
	}

	Xobj^ Xobj::Observe(String^ layerName, String^ layerXML)
	{
		if (m_pXobj)
		{
			CComBSTR blayerName = marshal_as<CComBSTR>(layerName);
			CComBSTR blayerXML = marshal_as<CComBSTR>(layerXML);
			IXobj* pXobj = nullptr;
			m_pXobj->Observe(blayerName, blayerXML, &pXobj);
			if (pXobj)
			{
				return theAppProxy._createObject<IXobj, Xobj>(pXobj);
			}
		}
		return nullptr;
	}

	Xobj^ Xobj::ObserveChild(int rowNum, int colNum, String^ layerName, String^ layerXML)
	{
		if (m_pXobj)
		{
			CComBSTR blayerName = marshal_as<CComBSTR>(layerName);
			CComBSTR blayerXML = marshal_as<CComBSTR>(layerXML);
			IXobj* pXobj = nullptr;
			m_pXobj->ObserveEx(rowNum, colNum, blayerName, blayerXML, &pXobj);
			if (pXobj)
			{
				return theAppProxy._createObject<IXobj, Xobj>(pXobj);
			}
		}
		return nullptr;
	}

	System::Void Xobj::LoadNode(TreeNode^ pXobj, CTangramXmlParse* pParse)
	{
		if (pParse)
		{
			int nCount = pParse->GetCount();
			for (int i = 0; i < nCount; i++)
			{
				CTangramXmlParse* _pParse = pParse->GetChild(i);
				if (_pParse)
				{
					CString name = _pParse->name();
					if (name == _T("tangramxml"))
					{
						HWND hWnd = (HWND)m_pBindTreeView->Handle.ToPointer();

						INucleus* pGalaxy = nullptr;
						IXobj* _pXobj = nullptr;
						m_pXobj->get_WinNucleus(&pGalaxy);
						CComBSTR bstrName("");
						pGalaxy->get_Name(&bstrName);
						String^ name = pXobj->Name + L".";
						name += m_pBindTreeView->Name;
						name += L"." + marshal_as<String^>(bstrName);
						CComBSTR strName = marshal_as<CComBSTR>(name->ToLower());
						Universe::WinNucleus^ _pGalaxy = Nuclei->CreateNucleus(m_pBindTreeView->Handle, name);
						pGalaxy->Observe(CComBSTR("default"), CComBSTR(_pParse->xml()), &_pXobj);
					}
					else
					{
						bool isTreeNode = _pParse->attrBool(_T("treenode"), false);
						if (isTreeNode)
						{
							TreeNode^ pChildNode = pXobj->Nodes->Add(marshal_as<String^>(_pParse->text()));
							if (pChildNode)
							{
								CString strTagName = name + _T("_tag");
								CTangramXmlParse* pChild2 = pParse->GetChild(strTagName);
								if (pChild2)
								{
									pChildNode->Tag = marshal_as<String^>(pChild2->xml());
								}
								LoadNode(pChildNode, pParse->GetChild(i));
							}
						}
					}
				}
			}
		}
	}

	void Xobj::NavigateTreeInit()
	{
		if (m_pBindTreeView != nullptr)
		{
			m_pBindTreeView->NodeMouseDoubleClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &Universe::Xobj::OnNodeMouseDoubleClick);
			m_pBindTreeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Universe::Xobj::OnAfterSelect);

			if (String::IsNullOrEmpty(m_strTreeViewData) == true)
				m_strTreeViewData = Universe::WebRT::m_strWizData;
			if (String::IsNullOrEmpty(m_strTreeViewData) == false)
			{
				String^ strData = m_strTreeViewData;
				CString strXml = marshal_as<CString>(strData);
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadXml(strXml) || m_Parse.LoadFile(strXml))
				{
					if (this->m_pBindTreeView->Nodes->Count == 0)
					{
						LoadNode(m_pBindTreeView->Nodes->Add(marshal_as<String^>(m_Parse.text())), &m_Parse);
					}
				}
				m_pBindTreeView->ExpandAll();
			}
		}
	}

	void Xobj::OnNodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e)
	{
		if (e->Node->Tag)
		{
			String^ strTag = e->Node->Tag->ToString();

			{
				Xobj^ pHostNode = nullptr;// hostnode->HostNode;
				if (bindTreeNode == nullptr)
				{
					String^ name = Attribute[L"bindnode"];
					if (String::IsNullOrEmpty(name) == false)
					{
						XobjCollection^ pCol = nullptr;
						RootXobj->GetXobjs(name, bindTreeNode, pCol);
						if (pCol)
						{
							delete pCol;
						}
					}
				}
				if (bindTreeNode != nullptr)
					pHostNode = bindTreeNode;
				if (pHostNode == nullptr)
				{
					pHostNode = HostXobj;
				}
				if (pHostNode)
				{
					CString strXml = strTag;
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						CString strAction = m_Parse.attr(_T("action"), _T(""));
						if (strAction != _T(""))
						{
							CTangramXmlParse* pChild = m_Parse.GetChild(strAction);
							if (pChild)
							{
								if (strAction == _T("doubleclick"))
									pHostNode->Observe(marshal_as<String^>(m_Parse.name()), marshal_as<String^>(pChild->xml()));
								else if (strAction == _T("openurl"))
								{
									Universe::WebRT::CreateBrowser(System::IntPtr::Zero, marshal_as<String^>(pChild->attr(_T("url"), _T("")) + _T("|")));
								}
							}

						}

					}
				}
			}
		}
	}

	void Xobj::OnAfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
	{
		if (e->Node->Tag)
		{
			String^ strTag = e->Node->Tag->ToString();

			{
				Xobj^ pHostNode = nullptr;
				if (bindTreeNode == nullptr)
				{
					String^ name = Attribute[L"bindnode"];
					if (String::IsNullOrEmpty(name) == false)
					{
						XobjCollection^ pCol = nullptr;
						RootXobj->GetXobjs(name, bindTreeNode, pCol);
						if (pCol)
							delete pCol;
					}
				}
				if (bindTreeNode != nullptr)
					pHostNode = bindTreeNode;
				//Xobj^ 
				if (pHostNode == nullptr)
				{
					pHostNode = HostXobj;
				}
				if (pHostNode)
				{
					CString strXml = strTag;
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						CTangramXmlParse* pChild = m_Parse.GetChild(_T("afterselected"));
						if (pChild)
							pHostNode->Observe(marshal_as<String^>(m_Parse.name()), marshal_as<String^>(pChild->xml()));
					}
				}
			}
		}
	}

	Object^ Xobj::ActiveMethod(String^ strMethod, cli::array<Object^, 1>^ p)
	{
		Object^ pRetObj = nullptr;
		if (m_pHostObj != nullptr)
		{
			MethodInfo^ mi = nullptr;
			if (m_pWebRTCLRMethodDic == nullptr)
				m_pWebRTCLRMethodDic = gcnew Dictionary<String^, MethodInfo^>();
			Object^ pObj = nullptr;
			if (m_pWebRTCLRMethodDic->TryGetValue(strMethod, mi) == true)
			{
				try
				{
					pRetObj = mi->Invoke(m_pHostObj, p);
				}
				finally
				{
				}
				return pRetObj;
			}
			try
			{
				mi = m_pHostObj->GetType()->GetMethod(strMethod);
				m_pWebRTCLRMethodDic[strMethod] = mi;
			}
			catch (AmbiguousMatchException^ e)
			{
				Debug::WriteLine(L"WebRT::ActiveMethod GetMethod: " + e->Message);
			}
			catch (ArgumentNullException^ e)
			{
				Debug::WriteLine(L"WebRT::ActiveMethod GetMethod: " + e->Message);
			}
			finally
			{
				if (mi != nullptr)
				{
					try
					{
						pRetObj = mi->Invoke(m_pHostObj, p);
					}
					finally
					{
					}
				}
			}
		}

		return pRetObj;
	}

	Nuclei::Nuclei(void)
	{
	}

	Nuclei::Nuclei(INuclei* pNuclei)
	{
		m_pNuclei = pNuclei;
		LONGLONG nValue = (LONGLONG)m_pNuclei;
		theAppProxy._insertObject(nValue, this);
		m_pWebRTClrEvent = new CNucleiEvent();
		m_pWebRTClrEvent->DispEventAdvise(m_pNuclei);
		m_pWebRTClrEvent->m_pNuclei = this;
	}

	Nuclei::~Nuclei()
	{
		if (m_pWebRTClrEvent)
		{
			m_pWebRTClrEvent->DispEventUnadvise(m_pNuclei);
			LONGLONG nValue = (LONGLONG)m_pNuclei;
			theAppProxy._removeObject(nValue);
			delete m_pWebRTClrEvent;
			m_pWebRTClrEvent = nullptr;
		}
	}

	void Nuclei::ObserveNuclei(String^ strFrames, String^ strKey, String^ bstrXml, bool bSaveToConfigFile)
	{
		m_pNuclei->ObserveNuclei(marshal_as<CComBSTR>(strFrames), marshal_as<CComBSTR>(strKey), marshal_as<CComBSTR>(bstrXml), bSaveToConfigFile);
	}

	Xobj^ Nuclei::GetXobj(String^ strName, String^ strNucleusName)
	{
		if (String::IsNullOrEmpty(strName) || String::IsNullOrEmpty(strNucleusName))
			return nullptr;
		CComBSTR bstrXml = marshal_as<CComBSTR>(strName);
		CComBSTR bstrNucleusName = marshal_as<CComBSTR>(strNucleusName);
		CComPtr<IXobj> pXobj;
		m_pNuclei->GetXobj(bstrXml, bstrNucleusName, &pXobj);
		Xobj^ pRetNode = nullptr;
		if (pXobj)
		{
			pRetNode = theAppProxy._createObject<IXobj, Xobj>(pXobj);
		}
		return pRetNode;
	}

	String^ Nuclei::GetPageXML()
	{
		BSTR bstrXML;
		m_pNuclei->get_NucleiXML(&bstrXML);
		String^ strXML = marshal_as<String^>(bstrXML);
		return strXML;
	}

	void WinNucleus::SendMessage(String^ strFrom, String^ strTo, String^ strMsgId, String^ strMsgContent, String^ strExtra)
	{
		if (m_pNucleus)
		{
			__int64 nHandle;
			m_pNucleus->get_HWND(&nHandle);
			HWND hWnd = (HWND)nHandle;
			IPCMsg msg;
			msg.m_strId = L"MESSAGE";
			msg.m_strParam1 = strFrom;
			msg.m_strParam2 = strTo;
			msg.m_strParam3 = strMsgId;
			msg.m_strParam4 = strMsgContent;
			msg.m_strParam5 = strExtra;
			g_pSpaceTelescopeImpl->m_pCurrentIPCMsg = &msg;
			::SendMessage(hWnd, WM_HUBBLE_DATA, (WPARAM)&msg, 20200203);
		}
		g_pSpaceTelescopeImpl->m_pCurrentIPCMsg = nullptr;
	}

	Xobj^ WinNucleus::Observe(String^ layerName, String^ layerXML)
	{
		Universe::Xobj^ pRetNode = nullptr;
		CComBSTR blayerName = marshal_as<CComBSTR>(layerName);
		CComBSTR blayerXML = marshal_as<CComBSTR>(layerXML);
		CComPtr<IXobj> pXobj;
		m_pNucleus->Observe(blayerName, blayerXML, &pXobj);
		if (pXobj)
		{
			pRetNode = theAppProxy._createObject<IXobj, Universe::Xobj>(pXobj);
			Universe::Xobj^ pRetNode2 = nullptr;
			if (!TryGetValue(layerName, pRetNode2))
			{
				Add(layerName, pRetNode);
			}
		}
		return pRetNode;
	}
}
