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
#include "stdafx.h"
#include "dllmain.h"
#include "OutLookStyleView.h"
#include "COMMCTRL.h"
#include <cmath>
#include "HLPRFuncs.h"
#include "Cursor.h"
#include "Mouse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const int MOUSE_TRACK_EVENT = 0x1111;

BEGIN_MESSAGE_MAP(COutLookStyleView, CWnd)
	ON_MESSAGE(WM_CREATETABPAGE,OnCreatePage)
	ON_MESSAGE(WM_TABCHANGE,OnActivePage)
	ON_MESSAGE(WM_MODIFYTABPAGE,OnModifyPage)
	ON_MESSAGE(WM_TGM_SET_CAPTION,OnTgmSetCaption)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_WM_SETCURSOR()
	ON_WM_SYSCOLORCHANGE()
	ON_WM_TIMER()
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()

COutLookStyleView::COutLookStyleView() :
m_nButtonHeight(SOB_BAR_DEFAULT_BTN_HEIGHT),
m_nViewCount(0),
m_nActiveView(0),
m_nMouseOnButton(-1),
m_hHandCursor(0),
m_nPriviousButton(0),
m_bLButtonDown(false),
m_bTrackLeave(false),
m_bTrackingMouse(false),
m_dwViewStyle( SOB_VIEW_HORZ | SOB_VIEW_ANIMATE )
{
}

COutLookStyleView::~COutLookStyleView()
{
	if( m_hHandCursor ) 
		DestroyCursor( m_hHandCursor );

	for(auto x = m_buttonArray.GetUpperBound(); x >= 0; x--)
	{
		COutLookBar* pButton = m_buttonArray.GetAt( x );
		delete pButton;
	}

}

void COutLookStyleView::OnDraw(CDC* pDC)
{
	UNUSED_ALWAYS( pDC );
}

int COutLookStyleView::CreateView( CString szcViewTitle, CRuntimeClass* pViewClass, CCreateContext* pContext,	int iIconIndex,	const DWORD dwStyle /*= WS_CHILD|WS_VISIBLE*/ )
{
	int nViewID = GetViewCount();
	
#ifdef _DEBUG
	ASSERT_VALID(this);
	ASSERT(pViewClass != NULL);
	ASSERT(pViewClass->IsDerivedFrom(RUNTIME_CLASS(CWnd)));
	ASSERT(AfxIsValidAddress(pViewClass, sizeof(CRuntimeClass), false));

	if(NULL != GetDlgItem(GetViewID(nViewID)))
	{
		TRACE0("Error: CreateView - view already exists!" );
		ASSERT(false);
		return SOB_ERROR;
	}
#endif

	CWnd* pWnd;
	TRY
	{
		pWnd = STATIC_DOWNCAST( CWnd, pViewClass->CreateObject() );

		if (pWnd == NULL)
		{
			AfxThrowMemoryException();
		}
	}
	CATCH_ALL(e)
	{
		TRACE0("Out of memory creating a view.\n");

		//
		// Note: DELETE_EXCEPTION(e) not required
		//
		return SOB_ERROR;
	}
	END_CATCH_ALL

	ASSERT_KINDOF( CWnd, pWnd );
	ASSERT( NULL == pWnd->m_hWnd );       // not yet created

	//
	// Create with the right size (wrong position)
	//
	if(!pWnd->Create( NULL, NULL, dwStyle, CRect(0,0,0,0), this, GetViewID(nViewID), pContext ))
	{
		TRACE0("Warning: couldn't create client view for Outlookbar.\n");
		return SOB_ERROR;
	}

	COutLookBar* pButton = NULL;
	try
	{
		pButton = new COutLookBar();
	}
	catch( CMemoryException* memex )
	{
		memex->ReportError();
		memex->Delete();
		return SOB_ERROR;
	}

	pButton->SetParentWnd(CWnd::FromHandlePermanent(pWnd->GetSafeHwnd()));
	pButton->SetButtonTitle(szcViewTitle);
	pButton->m_iIconIndex = iIconIndex;
	pButton->m_pImageList = &m_hButtonImageList;
	
	return (int)m_buttonArray.Add(pButton);
}

int COutLookStyleView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	LoadHandCursor( m_hHandCursor );
	return 0;
}

CWnd* COutLookStyleView::GetView(const int nView) const 
{
	ASSERT( nView <= GetViewCount() );
	return m_buttonArray.GetAt( nView )->GetParentWnd();
}

int COutLookStyleView::GetViewID(const int nID) const 
{
	return SOB_BAR_DEFAULT_FIRST_VIEW_ID + nID;
}

int COutLookStyleView::GetViewCount() const 
{
	return (int)m_buttonArray.GetSize();
}

DWORD COutLookStyleView::GetBarStyle() const
{
	return m_dwViewStyle;
}

int COutLookStyleView::GetActiveView() const
{
	return m_nActiveView;
}

int COutLookStyleView::SetActiveView(const int nNewView, const BOOL bRedraw /*= true*/)
{
	int nOldView = m_nActiveView;
	m_nActiveView = nNewView;
	if( bRedraw )
		Invalidate( true );

	return nOldView;
}

void COutLookStyleView::ModifyViewStyle(const DWORD dwRemove, const DWORD dwAdd, const BOOL bRedraw)
{
	m_dwViewStyle &= ~dwRemove;
	m_dwViewStyle |=  dwAdd;

	if( bRedraw )
		Invalidate( true );
}

BOOL COutLookStyleView::RemoveView(const int nView)
{
	BOOL bResult = false;
	
	if( GetViewCount() )
	{
		CWnd* pWnd = GetView(nView);
		if( pWnd )
		{
			COutLookBar* pBtn = m_buttonArray.GetAt(nView);			
			if(pBtn)
			{
				delete pBtn;
				m_buttonArray.RemoveAt( nView );
				pWnd->PostMessage( WM_CLOSE );
				RecalcLayout();
				Invalidate(true);
				bResult = true;
			}
		}
	}

	return bResult;
}

void COutLookStyleView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CWnd::OnMouseMove(nFlags, point);
	int  nButton		= ButtonHitTest( point );
	BOOL bIsLButtonDown = (nFlags & MK_LBUTTON); 

	if( -1 != nButton )  // The mouse is over one of the buttons...
	{
		//
		// left bustton is down...
		//
		if(bIsLButtonDown)
		{
			if(nButton != m_nPriviousButton)
			{
				if(nButton == m_nMouseOnButton)
				{
					InvalidateButton(nButton);
					m_nPriviousButton = m_nMouseOnButton;
				}
				else
				{
					if( nButton != m_nMouseOnButton && -1 != m_nPriviousButton )
					{
						InvalidateButton( m_nMouseOnButton );
						m_nPriviousButton = -1;;
					}
				}

			}//END_IF
		}
		else if( nButton != m_nPriviousButton )
		{
			if( -1 != m_nPriviousButton )
				InvalidateButton( m_nPriviousButton );

			InvalidateButton( nButton );

			m_nMouseOnButton = nButton;

			if( m_bTrackingMouse )
			{
				SetTimer( MOUSE_TRACK_EVENT, 200, NULL );
				m_bTrackingMouse = true;
			}

			m_nPriviousButton = nButton;
		}
	
	}
	else // The mouse is not over a button...
	{
		if( -1 != m_nPriviousButton && -1 != m_nMouseOnButton )
		{
			if( bIsLButtonDown )
			{
				InvalidateButton( m_nMouseOnButton );
			}
			else
			{
				InvalidateButton( m_nPriviousButton );
			}

			if( m_bTrackingMouse )
			{
				KillTimer( MOUSE_TRACK_EVENT );
				m_bTrackingMouse = false;
			}
		
		}//END_IF

		m_nPriviousButton = -1;
	}

	return;	
}

void COutLookStyleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CWnd::OnLButtonDown(nFlags, point);

	if( GetCapture() != this )
		Mouse.Capture( this );

	int nButton = ButtonHitTest( point );

	if( -1 != nButton )
	{
	    InvalidateButton( nButton );
	}
	
	m_bLButtonDown = true;
}

void COutLookStyleView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	int nButton = ButtonHitTest( point );

	if( -1 != nButton )  // The mouse is over a button. 
	{
		//
		// Clean up old button...
		//
		if( nButton != m_nMouseOnButton ) 
		{
			if( -1 != m_nMouseOnButton )
				InvalidateButton( m_nMouseOnButton );
		}

		//
		// Draw new MouseOnButton...
		//
		InvalidateButton( nButton );

		if( nButton == m_nMouseOnButton )
		{
			if( nButton != m_nActiveView )
			{				
				//
				// Only animat if both the global animate and individual 
				// button animate flags are turned on.
				//
				if( (m_dwViewStyle & SOB_VIEW_ANIMATE) && 
					(m_buttonArray.GetAt(nButton)->GetButtonStyle() & SOB_BTN_ANIMATE) )
				{
					ViewAnimation( nButton, m_nActiveView );		
				}

				int nOldPage = m_nActiveView;
				m_nActiveView = nButton;

				RecalcLayout();
				//if(!m_pWndNode->m_pDoc&&m_pWndNode->m_pDoc->m_pCompositor)
				//	m_pWndNode->m_pDoc->m_pCompositor->RecalcLayout();
				//theApp.HostPosChanged();
				CString str = _T("");
				str.Format(_T("%d"), m_nActiveView);
				m_pWndNode->put_Attribute(CComBSTR(L"activepage"), str.AllocSysString());
				//SendMessage(WM_TGM_SETACTIVEPAGE);
				//OnActivePage(m_nActiveView, nOldPage);
				::SendMessage(m_hWnd, WM_TABCHANGE, m_nActiveView, nOldPage);
				Invalidate();
			}
		}

		//
		//Save the new MouseOnButton location...
		//
		m_nMouseOnButton = nButton;
	}
	else if( -1 != m_nMouseOnButton ) // The mouse is NOT over a button. 
	{ 
		//
		// Clean up old button...
		//
		InvalidateButton( m_nMouseOnButton );
		m_nMouseOnButton = -1;
	}

	Mouse.Release();
	
	m_bLButtonDown = false;

	CWnd::OnLButtonUp(nFlags, point);
}

BOOL COutLookStyleView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	BOOL bResult = false;

	CPoint pt = Mouse;
	ScreenToClient( &pt );

	int nButton = ButtonHitTest( pt );

    if( NULL != m_hHandCursor && -1 != nButton )
    {
        ::SetCursor( m_hHandCursor );

        bResult =  true;
    }
	else
	{
		bResult = CWnd::OnSetCursor(pWnd, nHitTest, message)>0;
	}

    return bResult;
}

int COutLookStyleView::ButtonHitTest( const CPoint& point ) 
{
	int nButton = -1;

	int nViewCount = GetViewCount();

	for( int x = 0; x < nViewCount; x++ )
	{
		CRect rectButton = GetButtonRect( x );
		rectButton.InflateRect( 1, 1);
		if( rectButton.PtInRect( point ) )
		{
			nButton = x; 
		}

	} //END_FOR

	return nButton;
}

void COutLookStyleView::OnTimer(UINT_PTR nIDEvent)
{
	if( MOUSE_TRACK_EVENT == nIDEvent )
	{
		CPoint pt = Mouse;
		ScreenToClient( &pt );
		int nButton = ButtonHitTest( pt );
		if( -1 == nButton )
		{
			PostMessage( WM_MOUSEMOVE, m_bLButtonDown?MK_LBUTTON:0, MAKELPARAM( pt.x, pt.y ) );
		}
	}
	
	CWnd::OnTimer(nIDEvent);
}

void COutLookStyleView::RecalcLayout( const BOOL bRepaint /*=true*/ )
{
	CWnd  *pWnd;
	CRect rectParent;

	//
	// Get parent rect...
	//
	GetWindowRect( rectParent );

	//
	// Here I'm practicing a bit of voodo.  All inactive child windows are 
	// moved off the parent window rect, in effect making inactive child 
	// windows hidden.  This technique was implemented over using SW_HIDE 
	// because the animation requires inactive windows to be able to paint 
	// to a temporary bitmap.  Windows hidden with SW_HIDE are unable to 
	// paint to a temporary bitmap - to the best of my humble knowledge.  
	// If someone knows of a different / better technique, please send 
	// me a note.  
	// Thanks.
	//
	for(auto x = m_buttonArray.GetUpperBound(); x >= 0; x--)
	{
		int nIndex = (int)x;
		CRect rectChildWnd = GetInsideRect(nIndex);
		pWnd = GetView(nIndex);
		
		if(nIndex != m_nActiveView)
		{
			if( m_dwViewStyle & SOB_VIEW_HORZ )
			{
				//
				// HORZ - Move child rect off the parent rect...
				//
				rectChildWnd.OffsetRect( rectParent.right, 0 );
			}
			else
			{
				//
				// VERT - Move child rect off the parent rect...
				//
				rectChildWnd.OffsetRect( 0, rectParent.bottom );
			}
			pWnd->ShowWindow(SW_HIDE);
			//rectChildWnd=CRect(0,0,0,0);
		}
		else
		{
			pWnd->ShowWindow(SW_SHOW);
		}
		pWnd->MoveWindow( rectChildWnd, bRepaint );
		if(nIndex != m_nActiveView)
			pWnd->ShowWindow(SW_HIDE);
	}
	//for (int x = m_buttonArray.GetUpperBound(); x >= 0; x--)
	//{
	//	if (x != m_nActiveView)
	//	{
	//		GetView(x)->ShowWindow(SW_HIDE);
	//	}
	//}
	InvalidateRect(NULL);
}

void COutLookStyleView::OnSize( UINT nType, int cx, int cy ) 
{
	CWnd::OnSize(nType, cx, cy);

	for(int x = (int)m_buttonArray.GetUpperBound(); x >= 0; x--)
	{
		CRect rectButton = GetButtonRect( x );
		COutLookBar *pButton = m_buttonArray.GetAt( x );
		pButton->Size( rectButton, m_dwViewStyle );
	}

	RecalcLayout();
	
	return;	
}

CRect COutLookStyleView::GetButtonRect( const int nButton ) const
{
	CRect rectClient;
	GetClientRect( rectClient );
	
	return GetButtonRect( nButton, rectClient );
}

CRect COutLookStyleView::GetButtonRect( const int nButton, const CRect& rectClient ) const
{
	ASSERT( nButton < GetViewCount() );  // Request greater than max view count.

	CRect rc( rectClient );
	CRect rectButton; 
	
	const int nMaxCount = GetViewCount();

	if( m_dwViewStyle & SOB_VIEW_HORZ )
	{
		if( nButton > m_nActiveView )
		{
			rectButton.SetRect( rc.left, 
								rc.bottom - (((nMaxCount - nButton)) * m_nButtonHeight), 
								rc.right,
								rc.bottom - (((nMaxCount - nButton)  -1) * m_nButtonHeight));
            //
			// Subtract one for border line.
            //
			rectButton.bottom--;
		}
		else
		{
			rectButton.SetRect( rc.left,
								rc.top + (nButton * m_nButtonHeight),
								rc.right,
								rc.top + (((1 + nButton) * m_nButtonHeight) -1));
		}

	}
	else // BUTTONS_VERTICAL   
	{
		if( nButton > m_nActiveView )
		{
			rectButton.SetRect( rc.right - (((nMaxCount - nButton)) * m_nButtonHeight),
								rc.top,
								rc.right - (((nMaxCount - nButton)-1) * m_nButtonHeight),
								rc.bottom );
			//					
			// Subtract one for border line.
            //
			rectButton.right--;
		}
		else
		{
			rectButton.SetRect( rc.left + (nButton * m_nButtonHeight),
								rc.top ,
								(((1 + nButton) * m_nButtonHeight) -1),
								rc.bottom );
		}
	}
	
	return rectButton;
}

CRect COutLookStyleView::GetInsideRect( int nButton ) const
{
	CRect rectInside; 
	GetClientRect( rectInside );

	const int nViewCount = GetViewCount();

	if( m_dwViewStyle & SOB_VIEW_HORZ  )
	{
		if( nViewCount > 0 )
		{
			rectInside.top    += (m_nButtonHeight * (nButton + 1)) -1;
			rectInside.bottom -= ((nViewCount - nButton) - 1) * m_nButtonHeight;
			rectInside.top++;    
		}

	}
	else // BUTTONS_VERTICAL   
	{
		if( nViewCount > 0 )
		{
			rectInside.left += (m_nButtonHeight * (nButton + 1)) -1;
			rectInside.right-= ((nViewCount - nButton) - 1) * m_nButtonHeight;

			rectInside.left++;    
		}
	}

	return rectInside;
}

BOOL COutLookStyleView::OnEraseBkgnd(CDC* pDC) 
{
	if (pDC == NULL)
		return false;
	CRect rectClient;
	GetClientRect( rectClient );

	//
	// No need to setup clipping if there's no children windows...
	//
	if( ! GetViewCount()  )
	{
		pDC->FillSolidRect( rectClient, GetSysColor(COLOR_3DSHADOW) );
		return true;
	}

	int nViewCount = GetViewCount();
	int nDCSaved   = pDC->SaveDC();

	//
	// Setup own internal clpping to help prevent flickering.
	//

	CRgn rgnClip;
	rgnClip.CreateRectRgnIndirect( rectClient );

	CRect rectButton;

	for( int i = 0; i < nViewCount; i++ )
	{		
		rectButton = GetButtonRect( i );

		CRgn rgnButton;
		rgnButton.CreateRectRgnIndirect( rectButton );
		rgnClip.CombineRgn( &rgnButton, &rgnClip, RGN_XOR );
	}

	CRect rectChild = GetInsideRect( m_nActiveView );

	CRgn rgnChild;
	rgnChild.CreateRectRgnIndirect( rectChild );
	rgnClip.CombineRgn( &rgnClip, &rgnChild, RGN_XOR );

	pDC->SelectClipRgn( &rgnClip, RGN_AND );

	//
	// Fill the window cliped rect with Dark Shadow color.
	//
	pDC->FillSolidRect( rectClient, GetSysColor(COLOR_3DSHADOW) );

	//
	// Draw a dark line to create a nice border effect between buttons and views.
	//
	CPen pen( PS_SOLID, 1, GetSysColor(COLOR_3DDKSHADOW) );

	if( m_dwViewStyle & SOB_VIEW_HORZ )
	{
		pDC->MoveTo( rectChild.left,  rectChild.top-1 );
		pDC->LineTo( rectChild.right, rectChild.top-1 );

	}
	else // BUTTONS_VERTICAL   
	{
		pDC->MoveTo( rectChild.left-1,  rectChild.top );
		pDC->LineTo( rectChild.left-1,  rectChild.bottom );
	}

	//
	// DC restored...
	//
	pDC->RestoreDC( nDCSaved );

	return true;
}

void COutLookStyleView::InvalidateButton( const int nButton ) 
{
	ASSERT( nButton < GetViewCount() );

	CRect rectButton = GetButtonRect( nButton );

	InvalidateRect( rectButton );
}

void COutLookStyleView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CPoint pt = Mouse;
	ScreenToClient( &pt );

	int nButton	= ButtonHitTest( pt );

	for(int x = (int)m_buttonArray.GetUpperBound(); x >= 0; x--)
	{
		CRect rectButton = GetButtonRect( x );

		COutLookBar *pButton = m_buttonArray.GetAt( x );

		BUTTON_STATE dwButtonStyle = SOB_BTN_UP;
		
		if( nButton == x )
		{
			if( m_bLButtonDown )
            {
				dwButtonStyle = SOB_BTN_HIT;
            }
			else
            {
				dwButtonStyle = SOB_BTN_OVER;
            }
		}
		else if( m_bLButtonDown && x == m_nMouseOnButton )
		{
			dwButtonStyle = SOB_BTN_OVER;
		}

		pButton->Draw( &dc, rectButton, dwButtonStyle|m_dwViewStyle );
	}

	return; // Do not call CWnd::OnPaint() for painting messages
}

LRESULT COutLookStyleView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch( message )
	{
	case WM_PRINTCLIENT :
		{
			OnPrintClient( (HDC)wParam, (UINT)lParam );
			return true;
		}
		break;
	}
	return CWnd::DefWindowProc(message, wParam, lParam);
}

void COutLookStyleView::OnPrintClient( HDC hDC, UINT uFlags) 
{
	UNUSED_ALWAYS( uFlags );

	CDC *pDC = CDC::FromHandle(hDC);;
	
	for(int x = (int)m_buttonArray.GetUpperBound(); x >= 0; x--)
	{
		CRect rectButton = GetButtonRect( x );

		COutLookBar *pButton = m_buttonArray.GetAt( x );
		pButton->Draw( pDC, rectButton, SOB_BTN_UP|m_dwViewStyle );
	}
	
}

void COutLookStyleView::OnSysColorChange( void )
{
	CClientDC dc( this );

	//
	// We're gunna tell all our buttons that the system color is changing...
	//
	for(auto x = m_buttonArray.GetUpperBound(); x >= 0; x--)
	{
		COutLookBar *pButton = m_buttonArray.GetAt( x );
		pButton->OnSysColorChange();
	}

	RecalcLayout();
}

void COutLookStyleView::ViewAnimation( const int nNewView, const int nPreviousView )
{
	CClientDC dc( this );

	CBitmap	bmpCurrentView;		//  Bitmap of current view.
	CBitmap bmpNewView;			//	Bitmap of hidden view about to displayed.
	CBitmap bmpAnimation;		//  Bitmap used to for final animation.

	CDC		dcAnimation;		//  DC used for copying bitmaps.
	CDC     dcTemporary;        //  DC used to temporary copies.

	CRect	rectViews;			//  Rect of views - used just for width and height.
	CRect	rectClient;			//  Rect of client.
	CRect	rectButton;			//  Used to calculate button geometry.
	
	int nAnimationHeight = 0;
	int nAnimationWidth  = 0;

	DWORD dwStartTickCount = 0;
	DWORD dwIntervalTickCount = 0;

	//
	// Get system tickcount before entering into to animation loop...
	//
	dwIntervalTickCount = dwStartTickCount = GetTickCount();

	rectViews = GetInsideRect(0);
	GetClientRect( rectClient );

	//
	// Make sure both the height and width are positive values. 
	//
	rectViews.NormalizeRect();

	//
	// Grab views into bitmaps.
	//
	GetWindowBitmap( GetView(nPreviousView), &bmpCurrentView );
	GetWindowBitmap( GetView(nNewView), &bmpNewView );

	//
	//  Calculate animation bitmap view / height size;
	//
	if( m_dwViewStyle & SOB_VIEW_HORZ )
	{
		nAnimationHeight = (abs(nNewView - nPreviousView) * m_nButtonHeight);
		nAnimationHeight += rectViews.Height() * 2;
		
		nAnimationWidth  = rectViews.Width();		
	}
	else
	{
		nAnimationWidth = (abs(nNewView - nPreviousView) * m_nButtonHeight);
		nAnimationWidth += rectViews.Width() * 2;

		nAnimationHeight = rectViews.Height();
	}

	//
	// Create the bitmap used for the animation...
	//
	VERIFY( bmpAnimation.CreateCompatibleBitmap( &dc, nAnimationWidth, nAnimationHeight ) );

	//
	// Create temporary dc used to create animation bitmap.
	//
	VERIFY( dcAnimation.CreateCompatibleDC( &dc ) );
	VERIFY( dcTemporary.CreateCompatibleDC( &dc ) );

	//
	// Select animation bitmap into animation DC.
	//
	CBitmap *pOldAnimationBmp = dcAnimation.SelectObject( &bmpAnimation );

	//
	// Fill animation bitmap with with 3D shadow...
	//
	dcAnimation.FillSolidRect( CRect(rectClient.left, 
									 rectClient.top, 
		                             nAnimationWidth, 
									 nAnimationHeight), 
									 ::GetSysColor(COLOR_3DSHADOW) );

	//
	// Select current views bitmap into temporary DC.
	//
	CBitmap  *pOldTemporaryBmp;

	int	nStartBtn;
	int	nEndBtn;

	if( nNewView > nPreviousView )
	{
		pOldTemporaryBmp = dcTemporary.SelectObject( &bmpCurrentView );

		nStartBtn = nPreviousView;
		nEndBtn   = nNewView;
	}
	else
	{
		pOldTemporaryBmp = dcTemporary.SelectObject( &bmpNewView );

		nStartBtn = nNewView;
		nEndBtn   = nPreviousView;
	}

	//
	// Create pen used for dark border... 
	//
	CPen pen( PS_SOLID, 1, GetSysColor(COLOR_3DDKSHADOW) );
	CPen *pOldPen = dcAnimation.SelectObject( &pen );

	//
	// Copy the current view bitmap onto the animation bitmap...
	//
	dcAnimation.BitBlt( 0, 0, rectViews.Width(), rectViews.Height(), &dcTemporary, 0, 0, SRCCOPY );
	dcTemporary.SelectObject( pOldTemporaryBmp );

	if( m_dwViewStyle & SOB_VIEW_HORZ )
	{
		for( int x = nStartBtn; x < nEndBtn; x++ )
		{
			COutLookBar  *pButton = m_buttonArray.GetAt(x+1);
			ASSERT( pButton );

			rectButton.left   = rectViews.left;
			rectButton.top    = rectViews.Height() + (m_nButtonHeight * (x - nStartBtn));
			rectButton.right  = rectViews.Width();
			rectButton.bottom = (rectButton.top + m_nButtonHeight)-1;

			if( pButton )
				pButton->Draw( &dcAnimation, rectButton, m_dwViewStyle );
		}

		dcAnimation.MoveTo( rectButton.left,  rectButton.bottom-1 );
		dcAnimation.LineTo( rectButton.right, rectButton.bottom-1 );
	}
	else  //  SOB_VIEW_VERTICAL
	{ 
		for( int x = nStartBtn; x < nEndBtn; x++ )
		{
			COutLookBar  *pButton = m_buttonArray.GetAt(x+1);
			ASSERT( pButton );

			rectButton.left	  = rectViews.Width() + (m_nButtonHeight * (x - nStartBtn));
			rectButton.top	  = rectViews.top;
			rectButton.right  = (rectButton.left + m_nButtonHeight)-1;
			rectButton.bottom = rectViews.bottom;

			if( pButton )
				pButton->Draw( &dcAnimation, rectButton, m_dwViewStyle );
		}

		dcAnimation.MoveTo( rectButton.right-1,  rectButton.top );
		dcAnimation.LineTo( rectButton.right-1,  rectButton.bottom );
	}

	//
	// Restore old pen object...
	//
	dcAnimation.SelectObject( pOldPen ); 

	//
	// Select proper bitmap into in temporary DC.
	//
	if( nNewView > nPreviousView )
	{
		pOldAnimationBmp = dcTemporary.SelectObject( &bmpNewView );
	}
	else
	{
		pOldTemporaryBmp = dcTemporary.SelectObject( &bmpCurrentView );
	}

	//
	// Copy the temp bitmap onto the animation bitmap... 
	//
	if( m_dwViewStyle & SOB_VIEW_HORZ )
	{
		dcAnimation.BitBlt( 0, 
			                rectButton.bottom+1, 
							rectViews.Width(), 
							rectViews.Height(), 
							&dcTemporary, 
							0, 
							0, 
							SRCCOPY );
	}
	else
	{
		dcAnimation.BitBlt( rectButton.right, 
			                0, 
							rectViews.Width(), 
							rectViews.Height(), 
							&dcTemporary, 
							0, 
							0, 
							SRCCOPY );
	}

	//
	// Restore DC bimap.
	//
	dcTemporary.SelectObject( pOldAnimationBmp );
	
	int nDif = (nEndBtn - nStartBtn)-1;

	float nDisplacement;
	int nHeightWidth;
		
	if( m_dwViewStyle & SOB_VIEW_HORZ )
	{
		nDisplacement = ((float)rectViews.Height() / 20.0f);
		nHeightWidth  = rectViews.Height();
	}
	else
	{
		nDisplacement = ((float)rectViews.Width() / 20.0f);
		nHeightWidth  = rectViews.Width();
	}
	
	rectButton = GetButtonRect( nPreviousView );


	//
	// This is the adnimation loop.  
	//
	for( float nBmpPos = nDisplacement; nBmpPos < nHeightWidth; nBmpPos += nBmpPos )
	{
		if( nNewView > nPreviousView )
		{
			if( m_dwViewStyle & SOB_VIEW_HORZ )
			{
				dc.BitBlt( rectButton.left, 
						   rectButton.bottom+1, 
						   rectViews.right, 
						   rectViews.bottom+((rectButton.Height()+1)*nDif), 
						   &dcAnimation, 
						   0, 
						   (int)nBmpPos, 
						   SRCCOPY );
			}
			else
			{
				dc.BitBlt( rectButton.right+1, 
						   rectViews.top,
						   rectViews.Width() + (rectButton.Width()+1)*(nEndBtn-nStartBtn), 						   
						   rectViews.bottom, 
						   &dcAnimation, 
						   (int)nBmpPos, 
						   0, 
						   SRCCOPY );

			}
		}
		else
		{
			rectButton = GetButtonRect( nNewView );

			if( m_dwViewStyle & SOB_VIEW_HORZ )
			{
				dc.BitBlt( 0, 
						   rectButton.bottom+1, 
						   rectViews.right, 
						   rectViews.Height() + ((rectButton.Height()+1)*(nEndBtn-nStartBtn)),
						   &dcAnimation, 
						   0, 
						   rectViews.Height() - (int)nBmpPos, 
						   SRCCOPY );
			}
			else
			{
				dc.BitBlt( rectButton.right+1, 
						   rectViews.top,
						   rectViews.Width() + (rectButton.Width()+1)*(nEndBtn-nStartBtn), 						   
						   rectViews.bottom, 
						   &dcAnimation, 
						   rectViews.Width() - (int)nBmpPos, 
						   0, 
						   SRCCOPY );
			}

		}//END_ELSE


		DWORD dwTempTickCount = GetTickCount();

		if( (dwTempTickCount -  dwStartTickCount) > SOB_BAR_DEFAULT_ANIMATION_LIMIT )
			break;
		
		if( (dwTempTickCount < (dwIntervalTickCount+SOB_BAR_DEFAULT_ANIMATION_SPEED) ))
			Sleep( (dwIntervalTickCount+SOB_BAR_DEFAULT_ANIMATION_SPEED) - dwTempTickCount );
							
		dwIntervalTickCount = dwTempTickCount;

	}//END_FOR

}

COutLookBar::COutLookBar() : 
	m_dwButtonStyle(0),
	m_bUpdateBitmaps(true)
{
	m_dwButtonStyle = SOB_BTN_FANCYFACE | SOB_BTN_ANIMATE;
	m_pImageList = NULL;
};

COutLookBar::~COutLookBar()
{
}

COutLookBar* COutLookStyleView::GetButton( const int nButton ) const
{
	ASSERT( nButton < GetViewCount() );
	return m_buttonArray.GetAt( nButton );
}

CWnd* COutLookBar::GetParentWnd( void )
{
	return m_pWndParent;
}

void COutLookBar::SetParentWnd( CWnd* pWnd )
{
	m_pWndParent = pWnd;
}

DWORD COutLookBar::GetButtonStyle( void ) const 
{
	return m_dwButtonStyle;
}

void COutLookBar::ModifyButtonStyle( const DWORD dwRemove,
									   const DWORD dwAdd )
{
	m_dwButtonStyle = (m_dwButtonStyle & ~dwRemove);
	m_dwButtonStyle |= dwAdd;
}

void COutLookBar::SetButtonTitle( CString szcTitle )
{
	m_strButtonTitle = szcTitle;
	m_bUpdateBitmaps = true;
}

CString COutLookBar::GetButtonTitle( void ) const
{
	return m_strButtonTitle;
}

void COutLookBar::Draw( CDC* pDC, const CRect& rectScreen, const DWORD dwFlags)
{
	int nSaveDC = pDC->SaveDC();

	BOOL bIsPressed		= (dwFlags & SOB_BTN_HIT)>0;
	BOOL bMouseOnButton	= (dwFlags & SOB_BTN_OVER)>0;

	CDC		 tmpDC;
	CBitmap* pOldBmp = NULL;

	const COLORREF	color3DDKSHADOW = ::GetSysColor(COLOR_3DDKSHADOW);
	const COLORREF  color3DSHADOW   = ::GetSysColor(COLOR_3DSHADOW);
	const COLORREF  color3DHILIGHT = ::GetSysColor(COLOR_3DHILIGHT);

	//
	// Create and or update button bitmaps...
	//
	if( m_bUpdateBitmaps ) 
	{
		UpdateBitmaps( pDC, dwFlags );
	}
	
	if( ! tmpDC.CreateCompatibleDC(pDC) )
	{
		AfxThrowMemoryException();
	}
	
	if( bIsPressed )
	{
		//
		// Copy pressed bitmap to destination DC.
		//
		CBitmap* pOldBmp = tmpDC.SelectObject( &m_bmpPressedFace );

		pDC->BitBlt( rectScreen.left, 
			         rectScreen.top, 
					 rectScreen.right, 
					 rectScreen.bottom, 
					 &tmpDC, 
					 0,
					 0, 
					 SRCCOPY );

		//
		// Restore DC.
		//
		tmpDC.SelectObject( pOldBmp  );

		//
		// Draw border around bitmap.
		//
		pDC->Draw3dRect( rectScreen, 
			             color3DDKSHADOW, 
						 ::GetSysColor(COLOR_3DSHADOW) );

		pDC->Draw3dRect( rectScreen.left+1,
						 rectScreen.top+1, 
			             rectScreen.right,
						 rectScreen.bottom-1,
						 color3DSHADOW, 
						 color3DHILIGHT );
	}
	else 
	{
		//
		// Copy normal bitmap to destination DC.
		//
		pOldBmp = tmpDC.SelectObject( &m_bmpNormalFace );

		pDC->BitBlt( rectScreen.left, 
					 rectScreen.top, 
					 rectScreen.right, 
					 rectScreen.bottom, 
					 &tmpDC, 
					 0,
					 0, 
					 SRCCOPY );

		//
		// Draw border around bitmap.
		//
		if( false == bMouseOnButton ) 
		{	
			pDC->Draw3dRect( rectScreen, 
				             color3DHILIGHT, 
							 color3DSHADOW );			
		}
		else
		{
			pDC->Draw3dRect( rectScreen.left,
							 rectScreen.top, 
				             rectScreen.right-1,
							 rectScreen.bottom-1,
							 color3DHILIGHT, 
							 color3DSHADOW );

			pDC->Draw3dRect( rectScreen, 
				             color3DHILIGHT, 
							 color3DDKSHADOW );
		}

		//
		// Restore DC.
		//
		tmpDC.SelectObject( pOldBmp );
	
	}//END_ELSE

	//
	// Restore DC.
	//
	pDC->RestoreDC( nSaveDC );

	return;
}

void COutLookBar::Size( const CRect& rectNewSize, const DWORD dwStyle )
{
	//
	// Only update if bitmaps have changed from the previous size.
	//
	if( dwStyle & SOB_VIEW_HORZ )
		if( m_rectButton.Width() == rectNewSize.Width() )
			return;

	if( dwStyle & SOB_VIEW_VERT )
		if( m_rectButton.Height() == rectNewSize.Height() )
			return;

	//
	// Save new rect size and set updatebitmaps to true;
	//
	m_rectButton = rectNewSize;
	m_bUpdateBitmaps = true;
}

void COutLookBar::OnSysColorChange( void )
{
	//
	// Set updatebitmaps to true;
	//
	m_bUpdateBitmaps = true;
}

void COutLookBar::UpdateBitmaps( CDC* pDC, const DWORD dwFlags )
{
	CBitmap* pOldBmp = NULL;

	//
	// Nuke old bitmaps - if any...
	//
	m_bmpNormalFace.DeleteObject();
	m_bmpPressedFace.DeleteObject();


	COLORREF crFace   =  GetSysColor( COLOR_3DFACE );//RGB(128, 128, 255); 
	COLORREF crShadow = GetSysColor( COLOR_3DSHADOW );

	CRect tmpRect( 0,0,m_rectButton.Width(), m_rectButton.Height() );

	CDC tmpDC;
	tmpDC.CreateCompatibleDC( pDC );

	BOOL bHorizontalButtons = (dwFlags & SOB_VIEW_HORZ)>0; 

	if( m_bmpNormalFace.CreateCompatibleBitmap( pDC, 
		                                        tmpRect.Width(), 
												tmpRect.Height() ) &&
		m_bmpPressedFace.CreateCompatibleBitmap( pDC, 
		                                        tmpRect.Width(), 
												tmpRect.Height() ) )
	{

		//
		// Make sure we can use fancy face buttons, and we have enough color resolution...
		//
		if( (m_dwButtonStyle & SOB_BTN_FANCYFACE) && (pDC->GetDeviceCaps(BITSPIXEL) >= 16) )
		{
			BYTE red, grn, blu;
			
			red =  GetRValue(crShadow);
			red += ((GetRValue(crFace) - red) /3);

			grn =  GetGValue(crShadow);
			grn += ((GetGValue(crFace) - grn) /3);

			blu =  GetBValue(crShadow);
			blu += ((GetBValue(crFace) - blu) /3);

			crShadow = RGB( red, grn, blu );

			//
			// This is where we fill in the Normal button face color...
			//
			pOldBmp = tmpDC.SelectObject( &m_bmpNormalFace );

			//
			// Make funky buttons if the color resolution is 16-bit or 
			// higher (32k color res)...
			//
			if( tmpDC.GetDeviceCaps( BITSPIXEL ) >= 16 )
			{
				GradientFill( &tmpDC, 
							  tmpRect,
							  crFace, 
							  crShadow, 
							  bHorizontalButtons );
			}
			else
			{
				tmpDC.FillSolidRect( tmpRect, crFace );
			}

			tmpDC.SelectObject( pOldBmp );

			//
			// This is where we fill in the Pressed button face color...
			//
			pOldBmp = tmpDC.SelectObject( &m_bmpPressedFace );

			//
			// Make funky buttons if the color resolution is 16-bit or 
			// higher (32k color res)...
			//
			if( tmpDC.GetDeviceCaps( BITSPIXEL ) >= 16 )
			{
				GradientFill( &tmpDC, 
							  tmpRect,
							  crShadow, 
							  crFace, 
							  bHorizontalButtons );

			}
			else
			{
				tmpDC.FillSolidRect( tmpRect, crFace );
			}

			tmpDC.SelectObject( pOldBmp );
							 
		}
		else // Use boring flat buttons.
		{
			pOldBmp = tmpDC.SelectObject( &m_bmpNormalFace );

			tmpDC.FillSolidRect( tmpRect, crFace );
			tmpDC.SelectObject( pOldBmp );

			pOldBmp = tmpDC.SelectObject( &m_bmpPressedFace );

			tmpDC.FillSolidRect( tmpRect, crFace );
			tmpDC.SelectObject( pOldBmp );
		}
		
		//
		// Now draw text on the bitmaps....
		//
		if( /*false*/ ! m_strButtonTitle.IsEmpty() )
		{
			CFont* pOldFont = tmpDC.SelectObject( 
				CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT)) );
			
			if( bHorizontalButtons )				
			{
				tmpDC.SetBkMode( TRANSPARENT );

				pOldBmp = tmpDC.SelectObject( &m_bmpNormalFace );

				tmpDC.DrawText( LPCTSTR(GetButtonTitle()), 
								-1, 
								tmpRect, 
								DT_SINGLELINE
							   |DT_CENTER
							   |DT_VCENTER
							   |DT_END_ELLIPSIS );
				if (m_pImageList && m_iIconIndex != -1)
					m_pImageList->Draw(&tmpDC,this->m_iIconIndex ,CPoint(3,(tmpRect.Height() - 16)/2),0);

				tmpDC.SelectObject( pOldBmp );

				CRect tmpRect( tmpRect );
				tmpRect.OffsetRect( 1, 1 );

				pOldBmp = tmpDC.SelectObject( &m_bmpPressedFace );
				tmpDC.DrawText( LPCTSTR(GetButtonTitle()), 
								-1, 
								tmpRect, 
								DT_SINGLELINE
							   |DT_CENTER
							   |DT_VCENTER
							   |DT_END_ELLIPSIS );
				if (m_pImageList && m_iIconIndex != -1)
					m_pImageList->Draw(&tmpDC,this->m_iIconIndex ,CPoint(3,(tmpRect.Height() - 16)/2),0);

				tmpDC.SelectObject( pOldBmp );
			}
			else  // VERT BUTTONS...
			{
				pOldBmp = tmpDC.SelectObject( &m_bmpNormalFace );

				DrawVerticalText( &tmpDC, tmpRect, GetButtonTitle(), SS_CENTER );				
				if (m_pImageList && m_iIconIndex != -1)
					m_pImageList->Draw(&tmpDC,this->m_iIconIndex ,CPoint((tmpRect.Width() - 16)/2,3),0);
				
				tmpDC.SelectObject( pOldBmp );

				CRect tmpRect( tmpRect );
				tmpRect.OffsetRect(1, 1);

				pOldBmp = tmpDC.SelectObject( &m_bmpPressedFace );

				DrawVerticalText(  &tmpDC, tmpRect, GetButtonTitle(), SS_CENTER );
				if (m_pImageList && m_iIconIndex != -1)
					m_pImageList->Draw(&tmpDC,this->m_iIconIndex ,CPoint((tmpRect.Width() - 16)/2,3),0);

				tmpDC.SelectObject( pOldBmp );
			}

			//
			// Restore old font
			//
			tmpDC.SelectObject( pOldFont );

		}// END_IF

		m_bUpdateBitmaps = false;
	}
	else
	{
		//
		// Oh, very bad!
		//
		AfxThrowMemoryException();
	}

}

void COutLookStyleView::PostNcDestroy()
{
	CWnd::PostNcDestroy();
	delete this;
}

BOOL COutLookStyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	WNDCLASS wndClass;
	wndClass.style=CS_DBLCLKS; 
    wndClass.lpfnWndProc=AfxWndProc; 
    wndClass.cbClsExtra=0; 
    wndClass.cbWndExtra=0; 
    wndClass.hInstance=AfxGetInstanceHandle(); 
    wndClass.hIcon=0; 
    wndClass.hCursor=::LoadCursor(NULL,IDC_ARROW); 
    wndClass.hbrBackground=0; 
    wndClass.lpszMenuName=NULL; 
	wndClass.lpszClassName=_T("Tangram OutlookBar Class");
	
	if(!AfxRegisterClass(&wndClass))
		return false;
	cs.lpszClass = wndClass.lpszClassName;

	return CWnd::PreCreateWindow(cs);
}

LRESULT COutLookStyleView::OnCreatePage(WPARAM wParam, LPARAM lParam)
{
	HWND hPageWnd = (HWND)wParam;
	int nViewID = GetViewCount();

#ifdef _DEBUG
	ASSERT_VALID(this);
	if( NULL != GetDlgItem( GetViewID(nViewID) ) )
	{
		TRACE0("Error: CreateView - view already exists!" );
		ASSERT(false);
		return SOB_ERROR;
	}
#endif

	COutLookBar* pButton = NULL;
	try
	{
		pButton = new COutLookBar();
	}
	catch( CMemoryException* memex )
	{
		memex->ReportError();
		memex->Delete();

		return SOB_ERROR;
	}

	pButton->SetParentWnd(FromHandle(hPageWnd));
	//pButton->SetParentWnd( CWnd::FromHandlePermanent( pWnd->GetSafeHwnd() ) );
	pButton->SetButtonTitle( (LPCTSTR)lParam );
	
	return m_buttonArray.Add( pButton );
}

LRESULT COutLookStyleView::OnTgmSetCaption(WPARAM wParam, LPARAM lParam)
{
	COutLookBar* pButton = this->GetButton((int)wParam);
	if (pButton)
	{
		pButton->SetButtonTitle((LPTSTR)lParam);
	}
	this->RecalcLayout();
	return 0;
}

LRESULT COutLookStyleView::OnActivePage(WPARAM wParam, LPARAM lParam)
{
	int iIndex = (int)wParam;
	SetActiveView(iIndex);
	IXobj* pParantNode = nullptr;
	if (m_pWndNode)
	{
		IXobjCollection* pCol = nullptr;
		m_pWndNode->get_ChildNodes(&pCol);
		CComPtr<IXobj> pNode;
		pCol->get_Item(iIndex, &pNode);
		if (pNode)
		{
			pNode->ActiveTabPage(pNode);
			m_pWndNode->get_ParentXobj(&pParantNode);
		}
	}
	RecalcLayout();
	return 0;
}

LRESULT COutLookStyleView::OnModifyPage(WPARAM wParam, LPARAM lParam)
{
	HWND hPageWnd = (HWND)wParam;
	int nViewID = (int)lParam;
	COutLookBar* pButton = GetButton(nViewID);
	CWnd* pOld = CWnd::FromHandlePermanent(hPageWnd);
	if(pOld)
	{
		pButton->SetParentWnd(pOld);
	}
	else
	{
		CWnd* pWnd = pButton->GetParentWnd();
		if(::IsWindow(pWnd->GetSafeHwnd()))
		{
			HWND hWnd = pWnd->UnsubclassWindow();
		}

		if(FromHandlePermanent(hPageWnd) == NULL)
		{
			pWnd->SubclassWindow(hPageWnd);
		}
		else
		{
			pWnd = FromHandlePermanent(hPageWnd);
		}
	}
	RecalcLayout();
	return 0;
}

void COutLookStyleView::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	RecalcLayout();
	__super::OnWindowPosChanging(lpwndpos);
}
