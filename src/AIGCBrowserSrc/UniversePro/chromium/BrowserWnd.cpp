/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001           *
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
#include "../stdafx.h"
#include "../cosmos.h"
#include "../UniverseApp.h"
#include "../Xobj.h"
#include "../XobjWnd.h"
#include "../WinNucleus.h"
#include "WebPage.h"
#include "BrowserWnd.h"

namespace Browser {
	CBrowser::CBrowser() {
		m_bTabChange = false;
		m_bHostBrowser = false;
		m_nTop = 0;
		m_nWidth = 0;
		m_nHeigh = 0;
		m_fdevice_scale_factor = 1.0f;
		m_hDrawWnd = 0;
		m_hOldTab = NULL;
		m_pBrowser = nullptr;
		m_pRemoteXobj = nullptr;
		m_pParentXobj = nullptr;
		m_pVisibleWebView = nullptr;
		m_pOmniboxViewViews = nullptr;
		m_strCurKey = _T("");
		if (g_pSpaceTelescope->m_pCreatingOmniboxViewViews) {
			m_pOmniboxViewViews = g_pSpaceTelescope->m_pCreatingOmniboxViewViews;
			g_pSpaceTelescope->m_pCreatingOmniboxViewViews = nullptr;
		}
	}

	CBrowser::~CBrowser() {
	}

	void CBrowser::BeforeActiveChromeTab(HWND hOldWnd)
	{
		m_bSZMode = true;
		m_hBeforeChange = hOldWnd;
		m_bTabChange = true;
		g_pSpaceTelescope->m_mapSizingBrowser[m_hWnd] = this;
		//if (::GetParent(m_hWnd))
		m_bInTabChange = true;
	}

	void CBrowser::EndActiveChromeTab(HWND hActive)
	{
		if (m_bDestroy == false)
		{
			auto it = g_pSpaceTelescope->m_mapWebView.find(hActive);
			if (it != g_pSpaceTelescope->m_mapWebView.end())
			{
				m_bInTabChange = true;
				((CWebView*)it->second)->m_bCanShow = false;
			}
			::PostMessage(m_hWnd, WM_COSMOSMSG, 20210314, (LPARAM)hActive);
		}
	}

	CString CBrowser::GetXobjAttr(CString attrName) {
		if (m_pParentXobj)
		{
			if (m_pParentXobj->m_pHostParse != nullptr)
			{
				return m_pParentXobj->m_pHostParse->attr(attrName, _T(""));
			}
		}
		return _T("");
	}

	void CBrowser::BrowserLayoutImpl()
	{
		HWND _hWebPage = m_pVisibleWebView->m_hWnd;
		if (m_pVisibleWebView->m_pDevToolWnd)
		{
			if (::GetParent(_hWebPage) == ::GetParent(m_pVisibleWebView->m_pDevToolWnd->m_hWnd))
			{
				_hWebPage = m_pVisibleWebView->m_pDevToolWnd->m_hWnd;
				::ShowWindow(_hWebPage, SW_SHOW);
			}
		}
		HWND hExtendWnd = m_pVisibleWebView->m_hExtendWnd;
		RECT rcExtendWnd;
		::GetClientRect(hExtendWnd, &rcExtendWnd);
		HRGN hWebExtendWndRgn = ::CreateRectRgn(rcExtendWnd.left, rcExtendWnd.top, rcExtendWnd.right, rcExtendWnd.bottom);
		if (m_bSZMode == false)
		{
			RECT rcWebPage;
			::GetWindowRect(_hWebPage, &rcWebPage);
			::ScreenToClient(hExtendWnd, (LPPOINT)&rcWebPage);
			::ScreenToClient(hExtendWnd, ((LPPOINT)&rcWebPage) + 1);
			HRGN hWebPage = NULL;
			hWebPage = ::CreateRectRgn(rcWebPage.left, rcWebPage.top, rcWebPage.right, rcWebPage.bottom);
			if (hWebPage)
			{
				::CombineRgn(hWebExtendWndRgn, hWebExtendWndRgn, hWebPage, RGN_DIFF);
				::DeleteObject(hWebPage);
			}
		}
		::SetWindowRgn(hExtendWnd, hWebExtendWndRgn, false);
	}

	void CBrowser::UpdateContentRect(HWND hWnd, RECT& rc, int nTopFix, float dwDeviceScaleFactor) {
		m_fdevice_scale_factor = dwDeviceScaleFactor;
		if (m_hBeforeChange && hWnd == m_hBeforeChange)
		{
			return;
		}
		else
		{
			m_hBeforeChange = nullptr;
			if (m_bInTabChange)
			{
				::PostMessageW(m_hWnd, WM_BROWSERLAYOUT, 0, 1000);
				m_bInTabChange = false;
				return;
			}
			m_bInTabChange = false;
		}
		if (m_bDestroy || m_bInTabChange || hWnd == 0 || g_pSpaceTelescope->m_bChromeNeedClosed == TRUE || g_pSpaceTelescope->m_bOMNIBOXPOPUPVISIBLE)
		{
			return;
		}

		auto it = g_pSpaceTelescope->m_mapWebView.find(hWnd);
		if (it != g_pSpaceTelescope->m_mapWebView.end())
		{
			m_pVisibleWebView = (CWebView*)it->second;
		}
		else
		{
			m_pVisibleWebView = new CComObject<CWebView>();
			m_pVisibleWebView->SubclassWindow(hWnd);
			g_pSpaceTelescope->m_mapWebView[hWnd] = m_pVisibleWebView;
		}

		if (::IsWindowVisible(hWnd) == false)
		{
			if (::IsWindowVisible(m_hWnd))
			{
				if (m_pBrowser->GetActiveWebContentWnd() == hWnd && m_pVisibleWebView->m_pChromeRenderFrameHost)
				{
					m_pVisibleWebView->m_pChromeRenderFrameHost->ShowWebPage(true);
					if (m_pVisibleWebView->m_hExtendWnd)
						::SetParent(m_pVisibleWebView->m_hExtendWnd, m_hWnd);
					::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 7);
					return;
				}
				else
					return;
			}
			else
				return;
		}

		if (m_hOldTab)
		{
			RECT rc2;
			::GetWindowRect(m_hOldTab, &rc2);
			ScreenToClient(&rc2);
			::SetWindowPos(m_hOldTab, HWND_BOTTOM, rc2.left, rc2.top, 1, 1, SWP_NOREDRAW | SWP_NOACTIVATE);
			m_hOldTab = NULL;
		}

		if (theApp.m_bAppStarting && m_pVisibleWebView->m_bCanShow == false &&
			m_pWebRTFrameWndInfo && m_pWebRTFrameWndInfo->m_nFrameType == 2 &&
			m_pVisibleWebView == m_pWebRTFrameWndInfo->m_pWebView)
		{
			return;
		}

		if (m_bTabChange == true)
		{
			::PostMessage(m_hWnd, WM_COSMOSMSG, 20200205, 1);
			return;
		}

		if (m_pVisibleWebView)
		{
			HWND hExtendWnd = m_pVisibleWebView->m_hExtendWnd;
			if (hExtendWnd == nullptr)
			{
				hExtendWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, m_hWnd, NULL, theApp.m_hInstance, NULL);
				m_pVisibleWebView->m_hExtendWnd = hExtendWnd;
				m_pVisibleWebView->m_hChildWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, hExtendWnd, (HMENU)2, theApp.m_hInstance, NULL);
				CExtendWnd* pExtendWnd = new CExtendWnd();
				pExtendWnd->m_pHostPage = m_pVisibleWebView;
				pExtendWnd->SubclassWindow(m_pVisibleWebView->m_hChildWnd);
				::SetWindowLongPtr(hExtendWnd, GWLP_USERDATA, (LONG_PTR)m_pVisibleWebView->m_hChildWnd);
				::SetWindowLongPtr(m_pVisibleWebView->m_hChildWnd, GWLP_USERDATA, (LONG_PTR)m_pVisibleWebView);
			}
			if (::IsChild(hWnd, hExtendWnd))
				::SetParent(hExtendWnd, m_hWnd);

			if (m_pVisibleWebView->m_strCurKey == _T(""))
			{
				::SetWindowPos(hExtendWnd, m_hDrawWnd ? m_hDrawWnd : HWND_BOTTOM,
					rc.left,
					nTopFix * m_fdevice_scale_factor,
					0,
					0,
					SWP_SHOWWINDOW | SWP_NOREDRAW | SWP_NOACTIVATE);
				return;
			}
			m_nTop = nTopFix * m_fdevice_scale_factor;
			m_nWidth = (rc.right - rc.left) * m_fdevice_scale_factor;
			m_nHeigh = (rc.bottom - rc.top) * m_fdevice_scale_factor;
			::SetWindowPos(hExtendWnd, m_hDrawWnd ? m_hDrawWnd : HWND_BOTTOM,
				rc.left,
				m_nTop,
				m_nWidth,
				m_nHeigh,
				SWP_SHOWWINDOW | SWP_NOREDRAW | SWP_NOACTIVATE);
			if (theApp.m_bAppStarting)
				return;
			HWND hWebHostWnd = m_pVisibleWebView->m_hWebHostWnd;
			CXobj* pHostXobj = nullptr;
			if (m_pVisibleWebView->m_pNucleus)
			{
				CXobj* pXobj = m_pVisibleWebView->m_pNucleus->m_pWorkXobj->GetVisibleChildByName(_T("webviewclient"));
				if (pXobj)
					hWebHostWnd = pXobj->m_pHostWnd->m_hWnd;
				if (hWebHostWnd == NULL || !::IsChild(m_pVisibleWebView->m_pNucleus->m_pWorkXobj->m_pHostWnd->m_hWnd, hWebHostWnd))
				{
					if (pXobj)
					{
						hWebHostWnd = m_pVisibleWebView->m_hWebHostWnd = pXobj->m_pHostWnd->m_hWnd;
					}
				}
			}
			if (hWebHostWnd == NULL)
			{
				hWebHostWnd = m_pVisibleWebView->m_hChildWnd;
			}
			if (::IsWindowVisible(hWebHostWnd) == false) {
				rc.right = rc.left + 1;
				rc.bottom = rc.top + 1;
			}
			else {
				RECT rc2;
				::GetWindowRect(hWebHostWnd, &rc2);
				if (::ScreenToClient(hExtendWnd, (LPPOINT)&rc2))
				{
					::ScreenToClient(hExtendWnd, ((LPPOINT)&rc2) + 1);
					RECT rect;
					::GetClientRect(hExtendWnd, &rect);
					if (m_bSZMode)
					{
						rc.right = rc.left + 1;
						rc.bottom = rc.top + 1;
					}
					else
					{
						rc.left += rc2.left / m_fdevice_scale_factor;
						rc.right -= (rect.right - rc2.right) / m_fdevice_scale_factor;
						rc.top += (rc2.top - rect.top) / m_fdevice_scale_factor;
						rc.bottom -= (rect.bottom - rc2.bottom) / m_fdevice_scale_factor;
						if (rc.right <= rc.left || rc.bottom <= rc.top)
						{
							rc.right = rc.left + 1;
							rc.bottom = rc.top + 1;
						}
						if (m_pParentXobj && g_pSpaceTelescope->m_bChromeNeedClosed == false && m_bDestroy == false)
						{
							HWND hPWnd = m_pParentXobj->m_pXobjShareData->m_pNucleus->m_hWnd;
							if (m_pWebRTFrameWndInfo && m_pWebRTFrameWndInfo->m_nFrameType == 1)
							{
								if (m_OldRect.left != rc.left || m_OldRect.top != rc.top || m_OldRect.right != rc.right || m_OldRect.bottom != rc.bottom)
								{
									g_pSpaceTelescope->m_mapSizingBrowser[m_hWnd] = this;
									::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)hPWnd, 20210309);
								}
							}
						}
						m_OldRect = rc;
					}
				}
			}
		}
		BrowserLayout();
	};

	LRESULT CBrowser::BrowserLayout() {
		if (m_bInTabChange || m_bDestroy || m_pVisibleWebView == nullptr || !::IsWindowVisible(m_hWnd) ||
			g_pSpaceTelescope->m_bChromeNeedClosed == TRUE)
			return 0;
		if (!::IsWindow(m_hWnd))
			return 0;
		if (m_pWebRTFrameWndInfo && m_pWebRTFrameWndInfo->m_nFrameType == 2)
		{
			auto it = g_pSpaceTelescope->m_mapMDIParent.find(::GetParent(m_pWebRTFrameWndInfo->m_hClient));
			if (it != g_pSpaceTelescope->m_mapMDIParent.end())
			{
				if (it->second->m_bCreateNewDoc)
				{
					m_bInTabChange = true;
					return 0;
				}
			}
			if (m_pVisibleWebView == m_pWebRTFrameWndInfo->m_pWebView)
			{
				if (m_pVisibleWebView->m_bCanShow == false)
					return 0;
			}
		}
		RECT rcBrowser;
		GetClientRect(&rcBrowser);
		if (theApp.m_bAppStarting || m_pVisibleWebView->m_pNucleus == nullptr || m_pVisibleWebView->m_strCurKey == _T("")) {
			if (rcBrowser.right * rcBrowser.left)
				::SetWindowPos(m_pVisibleWebView->m_hExtendWnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_SHOWWINDOW);
			if (m_hDrawWnd)
				::SetWindowRgn(m_hDrawWnd, NULL, true);
			return 0;
		}

		if (!::IsWindowVisible(m_pVisibleWebView->m_hWnd))
		{
			if (m_pVisibleWebView->m_hExtendWnd)
				::SetParent(m_pVisibleWebView->m_hExtendWnd, m_pVisibleWebView->m_hWnd);
			auto it = g_pSpaceTelescope->m_mapWebView.find(m_pBrowser->GetActiveWebContentWnd());
			if (it != g_pSpaceTelescope->m_mapWebView.end())
			{
				m_pVisibleWebView = (CWebView*)it->second;
				if (m_pVisibleWebView->m_hExtendWnd)
					::SetParent(m_pVisibleWebView->m_hExtendWnd, m_hWnd);
			}
		}

		if (::GetParent(m_pVisibleWebView->m_hExtendWnd) != m_hWnd) {
			::SetParent(m_pVisibleWebView->m_hExtendWnd, m_hWnd);
		}

		BrowserLayoutImpl();

		if (m_pParentXobj) {
			RECT rc;
			::GetClientRect(m_pParentXobj->m_pHostWnd->m_hWnd, &rc);
			::SetWindowPos(m_hWnd, HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOREDRAW);
		}

		return 0;
	}

	LRESULT CBrowser::OnActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		if (m_bDestroy)
			return lRes;
		if (LOWORD(wParam) != WA_INACTIVE) {
			if (m_pBrowser) {
				g_pSpaceTelescope->m_pActiveBrowser = m_pBrowser;
				g_pSpaceTelescope->m_pActiveBrowser->m_pProxy = this;
			}
		}
		return lRes;
	}

	LRESULT CBrowser::OnMouseActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		if (m_pVisibleWebView)
		{
			g_pSpaceTelescope->m_pActiveHtmlWnd = m_pVisibleWebView;
			if (m_pVisibleWebView->m_pChromeRenderFrameHost)
			{
				g_pSpaceTelescope->m_pNucleus = nullptr;
				g_pSpaceTelescope->m_bWinFormActived = false;
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CBrowser::OnShowWindow(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL&) {
		if (m_pParentXobj && g_pSpaceTelescope->m_bChromeNeedClosed == false)
		{
			if (wParam) {
				RECT rc;
				::GetClientRect(m_pParentXobj->m_pHostWnd->m_hWnd, &rc);
				::SetWindowPos(m_hWnd, HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOREDRAW);
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CBrowser::OnWebRTMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		if (m_bDestroy)
			return lRes;
		HWND hWnd = (HWND)lParam;
		switch (wParam) {
		case 20230331:
		{
			if (m_pParentXobj)
				::PostMessage(m_pParentXobj->m_pHostWnd->m_hWnd, WM_COSMOSMSG, 0, 20210315);
		}
		break;
		case 202111090001:
		{
			HWND hTop = ::GetAncestor(m_hWnd, GA_ROOT);
			::RedrawWindow(hTop, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN /*| RDW_UPDATENOW*/);
		}
		break;
		case 0: {
			if (g_pSpaceTelescope->m_bCreatingDevTool)
			{
				g_pSpaceTelescope->m_pHtmlWndCreated = new CComObject<CWebView>;
				g_pSpaceTelescope->m_pHtmlWndCreated->SubclassWindow(hWnd);
				if (g_pSpaceTelescope->m_pCLRProxy)
					g_pSpaceTelescope->m_pCLRProxy->OnWebPageCreated(hWnd, (CWebViewImpl*)g_pSpaceTelescope->m_pHtmlWndCreated, (IWebView*)g_pSpaceTelescope->m_pHtmlWndCreated, 0);
				g_pSpaceTelescope->m_bCreatingDevTool = false;
				g_pSpaceTelescope->m_pHtmlWndCreated->m_bDevToolWnd = true;
				if (m_pVisibleWebView) {
					m_pVisibleWebView->m_pDevToolWnd = g_pSpaceTelescope->m_pHtmlWndCreated;
					g_pSpaceTelescope->m_pHtmlWndCreated->m_pWebWnd = m_pVisibleWebView;
				}
				g_pSpaceTelescope->m_pActiveHtmlWnd = m_pVisibleWebView;
				g_pSpaceTelescope->m_pNucleus = nullptr;
				g_pSpaceTelescope->m_bWinFormActived = false;
				g_pSpaceTelescope->m_pHtmlWndCreated->m_bCanShow = true;
				m_mapChildPage[hWnd] = g_pSpaceTelescope->m_pHtmlWndCreated;
				::PostMessage(hWnd, WM_COSMOSMSG, 20190331, 1);
			}
		} break;
		case 1:
		{
			if (lParam == 20200115)
			{
				::InvalidateRect(m_hWnd, nullptr, true);
				m_pBrowser->LayoutBrowser();
				::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 2);
				::InvalidateRect(m_hWnd, nullptr, true);
			}
		}
		break;
		case 20210314://TabChange
		{
			HWND hActiveWebView = m_pBrowser->GetActiveWebContentWnd();
			auto it = m_mapChildPage.find(hActiveWebView);
			if (it != m_mapChildPage.end())
				m_pVisibleWebView = it->second;
			else
			{
				auto it = g_pSpaceTelescope->m_mapWebView.find(hActiveWebView);
				if (it != g_pSpaceTelescope->m_mapWebView.end())
					m_pVisibleWebView = (CWebView*)it->second;
			}
			m_pVisibleWebView->m_bCanShow = false;
			if (theApp.m_bAppStarting == false && m_pParentXobj)
			{
				m_bSZMode = true;
				g_pSpaceTelescope->m_mapSizingBrowser[m_hWnd] = this;

				if (m_pWebRTFrameWndInfo)
				{
					switch (m_pWebRTFrameWndInfo->m_nFrameType)
					{
					case 1:
					{
						if (!::IsChild(m_pParentXobj->m_pHostWnd->m_hWnd, m_hWnd))
							::SetParent(m_hWnd, m_pParentXobj->m_pHostWnd->m_hWnd);
					}
					break;
					case 2:
						if (m_pVisibleWebView->m_pNucleus)
						{
							m_pVisibleWebView->m_bCanShow = true;
							IXobj* pObj = nullptr;
							m_pVisibleWebView->Observe(CComBSTR(m_pVisibleWebView->m_pNucleus->m_strCurrentKey), CComBSTR(""), &pObj);
							::PostMessage(m_pParentXobj->m_pHostWnd->m_hWnd, WM_COSMOSMSG, 0, 20210315);
						}
						break;
					}
				}
				CXobj* pClientObj = nullptr;
				if (m_pParentXobj->m_pParentWinFormWnd)
				{
					if (!::IsChild(m_hWnd, m_pParentXobj->m_pParentWinFormWnd->m_hWnd))
					{
						CNucleus* pGalaxy = m_pParentXobj->m_pParentWinFormWnd->m_pClientGalaxy;
						if (pGalaxy && pGalaxy->m_pWorkXobj)
						{
							pClientObj = pGalaxy->m_pWorkXobj->GetVisibleChildByName(_T("hostclient"));
							if (pClientObj)
							{
								g_pSpaceTelescope->ModifyBindingXobj(pGalaxy, pClientObj);
							}
						}
					}
				}
				else if (m_pParentXobj)
				{
					if (!::IsChild(m_hWnd, m_pParentXobj->m_pHostWnd->m_hWnd))
					{
						CNucleus* pGalaxy = m_pParentXobj->m_pXobjShareData->m_pNucleus;
						if (pGalaxy && pGalaxy->m_pWorkXobj)
						{
							pClientObj = m_pVisibleWebView->m_pNucleus->m_pWorkXobj->GetVisibleChildByName(_T("hostclient"));
							if (pClientObj)
							{
								g_pSpaceTelescope->ModifyBindingXobj(pGalaxy, pClientObj);
							}
						}
					}
				}
			}
			g_pSpaceTelescope->m_mapSizingBrowser[m_hWnd] = this;
			if (m_pParentXobj == nullptr)
				::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 7, 7);
			else
			{
				if (m_pVisibleWebView->m_strLoadingURLs == _T("") && g_pSpaceTelescope->m_hWaitTabWebPageWnd == NULL && g_pSpaceTelescope->m_nWaitTabCounts == 0)
				{
					::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 7, 7);
				}
				else
					::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 7);
			}
		}
		break;
		case 20190527:
		{
			return (LRESULT)((IBrowser*)this);
		}
		break;
		case 20200205:
		{
			if (lParam == 1)
			{
				m_bTabChange = false;
			}
		}
		return 1;
		break;
		case 20200128:
		{
			if (m_pVisibleWebView)
			{
				CNucleus* pGalaxy = m_pVisibleWebView->m_pNucleus;
				if (pGalaxy)
				{
					CXobj* pXobj = pGalaxy->m_pWorkXobj;
					CXobjWnd* pWnd = (CXobjWnd*)(pXobj->m_pHostWnd);
					return (LRESULT)(pWnd->m_hWnd);
				}
			}
		}
		break;
		case 1992:
		{
			return (LRESULT)m_pBrowser->GetBrowser();
		}
		break;
		case 20211020:
			if (m_pParentXobj && ::IsWindowVisible(m_pParentXobj->m_pHostWnd->m_hWnd))
			{
				ShowWindow(SW_SHOW);
			}
			break;
		case 20190629:
		{
			switch (lParam)
			{
			case 1:
				return m_pVisibleWebView && ::IsWindow(m_pVisibleWebView->m_hExtendWnd);
				break;
			}
		}
		break;
		}
		return lRes;
	}

	LRESULT CBrowser::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		m_bDestroy = true;
		if (g_pSpaceTelescope->m_mapBrowserWnd.size() == 1)
		{
			if (g_pSpaceTelescope->m_dwEnumTopWndThreadID != -1)
				::PostAppMessage(g_pSpaceTelescope->m_dwEnumTopWndThreadID, WM_COSMOSMSG, 1, 0);
		}
		if (g_pSpaceTelescope->m_pCLRProxy)
		{
			IBrowser* pIBrowser = nullptr;
			QueryInterface(__uuidof(IBrowser), (void**)&pIBrowser);
			g_pSpaceTelescope->m_pCLRProxy->OnDestroyChromeBrowser(pIBrowser);
		}

		m_pVisibleWebView = nullptr;
		auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(m_hWnd);
		if (it != g_pSpaceTelescope->m_mapBrowserWnd.end()) {
			g_pSpaceTelescope->m_mapBrowserWnd.erase(it);
		}
		if ((g_pSpaceTelescope->m_hMainWnd == g_pSpaceTelescope->m_hCosmosWnd && g_pSpaceTelescope->m_mapBrowserWnd.size() == 1) ||
			g_pSpaceTelescope->m_hHostBrowserWnd == m_hWnd)
		{
			if (g_pSpaceTelescope->m_hHostBrowserWnd == m_hWnd)
			{
				g_pSpaceTelescope->m_bChromeNeedClosed = true;
				for (auto& it : g_pSpaceTelescope->m_mapBrowserWnd)
				{
					if (((CBrowser*)it.second)->m_hWnd != m_hWnd)
						((CBrowser*)it.second)->PostMessageW(WM_CLOSE, 0, 0);
				}
				g_pSpaceTelescope->m_mapBrowserWnd.erase(g_pSpaceTelescope->m_mapBrowserWnd.begin(), g_pSpaceTelescope->m_mapBrowserWnd.end());
			}
		}

		bool bExitCLR = false;
		if ((g_pSpaceTelescope->m_hMainWnd == NULL && g_pSpaceTelescope->m_mapBrowserWnd.size() == 0) ||
			g_pSpaceTelescope->m_hHostBrowserWnd == m_hWnd) {
			if (g_pSpaceTelescope->m_hHostBrowserWnd == m_hWnd)
				g_pSpaceTelescope->m_hHostBrowserWnd = NULL;
			if (g_pSpaceTelescope->m_pCLRProxy)
			{
				if (g_pSpaceTelescope->m_pWebRTAppProxy)
				{
					bExitCLR = true;
					::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, 0, 20210420);
				}
			}

			if (g_pSpaceTelescope->m_hCBTHook) {
				UnhookWindowsHookEx(g_pSpaceTelescope->m_hCBTHook);
				g_pSpaceTelescope->m_hCBTHook = nullptr;
			}
		}

		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);

		if (g_pSpaceTelescope->m_hMainWnd == NULL &&
			g_pSpaceTelescope->m_bChromeNeedClosed == false &&
			g_pSpaceTelescope->m_mapBrowserWnd.size() == 1 &&
			::IsWindow(g_pSpaceTelescope->m_hHostBrowserWnd) &&
			g_pSpaceTelescope->m_nAppID == 10000 &&
			g_pSpaceTelescope->m_bEclipse == false)
		{
			::SendMessageW(g_pSpaceTelescope->m_hHostBrowserWnd, WM_CLOSE, 0, 0);
			if (g_pSpaceTelescope->m_dwEnumTopWndThreadID != -1)
				::PostAppMessage(g_pSpaceTelescope->m_dwEnumTopWndThreadID, WM_COSMOSMSG, 1, 0);
		}
		if (bExitCLR)
		{
			g_pSpaceTelescope->m_pWebRTAppProxy->OnWebRTClose(CosmosCloseState::FinalBrowserClose);
		}
		if (g_pSpaceTelescope->m_mapBrowserWnd.size() == 0)
		{
			::SendMessageW(g_pSpaceTelescope->m_hCosmosWnd, WM_CLOSE, 0, 0);
		}
		return lRes;
	}

	LRESULT CBrowser::OnChromeTabChange(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		if (m_pVisibleWebView && m_pVisibleWebView->m_pNucleus)
		{
		}
		return lRes;
	}

	LRESULT CBrowser::OnWindowPosChanging(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		WINDOWPOS* lpwndpos = (WINDOWPOS*)lParam;
		if (m_bInTabChange || m_bDestroy || !::IsWindowVisible(m_hWnd) || lpwndpos->flags == (SWP_NOSIZE | SWP_NOMOVE))
			return DefWindowProc(uMsg, wParam, lParam);
		HWND hPWnd = ::GetParent(m_hWnd);
		if (m_bSZMode)
		{
			g_pSpaceTelescope->m_mapSizingBrowser[m_hWnd] = this;
		}
		if (::IsWindow(hPWnd))
		{
			if (lpwndpos->cx * lpwndpos->cy <= 4) {
				TRACE(_T("too small!\n"));
			}
			RECT rc;
			::GetClientRect(hPWnd, &rc);
			lpwndpos->x = -12;
			lpwndpos->y = -6;
			lpwndpos->cx = rc.right + 24;
			lpwndpos->cy = rc.bottom + 18;
			lpwndpos->flags |= SWP_NOREDRAW | SWP_NOACTIVATE;
		}
		else if (g_pSpaceTelescope->m_bOMNIBOXPOPUPVISIBLE)
			::SendMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 2);
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CBrowser::OnExitSZ(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		m_bSZMode = false;
		for (auto& it : g_pSpaceTelescope->m_mapSizingBrowser)
		{
			if (::IsWindow(it.first))
			{
				it.second->m_bSZMode = false;
				it.second->m_pBrowser->LayoutBrowser();
			}
		}
		g_pSpaceTelescope->m_mapSizingBrowser.erase(g_pSpaceTelescope->m_mapSizingBrowser.begin(), g_pSpaceTelescope->m_mapSizingBrowser.end());
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CBrowser::OnEnterSZ(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&) {
		m_bSZMode = true;
		g_pSpaceTelescope->m_mapSizingBrowser[m_hWnd] = this;
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CBrowser::OnBrowserLayout(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
	{
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		if (m_bInTabChange || m_bDestroy)
		{
			if (m_pParentXobj)
			{
				if (wParam == 7 && m_pMDIParent == nullptr)
				{
					m_bInTabChange = false;
					::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 1, 7);
				}
				else
					return lRes;
			}
		}
		if (g_pSpaceTelescope->m_bChromeNeedClosed == false && m_pVisibleWebView)
		{
			switch (lParam)
			{
			case 1000:
			{
				m_bTabChange = false;
				if (m_pParentXobj)
				{
					g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(QueryType::RecalcLayout, m_pParentXobj->m_pXobjShareData->m_pNucleus->m_hWnd);
					m_pBrowser->LayoutBrowser();
				}
				if (::GetParent(m_hWnd) == nullptr)
				{
					HWND hWnd = m_pBrowser->GetActiveWebContentWnd();
					if (hWnd == m_pVisibleWebView->m_hWnd)
					{
						if (m_pVisibleWebView->m_pNucleus)
						{
							m_pBrowser->LayoutBrowser();
							BrowserLayout();
						}
					}
					else
					{
						auto it = g_pSpaceTelescope->m_mapWebView.find(hWnd);
						if (it != g_pSpaceTelescope->m_mapWebView.end())
						{
							m_pVisibleWebView = (CWebView*)it->second;
						}
						else
						{
							m_pVisibleWebView = new CComObject<CWebView>();
							m_pVisibleWebView->SubclassWindow(hWnd);
							g_pSpaceTelescope->m_mapWebView[hWnd] = m_pVisibleWebView;
						}
					}
				}
			}
			break;
			case 8:
			{
				RECT rc;
				::GetClientRect(m_hWnd, &rc);
				if ((rc.right < rc.left) || (rc.bottom < rc.top))
				{
					::GetClientRect(::GetParent(m_hWnd), &rc);
					::SetWindowPos(m_hWnd, HWND_TOP, 0, 0, rc.right, rc.bottom, SWP_NOREDRAW | SWP_NOACTIVATE);
				}
			}
			break;
			case 1:
			{
				m_bInTabChange = false;
				m_bSZMode = false;
				if (m_pMDIParent)
				{
					if (g_pSpaceTelescope->m_pUniverseAppProxy->m_nShellCmd != CCommandLineInfo::FileNothing)
					{
						::PostMessage(m_pMDIParent->m_hWnd, WM_QUERYAPPPROXY, 0, 19651965);
					}
				}
				else
				{
					if (m_pParentXobj && m_pParentXobj->m_pParentWinFormWnd && m_pParentXobj->m_pParentWinFormWnd->m_hMDIClient)
					{
						::SendMessage(m_pParentXobj->m_pParentWinFormWnd->m_hMDIClient, WM_COSMOSMSG, 0, 20180115);
					}
					if (m_pParentXobj)
						::PostMessage(m_pParentXobj->m_pXobjShareData->m_pNucleus->m_hWnd, WM_COSMOSMSG, 0, 20180115);
				}
			}
			break;
			case 2:
			case 3:
			case 4:
			{
				if (lParam == 4)
				{
					BrowserLayout();
					m_pBrowser->LayoutBrowser();
				}
				else if (m_pBrowser)
				{
					if (!::IsWindowVisible(m_hWnd))
						::ShowWindow(m_hWnd, SW_SHOW);
					if (g_pSpaceTelescope->m_bOMNIBOXPOPUPVISIBLE)
					{
						BrowserLayout();
						m_pBrowser->LayoutBrowser();
					}
					m_bTabChange = false;
				}
			}
			break;
			case 5:
			{
				if (m_pBrowser)
				{
					m_bTabChange = false;
					m_pBrowser->LayoutBrowser();
				}
			}
			break;
			case 7:
			{
				if (m_pVisibleWebView == nullptr)
					break;
				switch (wParam)
				{
				case 7:
				{
					m_bInTabChange = false;
					if (m_pParentXobj && m_pParentXobj->m_pParentWinFormWnd && m_pParentXobj->m_pParentWinFormWnd->m_hMDIClient)
					{
						m_pVisibleWebView->m_bCanShow = false;
						m_bSZMode = true;
						::SendMessage(m_pParentXobj->m_pParentWinFormWnd->m_hMDIClient, WM_COSMOSMSG, 3, 20180115);
						::PostMessage(m_pParentXobj->m_pParentWinFormWnd->m_hMDIClient, WM_COSMOSMSG, 0, 20180115);
					}
					if (m_pVisibleWebView)
						m_pVisibleWebView->m_bCanShow = true;
					::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 7);
				}
				break;
				case 3:
				{
					if (theApp.m_bAppStarting == false)
						m_pVisibleWebView->m_bCanShow = true;
				}
				break;
				case 2:
				{
					m_bTabChange = false;
					::SendMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 7);
					m_bSZMode = false;
					::PostAppMessage(::GetCurrentThreadId(), WM_BROWSERLAYOUT, (WPARAM)m_hWnd, 7);
				}
				break;
				case 1:
				{
					m_bTabChange = false;
					if (m_pMDIParent)
						m_pMDIParent->m_bCreateNewDoc = false;
					theApp.m_bAppStarting = false;
					::PostMessage(m_hWnd, WM_BROWSERLAYOUT, 0, 7);
					m_bSZMode = false;
					::PostMessage(m_hWnd, WM_COSMOSMSG, 202111090001, 0);
				}
				break;
				default:
				{
					if (/*(m_pMDIParent && m_pMDIParent->m_bCreateNewDoc) ||*/ !::IsWindowVisible(m_hWnd))
						break;
					if (/*g_pSpaceTelescope->m_nWaitTabCounts ||*/ m_bTabChange || m_bInTabChange)
						break;
					HWND hWnd = m_pBrowser->GetActiveWebContentWnd();
					for (auto& it : m_mapChildPage)
					{
						if (::IsWindow(it.first))
						{
							if (it.first != hWnd)
							{
								if (it.second->m_pChromeRenderFrameHost)
									it.second->m_pChromeRenderFrameHost->ShowWebPage(false);
							}
							else
							{
								m_pVisibleWebView = it.second;
							}
						}
					}

					m_bSZMode = false;
					m_pBrowser->LayoutBrowser();
					BrowserLayout();
					if (m_pParentXobj)
					{
						HWND hWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(QueryType::RecalcLayout, m_pParentXobj->m_pXobjShareData->m_pNucleus->m_hWnd);
					}

					if (m_pVisibleWebView && m_pVisibleWebView->m_pNucleus)
					{
						::SendMessage(m_pVisibleWebView->m_hExtendWnd, WM_BROWSERLAYOUT, (WPARAM)m_pVisibleWebView->m_hChildWnd, 0);
						m_pVisibleWebView->m_pNucleus->HostPosChanged();
						if (::GetParent(m_hWnd) == nullptr)
						{
							CXobj* pObj = m_pVisibleWebView->m_pNucleus->m_pWorkXobj;
							if (pObj && pObj->m_nViewType == Grid)
							{
								CSplitterWnd* pWnd = (CSplitterWnd*)pObj->m_pHostWnd;
								pWnd->RecalcLayout();
							}
						}
					}
					if (m_pMDIParent)
					{
						::PostMessage(m_pMDIParent->m_hWnd, WM_QUERYAPPPROXY, 0, 19651965);
					}
					else if (m_pParentXobj && ::IsWindowVisible(m_pParentXobj->m_pHostWnd->m_hWnd) && m_pParentXobj->m_pXobjShareData->m_pNucleus)
					{
						if (m_pVisibleWebView->m_pNucleus)
						{
							CXobj* pClient = m_pVisibleWebView->m_pNucleus->m_pWorkXobj->GetVisibleChildByName(_T("hostclient"));
							if (pClient)
							{
								g_pSpaceTelescope->ModifyBindingXobj(m_pParentXobj->m_pXobjShareData->m_pNucleus, pClient);
							}
						}
						::PostMessage(m_pParentXobj->m_pXobjShareData->m_pNucleus->m_hWnd, WM_COSMOSMSG, 0, 20180115);
						if (wParam == 100)
						{
							::PostMessage(m_hWnd, WM_COSMOSMSG, 202111090001, 0);
						}
					}
				}
				break;
				}
			}
			break;
			}
		}
		return lRes;
	}

	void CBrowser::OnFinalMessage(HWND hWnd) {
		CWindowImpl::OnFinalMessage(hWnd);
		delete this;
	}

	STDMETHODIMP CBrowser::get_RemoteXobj(IXobj** pVal)
	{
		if (m_pRemoteXobj != nullptr)
		{
			*pVal = m_pRemoteXobj;
		}
		return S_OK;
	}

	STDMETHODIMP CBrowser::put_RemoteXobj(IXobj* newVal)
	{
		CComQIPtr<IXobj>pXobj(newVal);
		if (pXobj)
			m_pRemoteXobj = pXobj.Detach();
		//if (m_pRemoteNode == nullptr)
		//{
		//	IStream* pStream = 0;
		//	HRESULT hr = ::CoMarshalInterThreadInterfaceInStream(IID_IXobj, (IXobj*)newVal.pdispVal, &pStream);
		//	if (hr == S_OK)
		//	{
		//		IDispatch* pTarget = nullptr;
		//		hr = ::CoGetInterfaceAndReleaseStream(pStream, IID_IDispatch, (LPVOID*)&pTarget);
		//		if (hr == S_OK && pTarget)
		//			hr = pTarget->QueryInterface(IID_IXobj, (void**)m_pRemoteNode);
		//	}
		//}
		return S_OK;
	}

	STDMETHODIMP CBrowser::AddURLs(BSTR bstrURLs)
	{
		if (m_pVisibleWebView)
		{
			CString strDisposition = _T("");
			strDisposition.Format(_T("%d"), NEW_BACKGROUND_TAB);
			if (m_pVisibleWebView->m_pChromeRenderFrameHost)
			{
				IPCMsg msg;
				msg.m_strId = L"ADD_URL";
				msg.m_strParam1 = OLE2T(bstrURLs);
				msg.m_strParam2 = strDisposition;
				m_pVisibleWebView->m_pChromeRenderFrameHost->SendCosmosMessage(&msg);
			}
		}
		return S_OK;
	}

	STDMETHODIMP CBrowser::OpenURL(BSTR bstrURL, BrowserWndOpenDisposition nDisposition, BSTR bstrKey, BSTR bstrXml)
	{
		if (m_pVisibleWebView)
		{
			CString strDisposition = _T("");
			strDisposition.Format(_T("%d"), nDisposition);
			if (m_pVisibleWebView->m_pChromeRenderFrameHost)
			{
				IPCMsg msg;
				msg.m_strId = L"OPEN_URL";
				msg.m_strParam1 = OLE2T(bstrURL);
				msg.m_strParam2 = strDisposition;
				m_pVisibleWebView->m_pChromeRenderFrameHost->SendCosmosMessage(&msg);
			}
		}
		return S_OK;
	}
}  // namespace Browser
