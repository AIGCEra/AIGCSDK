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

 // Xobj.cpp : implementation file

#include "stdafx.h"
#include "UniverseApp.h"
#include "Xobj.h"
#include "WinNucleus.h"
#include "XobjWnd.h"
#include "WPFView.h"
#include "GridWnd.h"
#include "TangramHtmlTreeWnd.h"
#include "chromium/WebPage.h"
#include "chromium/BrowserWnd.h"

struct AUX_DATA
{
	// system metrics
	int cxVScroll, cyHScroll;
	int cxIcon, cyIcon;

	int cxBorder2, cyBorder2;

	// device metrics for screen
	int cxPixelsPerInch, cyPixelsPerInch;

	// convenient system color
	HBRUSH hbrWindowFrame;
	HBRUSH hbrBtnFace;

	// color values of system colors used for CToolBar
	COLORREF clrBtnFace, clrBtnShadow, clrBtnHilite;
	COLORREF clrBtnText, clrWindowFrame;

	// standard cursors
	HCURSOR hcurWait;
	HCURSOR hcurArrow;
	HCURSOR hcurHelp;       // cursor used in Shift+F1 help

	// special GDI objects allocated on demand
	HFONT   hStatusFont;
	HFONT   hToolTipsFont;
	HBITMAP hbmMenuDot;
};

#ifndef _AFXDLL
extern AFX_DATA AUX_DATA afxData;
#else
AFX_DATA AUX_DATA afxData;
#endif // !_AFXDLL


#ifndef AFX_CX_BORDER
#define AFX_CX_BORDER CX_BORDER 
#endif

#ifndef AFX_CY_BORDER
#define AFX_CY_BORDER CY_BORDER 
#endif
#define CX_BORDER   1
#define CY_BORDER   1

// CGridWnd
enum HitTestValue
{
	noHit = 0,
	vSplitterBox = 1,
	hSplitterBox = 2,
	bothSplitterBox = 3,
	vSplitterBar1 = 101,
	vSplitterBar15 = 115,
	hSplitterBar1 = 201,
	hSplitterBar15 = 215,
	splitterIntersection1 = 301,
	splitterIntersection225 = 525
};

IMPLEMENT_DYNCREATE(CGridWnd, CSplitterWnd)

CGridWnd::CGridWnd()
{
	bInited = false;
	m_bCreated = false;
	m_pXobj = nullptr;
	m_pHostXobj = nullptr;
	m_nHostWidth = m_nHostHeight = 0;
	m_nMasterRow = m_nMasterCol = -1;
	m_Vmin = m_Vmax = m_Hmin = m_Hmax = 0;
}

CGridWnd::~CGridWnd()
{
}

BEGIN_MESSAGE_MAP(CGridWnd, CSplitterWnd)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEACTIVATE()
	ON_MESSAGE(WM_HUBBLE_GETNODE, OnGetWebRTObj)
	ON_MESSAGE(WM_COSMOSMSG, OnWebRTMsg)
	ON_MESSAGE(WM_TGM_SETACTIVEPAGE, OnActiveTangramObj)
	ON_MESSAGE(WM_HOSTNODEFORSPLITTERCREATED, OnSplitterCreated)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

// CGridWnd diagnostics

#ifdef _DEBUG
void CGridWnd::AssertValid() const
{
	//CSplitterWnd::AssertValid();
}

#ifndef _WIN32_WCE
void CGridWnd::Dump(CDumpContext& dc) const
{
	CSplitterWnd::Dump(dc);
}
#endif
#endif //_DEBUG

BOOL CGridWnd::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	if (CWnd::OnNotify(wParam, lParam, pResult))
		return TRUE;

	// route commands to the splitter to the parent frame window
	//*pResult = EnsureParentFrame()->SendMessage(WM_NOTIFY, wParam, lParam);
	return true;
}

void CGridWnd::TrackRowSize(int y, int row)
{
	ASSERT_VALID(this);
	ASSERT(m_nRows > 1);

	CPoint pt(0, y);
	ClientToScreen(&pt);
	GetPane(row, 0)->ScreenToClient(&pt);
	m_pRowInfo[row].nIdealSize = pt.y;      // new size
	if (pt.y < m_pRowInfo[row].nMinSize)
	{
		// resized too small
		m_pRowInfo[row].nIdealSize = 0; // make it go away
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteRow(row);
	}
	else if (m_pRowInfo[row].nCurSize + m_pRowInfo[row + 1].nCurSize
		< pt.y + m_pRowInfo[row + 1].nMinSize)
	{
		// not enough room for other pane
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteRow(row + 1);
	}
	if (m_pHostXobj && row != m_nRows - 1)
	{
		ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane

		CRect rectInside;
		GetInsideRect(rectInside);

		int i;
		int _nSize = rectInside.Height();
		CSplitterWnd::CRowColInfo* pInfo;

		if (_nSize < 0)
			_nSize = 0;  // if really too small, layout as zero size

		for (i = 0, pInfo = m_pRowInfo; i < m_nRows - 1; i++, pInfo++)
		{
			if (pInfo->nIdealSize < pInfo->nMinSize)
				pInfo->nIdealSize = 0;      // too small to see
			_nSize -= pInfo->nIdealSize;
		}
		_nSize -= (m_nRows - 1) * m_cxSplitterGap;
		pInfo->nCurSize = _nSize;
		pInfo->nIdealSize = _nSize;
	}
}

void CGridWnd::TrackColumnSize(int x, int col)
{
	ASSERT_VALID(this);
	ASSERT(m_nCols > 1);

	CPoint pt(x, 0);
	ClientToScreen(&pt);
	GetPane(0, col)->ScreenToClient(&pt);
	m_pColInfo[col].nIdealSize = pt.x;      // new size
	if (pt.x < m_pColInfo[col].nMinSize)
	{
		// resized too small
		m_pColInfo[col].nIdealSize = 0; // make it go away
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteColumn(col);
	}
	else if (m_pColInfo[col].nCurSize + m_pColInfo[col + 1].nCurSize
		< pt.x + m_pColInfo[col + 1].nMinSize)
	{
		// not enough room for other pane
		if (GetStyle() & SPLS_DYNAMIC_SPLIT)
			DeleteColumn(col + 1);
	}
	if (m_pHostXobj)
	{
		if (col != m_nCols - 1)
		{
			ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane

			CRect rectInside;
			GetInsideRect(rectInside);

			int i;
			int _nSize = rectInside.Width();
			CSplitterWnd::CRowColInfo* pInfo;

			if (_nSize < 0)
				_nSize = 0;  // if really too small, layout as zero size

			for (i = 0, pInfo = m_pColInfo; i < m_nCols - 1; i++, pInfo++)
			{
				if (pInfo->nIdealSize < pInfo->nMinSize)
					pInfo->nIdealSize = 0;      // too small to see
				_nSize -= pInfo->nIdealSize;
			}
			_nSize -= (m_nCols - 1) * m_cxSplitterGap;
			pInfo->nCurSize = _nSize;
			pInfo->nIdealSize = _nSize;
		}
		else
		{
			TRACE(L"");
		}
	}
}

LRESULT CGridWnd::OnWebRTMsg(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case 1992:
		return 0;
		break;
	case 1993:
	{
		//fix bug for .net Control or Window Form
		switch (wParam)
		{
		case 1:
		{
			bInited = true;
			::PostMessage(m_hWnd, WM_COSMOSMSG, 2, 1993);
			return 0;
		}
		break;
		case 2:
		{
			m_pXobj->m_pXobjShareData->m_pNucleus->HostPosChanged();
			return 0;
		}
		break;
		case 3:
		{
			RecalcLayout();
			return 0;
		}
		break;
		}
		return 0;
	}
	break;
	case 20210202:
	{
		HWND hWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(QueryType::RecalcLayout, m_hWnd);
		if (::IsWindow(hWnd))
		{
			WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(hWnd, _T("WebRTFrameWndInfo"));
			if (pWebRTFrameWndInfo)
			{
				HWND hClient = pWebRTFrameWndInfo->m_hClient;//0315
				INucleus* pGalaxy = nullptr;
				g_pSpaceTelescope->GetNucleus((__int64)hClient, &pGalaxy);
				if (pGalaxy)
				{
					CNucleus* _pGalaxy = (CNucleus*)pGalaxy;
					_pGalaxy->HostPosChanged();
				}
			}
		}
		m_pXobj->m_pXobjShareData->m_pNucleus->ModifyStyle(0, WS_CLIPCHILDREN);
		break;
	}
	break;
	}
	if (wParam == 0 || wParam == 0x01000)
		return 0;
	return CWnd::DefWindowProc(WM_COSMOSMSG, wParam, lParam);
}

LRESULT CGridWnd::OnActiveTangramObj(WPARAM wParam, LPARAM lParam)
{
	RecalcLayout();
	m_pXobj->m_pXobjShareData->m_pNucleus->HostPosChanged();
	::InvalidateRect(::GetParent(m_hWnd), nullptr, true);
	return -1;
}

LRESULT CGridWnd::OnSplitterCreated(WPARAM wParam, LPARAM lParam)
{
	int _nWidth = 0;
	SetColumnInfo(lParam, m_nHostWidth >= 0 ? m_nHostWidth : 0, _nWidth);
	SetRowInfo(wParam, m_nHostHeight >= 0 ? m_nHostHeight : 0, _nWidth);
	//SetColumnInfo(lParam, (m_nHostWidth>=0)? m_nHostWidth:0, _nWidth);
	//SetRowInfo(wParam, (m_nHostHeight>=0)? m_nHostHeight:0, _nWidth);
	return 0;
}

void CGridWnd::StartTracking(int ht)
{
	ASSERT_VALID(this);
	if (ht == noHit)
		return;

	HWND hWnd = m_pXobj->m_pXobjShareData->m_pNucleus->m_pNuclei->m_hWnd;
	bool bMdiChild = (::GetWindowLong(hWnd, GWL_EXSTYLE) & WS_EX_MDICHILD);
	ModifyStyle(WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0);
	//if (bMdiChild || ::GetParent(hWnd) == NULL)
	//	::BringWindowToTop(hWnd);

	GetInsideRect(m_rectLimit);

	if (ht >= splitterIntersection1 && ht <= splitterIntersection225)
	{
		// split two directions (two tracking rectangles)
		int row = (ht - splitterIntersection1) / 15;
		int col = (ht - splitterIntersection1) % 15;

		GetHitRect(row + vSplitterBar1, m_rectTracker);
		int yTrackOffset = m_ptTrackOffset.y;
		m_bTracking2 = true;
		GetHitRect(col + hSplitterBar1, m_rectTracker2);
		m_ptTrackOffset.y = yTrackOffset;
	}
	else if (ht == bothSplitterBox)
	{
		// hit on splitter boxes (for keyboard)
		GetHitRect(vSplitterBox, m_rectTracker);
		int yTrackOffset = m_ptTrackOffset.y;
		m_bTracking2 = true;
		GetHitRect(hSplitterBox, m_rectTracker2);
		m_ptTrackOffset.y = yTrackOffset;

		// center it
		m_rectTracker.OffsetRect(0, m_rectLimit.Height() / 2);
		m_rectTracker2.OffsetRect(m_rectLimit.Width() / 2, 0);
	}
	else
	{
		// only hit one bar
		GetHitRect(ht, m_rectTracker);
	}

	// steal focus and capture
	SetCapture();
	SetFocus();

	// make sure no updates are pending
	RedrawWindow(NULL, NULL, /*RDW_ERASE | RDW_FRAME | RDW_INVALIDATE |*/ RDW_ALLCHILDREN | RDW_UPDATENOW);

	// set tracking state and appropriate cursor
	m_bTracking = true;
	OnInvertTracker(m_rectTracker);
	if (m_bTracking2)
		OnInvertTracker(m_rectTracker2);
	m_htTrack = ht;
}

void CGridWnd::StopTracking(BOOL bAccept)
{
	if (!m_bTracking)
		return;

	HWND hWnd = m_pXobj->m_pXobjShareData->m_pNucleus->m_pNuclei->m_hWnd;
	bool bMdiChild = (::GetWindowLong(hWnd, GWL_EXSTYLE) & WS_EX_MDICHILD);

	CNucleus* pGalaxy = m_pXobj->m_pXobjShareData->m_pNucleus;
	if (::IsWindowVisible(pGalaxy->m_hWnd) && pGalaxy->m_nGalaxyType == CtrlBarGalaxy)
		pGalaxy->SetFocus();
	ModifyStyle(WS_CLIPCHILDREN, WS_CLIPSIBLINGS);

	CSplitterWnd::StopTracking(bAccept);

	if (bAccept)
	{
		pGalaxy->UpdateVisualWPFMap(::GetParent(m_hWnd), false);
		HWND h = ::GetParent(m_hWnd);
		if (h)
		{
			LRESULT lRes = ::SendMessage(h, WM_HUBBLE_GETNODE, 0, 0);
			if (lRes)
			{
				CXobj* pRetNode = (CXobj*)lRes;
				if (pRetNode && pRetNode->m_nViewType == Grid)
				{
					CNucleus* pGalaxy = pRetNode->m_pXobjShareData->m_pNucleus;
					pGalaxy->HostPosChanged();
				}
			}
		}

		CWebView* pWebWnd = nullptr;
		if (pGalaxy->m_pWebViewWnd)
		{
			pWebWnd = pGalaxy->m_pWebViewWnd;
			HWND hPWnd = ::GetParent(pWebWnd->m_hWnd);
			//::SendMessage(hPWnd, WM_BROWSERLAYOUT, 0, 4);
			::PostMessage(hPWnd, WM_BROWSERLAYOUT, 0, 7);
		}
		RecalcLayout();
		CCloudMDIFrame* pMdiParent = m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent;
		if (pMdiParent == nullptr)
		{
			if (m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebViewWnd && m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebViewWnd->m_pChromeRenderFrameHost)
			{
				HWND hBrowser = m_pXobj->m_pXobjShareData->m_pNucleus->m_pWebViewWnd->m_pChromeRenderFrameHost->GetHostBrowserWnd();
				auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
				if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
				{
					CBrowser* pBrowser = (CBrowser*)it->second;
					m_pXobj->m_pXobjShareData->m_pNucleus->m_pHostWebBrowserWnd = pBrowser;
					if (pBrowser->m_pMDIParent)
						m_pXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent = pMdiParent = pBrowser->m_pMDIParent;
					else if (pBrowser->m_pParentXobj && pBrowser->m_pParentXobj->m_pParentWinFormWnd)
					{
						if (pGalaxy->m_pParentWinForm == nullptr)
						{
							pGalaxy->m_pParentWinForm = pBrowser->m_pParentXobj->m_pParentWinFormWnd;
							if (pGalaxy->m_pParentWinForm->m_bMdiForm)
								pGalaxy->m_pParentMDIWinForm = pGalaxy->m_pParentWinForm;
						}
					}
					::PostMessage(hBrowser, WM_BROWSERLAYOUT, 0, 7);
				}
			}
		}
		if (pMdiParent)
		{
			pMdiParent->m_pHostBrowser->m_bSZMode = true;
			::SendMessage(pMdiParent->m_pHostBrowser->m_hWnd, WM_BROWSERLAYOUT, 0, 7);
			::PostMessage(pMdiParent->m_hWnd, WM_QUERYAPPPROXY, 0, 20210215);
		}

		if (pGalaxy->m_pParentMDIWinForm)
		{
			::SendMessage(pGalaxy->m_pParentMDIWinForm->m_hMDIClient, WM_COSMOSMSG, 0, 20180115);
		}
		else
		{
			CXobj* pClientObj = m_pXobj->m_pRootObj->GetVisibleChildByName(_T("hostclient"));
			if (pClientObj)
			{
				CBrowser* pBrowser = pClientObj->m_pXobjShareData->m_pNucleus->m_pHostWebBrowserWnd;
				if (pClientObj && pBrowser && pBrowser->m_pParentXobj)
				{
					g_pSpaceTelescope->ModifyBindingXobj(pBrowser->m_pParentXobj->m_pXobjShareData->m_pNucleus, pClientObj);
					::SendMessage(pBrowser->m_pParentXobj->m_pXobjShareData->m_pNucleus->m_hWnd, WM_COSMOSMSG, 0, 20180115);
				}
			}
		}
		HWND hTop = ::GetAncestor(m_hWnd, GA_ROOT);
		::RedrawWindow(hTop, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN /*| RDW_UPDATENOW*/);
	}
}

void CGridWnd::PostNcDestroy()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	delete m_pXobj;
	CSplitterWnd::PostNcDestroy();
	delete this;
}

// Generic routine:
//  for X direction: pInfo = m_pColInfo, nMax = m_nMaxCols, nSize = cx
//  for Y direction: pInfo = m_pRowInfo, nMax = m_nMaxRows, nSize = cy
void CGridWnd::_LayoutRowCol(CSplitterWnd::CRowColInfo* pInfoArray, int nMax, int nSize, int nSizeSplitter, CXobj* pHostNode, bool bCol)
{
	ASSERT(pInfoArray != NULL);
	ASSERT(nMax > 0);
	if (nSizeSplitter < 0)
		nSizeSplitter = 0;
	//ASSERT(nSizeSplitter > 0);

	CSplitterWnd::CRowColInfo* pInfo;
	CSplitterWnd::CRowColInfo* pInfoHost = nullptr;
	int i;

	if (nSize < 0)
		nSize = 0;  // if really too small, layout as zero size

	// start with ideal sizes
	int _indexHost = -1;
	int _nSize = nSize;
	if (pHostNode)
	{
		if (bCol)
		{
			_indexHost = pHostNode->m_nCol;
		}
		else
			_indexHost = pHostNode->m_nRow;
	}
	if (_indexHost != -1)
		pInfoHost = &pInfoArray[_indexHost];

	for (i = 0, pInfo = pInfoArray; i < nMax; i++, pInfo++)
	{
		if (pInfo->nIdealSize < pInfo->nMinSize)
			pInfo->nIdealSize = 0;      // too small to see
		pInfo->nCurSize = pInfo->nIdealSize;
		if (_indexHost != -1)
		{
			if (_indexHost != i)
			{
				_nSize -= pInfo->nIdealSize;
				if (pInfo->nIdealSize == 0)
				{
					if (bCol)
					{
						_nSize -= m_nLastWidth;
						pInfo->nIdealSize = m_nLastWidth;
						m_nLastWidth = 0;
					}
					else
					{
						_nSize -= m_nLastHeight;
						pInfo->nIdealSize = m_nLastHeight;
						m_nLastHeight = 0;
					}
				}
			}
		}
		if (i == nMax - 1)
		{
			if (_indexHost != -1 && pInfoHost)
			{
				if (_indexHost != nMax - 1)
				{
					_nSize -= (nMax - 1) * nSizeSplitter;
					if (_nSize < 0)
						_nSize = 0;
					pInfoHost->nCurSize = _nSize;
				}
				else
					pInfoHost->nCurSize = INT_MAX;// ; _nSize // last row/column takes the rest
				if (bCol)
					m_nHostWidth = _nSize;
				else
					m_nHostHeight = _nSize;
			}
			else
				pInfo->nCurSize = INT_MAX;  // last row/column takes the rest
		}
	}

	for (i = 0, pInfo = pInfoArray; i < nMax; i++, pInfo++)
	{
		ASSERT(nSize >= 0);
		if (nSize == 0)
		{
			// no more room (set pane to be invisible)
			pInfo->nCurSize = 0;
			continue;       // don't worry about splitters
		}
		else if (nSize < pInfo->nMinSize && i != 0)
		{
			// additional panes below the recommended minimum size
			//   aren't shown and the size goes to the previous pane
			pInfo->nCurSize = 0;

			// previous pane already has room for splitter + border
			//   add remaining size and remove the extra border
			(pInfo - 1)->nCurSize += nSize + afxData.cxBorder2;
			nSize = 0;
		}
		else
		{
			// otherwise we can add the second pane
			ASSERT(nSize > 0);
			if (pInfo->nCurSize == 0)
			{
				// too small to see
				if (i != 0)
					pInfo->nCurSize = 0;
			}
			else if (nSize < pInfo->nCurSize)
			{
				// this row/col won't fit completely - make as small as possible
				pInfo->nCurSize = nSize;
				nSize = 0;
			}
			else
			{
				// can fit everything
				nSize -= pInfo->nCurSize;
			}
		}

		// see if we should add a splitter
		ASSERT(nSize >= 0);
		if (i != nMax - 1)
		{
			// should have a splitter
			if (nSize > nSizeSplitter)
			{
				nSize -= nSizeSplitter; // leave room for splitter + border
				ASSERT(nSize > 0);
			}
			else
			{
				pInfo->nCurSize += nSize;
				if (pInfo->nCurSize > (nSizeSplitter - afxData.cxBorder2))
					pInfo->nCurSize -= (nSizeSplitter - afxData.cyBorder2);
				nSize = 0;
			}
		}
	}
}

// repositions client area of specified window
// assumes everything has WS_BORDER or is inset like it does
//  (includes scroll bars)
void CGridWnd::_DeferClientPos(AFX_SIZEPARENTPARAMS* lpLayout, CWnd* pWnd, int x, int y, int cx, int cy, BOOL bScrollBar)
{
	ASSERT(pWnd != NULL);
	ASSERT(pWnd->m_hWnd != NULL);
	CRect rect(x, y, x + cx, y + cy);

	// adjust for 3d border (splitter windows have implied border)
	if ((pWnd->GetExStyle() & WS_EX_CLIENTEDGE) ||
		pWnd->IsKindOf(RUNTIME_CLASS(CSplitterWnd)))
		rect.InflateRect(afxData.cxBorder2, afxData.cyBorder2);

	// first check if the new rectangle is the same as the current
	CRect rectOld;
	pWnd->GetWindowRect(rectOld);
	pWnd->GetParent()->ScreenToClient(&rectOld);
	if (rect != rectOld)
	{
		ASSERT(pWnd->m_hWnd != NULL);
		ASSERT(rect != NULL);
		HWND hWndParent = ::GetParent(pWnd->m_hWnd);
		ASSERT(hWndParent != NULL);

		if (lpLayout != NULL && lpLayout->hDWP == NULL)
			return;

		// first check if the new rectangle is the same as the current
		CRect rectOld;
		::GetWindowRect(pWnd->m_hWnd, rectOld);
		::ScreenToClient(hWndParent, &rectOld.TopLeft());
		::ScreenToClient(hWndParent, &rectOld.BottomRight());
		if (::EqualRect(rectOld, rect))
			return;     // nothing to do

		// try to use DeferWindowPos for speed, otherwise use SetWindowPos
		if (lpLayout != NULL)
		{
			lpLayout->hDWP = ::DeferWindowPos(lpLayout->hDWP, pWnd->m_hWnd, NULL,
				rect.left, rect.top, rect.right - rect.left,
				rect.bottom - rect.top, SWP_NOACTIVATE | SWP_NOZORDER);
		}
		else
		{
			::SetWindowPos(pWnd->m_hWnd, NULL, rect.left, rect.top, rect.right - rect.left,
				rect.bottom - rect.top,
				SWP_NOACTIVATE | SWP_NOZORDER);
		}
	}
	else
	{
		::PostMessage(pWnd->m_hWnd, WM_SPLITTERREPOSITION, 0, 0);
	}
}

void CGridWnd::RecalcLayout()
{
	ASSERT_VALID(this);
	ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane||::IsWindowVisible(m_hWnd) == FALSE
	if (m_bCreated == false || GetDlgItem(IdFromRowCol(0, 0)) == NULL)
		return;
	_RecalcLayout();
	m_pXobj->m_pXobjShareData->m_pNucleus->UpdateVisualWPFMap(m_hWnd, false);
}

void CGridWnd::_RecalcLayout()
{
	ASSERT_VALID(this);
	ASSERT(m_nRows > 0 && m_nCols > 0); // must have at least one pane

	if (m_nMaxCols >= 2)
	{
		int LimitWidth = 0;
		int LimitWndCount = 0;
		int Width = 0;
		RECT SplitterWndRect;
		GetWindowRect(&SplitterWndRect);
		Width = SplitterWndRect.right - SplitterWndRect.left - m_nMaxCols * m_cxSplitterGap - LimitWidth + m_cxBorder * m_nMaxCols;
		if (Width < 0)
			return;
	}
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CRect rectClient;
	GetClientRect(rectClient);
	rectClient.InflateRect(-m_cxBorder, -m_cyBorder);

	CRect rectInside;
	GetInsideRect(rectInside);

	// layout columns (restrict to possible sizes)
	_LayoutRowCol(m_pColInfo, m_nCols, rectInside.Width(), m_cxSplitterGap, m_pHostXobj, true);
	_LayoutRowCol(m_pRowInfo, m_nRows, rectInside.Height(), m_cySplitterGap, m_pHostXobj, false);

	// give the hint for the maximum number of HWNDs
	AFX_SIZEPARENTPARAMS layout;
	layout.hDWP = ::BeginDeferWindowPos((m_nCols + 1) * (m_nRows + 1) + 1);

	//BLOCK: Reposition all the panes
	{
		int x = rectClient.left;
		for (int col = 0; col < m_nCols; col++)
		{
			int cxCol = m_pColInfo[col].nCurSize;
			int y = rectClient.top;
			for (int row = 0; row < m_nRows; row++)
			{
				int cyRow = m_pRowInfo[row].nCurSize;

				CWnd* pWnd = GetDlgItem(IdFromRowCol(row, col));

				//CWnd* pWnd = GetPane(row, col);
				if (pWnd)
					_DeferClientPos(&layout, pWnd, x, y, cxCol, cyRow, FALSE);
				y += cyRow + m_cySplitterGap;
			}
			x += cxCol + m_cxSplitterGap;
		}
	}

	// move and resize all the windows at once!
	if (layout.hDWP == NULL || !::EndDeferWindowPos(layout.hDWP))
		TRACE(traceAppMsg, 0, "Warning: DeferWindowPos failed - low system resources.\n");

	// invalidate all the splitter bars (with NULL pDC)
	DrawAllSplitBars(NULL, rectInside.right, rectInside.bottom);
	::InvalidateRect(m_hWnd, nullptr, false);
}

BOOL CGridWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_pXobj = g_pSpaceTelescope->m_pActiveXobj;
	m_pXobj->m_pHostWnd = this;
	m_pXobj->m_nViewType = Grid;
	m_pXobj->m_nID = nID;
	m_pXobj->m_pDisp = nullptr;

	int r, g, b;
	CComBSTR bstrVal(L"");
	m_pXobj->get_Attribute(CComBSTR("lefttopcolor"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("RGB(%d,%d,%d)"), &r, &g, &b);
		rgbLeftTop = RGB(r, g, b);
	}
	else
	{
		rgbLeftTop = RGB(240, 240, 240);
	}

	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR("rightbottomcolor"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("RGB(%d,%d,%d)"), &r, &g, &b);
		rgbRightBottom = RGB(r, g, b);
	}
	else
	{
		rgbRightBottom = RGB(240, 240, 240);
	}
	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR(L"middlecolor"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		_stscanf_s(CString(bstrVal), _T("RGB(%d,%d,%d)"), &r, &g, &b);
		rgbMiddle = RGB(r, g, b);
	}
	else
	{
		rgbMiddle = RGB(240, 240, 240);
	}

	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR(L"splitterwidth"), &bstrVal);
	m_cxSplitterGap = m_cySplitterGap = m_cxSplitter = m_cySplitter = !CString(bstrVal).IsEmpty() ? _ttoi(CString(bstrVal)) : 7;

	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR(L"borderwidth"), &bstrVal);
	m_cxBorder = m_cyBorder = !CString(bstrVal).IsEmpty() ? _ttoi(CString(bstrVal)) : 2;

	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR(L"vmin"), &bstrVal);
	m_Vmin = !CString(bstrVal).IsEmpty() ? _ttoi(CString(bstrVal)) : 0;

	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR(L"vmax"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		m_Vmax = _ttoi(CString(bstrVal));
		if (m_Vmax <= 0)
			m_Vmax = 65535;
	}
	else
		m_Vmax = 65535;
	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR(L"hmin"), &bstrVal);
	m_Hmin = !CString(bstrVal).IsEmpty() ? _ttoi(CString(bstrVal)) : 0;

	bstrVal.Empty();
	m_pXobj->get_Attribute(CComBSTR(L"hmax"), &bstrVal);
	if (!CString(bstrVal).IsEmpty())
	{
		m_Hmax = _ttoi(CString(bstrVal));
		if (m_Hmax <= 0)
			m_Hmax = 65535;
	}
	else
		m_Hmax = 65535;

	m_pXobj->m_nRows = m_pXobj->m_pHostParse->attrInt(TGM_ROWS, 0);
	m_pXobj->m_nCols = m_pXobj->m_pHostParse->attrInt(TGM_COLS, 0);

	m_nMasterRow = m_pXobj->m_pHostParse->attrInt(L"masterrow", -1);
	m_nMasterCol = m_pXobj->m_pHostParse->attrInt(L"mastercol", -1);

	if (nID == 0)
		nID = 1;

	if (CreateStatic(pParentWnd, m_pXobj->m_nRows, m_pXobj->m_nCols, dwStyle, nID))
	{
		m_pXobj->NodeCreated();
		CString strWidth = m_pXobj->m_pHostParse->attr(TGM_WIDTH, _T(""));
		strWidth += _T(",");
		CString strHeight = m_pXobj->m_pHostParse->attr(TGM_HEIGHT, _T(""));
		strHeight += _T(",");

		int nWidth, nHeight, nPos;
		CString strW, strH, strOldWidth, strName = _T("");

		strOldWidth = strWidth;
		vector<CTangramXmlParse*> vecParse;
		long nSize = m_pXobj->m_pHostParse->GetCount();
		for (int i = 0; i < nSize; i++)
		{
			CTangramXmlParse* _pChild = m_pXobj->m_pHostParse->GetChild(i);
			if (_pChild->name().CompareNoCase(TGM_XOBJ) == 0)
				vecParse.push_back(_pChild);
		}
		nSize = vecParse.size();
		int nIndex = 0;
		CTangramXmlParse* pSubItem = vecParse[nIndex];
		if (pSubItem == nullptr)
		{
			strName.Format(_T("%s_splitterchild_%i"), m_pXobj->m_strName, 0);
			pSubItem = m_pXobj->m_pHostParse->AddNode(strName);
			vecParse.push_back(pSubItem);
		}
		for (int i = 0; i < m_pXobj->m_nRows; i++)
		{
			nPos = strHeight.Find(_T(","));
			strH = strHeight.Left(nPos);
			strHeight = strHeight.Mid(nPos + 1);
			nHeight = _ttoi(strH);
			m_nLastHeight = nHeight;

			strWidth = strOldWidth;
			for (int j = 0; j < m_pXobj->m_nCols; j++)
			{
				nPos = strWidth.Find(_T(","));
				strW = strWidth.Left(nPos);
				strWidth = strWidth.Mid(nPos + 1);
				nWidth = _ttoi(strW);
				m_nLastWidth = nWidth;
				CXobj* pObj = new CComObject<CXobj>;
				pObj->m_pRootObj = m_pXobj->m_pRootObj;
				pObj->m_pHostParse = pSubItem;
				pObj->m_pParentObj = m_pXobj;

				m_pXobj->AddChildNode(pObj);
				pObj->m_nRow = i;
				pObj->m_nCol = j;
				pObj->InitWndXobj();

				if (m_nMasterRow == i && m_nMasterCol == j)
				{
					m_pHostXobj = pObj;
				}

				if (pObj->m_pObjClsInfo)
				{
					pObj->m_nWidth = nWidth;
					pObj->m_nHeigh = nHeight;
					if (pContext->m_pNewViewClass == nullptr)
						pContext->m_pNewViewClass = RUNTIME_CLASS(CXobjWnd);
					CreateView(pObj->m_nRow, pObj->m_nCol, pObj->m_pObjClsInfo, CSize(max(pObj->m_nWidth, m_Hmin), max(pObj->m_nHeigh, m_Vmin)), pContext);
				}
				nIndex++;
				if (nIndex < nSize)
				{
					pSubItem = vecParse[nIndex];
				}
				else
				{
					if (nIndex < m_pXobj->m_nCols * m_pXobj->m_nRows)
					{
						strName.Format(_T("%s_splitterchild_%i"), m_pXobj->m_strName, nIndex);
						pSubItem = m_pXobj->m_pHostParse->AddNode(strName);
						vecParse.push_back(pSubItem);
					}
				}
			}
		}
		SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOREDRAW);
		if (m_pXobj->m_pXobjShareData->m_pNuclei)
			m_pXobj->m_pXobjShareData->m_pNuclei->Fire_NodeCreated(m_pXobj);

		SetWindowText(m_pXobj->m_strNodeName);
		m_bCreated = true;
		if (m_pHostXobj == nullptr)
		{
			CXobj* pHostNode = nullptr;
			CXobj* pParent = nullptr;
			CNucleus* pGalaxy = m_pXobj->m_pXobjShareData->m_pNucleus;
			bool bHasHostView = false;
			if (pGalaxy->m_pBindingXobj)
			{
				pHostNode = pGalaxy->m_pBindingXobj;
				if (::IsChild(m_hWnd, pHostNode->m_pHostWnd->m_hWnd))
				{
					bHasHostView = true;
					pParent = pHostNode->m_pParentObj;
					while (pParent != m_pXobj)
					{
						pHostNode = pParent;
						pParent = pHostNode->m_pParentObj;
					}
				}
			}
			if (pHostNode && ::IsChild(m_hWnd, pHostNode->m_pHostWnd->m_hWnd))
				m_pHostXobj = pHostNode;
		}
		_RecalcLayout();

		return true;
	}
	return false;
}

LRESULT CGridWnd::OnGetWebRTObj(WPARAM wParam, LPARAM lParam)
{
	if (m_pXobj)
		return (LRESULT)m_pXobj;
	return (long)CWnd::DefWindowProc(WM_HUBBLE_GETNODE, wParam, lParam);;
}

void CGridWnd::OnPaint()
{
	ASSERT_VALID(this);
	CPaintDC dc(this);

	CRect rectClient;
	GetClientRect(&rectClient);

	CRect rectInside;
	GetInsideRect(rectInside);
	rectInside.InflateRect(4, 4);


	// draw the splitter boxes
	if (m_bHasVScroll && m_nRows < m_nMaxRows)
	{
		OnDrawSplitter(&dc, splitBox, CRect(rectInside.right, rectClient.top, rectClient.right, rectClient.top + m_cySplitter));
	}

	if (m_bHasHScroll && m_nCols < m_nMaxCols)
	{
		OnDrawSplitter(&dc, splitBox,
			CRect(rectClient.left, rectInside.bottom,
				rectClient.left + m_cxSplitter, rectClient.bottom));
	}

	// extend split bars to window border (past margins)
	DrawAllSplitBars(&dc, rectInside.right, rectInside.bottom);
	// draw splitter intersections (inside only)
	GetInsideRect(rectInside);
	dc.IntersectClipRect(rectInside);
	CRect rect;
	rect.top = rectInside.top;
	for (int row = 0; row < m_nRows - 1; row++)
	{
		rect.top += m_pRowInfo[row].nCurSize + m_cyBorderShare;
		rect.bottom = rect.top + m_cySplitter;
		rect.left = rectInside.left;
		for (int col = 0; col < m_nCols - 1; col++)
		{
			rect.left += m_pColInfo[col].nCurSize + m_cxBorderShare;
			rect.right = rect.left + m_cxSplitter;
			OnDrawSplitter(&dc, splitIntersection, rect);
			rect.left = rect.right + m_cxBorderShare;
		}
		rect.top = rect.bottom + m_cxBorderShare;
	}
}

void CGridWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rectArg)
{
	if (pDC == nullptr)
	{
		RedrawWindow(rectArg, NULL, RDW_INVALIDATE | RDW_NOCHILDREN);
		return;
	}
	ASSERT_VALID(pDC);
	;

	// otherwise, actually draw
	CRect rect = rectArg;
	switch (nType)
	{
	case splitBorder:
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);
		rect.InflateRect(-AFX_CX_BORDER, -AFX_CY_BORDER);
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);

		return;

	case splitIntersection:
		break;

	case splitBox:
	{
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);
		rect.InflateRect(-AFX_CX_BORDER, -AFX_CY_BORDER);
		pDC->Draw3dRect(rect, rgbLeftTop, rgbRightBottom);
		rect.InflateRect(-AFX_CX_BORDER, -AFX_CY_BORDER);
		break;
	}
	// fall through...
	case splitBar:
	{
		pDC->FillSolidRect(rect, rgbMiddle);
		//pDC->FillSolidRect(rect, rgbMiddle);
		if ((rect.bottom - rect.top) > (rect.right - rect.left))
		{
			rect.bottom -= 1;
			rect.top += 1;
		}
		else
		{
			rect.right -= 1;
			rect.left += 1;
		}
	}
	break;

	default:
		ASSERT(false);  // unknown splitter type
	}
}

BOOL CGridWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = g_pSpaceTelescope->m_lpszSplitterClass;
	cs.style |= WS_CLIPSIBLINGS;
	return CSplitterWnd::PreCreateWindow(cs);
}

void CGridWnd::DrawAllSplitBars(CDC* pDC, int cxInside, int cyInside)
{
	//ColRect.clear();
	//RowRect.clear();
	ASSERT_VALID(this);

	int col;
	int row;
	CRect rect;

	// draw pane borders
	GetClientRect(rect);
	int x = rect.left;
	for (col = 0; col < m_nCols; col++)
	{
		int cx = m_pColInfo[col].nCurSize + 2 * m_cxBorder;
		if (col == m_nCols - 1 && m_bHasVScroll)
			cx += afxData.cxVScroll - CX_BORDER;
		int y = rect.top;
		for (row = 0; row < m_nRows; row++)
		{
			int cy = m_pRowInfo[row].nCurSize + 2 * m_cyBorder;
			if (row == m_nRows - 1 && m_bHasHScroll)
				cy += afxData.cyHScroll - CX_BORDER;
			OnDrawSplitter(pDC, splitBorder, CRect(x, y, x + cx, y + cy));
			y += cy + m_cySplitterGap - 2 * m_cyBorder;
		}
		x += cx + m_cxSplitterGap - 2 * m_cxBorder;
	}


	// draw column split bars
	GetClientRect(rect);
	rect.left += m_cxBorder;
	for (col = 0; col < m_nCols - 1; col++)
	{
		rect.left += m_pColInfo[col].nCurSize + m_cxBorderShare;
		rect.right = rect.left + m_cxSplitter;
		if (rect.left > cxInside)
			break;      // stop if not fully visible
		//ColumnsplitBar = rect;
		//ColRect.push_back(rect);
		OnDrawSplitter(pDC, splitBar, rect);

		rect.left = rect.right + m_cxBorderShare;
	}

	// draw row split bars
	GetClientRect(rect);
	rect.top += m_cyBorder;
	for (row = 0; row < m_nRows - 1; row++)
	{
		rect.top += m_pRowInfo[row].nCurSize + m_cyBorderShare;
		rect.bottom = rect.top + m_cySplitter;
		if (rect.top > cyInside)
			break;      // stop if not fully visible
		//RowsplitBar = rect;
		//RowRect.push_back(rect);
		OnDrawSplitter(pDC, splitBar, rect);

		rect.top = rect.bottom + m_cyBorderShare;
	}
}

CWnd* CGridWnd::GetActivePane(int* pRow, int* pCol)
{
	CWnd* pView = nullptr;
	pView = GetFocus();

	// make sure the pane is a child pane of the splitter
	if (pView != nullptr && !IsChildPane(pView, pRow, pCol))
		pView = nullptr;


	return pView;
}

int CGridWnd::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (g_pSpaceTelescope->m_pActiveHtmlWnd)
	{
		g_pSpaceTelescope->m_pActiveHtmlWnd = nullptr;
	}

	CNucleus* pGalaxy = m_pXobj->m_pXobjShareData->m_pNucleus;

	if (pGalaxy->m_pNuclei->m_pUniverseAppProxy)
	{
		HWND hMenuWnd = pGalaxy->m_pNuclei->m_pUniverseAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
	else if ((long)(g_pSpaceTelescope->m_pActiveAppProxy) > 1)
	{
		HWND hMenuWnd = g_pSpaceTelescope->m_pActiveAppProxy->GetActivePopupMenu(nullptr);
		if (::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}

	return MA_ACTIVATE;// CSplitterWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

void CGridWnd::Save()
{
	CString strWidth = _T("");
	CString strHeight = _T("");

	int minCx, minCy;

	for (int i = 0; i < m_pXobj->m_nRows; i++)
	{
		int iHeight;
		CString strH;
		GetRowInfo(i, iHeight, minCy);
		strH.Format(_T("%d,"), iHeight);

		strHeight += strH;
	}

	for (int j = 0; j < m_pXobj->m_nCols; j++)
	{
		int iWidth;
		CString strW;
		GetColumnInfo(j, iWidth, minCx);
		strW.Format(_T("%d,"), iWidth);

		strWidth += strW;
	}

	m_pXobj->put_Attribute(CComBSTR(TGM_HEIGHT), CComBSTR(strHeight));
	m_pXobj->put_Attribute(CComBSTR(TGM_WIDTH), CComBSTR(strWidth));
}

void CGridWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	if (point.x < m_Hmin && point.y < m_Vmin)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmin, m_Vmin));
	}

	else if (point.x < m_Hmin && point.y > m_Vmin && point.y < m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmin, point.y));
	}

	else if (point.x < m_Hmin && point.y > m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmin, m_Vmax));
	}

	else if (point.x > m_Hmax && point.y < m_Vmin)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmax, m_Vmin));
	}

	else if (point.x > m_Hmax && point.y > m_Vmin && point.y < m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmax, point.y));
	}

	else if (point.x > m_Hmax && point.y > m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(m_Hmax, m_Vmax));
	}

	else if (point.x > m_Hmin && point.x < m_Hmax && point.y > m_Vmax)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(point.x, m_Vmax));
	}
	else if (point.x > m_Hmin && point.x < m_Hmax && point.y < m_Vmin)
	{
		CSplitterWnd::OnMouseMove(nFlags, CPoint(point.x, m_Vmin));
	}
	else
	{
		CSplitterWnd::OnMouseMove(nFlags, point);
	}

	//CDC *pDC = GetDC();
	//for (int col = 0; col < m_nCols - 1; col++)
	//{
	//	if(PtInRect( &ColRect.at(col),point) && bColMoving == 0)
	//	{
	//		pDC->FillSolidRect(&(ColRect.at(col)),rgbMiddle);
	//	}
	//}

	//for (int row = 0; row < m_nRows - 1; row++)
	//{
	//	if(PtInRect( &RowRect.at(row),point))
	//	{
	//		pDC->FillSolidRect(&(RowRect.at(row)), rgbMiddle);
	//	}
	//}
}

void CGridWnd::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);
	if (m_pColInfo != nullptr)
		RecalcLayout();
}

void CGridWnd::OnDestroy()
{
	m_pXobj->Fire_Destroy();
	HANDLE hData = RemoveProp(m_hWnd, _T("WebRTInfo"));
	if (hData)
	{
		WebRTInfo* pInfo = (WebRTInfo*)hData;
		delete pInfo;
	}
	__super::OnDestroy();
}

void CGridWnd::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CSplitterWnd::OnShowWindow(bShow, nStatus);

	if (bShow) {
		this->RecalcLayout();
	}
}
