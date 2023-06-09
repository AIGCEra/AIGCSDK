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

#pragma once

#include <map>
#include "CommonUniverse.h"
#include "TangramXmlParse.h"
#include <ppl.h>
#include <ppltasks.h>
#include <agents.h>
#include <shlobj.h>

#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

using namespace std;
using namespace ATL;
using namespace concurrency;

#pragma comment(lib, "imagehlp.lib")

namespace CommonUniverse
{
	class CAIGCApp :
		public IUniverseAppProxy,
		public IWindowProvider {
	public:
		CAIGCApp();
		virtual ~CAIGCApp();

		CString m_strExeName;

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);

		virtual BOOL InitApplication();
	private:
		bool m_bBuiltInBrowser = false;
		bool m_bCrashReporting = false;
		bool m_bNoDefaultMainWnd = false;
		BOOL IsBrowserModel(bool bCrashReporting);
		bool ProcessAppType(bool bCrashReporting);
		virtual HWND GetActivePopupMenu(HWND hWnd) { return NULL; };

		//IUniverseAppProxy:
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {};
		virtual void OnObserveComplete(HWND hContentLoaderWnd, CString strUrl, IXobj* pRootNode) {};
		virtual CXobjProxy* OnXobjInit(IXobj* pNewNode);
		virtual CNucleusProxy* OnNucleusCreated(INucleus* pNewFrame);
		virtual CNucleiProxy* OnNucleiCreated(INuclei* pNewContentLoaderManager);
		virtual void OnIPCMsg(CWebPageImpl* pWebPageImpl, CString strType, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5) {};
		virtual void CustomizedDOMElement(HWND hWnd, CString strRuleName, CString strHTML) {};
		virtual void OpenDocFile(CString strFileName, CString strExt, CString strCreatingDOCID) {};
		virtual HWND QueryWndInfo(QueryType nType, HWND hWnd) { return NULL; };
		virtual CString QueryWndClassName(HWND hWnd) { return _T(""); };
		virtual CString QueryDocType(HWND hWnd) { return _T(""); };
		virtual bool EclipseAppInit() { return false; };
		virtual bool SetFrameCaption(HWND hWnd, CString strCaption, CString strAppName) { return false; };
		virtual CString QueryParentInfo(HWND hPWnd, void* lpInfo) { return _T(""); };
		virtual HWND GetFrameWnd(HWND hWnd, int& nType) { return NULL; };

		//IWindowProvider:
		virtual CString GetNames() { return _T(""); };
		virtual CString GetTags(CString strName) { return _T(""); };
		virtual HWND Create(HWND hParentWnd, IXobj* pXobj) { return NULL; };
	};

	class CWebRTWindowProviderApp :
		public IWindowProvider {
	public:
		CWebRTWindowProviderApp();
		virtual ~CWebRTWindowProviderApp();

		HINSTANCE m_hModule;

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);
	private:
		//IWindowProvider:
		virtual HWND Create(HWND hParentWnd, IXobj* pXobj) { return NULL; };
	};

	template <class T>
	class ATL_NO_VTABLE CAIGCModuleT :
		public CAIGCApp,
		public CAtlExeModuleT<T>
	{
	public:
		virtual HRESULT PreMessageLoop(int nShowCmd) {
			if (InitApplication()) {
				__super::PreMessageLoop(nShowCmd);
				return S_OK;
			}
			return S_FALSE;
		}
	};
};

using namespace CommonUniverse;
extern IWebRT* g_pWebRT;
