#if !defined(AFX_HOURGLASSFX_H__C53DB5BF_841A_44D4_8C41_062A9CFDD449__INCLUDED_)
#define AFX_HOURGLASSFX_H__C53DB5BF_841A_44D4_8C41_062A9CFDD449__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HourglassFX.h : header file
//
/////////////////////////////////////////////////////////////////////////////
//
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

/////////////////////////////////////////////////////////////////////////////
// CHourglassFX window

template <class BASE_TYPE>
class CHourglassFX : public BASE_TYPE
{
private:
	enum { ANICURSOR_FRAMES = 10 };

	HBRUSH m_hBrush;
	CRect m_rcIcon;
	int m_iAniStep;
	HCURSOR m_hAniCur;

// Construction-Destruction
public:
	CHourglassFX()
	{
		BASE_TYPE::ShowWaitMessage();
		BASE_TYPE::SetAnimationDelay(125);

		//m_hAniCur = AfxGetApp()->LoadCursor(IDR_HOURGLASS);
	};

	virtual ~CHourglassFX()
	{
		DestroyCursor(m_hAniCur);
	};

// Implementation
protected:
	virtual void PreAnimation(HTREEITEM hItemMsg);
	virtual void DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep);
	virtual void PostAnimation();
};

/////////////////////////////////////////////////////////////////////////////
// CHourglassFX

template <class BASE_TYPE>
void CHourglassFX<BASE_TYPE>::PreAnimation(HTREEITEM hItemMsg)
{
	BASE_TYPE::PreAnimation(hItemMsg);

	m_iAniStep = 0;

	// get msg image rect
	BASE_TYPE::GetItemImageRect(hItemMsg, &m_rcIcon);

	// create background brush with current bg color (take rgb part only)
	m_hBrush = CreateSolidBrush(::GetBkColor(NULL) & 0x00FFFFFF);
}

template <class BASE_TYPE>
void CHourglassFX<BASE_TYPE>::PostAnimation()
{
	DeleteObject(m_hBrush);

	BASE_TYPE::PostAnimation();
}

template <class BASE_TYPE>
void CHourglassFX<BASE_TYPE>::DoAnimation(BOOL bTimerEvent, int iMaxSteps, int iStep)
{
	BASE_TYPE::DoAnimation(bTimerEvent, iMaxSteps, iStep);

	if (!bTimerEvent) return;	// process only timer events

	m_iAniStep = (m_iAniStep + 1) % ANICURSOR_FRAMES;

	CClientDC dc(this);

	DrawIconEx(dc.GetSafeHdc(), m_rcIcon.left, m_rcIcon.top, m_hAniCur,
		m_rcIcon.Width(), m_rcIcon.Height(), m_iAniStep, m_hBrush, DI_NORMAL);
}


#endif // !defined(AFX_HOURGLASSFX_H__C53DB5BF_841A_44D4_8C41_062A9CFDD449__INCLUDED_)
