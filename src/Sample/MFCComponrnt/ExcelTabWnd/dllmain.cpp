// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "dllmain.h"
#include "TangramExcelTabCtrl.h"
#include "OutLookStyleView.h"


namespace CommonUniverse
{
	CWebRTImpl* g_pWebRTImpl = nullptr;
}

CTangramApp theApp;

CTangramApp::CTangramApp()
{
}

CTangramApp::~CTangramApp()
{
	OutputDebugString(_T("------------------Release CTangramExcelTabWndApp------------------------\n"));
}

BOOL CTangramApp::InitInstance()
{
	m_strContainer = _T(",exceltab,outlooktabwndh,outlooktabwndv,");
	WebRTInit(_T("tangramexceltabwnd.tab"));
	return __super::InitInstance();
}

HWND CTangramApp::Create(HWND hParentWnd, IXobj* pNode)
{
	CString strNames = _T("exceltab,outlooktabwndh,outlooktabwndv,");
	BSTR bstrTag = L"";
	pNode->get_Attribute(L"xobjtype", &bstrTag);
	USES_CONVERSION;
	CString m_strTag = OLE2T(bstrTag);
	::SysFreeString(bstrTag);
	m_strTag.Trim().MakeLower();
	if (m_strTag.CompareNoCase(_T("")) == 0)
		m_strTag = _T("exceltab");
	m_strTag += _T(",");
	int nIndex = strNames.Find(m_strTag);
	if (nIndex != -1)
	{
		CString s = strNames.Left(nIndex);
		nIndex = s.Replace(_T(","),_T(""));
	}

	if (::IsWindow(hParentWnd))
	{
		CRect rt;
		::GetClientRect(hParentWnd, &rt);
		switch (nIndex)
		{
		case 0:
			{
				CExcelTabView* pTangramExcelTabCtrl = new CExcelTabView();
				pTangramExcelTabCtrl->m_pWndNode = pNode;
				pTangramExcelTabCtrl->Create(CWnd::FromHandle(hParentWnd), rt, WS_CHILD | WS_VISIBLE, 0);
				return pTangramExcelTabCtrl->m_hWnd;
			}
			break;
		case 1:
		case 2:
			{
				COutLookStyleView* pOutLookBar = new COutLookStyleView();
				if (nIndex==1)
					pOutLookBar->m_dwViewStyle = SOB_VIEW_VERT | SOB_VIEW_ANIMATE;
				else
					pOutLookBar->m_dwViewStyle = SOB_VIEW_HORZ | SOB_VIEW_ANIMATE;
				pOutLookBar->m_pWndNode = pNode;

				pOutLookBar->Create(NULL, _T(""), WS_CHILD | WS_VISIBLE, rt, CWnd::FromHandle(hParentWnd), 0);
				::SetWindowLongPtr(pOutLookBar->m_hWnd, GWLP_USERDATA, 1992);
				pNode->get_Attribute(L"activepage", &bstrTag);
				CString m_strTag = OLE2T(bstrTag);
				::SysFreeString(bstrTag);
				int nActivePage = _wtoi(m_strTag);
				::PostMessage(pOutLookBar->m_hWnd, WM_TABCHANGE, nActivePage, 0);
				return pOutLookBar->m_hWnd;
			}
			break;
		}
	}
	return NULL;
}

CString CTangramApp::GetNames()
{
	return _T("ExcelTab,OutLookTabWndH,OutLookTabWndV,");
}

CString CTangramApp::GetTags(CString bstrName)
{
	return _T("");
}
