
#pragma once

typedef struct _tagPAGEINFO
{
	CWnd* pWnd;
	CString sTitle;
	BOOL bHasScrollHorz;
	BOOL bHasScrollVert;
	SCROLLINFO scrlInfoHorz;
	SCROLLINFO scrlInfoVert;

	// constructor
	_tagPAGEINFO()
	{
		pWnd=NULL;
		sTitle=_T("");
		bHasScrollHorz=false;
		bHasScrollVert=false;
	}

	// copy constructor
	_tagPAGEINFO(const _tagPAGEINFO& pi)
	{
		ASSERT(pi.pWnd!=NULL);
		pWnd=pi.pWnd;
		sTitle=pi.sTitle;
		bHasScrollHorz=pi.bHasScrollHorz;
		bHasScrollVert=pi.bHasScrollVert;
		scrlInfoHorz=pi.scrlInfoHorz;
		scrlInfoVert=pi.scrlInfoVert;
	}

	// assignment operator
	_tagPAGEINFO& operator=(const _tagPAGEINFO& pi)
	{
		if(this==&pi)
		{
			return *this;
		}

		ASSERT(pi.pWnd!=NULL);
		pWnd=pi.pWnd;
		sTitle=pi.sTitle;
		bHasScrollHorz=pi.bHasScrollHorz;
		bHasScrollVert=pi.bHasScrollVert;
		scrlInfoHorz=pi.scrlInfoHorz;
		scrlInfoVert=pi.scrlInfoVert;
		return *this;
	}

	void GetScrollInfo(CWnd* pWnd, BOOL bHorzScrlBar)
	{
		ASSERT_VALID(pWnd);

		if(bHorzScrlBar)
		{
			scrlInfoHorz.cbSize=sizeof(SCROLLINFO);
			pWnd->GetScrollInfo(SB_HORZ,&scrlInfoHorz);
			if(bHasScrollVert)
			{
				scrlInfoHorz.nMax-=::GetSystemMetrics(SM_CXVSCROLL);
				//				scrlInfoHorz.nPage-=::GetSystemMetrics(SM_CXVSCROLL);
				if(scrlInfoHorz.nPos+(int)scrlInfoHorz.nPage>scrlInfoHorz.nMax)
				{
					scrlInfoHorz.nPos=scrlInfoHorz.nMax-scrlInfoHorz.nPage;
				}
				if(scrlInfoHorz.nTrackPos+(int)scrlInfoHorz.nPage>scrlInfoHorz.nMax)
				{
					scrlInfoHorz.nTrackPos=scrlInfoHorz.nMax-scrlInfoHorz.nPage;
				}
			}
			if(scrlInfoHorz.nMax==0 || scrlInfoHorz.nPage==0)
			{
				bHasScrollHorz=false;
			}
		}
		else
		{
			scrlInfoVert.cbSize=sizeof(SCROLLINFO);
			pWnd->GetScrollInfo(SB_VERT,&scrlInfoVert);
			if(bHasScrollHorz)
			{
				scrlInfoVert.nMax-=1;
				//				scrlInfoVert.nPage-=1;
				if(scrlInfoVert.nPos+(int)scrlInfoVert.nPage>scrlInfoVert.nMax)
				{
					scrlInfoVert.nPos=scrlInfoVert.nMax-scrlInfoVert.nPage;
				}
				if(scrlInfoVert.nTrackPos+(int)scrlInfoVert.nPage>scrlInfoVert.nMax)
				{
					scrlInfoVert.nTrackPos=scrlInfoVert.nMax-scrlInfoVert.nPage;
				}
			}
			if(scrlInfoVert.nMax==0 || scrlInfoVert.nPage==0)
			{
				bHasScrollVert=false;
			}
		}
	}

} PAGEINFO;

#define ID_TABVIEWCONTAINER_SIGN	0x3a7b4567
#define ID_SPLITTERWIDTH			6
#define ID_TABBTNOVERLAPSIZE		5
#define ID_TABBTNGAPSIZE			3
#define ID_MINSCROLLBARWIDTH		60
#define ID_INITABBTNAREAWIDTH		200
#define ID_SCROLLTABBTNAREASTEP		15
#define IDT_SCROLLPAGE_TIMER		122
#define ID_SCROLLPAGE_DELAY			200
#define IDT_CHECKSCROLLINFO_TIMER	123
#define ID_CHECKSCROLLINFO_PERIOD	1000

// CExcelTabView window
class CExcelTabView : 
	public CWnd, 
	public IContainer
{
	// Construction
public:
	CExcelTabView();

	// Attributes
public:
	typedef enum _tagHITTEST
	{
		SCROLLBARHORZ=-1,
		SCROLLBARVERT=-2,
		SCRLSTARTBTN=-3,
		SCRLBACKWARDBTN=-4,
		SCRLFORWARDBTN=-5,
		SCRLENDBTN=-6,
		SPLITTER=-7,
		PAGE=-8,
		TABBTNAREA=-9,
		SIZEBAR=-10,
		NONE=-11
	} HITTEST;

	IXobj*	m_pWndNode;

protected:
	// scroll buttons rectangles
	CRect m_rectScrollToStartBtn;
	CRect m_rectScrollBackwardBtn;
	CRect m_rectScrollForwardBtn;
	CRect m_rectScrollToEndBtn;

	int m_nTabBtnAreaOrigin;
	CRect m_rectTabBtnArea;
	CArray<CRect,CRect&> m_arrTabBtnRects;
	int m_nLastTabBtnAreaWidth;

	CRect m_rectScrollBarHorz;
	CRect m_rectScrollBarVert;

	CRect m_rectSplitter;
	CRect m_rectSizeBar;
	CRect m_rectPage;

	// array of pages
	CArray<PAGEINFO,PAGEINFO> m_arrPages;
	// index of currently active page
	int m_nActivePageIndex;
	/////////////////////////////////////////

	// scroll style of the container (internal)
	DWORD m_dwScrollStyle;

	// internal array of unique IDs
	CArray<DWORD,DWORD> m_arrUniqueIDs;

	// scroll bars controls
	CScrollBar m_scrlBarHorz;
	CScrollBar m_scrlBarVert;

	// the ID of last scroll button that was pressed
	HITTEST m_nPressedScrlBtn;
	// flag that specifies if last pressed scroll button is still pressed 
	BOOL m_bIsScrlBtnPressed;
	// timer for tab buttons scrolling operations
	int m_nScrollPageTimer;

	// flag that specifies that splitter has been pressed
	BOOL m_bIsSplitterPressed;

	// fonts to draw text in tab buttons
	CFont m_fontTabBtnText;
	CFont m_fontActiveTabBtnText;

	// Operations
public:
	BOOL SetTabWnd (int iTab,CWnd* m_pNewWnd);
	BOOL RemoveTab (int iTab);
	void SetActiveTab (int iTab);
	void AddTab(CWnd* pTabWnd, LPCTSTR lpszTabLabel, UINT uiImageId);
	void RecalcLayout ();
	// Tab activation:
	int GetActiveTab () 
	{
		return m_nActivePageIndex;
	}

	int GetTabsNum () 
	{
		return GetPageCount();
	}

	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, 
		DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext=NULL);

	virtual BOOL Create(CWnd* pParentWnd, CRect rect=CRect(0,0,0,0), 
		DWORD dwStyle=WS_CHILD|WS_VISIBLE, UINT nID=AFX_IDW_PANE_FIRST+1);


	inline BOOL AddPage(CRuntimeClass* pClass, CCreateContext* pContext, LPCTSTR lpszTitle=NULL) 
	{
		return InsertPage(GetPageCount(),pClass,pContext,lpszTitle);
	}

	inline BOOL AddPage(CWnd* pWnd, LPCTSTR lpszTitle=NULL) 
	{ 
		return InsertPage(GetPageCount(),pWnd,lpszTitle); 
	}

	virtual BOOL InsertPage(int nIndex, CRuntimeClass* pClass, CCreateContext* pContext, LPCTSTR lpszTitle=NULL);

	virtual BOOL InsertPage(int nIndex, CWnd* pWnd, LPCTSTR lpszTitle=NULL);

	BOOL DeletePage(CWnd* pWnd, BOOL bDestroy=true);

	virtual BOOL DeletePage(int nIndex, BOOL bDestroy=true);

	inline CWnd* GetPage(int nIndex) const 
	{
		ASSERT(nIndex>=0 && nIndex<GetPageCount());
		if(nIndex>=0 && nIndex<GetPageCount())
			return m_arrPages[nIndex].pWnd;
		return NULL;
	}

	inline CString GetPageTitle(CWnd* pWnd) const 
	{
		ASSERT(pWnd!=NULL);
		if(pWnd==NULL)
		{
			return _T("");
		}
		int nIndex=-1;
		if(!FindPage(pWnd,nIndex) || nIndex==-1)
		{
			return _T("");
		}
		return GetPageTitle(nIndex);
	}

	inline CString GetPageTitle(int nIndex) const 
	{
		ASSERT(nIndex>=0 && nIndex<GetPageCount());
		if(nIndex>=0 && nIndex<GetPageCount())
		{
			return m_arrPages[nIndex].sTitle;
		}
		return _T("");
	}

	inline BOOL SetPageTitle(CWnd* pWnd, LPCTSTR lpszTitle) 
	{
		ASSERT(pWnd!=NULL);
		if(pWnd==NULL)
		{
			return false;
		}
		int nIndex=-1;
		if(!FindPage(pWnd,nIndex) || nIndex==-1)
		{
			return false;
		}
		return SetPageTitle(nIndex,lpszTitle);
	}

	BOOL SetPageTitle(int nIndex, LPCTSTR lpszTitle);

	inline int GetPageCount() const { return (int)m_arrPages.GetSize(); }

	inline BOOL FindPage(CWnd* pTestWnd, int& nIndex) const 
	{
		ASSERT(pTestWnd!=NULL);
		if(pTestWnd!=NULL)
		{
			return FindPage(pTestWnd->m_hWnd,nIndex);
		}
		return false;
	}

	inline BOOL FindPage(HWND hTestWnd, int& nIndex) const 
	{
		BOOL bResult=false;
		for(nIndex=0; nIndex<GetPageCount(); nIndex++)
		{
			if(m_arrPages[nIndex].pWnd->m_hWnd==hTestWnd)
			{
				bResult=true;
				break;
			}
		}
		return bResult;
	}

	inline BOOL IsPage(HWND hTestWnd) const 
	{
		int nIndex=-1;
		return FindPage(hTestWnd,nIndex);
	}

	inline BOOL IsPage(CWnd* pTestWnd) const 
	{
		int nIndex=-1;
		return FindPage(pTestWnd,nIndex);
	}

	inline BOOL IsActivePage(HWND hTestWnd) const 
	{
		int nIndex=-1;
		if(FindPage(hTestWnd,nIndex) && GetActivePageIndex()==nIndex)
		{
			return true;
		}
		return false;
	}

	inline BOOL IsActivePage(CWnd* pTestWnd) const 
	{
		int nIndex=-1;
		if(FindPage(pTestWnd,nIndex) && GetActivePageIndex()==nIndex)
		{
			return true;
		}
		return false;
	}

	inline int GetActivePageIndex() const { return m_nActivePageIndex; }

	inline CWnd* GetActivePage() const 
	{ 
		if(m_nActivePageIndex>=0 && m_nActivePageIndex<GetPageCount())
		{
			return m_arrPages[m_nActivePageIndex].pWnd;
		}
		return NULL;
	}

	inline BOOL SetActivePage(CWnd* pWnd) 
	{
		ASSERT(pWnd!=NULL);
		if(pWnd!=NULL)
		{
			int nIndex=-1;
			if(FindPage(pWnd,nIndex))
			{
				return SetActivePageIndex(nIndex);
			}
		}
		return false;
	}

	virtual BOOL SetActivePageIndex(int nIndex);

	inline CScrollBar* GetHorzScrollBar() 
	{ 
		if(::IsWindow(m_scrlBarHorz.GetSafeHwnd()))
		{
			return &m_scrlBarHorz; 
		}
		else
		{
			return NULL; 
		}
	}

	inline CScrollBar* GetVertScrollBar() 
	{ 
		if(::IsWindow(m_scrlBarVert.GetSafeHwnd()))
		{
			return &m_scrlBarVert; 
		}
		else
		{
			return NULL; 
		}
	}

protected:
	virtual void SetScrollStyle(DWORD dwScrollStyle, BOOL bForceToRebuild=false);
	inline DWORD GetScrollStyle() const { return m_dwScrollStyle; }

	virtual void CalcLayout();
	virtual void CalcTabBtnRects();
	virtual DWORD GetUniqueId();

	void EmptyRects();

	void Save()
	{
		//CString str;
		//str.Format(_T("%d"), m_nActiveView);
		//m_pWndNode->put_Attribute(L"activepage", CComBSTR(str));
	}

	// redraw the specified scroll button.
	void RedrawScrollButton(HITTEST hitTest);
	// redraw tab buttons area
	inline void RedrawTabBtnArea() 
	{ 
		ASSERT(::IsWindow(GetSafeHwnd()));
		RedrawWindow(m_rectTabBtnArea); 
	}
	// redraw splitter
	inline void RedrawSplitter() 
	{ 
		ASSERT(::IsWindow(GetSafeHwnd()));
		RedrawWindow(m_rectSplitter); 
	}
	// redraw all Tab View container elements 
	inline void RedrawContainer() 
	{
		CRect rect=m_rectScrollToStartBtn;
		rect.right=m_rectSplitter.right;
		RedrawWindow(rect);
		RedrawWindow(m_rectSizeBar);
	}

	// the following virtual routines are responsible for drawing
	// corresponding Tab View container elements 
	virtual void DrawScrollButtons(CDC* pDC);
	virtual void DrawTabBtnArea(CDC* pDC);
	virtual void DrawSplitter(CDC* pDC);
	virtual void DrawSizeBar(CDC* pDC);
	/////////////////////////////////////////////////////////////

	// draws specified scroll button
	virtual void DrawButton(CDC* pDC, CRect rect, HITTEST nButtonType) const;
	// draws tab button for the page with specified index
	virtual void DrawTabButton(CDC* pDC, int nIndex) const;

	// starts handling "move splitter" or "scroll tab buttons" operation
	void StartTracking(const CPoint& point);
	// stops "move splitter" or "scroll tab buttons" operation
	void StopTracking(const CPoint& point);

	inline BOOL CanScrollToStart() const 
	{ 
		ASSERT(m_nTabBtnAreaOrigin<=0);
		return (m_nTabBtnAreaOrigin<0 && 
			m_rectTabBtnArea.right>m_rectTabBtnArea.left); 
	}
	inline BOOL CanScrollBackward() const { return CanScrollToStart(); }
	inline BOOL CanScrollForward() const { return CanScrollToEnd(); }
	inline BOOL CanScrollToEnd() const 
	{
		ASSERT(m_nTabBtnAreaOrigin<=0);
		if(GetPageCount()>0 && 
			m_rectTabBtnArea.right>m_rectTabBtnArea.left)
		{
			ASSERT(GetPageCount()==m_arrTabBtnRects.GetSize());
			CRect rect=m_arrTabBtnRects[GetPageCount()-1];
			rect+=m_rectTabBtnArea.TopLeft();
			return (rect.right+m_nTabBtnAreaOrigin>m_rectTabBtnArea.right);
		}
		return false;
	}


	void EnsureTabBtnVisible(int nIndex, BOOL bPartialOk=false);

	/////////////////////////////////////////////////////////////////////

	// Implementation
public:
	virtual ~CExcelTabView();

	int HitTest(const CPoint& point) const;
	void ScrollPage(HITTEST nScrlBtn);

	// Generated message map functions
protected:
	afx_msg LRESULT OnCreatePage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnActivePage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnModifyPage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTgmSetCaption(WPARAM wParam, LPARAM lParam);

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCancelMode();
	afx_msg void OnDestroy();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);

	DECLARE_MESSAGE_MAP()
	// special command routing to frame
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	void PostNcDestroy();
	BOOL PreCreateWindow(CREATESTRUCT& cs);
};

CExcelTabView* PASCAL GetParentTabViewContainer(CWnd* pWnd, BOOL bOnlyActive=true);
