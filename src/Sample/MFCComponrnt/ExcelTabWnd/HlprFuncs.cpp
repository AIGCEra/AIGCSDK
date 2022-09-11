/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2020 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO 
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED 
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS 
* OUTLINED IN THE TANGRAM LICENSE AGREEMENT.TANGRAM TEAM 
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE 
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
********************************************************************************/

#include "StdAfx.h"
#include "HlprFuncs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BOOL DrawVerticalText
( 
	CDC* pDC, 
	const CRect& rectWindow, 
	CString szcText, 
	const DWORD dwStyle 
)
{
	int nSavedDC = pDC->SaveDC();

	//
    // Start by getting this control's font, and then tweak it a bit.
	//

	LOGFONT lf;
	CFont *pTmpFont = pDC->GetCurrentFont();

	if( NULL == pTmpFont )
	{
		ASSERT( pTmpFont );  // Font not selected in DC!
		return false;
	}

	pTmpFont->GetObject( sizeof(LOGFONT), &lf );
	
	//
    // Text will be rotated counter-clockwise 90 degrees.
	//
	lf.lfOrientation = lf.lfEscapement = 900;

	//
    // We need a TrueType font to get rotated text.  MS Sans Serif
    // won't cut it!  Opps!  A hard coded string!  
	//
    lstrcpy( lf.lfFaceName, _T("Tahoma") );

	//
	// Create a font with the tweaked attributes.
	//
    CFont font;
    if( false == font.CreateFontIndirect( &lf ) )
	{
		TRACE2("Error creating font! Line: %d, File: %s\n", __LINE__, __FILE__ );
		return false;
	}

	CFont *pfontOld = pDC->SelectObject( &font );


	CRect rectText( rectWindow );

	//
	// Compute size of horizontal oriented string
	//
	pDC->DrawText ( CString(szcText), 
		            rectText,
                    DT_LEFT 
				   |DT_TOP 
				   |DT_CALCRECT 
				   |DT_SINGLELINE );

	//
    // Dependence on format flags, compute offset of text rectangle
	// Horizontal offset is constant for all formats
	// Vertical offset depend on format
	//
	CSize szOffset(0,0);
    if ( dwStyle & SS_CENTER )
	{
	    szOffset = CSize( (rectWindow.Width()-rectText.Height())/2, 
			              -(rectWindow.Height()-rectText.Width())/2+rectText.Height() );
	}
    else if ( dwStyle & SS_RIGHT )
	{
	    szOffset = CSize( (rectWindow.Width()-rectText.Height())/2, 
			              -rectWindow.Height()+rectText.Width()+rectText.Height() );
	}
    else
	{
	    szOffset = CSize( (rectWindow.Width()-rectText.Height())/2, 
			              rectText.Height() );
	}
	
	//
	// Convert dimensions of horizontal oriented rectangle 
	// to dimensions of vertical oriented rectangle 
	// (swap horizontal and vertical sizes)
	// rectText.SetRect( rectWindow.left, 0, rectWindow.left + rectText.Height(), rectWindow.Height());
	// rectText.SetRect( rectWindow.left, rectWindow.top, rectText.right, rectWindow.Height());
	//

	rectText.top    = rectWindow.top;
	rectText.bottom = rectWindow.bottom;
	
	//
    // Offset text rectangle
	//
	rectText.OffsetRect(szOffset);
	rectText.top = 0;

	if( rectWindow.Height() < rectText.Width() )
		rectText.right -= ((rectText.Width() - rectWindow.Height())/2);

	pDC->SetBkMode( TRANSPARENT );
	pDC->DrawText( szcText, 
		           rectText,
                   DT_LEFT 
				  |DT_BOTTOM 
				  |DT_SINGLELINE 
				  |DT_END_ELLIPSIS );
    pDC->SelectObject ( pfontOld );
	pDC->RestoreDC( nSavedDC );
    
	return true;
}

void GradientFill
( 
	CDC* pDC, 
	const CRect& rectWindow,
	const COLORREF crFace,
	const COLORREF crShadow,
	const BOOL bHorizontal
)
{
	int nShadeHeight = bHorizontal ? rectWindow.Height() : rectWindow.Width();

	const float deltaR = (float)(abs( GetRValue(crFace) - GetRValue(crShadow)) ) / (float)nShadeHeight;
	const float deltaG = (float)(abs( GetGValue(crFace) - GetGValue(crShadow)) ) / (float)nShadeHeight;
	const float deltaB = (float)(abs( GetBValue(crFace) - GetBValue(crShadow)) ) / (float)nShadeHeight;
	
	for( int y = 1; y <= (int)nShadeHeight; y++ )
	{
		int red, grn, blu;

		red = TransitionColor( GetRValue(crShadow), GetRValue(crFace), y, deltaR );
		grn = TransitionColor( GetGValue(crShadow), GetGValue(crFace), y, deltaG );
		blu = TransitionColor( GetBValue(crShadow), GetBValue(crFace), y, deltaB );

		CPen pen( PS_SOLID, 1, RGB(red, grn, blu) );
		CPen *oldPen = pDC->SelectObject( &pen );

		if( bHorizontal == TRUE )
		{
			{
				pDC->MoveTo(rectWindow.left, rectWindow.bottom-y);
				pDC->LineTo(rectWindow.Width(), rectWindow.bottom-y);
			}
		}
		else // GF95_VERTICAL
		{
			{
				pDC->MoveTo( rectWindow.right-y, rectWindow.top );
				pDC->LineTo( rectWindow.right-y, rectWindow.bottom );
			}
		}

		pDC->SelectObject( oldPen );

	}//END_FOR
}

void GetWindowBitmap( CWnd* pWnd, CBitmap* bmpWindow )
{

	DWORD dwWndStyle = pWnd->GetStyle();

	if( dwWndStyle & WS_HSCROLL )
		pWnd->ShowScrollBar( SB_HORZ, false );

	if( dwWndStyle & WS_VSCROLL )
		pWnd->ShowScrollBar( SB_VERT, false );


	//
	// Get the window rect
	//
	CRect rectWindow;
	pWnd->GetClientRect( rectWindow );

	//
	// Create the bitmap
	//
	CClientDC dc( pWnd );
	VERIFY( bmpWindow->CreateCompatibleBitmap( &dc, rectWindow.Width(), rectWindow.Height() ) );

	//
	// Create temp DC and select newly created bitmap into temp DC. 
	//
	CDC tmpdc;
	tmpdc.CreateCompatibleDC( &dc );

	int nSavedDC = tmpdc.SaveDC();
	CBitmap* pOldBmp = tmpdc.SelectObject( bmpWindow );

	pWnd->Print( &tmpdc, PRF_CLIENT|PRF_NONCLIENT|PRF_ERASEBKGND|PRF_CHILDREN );

	tmpdc.SelectObject( pOldBmp );

	//
	// Re-enable the scroll bars...
	//
	if( dwWndStyle & WS_HSCROLL )
		pWnd->ShowScrollBar( SB_HORZ, true );

	if( dwWndStyle & WS_VSCROLL )
		pWnd->ShowScrollBar( SB_VERT, true );

	return;
}



//***************************************************************************
//
//
//***************************************************************************
BYTE TransitionColor
( 
	const BYTE bySource, 
	const BYTE byDestination, 
	const int nIndex, 
	const float nDelta 
)
{
	BYTE byResult = byDestination;

	if( bySource < byDestination )
	{
		byResult = bySource + (int)(nIndex * ((float)nDelta));
	}
	else if( bySource > byDestination )
	{
		byResult = bySource - (int)(nIndex * ((float)nDelta));
	}

	return byResult;
}
