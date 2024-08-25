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

class CXobjWnd : public CWnd
{
	DECLARE_DYNCREATE(CXobjWnd)
public:
	BOOL					m_bNoMove;
	BOOL					m_bBKWnd;
	BOOL					m_bEraseBkgnd;
	BOOL					m_bCreateExternal;
	HWND					m_hFormWnd;

	CString					m_strKey;
	CString					m_strXml;

	CXobj*					m_pXobj;
	CXobj*					m_pParentXobj;
	CTangramHtmlTreeWnd*	m_pXHtmlTree;

	IOleInPlaceActiveObject* m_pOleInPlaceActiveObject;

	BOOL PreTranslateMessage(MSG* pMsg);
	BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CXobjWnd();           // protected constructor used by dynamic creation
	virtual ~CXobjWnd();
	void PostNcDestroy();
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg LRESULT OnActiveTangramObj(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnWebRTMsg(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnTabChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetWebRTObj(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT OnAfterDPIChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnAfterDPIChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSplitterReposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	DECLARE_MESSAGE_MAP()
};

class CBKWnd : public CWindowImpl<CBKWnd, CWindow>
{
public:
	CBKWnd(void);
	HWND			m_hChild;
	CString			m_strURL;
	CXobj*			m_pXobj;
	CNucleus*		m_pNucleus;
	BEGIN_MSG_MAP(CBKWnd)
		MESSAGE_HANDLER(WM_MDICLIENTCREATED, OnMdiClientCreated)
		MESSAGE_HANDLER(WM_MOUSEACTIVATE, OnMouseActivate)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGED, OnWindowPosChanged)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWindowPosChanged)
	END_MSG_MAP()

private:
	LRESULT OnMouseActivate(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnMdiClientCreated(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT OnWindowPosChanged(UINT, WPARAM, LPARAM, BOOL&);
	void OnFinalMessage(HWND hWnd);
};
