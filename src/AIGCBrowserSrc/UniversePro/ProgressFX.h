#if !defined(AFX_PROGRESSFX_H__3A32359E_4128_426B_AB73_1D74DA101DAA__INCLUDED_)
#define AFX_PROGRESSFX_H__3A32359E_4128_426B_AB73_1D74DA101DAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202108220001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web pages,
 *    which are composed of standard DOM elements and binary components supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet based
 *    on modern javscript/Web technology.
// Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 *******************************************************************************/

#include <math.h>

 /////////////////////////////////////////////////////////////////////////////
 // CProgressFX window

template <class BASE_TYPE>
class CProgressFX : public BASE_TYPE
{
private:
	enum {
		BORDER_SIZE = 3, PROGRESS_HEIGHT = 16,
		PROGRESS_SIZE = 50, STEP_SIZE = 10
	};

	CRect m_rcBorder;
	CRect m_rcProg;
	HBRUSH m_hBorderBrush;
	HBRUSH m_hFillBrush;

	// Construction
public:
	CProgressFX()
	{
		BASE_TYPE::ShowWaitMessage();
	};

	// Attributes
public:

	// Operations
public:

	// Implementation
public:
	virtual ~CProgressFX() {};

protected:
	virtual void PreAnimation(HTREEITEM hItemMsg);
	virtual void DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep);
	virtual void PostAnimation();
};

/////////////////////////////////////////////////////////////////////////////
// CProgressFX

template <class BASE_TYPE>
void CProgressFX<BASE_TYPE>::PreAnimation(HTREEITEM hItemMsg)
{
	BASE_TYPE::PreAnimation(hItemMsg);

	// get msg item rect
	BASE_TYPE::GetItemRect(hItemMsg, &m_rcBorder, TRUE);
	int margin = (m_rcBorder.Height() - PROGRESS_HEIGHT) / 2;
	margin = (margin < 0) ? 0 : margin;
	// set height
	m_rcBorder.top += margin;
	m_rcBorder.bottom -= margin;
	// calc progress rect
	m_rcBorder.OffsetRect(m_rcBorder.Width() + BORDER_SIZE, 0);
	m_rcProg = m_rcBorder;
	m_rcProg.DeflateRect(BORDER_SIZE, BORDER_SIZE);
	// set width
	m_rcProg.right = m_rcProg.left;
	m_rcBorder.right = m_rcBorder.left + BORDER_SIZE * 2 + PROGRESS_SIZE;

	// create brushes
	m_hBorderBrush = CreateSolidBrush(RGB(0, 0, 0));
	m_hFillBrush = CreateSolidBrush(RGB(255, 0, 0));
}

template <class BASE_TYPE>
void CProgressFX<BASE_TYPE>::PostAnimation()
{
	DeleteObject(m_hBorderBrush);
	DeleteObject(m_hFillBrush);

	BASE_TYPE::PostAnimation();
}

template <class BASE_TYPE>
void CProgressFX<BASE_TYPE>::DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep)
{
	BASE_TYPE::DoAnimation(bTimerEvent, iMaxSteps, iStep);

	if (bTimerEvent) return;	// process only redraw events

	CClientDC dc(this);
	FrameRect(dc.GetSafeHdc(), &m_rcBorder, m_hBorderBrush);

	if (iMaxSteps > 0)	// linear progress 
		m_rcProg.right = m_rcProg.left + iStep * static_cast<int>(PROGRESS_SIZE) / iMaxSteps;
	else	// endless progress
	{
		double x = exp((double)((2 * STEP_SIZE * (double)iStep / static_cast<int>(PROGRESS_SIZE)) - 1)); 
		double y = exp((double)2);
		m_rcProg.right = m_rcProg.left + (LONG)(static_cast<int>(PROGRESS_SIZE) * (1 + static_cast<int>(STEP_SIZE) * (double)iStep / static_cast<int>(PROGRESS_SIZE) -
			log(y + x) / 2));
	}

	FillRect(dc.GetSafeHdc(), &m_rcProg, m_hFillBrush);
}


#endif // !defined(AFX_PROGRESSFX_H__3A32359E_4128_426B_AB73_1D74DA101DAA__INCLUDED_)
