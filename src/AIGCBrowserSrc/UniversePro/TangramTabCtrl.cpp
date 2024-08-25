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

// TangramTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "UniverseApp.h"
#include "Xobj.h"
#include "WinNucleus.h"
#include "TangramTabCtrl.h"
#include "TangramListView.h"

#include <io.h>
#include <stdio.h>

// CTangramListCtrl

IMPLEMENT_DYNAMIC(CTangramListCtrl, CListCtrl)

CTangramListCtrl::CTangramListCtrl()
{
	m_nListViewIndex = 0;
	m_nListViewSelectedIndex = 0;
	m_strDir = _T("");
	m_strSubDir = _T("");

	if (g_pSpaceTelescope->m_strExeName.CompareNoCase(_T("excel")) == 0)
	{
		auto it = g_pSpaceTelescope->m_mapValInfo.find(_T("exceldesignstate"));
		if (it == g_pSpaceTelescope->m_mapValInfo.end())
			g_pSpaceTelescope->m_mapValInfo[_T("exceldesignstate")] = CComVariant((VARIANT_BOOL)true);
	}
}

CTangramListCtrl::~CTangramListCtrl()
{
}


BEGIN_MESSAGE_MAP(CTangramListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CTangramListCtrl::OnNMDblclk)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CTangramListCtrl::OnLvnItemchanged)
END_MESSAGE_MAP()


// CTangramListCtrl message handlers

void CTangramListCtrl::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}

void CTangramListCtrl::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}

// CTangramTabCtrl

IMPLEMENT_DYNCREATE(CTangramTabCtrl, CTabCtrl)

CTangramTabCtrl::CTangramTabCtrl()
{
	m_nImageIndex = 0;
	m_strFilter = _T("*.xml");
	m_pNucleus = nullptr;
	m_pXobj = nullptr;
	m_pWebRTListView = nullptr;
}

CTangramTabCtrl::~CTangramTabCtrl()
{
}

BEGIN_MESSAGE_MAP(CTangramTabCtrl, CTabCtrl)
	ON_WM_MOUSEACTIVATE()
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnTcnSelchange)
	ON_MESSAGE(WM_INITIALUPDATE, OnInitialUpdate)
	ON_WM_WINDOWPOSCHANGED()
END_MESSAGE_MAP()

// CTangramTabCtrl message handlers

BOOL CTangramTabCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	m_pXobj = g_pSpaceTelescope->m_pActiveXobj;
	m_pXobj->m_pHostWnd = this;
	m_pXobj->m_nViewType = TabCtrl;
	m_pXobj->m_nID = nID;
	BOOL bRet = CTabCtrl::Create(dwStyle| TCS_MULTILINE|WS_CLIPCHILDREN, rect, pParentWnd, nID);
	m_ListCtrl.Create(WS_CHILD | WS_VISIBLE| LVS_AUTOARRANGE | LVS_SINGLESEL | LVS_SHAREIMAGELISTS | LVS_SHOWSELALWAYS, CRect(0, 0, 0, 0), this, 0);
	m_ListCtrl.m_pWebRTTabCtrl = this;
	::GetModuleFileName(theApp.m_hInstance, g_pSpaceTelescope->m_szBuffer, MAX_PATH);

	int width=320, heigh=90, clines=3;
	CComBSTR bstrVal("");
	m_pXobj->get_Attribute(CComBSTR("sizeandclines"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("SizeandcLines(%d,%d,%d)"), &width, &heigh, &clines);
	}

	SIZE size = { width, heigh};
	LVTILEVIEWINFO tileViewInfo = { 0 };

	tileViewInfo.cbSize = sizeof(tileViewInfo);
	tileViewInfo.dwFlags = LVTVIF_FIXEDSIZE;
	tileViewInfo.dwMask = LVTVIM_COLUMNS | LVTVIM_TILESIZE;
	tileViewInfo.cLines = clines;
	tileViewInfo.sizeTile = size;

	ListView_SetTileViewInfo(m_ListCtrl.m_hWnd, &tileViewInfo);
	ListView_SetView(m_ListCtrl.m_hWnd, LV_VIEW_TILE);
	CString strPath = g_pSpaceTelescope->m_szBuffer;
	int nPos = strPath.ReverseFind('\\');
	strPath = strPath.Left(nPos + 1) + _T("WebRTInit.dll");
	if (::PathFileExists(strPath))
	{
		CString strURL = _T("res://");
		strURL += strPath;
		strURL += _T("/images/tangrambk.png");
		m_ListCtrl.SetBkImage(LPTSTR(LPCTSTR(strURL)), TRUE);
	}

	PostMessage(WM_INITIALUPDATE);
	return bRet;
}

LRESULT CTangramTabCtrl::OnInitialUpdate(WPARAM wParam, LPARAM lParam)
{
	CComBSTR bstrKey(L"relationnode");
	m_pXobj->get_Attribute(bstrKey, &bstrKey);
	CString strKey = OLE2T(bstrKey);
	if (strKey == _T("TangramList"))
	{
		if (g_pSpaceTelescope->m_DocTemplateImageList.m_hImageList == 0)
			g_pSpaceTelescope->m_DocTemplateImageList.Create(32, 32, ILC_COLOR32, 0, 4);
		m_ListCtrl.SetImageList(&g_pSpaceTelescope->m_DocTemplateImageList, LVSIL_NORMAL);
	}
	if (strKey == _T("TangramListCLR"))
	{
	}
	CComPtr<IXobjCollection> pColl;
	CXobj* pXobj = m_pXobj->m_pRootObj;
	IXobj* _pXobj = nullptr;
	long nCount = 0;
	pXobj->GetXobjs(bstrKey, &_pXobj, &pColl, &nCount);
	if (_pXobj)
	{
		CXobjCollection* pWndXobjCollection = (CXobjCollection*)pColl.p;

		for (auto& it : *pWndXobjCollection->m_pXobjs)
		{
			CTangramListView* pWnd = (CTangramListView*)(it)->m_pHostWnd;
			pWnd->m_pWebRTTabCtrl = this;
			pWnd->InitTabCtrl(this);
		}
	}

	return CWnd::DefWindowProc(WM_INITIALUPDATE, wParam, lParam);
}

void CTangramTabCtrl::PostNcDestroy()
{
	if (m_pXobj)
		delete m_pXobj;

	CTabCtrl::PostNcDestroy();
	delete this;
}

int CTangramTabCtrl::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (g_pSpaceTelescope->m_pUniverseAppProxy)
	{
		HWND hMenuWnd = g_pSpaceTelescope->m_pUniverseAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
	g_pSpaceTelescope->m_pActiveXobj = m_pXobj;
	g_pSpaceTelescope->m_bWinFormActived = false;
	return MA_ACTIVATE;
}

void CTangramTabCtrl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}

void CTangramTabCtrl::RePosition()
{
}

void CTangramTabCtrl::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CTabCtrl::OnWindowPosChanged(lpwndpos);
}

void CTangramTabCtrl::FillListCtrl()
{
}

