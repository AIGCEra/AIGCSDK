/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001           *
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
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

#pragma once

// CTangramListView view
class CTangramTabCtrl;
class CTangramListView : public CListView
{
	DECLARE_DYNCREATE(CTangramListView)

protected:
	CTangramListView();           // protected constructor used by dynamic creation
	virtual ~CTangramListView();

public:
	INucleus* m_pNucleus;
	CTangramTabCtrl* m_pWebRTTabCtrl;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL			m_bCreated;
	BOOL			m_bFilling;
	int				m_nStyle;
	int				m_nActiveIndex;
	CXobj*		m_pXobj;
	CImageList		m_ImageList;

	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);

	DECLARE_MESSAGE_MAP()
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg LRESULT OnActiveTangramPage(WPARAM wParam, LPARAM lParam);
public:
	void InitTabCtrl(CTangramTabCtrl* pTabCtrl);
	void ChangeTemplate(int nItem);
};


