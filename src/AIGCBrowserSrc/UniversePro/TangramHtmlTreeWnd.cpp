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

#include "stdafx.h"
#pragma warning(disable : 4786)
#include "UniverseApp.h"
#include "Cosmos.h"
#include "TangramHtmlTreeWnd.h"
#include "XNamedColors.h"
#include "TangramXmlParse.h"
#include "TangramTreeNode.h"
#include "XHtmlDraw.h"
#include "CreateCheckboxImageList.h"
#include "tangramtreeview.h"
#include "XobjWnd.h"
#include "Xobj.h"
#include "WinNucleus.h"
#include "TangramBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef __noop
#if _MSC_VER < 1300
#define __noop ((void)0)
#endif
#endif

#undef TRACE
#define TRACE __noop


//=============================================================================
// if you want to see the TRACE output, uncomment this line:
#include "XTrace.h"
//=============================================================================


//=============================================================================
// REGISTERED XHTMLTREE MESSAGES
//=============================================================================
UINT WM_XHTMLTREE_CHECKBOX_CLICKED = ::RegisterWindowMessage(_T("WM_XHTMLTREE_CHECKBOX_CLICKED"));
UINT WM_XHTMLTREE_ITEM_EXPANDED    = ::RegisterWindowMessage(_T("WM_XHTMLTREE_ITEM_EXPANDED"));
UINT WM_XHTMLTREE_DISPLAY_TOOLTIP  = ::RegisterWindowMessage(_T("WM_XHTMLTREE_DISPLAY_TOOLTIP"));
UINT WM_XHTMLTREE_INIT_TOOLTIP     = ::RegisterWindowMessage(_T("WM_XHTMLTREE_INIT_TOOLTIP"));
#ifdef XHTMLDRAGDROP
UINT WM_XHTMLTREE_BEGIN_DRAG       = ::RegisterWindowMessage(_T("WM_XHTMLTREE_BEGIN_DRAG"));
UINT WM_XHTMLTREE_END_DRAG         = ::RegisterWindowMessage(_T("WM_XHTMLTREE_END_DRAG"));
UINT WM_XHTMLTREE_DROP_HOVER       = ::RegisterWindowMessage(_T("WM_XHTMLTREE_DROP_HOVER"));
#endif // XHTMLDRAGDROP
#ifdef XHTMLTREE_DEMO
UINT WM_XHTMLTREE_SCROLL_SPEED     = ::RegisterWindowMessage(_T("WM_XHTMLTREE_SCROLL_SPEED"));
#endif // XHTMLTREE_DEMO

#pragma warning(disable : 4996)	// disable bogus deprecation warning

const UINT HOT_TIMER			= 1;
const UINT LBUTTONDOWN_TIMER	= 2;
const UINT CTRL_UP_TIMER		= 3;
const UINT SHIFT_UP_TIMER		= 4;
const UINT SELECT_TIMER			= 5;
const UINT TOOLTIP_BASE_ID		= 10000;
const DWORD MIN_HOVER_TIME		= 1500;		// 1.5 seconds
const int SCROLL_ZONE			= 16;		// pixels for scrolling

int CTangramXHtmlTreeNode::m_nCount		= 0;

//=============================================================================
BEGIN_MESSAGE_MAP(CTangramHtmlTreeWnd, CTreeCtrl)
//=============================================================================
	//{{AFX_MSG_MAP(CTangramHtmlTreeWnd)
	//ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_SYSCOLORCHANGE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEACTIVATE()
	ON_WM_SIZE()
	ON_WM_RBUTTONDOWN()
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
	ON_NOTIFY_REFLECT_EX(NM_CLICK, OnClick)
	ON_NOTIFY_REFLECT_EX(NM_RCLICK, OnRClick)
	ON_NOTIFY_REFLECT_EX(NM_DBLCLK, OnDblclk)
	ON_NOTIFY_REFLECT_EX(TVN_BEGINLABELEDIT, OnBeginlabeledit)
	ON_NOTIFY_REFLECT_EX(TVN_ENDLABELEDIT, OnEndlabeledit)
	ON_MESSAGE(WM_HUBBLE_DESIGNERCMD, OnDesignNode)
	ON_MESSAGE(WM_HUBBLE_UPDATENODE,OnUpdateXMLNode)
	ON_MESSAGE(WM_INSERTTREENODE,OnInsertXMLNode)	
	ON_MESSAGE(WM_HUBBLE_GETTREEINFO,OnGetWebRTXmlParse)
	ON_MESSAGE(WM_REFRESHDATA,OnInsertData)	
	ON_MESSAGE(WM_GETSELECTEDNODEINFO,OnGetSelectedNodeInfo)	
	//}}AFX_MSG_MAP

#ifdef XHTMLDRAGDROP
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
#endif // XHTMLDRAGDROP

#ifdef XHTMLTOOLTIPS
	ON_NOTIFY(UDM_TOOLTIP_DISPLAY, NULL, OnDisplayTooltip)	
#else
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnToolTipText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipText)
#endif // XHTMLTOOLTIPS

	ON_NOTIFY_REFLECT_EX(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT_EX(TVN_SELCHANGING, OnSelchanging)
END_MESSAGE_MAP()

//=============================================================================
CTangramHtmlTreeWnd::CTangramHtmlTreeWnd()
//=============================================================================
  :	m_bDestroyingTree(false),
	m_bFirstTime(true),
	m_bSmartCheck(false),
	m_bCheckBoxes(false),
	m_bSelectFollowsCheck(true),
	m_bReadOnly(false),
	m_bHtml(true),
	m_bStripHtml(false),
	m_bLogFont(false),
	m_bToolTip(false),
	m_bDragging(false),
	m_bAutoScroll(true),
	m_bImages(true),
	m_pToolTip(0),
	m_hAnchorItem(0),
	m_hHotItem(0),
	m_hPreviousItem(0),
	m_hItemButtonDown(0),
	m_hPreviousDropItem(0),
	m_nPadding(0),
	m_nImageHeight(16),
	m_nToolCount(0),
	m_nDefaultTipWidth(0),
	m_nScrollTime(0),
	m_crCustomWindow(COLOR_NONE),
	m_crCustomWindowText(COLOR_NONE),
	m_nHorzPos(0),
	m_dwDropHoverTime(0),
	m_nNoDropCursor(0),
	m_nDropCopyCursor(0),
	m_nDropMoveCursor(0),
	m_hNoDropCursor(0),
	m_hDropCopyCursor(0),
	m_hDropMoveCursor(0),
	m_hPreviousCursor(0),
	m_hCurrentCursor(0),
	m_dwDragOps(XHTMLTREE_DO_DEFAULT)
{
	TRACE(_T("in CTangramHtmlTreeWnd::CTangramHtmlTreeWnd\n"));
	memset(&m_lf, 0, sizeof(m_lf));
	SetColors();
	m_pHostXmlParse = NULL;
	m_hPreviousCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);

	m_hFirstRoot				= 0;
	m_bNoHandle					= false;
	m_bAttached					= false;
	m_nHeight					= 0;
	m_hCurSelectedItem			= NULL;
	m_pNucleus				= NULL;
	m_pDualTangramFrame			= NULL;
	m_pHostWnd					= NULL;
	m_hDualWnd					= NULL;
	m_hAsynHostWnd				= NULL;	
	m_strDefaultXTML			= _T("");
	m_strURL					= _T("");
	m_strMainKey				= _T("");
	m_strMenuScript				= _T("");
	m_strSelectNodeInfo			= _T("");
	m_strBases					= _T("");
	m_strMenu					= _T("");
	m_strMultSelectedMenu		= _T("");
	m_strMultSelectedMenu2		= _T("");
	m_strImageURL				= _T("");
	m_strImageTarget			= _T("");
	m_strOutRelationWnds		= _T("");
	m_strInnerRelationNodes		= _T("");
	m_pObj = new CComObject<CTangramTreeView>;
	m_pObj->AddRef();
	m_pObj->m_pWebRTHtmlTreeWnd = this;
	//m_Links.SetAppCommands()
}

//=============================================================================
CTangramHtmlTreeWnd::~CTangramHtmlTreeWnd()
//=============================================================================
{
	if (m_pHostXmlParse)
	{
		//m_pHostXmlParse->Reflash();
		delete m_pHostXmlParse;
	}
	if (m_pToolTip)
		delete m_pToolTip;
	m_pToolTip = 0;

	if (m_StateImage.GetSafeHandle())
		m_StateImage.DeleteImageList();

	if (m_hNoDropCursor)
		DestroyCursor(m_hNoDropCursor);
	m_hNoDropCursor = NULL;

	if (m_hDropCopyCursor)
		DestroyCursor(m_hDropCopyCursor);
	m_hDropCopyCursor = NULL;

	if (m_hDropMoveCursor)
		DestroyCursor(m_hDropMoveCursor);
	m_hDropMoveCursor = NULL;

	TRACE(_T("CTangramXHtmlTreeNode::nCount=%d\n"), CTangramXHtmlTreeNode::m_nCount);
}

//=============================================================================
void CTangramHtmlTreeWnd::PostNcDestroy()
//=============================================================================
{
	CTreeCtrl::PostNcDestroy();
	delete this;
}


//=============================================================================
CTangramHtmlTreeWnd& CTangramHtmlTreeWnd::Initialize(BOOL bCheckBoxes /*= false*/, 
								   BOOL bToolTip /*= false*/)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::Initialize\n"));
	m_bDestroyingTree = true;

	DeleteAllItems();

	if (m_pToolTip)
		delete m_pToolTip;
	m_pToolTip = 0;

	SetImageList(NULL, TVSIL_STATE);

	if (m_StateImage.GetSafeHandle())
		m_StateImage.DeleteImageList();

	m_bHtml               = true;
	m_bFirstTime          = true;
	m_bSelectFollowsCheck = true;
	m_bLogFont            = false;
	m_bSmartCheck         = false;
	m_bDestroyingTree	  = false;
	m_bCheckBoxes         = bCheckBoxes;
	m_bToolTip            = bToolTip;
	m_nPadding            = 0;
	m_hAnchorItem         = 0;
	m_hHotItem            = 0;
	m_nImageHeight        = 16;
	memset(&m_lf, 0, sizeof(m_lf));

	SetColors();

	if (m_bToolTip)
	{
		TRACE(_T("creating tooltip\n"));
#ifdef XHTMLTOOLTIPS
		m_pToolTip = new CPPToolTip;
#else
		m_pToolTip = new CToolTipCtrl;
#endif // XHTMLTOOLTIPS
		if (m_pToolTip)
		{
			AfxGetModuleState()->m_hCurrentInstanceHandle = theApp.m_hInstance;
			m_pToolTip->Create(this);
		}
	}

	if (m_bCheckBoxes)
		CreateCheckboxImages();


	return *this;
}

//=============================================================================
// PreCreateWindow() is called when CTangramHtmlTreeWnd is used in a view.
//
BOOL CTangramHtmlTreeWnd::PreCreateWindow(CREATESTRUCT& cs) 
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::PreCreateWindow\n"));

	// style must include "no tooltips"
	cs.style |= TVS_NOTOOLTIPS;

	return CTreeCtrl::PreCreateWindow(cs);
}

//=============================================================================
void CTangramHtmlTreeWnd::PreSubclassWindow()
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::PreSubclassWindow\n"));
	DWORD dwStyle = GetStyle();

	if (dwStyle & TVS_CHECKBOXES)
		m_bCheckBoxes = true;

	// these styles must not be set
	ModifyStyle(TVS_CHECKBOXES, TVS_NOTOOLTIPS);

#ifdef XHTMLDRAGDROP
	ModifyStyle(TVS_DISABLEDRAGDROP, 0);
#else
	ModifyStyle(0, TVS_DISABLEDRAGDROP);
#endif // XHTMLDRAGDROP

	if (m_bCheckBoxes)
		CreateCheckboxImages();

	CTreeCtrl::PreSubclassWindow();
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::PreTranslateMessage(MSG* pMsg) 
//=============================================================================
{
	// allow edit control to receive messages, if 
	// label is being edited
	if (GetEditControl() && 
		((pMsg->message == WM_CHAR) ||
		 (pMsg->message == WM_KEYDOWN) ||
		 GetKeyState(VK_CONTROL)))
	{
		::TranslateMessage(pMsg);
		::DispatchMessage(pMsg);
		return true;
	}

	if (m_pToolTip && IsWindow(m_pToolTip->m_hWnd))
	{
		m_pToolTip->RelayEvent(pMsg);
	}

	//=========================================================================
	// WM_CHAR
	//=========================================================================
	if (pMsg->message == WM_CHAR)
	{
		if ((pMsg->wParam == VK_SPACE) && m_bCheckBoxes && !m_bReadOnly)
		{
			HTREEITEM hItem = GetSelectedItem();
			
			CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
	
			if (pXTCD && !pXTCD->m_bSeparator)		//+++1.6
			{
				SetCheck(hItem, !pXTCD->m_bChecked);
			}

			return true;
		}
	}

	//=========================================================================
	// WM_KEYDOWN
	//=========================================================================
	if (pMsg->message == WM_KEYDOWN)
	{
		TRACE(_T("WM_KEYDOWN: lParam=0x%X\n"), pMsg->lParam);

#ifdef XHTMLDRAGDROP
		//=====================================================================
		// VK_ESCAPE while dragging
		//=====================================================================
		if ((pMsg->wParam == VK_ESCAPE) && m_bDragging)
		{
			TRACE(_T("ESC seen during drag\n"));
			EndDragScroll();
			SendRegisteredMessage(WM_XHTMLTREE_END_DRAG, 0, 0);
			return true;
		}

		//=====================================================================
		// VK_CONTROL while dragging
		//=====================================================================
		if ((pMsg->wParam == VK_CONTROL) && 
			(m_dwDragOps & XHTMLTREE_DO_CTRL_KEY))
		{
			// check if Ctrl key down for first time
			if ((pMsg->lParam & 0x40000000) == 0)
			{
				if (IsOverItem() && m_bDragging)
				{
					SetDragCursor();
				}

				SetTimer(CTRL_UP_TIMER, 100, NULL);
			}
		}

		//=====================================================================
		// VK_SHIFT while dragging
		//=====================================================================
		if ((pMsg->wParam == VK_SHIFT) && 
			(m_dwDragOps & XHTMLTREE_DO_SHIFT_KEY))
		{
			// check if Shift key down for first time
			if ((pMsg->lParam & 0x40000000) == 0)
			{
				HTREEITEM hItem = IsOverItem();
				if (hItem && m_bDragging)
				{
					if (IsSeparator(hItem))					//+++1.6
					{
						SelectDropTarget(NULL);
						SetInsertMark(0, 0);
						SetInsertMark(hItem, true);
					}
					else
					{
						SetInsertMark(0, 0);
						SelectDropTarget(hItem);
					}
				}
				SetTimer(SHIFT_UP_TIMER, 100, NULL);
			}
		}
#endif // XHTMLDRAGDROP

		//=====================================================================
		// VK_RIGHT or VK_LEFT
		//=====================================================================
		if ((pMsg->wParam == VK_RIGHT) || (pMsg->wParam == VK_LEFT))
		{
			BOOL bRight = pMsg->wParam == VK_RIGHT;

			HTREEITEM hItem = GetSelectedItem();
			
			CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
		
			if (pXTCD && pXTCD->m_bEnabled && pXTCD->m_nChildren)
			{
				BOOL m_bExpanded = pXTCD->m_bExpanded;
				BOOL bOldExpanded = pXTCD->m_bExpanded;
				if (!m_bExpanded && bRight)
					m_bExpanded = true;
				if (m_bExpanded && !bRight)
					m_bExpanded = false;
				if (bOldExpanded != m_bExpanded)
				{
					Expand(hItem, m_bExpanded ? TVE_EXPAND : TVE_COLLAPSE);
					return true;
				}
			}
		}

		//=====================================================================
		// VK_DOWN or VK_UP
		//=====================================================================
		if ((pMsg->wParam == VK_DOWN) || (pMsg->wParam == VK_UP))
		{
			BOOL bDown = pMsg->wParam == VK_DOWN;

			HTREEITEM hItem = GetSelectedItem();
			
			if (hItem)
			{
				HTREEITEM hItemNew = bDown ? GetNextVisibleItem(hItem) : 
											 GetPrevVisibleItem(hItem);

				CTangramXHtmlTreeNode *pXTCD = NULL;

				while (hItemNew)
				{
					pXTCD = GetItemDataStruct(hItemNew);
			
					if (pXTCD && pXTCD->m_bEnabled)
						break;

					// next item is not enabled, just skip it
					hItemNew = bDown ? GetNextVisibleItem(hItemNew) : 
									   GetPrevVisibleItem(hItemNew);
				}

				if (hItemNew)
				{
					SelectItem(hItemNew);
					return true;
				}
			}
		}

		//=====================================================================
		// VK_MULTIPLY
		//=====================================================================
		if (pMsg->wParam == VK_MULTIPLY)
		{
			HTREEITEM hItem = GetSelectedItem();
			
			if (hItem)
			{
				ExpandBranch(hItem);
				EnsureVisible(hItem);
				SendMessage(WM_HSCROLL, SB_LEFT);
				return true;
			}
		}

		//=====================================================================
		// VK_SUBTRACT  VK_ADD
		//=====================================================================
		UINT nCode = 0;
		switch (pMsg->wParam)
		{
			default:			break;
			case VK_SUBTRACT:	nCode = TVE_COLLAPSE; break;
			case VK_ADD:		nCode = TVE_EXPAND; break;
		}
		if (nCode)
		{
			HTREEITEM hItem = GetSelectedItem();
			if (hItem)
			{
				Expand(hItem, nCode);
				return true;	// skip default processing
			}
		}

	}
	return CTreeCtrl::PreTranslateMessage(pMsg);
}

//=============================================================================
void CTangramHtmlTreeWnd::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
//=============================================================================
{
	if(::IsWindowVisible(m_hWnd)==false)
		return;
	NMTVCUSTOMDRAW* pCD = reinterpret_cast<NMTVCUSTOMDRAW*>(pNMHDR);

	CDC* pDC = CDC::FromHandle(pCD->nmcd.hdc);

	HTREEITEM hItem = reinterpret_cast<HTREEITEM> (pCD->nmcd.dwItemSpec);

	// Take the default processing unless we set this to something else below.
	*pResult = CDRF_DODEFAULT;

	// First thing - check the draw stage. If it's the control's prepaint
	// stage, then tell Windows we want messages for every item.

	//=========================================================================
	if (pCD->nmcd.dwDrawStage == CDDS_PREPAINT)	// before the painting cycle begins
	//=========================================================================
	{
		*pResult = CDRF_NOTIFYITEMDRAW /*| CDRF_NOTIFYPOSTPAINT*/;
	}
	//=========================================================================
	else if (pCD->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)	// before an item is drawn
	//=========================================================================
	{
		pCD->clrText = pCD->clrTextBk;	// don't want default drawing -
										// set text color = background color
		if (hItem)
		{
			CRect rectItem1;
			GetItemRect(hItem, &rectItem1, false);	// get rect for item
			if (!IsBadRect(rectItem1))
			{
				CBrush brush(m_crWindow);
				pDC->FillRect(&rectItem1, &brush);		// erase entire background
			}
		}
		*pResult = CDRF_NOTIFYPOSTPAINT | CDRF_NEWFONT;
	}
	//=========================================================================
	else if (pCD->nmcd.dwDrawStage == CDDS_ITEMPOSTPAINT)	// after an item has been drawn
	//=========================================================================
	{
		// by doing the drawing at this stage we avoid having to draw lines, etc.

		if (m_bFirstTime)
		{
			if (m_bToolTip)
				CreateToolTipsForTree();

			CImageList *pImageList = GetImageList(TVSIL_NORMAL);
			if (!pImageList)	//+++1.5
			{
				TRACE(_T("WARNING  no image list, setting m_bImages to false\n"));
				m_bImages = false;
			}
		}

		m_bFirstTime = false;

		CRect rectItem;
		GetItemRect(hItem, &rectItem, false);		// get rect for entire item
		CRect rectText;
		GetItemRect(hItem, &rectText, true);		// get rect for text
		rectText.right = rectItem.right;

		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		// set up colors

		COLORREF crText = m_crWindowText;
		COLORREF crAnchorText = m_crAnchorText;
		COLORREF crBackground = m_crWindow;
		COLORREF crTextBackground = m_crWindow;

		BOOL m_bEnabled = true;

		HTREEITEM hSelected = GetSelectedItem();

		if (pXTCD)
		{
			// try to use colors specified for this item
			pXTCD->ds.bIgnoreColorTag = false;
			crText  = pXTCD->ds.crText;
			crTextBackground = pXTCD->ds.crTextBackground;
			crBackground = pXTCD->ds.crBackground;
			//TRACE(_T("crText=%08X  crBkgnd=%08X ~~~~~\n"), crText, crBackground);
			m_bEnabled = pXTCD->m_bEnabled;
			if ((hItem == hSelected) || 
				(GetItemState(hItem, TVIF_STATE) & TVIS_DROPHILITED))
			{
				crTextBackground = m_crHighlight;
			}
			else
			{
			 	//crTextBackground = COLOR_NONE;
			}

			if (!m_bEnabled)
			{
				crText = crAnchorText = m_crGrayText;
				pXTCD->ds.bIgnoreColorTag = true;
			}
			else if ((hItem == hSelected) || 
				(GetItemState(hItem, TVIF_STATE) & TVIS_DROPHILITED))
			{
				crText = crAnchorText = m_crHighlightText;
				pXTCD->ds.bIgnoreColorTag = true;
			}
			else
			{
			}
		}

		if (crBackground == COLOR_NONE)
			crBackground = m_crWindow;

		if (pXTCD && pXTCD->m_bSeparator)			//+++1.6
		{
			if (crText == COLOR_NONE)
				crText = m_crSeparator;

			if (hItem == hSelected)
				crBackground = m_crHighlight;

			DrawSeparator(pDC, hItem, crText, crBackground, rectText);
		}
		else
		{
			if (crText == COLOR_NONE)
				crText = m_crWindowText;

			CString strText = GetItemText(hItem);

			BOOL bContainsHtml = false;

			// check for html tag and char entity
			if (strText.FindOneOf(_T("<&")) >= 0)
				bContainsHtml = true;

			if (m_bStripHtml && bContainsHtml)
				strText = GetItemText(hItem, true);

#ifdef XHTMLHTML
			if (m_bHtml && bContainsHtml)
				DrawItemTextHtml(pDC, hItem, strText, crText, crTextBackground,
									crBackground, crAnchorText, rectText);
			else
#endif // XHTMLHTML
				DrawItemText(pDC, hItem, strText, crText, crTextBackground, crBackground, rectText);
		}
	
		//*pResult = CDRF_SKIPDEFAULT;	// We've painted everything.
	}
}

void CTangramHtmlTreeWnd::UpdateData(CString strData)
{
	CString strXml = strData;
	CTangramXmlParse* _pHostXmlParse = new CTangramXmlParse();
	if (_pHostXmlParse->LoadXml(strXml))
	{
		DeleteItem(m_hFirstRoot);

		if (m_pHostXmlParse)
		{
			delete m_pHostXmlParse;
		}
		m_pHostXmlParse = _pHostXmlParse;
		m_hFirstRoot = LoadXmlFromXmlParse(m_pHostXmlParse);// , CTangramHtmlTreeWnd::ConvertToUnicode);
		ExpandAll();
		return;
	}
	delete _pHostXmlParse;
}
//=============================================================================
BOOL CTangramHtmlTreeWnd::SelectItem(HTREEITEM hItem)
//=============================================================================
{
	HTREEITEM hPrevItemSel = GetSelectedItem();

	if (hItem == hPrevItemSel)
		return true;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD && pXTCD->m_bEnabled)
	{
		NMTREEVIEW nmtv = { 0 };
		
		nmtv.hdr.hwndFrom = m_hWnd;
		nmtv.hdr.idFrom = GetDlgCtrlID();
		nmtv.hdr.code = TVN_SELCHANGED;
		nmtv.itemNew.hItem = hItem;

		CWnd *pWnd = GetParent();
		if (!pWnd)
			pWnd = GetOwner();
		if (pWnd && ::IsWindow(pWnd->m_hWnd))
		{
			pWnd->SendMessage(WM_NOTIFY, GetDlgCtrlID(), (LPARAM)&nmtv);
		}
	}
	else
	{
		if (hPrevItemSel)
			hItem = hPrevItemSel;
		else
			return true;
	}

	return CTreeCtrl::SelectItem(hItem);
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsSelected(HTREEITEM hItem)
//=============================================================================
{
	BOOL rc = false;

	if (hItem == GetSelectedItem())
		rc = true;

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsEnabled(HTREEITEM hItem)
//=============================================================================
{
	BOOL rc = false;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->m_bEnabled;
	}

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsExpanded(HTREEITEM hItem)
//=============================================================================
{
	BOOL rc = false;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->m_bExpanded && ItemHasChildren(hItem);
	}

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsSeparator(HTREEITEM hItem)			//+++1.6
//=============================================================================
{
	BOOL rc = false;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->m_bSeparator;
	}

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::GetItemPath(HTREEITEM hItem, CStringArray& sa, CPtrArray& items)
//=============================================================================
{
	BOOL rc = false;

	sa.RemoveAll();
	items.RemoveAll();

	if (hItem == NULL)
		hItem = GetRootItem();

	if (hItem)
	{
		CStringArray path;
		CPtrArray htreeitems;

		// get the path in reverse order
		while (hItem)
		{
			CString strText = GetItemText(hItem);

#ifdef XHTMLHTML
			// remove html tags
			CXHtmlDraw hd;
			TCHAR s[200];
			hd.GetPlainText(strText, s, sizeof(s)/sizeof(TCHAR)-1);
			strText = s;
#endif // XHTMLHTML
			path.Add(strText);
			htreeitems.Add(hItem);
			hItem = GetParentItem(hItem);
		}

		int n = (int) path.GetSize();
		if (n)
		{
			// return path in correct order
			for (int i = n-1; i >= 0 ; i--)
			{
				sa.Add(path[i]);
				items.Add(htreeitems[i]);
			}

			rc = true;
		}
	}

	return rc;
}

//=============================================================================
int CTangramHtmlTreeWnd::GetDefaultTipWidth()
//=============================================================================
{
	int nWidth = 200;

	if (m_nDefaultTipWidth == 0)
	{
		// no default width specified, use a heuristic
		CWnd *pWnd = GetParent();
		if (!pWnd)
			pWnd = GetOwner();

		if (pWnd && ::IsWindow(pWnd->m_hWnd))
		{
			CRect rectParent;
			pWnd->GetWindowRect(&rectParent);
			CRect rectTree;
			GetWindowRect(&rectTree);
			int nWidthTree = (3 * rectTree.Width()) / 4;
			int nWidthParent = rectParent.Width() / 2;
			nWidth = (nWidthTree < 200) ? nWidthParent : nWidthTree;
		}
	}
	else
	{
		nWidth = m_nDefaultTipWidth;
	}

	return nWidth;
}

//=============================================================================
void CTangramHtmlTreeWnd::CreateToolTipsForTree()
//=============================================================================
{
	if ((m_pToolTip == 0) || (!IsWindow(m_pToolTip->m_hWnd)))
		return;

#ifdef XHTMLTOOLTIPS
	m_pToolTip->SetNotify(true);
#endif // XHTMLTOOLTIPS

	m_pToolTip->SetMaxTipWidth(GetDefaultTipWidth());

	// first delete all existing tools
	int nCount = m_nToolCount; //m_pToolTip->GetToolCount();
	for (int j = 0; j < nCount; j++)
		m_pToolTip->DelTool(this, TOOLTIP_BASE_ID+j);
	m_nToolCount = 0;

	CRect rect; 
	GetClientRect(rect);

	CRect rectItem;
	GetItemRect(GetFirstVisibleItem(), &rectItem, false);
	ASSERT(!IsBadRect(rectItem));

	rect.top = 0;
	rect.bottom = rect.top + rectItem.Height()-1;
	UINT n = GetVisibleCount();

	// loop to add a tool for each visible item
	UINT i = 0;
	for (i = 0; i < n; i++)
	{
#ifdef XHTMLTOOLTIPS
		PPTOOLTIP_INFO ti;
		ti.nBehaviour = PPTOOLTIP_MULTIPLE_SHOW;
		ti.nIDTool = 123;
		ti.rectBounds = rect;
		ti.sTooltip = "";
		ti.nMask = PPTOOLTIP_MASK_BEHAVIOUR;
		m_pToolTip->AddTool(this, ti);
#else
		m_pToolTip->AddTool(this, LPSTR_TEXTCALLBACK, rect, TOOLTIP_BASE_ID+i);
#endif // XHTMLTOOLTIPS
		rect.top = rect.bottom+1;
		rect.bottom = rect.top + rectItem.Height()-1;
	}
	m_nToolCount = i;

	if (m_pToolTip)
	{
		// allow parent to perform custom initializatio of tooltip
		SendRegisteredMessage(WM_XHTMLTREE_INIT_TOOLTIP, 0, (LPARAM)m_pToolTip);
	}
}

//=============================================================================
// GetNormalImageWidth
// returns:  width - if image is specified
//          -width - TV_NOIMAGE is specified for this item
//               0 - no image list
int CTangramHtmlTreeWnd::GetNormalImageWidth(HTREEITEM hItem)
//=============================================================================
{
	int nWidth = 0;

	CImageList *pImageList = GetImageList(TVSIL_NORMAL);

	if (pImageList && hItem)
	{
		// there is an image list
		
		int nImage = TV_NOIMAGE;
		int nSelectedImage = TV_NOIMAGE;
		GetItemImage(hItem, nImage, nSelectedImage);

		IMAGEINFO ii = { 0 };
		if (pImageList->GetImageInfo(0, &ii))	// use first image width
		{
			nWidth = ii.rcImage.right - ii.rcImage.left;
		}

		if (nImage == TV_NOIMAGE)
			nWidth = -nWidth;
	}

	return nWidth;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::CreateCheckboxImages()
//=============================================================================
{
	CDC *pDC = GetDC();
	ASSERT(pDC);
	BOOL rc = HDCheckboxImageList::CreateCheckboxImageList(pDC, m_StateImage, 
				m_nImageHeight, m_crWindow);
	ReleaseDC(pDC);
	//SetImageList(&this->m_Images, TVSIL_STATE);
	SetImageList(&m_StateImage, TVSIL_STATE);
	return rc;
}

//=============================================================================
int CTangramHtmlTreeWnd::DrawItemText(CDC *pDC, 
							 HTREEITEM hItem, 
							 LPCTSTR lpszText,
							 COLORREF crText, 
							 COLORREF crTextBackground, 
							 COLORREF crBackground, 
							 CRect& rect)
//=============================================================================
{
	ASSERT(pDC);
	ASSERT(hItem);

	if (!pDC || !hItem)
	{
		TRACE(_T("ERROR bad parameters\n"));
		return 0;
	}

	if (IsBadRect(rect))
	{
		return 0;
	}

	int nWidth = 0;

	CRect rectText(rect);

	pDC->FillSolidRect(&rectText, crBackground);

	CString str = lpszText;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD && !str.IsEmpty())
	{
		UINT uFormat = DT_VCENTER | DT_SINGLELINE | DT_LEFT | DT_NOPREFIX;

		CFont *pOldFont = NULL;
		CFont font;

		CFont *pFont = pDC->GetCurrentFont();
		if (pFont)
		{
			LOGFONT lf;
			pFont->GetLogFont(&lf);

			lf.lfWeight    = pXTCD->ds.bBold ? FW_BOLD : FW_NORMAL;
			lf.lfUnderline = (BYTE) pXTCD->ds.bUnderline;
			lf.lfItalic    = (BYTE) pXTCD->ds.bItalic;
			lf.lfStrikeOut = (BYTE) pXTCD->ds.bStrikeThrough;

			font.CreateFontIndirect(&lf);
			pOldFont = pDC->SelectObject(&font);
		}

		pDC->SetTextColor(crText);
		if (crTextBackground == COLOR_NONE)
			pDC->SetBkColor(crBackground);
		else
			pDC->SetBkColor(crTextBackground);

		CRect rectOut(rectText);
		pDC->DrawText(str, &rectOut, uFormat | DT_CALCRECT);
		pDC->DrawText(str, &rectOut, uFormat);
		rectOut.InflateRect(m_nPadding, 0);
		nWidth = rectOut.right;

		pXTCD->ds.nRightX = rectOut.right;

		if (pOldFont)
			pDC->SelectObject(pOldFont);
	}

	return nWidth;
}

#ifdef XHTMLHTML
//=============================================================================
int CTangramHtmlTreeWnd::DrawItemTextHtml(CDC *pDC, 
								 HTREEITEM hItem, 
								 LPCTSTR lpszText,
								 COLORREF crText, 
								 COLORREF crTextBackground, 
								 COLORREF crBackground,
								 COLORREF crAnchorText, 
								 CRect& rect)
//=============================================================================
{
	ASSERT(pDC);
	ASSERT(hItem);

	if (!pDC || !hItem)
	{
		TRACE(_T("ERROR bad parameters\n"));
		return 0;
	}

	if (IsBadRect(rect))
	{
		return 0;
	}

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (!pXTCD)
	{
		TRACE(_T("ERROR no CTangramXHtmlTreeNode\n"));
		return 0;
	}

	COLORREF crTextOld, crTextBackgroundOld, crBackgroundOld, crAnchorTextOld;

	crTextOld = pXTCD->ds.crText;
	crTextBackgroundOld = pXTCD->ds.crTextBackground;
	crBackgroundOld = pXTCD->ds.crBackground;
	crAnchorTextOld = pXTCD->ds.crAnchorText;

	pXTCD->ds.crText         = crText;
	pXTCD->ds.crTextBackground   = crTextBackground;
	pXTCD->ds.crBackground   = crBackground;
	pXTCD->ds.crAnchorText   = crAnchorText;
	pXTCD->ds.rect           = rect;
	pXTCD->ds.bUseEllipsis   = false;

	if (m_bLogFont)
	{
		pXTCD->ds.bLogFont = true;
		memcpy(&pXTCD->ds.lf, &m_lf, sizeof(LOGFONT));
	}

	CString strText = lpszText;
	TRACE(_T("in CTangramHtmlTreeWnd::DrawItemTextHtml: <%s> crText=%06X  crBk=%06X\n"), strText, crText, crBackground);

	CXHtmlDraw htmldraw;

	int nWidth = htmldraw.Draw(pDC->m_hDC, strText, &pXTCD->ds, hItem == m_hAnchorItem);

	pXTCD->ds.crText = crTextOld;
	pXTCD->ds.crTextBackground = crTextBackgroundOld;
	pXTCD->ds.crBackground = crBackgroundOld;
	pXTCD->ds.crAnchorText = crAnchorTextOld;

	return nWidth;
}
#endif // XHTMLHTML

//=============================================================================
int CTangramHtmlTreeWnd::DrawSeparator(CDC *pDC,						//+++1.6
							  HTREEITEM hItem, 
							  COLORREF crText, 
							  COLORREF crBackground, 
							  CRect& rect)
//=============================================================================
{
	ASSERT(pDC);
	ASSERT(hItem);

	if (!pDC || !hItem)
	{
		TRACE(_T("ERROR bad parameters\n"));
		return 0;
	}

	if (IsBadRect(rect))
	{
		return 0;
	}

	int nWidth = 0;

	CRect rectSep(rect);
	pDC->FillSolidRect(&rectSep, crBackground);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		CPen pen(PS_SOLID, 1, crText);
		CPen * pOldPen = pDC->SelectObject(&pen);

		TRACE(_T("drawing separator\n"));

		rectSep.right -= 1;
		rectSep.left  -= 2;
		rectSep.top   += rectSep.Height()/2;

		pDC->MoveTo(rectSep.left, rectSep.top);
		pDC->LineTo(rectSep.right, rectSep.top);

		pDC->SelectObject(pOldPen);

		nWidth = rectSep.right;

		pXTCD->ds.nRightX = rectSep.right;
	}

	return nWidth;
}

//=============================================================================
void CTangramHtmlTreeWnd::OnDestroy()
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnDestroy\n"));
	delete m_pObj;
	DeleteMap();
	CTreeCtrl::OnDestroy();
}

//=============================================================================
void CTangramHtmlTreeWnd::DeleteMap()
//=============================================================================
{
	BOOL bOldDestroyingTree = m_bDestroyingTree;
	m_bDestroyingTree = true;
	int n = (int)m_DataMap.GetCount();
	POSITION pos = m_DataMap.GetStartPosition();
	HTREEITEM hItem = 0;
	CTangramXHtmlTreeNode *pXTCD = NULL;

	if (n > 0)
	{
		do
		{
			m_DataMap.GetNextAssoc(pos, hItem, pXTCD);

			if (hItem && pXTCD)
				delete pXTCD;

			n--;
		} while (pos != NULL);
	}

	ASSERT(n == 0);

	m_DataMap.RemoveAll();
	if (m_pHostXmlParse)
	{
		//m_pHostXmlParse->Reflash();
		delete m_pHostXmlParse;
		m_pHostXmlParse = NULL;
	}
	m_bDestroyingTree = bOldDestroyingTree;
}

//=============================================================================
// GetNextItem - Get next item in sequence (as if tree was completely expanded)
//   see http://www.codeguru.com/Cpp/controls/treeview/treetraversal/article.php/c645
//   hItem   - The reference item
//   Returns - The item immediately below the reference item
HTREEITEM CTangramHtmlTreeWnd::GetNextItem(HTREEITEM hItem)
//=============================================================================
{
	HTREEITEM hItemNext = NULL;

	ASSERT(hItem);

	if (hItem)
	{
		if (ItemHasChildren(hItem))
		{
			hItemNext = GetChildItem(hItem);	// first child
		}

		if (hItemNext == NULL)
		{
			// return next sibling item - go up the tree to find 
			// a parent's sibling if needed.
			while ((hItemNext = GetNextSiblingItem(hItem)) == NULL)
			{
				if ((hItem = GetParentItem(hItem)) == NULL)
					return NULL;
			}
		}
	}

	return hItemNext;
}

//=============================================================================
// GetNextItem  - Get previous item as if outline was completely expanded
// Returns      - The item immediately above the reference item
// hItem        - The reference item
HTREEITEM CTangramHtmlTreeWnd::GetPrevItem(HTREEITEM hItem)
//=============================================================================
{
	HTREEITEM hItemPrev;

	hItemPrev = GetPrevSiblingItem(hItem);
	if (hItemPrev == NULL)
		hItemPrev = GetParentItem(hItem);
	else
		hItemPrev = GetLastItem(hItemPrev);
	return hItemPrev;
}

//=============================================================================
// GetLastItem  - Gets last item in the branch
// Returns      - Last item
// hItem        - Node identifying the branch. NULL will 
//                return the last item in outine
HTREEITEM CTangramHtmlTreeWnd::GetLastItem(HTREEITEM hItem)
//=============================================================================
{
	// Last child of the last child of the last child ...
	HTREEITEM hItemNext;
	
	if (hItem == NULL)
	{
		// Get the last item at the top level
		hItemNext = GetRootItem();
		while (hItemNext)
		{
			hItem = hItemNext;
			hItemNext = GetNextSiblingItem(hItemNext);
		}
	}
	
	while (ItemHasChildren(hItem))
	{
		hItemNext = GetChildItem(hItem);
		while (hItemNext)
		{
			hItem = hItemNext;
			hItemNext = GetNextSiblingItem(hItemNext);
		}
	}
	
	return hItem;
}

//=============================================================================
// FindItem  - Finds an item that contains the search string
//
// http://www.codeguru.com/cpp/controls/treeview/treetraversal/article.php/c673/
//
// Returns        - Handle to the item or NULL
//
// str            - String to search for
// bCaseSensitive - Should the search be case sensitive
// bDownDir       - Search direction - true for down
// bWholeWord     - True if search should match whole words
// hItem          - Item to start searching from. NULL for
//                  currently selected item
HTREEITEM CTangramHtmlTreeWnd::FindItem(CString &str, 
							   BOOL bCaseSensitive /*= false*/, 
							   BOOL bDownDir /*= true*/, 
							   BOOL bWholeWord /*= false*/, 
							   BOOL bWrap /* = true */,
							   HTREEITEM hItem /*= NULL*/)
//=============================================================================
{
	int lenSearchStr = str.GetLength();
	if (lenSearchStr == 0) 
		return NULL;

	HTREEITEM hItemSel = hItem ? hItem : GetSelectedItem();
	HTREEITEM hItemCur = bDownDir ? GetNextItem(hItemSel) : GetPrevItem(hItemSel);
	CString sSearch = str;

	if (hItemCur == NULL)
	{
		if (bDownDir)  
			hItemCur = GetRootItem();
		else 
			hItemCur = GetLastItem(NULL);
	}

	if (!bCaseSensitive)
		sSearch.MakeLower();

	while (hItemCur && (hItemCur != hItemSel))
	{
		CString sItemText = GetItemText(hItemCur);

#ifdef XHTMLHTML

		TCHAR s[200];

		// remove html tags
		CXHtmlDraw hd;
		hd.GetPlainText(sItemText, s, sizeof(s)/sizeof(TCHAR)-1);

		sItemText = s;

#endif // XHTMLHTML

		if (!bCaseSensitive)
			sItemText.MakeLower();

		int n = 0;
		while ((n = sItemText.Find(sSearch)) != -1)
		{
			// search string found
			if (bWholeWord)
			{
				// check preceding char
				if (n != 0)
				{
					if (isalpha(sItemText[n-1]) || 
						sItemText[n-1] == '_')
					{
						// Not whole word
						sItemText = sItemText.Right(sItemText.GetLength() - 
											n - lenSearchStr);
						continue;
					}
				}

				// check succeeding char
				if (sItemText.GetLength() > (n + lenSearchStr) &&
					(isalpha(sItemText[n+lenSearchStr]) ||
					sItemText[n+lenSearchStr] == '_' ))
				{
					// Not whole word
					sItemText = sItemText.Right(sItemText.GetLength() 
									- n - sSearch.GetLength());
					continue;
				}
			}

			if (IsFindValid( hItemCur))
				return hItemCur;
			else 
				break;
		}

		hItemCur = bDownDir ? GetNextItem(hItemCur) : GetPrevItem(hItemCur);

		if ((hItemCur == NULL) && !bWrap)
			break;

		if ((hItemCur == NULL) && (hItemSel != NULL))	// wrap only if there 
														// is a selected item
		{
			if (bDownDir)  
				hItemCur = GetRootItem();
			else 
				hItemCur = GetLastItem(NULL);
		}
	}
	return NULL;
}

//=============================================================================
// IsFindValid	- Virtual function used by FindItem to allow this
//		  function to filter the result of FindItem
// Returns	- True if item matches the criteria
// Arg		- Handle of the item
BOOL CTangramHtmlTreeWnd::IsFindValid(HTREEITEM)
//=============================================================================
{
	return true;
}

//=============================================================================
void CTangramHtmlTreeWnd::RedrawItem(HTREEITEM hItem)
//=============================================================================
{
	if (hItem)
	{
		CRect rect;
		GetItemRect(hItem, &rect, false);
		InvalidateRect(&rect, false);
		UpdateWindow();
	}
}


int CTangramHtmlTreeWnd::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (m_pHostWnd)
	{
		g_pSpaceTelescope->m_pActiveXobj = m_pHostWnd->m_pXobj;
		g_pSpaceTelescope->m_pNucleus = m_pHostWnd->m_pXobj->m_pXobjShareData->m_pNucleus;
	}
	return MA_ACTIVATE;
	//return CFormView::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

//=============================================================================
// OnMouseMove - handle link underlining and checkbox hot state
void CTangramHtmlTreeWnd::OnMouseMove(UINT nFlags, CPoint point)
//=============================================================================
{
	// hItem will be non-zero if the cursor is anywhere over a valid item
	UINT flags = 0;
	HTREEITEM hItem = HitTest(point, &flags);
	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		int nPos = pXTCD->m_strTangramDataXML.Find(m_strMainKey);
		if(nPos!=-1)
		{
			RECT rc;
			GetItemRect(hItem,&rc,true);
			if(rc.left<=point.x&&point.x<=rc.right&&rc.top<=point.y&&point.y<=rc.bottom)
			{
			}
		}
	}

#ifdef XHTMLDRAGDROP

	if (!m_bDragging && !IsLeftButtonUp() && IsSeparator(hItem))
	{
		// we must send TVN_BEGINDRAG to ourself, since separator has no text
		NMTREEVIEW nmtv = { 0 };
	
		nmtv.hdr.hwndFrom = m_hWnd;
		nmtv.hdr.idFrom = GetDlgCtrlID();
		nmtv.hdr.code = TVN_BEGINDRAG;
		nmtv.itemNew.hItem = hItem;

		SendMessage(WM_NOTIFY, 0, (LPARAM)&nmtv);
	}
	else if (m_bDragging)
	{
		CPoint cursor_point(point);
		ClientToScreen(&cursor_point);

		LRESULT lResult = 0;				// allow drop if lResult is 0

		BOOL bCopyDrag = IsDragCopy();

		if (hItem)
		{
			// allow parent to decide whether to permit drag
			XHTMLTREEDRAGMSGDATA dragdata = { 0 };
			dragdata.m_hItem      = m_hItemButtonDown;
			dragdata.m_hAfter     = hItem;
			dragdata.m_bCopyDrag  = bCopyDrag;

			lResult = SendRegisteredMessage(WM_XHTMLTREE_DROP_HOVER, m_hItemButtonDown, (LPARAM)&dragdata);
		}

		// Check to see if the drag is over an item in the tree
		if (hItem && !lResult)
		{
			if (m_hPreviousDropItem != hItem)
			{
				SetDragCursor();

				SetInsertMark(0, 0);	// remove previous insert mark
				TRACE(_T("Drag target item 0x%X\n"), hItem);

				m_hPreviousDropItem = hItem;
				m_dwDropHoverTime = GetTickCount();

				// check if Shift key down
				if (GetBit(m_dwDragOps, XHTMLTREE_DO_SHIFT_KEY) &&
					(GetAsyncKeyState(VK_SHIFT) < 0))
				{
					TRACE(_T("VK_SHIFT down\n"));
					if (IsSeparator(hItem))					//+++1.6
					{
						SelectDropTarget(NULL);
						SetInsertMark(hItem, true);
					}
					else
					{
						SelectDropTarget(hItem);
					}
				}
				else
				{
					SetInsertMark(hItem, true);
					SelectDropTarget(NULL);
				}
			}
		}
		else	// not over an item
		{
			SetInsertMark(0, 0);	// remove insert mark
			m_hPreviousDropItem = 0;
			if (m_hNoDropCursor)
				SetCursor(m_hNoDropCursor);			// set to no-drop cursor
			else
				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_NO));		// set to no-drop cursor
		}

		SetFocus();
	}
	else 
		
#endif // XHTMLDRAGDROP
		
	if (hItem)
	{
		// if mouse is on a different item, or has moved off state icon
		if ((m_hHotItem && (m_hHotItem != hItem)) || 
			(m_hHotItem && ((flags & TVHT_ONITEMSTATEICON) == 0)))
		{
			int nState = GetStateImage(m_hHotItem);

			// a hot item can only be UNCHECKED, CHECKED, or CHECKED_TRISTATE

			nState &= ~HDCheckboxImageList::HOT_INDEX;

			// remove hot from previous hot item
			SetItemState(m_hHotItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

			m_hHotItem = NULL;
		}

		if ((m_hHotItem == NULL) && (flags & TVHT_ONITEMSTATEICON))
		{
			TRACE(_T("cursor over state image\n"));
			int nState = GetStateImage(hItem);

			if ((nState & HDCheckboxImageList::DISABLED_INDEX) == 0)		// is it enabled?
			{
				// a hot item can only be UNCHECKED, CHECKED, or CHECKED_TRISTATE

				nState |= HDCheckboxImageList::HOT_INDEX;

				// remove hot from previous hot item
				SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

				m_hHotItem = hItem;
				SetTimer(HOT_TIMER, 100, NULL);		// timer in case mouse leaves window
			}
		}

		CRect rect;
		BOOL bOverAnchor = IsOverAnchor(hItem, point, &rect);
		//TRACE(_T("bOverAnchor=%d\n"), bOverAnchor);

#ifdef XHTMLHTML
		if (bOverAnchor)
			m_Links.SetLinkCursor();
#endif // XHTMLHTML

		if ((m_hAnchorItem && (m_hAnchorItem != hItem)) || 
			(m_hAnchorItem && !bOverAnchor))
		{
			TRACE(_T("removing anchor 0x%X-----\n"), m_hAnchorItem);
			GetItemRect(m_hAnchorItem, &rect, false);	// note:  must get entire
														// rect, since text might
														// be shifted left
			m_hAnchorItem = NULL;
			InvalidateRect(&rect, false);
		}
		else if ((m_hAnchorItem == NULL) && bOverAnchor)
		{
			TRACE(_T("adding anchor 0x%X-----\n"), hItem);

			m_hAnchorItem = hItem;
			TRACE(_T("mouse over anchor 0x%X-----\n"), hItem);
			GetItemRect(hItem, &rect, false);	// note:  must get entire
												// rect, since text might
												// be shifted left
			InvalidateRect(&rect, false);
			SetTimer(HOT_TIMER, 80, NULL);		// timer in case mouse leaves window
		}
	}
	
	CTreeCtrl::OnMouseMove(nFlags, point);
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::IsOverItem(LPPOINT lpPoint /*= NULL*/)
//=============================================================================
{
	CPoint point;
	if (lpPoint)
	{
		point = *lpPoint;
	}
	else
	{
		::GetCursorPos(&point);
		ScreenToClient(&point);
	}
	UINT flags = 0;
	HTREEITEM hItem = HitTest(point, &flags);

	return hItem;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsOverAnchor(HTREEITEM hItem, CPoint point, CRect *pRect /*= NULL*/)
//=============================================================================
{
	BOOL rc = false;

	CRect rect(0,0,0,0);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
	
	if (pXTCD && pXTCD->ds.bHasAnchor && pXTCD->m_bEnabled)
	{
		GetItemRect(hItem, &rect, true);

		// set rect to anchor boundaries
		rect.left  = pXTCD->ds.rectAnchor.left;
		rect.right = pXTCD->ds.rectAnchor.right;

		if (rect.PtInRect(point))
		{
			rc = true;
		}
	}

	if (pRect)
		*pRect = rect;

	return rc;
}

//=============================================================================
HCURSOR CTangramHtmlTreeWnd::SetCursor(HCURSOR hCursor)
//=============================================================================
{
	if (hCursor == m_hCurrentCursor)
		return m_hCurrentCursor;

	m_hCurrentCursor = hCursor;

	TRACE(_T("calling ::SetCursor %X\n"), hCursor);

	return ::SetCursor(hCursor);
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsLeftButtonUp()
//=============================================================================
{
	BOOL rc = false;

	SHORT state = 0;
	if (GetSystemMetrics(SM_SWAPBUTTON))		// check if buttons have been swapped
		state = GetAsyncKeyState(VK_RBUTTON);	// buttons swapped, get right button state
	else
		state = GetAsyncKeyState(VK_LBUTTON);

	// if the most significant bit is set, the button is down
	if (state >= 0)
		rc = true;

	return rc;
}

//=============================================================================
// OnTimer - check if mouse has left, turn off underlining and hot state
void CTangramHtmlTreeWnd::OnTimer(UINT_PTR nIDEvent)
//=============================================================================
{
	CPoint point;
	::GetCursorPos(&point);
	ScreenToClient(&point);

	if (nIDEvent == HOT_TIMER)
	{
		// if mouse has left window, turn off hot and anchor highlighting

		CRect rectClient;
		GetClientRect(&rectClient);

		if (!rectClient.PtInRect(point))
		{
			KillTimer(nIDEvent);

			// mouse has left the window

			if (m_hHotItem)
			{
				int nState = GetStateImage(m_hHotItem);

				// a hot item can only be UNCHECKED, CHECKED, or CHECKED_TRISTATE

				nState &= ~HDCheckboxImageList::HOT_INDEX;

				// remove hot from previous hot item
				SetItemState(m_hHotItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

				m_hHotItem = NULL;
			}

			if (m_hAnchorItem)
			{
				// remove underline
				CRect rectAnchor;
				GetItemRect(m_hAnchorItem, &rectAnchor, false);
				m_hAnchorItem = NULL;
				InvalidateRect(&rectAnchor, true);
			}
		}
	}
	else if (nIDEvent == LBUTTONDOWN_TIMER)			// timer set by WM_LBUTTONDOWN
	{
		HTREEITEM hItem = IsOverItem(&point);

		if (IsLeftButtonUp())
		{
			TRACE(_T("mouse button is up >>>>>\n"));

			KillTimer(nIDEvent);

			HTREEITEM hItemSelected = GetSelectedItem();

#ifdef XHTMLDRAGDROP

			if (m_bDragging)				// case 1:  user is dragging
			{
				if (hItem && 
					(hItem != m_hItemButtonDown) && 
					(!IsChildNodeOf(hItem, m_hItemButtonDown)))
				{
					HTREEITEM hAfter = hItem;
					HTREEITEM hParent = GetParentItem(m_hItemButtonDown);
					HTREEITEM hNewParent = GetParentItem(hAfter);
					TRACE(_T("hParent=%X\n"), hParent);

					// check if Shift key down
					if ((m_dwDragOps & XHTMLTREE_DO_SHIFT_KEY) &&
						(GetAsyncKeyState(VK_SHIFT) < 0) &&
						!IsSeparator(hAfter))								//+++1.6
					{
						TRACE(_T("VK_SHIFT down, creating child item\n"));
						hNewParent = hAfter;
						hAfter = TVI_LAST;
					}
					else if (hParent == hAfter)
					{
						// dropping on parent
						hNewParent = hParent;
						hAfter = TVI_FIRST;
					}
					else if (ItemHasChildren(hAfter) && IsExpanded(hAfter))	//+++1.6
					{
						// dropping on node that is expanded
						hNewParent = hAfter;
						hAfter = TVI_FIRST;
					}
					else if (hNewParent == 0)								//+++1.6
					{
						// multiple roots
					}

					StartMoveBranch(m_hItemButtonDown, hNewParent, hAfter);
				}
				else
				{
					TRACE(_T("ERROR can't drop on %X\n"), hItem);
					SendRegisteredMessage(WM_XHTMLTREE_END_DRAG, 0, 0);
				}

				EndDragScroll();
			}
			else 

#endif // XHTMLDRAGDROP
				
			if (hItem && (hItem == hItemSelected)
				&& !IsSeparator(hItem))	// case 2:  user wants to edit a label
			{
				// clicking on a selected item
				CEdit *pEdit = GetEditControl();

				CRect rect;
				GetItemRect(hItem, &rect, true);
				if (rect.PtInRect(point))
				{
					TRACE(_T("sending TVM_EDITLABEL\n"));
					// click on item text, begin edit
					SendMessage(TVM_EDITLABEL, 0, (LPARAM)hItem);
				}
				else if (pEdit && IsWindow(pEdit->m_hWnd))
				{
					TRACE(_T("sending WM_CLOSE to edit box\n"));
					// click outside item text, end edit
					pEdit->SendMessage(WM_CLOSE);
				}
			}
		}

#ifdef XHTMLDRAGDROP

		else		// left button is down
		{
			//TRACE(_T("mouse button is down >>>>>\n"));

			if (m_bDragging)
			{
				// check how long we've been hovering over same item

				if (hItem && (hItem == m_hPreviousDropItem))
				{
					if (GetBit(m_dwDragOps, XHTMLTREE_DO_AUTO_EXPAND))
					{
						// still over same item
						if ((GetTickCount() - m_dwDropHoverTime) > MIN_HOVER_TIME)
						{
							// min hover time has passed, expand node if it has children
							Expand(hItem, TVE_EXPAND);
						}
					}
				}

				if (m_bAutoScroll)
					AutoScroll(hItem);
			}
		}

#endif // XHTMLDRAGDROP

	}

#ifdef XHTMLDRAGDROP

	else if (nIDEvent == CTRL_UP_TIMER)
	{
		// check if Ctrl key down
		if (!IsCtrlDown())
		{
			TRACE(_T("VK_CONTROL up\n"));

			KillTimer(nIDEvent);

			if (IsOverItem() && m_bDragging)
			{
				SetDragCursor();
			}
		}
	}
	else if (nIDEvent == SHIFT_UP_TIMER)
	{
		if ((m_dwDragOps & XHTMLTREE_DO_SHIFT_KEY) &&
			(GetAsyncKeyState(VK_SHIFT) >= 0))
		{
			TRACE(_T("VK_SHIFT up\n"));
			KillTimer(nIDEvent);
			HTREEITEM hItem = IsOverItem();
			if (hItem)
				SetInsertMark(hItem, true);
			SelectDropTarget(NULL);
		}
	}
	else if (nIDEvent == SELECT_TIMER)			// timer set by WM_LBUTTONDOWN
	{
		KillTimer(nIDEvent);
		HTREEITEM hItem = IsOverItem();
		if (hItem)
		{
			SelectItem(hItem);
		}
	}


#endif // XHTMLDRAGDROP

	CTreeCtrl::OnTimer(nIDEvent);
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::OnEraseBkgnd(CDC* pDC)
//=============================================================================
{
	CRect rectClientx;
	GetClientRect(&rectClientx);
	pDC->FillSolidRect(rectClientx, m_crWindow);
	return true;//CTreeCtrl::OnEraseBkgnd(pDC);//true;
}

//=============================================================================
CTangramHtmlTreeWnd& CTangramHtmlTreeWnd::SetCheck(HTREEITEM hItem, BOOL fCheck /*= true*/)
//=============================================================================
{
	ASSERT(hItem);

	if (hItem && m_bCheckBoxes)
	{
		TRACE(_T("in CTangramHtmlTreeWnd::SetCheck: %d  <%s>\n"), fCheck, GetItemText(hItem));
		
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD && pXTCD->m_bEnabled && !pXTCD->m_bSeparator)		//+++1.6
		{
			BOOL bOldChecked = pXTCD->m_bChecked;
			pXTCD->m_bChecked = fCheck;

			CString strID = pXTCD->m_strTangramItemID;
			if(strID!=_T(""))
			{
				if(fCheck)
				{
					m_mapSelectedNodeDic[strID] = pXTCD;
				}
				else
				{
					auto it = m_mapSelectedNodeDic.find(strID);
					if(it!=m_mapSelectedNodeDic.end())
						m_mapSelectedNodeDic.erase(it);
				}
				TRACE(_T("CurentSelected Node Count:%d\n"), m_mapSelectedNodeDic.size());
			}

			UINT nState = GetStateImage(hItem);

			SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

			if (m_bSmartCheck && (bOldChecked != fCheck))
			{
				HTREEITEM hParent = hItem;
				int nCount = 0;
				if (fCheck)
					nCount = pXTCD->m_nChildren - pXTCD->m_nChecked + 1;//bOldCheck ? 1 : 0;
				else
					nCount = -(pXTCD->m_nChecked + 1);//bOldCheck ? 1 : 0);

				SetCheckChildren(hItem, fCheck);

				// find all parents, adjust their checked counts
				TRACE(_T("starting nCount=%d\n"), nCount);
				while ((hParent = GetParentItem(hParent)) != NULL)
				{
					nCount = SetCheckParent(hParent, nCount);
				}
			}

			SendRegisteredMessage(WM_XHTMLTREE_CHECKBOX_CLICKED, hItem, fCheck);
		}
	}

	return *this;
}

//=============================================================================
void CTangramHtmlTreeWnd::SetHotItem(HTREEITEM hItem, UINT nFlags)
//=============================================================================
{
	if (m_hHotItem && (m_hHotItem != hItem))
	{
		int nState = GetStateImage(m_hHotItem);

		// a hot item can only be UNCHECKED, CHECKED, or CHECKED_TRISTATE

		nState &= ~HDCheckboxImageList::HOT_INDEX;

		// remove hot from previous hot item
		SetItemState(m_hHotItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

		m_hHotItem = NULL;
	}

	if (hItem && (m_hHotItem == NULL) && (nFlags & TVHT_ONITEMSTATEICON))
	{
		TRACE(_T("cursor over state image\n"));
		int nState = GetStateImage(hItem);

		// a hot item can only be UNCHECKED, CHECKED, or CHECKED_TRISTATE

		nState |= HDCheckboxImageList::HOT_INDEX;

		// remove hot from previous hot item
		SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

		m_hHotItem = hItem;
	}
}

//=============================================================================
LRESULT CTangramHtmlTreeWnd::SendRegisteredMessage(UINT nMessage, 
									   HTREEITEM hItem, 
									   LPARAM lParam /*= 0*/)
//=============================================================================
{
	LRESULT lResult = 0;

	CWnd *pWnd = GetParent();
	if (!pWnd)
		pWnd = GetOwner();

	if (pWnd && ::IsWindow(pWnd->m_hWnd))
	{
		XHTMLTREEMSGDATA msgdata = { 0 };
		msgdata.m_hCtrl    = m_hWnd;
		msgdata.m_nCtrlId  = GetDlgCtrlID();
		msgdata.m_hItem    = hItem;

		lResult = pWnd->SendMessage(nMessage, (WPARAM)&msgdata, lParam);
	}

	return lResult;
}

//=============================================================================
int CTangramHtmlTreeWnd::GetStateImage(HTREEITEM hItem)
//=============================================================================
{
	int nState = 0;

	ASSERT(hItem);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		if (m_bSmartCheck && (pXTCD->m_nChildren != 0))
		{
			if (pXTCD->m_nChecked == 0)
				nState = UNCHECKED;
			else if (pXTCD->m_nChecked == (pXTCD->m_nChildren - pXTCD->m_nSeparators))	//+++1.6
				nState = CHECKED;
			else
				nState = TRISTATE;
		}
		else
		{
			if (pXTCD->m_bChecked)
				nState = CHECKED;
			else
				nState = UNCHECKED;
		}
		if (!pXTCD->m_bEnabled)
			nState |= HDCheckboxImageList::DISABLED_INDEX;
	}

	TRACE(_T("GetStateImage returning %d ~~~~~\n"), nState);

	return nState;
}

//=============================================================================
int CTangramHtmlTreeWnd::SetCheckParent(HTREEITEM hItem, int nCount)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::SetCheckParent:  nCount=%d  <%s>\n"), nCount, GetItemText(hItem));
	ASSERT(hItem);

	int nState = 0;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		TRACE(_T("pXTCD->m_nChecked=%d  pXTCD->m_nChildren=%d \n"), pXTCD->m_nChecked, pXTCD->m_nChildren);
		pXTCD->m_nChecked += nCount;
		if (pXTCD->m_nChecked < 0)
			pXTCD->m_nChecked = 0;

		BOOL bOldCheck = pXTCD->m_bChecked;
		if (pXTCD->m_nChecked == (pXTCD->m_nChildren - pXTCD->m_nSeparators))	//+++1.6
			pXTCD->m_bChecked = true;
		else
			pXTCD->m_bChecked = false;

		if (pXTCD->m_bChecked != bOldCheck)
			nCount += pXTCD->m_bChecked ? 1 : -1;

		nState = GetStateImage(hItem);

		CString strID = pXTCD->m_strTangramItemID;
		if(strID!=_T(""))
		{
			if(pXTCD->m_bChecked)
			{
				m_mapSelectedNodeDic[strID] = pXTCD;
			}
			else
			{
				auto it = m_mapSelectedNodeDic.find(strID);
				if(it!=m_mapSelectedNodeDic.end())
					m_mapSelectedNodeDic.erase(it);
			}
		}
		//TRACE(_T("CurentSelected Node Count:%d\n"), m_mapSelectedNodeDic.size());
		SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

		TRACE(_T("nState=%d\n"), nState);				
		TRACE(_T("CurentSelected Node Count:%d\n"), m_mapSelectedNodeDic.size());
	}

	return nCount;
}

//=============================================================================
CTangramHtmlTreeWnd& CTangramHtmlTreeWnd::SetCheckChildren(HTREEITEM hItem, BOOL fCheck)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::SetCheckChildren\n"));

	// first set item state for this item
	SetItemStateChildren(hItem, fCheck);

	HTREEITEM hNext = GetChildItem(hItem);
	
	// loop to set item state for children
	while (hNext)
	{
		TRACE(_T("SetCheckChildren: %d  <%s>\n"), fCheck, GetItemText(hNext));

		// recurse into children
		if (ItemHasChildren(hNext))
			SetCheckChildren(hNext, fCheck);

		SetItemStateChildren(hNext, fCheck);

		hNext = GetNextItem(hNext, TVGN_NEXT);
	}

	return *this;
}

//=============================================================================
CTangramHtmlTreeWnd& CTangramHtmlTreeWnd::SetItemStateChildren(HTREEITEM hItem, BOOL fCheck)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::SetItemStateChildren\n"));

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD && pXTCD->m_bEnabled)
	{
		int nState = GetStateImage(hItem);
		if (pXTCD->m_bSeparator)				//+++1.6
		{
			nState = 0;
		}
		else
		{
			int nStateHot = nState & HDCheckboxImageList::HOT_INDEX;			// save hot
			int nStateDisabled = nState & HDCheckboxImageList::DISABLED_INDEX;	// save disabled
			nState &= ~(HDCheckboxImageList::HOT_INDEX | 
						HDCheckboxImageList::DISABLED_INDEX);	// remove hot & disabled

			pXTCD->m_bChecked = fCheck;

			CString strID = pXTCD->m_strTangramItemID;
			if(strID!=_T(""))
			{
				if (fCheck)
				{
					m_mapSelectedNodeDic[strID] = pXTCD;
					pXTCD->m_nChecked = pXTCD->m_nChildren - pXTCD->m_nSeparators;	//+++1.6
					if (pXTCD->m_nChecked < 0)
						pXTCD->m_nChecked = 0;
					nState = CHECKED;
				}
				else
				{
					auto it = m_mapSelectedNodeDic.find(strID);
					if(it!=m_mapSelectedNodeDic.end())
						m_mapSelectedNodeDic.erase(it);
					pXTCD->m_nChecked = 0;
					nState = UNCHECKED;
				}
				TRACE(_T("CurentSelected Node Count:%d\n"), m_mapSelectedNodeDic.size());
			}

			nState |= nStateHot;		// restore hot
			nState |= nStateDisabled;	// restore disabled
			TRACE(_T("setting state to %d\n"), nState);
		}
		SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
	}

	return *this;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::EnableItem(HTREEITEM hItem, BOOL m_bEnabled)
//=============================================================================
{
	BOOL rc = true;

	ASSERT(hItem);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->m_bEnabled;

		pXTCD->m_bEnabled = m_bEnabled;

		int nState = GetStateImage(hItem);

		if (m_bEnabled)
			nState &= ~HDCheckboxImageList::DISABLED_INDEX;
		else
			nState |= HDCheckboxImageList::DISABLED_INDEX;

		// set enabled state
		SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
	}

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::EnableBranch(HTREEITEM hItem, BOOL m_bEnabled)
//=============================================================================
{
	BOOL rc = true;

	if (hItem && !IsSeparator(hItem))	//+++1.6
	{
		rc = EnableItem(hItem, m_bEnabled);

		hItem = GetChildItem(hItem);

		if (hItem)
		{
			do
			{
				EnableBranch(hItem, m_bEnabled);

			} while ((hItem = GetNextSiblingItem(hItem)) != NULL);
		}
	}

	return rc;	// return state of first item
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::GetCheck(HTREEITEM hItem)
//=============================================================================
{
	BOOL rc = false;

	ASSERT(hItem);

	if (m_bCheckBoxes && hItem)
	{
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD)
		{
			if (m_bSmartCheck)
			{
				if (pXTCD->m_nChildren == 0)
				{
					rc = pXTCD->m_bChecked;
				}
				else
				{
					if (pXTCD->m_nChecked == 0)
						rc = false;		// no children are checked
					else if (pXTCD->m_nChecked == (pXTCD->m_nChildren - pXTCD->m_nSeparators))	//+++1.6
						rc = true;		// all children are checked
					else
						rc = false;		// not all children are checked
				}
			}
			else
			{
				rc = pXTCD->m_bChecked;
			}
		}
	}

	return rc;
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::GetFirstCheckedItem()
//=============================================================================
{
	if (m_bCheckBoxes)
	{
		for (HTREEITEM hItem = GetRootItem(); 
			 hItem != NULL; 
			 hItem = GetNextItem(hItem))
		{
			if (GetCheck(hItem))
				return hItem;
		}
	}

	return NULL;
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::GetNextCheckedItem(HTREEITEM hItem)
//=============================================================================
{
	if (m_bCheckBoxes)
	{
		for (hItem = GetNextItem(hItem); 
			 hItem != NULL; 
			 hItem = GetNextItem(hItem))
		{
			if (GetCheck(hItem))
				return hItem;
		}
	}

	return NULL;
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::GetPrevCheckedItem(HTREEITEM hItem)
//=============================================================================
{
	if (m_bCheckBoxes)
	{
		for (hItem = GetPrevItem(hItem); hItem != NULL; hItem = GetPrevItem(hItem))
		{
			if (GetCheck(hItem))
				return hItem;
		}
	}

	return NULL;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::DeleteItem(HTREEITEM hItem)
//=============================================================================
{
	if (hItem == NULL)
		return false;
	BOOL bOldDestroyingTree = m_bDestroyingTree;
	HTREEITEM hParentItem = GetParentItem(hItem);
	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
	if (pXTCD == NULL)
		return false;
	CTangramXHtmlTreeNode *pPXTCD = NULL;
	if(hParentItem)
		pPXTCD = GetItemDataStruct(hParentItem);
	CTangramXmlParse* pParse = pXTCD->m_pXmlParse;
	if (hItem && ItemHasChildren(hItem))
	{
		DeleteBranch(hItem);
	}
	else if (hItem)
	{
		if (pXTCD)
		{
			if (pXTCD->m_bChecked)
				m_nDeletedChecked++;

			HTREEITEM hParent = hItem;

			// find all parents, decrement their children counts,
			// adjust their checked counts and separator counts
			while ((hParent = GetParentItem(hParent)) != NULL)
			{
				IncrementChildren(hParent, -1);
				if (pXTCD->m_bChecked)
					SetCheckParent(hParent, -1);
				if (pXTCD->m_bSeparator)					//+++1.6
					IncrementSeparators(hParent, -1);
			}

			m_bDestroyingTree = true;
			m_DataMap.RemoveKey(hItem);
			delete pXTCD;
		}
	}

	m_bDestroyingTree = bOldDestroyingTree;

	m_nDeleted++;
	if (pParse&&pPXTCD)
	{
		//CTangramXmlParse* pParent = pParse->g
		pPXTCD->m_pXmlParse->RemoveNode(pParse);
	}
	if (pPXTCD == NULL)
	{
		if (m_pHostXmlParse)
		{
			m_pHostXmlParse->Reflash();
			delete m_pHostXmlParse;
			m_pHostXmlParse = NULL;
		}
	}
	return CTreeCtrl::DeleteItem(hItem);
}

//=============================================================================
void CTangramHtmlTreeWnd::DeleteBranch(HTREEITEM hItem)
//=============================================================================
{
	if (hItem)
	{
		HTREEITEM hChild = GetChildItem(hItem);
		while (hChild)
		{
			// recursively delete all the items
			HTREEITEM hNext = GetNextSiblingItem(hChild);
			DeleteBranch(hChild);
			hChild = hNext;
		}
		DeleteItem(hItem);
	}
}

//=============================================================================
CString CTangramHtmlTreeWnd::GetItemNote(HTREEITEM hItem, BOOL bStripHtml /*= false*/)
//=============================================================================
{
	CString strNote = _T("");

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD && pXTCD->m_pszNote)
	{
		strNote = pXTCD->m_pszNote;

		if (bStripHtml)
		{
#ifdef XHTMLHTML
			// remove html tags
			CXHtmlDraw hd;
			int n = strNote.GetLength();
			if (n > 3)		// minimum html string
			{
				TCHAR *s = new TCHAR [n + 16];
				hd.GetPlainText(strNote, s, n+4);
				strNote = s;
				delete [] s;
			}
#endif // XHTMLHTML
		}
	}

	return strNote;
}

//=============================================================================
int CTangramHtmlTreeWnd::GetItemNoteWidth(HTREEITEM hItem)
//=============================================================================
{
	int nWidth = 0;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD && pXTCD->m_pszNote)
	{
		nWidth = pXTCD->m_nTipWidth;
	}

	return nWidth;
}

//=============================================================================
CTangramHtmlTreeWnd& CTangramHtmlTreeWnd::SetItemNote(HTREEITEM hItem, 
									LPCTSTR lpszNote, 
									int m_nTipWidth /*= 0*/)
//=============================================================================
{
	ASSERT(hItem);
	ASSERT(lpszNote);

	if (hItem && lpszNote)
	{
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD)
		{
			if (pXTCD->m_pszNote)
				delete [] pXTCD->m_pszNote;
			pXTCD->m_pszNote = NULL;

			size_t len = _tcslen(lpszNote);
			pXTCD->m_pszNote = new TCHAR [len + 4];
			if (pXTCD->m_pszNote)
			{
				memset(pXTCD->m_pszNote, 0, len+4);
				_tcsncpy(pXTCD->m_pszNote, lpszNote, len+1);
				pXTCD->m_nTipWidth = m_nTipWidth;
			}
		}
	}

	return *this;
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::InsertItem(LPTVINSERTSTRUCT lpInsertStruct, CTangramXHtmlTreeNode * pData /*= NULL*/)
//=============================================================================
{
	CTangramXHtmlTreeNode *pXTCD = new CTangramXHtmlTreeNode;
	ASSERT(pXTCD);
	if (!pXTCD)
	{
		ASSERT(false);
		return 0;
	}

	if (pData)
	{
		// copy user items for CTangramXHtmlTreeNode
		pXTCD->m_bWaitingFor   = pData->m_bWaitingFor;
		pXTCD->m_bChecked   = pData->m_bChecked;
		pXTCD->m_bEnabled   = pData->m_bEnabled;
		pXTCD->m_bSeparator = pData->m_bSeparator;	//+++1.6
		pXTCD->m_strName = pData->m_strName;
		// copy user items for XHTMLDRAWSTRUCT
		pXTCD->ds.crText           		= pData->ds.crText;
		pXTCD->ds.crAnchorText     		= pData->ds.crAnchorText;
		pXTCD->ds.crBackground     		= pData->ds.crBackground;
		pXTCD->ds.crTextBackground 		= pData->ds.crTextBackground;
		pXTCD->ds.bIgnoreColorTag  		= pData->ds.bIgnoreColorTag;
		pXTCD->ds.bTransparent     		= pData->ds.bTransparent;
		pXTCD->ds.bBold            		= pData->ds.bBold;
		pXTCD->ds.bItalic          		= pData->ds.bItalic;
		pXTCD->ds.bUnderline       		= pData->ds.bUnderline;
		pXTCD->ds.bStrikeThrough   		= pData->ds.bStrikeThrough;
		pXTCD->ds.bUseEllipsis     		= pData->ds.bUseEllipsis;
		pXTCD->ds.bLogFont         		= pData->ds.bLogFont;
		pXTCD->ds.uFormat          		= pData->ds.uFormat;
		pXTCD->ds.lf               		= pData->ds.lf;
		pXTCD->m_strTangramXML     		= pData->m_strTangramXML;
		pXTCD->m_strTangramHeader		= pData->m_strTangramHeader;
		pXTCD->m_strTangramXML2     	= pData->m_strTangramXML2;
		pXTCD->m_strTangramMenuXML		= pData->m_strTangramMenuXML;
		pXTCD->m_strTangramDataURL		= pData->m_strTangramDataURL;
		pXTCD->m_strTangramDataXML		= pData->m_strTangramDataXML;
		pXTCD->m_strTangramItemID		= pData->m_strTangramItemID;
		CTangramTreeNode* pXobj			= new CComObject<CTangramTreeNode>;
		pXobj->m_pXHTMLTREEDATA			= pXTCD;
		pXTCD->m_pWebRTTreeNode		= pXobj;//new CComObject<CTangramTreeNode>;
		pXTCD->m_pWebRTTreeNode->AddRef();
		if (pData->m_pXmlParse)
			pXTCD->m_pXmlParse = pData->m_pXmlParse;
	}

	pXTCD->m_hTreeCtrl = m_hWnd;

	TVINSERTSTRUCT tvis;
	memcpy(&tvis, lpInsertStruct, sizeof(TVINSERTSTRUCT));

	if (!m_bImages)
	{
		tvis.item.iImage = TV_NOIMAGE;
		tvis.item.iSelectedImage = TV_NOIMAGE;	//+++1.5
	}

	tvis.item.mask |= TVIF_STATE;
	int nState = UNCHECKED;
	if (pXTCD->m_bChecked && m_bCheckBoxes)
		nState = CHECKED;
	if (!pXTCD->m_bEnabled)
		nState |= HDCheckboxImageList::DISABLED_INDEX;
	tvis.item.state = INDEXTOSTATEIMAGEMASK(nState);
	tvis.item.stateMask = TVIS_STATEIMAGEMASK;
	tvis.item.lParam = (LPARAM)pXTCD;

	CString strText = tvis.item.pszText;

	if (m_bStripHtml)
	{
#ifdef XHTMLHTML
		// remove html tags
		CXHtmlDraw hd;
		int n = strText.GetLength();
		if (n > 3)		// minimum html string
		{
			TCHAR *s = new TCHAR [n + 16];
			hd.GetPlainText(strText, s, n+4);
			strText = s;
			delete [] s;
		}
#endif // XHTMLHTML
	}

	TRACE(_T("inserting <%s>\n"), strText);

	tvis.item.pszText = strText.LockBuffer();

	HTREEITEM hItem = CTreeCtrl::InsertItem(&tvis);
	ASSERT(hItem);
	
	strText.UnlockBuffer();

	if (hItem)
	{
		m_DataMap.SetAt(hItem, pXTCD);
		pXTCD->m_hItem = hItem;
		TRACE(_T("count=%d\n"), m_DataMap.GetCount());

		if (m_bSmartCheck)
		{
			HTREEITEM hParent = hItem;

			// find all parents, increment their children counts,
			// adjust their checked counts
			int nCount = pXTCD->m_bChecked ? 1 : 0;
			while ((hParent = GetParentItem(hParent)) != NULL)
			{
				IncrementChildren(hParent);
				nCount = SetCheckParent(hParent, nCount);
			}
		}
		if(pXTCD->m_bWaitingFor)
		{
			pXTCD->m_hWaitItemMsg = InsertItem(_T("Loading..."),hItem,0);
		}
	}

	return hItem;
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::InsertItem(UINT nMask, 
								 LPCTSTR lpszItem, 
								 int nImage, 
								 int nSelectedImage, 
								 UINT nState, 
								 UINT nStateMask, 
								 LPARAM lParam, 
								 HTREEITEM hParent, 
								 HTREEITEM hInsertAfter)
//=============================================================================
{
	TVINSERTSTRUCT tvis = { 0 };

	tvis.item.mask = nMask;
	tvis.item.pszText = (LPTSTR)lpszItem;
	tvis.item.iImage = nImage;
	tvis.item.iSelectedImage = nSelectedImage;
	tvis.item.state = nState;
	tvis.item.stateMask = nStateMask;
	tvis.item.lParam = lParam;
	tvis.hParent = hParent;
	tvis.hInsertAfter = hInsertAfter;

	return InsertItem(&tvis);
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::InsertItem(LPCTSTR lpszItem, 
								 HTREEITEM hParent /*= TVI_ROOT*/, 
								 HTREEITEM hInsertAfter /*= TVI_LAST*/)
//=============================================================================
{
	TVINSERTSTRUCT tvis = { 0 };

	tvis.item.mask = TVIF_TEXT;
	tvis.item.pszText = (LPTSTR)lpszItem;
	tvis.hParent = hParent;
	tvis.hInsertAfter = hInsertAfter;

	return InsertItem(&tvis);
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::InsertItem(LPCTSTR lpszItem, 
								 int nImage, 
								 int nSelectedImage, 
								 HTREEITEM hParent /*= TVI_ROOT*/, 
								 HTREEITEM hInsertAfter /*= TVI_LAST*/)
//=============================================================================
{
	TVINSERTSTRUCT tvis = { 0 };

	tvis.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	tvis.item.pszText = (LPTSTR)lpszItem;
	tvis.item.iImage = nImage;
	tvis.item.iSelectedImage = nSelectedImage;
	tvis.hParent = hParent;
	tvis.hInsertAfter = hInsertAfter;

	return InsertItem(&tvis);
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::InsertSeparator(HTREEITEM hItem)	//+++1.6
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::InsertSeparator\n"));

	HTREEITEM hAfter = hItem;
	HTREEITEM hParent = GetParentItem(hItem);
	HTREEITEM hNewParent = GetParentItem(hItem);
	TRACE(_T("hParent=%X\n"), hParent);

	if (hParent == hAfter)
	{
		// dropping on parent
		hNewParent = hParent;
		hAfter = TVI_FIRST;
	}
	else if (ItemHasChildren(hAfter) && IsExpanded(hAfter))
	{
		// dropping on node that is expanded
		hNewParent = hAfter;
		hAfter = TVI_FIRST;
	}

	TVINSERTSTRUCT tvis = { 0 };
	tvis.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	tvis.item.pszText = (LPWSTR)_T("");
	tvis.item.iImage = TV_NOIMAGE;
	tvis.item.iSelectedImage = TV_NOIMAGE;
	tvis.hParent = hNewParent;
	tvis.hInsertAfter = hAfter;

	HTREEITEM hSep = InsertItem(&tvis);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hSep);

	if (pXTCD)
	{
		pXTCD->m_bSeparator = true;
		//SetItemTextColor(hSep, RGB(255,0,0));
	}

	SetItemState(hSep, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	// increment separator count in parents
	hParent = hSep;
	while ((hParent = GetParentItem(hParent)) != NULL)
	{
		IncrementSeparators(hParent, 1);
	}

	return hSep;
}

//=============================================================================
int CTangramHtmlTreeWnd::IncrementChildren(HTREEITEM hItem, int n /*= 1*/)
//=============================================================================
{
	int m_nChildren = 0;

	ASSERT(hItem);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		pXTCD->m_nChildren += n;
		if (pXTCD->m_nChildren < 0)
			pXTCD->m_nChildren = 0;
		m_nChildren = pXTCD->m_nChildren;
	}

	return m_nChildren;
}

//=============================================================================
int CTangramHtmlTreeWnd::IncrementSeparators(HTREEITEM hItem, int n /*= 1*/)		//+++1.6
//=============================================================================
{
	int m_nSeparators = 0;

	ASSERT(hItem);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		pXTCD->m_nSeparators += n;
		if (pXTCD->m_nSeparators < 0)
			pXTCD->m_nSeparators = 0;
		m_nSeparators = pXTCD->m_nSeparators;
	}

	return m_nSeparators;
}

//=============================================================================
CTangramXHtmlTreeNode * CTangramHtmlTreeWnd::GetItemDataStruct(HTREEITEM hItem)
//=============================================================================
{
	CTangramXHtmlTreeNode *pXTCD = NULL;

	if (hItem && !m_bDestroyingTree)
	{
		m_DataMap.Lookup(hItem, pXTCD);
	}

	return pXTCD;
}

#ifdef XHTMLTOOLTIPS

//=============================================================================
// OnDisplayTooltip - display CPPToolTip
void CTangramHtmlTreeWnd::OnDisplayTooltip(NMHDR * pNMHDR, LRESULT * pResult)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnDisplayTooltip\n"));
	*pResult = 0;

	NM_PPTOOLTIP_DISPLAY * pNotify = (NM_PPTOOLTIP_DISPLAY*)pNMHDR;

	CString strToolTip = _T("");

	if (PreDisplayToolTip(false, strToolTip))
	{
		// no limitation on text length
		
		TRACE(_T("setting tooltip to <%s>\n"), strToolTip);

		// change the tooltip's text
		pNotify->ti->sTooltip = strToolTip;
	}
}

#else


//=============================================================================
BOOL CTangramHtmlTreeWnd::OnToolTipText(UINT /*id*/, NMHDR * pNMHDR, LRESULT * pResult)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnToolTipText\n"));

	UINT nID = (UINT)pNMHDR->idFrom;
	
	// check if this is the automatic tooltip of the control
	if (nID == 0) 
		return true;	// do not allow display of automatic tooltip,
						// or our tooltip will disappear
	
	// handle both ANSI and UNICODE versions of the message
	TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
	TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
	
	*pResult = 0;
	
	CString strToolTip = _T("");

	if (PreDisplayToolTip(true, strToolTip))
	{
		// copy item text (up to 80 characters worth, limitation 
		// of the TOOLTIPTEXT structure) into the TOOLTIPTEXT 
		// structure's szText member
		
		strToolTip = strToolTip.Mid(0, sizeof(pTTTA->szText)-2);

#ifndef _UNICODE
		if (pNMHDR->code == TTN_NEEDTEXTA)
			lstrcpyn(pTTTA->szText, strToolTip, sizeof(pTTTA->szText));
		else
			_mbstowcsz(pTTTW->szText, strToolTip, sizeof(pTTTW->szText)/sizeof(TCHAR));
#else
		if (pNMHDR->code == TTN_NEEDTEXTA)
			_wcstombsz(pTTTA->szText, strToolTip, sizeof(pTTTA->szText));
		else
			lstrcpyn(pTTTW->szText, strToolTip, sizeof(pTTTW->szText)/sizeof(TCHAR));
#endif // _UNICODE
	}

	return false;	// we didn't handle the message, let the 
					// framework continue propagating the message
}

#endif  // XHTMLTOOLTIPS

//=============================================================================
// PreDisplayToolTip - returns true if tooltip should be displayed
BOOL CTangramHtmlTreeWnd::PreDisplayToolTip(BOOL bAlwaysRemoveHtml, CString& strToolTip)
//=============================================================================
{
	BOOL rc = false;

	if (m_bDragging)
		return rc;

	strToolTip = _T("");

	// get the mouse position
	const MSG* pMessage;
	pMessage = GetCurrentMessage();
	ASSERT(pMessage);
	CPoint point;
	point = pMessage->pt;		// get the point from the message
	ScreenToClient(&point);		// convert the point's coords to be relative 
								// to this control
	
	// see if the point falls on a tree item
	
	UINT flags = 0;
	HTREEITEM hItem = HitTest(point, &flags);

	if (IsSeparator(hItem))		//+++1.6
		return false;			// no tooltip for separator
		
	if (hItem && (flags & TVHT_ONITEM))
	{
		// it did fall on an item

		TRACE(_T("in PreDisplayToolTip:  mouse on item %X\n"), hItem);

		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD)
		{
			// get rect for item text
			CRect rectClient;
			GetClientRect(&rectClient);
			CRect rectText;
			GetItemRect(hItem, &rectText, true);	// get rect for text
			rectText.right = pXTCD->ds.nRightX;

			//TRACE(_T("nRightX = %d\n"), pXTCD->ds.nRightX);
			//TRACERECT(rectText);
			//TRACERECT(rectClient);

			strToolTip = GetItemNote(hItem);
			BOOL bNote = !strToolTip.IsEmpty();

			// check if text rect falls entirely inside client rect of control
			if (bNote || (rectText.right > (rectClient.right - 3)))
			{
				TRACE(_T("note or overflow\n"));

				// check if parent wants to display this tooltip --
				// if lResult is not zero, don't display 
				LRESULT lResult = 0;
				if (m_pToolTip)
				{
					lResult = SendRegisteredMessage(WM_XHTMLTREE_DISPLAY_TOOLTIP, 
									hItem, (LPARAM)m_pToolTip);
				}

				if (!lResult)
				{
					// get note again - this allows parent to modify note 
					// before it is displayed
					BOOL bStripHtml = bAlwaysRemoveHtml || !bNote;
					strToolTip = GetItemNote(hItem, bStripHtml);
					if (strToolTip.IsEmpty())
						strToolTip = GetItemText(hItem, bStripHtml);

					rc = true;

					// set tip width regardless of whether there is a note
					int m_nTipWidth = GetItemNoteWidth(hItem);

					if (m_nTipWidth == 0)
					{
						// no note width specified, use a heuristic
						m_nTipWidth = GetDefaultTipWidth();
					}

					if (m_nTipWidth && m_pToolTip && IsWindow(m_pToolTip->m_hWnd))
						m_pToolTip->SetMaxTipWidth(m_nTipWidth);
				}
			}
		}
	}

	return rc;
}

//=============================================================================
void CTangramHtmlTreeWnd::OnSysColorChange() 
//=============================================================================
{
	CTreeCtrl::OnSysColorChange();
	SetColors();	
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::GetItemTextBkColor(HTREEITEM hItem)
//=============================================================================
{
	COLORREF rc = 0;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
		rc = pXTCD->ds.crTextBackground;

	return rc;
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::GetItemTextColor(HTREEITEM hItem)
//=============================================================================
{
	COLORREF rc = 0;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
		rc = pXTCD->ds.crText;

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::SetItemText(HTREEITEM hItem, LPCTSTR lpszItem)		//+++1.6
//=============================================================================
{
	if (IsSeparator(hItem))
		return false;

	return CTreeCtrl::SetItemText(hItem, lpszItem);
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::SetItemTextBkColor(HTREEITEM hItem, COLORREF rgb)
//=============================================================================
{
	COLORREF rc = 0;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->ds.crTextBackground;
		pXTCD->ds.crTextBackground = rgb;
	}

	return rc;
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::SetItemTextColor(HTREEITEM hItem, COLORREF rgb)
//=============================================================================
{
	COLORREF rc = 0;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->ds.crText;
		pXTCD->ds.crText = rgb;
	}

	return rc;
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::SetBkColor(COLORREF rgb) 
//=============================================================================
{
	COLORREF old = m_crWindow; 
	if (rgb == COLOR_NONE)
		rgb = GetSysColor(COLOR_WINDOW);
	m_crCustomWindow = m_crWindow = rgb; 
	return old; 
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::SetTextColor(COLORREF rgb) 
//=============================================================================
{
	COLORREF old = m_crWindowText; 
	if (rgb == COLOR_NONE)
		rgb = GetSysColor(COLOR_WINDOWTEXT);
	m_crCustomWindowText = m_crWindowText = rgb; 
	return old; 
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::SetInsertMarkColor(COLORREF rgb)
//=============================================================================
{
	if (rgb == COLOR_NONE)
		rgb = GetSysColor(COLOR_HIGHLIGHT);
	m_crInsertMark = rgb; 
	return CTreeCtrl::SetInsertMarkColor(rgb);
}

//=============================================================================
CTangramHtmlTreeWnd& CTangramHtmlTreeWnd::SetSeparatorColor(COLORREF rgb)	//+++1.6
//=============================================================================
{
	if (rgb == COLOR_NONE)
		rgb = GetSysColor(COLOR_GRAYTEXT);
	m_crSeparator = rgb; 
	return *this;
}

//=============================================================================
void CTangramHtmlTreeWnd::SetColors()
//=============================================================================
{
	m_crWindow        = GetSysColor(COLOR_WINDOW);
	m_crWindowText    = GetSysColor(COLOR_WINDOWTEXT);
	m_crAnchorText    = RGB(0,0,255);
	m_crGrayText      = GetSysColor(COLOR_GRAYTEXT);
	m_crHighlight     = GetSysColor(COLOR_HIGHLIGHT);
	m_crHighlightText = GetSysColor(COLOR_HIGHLIGHTTEXT);
	m_crInsertMark    = GetSysColor(COLOR_HIGHLIGHT);
	m_crSeparator     = GetSysColor(COLOR_GRAYTEXT);		//+++1.6

	if (m_crCustomWindow != COLOR_NONE)
		m_crWindow = m_crCustomWindow;

	if (m_crCustomWindowText != COLOR_NONE)
		m_crWindowText = m_crCustomWindowText;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::EnableWindow(BOOL bEnable /*= true*/)
//=============================================================================
{
	BOOL rc = CTreeCtrl::EnableWindow(bEnable);

	if (bEnable)
	{
		if (m_crCustomWindow != COLOR_NONE)
			m_crWindow = m_crCustomWindow;
		else
			m_crWindow = GetSysColor(COLOR_WINDOW);

		if (m_crCustomWindowText != COLOR_NONE)
			m_crWindowText = m_crCustomWindowText;
		else
			m_crWindowText = GetSysColor(COLOR_WINDOWTEXT);
	}
	else
	{
		m_crWindow = GetDisabledColor(GetSysColor(COLOR_WINDOW));
		m_crWindowText = GetSysColor(COLOR_GRAYTEXT);
	}

	return rc;
}

//=============================================================================
COLORREF CTangramHtmlTreeWnd::GetDisabledColor(COLORREF color)
//=============================================================================
{
	BYTE r = GetRValue(color);
	BYTE g = GetGValue(color);
	BYTE b = GetBValue(color);
	const BYTE disabled_value = 10;

	r = (r >= disabled_value) ? (BYTE)(r - disabled_value) : r;
	g = (g >= disabled_value) ? (BYTE)(g - disabled_value) : g;
	b = (b >= disabled_value) ? (BYTE)(b - disabled_value) : b;

	return RGB(r, g, b);
}

//=============================================================================
CTangramHtmlTreeWnd& CTangramHtmlTreeWnd::SetLogfont(LOGFONT * pLogFont)
//=============================================================================
{
	ASSERT(pLogFont);

	if (pLogFont)
		m_lf = *pLogFont;

	return *this;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::GetItemBold(HTREEITEM hItem)
//=============================================================================
{
	BOOL rc = false;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
		rc = pXTCD->ds.bBold;

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::SetItemBold(HTREEITEM hItem, BOOL bBold)
//=============================================================================
{
	BOOL rc = false;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->ds.bBold;
		pXTCD->ds.bBold = bBold;
	}

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::DeleteAllItems()
//=============================================================================
{
	// avoid unneeded selchange notifications
	SelectItem(NULL);

	CollapseAll();
	BOOL bOldDestroyingTree = m_bDestroyingTree;
	m_bDestroyingTree = true;
	BOOL rc = CTreeCtrl::DeleteAllItems();
	DeleteMap();
	m_bDestroyingTree = bOldDestroyingTree;
	return rc;
}

//=============================================================================
void CTangramHtmlTreeWnd::CollapseAll()
//=============================================================================
{
	HTREEITEM hItemRoot = GetRootItem();

	HTREEITEM hItem = hItemRoot;

	if (hItem)
	{
		do 
		{
			CollapseBranch(hItem);

		} while ((hItem = GetNextSiblingItem(hItem)) != NULL);

		SelectItem(hItemRoot);

		SendMessage(WM_HSCROLL, SB_LEFT);
		UpdateWindow();
	}
}

//=============================================================================
void CTangramHtmlTreeWnd::ExpandAll()
//=============================================================================
{
	HTREEITEM hItemSel = GetSelectedItem();
	if (!hItemSel)
		hItemSel = GetRootItem();

	if (hItemSel)
	{
		HTREEITEM hItem = GetRootItem();	// must start with root for best performance

		SetRedraw(false);

		do 
		{
			ExpandBranch(hItem);

		} while ((hItem = GetNextSiblingItem(hItem)) != NULL);

		SelectItem(hItemSel);
		SetScrollPos(SB_VERT, 0);
		EnsureVisible(hItemSel);
		SendMessage(WM_HSCROLL, SB_LEFT);

		SetRedraw(true);
	}
		
	::PostMessage(m_hWnd,WM_REFRESHDATA,0,1);
}

//=============================================================================
void CTangramHtmlTreeWnd::ExpandBranch(HTREEITEM hItem)
//=============================================================================
{
	if (hItem && ItemHasChildren(hItem))
	{
		Expand(hItem, TVE_EXPAND);

		hItem = GetChildItem(hItem);

		if (hItem)
		{
			do
			{
				ExpandBranch(hItem);

			} while ((hItem = GetNextSiblingItem(hItem)) != NULL);
		}
	}
}

//=============================================================================
void CTangramHtmlTreeWnd::CollapseBranch(HTREEITEM hItem)
//=============================================================================
{
	if (hItem && ItemHasChildren(hItem))
	{
		Expand(hItem, TVE_COLLAPSE);

		hItem = GetChildItem(hItem);

		if (hItem && ItemHasChildren(hItem))
		{
			do 
			{
				CollapseBranch(hItem);

			} while ((hItem = GetNextSiblingItem(hItem)) != NULL);
		}
	}
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::Expand(HTREEITEM hItem, UINT nCode)
//=============================================================================
{
	if (hItem && ItemHasChildren(hItem)) 
	{
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD && pXTCD->m_bEnabled)
		{
			CString strHeaderXml = pXTCD->m_strTangramHeader;
			BOOL bOldExpanded = pXTCD->m_bExpanded;

			if (nCode == TVE_COLLAPSE || nCode == TVE_COLLAPSERESET)
			{
				pXTCD->m_bExpanded = false;
			}
			else if (nCode == TVE_EXPAND)
			{
				pXTCD->m_bExpanded = true;
			}
			else if (nCode == TVE_TOGGLE)
			{
				if (bOldExpanded)
					pXTCD->m_bExpanded = false;
				else
					pXTCD->m_bExpanded = true;
			}
			else
			{
				TRACE(_T("ERROR bad nCode=%u\n"), nCode);
			}

			if (pXTCD->m_bExpanded)
				pXTCD->m_bHasBeenExpanded = true;
			else
				pXTCD->m_bHasBeenExpanded = false;

			if (pXTCD->m_bExpanded != bOldExpanded)
				SendRegisteredMessage(WM_XHTMLTREE_ITEM_EXPANDED, hItem, 
					pXTCD->m_bExpanded);
		}
	}

	TRACE(_T("calling CTreeCtrl::Expand()\n"));
	BOOL rc = CTreeCtrl::Expand(hItem, nCode);
		
	::PostMessage(m_hWnd,WM_REFRESHDATA,0,1);
	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::GetHasBeenExpanded(HTREEITEM hItem)
//=============================================================================
{
	BOOL rc = false;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->m_bHasBeenExpanded;
	}

	return rc;
}

//=============================================================================
void CTangramHtmlTreeWnd::Init(CXobj* pXobj)
//=============================================================================
{
	if (pXobj)
	{
		CXobj* pRootXobj = pXobj->m_pRootObj;
		if (pRootXobj == NULL)
			pRootXobj = pXobj;
		CComBSTR bstrCallBackNode(L"");
		pXobj->get_Attribute(CComBSTR(L"CallBackNode"), &bstrCallBackNode);
		CString strCallBackNode = OLE2T(bstrCallBackNode);
		long nCount = 0;
		if (strCallBackNode != _T(""))
		{
			int nPos = strCallBackNode.Find(_T(","));
			if (nPos == -1)
			{
				IXobj* pXobj = NULL;
				CComPtr<IXobjCollection> pWebRTNodeCollection;
				pRootXobj->GetXobjs(CComBSTR(strCallBackNode), &pXobj, &pWebRTNodeCollection, &nCount);
				if (pXobj)
				{
					CComPtr<IDispatch> pdisp;
					pXobj->get_Extender(&pdisp);
					if (pdisp)
					{
						CComQIPtr<IWebRTTreeViewCallBack> pIWebRTTreeViewCallBack(pdisp);
						if (pIWebRTTreeViewCallBack)
						{
							m_pObj->put_TangramTreeViewCallBack(bstrCallBackNode, pIWebRTTreeViewCallBack.p);
							pIWebRTTreeViewCallBack->OnInitTreeView(m_pObj, CComBSTR(L"MainIMHistory"));
						}
					}
				}
			}
			while (nPos != -1)
			{
				CString strID = strCallBackNode.Left(nPos);
				strCallBackNode = strCallBackNode.Mid(nPos + 1);
				nPos = strCallBackNode.Find(_T(","));
				if (strID != _T(""))
				{
					IXobj* pXobj = NULL;
					CComPtr<IXobjCollection> pWebRTNodeCollection;
					pRootXobj->GetXobjs(CComBSTR(strID), &pXobj, &pWebRTNodeCollection, &nCount);
					if (pXobj)
					{
						CComPtr<IDispatch> pdisp;
						pXobj->get_Extender(&pdisp);
						if (pdisp)
						{
							CComQIPtr<IWebRTTreeViewCallBack> pIWebRTTreeViewCallBack(pdisp);
							if (pIWebRTTreeViewCallBack)
							{
								m_pObj->put_TangramTreeViewCallBack(strID.AllocSysString(), pIWebRTTreeViewCallBack.p);
							}
						}
					}
				}
				if (nPos == -1)
				{
					IXobj* pXobj = NULL;
					CComPtr<IXobjCollection> pWebRTNodeCollection;
					pRootXobj->GetXobjs(CComBSTR(strCallBackNode), &pXobj, &pWebRTNodeCollection, &nCount);
					if (pXobj)
					{
						CComPtr<IDispatch> pdisp;
						pXobj->get_Extender(&pdisp);
						if (pdisp)
						{
							CComQIPtr<IWebRTTreeViewCallBack> pIWebRTTreeViewCallBack(pdisp);
							if (pIWebRTTreeViewCallBack)
							{
								m_pObj->put_TangramTreeViewCallBack(bstrCallBackNode, pIWebRTTreeViewCallBack.p);
							}
						}
					}
				}
			}
		}
		Expand(m_hFirstRoot, TVE_EXPAND);
		SelectItem(m_hFirstRoot);
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(m_hFirstRoot);

		if (pXTCD->m_strTangramXML != _T("")/*&&m_LasthItem!=hItem*/)
		{
			CTangramXmlParse m_Parse;
			if (m_Parse.LoadXml(pXTCD->m_strTangramXML))
			{
				CString strBindWnds = m_Parse.attr(_T("BindWnds"), _T(""));
				//if (strBindWnds != _T(""))
				//{
				//	CTangramXmlParse* pParse = m_Parse.GetChild(_T("BindWnds"));
				//	if (pParse)
				//	{
				//		pXTCD->m_nType |= 0x0001;
				//		CString strIDs = strBindWnds;// pXTCD->m_strRelationNodes;
				//		int nPos = strIDs.Find(_T(","));
				//		long nCount = 0;
				//		while (nPos != -1)
				//		{
				//			CString strKey = strIDs.Left(nPos);
				//			strIDs = strIDs.Mid(nPos + 1);
				//			LONGLONG h = 0;
				//			this->m_pHostWnd->m_pXobj->get_BindWnd(CComBSTR(strKey), &h);
				//			if (h)
				//			{
				//				CComPtr<IXobj> pXobj2;
				//				CString strXml = pParse->GetChild(strKey)->xml();
				//				CComPtr<IXobj> _pXobj;
				//				theApp.m_pWebRTManager->NavigateXTML(h, strXml.AllocSysString(), &_pXobj);
				//				//pXobj->Navigate(CComBSTR(strKey),CComBSTR(strXml),&pXobj2);
				//			}
				//			nPos = strIDs.Find(_T(","));
				//			if (nPos == -1)
				//				break;
				//		}
				//	}
				//}
				pXTCD->m_strRelationNodes = m_Parse.attr(_T("RelationNodes"), _T(""));
				CTangramXmlParse* pParse = m_Parse.GetChild(_T("RelationNodes"));
				//if (pXTCD->m_strRelationNodes != _T("") && pParse)
				//{
				//	pXTCD->m_nType |= 0x0001;
				//	CString strIDs = pXTCD->m_strRelationNodes;
				//	int nPos = strIDs.Find(_T(","));
				//	long nCount = 0;
				//	while (nPos != -1)
				//	{
				//		CString strKey = strIDs.Left(nPos);
				//		strIDs = strIDs.Mid(nPos + 1);
				//		CComPtr<IXobj> pXobj;
				//		CComPtr<IXobjCollection> pXobjCollection;
				//		pRootXobj->GetNodes(CComBSTR(strKey), &pXobj, &pXobjCollection, &nCount);
				//		if (pXobj)
				//		{
				//			CComPtr<IXobj> pXobj2;
				//			CString strXml = pParse->GetChild(strKey)->xml();
				//			LONGLONG h = 0;
				//			pXobj->get_Handle(&h);
				//			if (h)
				//			{
				//				CComPtr<IXobj> _pXobj;
				//				theApp.m_pWebRTManager->NavigateXTML(h, strXml.AllocSysString(), &_pXobj);
				//				//pXobj->Navigate(CComBSTR(strKey),CComBSTR(strXml),&pXobj2);
				//			}
				//		}
				//		nPos = strIDs.Find(_T(","));
				//		if (nPos == -1)
				//			break;
				//	}
				//}

			}
		}
	}
}

void CTangramHtmlTreeWnd::WriteData(CString strData)
{
	//if(m_pWebBrowser2)
	//{
	//	CString strScript = strData;
	//	CTangramXmlParse m_Parse;
	//	if(m_Parse.LoadXml(strScript))
	//	{
	//		CString strWebScript = m_Parse.attr(_T("CallBack"),_T(""));
	//		if(strWebScript!=_T(""))
	//		{
	//			VARIANT var;
	//			BOOL bRet = false;
	//			CString strScript2 = _T("try{") +strWebScript + _T("('") + strData +_T("')")+ _T(";} catch(e){}");
	//			CComPtr<IDispatch> pDisp = NULL;
	//			m_pWebBrowser2->get_Document(&pDisp);
	//			if (pDisp)
	//			{			
	//				CComQIPtr<IHTMLDocument2,&IID_IHTMLDocument2> pDoc2(pDisp);
	//				if (pDoc2)
	//				{
	//					CComQIPtr<IHTMLWindow2,&IID_IHTMLWindow2> pWindow;
	//					pDoc2->get_parentWindow(&pWindow);

	//					if (pWindow)
	//					{
	//						try
	//						{
	//							bRet = (pWindow->execScript(CComBSTR(strScript2),L"",&var) == S_OK);
	//						}
	//						catch(...)
	//						{
	//							bRet = false;
	//						}
	//					}
	//				}
	//			}	
	//			return;
	//		}
	//	}
	//}
}

CString CTangramHtmlTreeWnd::TangramGetData(CTangramXmlParse* pParse, CTangramHelper* pThisHelper)
{
	if(pParse)
	{
		CString strData = GetSelectedNodeInfo(pParse->attr(_T("Propertys"),_T("")));
		return strData;
	}
	return _T("");
}

CString	CTangramHtmlTreeWnd::GetSelectedNodeInfo(CString strPropertys)
{
	CString strFormat = _T("");
	strFormat.Format(_T("<%ss>"),m_strLeafKey);
	CString strVal = strFormat;//_T("<Contacts>");

	strFormat.Format(_T("<%ss>"),m_strNodeKey);
	CString strVal2 = strFormat;//_T("<orgs>");
	strFormat.Format(_T("<%ss2>"),m_strNodeKey);
	CString strVal3 = strFormat;//_T("<orgs2>");
	if(strPropertys!=_T(""))
	{
		CString strProperty = _T("");
		int nCount = 0;
		for (auto it: m_mapSelectedNodeDic)
		{
			if(it.second->m_strTangramDataXML==_T("")&&it.second->m_hWaitItemMsg)
			{
				if(it.second->m_hWaitItemMsg)
				{
					strVal2 += _T("<");
					strVal2 += m_strNodeKey;
					strVal2 += _T(">");
					strVal2 += it.second->m_strTangramItemID;
					strVal2 += _T("</");
					strVal2 += m_strNodeKey;
					strVal2 += _T(">");//_T("</org>");
				}
				else
				{
					strVal3 += _T("<");
					strVal3 += m_strNodeKey;
					strVal3 += _T(">");//_T("<org>");
					strVal3 += it.second->m_strTangramItemID;
					strVal3 += _T("</");
					strVal3 += m_strNodeKey;
					strVal3 += _T(">");
				}
			}
			if(strPropertys!=_T("")&&it.second->m_strTangramDataXML!=_T(""))
			{
				CString _strPropertys = strPropertys;
				int nPos = _strPropertys.Find(_T(","));
				while(nPos!=-1)
				{
					strProperty = _strPropertys.Left(nPos);
					_strPropertys = _strPropertys.Mid(nPos+1);
					nPos = _strPropertys.Find(_T(","));
					if(strProperty!=_T(""))
					{
						CString strXML = it.second->m_strTangramDataXML;
						int nPos2 = strXML.Find(strProperty);
						if(nPos2!=-1)
						{
							CString str1 = strXML.Mid(nPos2);
							nPos2 = str1.Find(_T("\""));
							str1 = str1.Mid(nPos2+1);
							nPos2 = str1.Find(_T("\""));
							str1 = str1.Left(nPos2);
							CString strFormat = _T("");
							if(m_bNoHandle==false)
								strFormat.Format(_T("<%s handle=\"%d\" objid=\"%s\">%s</%s>"),strProperty,it.second->m_hItem,it.second->m_strTangramItemID,str1,strProperty);
							else
								strFormat.Format(_T("<%s>%s</%s>"),strProperty,str1,strProperty);
							strVal += strFormat;
							nCount++;
						}
					}
				}
			}
		}
		strFormat.Format(_T("</%ss>"),m_strNodeKey);
		strVal2 += strFormat;//_T("</orgs>");
		strFormat.Format(_T("</%ss2>"),m_strNodeKey);
		strVal3 += strFormat;//_T("</orgs2>");
		strFormat.Format(_T("</%ss>"),m_strLeafKey);
		strVal += strFormat;//_T("</Contacts>");
		CString s = _T("");
		CPoint point;
		::GetCursorPos(&point);
		s.Format(_T("<TangramXml PosX=\"%d\" PoxY=\"%d\">"),point.x,point.y);
		s += strVal;
		s += strVal2;
		s += strVal3;
		s +=  _T("</TangramXml>");
		strVal = s;
	}
	return strVal;
}

//=============================================================================
void CTangramHtmlTreeWnd::CheckAll(BOOL bCheck)
//=============================================================================
{
	if (m_bCheckBoxes)
	{
		if (m_bSmartCheck)
		{
			// check all root-level items
			HTREEITEM hRoot = GetRootItem();

			while (hRoot)
			{
				SetCheck(hRoot, bCheck);
				hRoot = GetNextItem(hRoot, TVGN_NEXT);	// get next root item
			}
		}
		else
		{
			// check all items
			HTREEITEM hItem = GetRootItem();

			while (hItem)
			{
				SetCheck(hItem, bCheck);
				hItem = GetNextItem(hItem);		// get next sequential item
			}
		}
	}
}

//=============================================================================
int CTangramHtmlTreeWnd::GetCheckedCount()
//=============================================================================
{
	int rc = 0;

	if (!m_bCheckBoxes)
		return 0;

	for (HTREEITEM hItem = GetRootItem();
		 hItem != NULL; 
		 hItem = GetNextItem(hItem))
	{
		if (GetCheck(hItem))
			rc++;
	}

	return rc;
}

//=============================================================================
int CTangramHtmlTreeWnd::GetChildrenCheckedCount(HTREEITEM hItem)
//=============================================================================
{
	int rc = 0;

	if (!m_bCheckBoxes)
		return 0;

	if (!hItem)
		hItem = GetRootItem();

	if (hItem && m_bSmartCheck)
	{
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD)
		{
			rc = pXTCD->m_nChecked;
		}
	}
	else if (hItem && ItemHasChildren(hItem))
	{
		HTREEITEM hChild = GetChildItem(hItem);
		if (hChild)
		{
			do
			{
				if (GetCheck(hChild))
					rc++;

				rc += GetChildrenCheckedCount(hChild);

			} while ((hChild = GetNextSiblingItem(hChild)) != NULL);
		}
	}

	return rc;
}

//=============================================================================
int CTangramHtmlTreeWnd::GetChildrenDisabledCount(HTREEITEM hItem)
//=============================================================================
{
	int rc = 0;

	if (!hItem)
		hItem = GetRootItem();

	if (hItem && ItemHasChildren(hItem))
	{
		HTREEITEM hChild = GetChildItem(hItem);
		if (hChild)
		{
			do
			{
				if (!IsEnabled(hChild))
					rc++;

				rc += GetChildrenDisabledCount(hChild);

			} while ((hChild = GetNextSiblingItem(hChild)) != NULL);
		}
	}

	return rc;
}

//=============================================================================
int CTangramHtmlTreeWnd::GetChildrenCount(HTREEITEM hItem)
//=============================================================================
{
	int rc = 0;

	if (!hItem)
		hItem = GetRootItem();

	if (hItem && m_bSmartCheck)
	{
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD)
		{
			rc = pXTCD->m_nChildren;
		}
	}
	else if (hItem && ItemHasChildren(hItem))
	{
		HTREEITEM hChild = GetChildItem(hItem);
		if (hChild)
		{
			do
			{
				rc++;
				rc += GetChildrenCount(hChild);

			} while ((hChild = GetNextSiblingItem(hChild)) != NULL);
		}
	}

	return rc;
}

//=============================================================================
int CTangramHtmlTreeWnd::GetSeparatorCount(HTREEITEM hItem)			//+++1.6
//=============================================================================
{
	int rc = 0;

	if (!hItem)
		hItem = GetRootItem();

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		rc = pXTCD->m_nSeparators;
	}

	return rc;
}

//=============================================================================
CString CTangramHtmlTreeWnd::GetItemText(HTREEITEM hItem, BOOL bStripHtml /*= false*/) const
//=============================================================================
{
	CString strText = _T("");

	if (hItem)
	{
		strText = CTreeCtrl::GetItemText(hItem);

		if (bStripHtml)
		{
#ifdef XHTMLHTML
			// remove html tags
			CXHtmlDraw hd;
			int n = strText.GetLength();
			if (n > 3)		// minimum html string
			{
				TCHAR *s = new TCHAR [n + 16];
				hd.GetPlainText(strText, s, n+4);
				strText = s;
				delete [] s;
			}
#endif // XHTMLHTML
		}
	}

	return strText;
}

//=============================================================================
void CTangramHtmlTreeWnd::OnLButtonDown(UINT nFlags, CPoint point)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnLButtonDown\n"));

	UINT uFlags = 0;
	HTREEITEM hItem = HitTest(point, &uFlags);
	HTREEITEM hItemSelected = GetSelectedItem();
	CEdit *pEdit = GetEditControl();

	if (hItem && (TVHT_ONITEMBUTTON & uFlags))
	{
		TRACE(_T("TVHT_ONITEMBUTTON\n"));
		if (pEdit && IsWindow(pEdit->m_hWnd))
		{
			TRACE(_T("sending WM_CLOSE to edit box\n"));
			pEdit->SendMessage(WM_CLOSE);
		}

		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD && !pXTCD->m_bEnabled)
			return;

		if (pXTCD && pXTCD->m_bEnabled && ItemHasChildren(hItem))
		{
			BOOL m_bExpanded = !pXTCD->m_bExpanded;
			Expand(hItem, m_bExpanded ? TVE_EXPAND : TVE_COLLAPSE);
			return;
		}
	}
	else if (hItem && (TVHT_ONITEMSTATEICON & uFlags))
	{
		TRACE(_T("TVHT_ONITEMSTATEICON\n"));
		// click on checkbox
	}
	else if (hItem && IsSeparator(hItem))		//+++1.6
	{
		if (hItem != hItemSelected)
			SelectItem(hItem);

		m_hItemButtonDown = hItem;
		TRACE(_T("setting LBUTTONDOWN_TIMER >>>>>\n"));
		SetTimer(LBUTTONDOWN_TIMER, 100, NULL);
		return;
	}
	else if (hItem && (hItem == hItemSelected))
	{
		// item was already selected, so catch the button up state -
		// this will be start of edit. We don't need to check if disabled, 
		// because disabled items can't be selected
		//
		// NOTE: we use timer because we don't always get WM_LBUTTONUP message.
		//
		m_hItemButtonDown = hItem;
		TRACE(_T("setting LBUTTONDOWN_TIMER >>>>>\n"));
		SetTimer(LBUTTONDOWN_TIMER, 100, NULL);

#ifndef XHTMLDRAGDROP
		// We disable the return to prevent edit box opening on button down -
		// it should open only on button up.
		// For drag & drop, we need to call base function to allow 
		// OnBegindrag() to be called.
		return;
#endif // XHTMLDRAGDROP

	}
#ifdef XHTMLDRAGDROP
	else if (hItem && (hItem != hItemSelected))
	{
		SetTimer(SELECT_TIMER, 50, NULL);
	}
#endif // XHTMLDRAGDROP

	TRACE(_T("calling CTreeCtrl::OnLButtonDown\n"));

	CTreeCtrl::OnLButtonDown(nFlags, point);
}

//=============================================================================
void CTangramHtmlTreeWnd::OnRButtonDown(UINT nFlags, CPoint point) 
//=============================================================================
{
#ifdef XHTMLDRAGDROP
	EndDragScroll();
	SendRegisteredMessage(WM_XHTMLTREE_END_DRAG, 0, 0);
#endif // XHTMLDRAGDROP
	CTreeCtrl::OnRButtonDown(nFlags, point);
}

//=============================================================================
// OnClick - handle clicking on checkbox and link
BOOL CTangramHtmlTreeWnd::OnClick(NMHDR* /*pNMHDR*/, LRESULT* pResult)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnClick\n"));

	BOOL rc = false;	// allow parent to handle

	CPoint point;
	::GetCursorPos(&point);
	ScreenToClient(&point);

	UINT flags = 0;
	HTREEITEM hItem = HitTest(point, &flags);
	TRACE(_T("in CTangramHtmlTreeWnd::OnClick:  hItem=%X\n"), hItem);

	if(hItem)
	{
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
		BOOL bHasChild = ItemHasChildren(hItem);
		if (hItem && !bHasChild)
		{
			//if(pXTCD&&pXTCD->m_strTangramDataURL!=_T(""))
			//{ 
			//	CTangramXmlParse m_Parse;
			//	if(m_Parse.LoadFile(pXTCD->m_strTangramDataURL))
			//	{
			//		int nCount = 0;
			//		LoadXml(&m_Parse, hItem,nCount);
			//		pXTCD->m_strTangramDataURL=_T("");
			//	}
			//}
		}
		if (pXTCD)		// will not be NULL if hItem is valid
		{
			if (pXTCD->m_bSeparator)			//+++1.6
			{
				return true;	// can't set checkbox if separator
			}
			else if (flags & TVHT_ONITEMSTATEICON)
			{
				TRACE(_T("click on checkbox\n"));

				if (pXTCD->m_bEnabled && !m_bReadOnly)
				{
					SetCheck(hItem, !pXTCD->m_bChecked);

					//BOOL bCheck = GetCheck(hItem);
					//TRACE(_T("item %s checked\n"), bCheck ? _T("is") : _T("is not"));

					if (m_bSelectFollowsCheck)
						SelectItem(hItem);

					int nState = GetStateImage(hItem);
					nState |= HDCheckboxImageList::HOT_INDEX;

					SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);

					m_hHotItem = hItem;
				}
				else
				{
					rc = true;
				}
			}
			else
			{
				TRACE(_T("not on checkbox\n"));
				// can't use TVHT_ONITEMLABEL because text might be shifted left
				if (pXTCD->ds.bHasAnchor && pXTCD->m_bEnabled)
				{
					if (IsOverAnchor(hItem, point))
					{
	#ifdef XHTMLHTML
						TRACE(_T("click on link\n"));
						m_Links.GotoURL(pXTCD->ds.pszAnchor, SW_SHOW, (LPARAM)(UINT_PTR)hItem);
	#endif // XHTMLHTML
					}
					else
					{
						TRACE(_T("not in link rect\n"));
					}
				}
				else if (!pXTCD->m_bEnabled)
				{
					TRACE(_T("click on disabled item\n"));
					rc = true;
				}
			}
		}
		if (pXTCD->m_bEnabled)
		{
			CString _strXml = _T("");
			
			IXobj* pRootXobj = NULL;
			if (m_pHostWnd)
			{
				m_pHostWnd->m_pXobj->get_RootXobj(&pRootXobj);
			}
			if (pXTCD->m_strTangramXML != _T("")/*&&m_LasthItem!=hItem*/)
			{
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadXml(pXTCD->m_strTangramXML))
				{
					CString strBindWnds = m_Parse.attr(_T("BindWnds"), _T(""));
					if (strBindWnds != _T(""))
					{
						CTangramXmlParse* pParse = m_Parse.GetChild(_T("BindWnds"));
						if (pParse)
						{
							pXTCD->m_nType |= 0x0001;
							CString strIDs = strBindWnds;// pXTCD->m_strRelationNodes;
							int nPos = strIDs.Find(_T(","));
							long nCount = 0;
							while (nPos != -1)
							{
								CString strKey = strIDs.Left(nPos);
								strIDs = strIDs.Mid(nPos + 1);
								LONGLONG h = 0;
								nPos = strIDs.Find(_T(","));
								if (nPos == -1)
									break;
							}
						}
					}
					pXTCD->m_strRelationNodes = m_Parse.attr(_T("RelationNodes"), _T(""));
					CTangramXmlParse* pParse = m_Parse.GetChild(_T("RelationNodes"));
				}
			}
		}

		*pResult = 0;
		return rc;
	}
	return false;
}

//=============================================================================
// OnRClick - handle clicking on checkbox and link
BOOL CTangramHtmlTreeWnd::OnRClick(NMHDR* /*pNMHDR*/, LRESULT* pResult)
//=============================================================================
{
	BOOL rc = false;	// allow parent to handle
	m_strSelectNodeInfo = GetSelectedNodeInfo(m_strMainKey + _T(","));
	//if(m_pWebBrowser2)
	//{
	//	theApp.m_pWebRTManager->PopupMenu(0,0,CComBSTR(m_pHostWnd->m_strXmlMenuScript),m_pWebBrowser2,(LONGLONG)m_hWnd);
	//}
	//else
	//	::SendMessage(m_hAsynHostWnd,WM_SETMENU,(WPARAM)m_strSelectNodeInfo.GetBuffer(),0);
	m_strSelectNodeInfo.ReleaseBuffer();
	CPoint point;
	::GetCursorPos(&point);
	ScreenToClient(&point);

	UINT flags = 0;
	HTREEITEM hItem = HitTest(point, &flags);
	return false;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::OnDblclk(NMHDR* /*pNMHDR*/, LRESULT* pResult) 
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnDblclk\n"));
	BOOL rc = false;	// allow parent to handle

	CPoint point;
	::GetCursorPos(&point);
	ScreenToClient(&point);

	UINT flags = 0;
	HTREEITEM hItem = HitTest(point, &flags);
	TRACE(_T("in CTangramHtmlTreeWnd::OnDblclk:  hItem=%X\n"), hItem);
	//if (hItem)
	//{
	//	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	//	if (pXTCD && pXTCD->m_bEnabled && ItemHasChildren(hItem)&&pXTCD->m_hWaitItemMsg)
	//	{
	//		BOOL m_bExpanded = !pXTCD->m_bExpanded;
	//		Expand(hItem, m_bExpanded ? TVE_EXPAND : TVE_COLLAPSE);
	//		return false;
	//	}
	//}


	if (hItem && (flags & (TVHT_ONITEM | TVHT_ONITEMBUTTON | TVHT_ONITEMSTATEICON)))
	{
		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
		
		IXobj* pRootXobj=NULL;
		if (m_pHostWnd)
		{
			m_pHostWnd->m_pXobj->get_RootXobj(&pRootXobj);
		}

		if (pXTCD && !pXTCD->m_bEnabled)
		{
			TRACE(_T("double click on disabled item\n"));
			rc = true;		// don't allow default processing
		}
		else 
		{
			BOOL bHasChild = ItemHasChildren(hItem);
			if (pXTCD && pXTCD->m_bEnabled && bHasChild)
			{
				if(pXTCD->m_hWaitItemMsg)
				{
					BOOL m_bExpanded = !pXTCD->m_bExpanded;
					Expand(hItem, TVE_COLLAPSE);
					//pXTCD->m_bHasBeenExpanded = true;
					//Expand(hItem, m_bExpanded ? TVE_EXPAND : TVE_COLLAPSE);
					//pXTCD->m_bExpanded = false;
				}
				else
				{
					pXTCD->m_bExpanded = !pXTCD->m_bExpanded;
					pXTCD->m_bHasBeenExpanded = true;
					SendRegisteredMessage(WM_XHTMLTREE_ITEM_EXPANDED, hItem, 
						pXTCD->m_bExpanded);
				}
				//pXTCD->bExpanded = !pXTCD->bExpanded;
				//pXTCD->bHasBeenExpanded = true;
				//SendRegisteredMessage(WM_XHTMLTREE_ITEM_EXPANDED, hItem, 
				//	pXTCD->bExpanded);
			}
			if (bHasChild == false)
			{
				if (pXTCD->m_strTangramXML != _T("")/*&&m_LasthItem!=hItem*/)
				{
					
				}
			}
		}
		
	}

	*pResult = rc;	
	return rc;
}


//=============================================================================
BOOL CTangramHtmlTreeWnd::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
//=============================================================================
{
	BOOL rc = false;	// allow parent to handle

	NMTREEVIEW* pNMTreeView = (NMTREEVIEW*)pNMHDR;
	
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	m_LasthItem = hItem;
	HTREEITEM hOldItem = pNMTreeView->itemOld.hItem;

	CString strItem = GetItemText(hItem);
	TRACE(_T("in CTangramHtmlTreeWnd::OnSelchanged:  <%s>\n"), strItem);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if(pXTCD->m_strTangramXML!=_T("")/*&&m_LasthItem!=hItem*/)
	{
		CTangramXmlParse m_Parse;
		if(m_Parse.LoadXml(pXTCD->m_strTangramXML))
		{
			CString strProperty = m_Parse.attr(_T("CallBack"),_T(""));
			if(strProperty!=_T(""))
			{
				if(m_pObj)
				{
					m_Parse.put_attr(_T("TreeViewHandle"),(__int64)hItem);
					m_Parse.put_attr(_T("TreeViewWndHandle"),(__int64)m_hWnd);
					auto it = m_pObj->m_mapWebRTTreeViewCallBack.end();
					for(it = m_pObj->m_mapWebRTTreeViewCallBack.begin(); it!=m_pObj->m_mapWebRTTreeViewCallBack.end();it++)
					{
						BSTR bstrXml = pXTCD->m_strTangramXML.AllocSysString();
						it->second->OnClick(m_Parse.xml().AllocSysString(),CComBSTR(L""));
						::SysFreeString(bstrXml);
					}
					::SetFocus(m_hWnd);
					if (pXTCD && !pXTCD->m_bEnabled)
					{
						if (hOldItem)
						{
							SelectItem(hOldItem);
						}
						rc = true;
					}
					else
					{
						if (hItem == m_hPreviousItem)
							rc = true;
					}
					
					if (!rc)
						m_hPreviousItem = hItem;

					::PostMessage(m_hWnd,WM_REFRESHDATA,0,1);
					*pResult = rc;
					return rc;
				}
			}
			else
			{
				CComPtr<IXobj> pRootXobj;
				if (m_pHostWnd)
				{
					m_pHostWnd->m_pXobj->get_RootXobj(&pRootXobj);
				}
				
				pXTCD->m_strRelationNodes = m_Parse.attr(_T("RelationNodes"),_T(""));
				CTangramXmlParse* pParse = m_Parse.GetChild(_T("RelationNodes"));
				
				::SetFocus(m_hWnd);
				if (pXTCD && !pXTCD->m_bEnabled)
				{
					if (hOldItem)
					{
						SelectItem(hOldItem);
					}
					rc = true;
				}
				else
				{
					if (hItem == m_hPreviousItem)
						rc = true;
				}

				if (!rc)
					m_hPreviousItem = hItem;

				::PostMessage(m_hWnd, WM_REFRESHDATA, 0, 1);
				*pResult = rc;
				return rc;
			}
		}
		if(m_pNucleus==NULL)
		{
			//IXobj* pXobj = NULL;
			//::SetWindowText(::GetParent(m_hWnd),_T("TangramTop"));
			////theApp.m_pWebRTManager->NavigateXTML((LONGLONG)m_hWnd,CComBSTR(pXTCD->m_strTangramXML),&pXobj);
			//m_bAttached = true;
			//if(m_pNucleus==NULL)
			//{
			//	HRESULT hr = pXobj->get_WinNucleus(&m_pNucleus);
			//	if(hr==S_OK)
			//		m_pNucleus->AddRef();
			//}
		}
		if(m_hPreviousItem != hItem)
		{
			if(m_bAttached==false)
			{
				m_pNucleus -> Attach();
			}
			m_bAttached = true;
			IXobj* pXobj = NULL;
			//theApp.m_pWebRTManager->NavigateXTML((long)m_hWnd,CComBSTR(pXTCD->m_strTangramXML),&pXobj);
		}
	}
	else if(pXTCD->m_strTangramXML==_T("")&&m_bAttached)
	{
		if(m_pNucleus&&m_hPreviousItem)
		{
			//m_pNucleus->Deatch();
			m_bAttached = false;
		}
	}

	::SetFocus(m_hWnd);
	if (pXTCD && !pXTCD->m_bEnabled)
	{
		if (hOldItem)
		{
			SelectItem(hOldItem);
		}
		rc = true;
	}
	else
	{
		if (hItem == m_hPreviousItem)
			rc = true;
	}
	
	if (!rc)
		m_hPreviousItem = hItem;

	::PostMessage(m_hWnd,WM_REFRESHDATA,0,1);
	*pResult = rc;
	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult) 
//=============================================================================
{
	BOOL rc = false;	// allow parent to handle

	NMTREEVIEW* pNMTreeView = (NMTREEVIEW*)pNMHDR;
	
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;

	CString strItem = GetItemText(hItem);
	TRACE(_T("in CTangramHtmlTreeWnd::OnSelchanging:  <%s>\n"), strItem);

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	if (pXTCD && !pXTCD->m_bEnabled)
	{
		rc = true;
	}

	*pResult = rc;
	return rc;
}

//=============================================================================
void CTangramHtmlTreeWnd::OnSize(UINT nType, int cx, int cy) 
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnSize\n"));

	CTreeCtrl::OnSize(nType, cx, cy);
	if(m_nHeight!=cy)
	{
		m_nHeight = cy;
		::PostMessage(m_hWnd,WM_REFRESHDATA,0,1);
		//GetProperty(_T("VisibleNode"));
	}

	m_bFirstTime = true;	// this will cause tooltips to be re-created
}

//=============================================================================
int CTangramHtmlTreeWnd::GetIndentLevel(HTREEITEM hItem)
//=============================================================================
{
	int nIndent = 0;

	while ((hItem = GetParentItem(hItem)) != NULL)
		nIndent++;

	return nIndent;
}

#ifdef XHTMLXML

//=============================================================================
BOOL CTangramHtmlTreeWnd::ConvertBuffer(const BYTE * inbuf, 
							   DWORD inlen,				// in bytes
							   BYTE ** outbuf,
							   DWORD& outlen,			// in bytes
							   ConvertAction eConvertAction /*= NoConvertAction*/)
//=============================================================================
{
	BOOL rc = false;

	ASSERT(inbuf);
	ASSERT(inlen != 0);

	outlen = 0;

	if (inbuf && (inlen != 0))
	{
		TRACE(_T("eConvertAction=%d\n"), eConvertAction);

		// copy buffer to ensure it's null terminated
		BYTE * buf = new BYTE [inlen+16];
		memset(buf, 0, inlen+16);
		memcpy(buf, inbuf, inlen);

		if (eConvertAction == ConvertToUnicode)
		{
			TRACE(_T("converting to unicode\n"));
			int wlen = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)buf, -1, NULL, 0);
			TRACE(_T("wlen=%d\n"), wlen);
			WCHAR *pszText = new WCHAR [wlen+16];
			memset(pszText, 0, (wlen+16) * sizeof(WCHAR));
			MultiByteToWideChar(CP_ACP, 0, (LPCSTR)buf, -1, pszText, wlen+2);
			outlen = (DWORD)wcslen(pszText) * sizeof(WCHAR);	// bytes
			*outbuf = (BYTE*) pszText;
			delete [] buf;
		}
		else if (eConvertAction == ConvertToAnsi)
		{
			TRACE(_T("converting to ansi\n"));
			LPCWSTR wp = (LPCWSTR) buf;
			int alen = WideCharToMultiByte(CP_ACP, 0, wp, -1, NULL, 0, NULL, NULL);
			TRACE(_T("alen=%d\n"), alen);
			char *pszText = new char [alen+16];
			memset(pszText, 0, alen+16);
			WideCharToMultiByte(CP_ACP, 0, wp, -1, pszText, alen+2, NULL, NULL);
			outlen = (DWORD)strlen(pszText);	// bytes
			*outbuf = (BYTE*) pszText;
			delete [] buf;
		}
		else
		{
			// no conversion
			outlen = inlen;						// bytes
			*outbuf = buf;
		}

		TRACE(_T("outlen=%d\n"), outlen);

		rc = true;
	}

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::LoadXmlFromFile(LPCTSTR lpszFile, ConvertAction eConvertAction)
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::LoadXmlFromFile: %s\n"), lpszFile);

	BOOL rc = false;

	ASSERT(lpszFile);

	if (lpszFile)
	{
		CTangramXmlParse m_Parse;
		if(m_Parse.LoadFile(lpszFile))
		{
			HTREEITEM hRoot = InsertXmlItem(&m_Parse, 0);
			LoadXml(&m_Parse, hRoot, m_nXmlCount);
		}
	}
	else
	{
		TRACE(_T("ERROR - bad parameter\n"));
	}

	//if (hFile)
	//	CloseHandle(hFile);

	return rc;
}


//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::LoadXmlFromString(LPCTSTR lpszXML, ConvertAction eConvertAction)
//=============================================================================
{
	BOOL rc = false;
	HTREEITEM hFirstRoot = 0;
	if (lpszXML!=NULL)
	{
		CTangramXmlParse m_Parse;
		if(m_Parse.LoadXml(lpszXML))
		{
			CString strURL = m_Parse.attr(_T("url"),_T(""));
			if(strURL==_T(""))
			{
				int nCount = m_Parse.GetCount();
				for(int i=0;i<nCount;i++)
				{
					HTREEITEM hRoot = InsertXmlItem(m_Parse.GetChild(i), 0);
					if(hFirstRoot==NULL)
						hFirstRoot = hRoot;
					LoadXml(m_Parse.GetChild(i), hRoot, m_nXmlCount);
				}
				return hFirstRoot;
			}
			else
			{
				m_strURL = strURL;

				CTangramXmlParse* pParse = m_Parse.GetChild(_T("TangramRest"));
				//CString strHeaderXml = pXTCD->m_strTangramHeader;

				if (pParse)
				{
					//CComPtr<IWebRTRestObj> p;
					//p.CoCreateInstance(CComBSTR(L"TangramEx.TangramRestObj.1"));
					//if (p)
					//{
					//	IWebRTRestObj* m_pWebRTRestObj = p.Detach();
					//	m_pWebRTRestObj->put_Header(CComBSTR(_T("UserID")), CComBSTR(theApp.m_strUserID));
					//	//CString strHandle = _T("");
					//	//strHandle.Format(_T("%p"), (LONGLONG)hItem);
					//	//m_pWebRTRestObj->put_Header(CComBSTR(_T("TreeItem")), CComBSTR(strHandle));
					//	CTangramXmlParse* pHeaders = m_Parse.GetChild(_T("Headers"));
					//	if (pHeaders)
					//	{
					//		CTangramXmlParse* pChild = NULL;
					//		int nCount = pHeaders->GetCount();
					//		for (int i = 0; i<nCount; i++)
					//		{
					//			pChild = pHeaders->GetChild(i);
					//			m_pWebRTRestObj->put_Header(CComBSTR(pChild->attr(_T("key"), _T(""))), CComBSTR(pChild->attr(_T("value"), _T(""))));
					//		}
					//	}
					//	//m_pWebRTRestObj->put_Header(CComBSTR(L"FileId"), CComBSTR(_strID));
					//	CComQIPtr<IRestNotify> pCloudAddinRestNotify(this->m_pHostWnd->m_pXobj);
					//	m_pWebRTRestObj->put_NotifyHandle((LONGLONG)m_hWnd);
					//	m_pWebRTRestObj->RestData(1, strURL.AllocSysString(), L"", L"", 0);
					//}
				}
				//else if (theApp.m_pWebRTManager)
				//{
				//	if(m_strMainKey==_T(""))
				//	{
				//		m_strMainKey = m_Parse.attr(_T("MainKey"),_T("Sip"));
				//		m_bNoHandle = m_Parse.attrBool(_T("NoHandle"),true);
				//		m_strLeafKey =  m_Parse.attr(_T("Leaf"),_T("Contact"));
				//		m_strNodeKey =  m_Parse.attr(_T("Node"),_T("org"));
				//		m_strNode2Key =  m_Parse.attr(_T("Node2"),_T("org2"));
				//	}
				//	CString strAsynXml = _T("");
				//	CString strObjID = _T("");
				//	if(m_pHostWnd&&m_pHostWnd->m_pXobj)
				//	{
				//		CComBSTR bstrID(L"");
				//		m_pHostWnd->m_pXobj->get_Attribute(CComBSTR(L"AsynObjID"),&bstrID);
				//		strObjID = OLE2T(bstrID);
				//		strObjID.Trim();
				//		if(strObjID==_T(""))
				//			strObjID = _T("TangramLyncPlus.LyncPlusAsynProxy.1");
				//	}
				//	strAsynXml.Format(_T("<AsynBottomObj ID=\"%s-%x\" ObjID=\"shell.explorer.2\" ExtID=\"%s\" URL=\"%s\" Visible=\"0\"/>"),_T("TangramTreeRoot"),m_hWnd,strObjID,strURL);
				//	if(theApp.m_pAppDisp)
				//		theApp.m_pWebRTManager->CreateAsynObject(CComBSTR(strAsynXml),theApp.m_pAppDisp,CComBSTR(L""),(LONGLONG)m_hWnd);
				//	else
				//		theApp.m_pWebRTManager->CreateAsynObject(CComBSTR(strAsynXml),theApp.m_pWebRTManager,CComBSTR(L""),(LONGLONG)m_hWnd);
				//}
			}
		}
	}
	else
	{
		TRACE(_T("ERROR - bad parameter\n"));
	}
	return hFirstRoot;
}

//=============================================================================
HTREEITEM CTangramHtmlTreeWnd::LoadXmlFromXmlParse(CTangramXmlParse* pParse)
//=============================================================================
{
	BOOL rc = false;
	HTREEITEM hFirstRoot = 0;
	if (pParse !=NULL)
	{
		{
			CString strURL = pParse->attr(_T("url"),_T(""));
			if(strURL==_T(""))
			{
				int nCount = pParse->GetCount();
				for(int i=0;i<nCount;i++)
				{
					CTangramXmlParse* pChild = pParse->GetChild(i);
					CString strName = pChild->name();
					if (strName.CompareNoCase(_T("TangramScript"))&& strName.CompareNoCase(_T("TangramMenuScript"))&&strName.CompareNoCase(_T("TangramProperty")))
					{
						HTREEITEM hRoot = InsertXmlItem(pChild, 0);
						if(hFirstRoot==NULL)
							hFirstRoot = hRoot;
						LoadXml(pChild, hRoot, m_nXmlCount);
					}
				}
				return hFirstRoot;
			}
		}
	}
	else
	{
		TRACE(_T("ERROR - bad parameter\n"));
	}
	return hFirstRoot;
}

HTREEITEM	CTangramHtmlTreeWnd::InsertXmlItem(CTangramXmlParse *pElement, HTREEITEM hParent)
{
	TRACE(_T("in CTangramHtmlTreeWnd::InsertXmlItem\n"));

	HTREEITEM hItem = 0;

	ASSERT(pElement);
	if (pElement)
	{
		CString strItemText = pElement->attr(_T("treecaption"), _T(""));
		CString strName = pElement->attr(_T("name"),_T(""));
		CString strNodeName = pElement->name();
		TRACE(_T("InsertXmlItem: <%s>\n"), strName);
		if (strName == _T(""))
			strName = strNodeName;

		if (strItemText == _T(""))
			strItemText = strName;
		// hack to stop display
		if (/*!strName.IsEmpty() &&*/ strItemText.Compare(_T("...")) != 0)
		{
			strName.TrimLeft();
			strName.TrimRight();

#if 0  // -----------------------------------------------------------
			if (strName.GetLength() <= 0)
			{
				TRACE(_T("ERROR - name is empty\n"));
				ASSERT(false);
			}
#endif // -----------------------------------------------------------

			CTangramXHtmlTreeNode xhtd;
			if (m_pHostXmlParse)
			{
				xhtd.m_pXmlParse = pElement;
			}
			xhtd.m_strName = strNodeName;
			xhtd.m_bWaitingFor = pElement->attrBool(_T("needfill"),false);
			if (xhtd.m_bWaitingFor)
			{
				xhtd.m_strTangramDataURL = pElement->attr(_T("url"),_T(""));
				xhtd.m_strTangramItemID = pElement->attr(TGM_GRID_TYPE,_T(""));
			}
			//if (strNodeName == TGM_NUCLEUS)
			//{

			//}
			//else if(strNodeName ==TGM_XOBJ)
			//{
			//	xhtd.m_strTangramXML = pElement->xml();
			//}
			CTangramXmlParse* pParse = pElement->GetChild(_T("headers"));
			if (pParse != NULL)
			{
				xhtd.m_strTangramHeader = pParse->xml();
				pElement->RemoveNode(pParse);
			}
			CString strSeparator = pElement->attr(_T("separator"),_T(""));
			if (!strSeparator.IsEmpty())
				xhtd.m_bSeparator = _ttoi(strSeparator);
			CString strChecked = pElement->attr(_T("checked"),_T(""));
			if (!strChecked.IsEmpty() && !xhtd.m_bSeparator)
				xhtd.m_bChecked = _ttoi(strChecked);
			CString strEnabled = pElement->attr(_T("enabled"),_T(""));
			if (!strEnabled.IsEmpty() && !xhtd.m_bSeparator)
				xhtd.m_bEnabled = _ttoi(strEnabled);
			TRACE(_T("name=<%s>, <%s>, <%s> \n"), strName, strChecked, strEnabled);
			TRACE(_T("m_bChecked=%d  m_bEnabled=%d  m_bSeparator=%d\n"), xhtd.m_bChecked, xhtd.m_bEnabled, xhtd.m_bSeparator);

			// get colors - must be named colors, e.g. "red"
			CString strTextColor = pElement->attr(_T("text-color"),_T(""));
			CString strBackgroundColor = pElement->attr(_T("text-background-color"),_T(""));

			if (!strTextColor.IsEmpty())
			{
				CXNamedColors crText(strTextColor);
				xhtd.ds.crText = crText.GetRGB();
			}

			if (!strBackgroundColor.IsEmpty())
			{
				CXNamedColors crBackground(strBackgroundColor);
				xhtd.ds.crTextBackground = crBackground.GetRGB();
			}

			int nImage = -1;
			CString strImage = pElement->attr(_T("image"),_T(""));
			if (!strImage.IsEmpty() && !xhtd.m_bSeparator)
			{
				nImage = _ttoi(strImage);
				CImageList *pImageList = GetImageList(TVSIL_NORMAL);
				if (pImageList)		//+++1.5
				{
					int nCount = pImageList->GetImageCount();
					if (nImage >= nCount)
					{
						TRACE(_T("ERROR - invalid image\n"));
						ASSERT(false);
						nImage = -1;
					}
				}
				else
				{
					TRACE(_T("WARNING  no image list, setting m_bImages to false\n"));
					m_bImages = false;
				}
			}

			//static int nItem = 1;

			// line not empty - add item
			TVINSERTSTRUCT tvis      = { 0 };
			if (!xhtd.m_bSeparator)
			{
				tvis.item.mask       = TVIF_TEXT;
				tvis.item.cchTextMax = strItemText.GetLength();
				tvis.item.pszText    = strItemText.LockBuffer();
			}
			tvis.hParent             = hParent;
			tvis.item.iImage         = TV_NOIMAGE;
			tvis.item.iSelectedImage = TV_NOIMAGE;
			tvis.item.mask          |= TVIF_IMAGE | TVIF_SELECTEDIMAGE;
			//tvis.item.mask          |= TVIF_PARAM;
			//tvis.item.lParam         = nItem++;		// for debugging

			if (m_bImages && (nImage != -1) && !xhtd.m_bSeparator)		//+++1.5
			{
				tvis.item.iImage = tvis.item.iSelectedImage = nImage;
			}

			pParse = pElement->GetChild(_T("TangramScript"));
			if(pParse!=NULL)
			{
				xhtd.m_strTangramXML = pParse->xml();
				//pElement->RemoveNode(pParse);
			}
			pParse = pElement->GetChild(_T("TangramMenuScript"));
			if(pParse!=NULL)
			{
				xhtd.m_strTangramMenuXML = pParse->xml();
				//pElement->RemoveNode(pParse);
			}
			pParse = pElement->GetChild(_T("TangramProperty"));
			if(pParse!=NULL)
			{
				xhtd.m_strTangramDataXML = pParse->xml();
				//pElement->RemoveNode(pParse);
			}
			hItem = InsertItem(&tvis, &xhtd);
			ASSERT(hItem);

			if (!xhtd.m_bSeparator)
				strItemText.UnlockBuffer();

			if (hItem)
			{
				if (xhtd.m_bSeparator)
				{
					SetItemState(hItem, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

					// increment separator count in parents
					HTREEITEM hParentSep = hItem;
					while ((hParentSep = GetParentItem(hParentSep)) != NULL)
					{
						IncrementSeparators(hParentSep, 1);
					}
				}
				else
				{
					CString strNote = pElement->attr(_T("note"),_T(""));
					int nNoteWidth = 0;
					CString strNoteWidth = pElement->attr(_T("note-width"),_T(""));
					if (!strNoteWidth.IsEmpty())
						nNoteWidth = _ttoi(strNoteWidth);
					if (!strNote.IsEmpty())
						SetItemNote(hItem, strNote, nNoteWidth);
				}
			}
		}
	}
	return hItem;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::LoadXml(CTangramXmlParse *pElement, HTREEITEM hParent, int& nCount)
//=============================================================================
{
	BOOL rc = true;

	ASSERT(pElement);
	if (pElement)
	{
		int nIndex = 0;
		int nCount = pElement->GetCount();
		for(int i=0;i<nCount;i++)
		{
			CTangramXmlParse* pChild = pElement->GetChild(i);
			CString strName = pChild->name();
			if (strName.CompareNoCase(_T("TangramScript")) && strName.CompareNoCase(_T("TangramMenuScript")) && strName.CompareNoCase(_T("TangramProperty")))

			{
				HTREEITEM hItem = InsertXmlItem(pChild, hParent);

				if (!hItem)
				{
					// found '...'
					rc = false;
					break;
				}

				rc = LoadXml(pChild, hItem, nCount);
				if (!rc)
					break;
			}
		}
	}

	return rc;
}

//=============================================================================
CString CTangramHtmlTreeWnd::GetXmlText(HTREEITEM hItem, LPCTSTR lpszElem)
//=============================================================================
{
	ASSERT(lpszElem);

	CString strElem = lpszElem;

	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

	CString s = _T("");

	s = GetItemText(hItem);
	s.Replace(_T("&"), _T("&amp;"));
	s.Replace(_T("<"), _T("&lt;"));
	s.Replace(_T(">"), _T("&gt;"));
	s.Replace(_T("\""), _T("&quot;"));

	CString strXml = _T("");
	strXml.Format(_T("<%s name=\"%s\""), strElem, s);

	if (pXTCD)
	{
		s.Format(_T(" separator=\"%s\""), pXTCD->m_bSeparator ? _T("1") : _T("0"));
		strXml += s;

		s.Format(_T(" checked=\"%s\""), pXTCD->m_bChecked ? _T("1") : _T("0"));
		strXml += s;

		s.Format(_T(" enabled=\"%s\""), pXTCD->m_bEnabled ? _T("1") : _T("0"));
		strXml += s;

		if (pXTCD->ds.crText != COLOR_NONE)
		{
			TCHAR szColor[50];
			szColor[0] = _T('\0');
			CXNamedColors nc(pXTCD->ds.crText);
			if (nc.IsKnownColor())
				nc.GetName(szColor, sizeof(szColor)/sizeof(TCHAR)-1);
			else
				nc.GetHex(szColor, sizeof(szColor)/sizeof(TCHAR)-1);
			if (szColor[0] != _T('\0'))
			{
				s.Format(_T(" text-color=\"%s\""), szColor);
				strXml += s;
			}
		}

		if (pXTCD->ds.crTextBackground != COLOR_NONE)
		{
			TCHAR szColor[50];
			szColor[0] = _T('\0');
			CXNamedColors nc(pXTCD->ds.crTextBackground);
			if (nc.IsKnownColor())
				nc.GetName(szColor, sizeof(szColor)/sizeof(TCHAR)-1);
			else
				nc.GetHex(szColor, sizeof(szColor)/sizeof(TCHAR)-1);
			if (szColor[0] != _T('\0'))
			{
				s.Format(_T(" text-background-color=\"%s\""), szColor);
				strXml += s;
			}
		}
	}
	 
	int nImage, nSelectedImage;
	GetItemImage(hItem, nImage, nSelectedImage);

	if (nImage != TV_NOIMAGE)
	{
		s.Format(_T(" image=\"%d\""), nImage);
		strXml += s;
	}

	s = GetItemNote(hItem);
	if (!s.IsEmpty())
	{
		s.Replace(_T("&"), _T("&amp;"));
		s.Replace(_T("<"), _T("&lt;"));
		s.Replace(_T(">"), _T("&gt;"));
		s.Replace(_T("\""), _T("&quot;"));

		strXml += _T(" note=\"");
		strXml += s;
		strXml += _T("\"");

		int nNoteWidth = 0;
		if (pXTCD)
			nNoteWidth = pXTCD->m_nTipWidth;
		if (nNoteWidth)
		{
			s.Format(_T(" note-width=\"%d\""), nNoteWidth);
			strXml += s;
		}
	}

	return strXml;
}

#endif	// XHTMLXML


//=============================================================================
LRESULT CTangramHtmlTreeWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
//=============================================================================
{
	LRESULT rc = CTreeCtrl::WindowProc(message, wParam, lParam);
	return rc;
}

//=============================================================================
// This function does special processing for bTextOnly=true, since
// the text rect is shifted left when there is no image.
//
BOOL CTangramHtmlTreeWnd::GetItemRect(HTREEITEM hItem, LPRECT lpRect, BOOL bTextOnly)
//=============================================================================
{
	BOOL rc = CTreeCtrl::GetItemRect(hItem, lpRect, bTextOnly);

	if (bTextOnly)
	{
		int width = GetNormalImageWidth(hItem);		// get width of normal image

		if (width < 0)
		{
			// TV_NOIMAGE specified, shift text to the left
			lpRect->left += width;
			lpRect->right += width;
		}

		CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);

		if (pXTCD)
		{
			lpRect->right = pXTCD->ds.nRightX;
		}

		//TRACERECT(*lpRect);
	}
	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::OnBeginlabeledit(NMHDR* /*pNMHDR*/, LRESULT* pResult) 
//=============================================================================
{
	*pResult = 0;

	HTREEITEM hItem = IsOverItem();

	TRACE(_T("in CTangramHtmlTreeWnd::OnBeginlabeledit: %X\n"), hItem);

	if (hItem && IsSeparator(hItem))	//+++1.6
	{
		*pResult =  1;		// separator item, don't allow edit
	}
	else if (m_bReadOnly)
	{
		*pResult =  1;		// tree is read-only, don't allow edit
	}
	else
	{
		m_nHorzPos = GetScrollPos(SB_HORZ);	// save initial scroll position
	}
	return (BOOL)*pResult;	// 0 = allow parent to handle
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::OnEndlabeledit(NMHDR* /*pNMHDR*/, LRESULT* pResult) 
//=============================================================================
{
	TRACE(_T("in CTangramHtmlTreeWnd::OnEndlabeledit\n"));
	
	*pResult = 0;
	if ((m_nHorzPos == 0) && (GetScrollPos(SB_HORZ) != 0))
		SendMessage(WM_HSCROLL, SB_LEFT);	// editing caused tree to be 
											// scrolled, so scroll it back
	return 0;								// 0 = allow parent to handle
}

//=============================================================================
// following code contributed by David McMinn
BOOL CTangramHtmlTreeWnd::OnCommand(WPARAM wParam, LPARAM lParam)
//=============================================================================
{
	CEdit *pEdit = GetEditControl();
	if (((HIWORD(wParam) == EN_SETFOCUS) || (HIWORD(wParam) == EN_CHANGE))  && 
		pEdit && 
		(pEdit->GetSafeHwnd() == (HWND)lParam))
	{
		AdjustEditRect();
	}
	return CTreeCtrl::OnCommand(wParam, lParam);
}

//=============================================================================
// AdjustEditRect() moves the in-place edit box to line up with item text
//
void CTangramHtmlTreeWnd::AdjustEditRect()
//=============================================================================
{
	CEdit *pEdit = GetEditControl();

	if (pEdit && IsWindow(pEdit->m_hWnd))
	{
		HTREEITEM hItemEdit = GetSelectedItem();
		if (hItemEdit)
		{
			// adjust position of edit box for all items, even
			// those with image
			CRect rectClient;
			GetClientRect(&rectClient);
			CRect rectEdit;
			GetItemRect(hItemEdit, &rectEdit, true);
			rectEdit.InflateRect(1, 1);				// allow for border
			rectEdit.OffsetRect(-1, -1);			// overlay existing text
			if (rectEdit.left < 0)
				rectEdit.left = 0;
			rectEdit.right = rectClient.right - 1;	// extend edit box full width
													// of tree control
			pEdit->MoveWindow(&rectEdit);
		}
	}
}

#ifdef XHTMLDRAGDROP

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsCtrlDown()
//=============================================================================
{
	BOOL rc = false;

	// always return false if XHTMLTREE_DO_CTRL_KEY is not set
	if (m_dwDragOps & XHTMLTREE_DO_CTRL_KEY)
		if (GetAsyncKeyState(VK_CONTROL) < 0)
			rc = true;

	return rc;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::IsDragCopy()
//
// returns true if copy, false if move
//
//  Ctrl key    COPY_DRAG flag    Action
// ----------+------------------+--------
//     up    |      false       |  move
//    down   |      false       |  copy
//     up    |      true        |  copy
//    down   |      true        |  move
//=============================================================================
{
	BOOL rc = false;

	BOOL bCopyDrag = GetBit(m_dwDragOps, XHTMLTREE_DO_COPY_DRAG);
	BOOL bCtrlDown = IsCtrlDown();

	if (bCtrlDown && !bCopyDrag)		// Ctrl down, !bCopyDrag: copy
		rc = true;
	else if (!bCtrlDown && bCopyDrag)	// Ctrl up, bCopyDrag: copy
		rc = true;

	return rc;
}

//=============================================================================
HCURSOR CTangramHtmlTreeWnd::GetDragCursor()
//=============================================================================
{
	BOOL bCopyDrag = IsDragCopy();

	HCURSOR hCursor = bCopyDrag ? m_hDropCopyCursor : m_hDropMoveCursor;

	return hCursor;
}

LRESULT CTangramHtmlTreeWnd::OnDesignNode(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CTangramHtmlTreeWnd::OnGetWebRTXmlParse(WPARAM wParam, LPARAM lParam)
{
	return (LRESULT)m_pHostXmlParse;
}

LRESULT CTangramHtmlTreeWnd::OnInsertXMLNode(WPARAM wParam, LPARAM lParam)
{
	CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct((HTREEITEM)lParam);
	//if (m_hCurSelectedItem && !ItemHasChildren(m_hCurSelectedItem))
	if (pXTCD && pXTCD->m_hItem && !ItemHasChildren(pXTCD->m_hItem))
	{
		if(pXTCD&&pXTCD->m_strTangramDataURL!=_T(""))
		{
			CTangramXmlParse m_Parse;
			if(m_Parse.LoadFile(pXTCD->m_strTangramDataURL))
			{
				int nCount = 0;
				LoadXml(&m_Parse, pXTCD->m_hItem,nCount);
				pXTCD->m_strTangramDataURL=_T("");
				m_hCurSelectedItem=NULL;
			}
		}
	}
	return -1;
}

LRESULT CTangramHtmlTreeWnd::OnGetSelectedNodeInfo(WPARAM wParam, LPARAM lParam)
{
	CString str = (LPCTSTR)wParam;
	m_strSelectNodeInfo = GetSelectedNodeInfo(str);
	return (LRESULT)LPCTSTR(m_strSelectNodeInfo);
	//return 0;
}

LRESULT CTangramHtmlTreeWnd::OnUpdateXMLNode(WPARAM wParam, LPARAM lParam)
{
	if (lParam == 1992)//for designer
	{
		CString strXml = (LPCTSTR)wParam;
		DeleteItem(m_hFirstRoot);

		if (m_pHostXmlParse)
		{
			delete m_pHostXmlParse;
		}
		m_pHostXmlParse = new CTangramXmlParse();
		m_pHostXmlParse->LoadXml(strXml);
		m_hFirstRoot = LoadXmlFromXmlParse(m_pHostXmlParse);
		ExpandAll();
	}
	return 0;
}

LRESULT CTangramHtmlTreeWnd::OnInsertData(WPARAM wParam, LPARAM lParam)
{
	if (lParam == 0)
	{
		DesignerData* pData = (DesignerData*)wParam;
		CString strXml = pData->m_strXml;
		if (strXml != _T(""))
		{
			if(m_hFirstRoot)
				DeleteItem(m_hFirstRoot);
			if (m_pHostXmlParse)
			{
				delete m_pHostXmlParse;
			}
			m_pHostXmlParse = new CTangramXmlParse();
			m_pHostXmlParse->LoadXml(strXml);
			m_hFirstRoot = LoadXmlFromXmlParse(m_pHostXmlParse);
			ExpandAll();
		}

		delete pData;
		return 0;
	}
	CString strData = (LPCTSTR)wParam;
	CString strID = (LPCTSTR)lParam;
	int nPos = strData.Find(_T("Action=\""));
	//if(strID.Find(_T("<Data>"))==0||nPos!=-1)
	//{
	//	CString strAction = _T("");
	//	strData = strData.Mid(nPos+8);
	//	nPos = strData.Find(_T("\""));
	//	strAction = strData.Left(nPos);
	//	nPos = strData.Find(_T(">"));
	//	strData = strData.Mid(nPos+1);
	//	nPos = strData.Find(_T("</Data>"));
	//	strData = strData.Left(nPos);
	//	nPos = strID.Find(_T("><"));
	//	CString s = strID.Mid(nPos+2);
	//	nPos = s.Find(_T(">"));
	//	s = s.Left(nPos);
	//	CString s1 = _T("");
	//	s1.Format(_T("<Data><%s>"),s);
	//	strID.Replace(s1,_T(""));
	//	s1.Format(_T("</%s>"),s);
	//	strID.Replace(s1,_T(";"));
	//	strID += strData;
	//	::SendMessage(theApp.m_hMainWnd,WM_LYNCACTION,(WPARAM)strID.GetBuffer(),(LPARAM)strAction.GetBuffer());
	//	strID.ReleaseBuffer();
	//	strAction.ReleaseBuffer();
	//	return 0;
	//}
	
	nPos = strData.Find(_T("<TreeNode"));
	if(nPos==-1)
		nPos = strData.Find(_T("<TREENODE"));
	if(nPos!=-1)
	{
		strData = strData.Mid(nPos);
		nPos = strData.Find(_T("</TreeNode>"));
		if(nPos==-1)
			nPos = strData.Find(_T("</TREENODE>"));
		strData = strData.Left(nPos+11);

		if(strID==_T("")||strID.Find(_T("TangramTreeRoot"))!=-1)
		{
			LoadXmlFromString(strData,CTangramHtmlTreeWnd::ConvertToUnicode);
		}
		else
		{
			map<CString,HTREEITEM>::iterator it = m_mapXobjDic.find(strID);
			if(it!=m_mapXobjDic.end())
			{
				CTangramXmlParse m_Parse;
				if(m_Parse.LoadXml(strData))
				{
					int nCount = 0;
					HTREEITEM hItem = it->second;
					if(hItem)
					{
						CTangramXHtmlTreeNode *pXTCD = GetItemDataStruct(hItem);
						BOOL bCheck = pXTCD->m_bChecked;
						LoadXml(&m_Parse,it->second,nCount);//	//DeleteItem(m_hItemMsg);
						DeleteItem(pXTCD->m_hWaitItemMsg);
						pXTCD->m_hWaitItemMsg = 0;
						SetCheck(hItem,bCheck);
					}

					m_mapXobjDic.erase(it);
				}
			}
		}
		return 0;
	}
	else
	{
		nPos = strID.Find(_T(",")); 
		while(nPos!=-1)
		{
			CString strState = strID.Left(nPos);
			strID = strID.Mid(nPos+1);
			nPos = strState.Find(_T("#"));
			CString strSip = strState.Left(nPos);
			strSip += _T("@");
			strSip += strData;
			strState = strState.Mid(nPos+1);
			nPos = strState.Find(_T("#"));
			HTREEITEM hItem = (HTREEITEM)::_wtoi64(strState.Left(nPos));
			int nState = ::_wtoi64(strState.Mid(nPos+1));
			int nImage = 0;
			switch(nState)
			{
            case 0://none
                {
					nImage = 2;
                }
                break;
            case 3500://free
                {
					nImage = 3;
                }
                break;
            case 5000://freeidle
                {
					nImage = 3;
                }
                break;
            case 6500://busy
                {
					nImage = 4;
                }
                break;
            case 7500://busyidle
                {
					nImage = 4;
                }
                break;
            case 9500://免打扰
                {
					nImage = 5;
                }
                break;
            case 12500://马上回来
                {
					nImage = 6;
                }
                break;
            case 15500://离开
                {
					nImage = 6;
                }
				break;
            case 18500://离线
                {
					nImage = 2;
                }
                break;
			}
			CTreeCtrl::SetItemImage(hItem,nImage,nImage);
			nPos = strID.Find(_T(",")); 
		}
	}
	return -1;
}
//=============================================================================
void CTangramHtmlTreeWnd::SetDragCursor()
//=============================================================================
{
	HCURSOR hCursor = GetDragCursor();

	if (hCursor)
		SetCursor(hCursor);
	else
		SetCursor(m_hPreviousCursor);
}

//=============================================================================
void CTangramHtmlTreeWnd::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
//=============================================================================
{
	ASSERT(!m_bDragging);

	NMTREEVIEW* pNMTreeView = (NMTREEVIEW*)pNMHDR;
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	ASSERT(hItem);

	if (!hItem)
		return;

	BOOL bCopyDrag = IsDragCopy();

#ifdef _DEBUG
	CString strText = GetItemText(hItem);
	TRACE(_T("in CTangramHtmlTreeWnd::OnBegindrag: %s  bCopyDrag=%d\n"), strText, bCopyDrag);
#endif

	// allow parent to decide whether to permit drag
	XHTMLTREEDRAGMSGDATA dragdata = { 0 };
	dragdata.m_hItem = hItem;
	dragdata.m_bCopyDrag = bCopyDrag;

	LRESULT lResult = SendRegisteredMessage(WM_XHTMLTREE_BEGIN_DRAG, hItem, 
		(LPARAM)&dragdata);

	if (lResult)
	{
		return;
	}

	m_hItemButtonDown = hItem;
	TRACE(_T("setting LBUTTONDOWN_TIMER >>>>>\n"));
	SetTimer(LBUTTONDOWN_TIMER, 100, NULL);

	m_bDragging = true;

	if (m_nNoDropCursor && (m_hNoDropCursor == NULL))
		m_hNoDropCursor = AfxGetApp()->LoadCursor(m_nNoDropCursor);
	if (m_nDropCopyCursor && (m_hDropCopyCursor == NULL))
		m_hDropCopyCursor = AfxGetApp()->LoadCursor(m_nDropCopyCursor);
	if (m_nDropMoveCursor && (m_hDropMoveCursor == NULL))
		m_hDropMoveCursor = AfxGetApp()->LoadCursor(m_nDropMoveCursor);

	SetDragCursor();

	m_dwDropHoverTime = GetTickCount();
	SetInsertMarkColor(m_crInsertMark);
	m_hPreviousDropItem = NULL;
	
	SetCapture();
	SetFocus();
	
	*pResult = 0;
}

//=============================================================================
// Determines if hItem is a child of hitemSuspectedParent
// Called in OnTimer to prevent the case where an item is attempted
// to be made a child of its own child.
//
BOOL CTangramHtmlTreeWnd::IsChildNodeOf(HTREEITEM hItem, HTREEITEM hitemSuspectedParent)
//=============================================================================
{
	do
	{
		if (hItem == hitemSuspectedParent)
			break;
	}
	while ((hItem = GetParentItem(hItem)) != NULL);

	return (hItem != NULL);
}

//=============================================================================
// CopyItem   - Copies an item to a new location
// Returns    - Handle of the new item
// hItem      - Item to be copied
// hNewParent - Handle of the parent for new item
// hAfter     - Item after which the new item should be created
HTREEITEM CTangramHtmlTreeWnd::MoveItem(HTREEITEM hItem, 
							   HTREEITEM hNewParent, 
							   HTREEITEM hAfter /*= TVI_LAST*/)
//=============================================================================
{
	HTREEITEM hNewItem = NULL;
	CTangramXHtmlTreeNode *pXTCD = NULL;

	if (hItem)
		pXTCD = GetItemDataStruct(hItem);

	if (pXTCD)
	{
		TVINSERTSTRUCT tvis;
		CString strText = _T("");
		
		// get information of the source item
		tvis.item.hItem = hItem;
		tvis.item.mask = TVIF_CHILDREN | TVIF_HANDLE | TVIF_PARAM |
			TVIF_IMAGE | TVIF_SELECTEDIMAGE;
		GetItem(&tvis.item);  
		strText = GetItemText(hItem);
		
		tvis.item.cchTextMax = strText.GetLength();
		tvis.item.pszText = strText.LockBuffer();
		
		// insert the item at proper location
		tvis.hParent = hNewParent;
		tvis.hInsertAfter = hAfter;
		tvis.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_PARAM;

		hNewItem = InsertItem(&tvis, pXTCD);

		strText.UnlockBuffer();

		if (pXTCD->m_bSeparator)			//+++1.6
		{
			SetItemState(hNewItem, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

			// increment separator count
			HTREEITEM hParent = hNewItem;
			while ((hParent = GetParentItem(hParent)) != NULL)
			{
				IncrementSeparators(hParent, 1);
			}
		}

#if 0  // -----------------------------------------------------------
		SetItemState(hNewItem, GetItemState(hItem, TVIS_STATEIMAGEMASK), 
			TVIS_STATEIMAGEMASK);
#endif // -----------------------------------------------------------
		
	}

	return hNewItem;
}

//=============================================================================
// MoveBranch - Moves all items in a branch to a new location
// Returns    - The new branch node
// hBranch    - The node that starts the branch
// hNewParent - Handle of the parent for new branch
// hAfter     - Item after which the new branch should be created
HTREEITEM CTangramHtmlTreeWnd::MoveBranch(HTREEITEM hBranch, 
								 HTREEITEM hNewParent, 
								 HTREEITEM hAfter /*= TVI_LAST*/)
//=============================================================================
{
	HTREEITEM hChild;
	
	HTREEITEM hNewItem = MoveItem(hBranch, hNewParent, hAfter);
	HTREEITEM hNext = GetChildItem(hBranch);
	hChild = hNext;
	while (hChild)
	{
		MoveBranch(hChild, hNewItem);
		hNext = GetNextSiblingItem(hChild);
		hChild = hNext;
	}
	return hNewItem;
}

//=============================================================================
BOOL CTangramHtmlTreeWnd::StartMoveBranch(HTREEITEM hItem, 
								 HTREEITEM hNewParent, 
								 HTREEITEM hAfter /*= TVI_LAST*/)
//=============================================================================
{
	BOOL bCopyDrag = IsDragCopy();

	TRACE(_T("in CTangramHtmlTreeWnd::StartMoveBranch: %s %X:  new parent=%X  after=%X\n"), 
		bCopyDrag ? _T("copying") : _T("moving"), hItem, hNewParent, hAfter);

	BOOL rc = false;

	ASSERT(hItem);

	if (hItem)
	{
		// allow parent to decide whether to permit drag
		XHTMLTREEDRAGMSGDATA dragdata = { 0 };
		dragdata.m_hItem      = hItem;
		dragdata.m_hNewParent = hNewParent;
		dragdata.m_hAfter     = hAfter;
		dragdata.m_bCopyDrag  = bCopyDrag;

		LRESULT lResult = SendRegisteredMessage(WM_XHTMLTREE_END_DRAG, hItem, 
			(LPARAM)&dragdata);

		rc = lResult == 0;				// allow drop if lResult is 0

		if (rc)
		{
			MoveBranch(hItem, hNewParent, hAfter);

			if (!bCopyDrag)
			{
				// moving, so delete original item
				m_nDeleted = 0;
				m_nDeletedChecked = 0;
				DeleteBranch(hItem);	// this was a move, not a copy
				TRACE(_T("m_nDeleted=%d  m_nDeletedChecked=%d\n"), m_nDeleted, m_nDeletedChecked);
			}
		}
	}

	return rc;
}

//=============================================================================
void CTangramHtmlTreeWnd::AutoScroll(HTREEITEM hItem)
//=============================================================================
{
	DWORD dwSpeedFlags = XHTMLTREE_DO_SCROLL_NORMAL | XHTMLTREE_DO_SCROLL_FAST;

#ifdef _DEBUG
	if ((m_dwDragOps & dwSpeedFlags) == dwSpeedFlags)
	{
		TRACE(_T("ERROR - only one speed flag should be set\n"));
		ASSERT(false);
	}
#endif // _DEBUG

	if ((m_dwDragOps & dwSpeedFlags) == 0)
	{
		// no speed flags, don't scroll
		return;
	}
		
	if (m_dwDragOps & XHTMLTREE_DO_SCROLL_NORMAL)
	{
		// scroll every other time, about 5 times a second
		if ((++m_nScrollTime & 1) == 0)
			return;
	}

	int n = 0;

	if (hItem)
	{
		int nScrollZone = GetItemHeight() + 5;

		CPoint point;
		GetCursorPos(&point);	// screen coords
		CRect rect;
		GetClientRect(&rect);
		ClientToScreen(&rect);	// screen coords

		int nDistance = 0;
		BOOL bUp = true;

		if (point.y < (rect.top + nScrollZone))
		{
			nDistance = point.y - rect.top;
			bUp = true;		// up
		}
		else if (point.y > (rect.bottom - nScrollZone))
		{
			nDistance = rect.bottom - point.y;
			bUp = false;	// down
		}

		if (nDistance > 0)
		{
			SetInsertMark(0, 0);	// remove previous insert mark

			if (nDistance > ((nScrollZone/3)*2))
			{
				// in region farthest from border, scroll slow
				SendMessage(WM_VSCROLL, bUp ? SB_LINEUP : SB_LINEDOWN);
				n = 1;
			}
			else if (nDistance > (nScrollZone/3))
			{
				// in middle region, scroll faster
				SendMessage(WM_VSCROLL, bUp ? SB_LINEUP : SB_LINEDOWN);
				SendMessage(WM_VSCROLL, bUp ? SB_LINEUP : SB_LINEDOWN);
				n = 2;
			}
			else
			{
				// in region closest to border, scroll very fast
				SendMessage(WM_VSCROLL, bUp ? SB_PAGEUP : SB_PAGEDOWN);
				n = 3;
			}

			ScreenToClient(&point);

			HTREEITEM hItem = IsOverItem(&point);

			if (hItem)
			{
				if ((m_dwDragOps & XHTMLTREE_DO_SHIFT_KEY) &&
					(GetAsyncKeyState(VK_SHIFT) < 0))
				{
					TRACE(_T("VK_SHIFT down\n"));
					if (IsSeparator(hItem))					//+++1.6
					{
						SelectDropTarget(NULL);
						SetInsertMark(hItem, true);
					}
					else
					{
						SelectDropTarget(hItem);
					}
				}
				else
				{
					SetInsertMark(hItem, true);
					SelectDropTarget(NULL);
				}
			}
		}
	}

#ifdef XHTMLTREE_DEMO
	CWnd *pWnd = GetParent();
	if (!pWnd)
		pWnd = GetOwner();
	if (pWnd && ::IsWindow(pWnd->m_hWnd))
		pWnd->SendMessage(WM_XHTMLTREE_SCROLL_SPEED, n, 0);
#endif // XHTMLTREE_DEMO
}
#endif // XHTMLDRAGDROP

//=============================================================================
void CTangramHtmlTreeWnd::EndDragScroll()
//=============================================================================
{
#ifdef XHTMLDRAGDROP

	TRACE(_T("in CTangramHtmlTreeWnd::EndDragScroll\n"));

	KillTimer(LBUTTONDOWN_TIMER);
	KillTimer(SHIFT_UP_TIMER);
	SetInsertMark(0, 0);
	m_nScrollTime = 0;
	if (m_bAutoScroll)
		AutoScroll(NULL);
	SelectDropTarget(NULL);
	ReleaseCapture();
	m_bDragging = false;
	SetCursor(m_hPreviousCursor);

#endif // XHTMLDRAGDROP
}
