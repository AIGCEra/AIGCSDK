/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001
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
// Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 *******************************************************************************/

// NOTE ABOUT PRECOMPILED HEADERS:
// This file does not need to be compiled with precompiled headers (.pch).
// To disable this, go to Project | Settings | C/C++ | Precompiled Headers
// and select "Not using precompiled headers".  Be sure to do this for all
// build configurations.
//#include "stdafx.h"

#include <windows.h>
#include <tchar.h>
#include <crtdbg.h>
#include "XNamedColors.h"
#include "XString.h"
#include "XHtmlDraw.h"

#ifndef __noop
#if _MSC_VER < 1300
#define __noop ((void)0)
#endif
#endif

#undef TRACE
#define TRACE __noop

// if you want to see the TRACE output, 
// uncomment this line:
//#include "XTrace.h"

#pragma warning(disable : 4127)	// for _ASSERTE: conditional expression is constant
#pragma warning(disable : 4996)	// disable bogus deprecation warning


///////////////////////////////////////////////////////////////////////////////
//
// HTML CHARACTER ENTITIES
//
// Some common character entities - note that these will be displayed correctly
// ONLY if they are in the currently selected font
//
CXHtmlDraw::CHAR_ENTITIES CXHtmlDraw::m_aCharEntities[] = 
{
	{ (_TCHAR*)_T("&amp;"),		0,	_T('&') },		// ampersand
	{ (_TCHAR*)_T("&bull;"),		0,	_T('\x95') },	// bullet      NOT IN MS SANS SERIF
	{ (_TCHAR*)_T("&cent;"),		0,	_T('\xA2') },	// cent sign
	{ (_TCHAR*)_T("&copy;"),		0,	_T('\xA9') },	// copyright
	{ (_TCHAR*)_T("&deg;"),		0,	_T('\xB0') },	// degree sign
	{ (_TCHAR*)_T("&euro;"),		0,	_T('\x80') },	// euro sign
	{ (_TCHAR*)_T("&frac12;"),	0,	_T('\xBD') },	// fraction one half
	{ (_TCHAR*)_T("&frac14;"),	0,	_T('\xBC') },	// fraction one quarter
	{ (_TCHAR*)_T("&gt;"),		0,	_T('>') },		// greater than
	{ (_TCHAR*)_T("&iquest;"),	0,	_T('\xBF') },	// inverted question mark
	{ (_TCHAR*)_T("&lt;"),		0,	_T('<') },		// less than
	{ (_TCHAR*)_T("&micro;"),	0,	_T('\xB5') },	// micro sign
	{ (_TCHAR*)_T("&middot;"),	0,	_T('\xB7') },	// middle dot = Georgian comma
	{ (_TCHAR*)_T("&nbsp;"),		0,	_T(' ') },		// nonbreaking space
	{ (_TCHAR*)_T("&para;"),		0,	_T('\xB6') },	// pilcrow sign = paragraph sign
	{ (_TCHAR*)_T("&plusmn;"),	0,	_T('\xB1') },	// plus-minus sign
	{ (_TCHAR*)_T("&pound;"),	0,	_T('\xA3') },	// pound sign
	{ (_TCHAR*)_T("&quot;"),		0,	_T('"') },		// quotation mark
	{ (_TCHAR*)_T("&reg;"),		0,	_T('\xAE') },	// registered trademark
	{ (_TCHAR*)_T("&sect;"),		0,	_T('\xA7') },	// section sign
	{ (_TCHAR*)_T("&sup1;"),		0,	_T('\xB9') },	// superscript one
	{ (_TCHAR*)_T("&sup2;"),		0,	_T('\xB2') },	// superscript two
	{ (_TCHAR*)_T("&times;"),	0,	_T('\xD7') },	// multiplication sign
	{ (_TCHAR*)_T("&trade;"),	0,	_T('\x99') },	// trademark   NOT IN MS SANS SERIF
	{ NULL,				0,	0 }				// MUST BE LAST
};


///////////////////////////////////////////////////////////////////////////////
// ctor
CXHtmlDraw::CXHtmlDraw(UINT nMaxText /*= XHTMLDRAW_MAX_TEXT*/)
  : m_nMaxText(nMaxText),
	m_bOverAnchor(false)
{
	InitCharEntities();
}

///////////////////////////////////////////////////////////////////////////////
// dtor
CXHtmlDraw::~CXHtmlDraw()
{

}

///////////////////////////////////////////////////////////////////////////////
// Draw
int CXHtmlDraw::Draw(HDC hDC, 
					 LPCTSTR lpszText, 
					 XHTMLDRAWSTRUCT * pXHDS, 
					 BOOL bUnderlineUrl)
{
	TRACE(_T("in CXHtmlDraw::Draw:  <%s>  bUnderlineUrl=%d\n"), lpszText, bUnderlineUrl);

	static BOOL bInDraw = false;

	if (bInDraw)
		return 0;
	bInDraw = true;

	// check parameters ----------------------------------------------

	_ASSERTE(hDC);
	_ASSERTE(lpszText);
	_ASSERTE(pXHDS);
	if (!hDC || !lpszText || (lpszText[0] == _T('\0')) || !pXHDS)
	{
		bInDraw = false;
		return 0;
	}

	HWND hWnd = ::WindowFromDC(hDC);

	if (!::IsWindow(hWnd))
	{
		TRACE(_T("warn: not a window\n"));
		bInDraw = false;
		return 0;
	}

	// check if window is hidden ------------------------------------

	if (!::IsWindowVisible(hWnd))
	{
		TRACE(_T("warn: window invisible\n"));
		bInDraw = false;
		return 0;
	}

	RECT rectClip;
	int nResult = ::GetClipBox(hDC, &rectClip);

	if (nResult == NULLREGION)
	{
		//	window is covered
		TRACE(_T("warn: window is covered\n"));
		bInDraw = false;
		return 0;
	}

	// initialize for drawing ---------------------------------------

	// rectText is used to draw into the dc
	RECT rectText = pXHDS->rect;
	if ((rectText.left >=  rectText.right) || 
		(rectText.top >= rectText.bottom))
	{
		TRACE(_T("warn: bad rect\n"));
		bInDraw = false;
		return 0;
	}

	// rectDraw is the rect for the entire drawing area
	RECT rectDraw = pXHDS->rect;
	int nRectWidth  = rectDraw.right - rectDraw.left;
	int nRectHeight = rectDraw.bottom - rectDraw.top;
	int nXOffset = rectDraw.left;

	// set up for double buffering
	HDC hMemDC = CreateCompatibleDC(hDC);
	HBITMAP hBitmap = CreateCompatibleBitmap(hDC, nRectWidth, nRectHeight);
	HBITMAP hOldBitmap = (HBITMAP) SelectObject(hMemDC, hBitmap);

	if (pXHDS->bTransparent && !pXHDS->hDC)
	{
		// save a bitmap of the original drawing area, in case
		// there are links, and we need to erase the underline
		pXHDS->hDC = CreateCompatibleDC(hDC);
		pXHDS->hBitmap = CreateCompatibleBitmap(hDC, nRectWidth, nRectHeight);
		pXHDS->hOldBitmap = (HBITMAP) SelectObject(pXHDS->hDC, pXHDS->hBitmap);
		BitBlt(pXHDS->hDC, 0, 0, nRectWidth, nRectHeight,
			hDC, rectDraw.left, rectDraw.top, SRCCOPY);
		BitBlt(hMemDC, 0, 0, nRectWidth, nRectHeight,
			hDC, rectDraw.left, rectDraw.top, SRCCOPY);
	}
	else if (pXHDS->bTransparent && pXHDS->hDC)
	{
		// restore the original drawing area from saved HDC
		BitBlt(hMemDC, 0, 0, nRectWidth, nRectHeight,
			pXHDS->hDC, 0, 0, SRCCOPY);
	}

	pXHDS->rectAnchor = rectText;	// save rect in case of anchor

	// remap rectText to memory dc - left and top start at 0
	rectText.left = 0;
	rectText.top = 0;
	rectText.right = nRectWidth;
	rectText.bottom = nRectHeight;

	// create initial font ------------------------------------------

	LOGFONT lf = { 0 };
	LOGFONT prev_lf = { 0 };

	if (pXHDS->bLogFont)
	{
		TRACE(_T("using logfont\n"));
		memcpy(&lf, &pXHDS->lf, sizeof(LOGFONT));
	}
	else
	{
		HFONT hfont = (HFONT)::GetCurrentObject(hDC, OBJ_FONT);	//+++1.1
		if (hfont)
			GetObject(hfont, sizeof(LOGFONT), &lf);
		else
			GetObject(GetStockObject(SYSTEM_FONT), sizeof(LOGFONT), &lf);
	}
	memcpy(&prev_lf, &lf, sizeof(LOGFONT));

	// variable initialization --------------------------------------

	TCHAR *pszText = new TCHAR [m_nMaxText+1];
	memset(pszText, 0, (m_nMaxText+1)*sizeof(TCHAR));
	_tcsncpy(pszText, lpszText, m_nMaxText);
	TCHAR *pTextBuffer = pszText;	// save buffer address for delete

	TCHAR *pszText1 = new TCHAR [m_nMaxText+1];
	memset(pszText1, 0, (m_nMaxText+1)*sizeof(TCHAR));

	if (pXHDS->pszAnchor)
		delete [] pXHDS->pszAnchor;
	pXHDS->pszAnchor = NULL;

	pXHDS->bHasAnchor = false;
	pXHDS->bAnchorIsUnderlined = false;
	BOOL bInAnchor = false;

	int n = (int) _tcslen(pszText);		// n must be int

	int i = 0;
	int nWidth = 0;

	pXHDS->bHasAnchor = false;
	pXHDS->nRightX = 0;
	
	COLORREF crText = pXHDS->crText;
	if (crText == COLOR_NONE)
		crText = GetSysColor(COLOR_WINDOWTEXT);

	COLORREF crBackground = pXHDS->crBackground;
	if (crBackground == COLOR_NONE)
		crBackground = GetSysColor(COLOR_WINDOW);

	COLORREF crTextNew = crText;
	COLORREF crBkgndNew = crBackground;

	// if no transparency, fill entire rect with default bg color
	if (!pXHDS->bTransparent)
	{
		HBRUSH hbrush = CreateSolidBrush(crBkgndNew); 
		_ASSERTE(hbrush);
		FillRect(hMemDC, &rectText, hbrush);
		if (hbrush)
			DeleteObject(hbrush);
	}

	BOOL bBold = pXHDS->bBold;
	BOOL bItalic = pXHDS->bItalic;
	BOOL bUnderline = pXHDS->bUnderline;
	BOOL bStrikeThrough = pXHDS->bStrikeThrough;
	BOOL bSubscript = false;
	BOOL bSuperscript = false;
	int nSizeChange = 0;

	// replace character entity names in text with codes ------------

	TCHAR ent[3] = { _T('\0') };
	ent[0] = _T('\001');	// each entity name is replaced with a two-character
							// code that begins with \001

	BOOL bCharacterEntities = false;	// assume no char entities

	// we are replacing character entites with a two-character sequence,
	// so the resulting string will be shorter
	size_t buflen = _tcslen(pszText) + 100;
	TCHAR *buf = new TCHAR [buflen];
	memset(buf, 0, buflen*sizeof(TCHAR));

	for (i = 0; m_aCharEntities[i].pszName != NULL; i++)
	{
		ent[1] = m_aCharEntities[i].cCode;
		int nRep = _tcsistrrep(pszText, m_aCharEntities[i].pszName, ent, buf);
		if (nRep > 0)
		{
			bCharacterEntities = true;
			_tcscpy(pszText, buf);
		}
	}

	delete [] buf;
	buf = NULL;

	TEXTMETRIC tm = { 0 };

	n = (int) _tcslen(pszText);	// get length again after char entity substitution
	int textLen = n;

	while ((n > 0) && pszText && (pszText < (pTextBuffer + textLen)))
	{
		TRACE(_T("start while:  n=%d  pszText=<%s>\n"), n, pszText);

		///////////////////////////////////////////////////////////////////////
		if (_tcsnicmp(pszText, _T("<B>"), 3) == 0)	// check for <b> or <B>
		{
			n -= 3;
			pszText += 3;
			bBold++;// = true;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</B>"), 4) == 0)	// check for </B>
		{
			n -= 4;
			pszText += 4;
			if (bBold)
				bBold--;// = false;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<I>"), 3) == 0)	// check for <I>
		{
			n -= 3;
			pszText += 3;
			bItalic++;// = true;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</I>"), 4) == 0)	// check for </I>
		{
			n -= 4;
			pszText += 4;
			if (bItalic)
				bItalic--;// = false;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<U>"), 3) == 0)		// check for <U>
		{
			n -= 3;
			pszText += 3;
			bUnderline++;// = true;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</U>"), 4) == 0)	// check for </U>
		{
			n -= 4;
			pszText += 4;
			if (bUnderline)
				bUnderline--;// = false;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<S>"), 3) == 0)		// check for <S>
		{
			n -= 3;
			pszText += 3;
			bStrikeThrough++;// = true;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</S>"), 4) == 0)	// check for </S>
		{
			n -= 4;
			pszText += 4;
			if (bStrikeThrough)
				bStrikeThrough--;// = false;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<BIG>"), 5) == 0)	// check for <BIG>
		{
			n -= 5;
			pszText += 5;
			if (lf.lfHeight > 0)
				lf.lfHeight += 2;
			else
				lf.lfHeight -= 2;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</BIG>"), 6) == 0)	// check for </BIG>
		{
			n -= 6;
			pszText += 6;
			if (lf.lfHeight > 0)
				lf.lfHeight -= 2;
			else
				lf.lfHeight += 2;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<SMALL>"), 7) == 0)	// check for <SMALL>
		{
			n -= 7;
			pszText += 7;
			if (lf.lfHeight > 0)
				lf.lfHeight -= 2;
			else
				lf.lfHeight += 2;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</SMALL>"), 8) == 0)	// check for </SMALL>
		{
			n -= 8;
			pszText += 8;
			if (lf.lfHeight > 0)
				lf.lfHeight += 2;
			else
				lf.lfHeight -= 2;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<SUB>"), 5) == 0)	// check for <SUB>
		{
			n -= 5;
			pszText += 5;
			bSubscript++;// = true;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</SUB>"), 6) == 0)	// check for </SUB>
		{
			n -= 6;
			pszText += 6;
			if (bSubscript)
				bSubscript--;// = false;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<SUP>"), 5) == 0)	// check for <SUP>
		{
			n -= 5;
			pszText += 5;
			bSuperscript++;// = true;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</SUP>"), 6) == 0)	// check for </SUP>
		{
			n -= 6;
			pszText += 6;
			if (bSuperscript)
				bSuperscript--;// = false;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<FONT"), 5) == 0)	// check for <FONT
		{
			TRACE(_T("found font\n"));
			TCHAR *cp = _tcschr(pszText, _T('>'));
			if (cp)
			{
				TCHAR szAttributes[XHTMLDRAW_MAX_TEXT] = { 0 };
				_tcsncpy(szAttributes, &pszText[5], cp-pszText-5);
				TRACE(_T("szAttributes=<%s>\n"), szAttributes);
				size_t m = _tcslen(szAttributes);
				n -= (int) (cp - pszText + 1);
				pszText = cp + 1;

				// loop to parse FONT attributes
				while (m > 0)
				{
					// trim left whitespace
					if ((_tcslen(szAttributes) > 0) && 
						(szAttributes[0] == _T(' ')))
					{
						m--;
						_tcscpy(szAttributes, &szAttributes[1]);
						continue;
					}

					///////////////////////////////////////////////////////////
					if (_tcsnicmp(szAttributes, _T("COLOR"), 5) == 0)
					{
						TRACE(_T("found color\n"));
						TCHAR *cp2 = _tcschr(szAttributes, _T('"'));
						if (cp2)
						{
							m -= (cp2 - szAttributes) + 1;
							_tcscpy(szAttributes, cp2+1);

							cp2 = _tcschr(szAttributes, _T('"'));
							if (cp2)
							{
								*cp2 = _T('\0');
								TCHAR szColor[XHTMLDRAW_MAX_TEXT] = { _T('\0') };
								_tcsncpy(szColor, szAttributes, cp2-szAttributes+1);
								TRACE(_T("szColor=<%s>\n"), szColor);
								CXNamedColors nc(szColor);
								if (!pXHDS->bIgnoreColorTag)
									crTextNew = nc.GetRGB();
								_tcscpy(szAttributes, cp2+1);
								m = _tcslen(szAttributes);
							}
						}
						else
							break;
					}
					///////////////////////////////////////////////////////////
					else if (_tcsnicmp(szAttributes, _T("BGCOLOR"), 7) == 0)
					{
						TRACE(_T("found bgcolor\n"));
						TCHAR *cp2 = _tcschr(szAttributes, _T('"'));
						if (cp2)
						{
							m -= cp2 - szAttributes + 1;
							_tcscpy(szAttributes, cp2+1);

							cp2 = _tcschr(szAttributes, _T('"'));
							if (cp2)
							{
								*cp2 = _T('\0');
								TCHAR szBgColor[XHTMLDRAW_MAX_TEXT] = { _T('\0') };
								_tcsncpy(szBgColor, szAttributes, cp2-szAttributes+1);
								TRACE(_T("szBgColor=<%s>\n"), szBgColor);
								CXNamedColors nc(szBgColor);
								crBkgndNew = nc.GetRGB();
								_tcscpy(szAttributes,  cp2+1);
								m = _tcslen(szAttributes);
							}
						}
						else
							break;
					}
					///////////////////////////////////////////////////////////
					else if (_tcsnicmp(szAttributes, _T("FACE"), 4) == 0)
					{
						TCHAR *cp2 = _tcschr(szAttributes, _T('"'));
						if (cp2)
						{
							m -= cp2 - szAttributes + 1;
							_tcscpy(szAttributes, cp2+1);
							cp2 = _tcschr(szAttributes, _T('"'));
							if (cp2)
							{
								const int nFaceSize = sizeof(lf.lfFaceName);	// in bytes
								int nMaxFaceSize = nFaceSize / sizeof(TCHAR);	// in TCHARs
								memset(lf.lfFaceName, 0, nFaceSize);
								int nNewFaceSize = (int)(cp2 - szAttributes);	// in TCHARs
								memset(&lf.lfFaceName, 0, nFaceSize);
								_tcsncpy(lf.lfFaceName, szAttributes, 
									(nNewFaceSize > nMaxFaceSize) ? nMaxFaceSize : nNewFaceSize);
								TRACE(_T("lf.lfFaceName=<%s>\n"), lf.lfFaceName);

								m -= cp2 - szAttributes + 1;
								if (m > 0)
									_tcscpy(szAttributes, cp2+1);
								else
									szAttributes[0] = _T('\0');
								m = _tcslen(szAttributes);
							}
						}
						else
							break;
					}
					///////////////////////////////////////////////////////////
					else if (_tcsnicmp(szAttributes, _T("SIZE"), 4) == 0)
					{
						TCHAR *cp2 = _tcschr(szAttributes, _T('"'));
						if (cp2)
						{
							m -= cp2 - szAttributes + 1;
							_tcscpy(szAttributes, cp2+1);
							cp2 = _tcschr(szAttributes, _T('"'));
							if (cp2)
							{
								int nSize = _ttoi(szAttributes);
								lf.lfHeight -= nSize;
								nSizeChange = nSize;

								m -= cp2 - szAttributes + 1;
								if (m > 0)
									_tcscpy(szAttributes, cp2+1);
								else
									szAttributes[0] = _T('\0');
								m = _tcslen(szAttributes);
							}
						}
						else
							break;
					}
					else
					{
						while ((_tcslen(szAttributes) > 0) && 
							   (szAttributes[0] != _T(' ')))
						{
							m--;
							_tcscpy(szAttributes, &szAttributes[1]);
						}
					}
				}
			}
			else
			{
				TRACE(_T("ERROR no closing >\n"));
				pszText += 5;
				n -= 5;
			}
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</FONT>"), 7) == 0)	// check for </FONT>
		{
			n -= 7;
			pszText += 7;
			crTextNew = crText;
			crBkgndNew = crBackground;
			memcpy(&lf, &prev_lf, sizeof(lf));
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("<A"), 2) == 0)	// check for <A
		{
			TCHAR *cp = 0;
			if ((cp = _tcsistr(pszText, _T("HREF="))) != NULL)	// check for HREF=
			{
				cp += 5;
				if (*cp == _T('"'))
					cp += 1;
				TCHAR *cp2 = _tcschr(cp, _T('>'));
				if (cp2)
				{
					size_t len = cp2 - cp;
					if (pXHDS->pszAnchor)
						delete [] pXHDS->pszAnchor;
					pXHDS->pszAnchor = new TCHAR [len+4];
					memset(pXHDS->pszAnchor, 0, (len+4)*sizeof(TCHAR));
					_tcsncpy(pXHDS->pszAnchor, cp, len);
					size_t last = _tcslen(pXHDS->pszAnchor);
					if (last > 0)
						last--;
					if (pXHDS->pszAnchor[last] == _T('"'))
						pXHDS->pszAnchor[last] = _T('\0');
					TRACE(_T("len=%d  pXHDS->szUrl=<%s>\n"), len, pXHDS->pszAnchor);
					n -= (int) (cp2 + 1 - pszText);
					pszText = cp2 + 1;
					TRACE(_T("pszText=<%s>\n"), pszText);

					// set start X of url
					pXHDS->rectAnchor.left = rectText.left + nXOffset;
					TRACE(_T("setting pXHDS->rectAnchor.left to %d\n"), pXHDS->rectAnchor.left);

					crTextNew = pXHDS->crAnchorText; //RGB(0,0,255);	//pXHDS->crText;
					crBkgndNew = crBackground;
					memcpy(&lf, &prev_lf, sizeof(lf));

					bInAnchor = true;

					if (bUnderlineUrl)
					{
						pXHDS->bAnchorIsUnderlined = true;
						bUnderline++;
					}
				}
			}
			else
			{
				TRACE(_T("ERROR no closing >\n"));
				pszText += 2;
				n -= 2;
			}
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		else if (_tcsnicmp(pszText, _T("</A>"), 4) == 0)	// check for </A>
		{
			n -= 4;
			pszText += 4;

			if (bInAnchor)
			{
				pXHDS->rectAnchor.right = rectText.left + nXOffset;
				pXHDS->bHasAnchor = true;
				TRACE(_T("setting pXHDS->rectAnchor.right to %d\n"), pXHDS->rectAnchor.right);

				if (bUnderlineUrl)
					bUnderline--;
				crTextNew = crText;
				crBkgndNew = crBackground;
				memcpy(&lf, &prev_lf, sizeof(lf));
			}

			bInAnchor = false;
			continue;
		}
		///////////////////////////////////////////////////////////////////////
		// plain text
		else
		{
			TRACE(_T("text:  pszText=<%s>\n"), pszText);
			TCHAR *cp = _tcschr(pszText, _T('<'));
			if (cp)
			{
				// there's another tag
				_tcsncpy(pszText1, pszText, cp - pszText);
				pszText1[cp-pszText] = _T('\0');
				TRACE(_T("pszText1=<%s>\n"), pszText1);

				if (_tcslen(pszText1) <= 0)
				{
					if (_tcslen(pszText) != 0)
					{
						_tcscpy(pszText1, pszText);
						n -= 1;
					}
				}
				pszText = cp;
			}
			else
			{
				// no more html tags
				_tcscpy(pszText1, pszText);
				pszText = NULL;
			}
		}
		TRACE(_T("pszText=<%s>\n"), pszText);
		TRACE(_T("pszText1=<%s>\n"), pszText1);

		// create new font ------------------------------------------

		lf.lfWeight    = bBold ? FW_BOLD : FW_NORMAL;
		lf.lfUnderline = (BYTE) bUnderline;
		lf.lfItalic    = (BYTE) bItalic;
		lf.lfStrikeOut = (BYTE) bStrikeThrough;

		HFONT hNewFont = CreateFontIndirect(&lf);
		_ASSERTE(hNewFont);

		HFONT hOldFont = (HFONT) SelectObject(hMemDC, hNewFont);

		SetTextColor(hMemDC, crTextNew);
		if (pXHDS->crTextBackground != COLOR_NONE)
			SetBkColor(hMemDC, pXHDS->crTextBackground);
		else
			SetBkMode(hMemDC, TRANSPARENT);		// need transparency for italic fonts

		// replace char entities ------------------------------------

		size_t end = _tcslen(pszText1);
		buflen = end + 100;
		_ASSERTE(buf == NULL);
		buf = new TCHAR [buflen];
		memset(buf, 0, buflen*sizeof(TCHAR));

		_tcsncpy(buf, pszText1, buflen-1);

		ReplaceCharEntities(buf, end);

		int len = (int)_tcslen(buf);
		SIZE size;
		GetTextExtentPoint32(hMemDC, buf, len, &size);
		LONG width = size.cx;

		if ((crBkgndNew != crBackground) &&
			(pXHDS->crTextBackground == COLOR_NONE))
		{
			// changing backgrounds, so fill in with new color
			HBRUSH hbrushnew = CreateSolidBrush(crBkgndNew); 
			if (hbrushnew)
			{
				RECT rect = rectText;
				rect.right = rect.left + width + 1;
				if (bItalic)
				{
					rect.right += 1;		// italic needs a little more
					if (!IsTrueType(hMemDC))
						rect.right += 2;	// non-TTF fonts need even more
				}
				if (rect.right > rectText.right)
					rect.right = rectText.right;
				FillRect(hMemDC, &rect, hbrushnew);
				DeleteObject(hbrushnew);
			}
		}

		UINT uFormat = pXHDS->uFormat;

		if (pXHDS->bUseEllipsis)
			uFormat |= DT_END_ELLIPSIS;

		if (pXHDS->bHasAnchor)
		{
			// set rect for anchor
			RECT rectCalc = rectText;
			int nHeight = DrawText(hMemDC, buf, -1, &rectCalc, uFormat | DT_CALCRECT);
			TRACE(_T("nHeight=%d -----\n"), nHeight);
			pXHDS->rectAnchor.bottom = pXHDS->rectAnchor.top + nHeight;
		}

		RECT savedrect = rectText;

		GetTextMetrics(hMemDC, &tm);
		int nBaselineAdjust = tm.tmAscent / 2;

		if (bSubscript)
		{
			rectText.top += nBaselineAdjust;
			rectText.bottom += nBaselineAdjust;
		}
		if (bSuperscript)
		{
			rectText.top -= nBaselineAdjust;
			rectText.bottom -= nBaselineAdjust;
		}

		// draw text ------------------------------------------------

		TRACE(_T("DrawText: <%s>\n"), buf);
		DrawText(hMemDC, buf, -1, &rectText, uFormat);

		rectText = savedrect;

		nSizeChange = 0;

		if (hOldFont)
			SelectObject(hMemDC, hOldFont);
		if (hNewFont)
			DeleteObject(hNewFont);
		hNewFont = 0;
		hOldFont = 0;

		delete [] buf;
		buf = NULL;

		rectText.left += width;

		n -= (int)_tcslen(pszText1);

	}	// while

	// save the rightmost pixel position - note that rectText
	// is remapped to 0,0 for the memory dc
	pXHDS->nRightX = rectText.left + nXOffset;
	TRACE(_T("nRightX = %d =====\n"), pXHDS->nRightX);

	// end double buffering
	BitBlt(hDC, rectDraw.left, rectDraw.top, nRectWidth, nRectHeight,
		hMemDC, 0, 0, SRCCOPY);			
	
	// swap back the original bitmap
	if (hOldBitmap)
		SelectObject(hMemDC, hOldBitmap);
	if (hBitmap)
		DeleteObject(hBitmap);
	hBitmap = 0;

	DeleteDC(hMemDC);
	hMemDC = 0;

	if (pTextBuffer)
		delete [] pTextBuffer;
	pTextBuffer = 0;
	if (pszText1)
		delete [] pszText1;
	pszText1 = 0;

	bInDraw = false;

	return nWidth;
}

///////////////////////////////////////////////////////////////////////////////
// IsTrueType
BOOL CXHtmlDraw::IsTrueType(HDC hDC)
{
	BOOL rc = false;

	_ASSERTE(hDC);

	TEXTMETRIC tm;
	if (hDC && GetTextMetrics(hDC, &tm))
		rc = tm.tmPitchAndFamily & TMPF_TRUETYPE;

	return rc;
}

///////////////////////////////////////////////////////////////////////////////
// InitCharEntities
void CXHtmlDraw::InitCharEntities()
{
	for (int i = 0; m_aCharEntities[i].pszName != NULL; i++)
	{
		m_aCharEntities[i].cCode = (TCHAR) (i + 2);	// don't use 0 or 1
	}
}

///////////////////////////////////////////////////////////////////////////////
// ReplaceCharEntities
void CXHtmlDraw::ReplaceCharEntities(TCHAR * buf, size_t buflen)
{
	_ASSERTE(buf);

	if (buf)
	{
		if (_tcschr(buf, _T('\001')))
		{
			TCHAR *cp1 = buf;
			TCHAR *cp2 = buf;

			while (cp1 < (buf + buflen))
			{
				TCHAR c = *cp1++;

				if (c == _T('\0'))
					break;

				if (c == _T('\001'))	// is this a char entity?
				{
					// get next char - it is table index
					c = *cp1++;

					if (c == _T('\0'))
						break;

					c = GetCharEntity(c);
				}

				*cp2++ = c;
			}
			*cp2 = _T('\0');
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
// GetCharEntity
TCHAR CXHtmlDraw::GetCharEntity(TCHAR cCode)
{
	TCHAR c = _T(' ');

	for (int i = 0; m_aCharEntities[i].pszName != NULL; i++)
	{
		if (cCode == m_aCharEntities[i].cCode)
		{
			c = m_aCharEntities[i].cSymbol;
			break;
		}
	}

	return c;
}

///////////////////////////////////////////////////////////////////////////////
// GetPlainText
int CXHtmlDraw::GetPlainText(const TCHAR *html, 
							 TCHAR *plain, 
							 DWORD dwPlainSize)
{
	size_t nSize = 0;

	_ASSERTE(html);

	if (html)
	{
		if (plain)
			memset(plain, 0, dwPlainSize*sizeof(TCHAR));

		if (_tcschr(html, _T('<')) || _tcschr(html, _T('&')))
		{
			// there is html in this string

			// we are stripping out character entities, so the
			// resulting string will be shorter than the original
			size_t buflen = _tcslen(html) + 100;

			TCHAR *buf1 = new TCHAR [buflen];
			TCHAR *buf2 = new TCHAR [buflen];

			memset(buf1, 0, buflen*sizeof(TCHAR));
			memset(buf2, 0, buflen*sizeof(TCHAR));

			_tcsncpy(buf1, html, buflen-1);

			TCHAR ent[2] = { _T('\0') };

			// loop to remove character entities
			for (int i = 0; m_aCharEntities[i].pszName != NULL; i++)
			{
				ent[0] = m_aCharEntities[i].cSymbol;
				int nRep = _tcsistrrep(buf1, m_aCharEntities[i].pszName, ent, buf2);
				if (nRep > 0)
					_tcscpy(buf1, buf2);
			}

			TRACE(_T("after entities:  <%s>\n"), buf1);

			TCHAR *cp1 = buf1;
			TCHAR *cp2 = NULL;
			nSize = _tcslen(buf1);
			memset(buf2, 0, buflen*sizeof(TCHAR));

			while (cp1 < (buf1 + nSize))
			{
				if (!*cp1)
					break;

				// look for html tag
				cp2 = _tcschr(cp1, _T('<'));

				if (cp2)
				{
					// copy everything up to this point
					_tcsncat(buf2, cp1, cp2-cp1);
					cp1 = cp2 + 1;	// in case no >
					cp2 = _tcschr(cp1, _T('>'));
					if (cp2)
						cp1 = cp2 + 1;
				}
				else
				{
					// no more tags, just copy rest
					_tcscat(buf2, cp1);
					break;
				}
			}

			TRACE(_T("GetPlainText:  buf1=<%s>\n"), buf1);
			TRACE(_T("GetPlainText:  buf2=<%s>\n"), buf2);

			if (plain)
			{
				_tcsncpy(plain, buf2, dwPlainSize-1);
				TRACE(_T("GetPlainText:  plain=<%s>\n"), plain);
				nSize = _tcslen(plain);
			}
			else
			{
				// no output buffer, just return required size
				nSize = _tcslen(buf2);
			}

			delete [] buf1;
			delete [] buf2;
		}
		else
		{
			// no html in string, just copy to output buffer
			if (plain)
			{
				_tcsncpy(plain, html, dwPlainSize-1);
				nSize = _tcslen(plain);
			}
			else
			{
				// no output buffer, just return required size
				nSize = _tcslen(html);
			}
		}
	}

	return (int)nSize;
}

///////////////////////////////////////////////////////////////////////////////
// IsOverAnchor
BOOL CXHtmlDraw::IsOverAnchor(HWND hWnd, XHTMLDRAWSTRUCT * pXHDS)
{
	TRACE(_T("in CXHtmlDraw::IsOverAnchor\n"));

	BOOL rc = false;

	if (pXHDS && pXHDS->bHasAnchor && hWnd && ::IsWindow(hWnd))
	{
		POINT point;
		GetCursorPos(&point);
		::ScreenToClient(hWnd, &point);
		RECT rect = pXHDS->rectAnchor;
		//TRACERECT(rect);
		//TRACEPOINT(point);
		rc = ::PtInRect(&rect, point);
		if (rc)
		{
			TRACE(_T("mouse over anchor\n"));
		}
	}

	return rc;
}

