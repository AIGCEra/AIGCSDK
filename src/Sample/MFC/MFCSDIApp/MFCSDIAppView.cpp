
// MFCSDIAppView.cpp : implementation of the CMFCSDIAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSDIApp.h"
#endif

#include "MFCSDIAppDoc.h"
#include "MFCSDIAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSDIAppView

IMPLEMENT_DYNCREATE(CMFCSDIAppView, CFormView)

BEGIN_MESSAGE_MAP(CMFCSDIAppView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCSDIAppView construction/destruction

CMFCSDIAppView::CMFCSDIAppView() noexcept
	: CFormView(IDD_MFCSDIAPP_FORM)
{
	// TODO: add construction code here

}

CMFCSDIAppView::~CMFCSDIAppView()
{
}

void CMFCSDIAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCSDIAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMFCSDIAppView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMFCSDIAppView printing

BOOL CMFCSDIAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSDIAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSDIAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCSDIAppView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMFCSDIAppView diagnostics

#ifdef _DEBUG
void CMFCSDIAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCSDIAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCSDIAppDoc* CMFCSDIAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSDIAppDoc)));
	return (CMFCSDIAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSDIAppView message handlers
