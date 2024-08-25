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
#include "chromium/WebPage.h"

using namespace Browser;
class CBKWnd;
class CWormhole;

class CWebRTWnd : public CWnd
{
public:
	CWebRTWnd() {}
	virtual ~CWebRTWnd() {}
	HWND m_hClient = nullptr;
protected:
	void PostNcDestroy()
	{
		CWnd::PostNcDestroy();
		delete this;
	}
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};

// CWebRTTreeCtrl window
class CWebRTTreeCtrl : public CTreeCtrl
{
	// Construction
public:
	CWebRTTreeCtrl() noexcept;

	// Overrides
protected:

	// Implementation
public:
	virtual ~CWebRTTreeCtrl();
	HTREEITEM FillTreeView(CTangramXmlParse* pParse, CTangramXmlParse* pParseTag, HTREEITEM hParentItem);
	CXobj* m_pHostObj = nullptr;
	CNucleus* m_pNucleus = nullptr;
	map<HTREEITEM, CosmosUIItemData*> m_mapTreeItemData;
protected:
	afx_msg LRESULT OnXobjCreatedMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCloudMsgReceived(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMReturn(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMTVStateImageChanging(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnTvnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnTvnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnTvnItemChanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnTvnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
};

// CWebRTListCtrl window
class CWebRTListCtrl : public CListCtrl
{
	// Construction
public:
	CWebRTListCtrl() noexcept;

	// Overrides
protected:

	// Implementation
public:
	virtual ~CWebRTListCtrl();
	CXobj* m_pHostObj = nullptr;
	CNucleus* m_pNucleus = nullptr;
	map<LVITEM, CosmosUIItemData*> m_mapListItemData;
protected:
	afx_msg LRESULT OnCloudMsgReceived(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnXobjCreatedMsg(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnLvnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnLvnDeleteallitems(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnLvnInsertitem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnLvnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnLvnItemActivate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnLvnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnLvnLinkClicked(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMHover(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMKillfocus(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMRDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMReturn(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
};

// CWebRTTabCtrl window
class CWebRTTabCtrl : public CTabCtrl
{
	// Construction
public:
	CWebRTTabCtrl() noexcept;

	// Overrides
protected:

	// Implementation
public:
	virtual ~CWebRTTabCtrl();
	CXobj* m_pHostObj = nullptr;
	CNucleus* m_pNucleus = nullptr;
	map<TCITEM, CosmosUIItemData*> m_mapTabItemData;
protected:
	afx_msg LRESULT OnCloudMsgReceived(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnXobjCreatedMsg(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnTcnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnTcnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
};

class CWebRuntimeWnd :
	public CWindowImpl<CWebRuntimeWnd, CWindow>
{
public:
	CWebRuntimeWnd(void) { 
		m_bSZMode = false; 
		m_pHostBrowser = nullptr;
	};
	virtual ~CWebRuntimeWnd(void) {};
	BEGIN_MSG_MAP(CWebRuntimeWnd)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
		MESSAGE_HANDLER(WM_COSMOSMSG, OnWebRTMsg)
		MESSAGE_HANDLER(WM_EXITSIZEMOVE, OnExitSZ)
		MESSAGE_HANDLER(WM_ENTERSIZEMOVE, OnEnterSZ)
		MESSAGE_HANDLER(WM_DPICHANGED, OnDpiChanged)
		MESSAGE_HANDLER(WM_SYSCOMMAND, OnSysCommand)
	END_MSG_MAP()
private:
	bool	m_bSZMode = false;
	BOOL	m_bDpiChanged = false;
	CBrowser* m_pHostBrowser = nullptr;
	LRESULT OnExitSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnEnterSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnCommand(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTMsg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnSysCommand(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDpiChanged(UINT, WPARAM, LPARAM, BOOL&);
	void OnFinalMessage(HWND hWnd);
};

class CCloudMDIChild :
	public CWindowImpl<CCloudMDIChild, CWindow>
{
public:
	CCloudMDIChild(void);
	virtual ~CCloudMDIChild(void);

	BOOL							m_bFrameAttached = false;
	HWND							m_hMDIChildClient;

	CString							m_strKey;
	CString							m_strDocXml = _T("");
	CString							m_strDocTemplateKey = _T("");

	map<int, HWND>					m_mapView;
	CNucleus*						m_pMDIChildNucleus = nullptr;
	CCloudMDIFrame*					m_pParent = nullptr;
	BEGIN_MSG_MAP(CCloudMDIChild)
		MESSAGE_HANDLER(WM_COSMOSMSG, OnWebRTMg)
		MESSAGE_HANDLER(WM_MDIACTIVATE, OnMDIActivate)
		MESSAGE_HANDLER(WM_COSMOSOBSERVED, OnWebRTDocObserveed)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGED, OnWindowPosChanging)
	END_MSG_MAP()

private:
	void OnFinalMessage(HWND hWnd);
	LRESULT OnMDIActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTMg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTDocObserveed(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWindowPosChanging(UINT, WPARAM, LPARAM, BOOL&);
};

class CCloudMDTFrame :
	public CWindowImpl<CCloudMDTFrame, CWindow>
{
public:
	CCloudMDTFrame(void);
	virtual ~CCloudMDTFrame(void);
	BOOL			m_bCreateNewMDTDoc = false;
	BOOL			m_bFrameAttached = false;
	BOOL			m_bSZMode = false;
	BOOL			m_bDpiChanged = false;
	HWND			m_hMDTClient = NULL;
	CString			m_strDocTemplateKey = _T("");

	CBrowser*		m_pBrowser = nullptr;
	map<int, HWND>	m_mapView;
	map<int, HWND>	m_mapControlBar;

	BEGIN_MSG_MAP(CCloudMDTFrame)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
		MESSAGE_HANDLER(WM_COSMOSMSG, OnWebRTMsg)
		MESSAGE_HANDLER(WM_EXITSIZEMOVE, OnExitSZ)
		MESSAGE_HANDLER(WM_ENTERSIZEMOVE, OnEnterSZ)
		MESSAGE_HANDLER(WM_DPICHANGED, OnDpiChanged)
		MESSAGE_HANDLER(WM_SYSCOMMAND, OnSysCommand)
	END_MSG_MAP()
private:
	LRESULT OnClose(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnExitSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnEnterSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTMsg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnCommand(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnSysCommand(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDpiChanged(UINT, WPARAM, LPARAM, BOOL&);

	void OnFinalMessage(HWND hWnd);
};

class CCloudMDIFrame :
	public CWindowImpl<CCloudMDIFrame, CWindow>
{
public:
	CCloudMDIFrame(void);
	virtual ~CCloudMDIFrame(void);

	BOOL						m_bActiveChild = false;
	BOOL						m_bDestroy = false;
	BOOL						m_bFrameAttached = false;
	BOOL						m_bDpiChanged = false;
	BOOL						m_bCreateNewDoc = false;
	BOOL						m_bProcessBrowserPos = false;
	BOOL						m_bAdjustClient = false;
	HWND						m_hMDIClient = nullptr;
	CString						m_strKey;
	CString						m_strXml;
	CNucleus*					m_pMDINucleus = nullptr;
	CBrowser*					m_pHostBrowser = nullptr;
	CCloudMDIChild*				m_pActiveMDIChild = nullptr;
	WebRTFrameWndInfo*			m_pWebRTFrameWndInfo = nullptr;
	map<int, HWND>				m_mapControlBar;
	map<CString, CString>		m_mapClientCtrlBarData;
	map<CString, CString>		m_mapDocAppName;
	map<CString, CString>		m_mapDocTemplate;
	map<CString, CString>		m_mapDocDefaultName;
	map<HWND, CCloudMDIChild*>	m_mapMDIChild;

	BEGIN_MSG_MAP(CCloudMDIFrame)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
		MESSAGE_HANDLER(WM_COSMOSMSG, OnWebRTMsg)
		MESSAGE_HANDLER(WM_EXITSIZEMOVE, OnExitSZ)
		MESSAGE_HANDLER(WM_ENTERSIZEMOVE, OnEnterSZ)
		MESSAGE_HANDLER(WM_SYSCOMMAND, OnSysCommand)
		MESSAGE_HANDLER(WM_DPICHANGED, OnDpiChanged)
		MESSAGE_HANDLER(WM_QUERYAPPPROXY, OnQueryAppProxy)
	END_MSG_MAP()

	void OnFinalMessage(HWND hWnd);
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTMsg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnExitSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnEnterSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnSysCommand(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnQueryAppProxy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnActivate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDpiChanged(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};

class CCloudWinForm :
	public CWindowImpl<CCloudWinForm, CWindow>
{
public:
	CCloudWinForm(void);
	virtual ~CCloudWinForm(void);
	bool									m_bReady = false;
	bool									m_bSZMode = false;
	bool									m_bhostclient = false;
	bool									m_bDpiChanged = false;
	int										m_nState;
	HWND									m_hMDIClient = NULL;
	HWND									m_hOwnerWebView = NULL;
	HWND									m_hMDIChildBeingClosedOrMinimized = NULL;
	BOOL									m_bMdiForm;
	BOOL									m_bMainForm = false;
	CString									m_strKey;
	CString									m_strOldKey;
	CString									m_strXml;
	CString									m_strPath;
	CString									m_strBKID;
	CString									m_strChildFormPath;

	CBKWnd* m_pBKWnd;
	CXobj* m_pXobj = nullptr;
	CXobj* m_pBindMDIXobj = nullptr;
	CXobj* m_pWebBindMDIXobj = nullptr;
	CNucleus* m_pClientGalaxy = nullptr;
	CBrowser* m_pBrowser = nullptr;
	CWebView* m_pOwnerHtmlWnd;
	CWormhole* m_pWormhole;
	CCloudWinForm* m_pActiveChild = nullptr;
	CCloudWinForm* m_pMDIParent = nullptr;
	map<HWND, CCloudWinForm*>				m_mapMDIChild;
	CMDIChildFormInfo* m_pChildFormsInfo;
	void SendMessage();
	void OnShowAllChild();

	BEGIN_MSG_MAP(CCloudWinForm)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_HUBBLE_DATA, OnGetMe)
		MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
		MESSAGE_HANDLER(WM_COSMOSMSG, OnWebRTMsg)
		MESSAGE_HANDLER(WM_EXITSIZEMOVE, OnExitSZ)
		MESSAGE_HANDLER(WM_ENTERSIZEMOVE, OnEnterSZ)
		MESSAGE_HANDLER(WM_SYSCOMMAND, OnSysCommand)
		MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
		MESSAGE_HANDLER(WM_MDICHILDMIN, OnMdiChildMin)
		MESSAGE_HANDLER(WM_MDIACTIVATE, OnMDIActivate)
		MESSAGE_HANDLER(WM_HUBBLE_GETXML, OnWebRTGetXml)
		MESSAGE_HANDLER(WM_WINFORMCREATED, OnFormCreated)
		MESSAGE_HANDLER(WM_DPICHANGED, OnDpiChanged)
		MESSAGE_HANDLER(WM_MOUSEACTIVATE, OnMouseActivate)
		MESSAGE_HANDLER(WM_MDICLIENTCREATED, OnMdiClientCreated)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanging)
		MESSAGE_HANDLER(WM_DPICHANGED_BEFOREPARENT, OnBefoDPIChanged)
	END_MSG_MAP()

	void OnFinalMessage(HWND hWnd);

private:
	LRESULT OnClose(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnGetMe(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnFormCreated(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTMsg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTGetXml(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnMdiClientCreated(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWindowPosChanging(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnMDIActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnMouseActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnMdiChildMin(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnExitSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnEnterSZ(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnSysCommand(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnShowWindow(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDpiChanged(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnBefoDPIChanged(UINT, WPARAM, LPARAM, BOOL&);
};

class ATL_NO_VTABLE CNucleus :
	public CComObjectRootBase,
	public CWindowImpl<CNucleus, CWindow>,
	public IDispatchImpl<INucleus, &IID_INucleus, &LIBID_Universe, 1, 0>
{
public:
	CNucleus();
	virtual ~CNucleus();

	bool											m_bTabbedMDIClient;
	bool											m_bDetached;
	bool											m_bNoRedrawState = false;
	bool											m_bMDIChild;
	bool											m_bObserveState = false;
	bool											m_bNeedProcessFrame = false;
	BOOL											m_bWebCommandMsg = false;;
	GalaxyType										m_nGalaxyType;
	DWORD											m_dwHostProcessID;
	HWND											m_hHostWnd;
	CString											m_strLastKey;
	CString											m_strNucleusName;
	CString											m_strCurrentKey;
	CString											m_strCurrentXml;
	CString											m_strDocTemplateID = _T("");
	CString											m_strHostWebBrowserNodeName = _T("");

	IPCMsg* m_pCurrentIPCMsg;
	CBKWnd* m_pBKWnd = nullptr;
	CEclipseWnd* m_pWorkBenchFrame;
	CCloudWinForm* m_pParentWinForm = nullptr;
	CCloudWinForm* m_pParentMDIWinForm = nullptr;
	CCloudMDTFrame* m_pCloudMDTFrame = nullptr;
	CCloudMDIChild* m_pCloudMDIChild = nullptr;
	CCloudMDIFrame* m_pMDIParent = nullptr;
	CWebView* m_pWebViewWnd = nullptr;
	CXobj* m_pHostWebBrowserNode = nullptr;
	CBrowser* m_pHostWebBrowserWnd = nullptr;
	CNuclei* m_pNuclei = nullptr;
	CXobj* m_pWorkXobj = nullptr;
	CXobj* m_pParentXobj = nullptr;
	CXobj* m_pBindingXobj = nullptr;
	CXobj* m_pContainerNode = nullptr;
	NucleusInfo* m_pNucleusInfo = nullptr;
	WebRTFrameWndInfo* m_pWebRTFrameWndInfo = nullptr;
	CWormhole* m_pWormhole = nullptr;
	map<CString, CXobj*>							m_mapXobj;
	map<HWND, CWPFView*>							m_mapWPFView;
	map<HWND, CWPFView*>							m_mapVisibleWPFView;
	map<IUniverseAppProxy*, CNucleusProxy*>			m_mapGalaxyProxy;
	CComObject<CXobjCollection>* m_pRootNodes;

	void Lock() {}
	void Unlock() {}
	void Destroy();
	void HostPosChanged();
	HWND GetWinForm(HWND hWnd);
	void UpdateVisualWPFMap(HWND, BOOL);

	CTangramXmlParse* UpdateXobj();
	BOOL Create();
	CXobj* ObserveInternal(CTangramXmlParse* pParse, CString strKey);

	STDMETHOD(get_GalaxyXML)(BSTR* pVal);
	STDMETHOD(ModifyHost)(LONGLONG hHostWnd);
	STDMETHOD(Observe)(BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj);
	STDMETHOD(GetXml)(BSTR bstrRootName, BSTR* bstrRet);

	BEGIN_COM_MAP(CNucleus)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(INucleus)
	END_COM_MAP()

	BEGIN_MSG_MAP(CNucleus)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_COMMAND, OnCommand)
		MESSAGE_HANDLER(WM_HSCROLL, OnHScroll)
		MESSAGE_HANDLER(WM_VSCROLL, OnHScroll)
		MESSAGE_HANDLER(WM_HUBBLE_DATA, OnGetMe)
		MESSAGE_HANDLER(WM_NCDESTROY, OnNcDestroy)
		MESSAGE_HANDLER(WM_COSMOSMSG, OnWebRTMsg)
		MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
		MESSAGE_HANDLER(WM_PARENTNOTIFY, OnParentNotify)
		MESSAGE_HANDLER(WM_MOUSEACTIVATE, OnMouseActivate)
		MESSAGE_HANDLER(WM_QUERYAPPPROXY, OnQueryAppProxy)
		MESSAGE_HANDLER(WM_HUBBLE_ACTIVEPAGE, OnTabChanged)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanging)
	END_MSG_MAP()

protected:
	ULONG InternalAddRef() { return 1; }
	ULONG InternalRelease() { return 1; }

private:
	LRESULT OnGetMe(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnCommand(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnHScroll(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnNcDestroy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnTabChanged(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWebRTMsg(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnShowWindow(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnParentNotify(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnMouseActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnQueryAppProxy(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWindowPosChanging(UINT, WPARAM, LPARAM, BOOL&);

	STDMETHOD(get_Count)(long* pCount);
	STDMETHOD(get_Xobj)(VARIANT vIndex, IXobj** ppXobj);
	STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	STDMETHOD(get_HWND)(LONGLONG* pVal);
	STDMETHOD(get_Nuclei)(INuclei** pVal);
	STDMETHOD(get_CurrentNavigateKey)(BSTR* pVal);
	STDMETHOD(get_VisibleXobj)(IXobj** pVal);
	STDMETHOD(get_RootXobjs)(IXobjCollection** pXobjColletion);
	STDMETHOD(get_GalaxyType)(GalaxyType* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_HostBrowser)(IBrowser** ppChromeWebBrowser);
	STDMETHOD(get_HostWebPage)(IWebView** ppChromeWebPage);

	STDMETHOD(Attach)(void);
	STDMETHOD(Detach)(void);

	void OnFinalMessage(HWND hWnd);
};
