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

// CTangramListCtrl

class CTangramListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CTangramListCtrl)

public:
	CTangramListCtrl();
	virtual ~CTangramListCtrl();
	int					m_nListViewIndex;
	int					m_nListViewSelectedIndex;
	CString				m_strDir;
	CString				m_strSubDir;
	CTangramTabCtrl*	m_pWebRTTabCtrl;
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
};

// CTangramTabCtrl

class CTangramTabCtrl : public CTabCtrl
{
	DECLARE_DYNCREATE(CTangramTabCtrl)

public:
	CTangramTabCtrl();
	virtual ~CTangramTabCtrl();
	int					m_nImageIndex;
	CString				m_strFilter;
	CXobj*			m_pXobj;
	CNucleus*		m_pNucleus;
	CTangramListView*	m_pWebRTListView;
	CTangramListCtrl	m_ListCtrl;
	void RePosition();
	void FillListCtrl();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
protected:
	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg LRESULT OnInitialUpdate(WPARAM wParam, LPARAM lParam);
};


