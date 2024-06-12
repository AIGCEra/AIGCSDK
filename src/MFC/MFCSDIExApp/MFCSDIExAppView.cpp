
// MFCSDIExAppView.cpp : implementation of the CMFCSDIExAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSDIExApp.h"
#endif

#include "MFCSDIExAppDoc.h"
#include "MFCSDIExAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSDIExAppView

IMPLEMENT_DYNCREATE(CMFCSDIExAppView, CFormView)

BEGIN_MESSAGE_MAP(CMFCSDIExAppView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCSDIExAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCSDIExAppView construction/destruction

CMFCSDIExAppView::CMFCSDIExAppView() noexcept
	: CFormView(IDD_MFCSDIEXAPP_FORM)
{
	// TODO: add construction code here

}

CMFCSDIExAppView::~CMFCSDIExAppView()
{
}

void CMFCSDIExAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCSDIExAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMFCSDIExAppView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	//ResizeParentToFit();

}


// CMFCSDIExAppView printing


void CMFCSDIExAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCSDIExAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSDIExAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSDIExAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCSDIExAppView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

void CMFCSDIExAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCSDIExAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCSDIExAppView diagnostics

#ifdef _DEBUG
void CMFCSDIExAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCSDIExAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCSDIExAppDoc* CMFCSDIExAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSDIExAppDoc)));
	return (CMFCSDIExAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSDIExAppView message handlers
