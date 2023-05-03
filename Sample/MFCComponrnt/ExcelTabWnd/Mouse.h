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
#pragma once
#define _MOUSE_HDR_INCLUDED_

//***************************************************************************
// class to represent global mouse object.
//***************************************************************************
class CMouse 
{
public:

	CWnd*	 Capture();			
	CWnd*	 Capture(CWnd *w);
	void	 Release();
	CPoint	 GetPos();
	operator CPoint();
};

extern CMouse Mouse;

inline CWnd* CMouse::Capture( void )
{ 
	return CWnd::GetCapture(); 
}

inline CWnd* CMouse::Capture( CWnd *w )	
{ 
	return w->SetCapture(); 
}

inline void CMouse::Release( void )
{ 
	ReleaseCapture(); 
}

inline CPoint CMouse::GetPos( void )
{ 
	CPoint p; 
	::GetCursorPos(&p); 
	return p; 
}

inline CMouse::operator CPoint( void )
{ 
	return GetPos(); 
}
