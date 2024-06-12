
// MFCSDIExAppDoc.cpp : implementation of the CMFCSDIExAppDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSDIExApp.h"
#endif

#include "MFCSDIExAppDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCSDIExAppDoc

IMPLEMENT_DYNCREATE(CMFCSDIExAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCSDIExAppDoc, CDocument)
END_MESSAGE_MAP()


// CMFCSDIExAppDoc construction/destruction

CMFCSDIExAppDoc::CMFCSDIExAppDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCSDIExAppDoc::~CMFCSDIExAppDoc()
{
}

BOOL CMFCSDIExAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCSDIExAppDoc serialization

void CMFCSDIExAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << theApp.GetDocTemplateID(this);
		// TODO: add storing code here
	}
	else
	{
		ar >> theApp.m_strCreatingDOCID;
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCSDIExAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCSDIExAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCSDIExAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCSDIExAppDoc diagnostics

#ifdef _DEBUG
void CMFCSDIExAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCSDIExAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCSDIExAppDoc commands
