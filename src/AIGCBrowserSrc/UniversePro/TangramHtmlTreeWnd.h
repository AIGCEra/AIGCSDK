/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202108220001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser;
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

#ifndef XHTMLTREE_H
#define XHTMLTREE_H

#include <afxtempl.h>
#include "XHtmlDraw.h"

extern UINT WM_XHTMLTREE_CHECKBOX_CLICKED;
extern UINT WM_XHTMLTREE_ITEM_EXPANDED;
extern UINT WM_XHTMLTREE_DISPLAY_TOOLTIP;
extern UINT WM_XHTMLTREE_INIT_TOOLTIP;
#ifdef XHTMLDRAGDROP
extern UINT WM_XHTMLTREE_BEGIN_DRAG;
extern UINT WM_XHTMLTREE_END_DRAG;
extern UINT WM_XHTMLTREE_DROP_HOVER;
#endif // XHTMLDRAGDROP
#ifdef XHTMLTREE_DEMO
extern UINT WM_XHTMLTREE_SCROLL_SPEED;
#endif // XHTMLTREE_DEMO

const int TV_NOIMAGE = 0xFFFE;
typedef map<CString,HTREEITEM> NodeDictionary;
typedef map<CString,CString> NodeDataDictionary;

struct CTangramXHtmlTreeNode;
typedef map<CString,CTangramXHtmlTreeNode*> NodeMap;

class CTangramXmlParse;
class CXobjWnd;
class CTangramHelper;
//=============================================================================
// Uncomment the following line if you want to use HTML in tree
//=============================================================================
//#define XHTMLHTML

#ifdef XHTMLHTML
#include "XHtmlDrawLink.h"
#endif // XHTMLHTML

//=============================================================================
// Uncomment the following line if you want HTML tooltips, displayed
// using CPPToolTip:  http://www.codeproject.com/miscctrl/pptooltip.asp
//=============================================================================
//#define XHTMLTOOLTIPS

#ifdef XHTMLTOOLTIPS
#include "PPTooltip.h"
#endif // XHTMLTOOLTIPS

//=============================================================================
// Uncomment the following line if you want to include XML functions.
//=============================================================================
//#define XHTMLXML

#ifdef XHTMLXML
#endif // XHTMLXML

//=============================================================================
// Uncomment the following line if you want to enable drag & drop.
//=============================================================================
//#define XHTMLDRAGDROP

//=============================================================================
// CTangramHtmlTreeWnd data
//=============================================================================
struct DesignerData
{
	CString m_strXml;
};

struct CTangramXHtmlTreeNode
{
	// ctor
	CTangramXHtmlTreeNode()
	{
		m_pXmlParse = NULL;
		m_bChecked         = FALSE;
		m_bEnabled         = TRUE;
		m_bSeparator       = FALSE;
		m_nNodeType		   = BlankView;
		m_strName = _T("");
		m_strTangramXML	   = _T("");
		m_strTangramXML2	= _T("");
		m_strTangramMenuXML  = _T("");
		m_strTangramHeader = _T("");
		m_strTangramDataURL  = _T("");
		m_strTangramDataXML  = _T("");
		m_strTangramItemID  = _T("");
		m_strRelationNodes  = _T("");
		m_strRelationWnds  = _T("");

		// below are reserved for CTangramHtmlTreeWnd use only
		m_hTreeCtrl        = 0;
		m_bExpanded        = FALSE;
		m_bHasBeenExpanded = FALSE;
		m_bModified        = FALSE;
		m_bWaitingFor      = FALSE;
		m_bNeedData        = FALSE;
		m_nType		       = 0;
		m_nChildren        = 0;
		m_nChecked         = 0;
		m_nSeparators      = 0;
		m_pszNote          = 0;
		m_nTipWidth        = 0;
		m_hWaitItemMsg	   = 0;
		m_pWebRTTreeNode = NULL;
		m_hItem = NULL;
		m_nCount++;
	}

	// dtor
	virtual ~CTangramXHtmlTreeNode()
	{
		if (m_pszNote)
			delete [] m_pszNote;
		m_pszNote = 0;
		m_nCount--;
		if(m_pWebRTTreeNode)
		{
			DWORD dwRef = m_pWebRTTreeNode->Release();
			while(dwRef)
			{
				dwRef = m_pWebRTTreeNode->Release();
			}
		}
	}
	virtual BOOL ModifyNode(int nRow, int nCol, CString strName, CString strXml) { return FALSE; }

	BOOL	m_bWaitingFor;			
	BOOL	m_bChecked;				// TRUE = item checkbox is checked
	BOOL	m_bEnabled;				// TRUE = enabled, FALSE = disabled 
									// (gray text)
	BOOL	m_bSeparator;				// TRUE = item is separator; cannot have children

	// below are reserved for CTangramHtmlTreeWnd use only

	HWND	m_hTreeCtrl;				// HWND of tree control
	BOOL	m_bExpanded;				// TRUE = item is expanded to show its children
	BOOL	m_bHasBeenExpanded;		// TRUE = item has been expanded (at least once)
	BOOL	m_bModified;				// TRUE = item has been modified
	BOOL	m_bNeedData;
	int		m_nChildren;				// total count of children of this 
									// item
	int		m_nChecked;				// count of children that are 
									// checked - an item in a "mixed" 
									// state is counted as being 
									// unchecked
	int		m_nSeparators;			// count of children that are separators
	int		m_nType;
	XobjType	m_nNodeType;
	TCHAR * m_pszNote;				// note for tooltip
	int		m_nTipWidth;				// width of tooltip for note
	CXHtmlDraw::XHTMLDRAWSTRUCT ds;	// HTML draw info
	static int m_nCount;				// incremented in ctor, decremented in dtor
	
	CTangramXmlParse*	m_pXmlParse;
	IWebRTTreeNode*	m_pWebRTTreeNode;

	map<CString, CXobj*> m_mapBindNode;
	HTREEITEM m_hItem;
	HTREEITEM m_hWaitItemMsg;
	CString	m_strName;
	CString	m_strTangramXML;
	CString	m_strTangramXML2;
	CString	m_strTangramMenuXML;
	CString	m_strTangramDataURL;
	CString	m_strTangramHeader;
	CString	m_strTangramDataXML;
	CString	m_strTangramItemID;
	CString	m_strRelationNodes;
	CString	m_strRelationWnds;
};

//=============================================================================
// data returned in notification messages
//=============================================================================
struct XHTMLTREEMSGDATA
{
	HWND		m_hCtrl;				// hwnd of XHtmlTree
	UINT		m_nCtrlId;			// id of XHtmlTree
	HTREEITEM	m_hItem;				// current item
};

//=============================================================================
// data returned in drag notification messages - not all data will be
// returned for every message
//=============================================================================
struct XHTMLTREEDRAGMSGDATA
{
	HTREEITEM	m_hItem;				// item being dragged
	HTREEITEM	m_hNewParent;			// proposed new parent
	HTREEITEM	m_hAfter;				// drop target - item being dragged will
									// either sequentially follow this item,
									// or hAfter specifies the relationship
									// (TVI_FIRST, TVI_LAST, etc.) the
									// dragged item will have with hNewParent.
									// Note that TVI_xxxx constants are all
									// defined as 0xFFFFnnnn, with the 16
									// high-order bits set.
	BOOL		m_bCopyDrag;			// TRUE = dropped item will be copied;
									// FALSE = dropped item will be moved
};

//=============================================================================
// drag operations flags for m_dwDragOps
//=============================================================================
#define XHTMLTREE_DO_CTRL_KEY		0x0001	// TRUE = Ctrl key toggles move/copy;
											// FALSE = Ctrl key is ignored
#define XHTMLTREE_DO_SHIFT_KEY		0x0002	// TRUE = Shift key toggles "move
											// under" mode; FALSE = Shift key is 
											// ignored
#define XHTMLTREE_DO_SCROLL_NORMAL	0x0004	// TRUE = normal drag scroll
#define XHTMLTREE_DO_SCROLL_FAST	0x0008	// TRUE = fast drag scroll
#define XHTMLTREE_DO_COPY_DRAG		0x0010	// TRUE = change default drag from
											// move to copy
#define XHTMLTREE_DO_AUTO_EXPAND	0x0020	// TRUE = auto-expand node when 
											// cursor hovers

#define XHTMLTREE_DO_DEFAULT		(XHTMLTREE_DO_CTRL_KEY | \
									 XHTMLTREE_DO_SHIFT_KEY | \
									 XHTMLTREE_DO_SCROLL_NORMAL | \
									 XHTMLTREE_DO_AUTO_EXPAND)

class CTangramTreeView;
//=============================================================================
class CTangramHtmlTreeWnd : public CTreeCtrl
//=============================================================================
{
//=============================================================================
// Construction
//=============================================================================
public:
	CTangramHtmlTreeWnd();
	virtual ~CTangramHtmlTreeWnd();

//=============================================================================
// Attributes
//=============================================================================
public:
	CTangramXmlParse* m_pHostXmlParse;
	HTREEITEM		m_LasthItem;
	HTREEITEM		m_hFirstRoot;
	long			m_nHeight;
	BOOL			m_bNoHandle;
	HWND			m_hAsynHostWnd;
	HWND			m_hDualWnd;
	CString			m_strURL;
	CString			m_strImageURL;
	CString			m_strImageTarget;
	CString			m_strDefaultXTML;

	CString			m_strMainKey;
	CString			m_strLeafKey;
	CString			m_strNodeKey;
	//CString			m_strNode2Key;
	CString			m_strBases;
	CString			m_strMenuScript;
	CString			m_strMenu;
	CString			m_strMultSelectedMenu;
	CString			m_strMultSelectedMenu2;
	CString			m_strSelectNodeInfo;
	CString			m_strOutRelationWnds;
	CString			m_strInnerRelationNodes;

	map<HWND,CString> m_mapOutRelationWnd;	

	CImageList		m_Images;
	NodeDictionary	m_mapXobjDic;
	NodeMap			m_mapSelectedNodeDic;
	CComObject<CTangramTreeView>* m_pObj;
	CXobjWnd*	m_pHostWnd;
	CTangramHelper*	m_pWebRTHelper;
	enum CheckedState { UNUSED1 = 0, 
						UNCHECKED, CHECKED, TRISTATE, 
						UNUSED2,
						UNCHECKED_DISABLED, CHECKED_DISABLED, TRISTATE_DISABLED };

#ifdef XHTMLHTML
	CXHtmlDrawLink	m_Links;
#endif // XHTMLHTML

	COLORREF	GetBkColor() { return m_crCustomWindow; }
	BOOL		GetBit(DWORD bits, DWORD bitmask) { return bits & bitmask; }
	BOOL		GetCheck(HTREEITEM hItem);
	int			GetCheckedCount();
	int			GetChildrenCheckedCount(HTREEITEM hItem);
	int			GetChildrenCount(HTREEITEM hItem);
	int			GetChildrenDisabledCount(HTREEITEM hItem);
	int			GetDefaultTipWidth();
	COLORREF	GetDisabledColor(COLORREF color);
	BOOL		GetDisplayToolTips() { return m_bToolTip; }
	DWORD		GetDragOps() { return m_dwDragOps; }
	HTREEITEM	GetFirstCheckedItem();
	BOOL		GetHasBeenExpanded(HTREEITEM hItem);
	BOOL		GetHasCheckBoxes() { return m_bCheckBoxes; }
	BOOL		GetHtml() { return m_bHtml; }
	BOOL		GetImages() { return m_bImages; }
	int			GetIndentLevel(HTREEITEM hItem);
	COLORREF	GetInsertMarkColor() { return m_crInsertMark; }
	BOOL		GetItemBold(HTREEITEM hItem);
	CString		GetItemNote(HTREEITEM hItem, BOOL bStripHtml = FALSE);
	int			GetItemNoteWidth(HTREEITEM hItem);
	BOOL		GetItemPath(HTREEITEM hItem, CStringArray& sa, CPtrArray& items);
	BOOL		GetItemRect(HTREEITEM hItem, LPRECT lpRect, BOOL bTextOnly);
	COLORREF	GetItemTextBkColor(HTREEITEM hItem);
	COLORREF	GetItemTextColor(HTREEITEM hItem);
	CTangramXHtmlTreeNode * GetItemDataStruct(HTREEITEM hItem);
	CString		GetItemText(HTREEITEM hItem, BOOL bStripHtml = FALSE) const;
	HTREEITEM	GetLastItem(HTREEITEM hItem);
	LOGFONT *	GetLogfont() { return &m_lf; }
	HTREEITEM	GetNextCheckedItem(HTREEITEM hItem);
	HTREEITEM	GetNextItem(HTREEITEM hItem);
				// do not hide CTreeCtrl version
	HTREEITEM	GetNextItem(HTREEITEM hItem, UINT nCode)	
				{ return CTreeCtrl::GetNextItem(hItem, nCode); }
	HTREEITEM	GetPrevCheckedItem(HTREEITEM hItem);
	HTREEITEM	GetPrevItem(HTREEITEM hItem);
	BOOL		GetReadOnly() { return m_bReadOnly; }
	BOOL		GetSelectFollowsCheck() { return m_bSelectFollowsCheck; }
	COLORREF	GetSeparatorColor() { return m_crSeparator; }		//+++1.6
	int			GetSeparatorCount(HTREEITEM hItem);
	BOOL		GetSmartCheckBox() { return m_bSmartCheck; }
	int			GetStateImage(HTREEITEM hItem);
	BOOL		GetStripHtml() { return m_bStripHtml; }
	COLORREF	GetTextColor() { return m_crCustomWindowText; }
#ifdef XHTMLTOOLTIPS
	CPPToolTip * GetToolTips() { return m_pToolTip; }
#else
	CToolTipCtrl * GetToolTips() { return m_pToolTip; }
#endif // XHTMLTOOLTIPS
	BOOL		GetUseLogfont() { return m_bLogFont; }
	int			GetXmlCount() { return m_nXmlCount; }

	BOOL		IsChecked(HTREEITEM hItem) { return GetCheck(hItem); }
	BOOL		IsChildNodeOf(HTREEITEM hitem, HTREEITEM hitemSuspectedParent);
	BOOL		IsEnabled(HTREEITEM hItem);
	BOOL		IsExpanded(HTREEITEM hItem);
	HTREEITEM	IsOverItem(LPPOINT lpPoint = NULL);
	BOOL		IsSelected(HTREEITEM hItem);
	BOOL		IsSeparator(HTREEITEM hItem);

	COLORREF	SetBkColor(COLORREF rgb);
	void		SetBit(DWORD& bits, DWORD bitmask, BOOL value)
				{
					if (value)
						bits |= bitmask;
					else
						bits &= ~bitmask;
				}
	CTangramHtmlTreeWnd&	SetCheck(HTREEITEM hItem, BOOL fCheck = TRUE);
	CTangramHtmlTreeWnd&	SetCheckChildren(HTREEITEM hItem, BOOL fCheck);
	CTangramHtmlTreeWnd&	SetDefaultTipWidth(int nDefaultTipWidth)
				{ m_nDefaultTipWidth = nDefaultTipWidth; return *this; }
	CTangramHtmlTreeWnd&	SetDisplayToolTips(BOOL bFlag) 
				{ m_bToolTip = bFlag; return *this; }
	CTangramHtmlTreeWnd&	SetDragOps(DWORD dwOps)
				{ m_dwDragOps = dwOps; return *this; }
	CTangramHtmlTreeWnd&	SetDropCursors(UINT nNoDropCursor, UINT nDropCopyCursor, UINT nDropMoveCursor) 
				{ 
					m_nNoDropCursor = nNoDropCursor; 
					m_nDropCopyCursor = nDropCopyCursor; 
					m_nDropMoveCursor = nDropMoveCursor; 
					return *this; 
				}
	CTangramHtmlTreeWnd&	SetHasCheckBoxes(BOOL bHasCheckBoxes) 
				{ m_bCheckBoxes = bHasCheckBoxes; return *this; }
	CTangramHtmlTreeWnd&	SetHtml(BOOL bFlag) 
				{ m_bHtml = bFlag; return *this; }
	CTangramHtmlTreeWnd&	SetImages(BOOL bFlag) 
				{ m_bImages = bFlag; return *this; }
	COLORREF	SetInsertMarkColor(COLORREF rgb);
	BOOL		SetItemBold(HTREEITEM hItem, BOOL bBold);
	CTangramHtmlTreeWnd&	SetItemNote(HTREEITEM hItem, LPCTSTR lpszNote, int m_nTipWidth = 0);
	BOOL		SetItemText(HTREEITEM hItem, LPCTSTR lpszItem);
	COLORREF	SetItemTextBkColor(HTREEITEM hItem, COLORREF rgb);
	COLORREF	SetItemTextColor(HTREEITEM hItem, COLORREF rgb);
	CTangramHtmlTreeWnd&	SetItemStateChildren(HTREEITEM hItem, BOOL fCheck);
	CTangramHtmlTreeWnd&	SetLogfont(LOGFONT * pLogFont);
	CTangramHtmlTreeWnd&	SetReadOnly(BOOL bReadOnly)
				{ m_bReadOnly = bReadOnly; return *this; }
	CTangramHtmlTreeWnd&	SetSelectFollowsCheck(BOOL bFlag) 
				{ m_bSelectFollowsCheck = bFlag; return *this; }
	CTangramHtmlTreeWnd&	SetSeparatorColor(COLORREF rgb);		//+++1.6
	CTangramHtmlTreeWnd&	SetSmartCheckBox(BOOL bFlag) 
				{ m_bSmartCheck = bFlag; return *this; }
	CTangramHtmlTreeWnd&	SetStripHtml(BOOL bFlag) 
				{ m_bStripHtml = bFlag; return *this; }
	COLORREF	SetTextColor(COLORREF rgb);
#ifdef XHTMLTOOLTIPS
	CPPToolTip * SetToolTips(CPPToolTip * pWndTip) 
				{ CPPToolTip * old = m_pToolTip; m_pToolTip = pWndTip; return old; }
#else
	CToolTipCtrl * SetToolTips(CToolTipCtrl * pWndTip) 
				{ CToolTipCtrl * old = m_pToolTip; m_pToolTip = pWndTip; return old; }
#endif // XHTMLTOOLTIPS
	CTangramHtmlTreeWnd&	SetUseLogfont(BOOL bFlag) 
				{ m_bLogFont = bFlag; return *this; }

//=============================================================================
// Operations
//=============================================================================
public:
	void		Init(CXobj* pXobj);
	void		WriteData(CString strData);
	CString		TangramGetData(CTangramXmlParse*, CTangramHelper*);
	CString		GetSelectedNodeInfo(CString strPropertys);
	void		CheckAll(BOOL bCheck);
	void		CollapseBranch(HTREEITEM hItem);
	BOOL		CreateCheckboxImages();
	void		CreateToolTipsForTree();
	BOOL		DeleteItem(HTREEITEM hItem);
	BOOL		EnableBranch(HTREEITEM hItem, BOOL m_bEnabled);
	BOOL		EnableItem(HTREEITEM hItem, BOOL m_bEnabled);
	BOOL		EnableWindow(BOOL bEnable = TRUE);
	BOOL		Expand(HTREEITEM hItem, UINT nCode);
	void		ExpandBranch(HTREEITEM hItem);
	void		ExpandAll();
	void		CollapseAll();
	BOOL		DeleteAllItems();
	virtual HTREEITEM FindItem(CString &sSearch, 
							   BOOL bCaseSensitive = FALSE, 
							   BOOL bDownDir = TRUE,
							   BOOL bWholeWord = FALSE, 
							   BOOL bWrap = TRUE,
							   HTREEITEM hItem = NULL);
	int			IncrementChildren(HTREEITEM hItem, int n = 1);
	int			IncrementSeparators(HTREEITEM hItem, int n = 1);
	CTangramHtmlTreeWnd&	Initialize(BOOL bCheckBoxes = FALSE, BOOL bToolTip = FALSE);
	HTREEITEM	InsertItem(LPTVINSERTSTRUCT lpInsertStruct, CTangramXHtmlTreeNode * pData = NULL);
	HTREEITEM	InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage, 
					int nSelectedImage, UINT nState, UINT nStateMask, 
					LPARAM lParam, HTREEITEM hParent, HTREEITEM hInsertAfter);
	HTREEITEM	InsertItem(LPCTSTR lpszItem, HTREEITEM hParent = TVI_ROOT, 
					HTREEITEM hInsertAfter = TVI_LAST );
	HTREEITEM	InsertItem(LPCTSTR lpszItem, int nImage, int nSelectedImage, 
					HTREEITEM hParent = TVI_ROOT, 
					HTREEITEM hInsertAfter = TVI_LAST);
	HTREEITEM	InsertSeparator(HTREEITEM hItem);
	void		RedrawItem(HTREEITEM hItem);
	BOOL		SelectItem(HTREEITEM hItem);
	HCURSOR		SetCursor(HCURSOR hCursor);
	void		UpdateData(CString strData);

//=============================================================================
// XML functions
//=============================================================================
#ifdef XHTMLXML

public:
	enum ConvertAction
	{
		NoConvertAction = 0, ConvertToUnicode, ConvertToAnsi
	};

	BOOL		ConvertBuffer(const BYTE * inbuf, 
							  DWORD inlen,				// in bytes
							  BYTE ** outbuf,
							  DWORD& outlen,			// in bytes
							  ConvertAction eConvertAction = NoConvertAction);
	CString		GetXmlText(HTREEITEM hItem, LPCTSTR lpszElem);
	BOOL		LoadXmlFromFile(LPCTSTR lpszFile, ConvertAction eConvertAction);
	HTREEITEM	LoadXmlFromXmlParse(CTangramXmlParse* pParse);
	HTREEITEM	LoadXmlFromString(LPCTSTR lpszFile, ConvertAction eConvertAction);
	HTREEITEM	InsertXmlItem(CTangramXmlParse *pElement, HTREEITEM hParent);
	BOOL		LoadXml(CTangramXmlParse *pElement, 
							 HTREEITEM hParent,
							 int& nCount);

protected:

#endif // XHTMLXML

//=============================================================================
// Overrides
//=============================================================================
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTangramHtmlTreeWnd)
public:
	virtual void PostNcDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	virtual void PreSubclassWindow();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//BOOL SetBKImage(LPCTSTR LpszResource);
	//}}AFX_VIRTUAL

//=============================================================================
// Implementation
//=============================================================================
protected:
	CMap< HTREEITEM, HTREEITEM, CTangramXHtmlTreeNode *, CTangramXHtmlTreeNode *& > m_DataMap;
											// maps HTREEITEM ==> CTangramXHtmlTreeNode
	BOOL			m_bReadOnly;			// TRUE = tree is read-only 
											// (checkboxes disabled)
	BOOL			m_bSmartCheck;			// TRUE = Smart Checkboxes enabled
	BOOL			m_bCheckBoxes;			// TRUE = checkboxes enabled
	BOOL			m_bSelectFollowsCheck;	// TRUE = item will be selected, 
											// after user clicks on checkbox
	BOOL			m_bHtml;
	BOOL			m_bStripHtml;
	BOOL			m_bLogFont;
	BOOL			m_bToolTip;
	BOOL			m_bImages;				// TRUE = allow images
	BOOL			m_bDestroyingTree;
	BOOL			m_bFirstTime;
	BOOL			m_bDragging;
	BOOL			m_bAutoScroll;			// TRUE = tree will automatically 
											// scroll when dragging
	INucleus* m_pNucleus;
	INucleus*	m_pDualTangramFrame;
	BOOL			m_bAttached;

	HTREEITEM		m_hCurSelectedItem;
	HTREEITEM		m_hAnchorItem;
	HTREEITEM		m_hHotItem;
	HTREEITEM		m_hPreviousItem;
	HTREEITEM		m_hItemButtonDown;
	HTREEITEM		m_hPreviousDropItem;
	DWORD			m_dwDropHoverTime;		// number of ticks over a drop item
	int				m_nPadding;				// horizontal padding in pixels
	int				m_nImageHeight;
	int				m_nToolCount;			// no. of items added to tooltip 
											// control
	int				m_nDefaultTipWidth;
	int				m_nXmlCount;			// count of items loaded from XML 
											// file
	int				m_nDeleted;
	int				m_nDeletedChecked;
	CImageList		m_StateImage;
	LOGFONT			m_lf;
	int				m_nHorzPos;				// initial horz scroll position - saved
											// before in-place edit begins
	UINT			m_nScrollTime;			// used for scrolling while dragging
	DWORD			m_dwDragOps;			// drag features
	UINT			m_nNoDropCursor;		// resource ID for no-drop cursor
	UINT			m_nDropCopyCursor;		// resource ID for drop (copy) cursor
	UINT			m_nDropMoveCursor;		// resource ID for drop (move) cursor
	HCURSOR			m_hNoDropCursor;		// no-drop cursor handle
	HCURSOR			m_hDropCopyCursor;		// drop (copy) cursor handle
	HCURSOR			m_hDropMoveCursor;		// drop (move) cursor handle
	HCURSOR			m_hPreviousCursor;
	HCURSOR			m_hCurrentCursor;

#ifdef XHTMLTOOLTIPS
	CPPToolTip *	m_pToolTip;
#else
	CToolTipCtrl *	m_pToolTip;
#endif // XHTMLTOOLTIPS

	COLORREF		m_crCustomWindow;
	COLORREF		m_crCustomWindowText;
	COLORREF		m_crWindow;
	COLORREF		m_crWindowText;
	COLORREF		m_crAnchorText;
	COLORREF		m_crGrayText;
	COLORREF		m_crHighlight;
	COLORREF		m_crHighlightText;
	COLORREF		m_crInsertMark;
	COLORREF		m_crSeparator;

	void		AdjustEditRect();
	void		AutoScroll(HTREEITEM hItem);
	void		DeleteBranch(HTREEITEM hItem);

	void		DeleteMap();
	int			DrawItemText(CDC *pDC, HTREEITEM hItem, LPCTSTR lpszText, 
					COLORREF crText, COLORREF crTextBackground, 
					COLORREF crBackground, CRect& rect);
#ifdef XHTMLHTML
	int			DrawItemTextHtml(CDC *pDC, HTREEITEM hItem, LPCTSTR lpszText, 
					COLORREF crText, COLORREF crTextBackground, 
					COLORREF crBackground, COLORREF crAnchorText,
					CRect& rect);
#endif // XHTMLHTML
	int			DrawSeparator(CDC *pDC, HTREEITEM hItem,
					COLORREF crText, COLORREF crBackground, CRect& rect);
	void		EndDragScroll();
	int			GetNormalImageWidth(HTREEITEM hItem);
	BOOL		IsBadRect(CRect& r)
				{ 
					return (r.IsRectEmpty() || (r.Height() <= 0) || (r.Width() <= 0)); 
	}
	virtual BOOL IsFindValid(HTREEITEM);
	BOOL		IsLeftButtonUp();
	BOOL		IsOverAnchor(HTREEITEM hItem, CPoint point, CRect *pRect = NULL);
	BOOL		PreDisplayToolTip(BOOL bAlwaysRemoveHtml, CString& strToolTip);
	LRESULT		SendRegisteredMessage(UINT nMessage, HTREEITEM hItem, LPARAM lParam = 0);
	int			SetCheckParent(HTREEITEM hItem, int nCount);
	void		SetColors();
	void		SetHotItem(HTREEITEM hItem, UINT nFlags);

#ifdef XHTMLDRAGDROP
	HCURSOR		GetDragCursor();
	BOOL		IsCtrlDown();
	BOOL		IsDragCopy();
	HTREEITEM	MoveBranch(HTREEITEM hBranch, 
						   HTREEITEM hNewParent, 
						   HTREEITEM hAfter = TVI_LAST);
	HTREEITEM	MoveItem(HTREEITEM hItem, 
						 HTREEITEM hNewParent, 
						 HTREEITEM hAfter = TVI_LAST);
	void		SetDragCursor();
	BOOL		StartMoveBranch(HTREEITEM hItem, 
								HTREEITEM hNewParent, 
								HTREEITEM hAfter = TVI_LAST);
#endif // XHTMLDRAGDROP


//=============================================================================
// Generated message map functions
//=============================================================================
public:
	//{{AFX_MSG(CTangramHtmlTreeWnd)
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnRClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSysColorChange();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg LRESULT OnDesignNode(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetWebRTXmlParse(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdateXMLNode(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnInsertXMLNode(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnInsertData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetSelectedNodeInfo(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG

#ifdef XHTMLDRAGDROP
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
#endif // XHTMLDRAGDROP

#ifdef XHTMLTOOLTIPS
	afx_msg void OnDisplayTooltip(NMHDR * pNMHDR, LRESULT * result);
#else
	virtual afx_msg BOOL OnToolTipText(UINT id, NMHDR * pNMHDR, LRESULT * pResult);
#endif // XHTMLTOOLTIPS

	afx_msg BOOL OnSelchanged(NMHDR * pNMHDR, LRESULT * pResult);
	afx_msg BOOL OnSelchanging(NMHDR * pNMHDR, LRESULT * pResult);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif //XHTMLTREE_H
