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
#define HLPRFUNCS_H_INCLUDED_

#pragma once

struct CLogFont : public LOGFONT
{
public:
	CLogFont() { ZeroMemory( this, sizeof(LOGFONT) ); }
};

BOOL DrawVerticalText
( 
	CDC* pDC, 
	const CRect& rectWindow, 
	CString szcText, 
	const DWORD dwStyle 
);

void GradientFill
( 
	CDC* pDC, 
	const CRect& rectWindow,
	const COLORREF crFace,
	const COLORREF crShadow,
	const BOOL bHorizontal 
);

void GetWindowBitmap( CWnd* pWnd, CBitmap* bmpWindow );

BYTE TransitionColor
( 
	const BYTE bySource, 
	const BYTE byDestination, 
	const int nIndex, 
	const float nDelta 
);
