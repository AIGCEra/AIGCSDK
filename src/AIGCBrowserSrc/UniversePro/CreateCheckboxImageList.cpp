/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001           *
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web pages,
 *    which are composed of standard DOM elements and binary components supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet based
 *    on modern javscript/Web technology.
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

 // CreateCheckboxImageList.cpp  Version 1.0
//
// Author:  Hans Dietrich
//          hdietrich@gmail.com
//
// History
//     Version 1.0 - 2007 July 15
//     - Initial public release
//
// License:
//     This software is released into the public domain.  You are free to use
//     it in any way you like, except that you may not sell this source code.
//
//     This software is provided "as is" with no expressed or implied warranty.
//     I accept no liability for any damage or loss of business that this 
//     software may cause.
// 
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CreateCheckboxImageList.h"
#include "visualstylesxp.h"

namespace HDCheckboxImageList
{

///////////////////////////////////////////////////////////////////////////////
//
// CreateCheckboxImageList()
//
// Purpose:     Create themed checkbox image list
//
// Parameters:  pDC          - pointer to device context for drawing
//              imagelist    - image list to create
//              nSize        - height and width of images
//              crBackground - fill color
//
// Returns:     BOOL         - true if image list created OK
//
BOOL CreateCheckboxImageList(CDC *pDC, 
							 CImageList& imagelist, 
							 int nSize, 
							 COLORREF crBackground)
{
	ASSERT(pDC);
	ASSERT(nSize > 0);

	BOOL rc = false;

	///////////////////////////////////////////////////////////////////////////
	//
	// CHECKBOX IMAGES
	//
	// From MSDN:  "To indicate that the item has no state image, set the
	//             index to zero. This convention means that image zero in 
	//             the state image list cannot be used as a state image."
	//
	// Note that comparable hot image = cold image index OR 8.
	// Disabled state = index OR 4.
	
	struct CHECKBOXDRAWDATA
	{
		TCHAR * pszDesc;	// description for debugging
		int nStateId;		// for DrawThemeBackground
		UINT nState;		// for DrawFrameControl
	} 
	cbdd[] =
	{
		// cold -----------------------------------------------------------------------------------
/*0000*/(_TCHAR*)_T("unused"),				0,						0,
/*0001*/(_TCHAR*)_T("unchecked normal"),		CBS_UNCHECKEDNORMAL,	DFCS_BUTTONCHECK | DFCS_FLAT,
/*0010*/(_TCHAR*)_T("checked normal"),		CBS_CHECKEDNORMAL,		DFCS_BUTTONCHECK | DFCS_CHECKED | DFCS_FLAT,
/*0011*/(_TCHAR*)_T("tri-state normal"),		CBS_MIXEDNORMAL,		DFCS_BUTTON3STATE | DFCS_CHECKED | DFCS_FLAT,
/*0100*/(_TCHAR*)_T("unused"),				0,						0,
/*0101*/(_TCHAR*)_T("unchecked disabled"),	CBS_UNCHECKEDDISABLED,	DFCS_BUTTONCHECK | DFCS_INACTIVE | DFCS_FLAT,
/*0110*/(_TCHAR*)_T("checked disabled"),		CBS_CHECKEDDISABLED,	DFCS_BUTTONCHECK | DFCS_CHECKED | DFCS_INACTIVE | DFCS_FLAT,
/*0111*/(_TCHAR*)_T("tri-state disabled"),	CBS_MIXEDDISABLED,		DFCS_BUTTON3STATE | DFCS_CHECKED | DFCS_INACTIVE | DFCS_FLAT,

		// hot ------------------------------------------------------------------------------------
/*1000*/(_TCHAR*)_T("unused"),				0,						0,
/*1001*/(_TCHAR*)_T("unchecked normal"),		CBS_UNCHECKEDHOT,		DFCS_BUTTONCHECK | DFCS_FLAT,
/*1010*/(_TCHAR*)_T("checked normal"),		CBS_CHECKEDHOT,			DFCS_BUTTONCHECK | DFCS_CHECKED | DFCS_FLAT,
/*1011*/(_TCHAR*)_T("tri-state normal"),		CBS_MIXEDHOT,			DFCS_BUTTON3STATE | DFCS_CHECKED | DFCS_FLAT,
/*1100*/(_TCHAR*)_T("unused"),				0,						0,
/*1101*/(_TCHAR*)_T("unchecked disabled"),	CBS_UNCHECKEDDISABLED,	DFCS_BUTTONCHECK | DFCS_INACTIVE | DFCS_FLAT,
/*1110*/(_TCHAR*)_T("checked disabled"),		CBS_CHECKEDDISABLED,	DFCS_BUTTONCHECK | DFCS_CHECKED | DFCS_INACTIVE | DFCS_FLAT,
/*1111*/(_TCHAR*)_T("tri-state disabled"),	CBS_MIXEDDISABLED,		DFCS_BUTTON3STATE | DFCS_CHECKED | DFCS_INACTIVE | DFCS_FLAT,

		NULL, 0, 0		// last entry
	};

	if (pDC && (nSize > 0))
	{
		const int nBmpWidth = nSize;
		const int nBmpHeight = nSize;
		const int nImages = sizeof(cbdd)/sizeof(cbdd[0]);
		ASSERT(nImages == 17);

		if (imagelist.GetSafeHandle())
			imagelist.DeleteImageList();

		CBitmap bmpCheckboxes;

		if (bmpCheckboxes.CreateCompatibleBitmap(pDC, nBmpWidth * nImages, 
				nBmpHeight))
		{
			if (imagelist.Create(nBmpWidth, nBmpHeight, ILC_COLOR32 | ILC_MASK, 
					nImages, 1))
			{
				CDC dcMem;
				if (dcMem.CreateCompatibleDC(pDC))
				{
					HTHEME hTheme = NULL;
					hTheme = (g_xpStyle.IsThemeActive() && 
							  g_xpStyle.IsAppThemed()) ? 
							  g_xpStyle.OpenThemeData(NULL, L"BUTTON") : NULL;
					CBitmap* pOldBmp = dcMem.SelectObject(&bmpCheckboxes);
					dcMem.FillSolidRect(0, 0, nBmpWidth*nImages, nBmpHeight, 
						crBackground);

					int nImageWidth  = nBmpWidth - 2;		// allow 2 for border
					int nImageHeight = nBmpHeight - 2;
					int nImageLeft   = (nBmpWidth - nImageWidth) / 2;
					int nImageTop    = (nBmpHeight - nImageHeight) / 2;

					CRect rectImage(nImageLeft, 
									nImageTop, 
									nImageLeft+nImageWidth, 
									nImageTop+nImageHeight);

					for (int i = 0; cbdd[i].pszDesc != NULL; i++)
					{
						if (_tcscmp(cbdd[i].pszDesc, _T("unused")) == 0)
						{
							// unused image slot
							// note that we skip the first image - they are 1-based
						}
						else
						{
							if (hTheme)
							{
								g_xpStyle.DrawThemeBackground(hTheme, dcMem, 
									BP_CHECKBOX, cbdd[i].nStateId, &rectImage, 
									NULL);
								g_xpStyle.DrawThemeEdge(hTheme, dcMem, 
									BP_CHECKBOX, cbdd[i].nStateId, &rectImage, 0, 0, 
									NULL);
							}
							else
							{
								dcMem.DrawFrameControl(&rectImage, DFC_BUTTON, 
									cbdd[i].nState);
							}
						}

						rectImage.left  += nBmpWidth;
						rectImage.right += nBmpWidth;
					}

					if (hTheme)
					{
						g_xpStyle.CloseThemeData(hTheme);
						hTheme = NULL;
					}

					dcMem.SelectObject(pOldBmp);
					imagelist.Add(&bmpCheckboxes, RGB(255,0,255));
					if (hTheme)
						g_xpStyle.CloseThemeData(hTheme);

					rc = true;
				}
				else
				{
					TRACE(_T("ERROR - failed to create DC\n"));
				}
			}
			else
			{
				TRACE(_T("ERROR - failed to create image list\n"));
			}
		}
		else
		{
			TRACE(_T("ERROR - failed to create bitmap\n"));
		}
	}
	else
	{
		TRACE(_T("ERROR - bad parameters\n"));
	}
	return rc;
}

}	// namespace