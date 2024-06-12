/********************************************************************************
*		 			Tangram Library - version 10.0.0							*
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
#include "Stdafx.h"
#include "Cursor.h"
#include "dllmain.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//***************************************************************************
//
//***************************************************************************
BOOL LoadHandCursor( HCURSOR& hCursor )
{
	BOOL bResult = false;

    // Get the windows directory
 //   CString strWndDir;
 //   GetWindowsDirectory( strWndDir.GetBuffer(MAX_PATH), MAX_PATH );
	//strWndDir.ReleaseBuffer();

 //   strWndDir += _T("\\winhlp32.exe");

    // This retrieves cursor #106 from winhlp32.exe, which is a hand pointer
	HMODULE hModule = theApp.m_hInstance;//LoadLibrary(strWndDir);

    if( hModule ) 
	{
        HCURSOR hHandCursor = ::LoadCursor( hModule, MAKEINTRESOURCE(IDC_CURSOR_HAND2) );

        if (hHandCursor)
		{
            hCursor = CopyCursor(hHandCursor);
			bResult = true;
		}
    }

    //FreeLibrary(hModule);

	return bResult;
}
