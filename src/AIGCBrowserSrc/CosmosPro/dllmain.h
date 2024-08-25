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

// dllmain.h : Declaration of module class.

#include "CosmosEvents.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

class CXobjCLREvent;

class CSpaceTelescope :
	public IWebRTDelegate,
	public IUniverseAppProxy
{
public:
	CSpaceTelescope();
	virtual ~CSpaceTelescope();

	bool									m_bHostApp;
	bool									m_bNativeApp;
	bool									m_bBrowserModeInit = false;
	DWORD									m_dwThreadID;
	IWebRT*									m_pWebRT;

	CString									m_strAppPath;
	CString									m_strOfficeComponentPath;

	CString GetLibPathFromAssemblyQualifiedName(CString strAssemblyQualifiedName);
	//CString BuildConfigDataFile(CString strExeName, CString strProductName, CString strCompanyPathName);
	virtual void ProcessMsg(MSG* msg);
	virtual void ForegroundIdleProc() {};
	virtual bool DoIdleWork();
	virtual bool OnAppIdle(BOOL& bIdle, LONG lCount) {
		return false;
	};

	virtual HWND QueryCanClose(HWND hWnd) { return NULL; };

	virtual bool IsAppIdleMessage() {
		return false;
	};

	virtual HWND GetMainWnd()
	{
		return NULL;
	};

	virtual void WebRTInit() {};
	virtual bool OnUniversePreTranslateMessage(MSG* pMsg);

	void InitWebRTApp(bool bCrashReporting);
private:
	//CWebRTEvents:
	void OnWebRTClose(CosmosCloseState state);
	void OnObserveComplete(HWND hWnd, CString strUrl, IXobj* pRootXobj);
	HWND InitWebRTApp();
	CString _GetLibPathFromAssemblyQualifiedName(CString strDir, CString strLibName);
	virtual void IPCMsg(HWND hWnd, CString strType, CString strParam1, CString strParam2);
	virtual void CustomizedDOMElement(HWND hWnd, CString strRuleName, CString strHTML);
};

extern CSpaceTelescope theApp;

class CWebRTXobjEvent : public CXobjEvents
{
public:
	CWebRTXobjEvent();
	virtual ~CWebRTXobjEvent();

	CXobjCLREvent* m_pXobjCLREvent;
private:
	void __stdcall  OnObserveComplete();
	void __stdcall  OnDestroy();
	void __stdcall  OnDocumentComplete(IDispatch* pDocdisp, BSTR bstrUrl);
	void __stdcall  OnXobjAddInCreated(IDispatch* pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml);
	void __stdcall  OnTabChange(int nActivePage, int nOldPage);
	void __stdcall  OnIPCMessageReceived(BSTR bstrFrom, BSTR bstrTo, BSTR bstrMsgId, BSTR bstrPayload, BSTR bstrExtra);
};
