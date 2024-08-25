/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202112150001           *
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
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

 // XobjHelper.cpp : implementation file
 //

#include "stdafx.h"
#include "Xobj.h"
#include "WinNucleus.h"
#include "GridWnd.h"
#include "Wormhole.h"
#include "XobjWnd.h"
#include "UniverseApp.h"
#include "TangramHtmlTreeWnd.h"

#include "chromium/WebPage.h"

// CXobjWnd

IMPLEMENT_DYNCREATE(CXobjWnd, CWnd)

CXobjWnd::CXobjWnd()
{
	m_hFormWnd = NULL;
	m_bNoMove = false;
	m_bBKWnd = false;
	m_bCreateExternal = false;
	m_bEraseBkgnd = true;
	m_pXobj = nullptr;
	m_pXHtmlTree = nullptr;
	m_pParentXobj = nullptr;
	m_pOleInPlaceActiveObject = nullptr;
	m_strKey = m_strXml = _T("");
}

CXobjWnd::~CXobjWnd()
{
}

BEGIN_MESSAGE_MAP(CXobjWnd, CWnd)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEACTIVATE()
	ON_WM_WINDOWPOSCHANGED()
	ON_MESSAGE(WM_TABCHANGE, OnTabChange)
	ON_MESSAGE(WM_COSMOSMSG, OnWebRTMsg)
	ON_MESSAGE(WM_HUBBLE_GETNODE, OnGetWebRTObj)
	ON_MESSAGE(WM_TGM_SETACTIVEPAGE, OnActiveTangramObj)

	ON_MESSAGE(WM_SPLITTERREPOSITION, OnSplitterReposition)
	ON_MESSAGE(WM_DPICHANGED_AFTERPARENT, OnAfterDPIChanged)
	//ON_MESSAGE(WM_DPICHANGED_AFTERPARENT, OnAfterDPIChanged)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

// CXobjWnd diagnostics

#ifdef _DEBUG
void CXobjWnd::AssertValid() const
{
	///CView::AssertValid();
}

#ifndef _WIN32_WCE
void CXobjWnd::Dump(CDumpContext& dc) const
{
	CWnd::Dump(dc);
}
#endif
#endif //_DEBUG

//CXobjWnd message handlers
BOOL CXobjWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_pXobj = g_pSpaceTelescope->m_pActiveXobj;
	m_pXobj->m_nID = nID;
	m_pXobj->m_pHostWnd = this;
	if (m_pXobj->m_strID.CompareNoCase(TGM_NUCLEUS) == 0)
	{
		CNucleus* pGalaxy = m_pXobj->m_pXobjShareData->m_pNucleus;
		g_pSpaceTelescope->ModifyBindingXobj(pGalaxy, m_pXobj);

		m_pXobj->m_pXobjShareData->m_pHostClientView = this;
		CNuclei* pNuclei = pGalaxy->m_pNuclei;
		HWND hWnd = CreateWindow(L"Cosmos Xobj Class", NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, pParentWnd->m_hWnd, (HMENU)nID, AfxGetInstanceHandle(), NULL);
		BOOL bRet = SubclassWindow(hWnd);
		HWND hTopParent = ::GetWindow(hWnd, GA_ROOT);
		CCloudMDIFrame* pMDIParent = nullptr;
		auto it = g_pSpaceTelescope->m_mapMDIParent.find(hTopParent);
		if (it != g_pSpaceTelescope->m_mapMDIParent.end())
		{
			pMDIParent = it->second;
			//if (m_pXobj->m_pXobjShareData->m_pNucleus == it->second->m_pNucleus &&
			//	!::IsChild(it->second->m_hMDIClient, hWnd))
			//{
			//	it->second->m_vMdiClientXobjs.push_back(m_pXobj);
			//}
		}
		if (m_pXobj->m_pParentObj)
		{
			if (m_pXobj->m_pParentObj->m_nViewType == Grid)
			{
				::PostMessage(::GetParent(m_hWnd), WM_HOSTNODEFORSPLITTERCREATED, m_pXobj->m_nRow, m_pXobj->m_nCol);
				ModifyStyleEx(WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE, 0);
			}
			else if (pMDIParent && pGalaxy->m_nGalaxyType == GalaxyType::MDIClientGalaxy && pGalaxy->m_pBindingXobj)
			{
				RECT rc = { 0,0,0,0 };
				if (g_pSpaceTelescope->m_pUniverseAppProxy && g_pSpaceTelescope->m_pUniverseAppProxy->m_pMDIClientAreaWnd)
				{
					rc = g_pSpaceTelescope->m_pUniverseAppProxy->GetClientAreaBounds();
					::SetWindowPos(pGalaxy->m_pWorkXobj->m_pHostWnd->m_hWnd, m_hWnd, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top,  /*SWP_NOSENDCHANGING| SWP_NOZORDER |*/ SWP_NOACTIVATE | SWP_FRAMECHANGED);
				}
			}
		}
		m_pXobj->NodeCreated();
		return bRet;
	}
	return m_pXobj->Create(dwStyle, rect, pParentWnd, nID, pContext);
}

LRESULT CXobjWnd::OnSplitterReposition(WPARAM wParam, LPARAM lParam)
{
	switch (m_pXobj->m_nViewType)
	{
	case CLRCtrl:
	case ActiveX:
	case TabGrid:
		m_pXobj->m_pXobjShareData->m_pNucleus->HostPosChanged();
		break;
		break;
	default:
		break;
	}

	return CWnd::DefWindowProc(WM_SPLITTERREPOSITION, wParam, lParam);
}

//LRESULT CXobjWnd::OnAfterDPIChanged(WPARAM wParam, LPARAM lParam)
//{
//	if (m_pXobj->m_pWebBrowser)
//	{
//		RECT rc;
//		::GetClientRect(m_hWnd, &rc);
//		if (m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebRTFrameWndInfo)
//		{
//			int nFrameType = m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebRTFrameWndInfo->m_nFrameType;
//			switch (nFrameType)
//			{
//			case 1:
//				break;
//			case 2:
//			{
//				CCloudMDIFrame* pMDIParent = m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent;
//				if (m_pXobj->m_pWebBrowser == pMDIParent->m_pHostBrowser)
//				{
//					//if (m_pXobj->m_pWebBrowser->m_pParentXobj == nullptr)
//					//	return 0;
//				}
//			}
//			break;
//			}
//		}
//
//		//if (m_pXobj->m_pWebBrowser->m_pVisibleWebView && m_pXobj->m_pWebBrowser->m_pVisibleWebView->m_bCanShow == false)
//		//	return;
//		if (::IsChild(m_hWnd, m_pXobj->m_pWebBrowser->m_hWnd) == false)
//		{
//			::SetParent(m_pXobj->m_pWebBrowser->m_hWnd, m_hWnd);
//		}
//
//		::SetWindowPos(m_pXobj->m_pWebBrowser->m_hWnd, HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOREDRAW);
//		m_pXobj->m_pWebBrowser->m_pBrowser->LayoutBrowser();
//		m_pXobj->m_pWebBrowser->BrowserLayout();
//	}
//
//	return CWnd::DefWindowProc(WM_SPLITTERREPOSITION, wParam, lParam);
//}

LRESULT CXobjWnd::OnAfterDPIChanged(WPARAM wParam, LPARAM lParam)
{
	if (m_pXobj->m_pWebBrowser)
	{
		g_pSpaceTelescope->m_mapDpiChangedBrowser[m_pXobj->m_pWebBrowser->m_hWnd] = m_pXobj->m_pWebBrowser;
	}

	return CWnd::DefWindowProc(WM_DPICHANGED_AFTERPARENT, wParam, lParam);
}

int CXobjWnd::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (g_pSpaceTelescope->m_pActiveHtmlWnd)
	{
		::PostMessage(g_pSpaceTelescope->m_pActiveHtmlWnd->m_hWnd, WM_COSMOSMSG, 20190331, 0);
		g_pSpaceTelescope->m_pActiveHtmlWnd = nullptr;
	}
	//HWND hWnd = m_pXobj->m_pXobjShareData->m_pNucleus->m_pNuclei->m_hWnd;
	//if (((::GetWindowLong(hWnd, GWL_EXSTYLE) & WS_EX_MDICHILD)) || ::GetParent(hWnd) == NULL)
	//	::BringWindowToTop(hWnd);

	CNucleus* pGalaxy = m_pXobj->m_pRootObj->m_pXobjShareData->m_pNucleus;
	if (pGalaxy->m_pNuclei->m_pUniverseAppProxy)
	{
		HWND hMenuWnd = pGalaxy->m_pNuclei->m_pUniverseAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
	else if (g_pSpaceTelescope->m_pActiveAppProxy)
	{
		HWND hMenuWnd = g_pSpaceTelescope->m_pActiveAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
	if (m_pXobj && m_pXobj->m_pXobjShareData->m_pNuclei)
		m_pXobj->m_pXobjShareData->m_pNuclei->Fire_NodeMouseActivate(m_pXobj);

	if ((m_pXobj->m_nViewType == TabGrid || m_pXobj->m_nViewType == Grid))
	{
		if (g_pSpaceTelescope->m_pNucleus != m_pXobj->m_pXobjShareData->m_pNucleus)
			::SetFocus(m_hWnd);
		g_pSpaceTelescope->m_pActiveXobj = m_pXobj;
		g_pSpaceTelescope->m_bWinFormActived = false;
		return MA_ACTIVATE;
	}

	if (!m_bCreateExternal)
		Invalidate(true);
	else
	{
		if ((m_pXobj->m_nViewType != TabGrid && m_pXobj->m_nViewType != Grid))
		{
			if (g_pSpaceTelescope->m_pNucleus != m_pXobj->m_pXobjShareData->m_pNucleus || g_pSpaceTelescope->m_pActiveXobj != m_pXobj)
				::SetFocus(m_hWnd);
		}
	}
	g_pSpaceTelescope->m_pActiveXobj = m_pXobj;
	g_pSpaceTelescope->m_bWinFormActived = false;
	g_pSpaceTelescope->m_pNucleus = m_pXobj->m_pXobjShareData->m_pNucleus;

	CWebView* pHtmlWnd = g_pSpaceTelescope->m_pNucleus->m_pWebViewWnd;
	CString strID = m_pXobj->m_strName;

	if ((m_pXobj->m_nViewType == ActiveX || m_pXobj->m_nViewType == CLRCtrl))
	{
		if (pHtmlWnd)
		{
			CWormhole* pSession = m_pXobj->m_pWormhole;
			if (pSession)
			{
				pSession->InsertString(_T("msgID"), IPC_NODE_ONMOUSEACTIVATE_ID);
				pHtmlWnd->m_pChromeRenderFrameHost->SendCosmosMessage(pSession->m_pSession);
			}
		}
		//return CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
		return MA_ACTIVATE;// MA_NOACTIVATE;
	}

	if (m_bCreateExternal == false)
	{
		if (pHtmlWnd)
		{
			IPCMsg pIPCInfo;
			pIPCInfo.m_strId = IPC_NODE_ONMOUSEACTIVATE_ID;
			pIPCInfo.m_strParam1 = strID;
			CString strHandle = _T("");
			strHandle.Format(_T("%I64d"), (__int64)m_hWnd);
			pIPCInfo.m_strParam2 = strHandle;
			strHandle.Format(_T("%d"), m_pXobj->m_nViewType);
			pIPCInfo.m_strParam3 = strHandle;
			strHandle.Format(_T("%I64d"), (__int64)pGalaxy->m_hWnd);
			pIPCInfo.m_strParam4 = strHandle;
			//strHandle.Format(_T("%d"), m_pRootObj->m_pHostWnd->m_hWnd);
			pIPCInfo.m_strParam5 = _T("wndnode");
			pHtmlWnd->m_pChromeRenderFrameHost->SendCosmosMessage(&pIPCInfo);
		}
		return MA_ACTIVATEANDEAT;
	}
	else
		return CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

BOOL CXobjWnd::OnEraseBkgnd(CDC* pDC)
{
	if (m_pXobj->m_nViewType != BlankView)
		return true;
	CBitmap bit;
	RECT rt;
	GetClientRect(&rt);
	CBrush br(RGB(255,255,255));
	pDC->FillRect(&rt, &br);
	CNucleus* pGalaxy = m_pXobj->m_pXobjShareData->m_pNucleus;
	if (m_pXobj->m_strID.CompareNoCase(TGM_NUCLEUS) == 0)
	{
		return true;
		HWND hWnd = pGalaxy->m_hWnd;
		if (::IsWindow(hWnd) && !::IsWindowVisible(hWnd))
		{
			//pGalaxy->HostPosChanged();
			return false;
		}
	}

	if (m_pXobj->m_strID.CompareNoCase(TGM_NUCLEUS) && (m_bCreateExternal == false && m_pXobj->m_pDisp == NULL) && m_bEraseBkgnd)
	{
		CString strText = _T("");
		CComBSTR bstrCaption(L"");
		m_pXobj->get_Attribute(CComBSTR(L"caption"), &bstrCaption);
		CString strInfo = _T("\n\n  ");
		CString str = _T("");
		strText.Format(strInfo, m_pXobj->m_strName, CString(OLE2T(bstrCaption)));
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkMode(TRANSPARENT);
		pDC->DrawText(strText, &rt, DT_LEFT);
	}
	return true;
}

BOOL CXobjWnd::PreTranslateMessage(MSG* pMsg)
{
	if (m_pXHtmlTree)
	{
		return m_pXHtmlTree->PreTranslateMessage(pMsg);
	}

	if (m_pOleInPlaceActiveObject)
	{
		LRESULT hr = m_pOleInPlaceActiveObject->TranslateAccelerator((LPMSG)pMsg);
		if (hr == S_OK)
			return true;
		else
		{
			if (m_pXobj->m_nViewType == CLRCtrl)
			{
				VARIANT_BOOL bShiftKey = false;
				if (::GetKeyState(VK_SHIFT) < 0)  // shift pressed
					bShiftKey = true;
				hr = g_pSpaceTelescope->m_pCLRProxy->ProcessCtrlMsg(::GetWindow(m_hWnd, GW_CHILD), bShiftKey ? true : false);
				if (hr == S_OK)
					return true;
				return false;
			}
			else
			{
				pMsg->hwnd = 0;
				return true;
			}
		}
	}
	else
	{
		if (m_pXobj->m_nViewType == CLRCtrl)
		{
			if (g_pSpaceTelescope->m_pCLRProxy->ProcessFormMsg(m_hWnd, pMsg, 0))
				return true;
			return false;
		}
	}
	if (IsDialogMessage(pMsg))
		return true;
	return CWnd::PreTranslateMessage(pMsg);
}

void CXobjWnd::OnDestroy()
{
	m_pXobj->Fire_Destroy();
	HANDLE hData = RemoveProp(m_hWnd, _T("WebRTInfo"));
	if (hData)
	{
		WebRTInfo* pInfo = (WebRTInfo*)hData;
		delete pInfo;
	}
	if (g_pSpaceTelescope->m_pClrCoreHost && m_pXobj->m_nViewType == CLRCtrl) {
		IUnknown* pUnk = m_pXobj->m_pUnk.p;
		if (pUnk)
		{
			ATL::CComPolyObject<ATL::CAxHostWindow>* pWnd = (ATL::CComPolyObject<ATL::CAxHostWindow>*)(void*)pUnk;
			//pWnd->m_contained.m_spOleObject->Unadvise(pWnd->m_contained.m_dwOleObject);
			pWnd->m_contained.m_spOleObject->Close(OLECLOSE_NOSAVE);
			//pWnd->m_contained.m_spOleObject->SetClientSite(NULL);
			pWnd->m_contained.m_spOleObject.Detach();
			m_pXobj->m_pUnk.Detach();
			TRACE(L"Release CLR Obj : %x\n", pWnd->m_contained.m_hWnd);
		}
	}
	CWnd::OnDestroy();
}

void CXobjWnd::PostNcDestroy()
{
	delete m_pXobj;
	CWnd::PostNcDestroy();
	delete this;
}

LRESULT CXobjWnd::OnTabChange(WPARAM wParam, LPARAM lParam)
{
	if (wParam == lParam)
		return 0;// CWnd::DefWindowProc(WM_TABCHANGE, wParam, lParam);
	int nOldPage = m_pXobj->m_nActivePage;
	m_pXobj->m_nActivePage = (int)wParam;
	IXobj* pXobj = nullptr;
	m_pXobj->GetXobj(0, wParam, &pXobj);

	CNucleus* pGalaxy = m_pXobj->m_pXobjShareData->m_pNucleus;
	if (pGalaxy->m_nGalaxyType != GalaxyType::CtrlBarGalaxy)
		::PostMessage(pGalaxy->m_hWnd, WM_COSMOSMSG, 0, 20180115);
	if (pXobj)
	{
		CXobj* _pXobj = (CXobj*)pXobj;
		CString str = _T("");
		str.Format(_T("%I64d"), wParam);
		m_pXobj->put_Attribute(CComBSTR(L"activepage"), str.AllocSysString());
		if (_pXobj->m_nViewType == Grid)
		{
			((CSplitterWnd*)_pXobj->m_pHostWnd)->RecalcLayout();
		}
		else
		{
			if (pGalaxy->m_nGalaxyType != GalaxyType::CtrlBarGalaxy)
				pGalaxy->HostPosChanged();
		}
		if (_pXobj->m_pWebBrowser) {
			g_pSpaceTelescope->m_pActiveHtmlWnd = _pXobj->m_pWebBrowser->m_pVisibleWebView;
		}
		if (lParam != wParam)
		{
			::PostMessage(pGalaxy->m_hWnd, WM_HUBBLE_ACTIVEPAGE, wParam, lParam);
			::SendMessage(_pXobj->m_pHostWnd->m_hWnd, WM_HUBBLE_ACTIVEPAGE, wParam, lParam);
		}
		if (m_pXobj->m_nViewType == TabGrid)
		{
			for (auto& it : m_pXobj->m_vChildNodes)
			{
				CXobj* pXobj = it;
				if (pXobj->m_nCol != m_pXobj->m_nActivePage)
				{
					pXobj->m_pHostWnd->ShowWindow(SW_HIDE);
				}
			}
		}
		HWND h = ::GetParent(m_hWnd);
		if (h)
		{
			LRESULT lRes = ::SendMessage(h, WM_HUBBLE_GETNODE, 0, 0);
			if (lRes)
			{
				CXobj* pRetNode = (CXobj*)lRes;
				if (pRetNode && pRetNode->m_nViewType == Grid)
				{
					pRetNode->m_pXobjShareData->m_pNucleus->HostPosChanged();
				}
			}
		}
	}
	if (lParam != wParam)
	{
		CCloudMDIFrame* pMainParent = nullptr;
		CXobj* pMDIClientObj = m_pXobj->GetVisibleChildByName(_T("hostclient"));
		WebRTFrameWndInfo* pInfo = m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebRTFrameWndInfo;
		if (pInfo)
		{
			switch (pInfo->m_nFrameType)
			{
			case 2:
			{
				pMainParent = m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent;
				auto it = g_pSpaceTelescope->m_mapMDIParent.find(::GetParent(pInfo->m_hClient));
				if (it != g_pSpaceTelescope->m_mapMDIParent.end())
				{
					pMainParent = it->second;
					if (pMainParent->m_bCreateNewDoc)
						return CWnd::DefWindowProc(WM_TABCHANGE, wParam, lParam);
					if (pMDIClientObj == nullptr) {
						if (m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebViewWnd) {
							CXobj* pObj = m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebViewWnd->m_pNucleus->m_pWorkXobj;
							pMDIClientObj = pObj->GetVisibleChildByName(_T("hostclient"));
						}
					}
					if (pMDIClientObj)
					{
						g_pSpaceTelescope->ModifyBindingXobj(pMainParent->m_pMDINucleus, pMDIClientObj);
					}
				}
			}
			break;
			case 1:
				break;
			}
		}
		if (pMDIClientObj)
		{
			CNucleus* pNucleus = nullptr;
			if (pGalaxy->m_pParentMDIWinForm && pGalaxy->m_pParentMDIWinForm->m_pClientGalaxy && ::IsChild(pGalaxy->m_pParentMDIWinForm->m_hWnd, pMDIClientObj->m_pHostWnd->m_hWnd))
			{
				pNucleus = pGalaxy->m_pParentMDIWinForm->m_pClientGalaxy;
			}
			else
			{
				if (pMDIClientObj->m_pParentWinFormWnd && pMDIClientObj->m_pParentWinFormWnd->m_bMdiForm)
				{
					pNucleus = pMDIClientObj->m_pParentWinFormWnd->m_pClientGalaxy;
				}
				else
				{
					pNucleus = m_pXobj->m_pRootObj->m_pXobjShareData->m_pNucleus;
				}
			}
			if (pNucleus) {
				g_pSpaceTelescope->ModifyBindingXobj(pNucleus, pMDIClientObj);
				::PostMessage(m_pXobj->m_pXobjShareData->m_pNucleus->m_hWnd, WM_COSMOSMSG, 0, 20180115);
			}
		}
		if (pGalaxy->m_nGalaxyType != GalaxyType::CtrlBarGalaxy && pGalaxy->m_pWebViewWnd)
		{
			HWND hWnd = ::GetParent(pGalaxy->m_pWebViewWnd->m_hWnd);
			if (pMainParent == nullptr || pMainParent->m_bCreateNewDoc == false)
			{
				auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hWnd);
				if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
				{
					CBrowser* pBrowser = (CBrowser*)it->second;
					pBrowser->m_bSZMode = true;
					if (pBrowser->m_pParentXobj && pBrowser->m_pParentXobj->m_pParentWinFormWnd)
					{
						pGalaxy->m_pParentWinForm = pBrowser->m_pParentXobj->m_pParentWinFormWnd;
						if (pGalaxy->m_pParentWinForm->m_bMdiForm)
							pGalaxy->m_pParentMDIWinForm = pGalaxy->m_pParentWinForm;
						HWND hClient = pGalaxy->m_pParentWinForm->m_hMDIClient;
						CNucleus* pClientGalaxy = (CNucleus*)g_pSpaceTelescope->GetNucleus(pGalaxy->m_pParentWinForm->m_hMDIClient);
						if (pClientGalaxy)
						{
							pGalaxy->m_pParentMDIWinForm->m_pClientGalaxy = pClientGalaxy;
						}
					}
					g_pSpaceTelescope->m_mapSizingBrowser[hWnd] = pBrowser;
					::SendMessage(hWnd, WM_BROWSERLAYOUT, 1, 7);
					pBrowser->m_pBrowser->LayoutBrowser();
					if (pBrowser->m_pParentXobj && ::IsWindowVisible(pBrowser->m_pParentXobj->m_pHostWnd->m_hWnd))
					{
						::PostMessage(pBrowser->m_hWnd, WM_COSMOSMSG, 20211020, 0);
					}
				}
			}
			if (pGalaxy->m_pParentMDIWinForm)
			{
				HWND hClient = pGalaxy->m_pParentMDIWinForm->m_hMDIClient;
				::PostMessage(hClient, WM_COSMOSMSG, 3, 20180115);
			}
			else
			{
				::PostMessage(m_hWnd, WM_COSMOSMSG, 0, 20210202);
			}
		}
		if (!m_pXobj->m_pXobjShareData->m_pNucleus->m_pParentMDIWinForm)
			m_pXobj->m_pXobjShareData->m_pNucleus->ModifyStyle(WS_CLIPCHILDREN, 0);
		m_pXobj->Fire_TabChange(wParam, lParam);
		m_pXobj->m_pXobjShareData->m_pNuclei->Fire_TabChange(m_pXobj, wParam, lParam);
	}
	LRESULT lRes = CWnd::DefWindowProc(WM_TABCHANGE, wParam, lParam);
	HWND hTop = ::GetAncestor(m_hWnd, GA_ROOT);
	::RedrawWindow(hTop, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN /*| RDW_UPDATENOW*/);
	return lRes;
}

LRESULT CXobjWnd::OnWebRTMsg(WPARAM wParam, LPARAM lParam)
{
	if (wParam && lParam == 20201028)
	{
		CBrowser* pWnd = (CBrowser*)wParam;
		if (pWnd->m_pParentXobj != m_pXobj)
			return CWnd::DefWindowProc(WM_COSMOSMSG, wParam, lParam);
		pWnd->m_pParentXobj = m_pXobj;
		::PostMessage(m_hWnd, WM_COSMOSMSG, 0, 20210202);
		return CWnd::DefWindowProc(WM_COSMOSMSG, wParam, lParam);
	}
	if (wParam == 0 && lParam)//Create CLRCtrl Node
	{
		switch (lParam)
		{
		case 20210315:
		{
			if (m_pXobj->m_pWebBrowser)
			{
				RECT rc;
				::GetClientRect(m_hWnd, &rc);
				if (!::IsChild(m_hWnd, m_pXobj->m_pWebBrowser->m_hWnd))
					::SetParent(m_pXobj->m_pWebBrowser->m_hWnd, m_hWnd);
				::SetWindowPos(m_pXobj->m_pWebBrowser->m_hWnd, HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
			}
		}
		break;
		case 20210316:
		{
			if (m_pXobj->m_pWebBrowser)
			{
				CCloudMDIFrame* pParent = m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent;
				if (pParent && pParent->m_bProcessBrowserPos == false)
				{
					if (pParent->m_pActiveMDIChild == nullptr)
					{
						pParent->m_bProcessBrowserPos = true;
						RECT rc;
						::GetClientRect(m_hWnd, &rc);
						m_pXobj->m_pWebBrowser->m_bSZMode = true;
						::SetParent(m_pXobj->m_pWebBrowser->m_hWnd, m_hWnd);
						::SetWindowPos(m_pXobj->m_pWebBrowser->m_hWnd, HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_NOACTIVATE | SWP_NOREDRAW | SWP_SHOWWINDOW | SWP_NOSENDCHANGING);
					}
				}
			}
		}
		break;
		case 20210225:
		{
			m_pXobj->put_Attribute(CComBSTR("objid"), CComBSTR(TGM_NUCLEUS));
		}
		break;
		case 20210202:
		{
			if (m_pXobj->m_pWebBrowser && m_pXobj->m_pWebBrowser->m_pMDIParent)
			{
				m_pXobj->m_pWebBrowser->m_pVisibleWebView->m_bCanShow = true;
				::PostMessageW(m_pXobj->m_pWebBrowser->m_hWnd, WM_COSMOSMSG, 20210314, 1);
				int nPage = -1;
				m_pXobj->get_ActivePage(&nPage);
				IXobj* pObj = nullptr;
				m_pXobj->GetXobj(0, nPage, &pObj);
				if (pObj)
				{
					CXobj* _pObj = (CXobj*)pObj;
					if (_pObj->m_strID.CompareNoCase(TGM_NUCLEUS) == 0)
						m_pXobj->m_pXobjShareData->m_pNucleus->SetFocus();
					else
						_pObj->m_pHostWnd->SetFocus();
				}
				HWND hTop = ::GetAncestor(m_hWnd, GA_ROOT);
				::RedrawWindow(hTop, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_UPDATENOW/**/);
				m_pXobj->m_pXobjShareData->m_pNucleus->ModifyStyle(0, WS_CLIPCHILDREN);
				//if (m_pXobj->m_pWebBrowser->m_pMDIParent->m_bCreateNewDoc==false)
				::PostMessage(m_hWnd, WM_COSMOSMSG, 0, 20210316);
			}
			if (m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent || m_pXobj->m_pXobjShareData->m_pNucleus->m_pParentMDIWinForm)
			{
				::PostMessage(m_pXobj->m_pXobjShareData->m_pNucleus->m_hWnd, WM_COSMOSMSG, 0, 20210411);
			}
		}
		break;
		case 20190602:
		{
			CCloudWinForm* pWebRTWinFormWnd = (CCloudWinForm*)::SendMessage(m_hWnd, WM_HUBBLE_DATA, 0, 20190214);
			if (pWebRTWinFormWnd)
				return (LRESULT)pWebRTWinFormWnd->m_pChildFormsInfo;
			return 0;
		}
		case 20200128:
		{
			if (m_pXobj && m_pXobj->m_pWebBrowser)
			{
				::SetWindowPos(m_pXobj->m_pWebBrowser->m_hWnd, HWND_TOP, 0, 0, 0, 0, SWP_NOACTIVATE | SWP_NOREDRAW);
			}
		}
		break;
		case 20201028:
		case 19631222:
		case 20191031:
		case 20180115:
		case 19820911:
		default:
			break;
		}
	}
	return CWnd::DefWindowProc(WM_COSMOSMSG, wParam, lParam);
}

LRESULT CXobjWnd::OnActiveTangramObj(WPARAM wParam, LPARAM lParam)
{
	if (m_pXobj->m_nViewType == CLRCtrl)
		::SetWindowLong(m_hWnd, GWL_STYLE, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);

	m_pXobj->m_pXobjShareData->m_pNucleus->HostPosChanged();
	::InvalidateRect(::GetParent(m_hWnd), nullptr, true);
	return CWnd::DefWindowProc(WM_TGM_SETACTIVEPAGE, wParam, lParam);
}

LRESULT CXobjWnd::OnGetWebRTObj(WPARAM wParam, LPARAM lParam)
{
	if (m_pXobj)
	{
		HWND hBrowser = (HWND)lParam;
		if (::IsWindow(hBrowser))
		{
			auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
			if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
			{
				m_pXobj->m_pWebBrowser = (CBrowser*)it->second;
			}
		}
		return (LRESULT)m_pXobj;
	}
	return CWnd::DefWindowProc(WM_HUBBLE_GETNODE, wParam, lParam);;
}

LRESULT CXobjWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_bCreateExternal)
	{
		switch (message)
		{
		case WM_COMMAND:
		{
			//WNDPROC* lplpfn = GetSuperWndProcAddr();
			LRESULT res = CWnd::WindowProc(message, wParam, lParam);// CallWindowProc(*lplpfn, m_hWnd, message, wParam, lParam);
			HWND hWnd = (HWND)lParam;
			if (::IsWindow(hWnd) && m_pXobj)
			{
				//if (m_pXobj->m_nViewType == TabGrid)return res;
				::GetClassName(hWnd, g_pSpaceTelescope->m_szBuffer, MAX_PATH);
				CString strName = g_pSpaceTelescope->m_szBuffer;
				m_pXobj->Fire_ControlNotify(m_pXobj, HIWORD(wParam), LOWORD(wParam), lParam, CComBSTR(g_pSpaceTelescope->m_szBuffer));
				if (m_pXobj->m_bWebCommandMsg && m_pXobj->m_pWormhole)
				{
					HWND hCtrl = (HWND)lParam;
					CString strVal = _T("");
					if (strName == _T("Edit"))
					{
						CEdit edit;
						edit.Attach(hCtrl);
						edit.GetWindowText(strVal);
						edit.Detach();
					}
					else
					{
						::GetWindowText((HWND)lParam, g_pSpaceTelescope->m_szBuffer, MAX_PATH);
						strVal = g_pSpaceTelescope->m_szBuffer;
					}
					m_pXobj->m_pWormhole->InsertString(_T("msgID"), _T("WM_COMMAND"));
					m_pXobj->m_pWormhole->InsertString(_T("CtrlClass"), strName);
					m_pXobj->m_pWormhole->InsertString(_T("CtrlValue"), strVal);
					m_pXobj->m_pWormhole->InsertLong(_T("NotifyCode"), HIWORD(wParam));
					m_pXobj->m_pWormhole->InsertLong(_T("CtrlID"), LOWORD(wParam));
					m_pXobj->m_pWormhole->Insertint64(_T("CtrlHandle"), lParam);
					m_pXobj->m_pWormhole->SendMessage();
					m_pXobj->m_pWormhole->InsertString(_T("msgID"), _T(""));
				}
			}

			return res;
		}
		case WM_ACTIVATE:
		case WM_ERASEBKGND:
		case WM_SETFOCUS:
		case WM_CONTEXTMENU:
		case WM_LBUTTONDOWN:
		case WM_TGM_SETACTIVEPAGE:
		case WM_RBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		case WM_LBUTTONDBLCLK:
		{
			WNDPROC* lplpfn = GetSuperWndProcAddr();
			return CallWindowProc(*lplpfn, m_hWnd, message, wParam, lParam);
		}
		case WM_MOUSEACTIVATE:
		{
			break;
		}
		}
	}

	return CWnd::WindowProc(message, wParam, lParam);
}

CBKWnd::CBKWnd(void)
{
	m_pNucleus = nullptr;
	m_hChild = nullptr;
	m_pXobj = nullptr;
	m_strURL = _T("");
}

void CBKWnd::OnFinalMessage(HWND hWnd)
{
	CWindowImpl<CBKWnd, CWindow>::OnFinalMessage(hWnd);
	delete this;
}

LRESULT CBKWnd::OnMouseActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	if (m_pXobj)
	{
		g_pSpaceTelescope->m_pActiveXobj = m_pXobj;
		g_pSpaceTelescope->m_bWinFormActived = false;
	}
	return DefWindowProc(uMsg, wParam, lParam);
}

LRESULT CBKWnd::OnMdiClientCreated(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	if (m_hChild)
	{
		CNuclei* pNuclei = m_pXobj->m_pXobjShareData->m_pNuclei;
		INucleus* pGalaxy = nullptr;
		pNuclei->CreateNucleus(CComVariant(0), CComVariant((LONGLONG)m_hChild), CComBSTR(L"ClientFrame"), &pGalaxy);
		CString strXml = _T("");
		strXml.Format(_T("<mdiclient><nucleus><xobj name=\"mdiclient\" gridtype=\"activex\" objid=\"%s\" /></nucleus></mdiclient>"), m_strURL);
		IXobj* pXobj = nullptr;
		pGalaxy->Observe(CComBSTR(L"default"), strXml.AllocSysString(), &pXobj);
		m_pNucleus = (CNucleus*)pGalaxy;
		//g_pSpaceTelescope->m_mapBKFrame[m_hChild] = m_pNucleus;
	}
	return 1;
}

LRESULT CBKWnd::OnWindowPosChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	WINDOWPOS* lpwndpos = (WINDOWPOS*)lParam;
	if (lpwndpos->cx == 0 && lpwndpos->cy == 0)
	{
		RECT rc;
		::GetClientRect(::GetParent(m_hWnd), &rc);
		lpwndpos->cx = rc.right;
		lpwndpos->cy = rc.bottom;
	}
	if (::IsWindow(m_hChild))
	{
		//::SetWindowPos(m_hChild, HWND_BOTTOM, +2, +2, lpwndpos->cx - 4, lpwndpos->cy - 4, SWP_NOREDRAW | SWP_NOACTIVATE);
		::SetWindowPos(m_hChild, HWND_BOTTOM, 0, 0, lpwndpos->cx, lpwndpos->cy, SWP_NOREDRAW | SWP_NOACTIVATE);
	}
	lpwndpos->flags |= SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOREDRAW;
	lpwndpos->x -= 2;
	lpwndpos->y -= 2;
	//lpwndpos->cx -= 2;
	return DefWindowProc(uMsg, wParam, lParam);
}

void CXobjWnd::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CWnd::OnWindowPosChanged(lpwndpos);
	if (lpwndpos) {
		bool bNotCtrlBar = (m_pXobj->m_pXobjShareData->m_pNucleus->m_nGalaxyType != GalaxyType::CtrlBarGalaxy);
		if (m_pXobj->m_strID.CompareNoCase(TGM_NUCLEUS) == 0 || m_pXobj->m_strID.CompareNoCase(_T("hostclient")) == 0)
		{
			::ShowWindow(m_pXobj->m_pXobjShareData->m_pNucleus->m_hWnd, SW_SHOW);
			m_pXobj->m_pXobjShareData->m_pNucleus->HostPosChanged();
			return;
		}
		if (bNotCtrlBar)
		{
			CCloudMDIFrame* pMainWnd = m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent;
			if (pMainWnd)
			{
				CNucleus* pGalaxy = pMainWnd->m_pMDINucleus;
				if (pGalaxy && pGalaxy->m_pBindingXobj == m_pXobj)
				{
					pGalaxy->HostPosChanged();
					if (pMainWnd->m_pActiveMDIChild)
						::PostMessage(pMainWnd->m_hWnd, WM_QUERYAPPPROXY, 0, 19651965);
					return;
				}
			}
		}
		if (m_pXobj->m_strName == _T("hostclient") && m_pXobj->m_pXobjShareData->m_pNucleus->m_pBindingXobj == m_pXobj) {
			TRACE(L"\n");
			::ShowWindow(m_pXobj->m_pXobjShareData->m_pNucleus->m_hWnd, SW_SHOW);
			m_pXobj->m_pXobjShareData->m_pNucleus->HostPosChanged();
			return;
		}
		if (m_pXobj->m_pWebBrowser)
		{
			if (m_pXobj->m_pWebBrowser->m_pParentXobj != m_pXobj)
			{
				if (m_pXobj->m_pWebBrowser->m_pParentXobj == nullptr)
					m_pXobj->m_pWebBrowser->m_pParentXobj = m_pXobj;
				else
					m_pXobj->m_pWebBrowser = nullptr;
				return;
			}
			m_pXobj->m_pWebBrowser->m_pVisibleWebView->m_bCanShow = (theApp.m_bAppStarting == false);
			if (m_pXobj->m_pWebBrowser->m_pParentXobj == nullptr ||
				m_pXobj->m_pWebBrowser->m_pVisibleWebView == nullptr ||
				m_pXobj->m_pWebBrowser->m_pVisibleWebView->m_bCanShow == false)
			{
				if (m_pXobj->m_pWebBrowser->m_pParentXobj && m_pXobj->m_pWebBrowser->m_pVisibleWebView->m_bCanShow)
					::PostMessage(m_hWnd, WM_COSMOSMSG, 0, 20210316);
				return;
			}
			if (::IsChild(m_hWnd, m_pXobj->m_pWebBrowser->m_hWnd) == false)
			{
				m_pXobj->m_pWebBrowser->m_bSZMode = true;
				::SetParent(m_pXobj->m_pWebBrowser->m_hWnd, m_hWnd);
			}
			if (lpwndpos->cx && lpwndpos->cy)
			{
				if (!g_pSpaceTelescope->m_bIsProcessCmdforNewOrOpen) {
					if (g_pSpaceTelescope->m_nWaitTabCounts)
					{
						::SetWindowPos(m_pXobj->m_pWebBrowser->m_hWnd, HWND_TOP, 0, 0, 0, 0, SWP_NOACTIVATE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
					}
					else
					{
						::SetWindowPos(m_pXobj->m_pWebBrowser->m_hWnd, HWND_TOP, -12, -6, lpwndpos->cx + 24, lpwndpos->cy + 18, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOREDRAW | SWP_NOSENDCHANGING);
					}
				}
			}
			return;
		}
		if (m_pXobj && m_pXobj->m_nViewType == CLRCtrl && m_pXobj->m_hHostWnd)
		{
			if (m_bNoMove)
			{
				lpwndpos->flags |= SWP_NOMOVE;
				CXobjWnd* pXobjWnd = (CXobjWnd*)m_pXobj->m_pHostWnd;
				if (m_pXobj->m_pParentObj->m_nViewType == Grid)
				{
					CGridWnd* pWnd = (CGridWnd*)m_pXobj->m_pParentObj->m_pHostWnd;
					::PostMessage(pWnd->m_hWnd, WM_COSMOSMSG, 3, 1993);
				}
			}
		}
		if (m_pXobj && m_pXobj->m_hHostWnd)
		{
			if (m_pXobj->m_nViewType == CLRCtrl)
			{
				if (m_bNoMove)
				{
					m_bNoMove = false;
				}
				return;
			}
			else if (m_pXobj->m_nViewType == BlankView)
			{
				::SetWindowPos(m_pXobj->m_hHostWnd, HWND_BOTTOM, 0, 0, lpwndpos->cx, lpwndpos->cy, SWP_FRAMECHANGED | SWP_NOACTIVATE);
				//::InvalidateRect(m_hWnd, nullptr, true);
				if (m_pXobj->m_hChildHostWnd)
					::SetWindowPos(m_pXobj->m_hChildHostWnd, HWND_BOTTOM, 0, 0, lpwndpos->cx, lpwndpos->cy, SWP_NOACTIVATE | SWP_NOREDRAW);
			}
		}
		if (m_hFormWnd)
			::SetWindowPos(m_hFormWnd, HWND_TOP, 0, 0, lpwndpos->cx, lpwndpos->cy, SWP_NOACTIVATE | SWP_NOREDRAW);
		if (m_pXobj->m_strID.CompareNoCase(TGM_NUCLEUS) && (m_bCreateExternal == false && m_pXobj->m_pDisp == NULL) && m_pXobj != m_pXobj->m_pRootObj)
		{
			return;
		}
		if (m_pXobj->m_nViewType == TangramTreeView)
		{
			lpwndpos->flags &= ~SWP_NOREDRAW;
			::SetWindowPos(m_pXHtmlTree->m_hWnd, NULL, 0, 0, lpwndpos->cx, lpwndpos->cy, SWP_NOACTIVATE);
		}

		if (m_bCreateExternal)
		{
			Invalidate(true);
		}
	}
}

void CXobjWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	if (m_pXobj->m_nViewType == TangramTreeView && m_pXobj->m_pParentObj == NULL)
	{
		::SetWindowPos(m_pXHtmlTree->m_hWnd, NULL, 0, 0, cx, cy,/*SWP_NOREDRAW|*/SWP_NOACTIVATE);
	}
}

void CXobjWnd::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CWnd::OnShowWindow(bShow, nStatus);
	if (bShow)
	{
		if (m_pXobj->m_pWebBrowser)
		{
			RECT rc;
			::GetClientRect(m_hWnd, &rc);
			if (m_pXobj->m_pRootObj->m_bCreated == false)//||rc.right * rc.bottom == 0)
				return;
			if (m_pXobj->m_pWebBrowser->m_pParentXobj != m_pXobj)
				return;
			if (m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebRTFrameWndInfo)
			{
				int nFrameType = m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebRTFrameWndInfo->m_nFrameType;
				switch (nFrameType)
				{
				case 1:
					break;
				case 2:
				{
					CCloudMDIFrame* pMDIParent = m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent;
					if (m_pXobj->m_pWebBrowser == pMDIParent->m_pHostBrowser)
					{
						if (m_pXobj->m_pWebBrowser->m_pParentXobj == nullptr)
							return;
					}
				}
				break;
				}
			}

			//if (m_pXobj->m_pWebBrowser->m_pVisibleWebView && m_pXobj->m_pWebBrowser->m_pVisibleWebView->m_bCanShow == false)
			//	return;
			if (::IsChild(m_hWnd, m_pXobj->m_pWebBrowser->m_hWnd) == false)
			{
				::SetParent(m_pXobj->m_pWebBrowser->m_hWnd, m_hWnd);
			}

			::SetWindowPos(m_pXobj->m_pWebBrowser->m_hWnd, HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOREDRAW);
			HWND hWebView = m_pXobj->m_pWebBrowser->m_pVisibleWebView->m_hWnd;
			::GetClientRect(hWebView, &rc);
			if (rc.right * rc.left <= 4)
				::PostMessage(m_pXobj->m_pWebBrowser->m_hWnd, WM_BROWSERLAYOUT, 0, 7);
		}
	}
}
