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
 
// TangramHtmlTreeExWnd.cpp : implementation file
//

#include "stdafx.h"
#include "TangramHtmlTreeExWnd.h"

#pragma warning(push)
#pragma warning(disable: 4201)
#include <mmsystem.h>
#pragma warning(pop)

#pragma comment(lib, "winmm.lib")
// CTangramHtmlTreeExWnd

CTangramHtmlTreeExWnd::CTangramHtmlTreeExWnd()
{
	m_bDrawSnapshot = false;

	m_sWaitMsg = _T("Loading...");
	m_bShowWaitMsg = false;
	m_hIconMsg = NULL;	// default: blank icon
	m_nTimerDelay = 0;	// default: no timer

	m_hRedrawEvent = NULL;
	m_hTimerEvent = NULL;
	m_hThread = NULL;
}

CTangramHtmlTreeExWnd::~CTangramHtmlTreeExWnd()
{
}


BEGIN_MESSAGE_MAP(CTangramHtmlTreeExWnd, CTangramHtmlTreeWnd)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemExpanding)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemExpanded)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CTangramHtmlTreeExWnd message handlers
/////////////////////////////////////////////////////////////////////////////
// CTangramHtmlTreeExWnd message handlers

void CTangramHtmlTreeExWnd::OnItemExpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	if (pNMTreeView->action & TVE_EXPAND)
		PreExpandItem(pNMTreeView->itemNew.hItem);

	*pResult = 0;
}

void CTangramHtmlTreeExWnd::OnItemExpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	if (pNMTreeView->action & TVE_EXPAND)
		ExpandItem(pNMTreeView->itemNew.hItem);
	else if (pNMTreeView->action & TVE_COLLAPSE)
	{
		if (WantsRefresh(pNMTreeView->itemNew.hItem))
		{
			// delete child items
			DeleteChildren(pNMTreeView->itemNew.hItem);
		}
	}

	*pResult = 0;
}

void CTangramHtmlTreeExWnd::PreAnimation(HTREEITEM hItemMsg)
{
	UNREFERENCED_PARAMETER(hItemMsg);
}

void CTangramHtmlTreeExWnd::PostAnimation()
{
	::SendMessage(m_hWnd,WM_INSERTTREENODE,0,(LPARAM)m_hCurSelectedItem);
}

void CTangramHtmlTreeExWnd::DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep)
{
	UNREFERENCED_PARAMETER(bTimerEvent);
	UNREFERENCED_PARAMETER(iMaxSteps);
	UNREFERENCED_PARAMETER(iStep);
}

int CTangramHtmlTreeExWnd::GetPopulationCount(int *piMaxSubItems)
{
	if (piMaxSubItems != NULL)
		*piMaxSubItems = m_iItemCount;
	return m_iItemIndex;
}

void CTangramHtmlTreeExWnd::SetPopulationCount(int iMaxSubItems, int iFirstSubItem)
{
	m_iItemCount = iMaxSubItems;
	m_iItemIndex = iFirstSubItem;

	SetEvent(m_hRedrawEvent);
}

void CTangramHtmlTreeExWnd::UpdatePopulation(int iSubItems)
{
	m_iItemIndex = iSubItems;

	SetEvent(m_hRedrawEvent);
}

void CTangramHtmlTreeExWnd::IncreasePopulation(int iSubItemsToAdd)
{
	m_iItemIndex += iSubItemsToAdd;

	SetEvent(m_hRedrawEvent);
}

void CTangramHtmlTreeExWnd::SetAnimationDelay(UINT nMilliseconds)
{
	// if greater than zero, periodic DoAnimation() will be called
	m_nTimerDelay = nMilliseconds;
}

DWORD WINAPI CTangramHtmlTreeExWnd::AnimationThreadProc(LPVOID pThis)
{
	CTangramHtmlTreeExWnd* me = (CTangramHtmlTreeExWnd*)pThis;

	HANDLE events[2] = { me->m_hTimerEvent, me->m_hRedrawEvent };
	
	while (!me->m_bAbortAnimation)
	{
		DWORD wait = WaitForMultipleObjects(2, events, false, INFINITE);
		
		if (me->m_bAbortAnimation || wait == WAIT_FAILED)
			break;

		if (wait == WAIT_OBJECT_0)	// timer event
			me->DoAnimation(true, me->m_iItemCount, me->m_iItemIndex);
		else	// redraw event
			me->DoAnimation(false, me->m_iItemCount, me->m_iItemIndex);
	}

	return 0;
}

void CTangramHtmlTreeExWnd::StartAnimation()
{
	// user-defined setup
	PreAnimation(m_hItemMsg);

	// animation can go
	m_bAbortAnimation = false;
	// automatic reset events, signaled
	m_hTimerEvent = CreateEvent(NULL, false, true, NULL);
	m_hRedrawEvent = CreateEvent(NULL, false, true, NULL);
	// start animation thread
	DWORD dwThreadID = 0;
	m_hThread = CreateThread(NULL, 0, AnimationThreadProc, this,
		THREAD_PRIORITY_HIGHEST, &dwThreadID);
	// setup timer, if specified
	if (m_nTimerDelay > 0)
		m_nTimerID = (UINT)timeSetEvent(m_nTimerDelay, 5, (LPTIMECALLBACK)m_hTimerEvent,
			0, TIME_PERIODIC | TIME_CALLBACK_EVENT_SET);
}

void CTangramHtmlTreeExWnd::StopAnimation()
{
	// stop and destroy timer
	timeKillEvent(m_nTimerID);
	// signal thread to terminate
	m_bAbortAnimation = true;
	SetEvent(m_hRedrawEvent);	// make sure it can see the signal
	// wait thread termination
	WaitForSingleObject(m_hThread, INFINITE);
	// clean up
	CloseHandle(m_hTimerEvent);
	m_hTimerEvent = NULL;
	CloseHandle(m_hRedrawEvent);
	m_hRedrawEvent = NULL;
	CloseHandle(m_hThread);
	m_hThread = NULL;

	// user-defined cleanup
	PostAnimation();
}

void CTangramHtmlTreeExWnd::PopulateRoot()
{
	//PreExpandItem(TVI_ROOT);
	//ExpandItem(TVI_ROOT);
	//// force update, don't scroll
	//SetRedraw(false);
	//SCROLLINFO si;
	//GetScrollInfo(SB_HORZ, &si);
	//EnsureVisible(GetChildItem(TVI_ROOT));
	//SetScrollInfo(SB_HORZ, &si, false);
	//SetRedraw();
}

void CTangramHtmlTreeExWnd::PreExpandItem(HTREEITEM hItem)
{
	if(hItem)
	{
		m_hCurSelectedItem = hItem;
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
		if(pXTCD->m_hWaitItemMsg)
		{
			m_hItemToPopulate = hItem;

			// fix redraw when expanded programatically
			UpdateWindow();
			// hide changes until it's expanded
			SetRedraw(false);
			// add wait msg, to allow item expansion
			m_hItemMsg = pXTCD->m_hWaitItemMsg;//InsertItem(m_sWaitMsg, m_hItemToPopulate);
			// zero progress
			m_iItemCount = 1;
			m_iItemIndex = 0;
			return;
		}
	}
	if (!NeedsChildren(hItem))
	{
		if (WantsRefresh(hItem))
		{
			// delete child items before populating
			DeleteChildren(hItem);
		}
		else
		{
			// doesn't want new items
			m_hItemToPopulate = NULL;
			return;
		}
	}
	// if it wants new child items, go on
	m_hItemToPopulate = hItem;

	// fix redraw when expanded programatically
	UpdateWindow();
	// hide changes until it's expanded
	SetRedraw(false);
	// add wait msg, to allow item expansion
	m_hItemMsg = InsertItem(m_sWaitMsg, m_hItemToPopulate);
	// zero progress
	m_iItemCount = 1;
	m_iItemIndex = 0;
}

//void CTangramHtmlTreeExWnd::PreExpandItem(HTREEITEM hItem)
//{
//	if (!NeedsChildren(hItem))
//	{
//		if (WantsRefresh(hItem))
//		{
//			// delete child items before populating
//			DeleteChildren(hItem);
//		}
//		else
//		{
//			// doesn't want new items
//			m_hItemToPopulate = NULL;
//			return;
//		}
//	}
//	// if it wants new child items, go on
//	m_hItemToPopulate = hItem;
//
//	// fix redraw when expanded programatically
//	UpdateWindow();
//	// hide changes until it's expanded
//	SetRedraw(false);
//	// add wait msg, to allow item expansion
//	m_hItemMsg = InsertItem(m_sWaitMsg, m_hItemToPopulate);
//	// zero progress
//	m_iItemCount = 1;
//	m_iItemIndex = 0;
//}
//
void CTangramHtmlTreeExWnd::ExpandItem(HTREEITEM hItem)
{
	if (m_hItemToPopulate == NULL)
		return;	// just expand, doesn't want new items

	ASSERT(hItem == m_hItemToPopulate);	// should never fail!!!

	if (m_bShowWaitMsg)
	{
		// display wait msg now, make sure it's visible
		SetRedraw();
		EnsureVisible(m_hItemMsg);
		UpdateWindow();
	}
	// setup animation thread, call PreAnimation
	StartAnimation();
	// draw icon
	if (m_bShowWaitMsg)
		DrawUserIcon();
	// delay redraw after populating
	SetRedraw(false);
	// take a snapshot of the background
	TakeSnapshot();
	// del temporary item (wait msg still shown)
	//DeleteItem(m_hItemMsg);
	// fill in with sub items
	BOOL bCheckChildren = PopulateItem(hItem);
	// clean up animation thread, call PostAnimation
	StopAnimation();
	// change parent to reflect current children number
	if (hItem != TVI_ROOT)
	{
		TVITEM item;
		item.hItem = hItem;
		item.mask = TVIF_HANDLE | TVIF_CHILDREN;
		item.cChildren = NeedsChildren(hItem) ? 0 : 1;
		if (bCheckChildren)
			SetItem(&item);
		else if (item.cChildren == 0)
			// restore item's plus button if no children inserted
			SetItemState(hItem, 0, TVIS_EXPANDED);
	}
	// clean up snapshot
	DestroySnapshot();
	// redraw now
	SetRedraw(true);
}

BOOL CTangramHtmlTreeExWnd::WantsRefresh(HTREEITEM hItem)
{
	UNREFERENCED_PARAMETER(hItem);

	// default implementation, no refresh
	return false;
}

BOOL CTangramHtmlTreeExWnd::GetItemImageRect(HTREEITEM hItem, LPRECT pRect)
{
	//if (GetImageList(TVSIL_NORMAL) == NULL)
	//	return false;	// no images

	CRect rc;
	// get item rect
	if (!GetItemRect(hItem, &rc, true))
		return false;

	int cx = GetSystemMetrics(SM_CXSMICON);
	int cy = GetSystemMetrics(SM_CYSMICON);

	// move onto the icon space
	int margin = (rc.Height()-cy)/2;
	rc.OffsetRect(-cx-3 , margin);
	rc.right = rc.left + cx;	// make it square
	rc.bottom = rc.top + cy;	// make it square

	*pRect = rc;
	return true;
}

void CTangramHtmlTreeExWnd::DrawUserIcon()
{
	// draw user defined icon

	CRect rcIcon;
	if (!GetItemImageRect(m_hItemMsg, &rcIcon))
		return;	// no image

	// create background brush with current bg color (take rgb part only)
	HBRUSH hBrush = CreateSolidBrush(GetBkColor() & 0x00FFFFFF);

	CClientDC dc(this);

	if (m_hIconMsg != NULL)
		DrawIconEx(dc.GetSafeHdc(), rcIcon.left, rcIcon.top, m_hIconMsg,
			rcIcon.Width(), rcIcon.Height(), 0, hBrush, DI_NORMAL);
	else
		FillRect(dc.GetSafeHdc(), &rcIcon, hBrush);

	DeleteObject(hBrush);
}

void CTangramHtmlTreeExWnd::SetWaitMessage(LPCTSTR pszText, HICON hIcon)
{
	m_sWaitMsg = pszText;
	m_hIconMsg = hIcon;
}

void CTangramHtmlTreeExWnd::RefreshSubItems(HTREEITEM hParent)
{
	if (hParent != TVI_ROOT && !ItemHasChildren(hParent))
		return;

	SetRedraw(false);
	DeleteChildren(hParent);
	if (hParent == TVI_ROOT)
		PopulateRoot();
	else
	{
		PreExpandItem(hParent);
		ExpandItem(hParent);
	}
	SetRedraw(true);
}

inline BOOL CTangramHtmlTreeExWnd::NeedsChildren(HTREEITEM hParent)
{
	return (GetChildItem(hParent) == NULL);
}

void CTangramHtmlTreeExWnd::DeleteChildren(HTREEITEM hParent)
{
	HTREEITEM hChild = GetChildItem(hParent);
	HTREEITEM hNext;

	while (hChild != NULL)
	{
		hNext = GetNextSiblingItem(hChild);
		DeleteItem(hChild);
		hChild = hNext;
	}
}

BOOL CTangramHtmlTreeExWnd::OnEraseBkgnd(CDC* pDC) 
{
	if (!m_bDrawSnapshot)
		return CTangramHtmlTreeWnd::OnEraseBkgnd(pDC);

	DrawSnapshot(pDC);
	SetEvent(m_hRedrawEvent);

	CRect rectClientx;
	GetClientRect(&rectClientx);
	pDC->FillSolidRect(rectClientx, m_crWindow);
	return true;
	//return CTangramHtmlTreeWnd::OnEraseBkgnd(pDC) ;
}

void CTangramHtmlTreeExWnd::TakeSnapshot()
{
	CClientDC dc(this);
	CRect rcClient;
	GetClientRect(&rcClient);
	int width = rcClient.Width(), height = rcClient.Height();

	// create the snapshot
	CDC dcSnapshot;
	dcSnapshot.CreateCompatibleDC(&dc);
	m_bmpSnapshot.CreateCompatibleBitmap(&dc, width, height);
	// copy the control's background
	CBitmap* pOldBmp = dcSnapshot.SelectObject(&m_bmpSnapshot);
	dcSnapshot.BitBlt(0, 0, width, height, &dc, 0, 0, SRCCOPY);
	dcSnapshot.SelectObject(pOldBmp);

	m_bDrawSnapshot = true;
}

void CTangramHtmlTreeExWnd::DrawSnapshot(CDC *pDC)
{
	BITMAP bm;
	m_bmpSnapshot.GetBitmap(&bm);

	// prepare the snapshot
	CDC dcSnapshot;
	dcSnapshot.CreateCompatibleDC(pDC);
	// copy to the control's background
	CBitmap* pOldBmp = dcSnapshot.SelectObject(&m_bmpSnapshot);
	pDC->BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &dcSnapshot, 0, 0, SRCCOPY);
	dcSnapshot.SelectObject(pOldBmp);
}

void CTangramHtmlTreeExWnd::DestroySnapshot()
{
	m_bmpSnapshot.DeleteObject();

	m_bDrawSnapshot = false;
}

// TangramHtmlTreeExWnd.cpp : implementation file
//
// CTangramHtmlTreeEx2Wnd

CTangramHtmlTreeEx2Wnd::CTangramHtmlTreeEx2Wnd()
{
	m_bEndless = false;
}

CTangramHtmlTreeEx2Wnd::~CTangramHtmlTreeEx2Wnd()
{
}


BEGIN_MESSAGE_MAP(CTangramHtmlTreeEx2Wnd, CTangramHtmlTreeExWnd)
END_MESSAGE_MAP()



// CTangramHtmlTreeEx2Wnd message handlers

BOOL CTangramHtmlTreeEx2Wnd::PopulateItem(HTREEITEM hParent)
{
	DWORD level = 1;
	
	if (hParent != TVI_ROOT)
		level = GetItemData(hParent)+1;

	//if (m_bEndless)
	//	SetPopulationCount(0);
	//else
	//	SetPopulationCount(20-level);

	IncreasePopulation();
	if (hParent != TVI_ROOT)
		Sleep(100);

	SetPopulationCount(20,1);
	Sleep(100);

	return true;
}

void CTangramHtmlTreeEx2Wnd::PreSubclassWindow() 
{
	PopulateRoot();
}

void CTangramHtmlTreeEx2Wnd::SetProgressType(BOOL bEndless)
{
	m_bEndless = bEndless;
}
