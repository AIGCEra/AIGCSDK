#pragma once


// CWebView view

class CWebView : public CView
{
	DECLARE_DYNCREATE(CWebView)

protected:
	CWebView();           // protected constructor used by dynamic creation
	virtual ~CWebView();
	HWND			m_hWebBrowser;
	IBrowser*		m_pChromeWebBrowser = nullptr;
	vector<HWND>	m_vHtmlWnd;
public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg LRESULT OnTangramMsg(WPARAM wParam, LPARAM lParam);
};


