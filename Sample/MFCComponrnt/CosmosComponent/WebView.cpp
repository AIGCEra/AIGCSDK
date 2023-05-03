// WebView.cpp : implementation file
//

#include "pch.h"
#include "WebView.h"
#include "dllmain.h"

IMPLEMENT_DYNCREATE(CWebView, CView)

CWebView::CWebView()
{
	m_hWebBrowser = NULL;
	//m_pChromForVSAppObj = nullptr;
}

CWebView::~CWebView()
{
}

BEGIN_MESSAGE_MAP(CWebView, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_WINDOWPOSCHANGED()
	ON_MESSAGE(WM_COSMOSMSG, OnTangramMsg)
END_MESSAGE_MAP()

// CWebView drawing

void CWebView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CWebView diagnostics

#ifdef _DEBUG
void CWebView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CWebView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CWebView message handlers

int CWebView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CComBSTR bstrUrl;
	if (g_pWebRT)
	{
		IXobj* pNode = nullptr;
		g_pWebRT->get_CreatingXobj(&pNode);
		pNode->get_Attribute(CComBSTR("url"), &bstrUrl);
		//if (theApp.m_pTangramFromWebRuntime && bstrUrl.Length())
		//{
		//	CComPtr<IBrowser> pWebBrowser;
		//	theApp.m_pTangramFromWebRuntime->CreateBrowser((__int64)m_hWnd, bstrUrl, &pWebBrowser);
		//	if (pWebBrowser)
		//	{
		//		m_pChromeWebBrowser = pWebBrowser.Detach();
		//		m_pChromeWebBrowser->AddRef();
		//		m_hWebBrowser = ::GetWindow(m_hWnd, GW_CHILD);
		//	}
		//}
	}
	return 0;
}


LRESULT CWebView::OnTangramMsg(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case 20200601:
		if (::IsWindow(m_hWebBrowser))
		{
			RECT rc;
			::GetClientRect(m_hWnd, &rc);
			::SetWindowPos(m_hWebBrowser, NULL, 0, 0, rc.right, rc.bottom, SWP_FRAMECHANGED|SWP_NOACTIVATE | SWP_NOREDRAW);
		}
		break;
	case 20200609:
		if (::IsWindow(m_hWebBrowser))
		{
			HWND hHtmlWnd = (HWND)wParam;
			m_vHtmlWnd.push_back(hHtmlWnd);
		}
		break;
	}
	return CView::DefWindowProc(WM_COSMOSMSG, wParam, lParam);
}

void CWebView::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	if (::IsWindow(m_hWebBrowser))
	{
		::SetWindowPos(m_hWebBrowser, NULL, 0, 0, lpwndpos->cx, lpwndpos->cy, SWP_NOACTIVATE | SWP_NOREDRAW);
	}
	CView::OnWindowPosChanged(lpwndpos);
}

void CWebView::OnDestroy()
{
	if(m_pChromeWebBrowser)
		m_pChromeWebBrowser->Release();
	//::DestroyWindow(m_hWebBrowser);
	CView::OnDestroy();
}
