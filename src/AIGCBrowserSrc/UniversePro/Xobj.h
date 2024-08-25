/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001           *
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

// Xobj.h : Declaration of the CXobj

#include "Nuclei.h"
#include "chromium/BrowserWnd.h"

#pragma once

class CWormhole;
class CXobjShareData
{
public:
	CXobjShareData();
	~CXobjShareData();

	CNucleus*				m_pNucleus = nullptr;
	CNucleus*				m_pOldGalaxy = nullptr;
	IDispatch*				m_pOfficeObj = nullptr;
	CXobjWnd*				m_pHostClientView = nullptr;
	CTangramXmlParse*		m_pWebRTParse = nullptr;
	CNuclei*				m_pNuclei = nullptr;
	CMapStringToPtr			m_PlugInDispDictionary;
};

// CXobj 
class ATL_NO_VTABLE CXobj : 
	public CComObjectRootBase,
	public IConnectionPointContainerImpl<CXobj>,
	public IConnectionPointImpl<CXobj, &__uuidof(_IXobjEvents)>,
	public IDispatchImpl<IXobj, &IID_IXobj, &LIBID_Universe, 1, 0>
{
public:
	CXobj();
	virtual ~CXobj();

	BOOL							m_bTopObj;
	BOOL							m_bCreated;
	BOOL							m_bWebCommandMsg = false;;

	XobjType						m_nViewType;
	int								m_nID;
	int								m_nActivePage;
	int								m_nWidth;
	int								m_nHeigh;
	int								m_nRow;
	int								m_nCol;
	int								m_nRows;
	int								m_nCols;
	HWND							m_hHostWnd;
	HWND							m_hHostCtrlWnd;
	HWND							m_hChildHostWnd;

	CString 						m_strID;
	CString 						m_strURL;
	CString							m_strKey;
	CString							m_strName;
	CString 						m_strObjTypeID;
	CString 						m_strCaption;
	CString 						m_strCosmosXml = _T("");
	CString 						m_strXmlRefXobjInfo=_T("");

	CString							m_strLastIPCMsgID = _T("");
	CString							m_strLastIPCParam1 = _T("");
	CString							m_strLastIPCParam2 = _T("");
	CString							m_strLastIPCParam3 = _T("");
	CString							m_strLastIPCParam4 = _T("");
	CString							m_strLastIPCParam5 = _T("");

	CString							m_strNodeName;
	CString 						m_strExtenderID;

	IDispatch*						m_pDisp;
	CComPtr<IUnknown>				m_pUnk;
	CXobj* 							m_pRootObj;
	CXobj* 							m_pParentObj;
	CCloudWinForm*					m_pParentWinFormWnd;
	CTangramXmlParse*				m_pHostParse;
	CTangramXmlParse* 				m_pDocXmlParseNode;
	IContainer*						m_pWindow;
	CXobjShareData*					m_pXobjShareData;
	CBrowser*						m_pWebBrowser;
	CWnd*							m_pHostWnd;
	CNucleus*						m_pHostGalaxy;
	CRuntimeClass*					m_pObjClsInfo;

	CXobjEvents*					m_pCLREventConnector;

	VARIANT							m_varTag;
	IDispatch*						m_pExtender;
	CXobjVector						m_vChildNodes;
	CXobj*							m_pCurrentExNode;
	CXobj*							m_pNucleusNode;
	CWebView*						m_pWebView = nullptr;
	CWormhole*						m_pWormhole;
	map<CString, CNucleus*>			m_mapSubFrame;
	map<CXobj*, CString>			m_mapExtendNode;
	map<CString, CXobj*>			m_mapChildXobj;
	map<HWND, CCloudWinForm*>		m_mapFormNode;
	CComObject<CXobjCollection>*	m_pChildNodeCollection;

	map<IUniverseAppProxy*, CXobjProxy*> m_mapWndXobjProxy;

	void	InitWndXobj();
	BOOL	Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext);
	BOOL	PreTranslateMessage(MSG* pMsg);
	BOOL	AddChildNode(CXobj* pXobj);
	BOOL	RemoveChildNode(CXobj* pXobj);
	CString GetNames();
	CWebView* GetHtmlWnd();
	void NodeCreated();
	CXobj* GetVisibleChildByName(CString strXobjName);
	HRESULT Fire_ObserveComplete();
	HRESULT Fire_Destroy();
	HRESULT Fire_XobjAddInCreated(IDispatch * pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml);
	HRESULT Fire_XobjAddInsCreated();
	HRESULT Fire_XobjDocumentComplete(IDispatch * ExtenderDisp, BSTR bstrURL);
	HRESULT Fire_ControlNotify(IXobj * sender, LONG NotifyCode, LONG CtrlID, LONGLONG CtrlHandle, BSTR CtrlClassName);
	HRESULT Fire_TabChange(LONG ActivePage, LONG OldPage);
	HRESULT Fire_IPCMessageReceived(BSTR bstrFrom, BSTR bstrTo, BSTR bstrMsgId, BSTR bstrPayload, BSTR bstrExtra);

	void Lock(){}
	void Unlock(){}
protected:
	ULONG InternalAddRef(){ return 1; }
	ULONG InternalRelease(){ return 1; }

public:
	STDMETHOD(get_XObject)(VARIANT* pVar);
	STDMETHOD(get_Tag)(VARIANT* pVar);
	STDMETHOD(put_Tag)(VARIANT var);
	STDMETHOD(get_AxPlugIn)(BSTR bstrName, IDispatch** pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(put_Name)(BSTR bstrName);
	STDMETHOD(get_Caption)(BSTR* pVal);
	STDMETHOD(put_Caption)(BSTR bstrCaption);
	STDMETHOD(get_Attribute)(BSTR bstrKey, BSTR* pVal);
	STDMETHOD(put_Attribute)(BSTR bstrKey, BSTR bstrVal);
	STDMETHOD(get_Handle)(LONGLONG* hWnd);
	STDMETHOD(get_XML)(BSTR* pVal);
	STDMETHOD(get_ChildNodes)(IXobjCollection** );
	STDMETHOD(get_Row)(long* nRow);
	STDMETHOD(get_Col)(long* nCol);
	STDMETHOD(get_Objects)(long nType, IXobjCollection** );
	STDMETHOD(get_XobjType)(XobjType* nType);
	STDMETHOD(get_ParentXobj)(IXobj** ppXobj);
	STDMETHOD(get_RootXobj)(IXobj** ppXobj);
	STDMETHOD(get_OuterXml)(BSTR* pVal);
	STDMETHOD(get_Key)(BSTR* pVal);
	STDMETHOD(get_WinNucleus)(INucleus** pVal);
	STDMETHOD(get_HostGalaxy)(INucleus** pVal);
	STDMETHOD(get_Height)(LONG* pVal);
	STDMETHOD(get_Width)(LONG* pVal);
	STDMETHOD(get_Extender)(IDispatch** pVal);
	STDMETHOD(put_Extender)(IDispatch* newVal);
	STDMETHOD(get_Nuclei)(INuclei** pVal);
	STDMETHOD(get_NameAtWindowPage)(BSTR* pVal);
	STDMETHOD(get_DocXml)(BSTR* pVal);
	STDMETHOD(get_HostXobj)(IXobj** pVal);
	STDMETHOD(put_HostXobj)(IXobj* newVal);
	STDMETHOD(get_ActivePage)(int* pVal);
	STDMETHOD(put_ActivePage)(int newVal);
	STDMETHOD(get_OfficeObj)(IDispatch** pVal);
	STDMETHOD(get_WebView)(IWebView** pVal);

	STDMETHOD(get_Rows)(long* nRows);
	STDMETHOD(get_Cols)(long* nCols);
	STDMETHOD(get_Hmin)(int* pVal);
	STDMETHOD(put_Hmin)(int newVal);
	STDMETHOD(get_Hmax)(int* pVal);
	STDMETHOD(put_Hmax)(int newVal);
	STDMETHOD(get_Vmin)(int* pVal);
	STDMETHOD(put_Vmin)(int newVal);
	STDMETHOD(get_Vmax)(int* pVal);
	STDMETHOD(put_Vmax)(int newVal);
	STDMETHOD(get_rgbMiddle)(OLE_COLOR* pVal);
	STDMETHOD(put_rgbMiddle)(OLE_COLOR newVal);
	STDMETHOD(get_rgbRightBottom)(OLE_COLOR* pVal);
	STDMETHOD(put_rgbRightBottom)(OLE_COLOR newVal);
	STDMETHOD(get_rgbLeftTop)(OLE_COLOR* pVal);
	STDMETHOD(put_rgbLeftTop)(OLE_COLOR newVal);
	STDMETHOD(get_URL)(BSTR* pVal);
	STDMETHOD(put_URL)(BSTR newVal);

	STDMETHOD(Observe)(BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj);
	STDMETHOD(ObserveEx)(int nRow, int nCol, BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj);
	STDMETHOD(ActiveTabPage)(IXobj* pXobj);
	STDMETHOD(GetXobj)(long nRow, long nCol,IXobj** ppXobj);
	STDMETHOD(GetXobjs)(BSTR bstrName, IXobj** ppXobj, IXobjCollection** ppXobjs, long* pCount);
	STDMETHOD(GetCtrlByName)(BSTR bstrName, VARIANT_BOOL bFindInChild, IDispatch** ppRetDisp);
	STDMETHOD(GetCtrlValueByName)(BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR* bstrVal);
	STDMETHOD(SetCtrlValueByName)(BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR bstrVal);
	STDMETHOD(LoadXML)(int nType, BSTR bstrXML);
	STDMETHOD(Show)();
	STDMETHOD(GetXobjByName)(BSTR bstrName, IXobjCollection** pVal);
	STDMETHOD(GetChildXobjByName)(BSTR bstrName, IXobj** pVal);
	STDMETHOD(NavigateURL)(BSTR bstrURL, IDispatch* dispObjforScript);

	STDMETHOD(SendIPCMessage)(BSTR bstrTo, BSTR bstrPayload, BSTR bstrExtra, BSTR bstrMsgId, BSTR* bstrRet);
	STDMETHOD(GetUIScript)(BSTR bstrCtrlName, BSTR* bstrVal);

	BEGIN_COM_MAP(CXobj)
		COM_INTERFACE_ENTRY(IXobj)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CXobj)
		CONNECTION_POINT_ENTRY(__uuidof(_IXobjEvents))
	END_CONNECTION_POINT_MAP()

	HWND CreateView(HWND hParentWnd, CString strTag);

private:
	CString _GetNames(CXobj* pXobj);
	void _get_Objects(CXobj* pXobj, UINT32& nType, CXobjCollection* pXobjColletion);
	int _getNodes(CXobj* pXobj, CString& strName, CXobj**ppRetXobj, CXobjCollection* pXobjs);
};

// CXobjCollection

class ATL_NO_VTABLE CXobjCollection :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IXobjCollection, &IID_IXobjCollection, &LIBID_Universe, 1, 0>
{
public:
	CXobjCollection();
	~CXobjCollection();

	BEGIN_COM_MAP(CXobjCollection)
		COM_INTERFACE_ENTRY(IXobjCollection)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	STDMETHOD(get_XobjCount)(long* pCount);
	STDMETHOD(get_Item)(long iIndex, IXobj ** ppXobj);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	CXobjVector*	m_pXobjs;

private:
	CXobjVector	m_vXobjs;
};
