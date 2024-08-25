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

// Nuclei.h : CNuclei implementation file

#pragma once

#include <assert.h>
#include <wininet.h>

#include "EclipsePlus\EclipseAddin.h"

// CNuclei
class ATL_NO_VTABLE CNuclei : 
	public CComObjectRootBase,
	public IConnectionPointContainerImpl <CNuclei>,
	public IConnectionPointImpl<CNuclei, &__uuidof(_IWebRTObjEvents)>,
	public IDispatchImpl<INuclei, &IID_INuclei, &LIBID_Universe, 1, 0>
{
	friend CSpaceTelescope;
public:
	CNuclei();
	virtual ~CNuclei();

	BOOL										m_bDoc;
	BOOL										m_bPageDataLoaded;
	HWND										m_hWnd;

	CString										m_strPageFilePath;
	CString										m_strPageFileName;
	CString										m_strConfigFileNodeName;
	CString										m_strXmlHeader;
	CString										m_strXmlBottom;

	CNucleus*									m_pBKGalaxy;
	CCloudWinForm*								m_pParentWinFormWnd;
	IUniverseAppProxy*							m_pUniverseAppProxy;
	map<CString, CString>						m_strMapKey;
	map<CString, HWND>							m_mapWnd;
	map<HWND, CNucleus*>						m_mapGalaxy;
	map<CString, CXobj*>						m_mapXobj;
	map<__int64, CWebRTEvent*>				m_mapEventObj;
	map<IUniverseAppProxy*, CNucleiProxy*>		m_mapNucleiProxy;

	BEGIN_COM_MAP(CNuclei)
		COM_INTERFACE_ENTRY(INuclei)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CNuclei)
		CONNECTION_POINT_ENTRY(__uuidof(_IWebRTObjEvents))
	END_CONNECTION_POINT_MAP()

	void Lock(){}
	void Unlock(){}
	void BeforeDestory();
	HRESULT Fire_GalaxyClusterLoaded(IDispatch* sender, BSTR url);
	HRESULT Fire_NodeCreated(IXobj * pXobjCreated);
	HRESULT Fire_AddInCreated(IXobj * pRootXobj, IDispatch * pAddIn, BSTR bstrID, BSTR bstrAddInXml);
	HRESULT Fire_BeforeOpenXml(BSTR bstrXml, LONGLONG hWnd);
	HRESULT Fire_OpenXmlComplete(BSTR bstrXml, LONGLONG hWnd, IXobj * pRetRootNode);
	HRESULT Fire_Destroy();
	HRESULT Fire_NodeMouseActivate(IXobj * pActiveNode);
	HRESULT Fire_ClrControlCreated(IXobj * Node, IDispatch * Ctrl, BSTR CtrlName, LONGLONG CtrlHandle);
	HRESULT Fire_TabChange(IXobj* sender, LONG ActivePage, LONG OldPage);
	HRESULT Fire_CosmosEvent(IWebRTEventObj* pEventObj);
	HRESULT Fire_IPCMsg(INucleus* pSender, BSTR bstrType, BSTR bstrContent, BSTR bstrFeature);

protected:
	ULONG InternalAddRef(){ return 1; }
	ULONG InternalRelease(){ return 1; }

public:
	STDMETHOD(get_Count)(long* pCount);
	STDMETHOD(get_WinNucleus)(VARIANT vIndex, INucleus ** ppNucleus);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	STDMETHOD(get_Handle)(LONGLONG* pVal);
	STDMETHOD(get_NucleusName)(LONGLONG hHwnd, BSTR* pVal);
	STDMETHOD(get_Xobj)(BSTR bstrNodeName, IXobj** pVal);
	STDMETHOD(get_XobjNames)(BSTR* pVal);
	STDMETHOD(get_XObject)(BSTR bstrName, IDispatch** pVal);
	STDMETHOD(get_Parent)(INuclei** pVal);
	STDMETHOD(get_Width)(long* pVal);
	STDMETHOD(put_Width)(long newVal);
	STDMETHOD(get_Height)(long* pVal);
	STDMETHOD(put_Height)(long newVal);
	STDMETHOD(get_NucleiXML)(BSTR* pVal);

	STDMETHOD(CreateNucleus)(VARIANT ParentObj, VARIANT HostWnd, BSTR bstrNucleusName, INucleus** pRetFrame);
	STDMETHOD(GetXobj)(BSTR bstrNucleusName, BSTR bstrNodeName, IXobj** pRetNode);
	STDMETHOD(GetNucleusFromCtrl)(IDispatch* ctrl, INucleus** ppNucleus);
	STDMETHOD(GetCtrlInXobj)(BSTR NodeName, BSTR CtrlName, IDispatch** ppCtrl);
	STDMETHOD(Observe)(IDispatch* Parent, BSTR CtrlName, BSTR NucleusName, BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj);
	STDMETHOD(ObserveCtrl)(VARIANT MdiForm, BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj);
	STDMETHOD(ObserveNuclei)(BSTR bstrFrames, BSTR bstrKey, BSTR bstrXml, VARIANT_BOOL bSaveToConfigFile);
};

