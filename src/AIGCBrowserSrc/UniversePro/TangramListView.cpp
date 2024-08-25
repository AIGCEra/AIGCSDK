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

// TangramListView.cpp : implementation file
//

#include "stdafx.h"
#include "TangramListView.h"
#include "UniverseApp.h"
#include "Xobj.h"
#include "WinNucleus.h"
#include "TangramTabCtrl.h"
#include <io.h>
#include <stdio.h>
//#include "VisualStudioPlus/VSAddin.h"

// CTangramListView

IMPLEMENT_DYNCREATE(CTangramListView, CListView)

CTangramListView::CTangramListView()
{
	m_bCreated = FALSE;
	m_bFilling = FALSE;
	m_nStyle = 0;
	m_nActiveIndex = 0;
	m_pNucleus = nullptr;
	m_pXobj = nullptr;
	m_pWebRTTabCtrl = nullptr;
}

CTangramListView::~CTangramListView()
{
	if (m_pXobj)
		delete m_pXobj;
}

BEGIN_MESSAGE_MAP(CTangramListView, CListView)
	ON_WM_MOUSEACTIVATE()
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CTangramListView::OnLvnItemchanged)
	ON_MESSAGE(WM_HUBBLE_ACTIVEPAGE, OnActiveTangramPage)
END_MESSAGE_MAP()


// CTangramListView diagnostics

#ifdef _DEBUG
void CTangramListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CTangramListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG

// CTangramListView message handlers

void CTangramListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
}

void CTangramListView::InitTabCtrl(CTangramTabCtrl* pTabCtrl)
{
}

void CTangramListView::ChangeTemplate(int nItem)
{
}

BOOL CTangramListView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_pXobj = g_pSpaceTelescope->m_pActiveXobj;
	m_pXobj->m_pHostWnd = this;
	m_pXobj->m_nViewType = TangramListView;
	m_pXobj->m_nID = nID;
	CString strURL = _T("");
	BOOL bRet = CListView::Create(lpszClassName, lpszWindowName, dwStyle| LVS_ICON| LVS_AUTOARRANGE| LVS_SINGLESEL| LVS_SHAREIMAGELISTS| LVS_SHOWSELALWAYS, rect, pParentWnd, nID, pContext);
	if (::FindResource(NULL, _T("TANGRAMBK.PNG"), _T("IMAGES")) == nullptr)
	{
		::GetModuleFileName(theApp.m_hInstance, g_pSpaceTelescope->m_szBuffer, MAX_PATH);
		CString strPath = g_pSpaceTelescope->m_szBuffer;
		int nPos = strPath.ReverseFind('\\');
		strPath = strPath.Left(nPos + 1) + _T("WebRTInit.dll");
		//CString strPath = g_pSpaceTelescope->m_strProgramFilePath;
		//strPath += _T("\\tangram\\WebRTInit.dll");
		if (::PathFileExists(strPath))
		{
			strURL = _T("res://");
			strURL += strPath;
			strURL += _T("/images/tangrambk.png");
		}
	}
	else
	{
		::GetModuleFileName(NULL, g_pSpaceTelescope->m_szBuffer, MAX_PATH);
		strURL = _T("res://") + CString(g_pSpaceTelescope->m_szBuffer) + _T("/images/tangrambk.png");
	}
	SendMessage(WM_INITIALUPDATE);
	if(strURL!=_T(""))
		GetListCtrl().SetBkImage(LPTSTR(LPCTSTR(strURL)), TRUE);

	int width = 320, heigh = 90, clines = 3;
	CComBSTR bstrVal("");
	m_pXobj->get_Attribute(CComBSTR("sizeandclines"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("SizeandcLines(%d,%d,%d)"), &width, &heigh, &clines);
	}
	SIZE size = { width, heigh };
	LVTILEVIEWINFO tileViewInfo = { 0 };

	tileViewInfo.cbSize = sizeof(tileViewInfo);
	tileViewInfo.dwFlags = LVTVIF_FIXEDSIZE;
	tileViewInfo.dwMask = LVTVIM_COLUMNS | LVTVIM_TILESIZE;
	tileViewInfo.cLines = clines;
	tileViewInfo.sizeTile = size;

	ListView_SetTileViewInfo(GetListCtrl().m_hWnd, &tileViewInfo);
	ListView_SetView(GetListCtrl().m_hWnd, LV_VIEW_TILE);
	return bRet;
}

int CTangramListView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
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

void CTangramListView::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}

LRESULT CTangramListView::OnActiveTangramPage(WPARAM wParam, LPARAM lParam)
{
	return CWnd::DefWindowProc(WM_TABCHANGE, wParam, lParam);
}
