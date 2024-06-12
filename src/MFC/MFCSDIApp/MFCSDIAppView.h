
// MFCSDIAppView.h : interface of the CMFCSDIAppView class
//

#pragma once


class CMFCSDIAppView : public CFormView
{
protected: // create from serialization only
	CMFCSDIAppView() noexcept;
	DECLARE_DYNCREATE(CMFCSDIAppView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCSDIAPP_FORM };
#endif

// Attributes
public:
	CMFCSDIAppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCSDIAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCSDIAppView.cpp
inline CMFCSDIAppDoc* CMFCSDIAppView::GetDocument() const
   { return reinterpret_cast<CMFCSDIAppDoc*>(m_pDocument); }
#endif

