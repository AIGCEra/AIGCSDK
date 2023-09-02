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
#include <afxcontrolbars.h>     // MFC support for ribbons and control bars
#include "metahost.h"
#include "CommonUniverse.h"
#include "TangramXmlParse.h"
#include <ppl.h>
#include <ppltasks.h>
#include <agents.h>
#include <shlobj.h>
#include <atlctl.h>
#include <afxcview.h>

using namespace std;
using namespace ATL;
using namespace concurrency;

#pragma comment(lib, "imagehlp.lib")

namespace CommonUniverse
{
	class CAIGCWinApp :
		public CWinApp,
		public IUniverseAppProxy,
		public IWindowProvider {
	public:
		CAIGCWinApp();
		virtual ~CAIGCWinApp();
		CString GetDocTemplateID(CDocument* pDoc);

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);

	private:
		bool m_bBuiltInBrowser = false;
		bool m_bCrashReporting = false;
		bool m_bNoDefaultMainWnd = false;
		map<CView*, CDocument*> m_mapViewDoc;
		BOOL IsBrowserModel(bool bCrashReporting);
		bool ProcessAppType(bool bCrashReporting);
		virtual int Run();
		virtual BOOL InitApplication();
		virtual HWND GetActivePopupMenu(HWND hWnd);

		//IUniverseAppProxy:
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {};
		virtual void OnObserveComplete(HWND hContentLoaderWnd, CString strUrl, IXobj* pRootNode) {};
		virtual CXobjProxy* OnXobjInit(IXobj* pNewNode);
		virtual CNucleusProxy* OnNucleusCreated(INucleus* pNewFrame);
		virtual CNucleiProxy* OnNucleiCreated(INuclei* pNewContentLoaderManager);
		virtual void OnIPCMsg(CWebViewImpl* pWebViewImpl, CString strType, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5);
		virtual void CustomizedDOMElement(HWND hWnd, CString strRuleName, CString strHTML) {};
		virtual void OpenDocFile(CString strFileName, CString strExt, CString strCreatingDOCID);
		virtual HWND QueryWndInfo(QueryType nType, HWND hWnd);
		virtual CString QueryWndClassName(HWND hWnd);
		virtual CString QueryDocType(HWND hWnd);
		virtual bool EclipseAppInit() { return false; };
		virtual bool SetFrameCaption(HWND hWnd, CString strCaption, CString strAppName);
		virtual CString QueryParentInfo(HWND hPWnd, void* lpInfo);
		virtual HWND GetFrameWnd(HWND hWnd, int& nType);

		//IWindowProvider:
		virtual CString GetNames();
		virtual CString GetTags(CString strName);
		virtual HWND Create(HWND hParentWnd, IXobj* pGrid);
	};

	class CComponentApp :
		public CWinApp,
		public IWindowProvider
	{
	public:
		CComponentApp();
		virtual ~CComponentApp();
		bool WebRTInit(CString strID);
		virtual BOOL InitInstance();
		virtual int ExitInstance();
	private:
		virtual CString GetNames();
		virtual CString GetTags(CString strName);
		virtual HWND Create(HWND hParentWnd, IXobj* pGrid);
	};

	class CAIGCWinAppEx :
		public CWinAppEx,
		public IUniverseAppProxy,
		public IWindowProvider {
	public:
		CAIGCWinAppEx();
		virtual ~CAIGCWinAppEx();
		CString GetDocTemplateID(CDocument* pDoc);

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);

	private:
		bool m_bBuiltInBrowser = false;
		bool m_bCrashReporting = false;
		bool m_bNoDefaultMainWnd = false;
		map<CView*, CDocument*> m_mapViewDoc;
		BOOL IsBrowserModel(bool bCrashReporting);
		bool ProcessAppType(bool bCrashReporting);
		virtual int Run();
		virtual BOOL InitApplication();
		virtual HWND GetActivePopupMenu(HWND hWnd);

		//IUniverseAppProxy:
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {};
		virtual void OnObserveComplete(HWND hContentLoaderWnd, CString strUrl, IXobj* pRootNode) {};
		virtual CXobjProxy* OnXobjInit(IXobj* pNewNode);
		virtual CNucleusProxy* OnNucleusCreated(INucleus* pNewFrame);
		virtual CNucleiProxy* OnNucleiCreated(INuclei* pNewContentLoaderManager);
		virtual void OnIPCMsg(CWebViewImpl* pWebViewImpl, CString strType, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5);
		virtual void CustomizedDOMElement(HWND hWnd, CString strRuleName, CString strHTML) {};
		virtual void OpenDocFile(CString strFileName, CString strExt, CString strCreatingDOCID);
		virtual HWND QueryWndInfo(QueryType nType, HWND hWnd);
		virtual CString QueryWndClassName(HWND hWnd);
		virtual CString QueryDocType(HWND hWnd);
		virtual bool EclipseAppInit() { return false; };
		virtual bool SetFrameCaption(HWND hWnd, CString strCaption, CString strAppName);
		virtual CString QueryParentInfo(HWND hPWnd, void* lpInfo);
		virtual HWND GetFrameWnd(HWND hWnd, int& nType);

		//IWindowProvider:
		//virtual bool WebRTInit(CString strID);
		virtual CString GetNames();
		virtual CString GetTags(CString strName);
		virtual HWND Create(HWND hParentWnd, IXobj* pGrid);
	};

	class CWebRTMDIFrame :
		public CMDIFrameWndEx,
		public CNucleiProxy
	{
	public:
		CWebRTMDIFrame() {};
		virtual ~CWebRTMDIFrame() {};

		DECLARE_DYNCREATE(CWebRTMDIFrame)

		virtual BOOL OnShowPopupMenu(CMFCPopupMenu* /*pMenuPopup*/);
		//virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
		virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	protected:
		DECLARE_MESSAGE_MAP()

	private:
		bool bAdjustClient = false;

		void AdjustClientArea();
		void OnTabChange(IXobj* sender, LONG ActivePage, LONG OldPage);
		void OnClrControlCreated(IXobj* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle);
		void OnEvent(IDispatch* sender, IDispatch* EventArg) {};
		void OnControlNotify(IXobj* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName) {};
		void OnHubbleEvent(IWebRTEventObj* NotifyObj) {};
	};
};

using namespace CommonUniverse;
extern IWebRT* g_pWebRT;

#ifndef CMDIFrameWndEx
	#ifndef _WINDLL
		#define CWinApp CAIGCWinApp
	#else
		#define CWinApp CComponentApp
	#endif // !_WINDLL

	#define CWinAppEx CAIGCWinAppEx
	#define CMDIFrameWndEx CWebRTMDIFrame
#endif // !CMDIFrameWndEx
