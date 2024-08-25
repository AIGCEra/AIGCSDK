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
 
 // TangramTreeView.h : Declaration of the CTangramTreeView

#pragma once
#include "resource.h"       // main symbols
#include "universe.h"

class CTangramHtmlTreeWnd;
// CTangramTreeView

class CTangramTreeView :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IWebRTTreeView, &IID_IWebRTTreeView, &LIBID_Universe, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTangramTreeView();

DECLARE_NO_REGISTRY()

	CTangramHtmlTreeWnd* m_pWebRTHtmlTreeWnd;
	map<CString,IWebRTTreeViewCallBack*>	m_mapWebRTTreeViewCallBack;
BEGIN_COM_MAP(CTangramTreeView)
	COM_INTERFACE_ENTRY(IWebRTTreeView)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease();

public:
	STDMETHOD(put_TangramTreeViewCallBack)(BSTR bstrKey, IWebRTTreeViewCallBack* newVal);
	STDMETHOD(AddTreeNode)(long hItem, BSTR bstrXml);
	STDMETHOD(InsertNode)(BSTR bstrXml, long* hItem);
	STDMETHOD(get_FirstRoot)(long* pVal);
};
