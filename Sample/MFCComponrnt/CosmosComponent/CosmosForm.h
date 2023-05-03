/********************************************************************************
*					Tangram Wizard - version 1.0.0							*
*********************************************************************************
* Copyright (C) 2002-2020 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS
* OUTLINED IN THE GPL LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.webruntime.com
*
*
********************************************************************************/

#pragma once


// CCosmosFormView view

class CCosmosFormView : public CFormView
{
	DECLARE_DYNCREATE(CCosmosFormView)

protected:
	CCosmosFormView();           // protected constructor used by dynamic creation
	virtual ~CCosmosFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITANGRAMVSCOMPONENTFORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnBnClickedBtnHowto();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


