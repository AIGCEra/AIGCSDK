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

#pragma once
#include "../Cosmos.h"
#include "tangrambase.h"

class CEclipseWnd;
class CEclipseCtrl;

class ATL_NO_VTABLE CEclipseExtender :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IEclipseExtender, &IID_IEclipseExtender, &LIBID_Universe, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEclipseExtender(void);
	virtual ~CEclipseExtender(void);

	BEGIN_COM_MAP(CEclipseExtender)
		COM_INTERFACE_ENTRY(IEclipseExtender)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	STDMETHOD(Close)();
	STDMETHOD(get_ActiveWorkBenchWindow)(BSTR bstrID, IWorkBenchWindow** pVal);
};

class ATL_NO_VTABLE CEclipseWnd :
	public CWindowImpl<CEclipseWnd, CWindow>,
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IWorkBenchWindow, &IID_IWorkBenchWindow, &LIBID_Universe, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEclipseWnd(void);
	virtual ~CEclipseWnd(void);
	BOOL							m_bInit;
	int								m_nNewWinCmdID;
	HWND							m_hClient;
	CString							m_strAppProxyID;
	CString							m_strDocKey;
	CString							m_strXml;
	CString							m_strPath;
	CString							m_strFrameID;
	CString							m_strNodeName;
	CNuclei*					m_pNuclei;
	CXobj*							m_pCurXobj;
	CXobj*							m_pHostXobj;
	CNucleus*					m_pNucleus;
	IUniverseAppProxy*				m_pAppProxy;
	void Show(CString strID);
	BEGIN_COM_MAP(CEclipseWnd)
		COM_INTERFACE_ENTRY(IWorkBenchWindow)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	BEGIN_MSG_MAP(CEclipseWnd)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
		MESSAGE_HANDLER(WM_COSMOSMSG, OnWebRTMsg)
		MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
		MESSAGE_HANDLER(WM_QUERYAPPPROXY, OnQueryAppProxy)
		MESSAGE_HANDLER(WM_HUBBLE_GETXML, OnWebRTGetXml)
	END_MSG_MAP()
protected:
	ULONG InternalAddRef() { return 1; }
	ULONG InternalRelease() { return 1; }

	LRESULT OnCommand(UINT, WPARAM, LPARAM, BOOL& );
	LRESULT OnClose(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnQueryAppProxy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnActivate(UINT, WPARAM, LPARAM, BOOL& );
	LRESULT OnShowWindow(UINT, WPARAM, LPARAM, BOOL& );
	LRESULT OnWebRTMsg(UINT, WPARAM, LPARAM, BOOL& );
	LRESULT OnWebRTGetXml(UINT, WPARAM, LPARAM, BOOL& );

	void OnFinalMessage(HWND hWnd);

	STDMETHOD(get_Count)(long* pCount);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	STDMETHOD(get_Handle)(LONGLONG* pVal);
	STDMETHOD(get_CosmosCtrl)(LONGLONG hWnd, IEclipseCtrl** pVal);
	STDMETHOD(get_Nuclei)(INuclei** pVal);
	STDMETHOD(get_WinNucleus)(INucleus** pVal);
	STDMETHOD(Active)();
	STDMETHOD(CloseTangramUI)();
	STDMETHOD(ObserveEx)(BSTR bstrKey, BSTR bstrXml, IXobj** ppXobj);
	STDMETHOD(ObserveinView)(int nIndex, BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj);

public:
	STDMETHOD(get_Ctrl)(VARIANT vIndex, IEclipseCtrl **ppCtrl);
	STDMETHOD(Observe)(BSTR bstrKey, BSTR bstrXml, IXobj** ppXobj);
	void CreatePage(BOOL bSaveToConfigFile);
};

