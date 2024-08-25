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

#pragma once

// CGridWnd

class CGridWnd : public CSplitterWnd
{
	DECLARE_DYNCREATE(CGridWnd)
public:
	void Save();
	void RecalcLayout();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CXobj* m_pHostXobj;
	bool bInited;
	int m_nHostWidth, m_nHostHeight;
	int m_Vmin,m_Vmax,m_Hmin,m_Hmax;
	int m_nMasterRow;
	int m_nMasterCol;
	int m_nLastWidth = 0;
	int m_nLastHeight = 0;
	COLORREF		rgbLeftTop;
	COLORREF		rgbMiddle;
	COLORREF		rgbRightBottom;
protected:
	CGridWnd();           // protected constructor used by dynamic creation
	virtual ~CGridWnd();

	BOOL			m_bCreated;
	CXobj*			m_pXobj;

	BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	void StartTracking(int ht);
	void StopTracking(BOOL bAccept);
	void TrackRowSize(int y, int row);
	void TrackColumnSize(int x, int col);
	void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
	void PostNcDestroy();
	void DrawAllSplitBars(CDC* pDC, int cxInside, int cyInside);
	CWnd* GetActivePane(int* pRow = NULL, int* pCol = NULL);
	//void OnInvertTracker(const CRect& rect);
	//void RefreshNode(IXobj*);

	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg LRESULT OnWebRTMsg(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnActiveTangramObj(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnGetWebRTObj(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnSplitterCreated(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	void _RecalcLayout();
	void _LayoutRowCol(CSplitterWnd::CRowColInfo* pInfoArray, int nMax, int nSize, int nSizeSplitter, CXobj* pHostNode, bool bCol);
	void _DeferClientPos(AFX_SIZEPARENTPARAMS* lpLayout, CWnd* pWnd, int x, int y, int cx, int cy, BOOL bScrollBar);
public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
