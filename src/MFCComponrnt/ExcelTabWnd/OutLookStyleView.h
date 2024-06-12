/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2020 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO 
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED 
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS 
* OUTLINED IN THE TANGRAM LICENSE AGREEMENT.TANGRAM TEAM 
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE 
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
********************************************************************************/
#pragma once

#define SOB_ERROR			0xffffffff // == -1
const int SOB_BAR_DEFAULT_FIRST_VIEW_ID	 = 0xDEAD;
const int SOB_BAR_DEFAULT_BTN_HEIGHT	 = 24;
const int SOB_BAR_DEFAULT_ANIMATION_SPEED =	10;
const int SOB_BAR_DEFAULT_ANIMATION_LIMIT =	200;
const DWORD SOB_VIEW_HORZ		=	0x00000001;
const DWORD SOB_VIEW_VERT		=	0x00000002;
const DWORD SOB_VIEW_ANIMATE	=	0x00000004;
const DWORD SOB_BTN_ANIMATE		=	0x00001000;
const DWORD SOB_BTN_FANCYFACE	=   0x00002000;

/////////////////////////////////////////////////////////////////////////////
// Constance used by COutLookStyleView & COutLookBar.  
/////////////////////////////////////////////////////////////////////////////
typedef enum tagButtonState
{ 
	SOB_BTN_UP   = 0x00000010,
	SOB_BTN_HIT  = 0x00000020, 
	SOB_BTN_OVER = 0x00000040 

} BUTTON_STATE, * LPBUTTON_STATE;

class COutLookBar 
{
	BOOL		m_bUseFancyFaceButton;
	BOOL		m_bUpdateBitmaps;
	int			m_iIconIndex;
	DWORD		m_dwButtonStyle;
	CString		m_strButtonTitle;
	CRect		m_rectButton;
	CBitmap		m_bmpNormalFace;
	CBitmap		m_bmpPressedFace;
	CWnd*		m_pWndParent;
	CImageList*	m_pImageList;

public:
	COutLookBar();
	~COutLookBar(); 

	void SetParentWnd( CWnd* pWnd );
	DWORD GetButtonStyle( void ) const;
	void  ModifyButtonStyle( const DWORD dwRemove, const DWORD dwAdd );
	void   SetButtonTitle( CString szcTitle );
	CString GetButtonTitle( void ) const;
	CWnd* GetParentWnd( void );

protected:
	friend class COutLookStyleView;

	void Draw( CDC* pDC, const CRect& rectScreen, const DWORD dwFlags = SS_CENTER );
	void Size( const CRect& rectNewSize, const DWORD dwStyle );
	void UpdateBitmaps( CDC* pDC, DWORD dwFlags );
	void OnSysColorChange( void );
};

typedef CArray< COutLookBar*, COutLookBar* > CSliderButtonArray; 

class COutLookStyleView : 
	public CWnd,
	public IContainer
{
// Construction
public:
	COutLookStyleView();
	virtual ~COutLookStyleView();

// Attributes
public:
	int				m_nButtonHeight;
	CImageList		m_hButtonImageList;
	DWORD			m_dwViewStyle;
	IXobj*			m_pWndNode;

protected:
	BOOL			m_bLButtonDown;
	BOOL			m_bTrackLeave;
	int				m_nViewCount;
	int				m_nActiveView;
	int				m_nMouseOnButton;
	HCURSOR			m_hHandCursor;
	CSliderButtonArray  m_buttonArray;

private:
	int				m_nPriviousButton;
	BOOL			m_bTrackingMouse;

// Operations
public:
	int CreateView( CString szcViewTitle, CRuntimeClass* pViewClass, CCreateContext* pContext, int iIconIndex = -1, const DWORD dwStyle = WS_CHILD|WS_VISIBLE );
	int	  GetViewID( const int nID ) const;
	int	  GetViewCount() const;
	int	  ButtonHitTest( const CPoint& point );
	int	  GetActiveView( void ) const;
	int   SetActiveView( const int nNewView, const BOOL bRedraw = true );
	BOOL  RemoveView( const int nView );
	DWORD GetBarStyle( void ) const;
	CWnd* GetView( const int nView ) const;
	COutLookBar* GetButton( const int nButton ) const;
	CRect GetButtonRect( const int nButton, const CRect& rectClient ) const;
	CRect GetButtonRect( const int nButton ) const;
	CRect GetInsideRect( const int nButton ) const;
	void  ModifyViewStyle( const DWORD dwRemove, const DWORD dwAdd, const BOOL bRedraw );
	void RecalcLayout( const BOOL bRepaint = true );
	void  InvalidateButton( const int nButton );

	void Save()
	{
		CString str;
		str.Format(_T("%d"), m_nActiveView);
		m_pWndNode->put_Attribute(L"activepage", CComBSTR(str));
	}

protected:
	void ViewAnimation( const int nNewView, const int nPreviousView );
	void OnPrintClient( HDC hDC, UINT uFlags );
	void PostNcDestroy();
	void OnDraw(CDC* pDC);      // overridden to draw this view
	LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	BOOL PreCreateWindow(CREATESTRUCT& cs);

	// Generated message map functions
protected:
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSysColorChange();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg LRESULT OnCreatePage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnActivePage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnModifyPage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTgmSetCaption(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
