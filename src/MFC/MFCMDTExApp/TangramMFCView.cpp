
// TangramMFCView.cpp : implementation of the CTangramMFCView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TangramMFC.h"
#endif

#include "TangramMFCDoc.h"
#include "TangramMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTangramMFCView

IMPLEMENT_DYNCREATE(CTangramMFCView, CFormView)

BEGIN_MESSAGE_MAP(CTangramMFCView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTangramMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTangramMFCView construction/destruction

CTangramMFCView::CTangramMFCView() noexcept
	: CFormView(IDD_TANGRAMMFC_FORM)
{
	// TODO: add construction code here

}

CTangramMFCView::~CTangramMFCView()
{
}

void CTangramMFCView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CTangramMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTangramMFCView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
}


// CTangramMFCView printing


void CTangramMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTangramMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTangramMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTangramMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTangramMFCView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

void CTangramMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTangramMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTangramMFCView diagnostics

#ifdef _DEBUG
void CTangramMFCView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTangramMFCView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTangramMFCDoc* CTangramMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTangramMFCDoc)));
	return (CTangramMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CTangramMFCView message handlers
