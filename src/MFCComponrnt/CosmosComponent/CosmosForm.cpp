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

// CCosmosFormView.cpp : implementation file
//

#include "pch.h"
#include "resource.h"
#include "dllmain.h"
#include "CosmosForm.h"

using namespace CommonUniverse;

// CCosmosFormView

IMPLEMENT_DYNCREATE(CCosmosFormView, CFormView)

CCosmosFormView::CCosmosFormView()
	: CFormView(IDD_ITANGRAMVSCOMPONENTFORMVIEW)
{

}

CCosmosFormView::~CCosmosFormView()
{
}

void CCosmosFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCosmosFormView, CFormView)
	ON_BN_CLICKED(IDC_BTN_HOWTO, &CCosmosFormView::OnBnClickedBtnHowto)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CCosmosFormView diagnostics

#ifdef _DEBUG
void CCosmosFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CCosmosFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

BOOL CCosmosFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

// CCosmosFormView message handlers
void CCosmosFormView::OnBnClickedBtnHowto()
{
	g_pSpaceTelescopeImpl->InsertMsgData(m_hWnd, _T("xx"), _T("yy"));
}

int CCosmosFormView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (g_pWebRT)
	{
		IXobj* pNode = nullptr;
		g_pWebRT->get_CreatingXobj(&pNode);
	}

	return 0;
}
