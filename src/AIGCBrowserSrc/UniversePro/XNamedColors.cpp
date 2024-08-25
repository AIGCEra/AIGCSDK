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

// NOTE ABOUT PRECOMPILED HEADERS:
// This file does not need to be compiled with precompiled headers (.pch).
// To disable this, go to Project | Settings | C/C++ | Precompiled Headers
// and select "Not using precompiled headers".  Be sure to do this for all
// build configurations.
//#include "stdafx.h"

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <crtdbg.h>
#include "XNamedColors.h"

#pragma warning(disable : 4127)	// conditional expression is constant (_ASSERTE)
#pragma warning(disable : 4996)	// disable bogus deprecation warning


///////////////////////////////////////////////////////////////////////////////
// array of colors and names
const CXNamedColors::COLORNAMES CXNamedColors::m_aColorNames[] = 
{
	// named HTML colors
	{ colorAliceBlue,				(_TCHAR*)_T("AliceBlue") },
	{ colorAntiqueWhite,			(_TCHAR*)_T("AntiqueWhite") },
	{ colorAqua,					(_TCHAR*)_T("Aqua") },
	{ colorAquamarine,				(_TCHAR*)_T("Aquamarine") },
	{ colorAzure,					(_TCHAR*)_T("Azure") },
	{ colorBeige,					(_TCHAR*)_T("Beige") },
	{ colorBisque,					(_TCHAR*)_T("Bisque") },
	{ colorBlack,					(_TCHAR*)_T("Black") },
	{ colorBlanchedAlmond,			(_TCHAR*)_T("BlanchedAlmond") },
	{ colorBlue,					(_TCHAR*)_T("Blue") },
	{ colorBlueViolet,				(_TCHAR*)_T("BlueViolet") },
	{ colorBrown,					(_TCHAR*)_T("Brown") },
	{ colorBurlywood,				(_TCHAR*)_T("Burlywood") },
	{ colorCadetBlue,				(_TCHAR*)_T("CadetBlue") },
	{ colorChartreuse,				(_TCHAR*)_T("Chartreuse") },
	{ colorChocolate,				(_TCHAR*)_T("Chocolate") },
	{ colorCoral,					(_TCHAR*)_T("Coral") },
	{ colorCornflowerBlue,			(_TCHAR*)_T("CornflowerBlue") },
	{ colorCornsilk,				(_TCHAR*)_T("Cornsilk") },
	{ colorCrimson,					(_TCHAR*)_T("Crimson") },
	{ colorCyan,					(_TCHAR*)_T("Cyan") },
	{ colorDarkBlue,				(_TCHAR*)_T("DarkBlue") },
	{ colorDarkCyan,				(_TCHAR*)_T("DarkCyan") },
	{ colorDarkGoldenRod,			(_TCHAR*)_T("DarkGoldenRod") },
	{ colorDarkGray,				(_TCHAR*)_T("DarkGray") },
	{ colorDarkGreen,				(_TCHAR*)_T("DarkGreen") },
	{ colorDarkKhaki,				(_TCHAR*)_T("DarkKhaki") },
	{ colorDarkMagenta,				(_TCHAR*)_T("DarkMagenta") },
	{ colorDarkOliveGreen,			(_TCHAR*)_T("DarkOliveGreen") },
	{ colorDarkOrange,				(_TCHAR*)_T("DarkOrange") },
	{ colorDarkOrchid,				(_TCHAR*)_T("DarkOrchid") },
	{ colorDarkRed,					(_TCHAR*)_T("DarkRed") },
	{ colorDarkSalmon,				(_TCHAR*)_T("DarkSalmon") },
	{ colorDarkSeaGreen,			(_TCHAR*)_T("DarkSeaGreen") },
	{ colorDarkSlateBlue,			(_TCHAR*)_T("DarkSlateBlue") },
	{ colorDarkSlateGray,			(_TCHAR*)_T("DarkSlateGray") },
	{ colorDarkTurquoise,			(_TCHAR*)_T("DarkTurquoise") },
	{ colorDarkViolet,				(_TCHAR*)_T("DarkViolet") },
	{ colorDeepPink,				(_TCHAR*)_T("DeepPink") },
	{ colorDeepSkyBlue,				(_TCHAR*)_T("DeepSkyBlue") },
	{ colorDimGray,					(_TCHAR*)_T("DimGray") },
	{ colorDodgerBlue,				(_TCHAR*)_T("DodgerBlue") },
	{ colorFireBrick,				(_TCHAR*)_T("FireBrick") },
	{ colorFloralWhite,				(_TCHAR*)_T("FloralWhite") },
	{ colorForestGreen,				(_TCHAR*)_T("ForestGreen") },
	{ colorFuchsia,					(_TCHAR*)_T("Fuchsia") },
	{ colorGainsboro,				(_TCHAR*)_T("Gainsboro") },
	{ colorGhostWhite,				(_TCHAR*)_T("GhostWhite") },
	{ colorGold,					(_TCHAR*)_T("Gold") },
	{ colorGoldenRod,				(_TCHAR*)_T("GoldenRod") },
	{ colorGray,					(_TCHAR*)_T("Gray") },
	{ colorGreen,					(_TCHAR*)_T("Green") },
	{ colorGreenYellow,				(_TCHAR*)_T("GreenYellow") },
	{ colorHoneyDew,				(_TCHAR*)_T("HoneyDew") },
	{ colorHotPink,					(_TCHAR*)_T("HotPink") },
	{ colorIndianRed,				(_TCHAR*)_T("IndianRed") },
	{ colorIndigo,					(_TCHAR*)_T("Indigo") },
	{ colorIvory,					(_TCHAR*)_T("Ivory") },
	{ colorKhaki,					(_TCHAR*)_T("Khaki") },
	{ colorLavender,				(_TCHAR*)_T("Lavender") },
	{ colorLavenderBlush,			(_TCHAR*)_T("LavenderBlush") },
	{ colorLawngreen,				(_TCHAR*)_T("Lawngreen") },
	{ colorLemonChiffon,			(_TCHAR*)_T("LemonChiffon") },
	{ colorLightBlue,				(_TCHAR*)_T("LightBlue") },
	{ colorLightCoral,				(_TCHAR*)_T("LightCoral") },
	{ colorLightCyan,				(_TCHAR*)_T("LightCyan") },
	{ colorLightGoldenRodYellow,	(_TCHAR*)_T("LightGoldenRodYellow")},
	{ colorLightGreen,				(_TCHAR*)_T("LightGreen") },
	{ colorLightGrey,				(_TCHAR*)_T("LightGrey") },
	{ colorLightPink,				(_TCHAR*)_T("LightPink") },
	{ colorLightSalmon,				(_TCHAR*)_T("LightSalmon") },
	{ colorLightSeaGreen,			(_TCHAR*)_T("LightSeaGreen") },
	{ colorLightSkyBlue,			(_TCHAR*)_T("LightSkyBlue") },
	{ colorLightSlateGray,			(_TCHAR*)_T("LightSlateGray") },
	{ colorLightSteelBlue,			(_TCHAR*)_T("LightSteelBlue") },
	{ colorLightYellow,				(_TCHAR*)_T("LightYellow") },
	{ colorLime,					(_TCHAR*)_T("Lime") },
	{ colorLimeGreen,				(_TCHAR*)_T("LimeGreen") },
	{ colorLinen,					(_TCHAR*)_T("Linen") },
	{ colorMagenta,					(_TCHAR*)_T("Magenta") },
	{ colorMaroon,					(_TCHAR*)_T("Maroon") },
	{ colorMediumAquamarine,		(_TCHAR*)_T("MediumAquamarine") },
	{ colorMediumBlue,				(_TCHAR*)_T("MediumBlue") },
	{ colorMediumOrchid,			(_TCHAR*)_T("MediumOrchid") },
	{ colorMediumPurple,			(_TCHAR*)_T("MediumPurple") },
	{ colorMediumSeaGreen,			(_TCHAR*)_T("MediumSeaGreen") },
	{ colorMediumSlateBlue,			(_TCHAR*)_T("MediumSlateBlue") },
	{ colorMediumSpringGreen,		(_TCHAR*)_T("MediumSpringGreen") },
	{ colorMediumTurquoise,			(_TCHAR*)_T("MediumTurquoise") },
	{ colorMediumVioletRed,			(_TCHAR*)_T("MediumVioletRed") },
	{ colorMidnightBlue,			(_TCHAR*)_T("MidnightBlue") },
	{ colorMintCream,				(_TCHAR*)_T("MintCream") },
	{ colorMistyRose,				(_TCHAR*)_T("MistyRose") },
	{ colorMoccasin,				(_TCHAR*)_T("Moccasin") },
	{ colorNavajoWhite,				(_TCHAR*)_T("NavajoWhite") },
	{ colorNavy,					(_TCHAR*)_T("Navy") },
	{ colorOldLace,					(_TCHAR*)_T("OldLace") },
	{ colorOlive,					(_TCHAR*)_T("Olive") },
	{ colorOliveDrab,				(_TCHAR*)_T("OliveDrab") },
	{ colorOrange,					(_TCHAR*)_T("Orange") },
	{ colorOrangeRed,				(_TCHAR*)_T("OrangeRed") },
	{ colorOrchid,					(_TCHAR*)_T("Orchid") },
	{ colorPaleGoldenRod,			(_TCHAR*)_T("PaleGoldenRod") },
	{ colorPaleGreen,				(_TCHAR*)_T("PaleGreen") },
	{ colorPaleTurquoise,			(_TCHAR*)_T("PaleTurquoise") },
	{ colorPaleVioletRed,			(_TCHAR*)_T("PaleVioletRed") },
	{ colorPapayaWhip,				(_TCHAR*)_T("PapayaWhip") },
	{ colorPeachPuff,				(_TCHAR*)_T("PeachPuff") },
	{ colorPeru,					(_TCHAR*)_T("Peru") },
	{ colorPink,					(_TCHAR*)_T("Pink") },
	{ colorPlum,					(_TCHAR*)_T("Plum") },
	{ colorPowderBlue,				(_TCHAR*)_T("PowderBlue") },
	{ colorPurple,					(_TCHAR*)_T("Purple") },
	{ colorRed,						(_TCHAR*)_T("Red") },
	{ colorRosyBrown,				(_TCHAR*)_T("RosyBrown") },
	{ colorRoyalBlue,				(_TCHAR*)_T("RoyalBlue") },
	{ colorSaddleBrown,				(_TCHAR*)_T("SaddleBrown") },
	{ colorSalmon,					(_TCHAR*)_T("Salmon") },
	{ colorSandyBrown,				(_TCHAR*)_T("SandyBrown") },
	{ colorSeaGreen,				(_TCHAR*)_T("SeaGreen") },
	{ colorSeaShell,				(_TCHAR*)_T("SeaShell") },
	{ colorSienna,					(_TCHAR*)_T("Sienna") },
	{ colorSilver,					(_TCHAR*)_T("Silver") },
	{ colorSkyBlue,					(_TCHAR*)_T("SkyBlue") },
	{ colorSlateBlue,				(_TCHAR*)_T("SlateBlue") },
	{ colorSlateGray,				(_TCHAR*)_T("SlateGray") },
	{ colorSnow,					(_TCHAR*)_T("Snow") },
	{ colorSpringGreen,				(_TCHAR*)_T("SpringGreen") },
	{ colorSteelBlue,				(_TCHAR*)_T("SteelBlue") },
	{ colorTan,						(_TCHAR*)_T("Tan") },
	{ colorTeal,					(_TCHAR*)_T("Teal") },
	{ colorThistle,					(_TCHAR*)_T("Thistle") },
	{ colorTomato,					(_TCHAR*)_T("Tomato") },
	{ colorTurquoise,				(_TCHAR*)_T("Turquoise") },
	{ colorViolet,					(_TCHAR*)_T("Violet") },
	{ colorWheat,					(_TCHAR*)_T("Wheat") },
	{ colorWhite,					(_TCHAR*)_T("White") },
	{ colorWhiteSmoke,				(_TCHAR*)_T("WhiteSmoke") },
	{ colorYellow,					(_TCHAR*)_T("Yellow") },
	{ colorYellowGreen,				(_TCHAR*)_T("YellowGreen") },

	// Windows system colors
	{ colorActiveBorder,			(_TCHAR*)_T("ActiveBorder") },
	{ colorActiveCaption,			(_TCHAR*)_T("ActiveCaption") },
	{ colorActiveCaptionText,		(_TCHAR*)_T("ActiveCaptionText") },
	{ colorAppWorkspace,			(_TCHAR*)_T("AppWorkspace") },
	{ colorBackground,				(_TCHAR*)_T("Background") },
	{ colorBtnFace,					(_TCHAR*)_T("BtnFace") },
	{ colorBtnHighlight,			(_TCHAR*)_T("BtnHighlight") },
	{ colorBtnHilight,				(_TCHAR*)_T("BtnHilight") },
	{ colorBtnShadow,				(_TCHAR*)_T("BtnShadow") },
	{ colorBtnText,					(_TCHAR*)_T("BtnText") },
	{ colorCaptionText,				(_TCHAR*)_T("CaptionText") },
	{ colorControl,					(_TCHAR*)_T("Control") },
	{ colorControlDark,				(_TCHAR*)_T("ControlDark") },
	{ colorControlDarkDark,			(_TCHAR*)_T("ControlDarkDark") },
	{ colorControlLight,			(_TCHAR*)_T("ControlLight") },
	{ colorControlLightLight,		(_TCHAR*)_T("ControlLightLight") },
	{ colorControlText,				(_TCHAR*)_T("ControlText") },
	{ colorDesktop,					(_TCHAR*)_T("Desktop") },
	{ colorGradientActiveCaption,	(_TCHAR*)_T("GradientActiveCaption") },
	{ colorGradientInactiveCaption,	(_TCHAR*)_T("GradientInactiveCaption") },
	{ colorGrayText,				(_TCHAR*)_T("GrayText") },
	{ colorHighlight,				(_TCHAR*)_T("Highlight") },
	{ colorHighlightText,			(_TCHAR*)_T("HighlightText") },
	{ colorHotLight,				(_TCHAR*)_T("HotLight") },
	{ colorHotTrack,				(_TCHAR*)_T("HotTrack") },
	{ colorInactiveBorder,			(_TCHAR*)_T("InactiveBorder") },
	{ colorInactiveCaption,			(_TCHAR*)_T("InactiveCaption") },
	{ colorInactiveCaptionText,		(_TCHAR*)_T("InactiveCaptionText") },
	{ colorInfo,					(_TCHAR*)_T("Info") },
	{ colorInfoBk,					(_TCHAR*)_T("InfoBk") },
	{ colorInfoText,				(_TCHAR*)_T("InfoText") },
	{ colorMenu,					(_TCHAR*)_T("Menu") },
	{ colorMenuBar,					(_TCHAR*)_T("MenuBar") },
	{ colorMenuHilight,				(_TCHAR*)_T("MenuHilight") },
	{ colorMenuText,				(_TCHAR*)_T("MenuText") },
	{ colorScrollBar,				(_TCHAR*)_T("ScrollBar") },
	{ colorWindow,					(_TCHAR*)_T("Window") },
	{ colorWindowFrame,				(_TCHAR*)_T("WndFrame") },
	{ colorWindowText,				(_TCHAR*)_T("WindowText") }
};

const int CXNamedColors::m_nNamedColors = 
				sizeof(CXNamedColors::m_aColorNames) / 
				sizeof(CXNamedColors::m_aColorNames[0]);

///////////////////////////////////////////////////////////////////////////////
CXNamedColors::CXNamedColors()
{
	m_Color = RGB(0,0,0);		// initialize to black
}

///////////////////////////////////////////////////////////////////////////////
// can be:  "red" or "255,0,0" or "#0000FF"
CXNamedColors::CXNamedColors(LPCTSTR lpszColor)
{
	SetColorFromString(lpszColor);
}

///////////////////////////////////////////////////////////////////////////////
CXNamedColors::CXNamedColors(COLORREF color)
{
	m_Color = color;
}

///////////////////////////////////////////////////////////////////////////////
// nSysColorIndex is one of the values used with GetSysColor()
CXNamedColors::CXNamedColors(int nSysColorIndex)
{
	SetSysColor(nSysColorIndex);
}

///////////////////////////////////////////////////////////////////////////////
CXNamedColors::~CXNamedColors()
{
}

///////////////////////////////////////////////////////////////////////////////
int CXNamedColors::GetColorIndex()
{
	int rc = -1;

	for (int i = 0; i < m_nNamedColors; i++)
	{
		if (m_Color == m_aColorNames[i].color)
		{
			rc = i;
			break;
		}
	}

	return rc;
}

///////////////////////////////////////////////////////////////////////////////
COLORREF CXNamedColors::GetColorByIndex(int index)
{
	_ASSERTE((index >= 0) && (index < m_nNamedColors));

	COLORREF rc = (DWORD)-1;

	if ((index >= 0) && (index < m_nNamedColors))
	{
		rc = m_aColorNames[index].color;
		if (rc & 0x80000000L)
			rc = GetSysColor(rc & 0x7FFFFFFFL);
	}

	return rc;
}

///////////////////////////////////////////////////////////////////////////////
void CXNamedColors::GetColorNameByIndex(int index, 
										LPTSTR lpszBuf, 
										DWORD nBufSize)
{
	_ASSERTE(lpszBuf);
	_ASSERTE(nBufSize > 0);
	_ASSERTE((index >= 0) && (index < m_nNamedColors));
	if (!lpszBuf || (nBufSize == 0))
		return;

	if ((index >= 0) && (index < m_nNamedColors))
	{
		memset(lpszBuf, 0, nBufSize*sizeof(TCHAR));
		_tcsncpy(lpszBuf, m_aColorNames[index].pszName, nBufSize-1);
	}
}

///////////////////////////////////////////////////////////////////////////////
void CXNamedColors::GetHex(LPTSTR lpszBuf, DWORD nBufSize)	// nBufSize in TCHARs
{
	_ASSERTE(lpszBuf);
	_ASSERTE(nBufSize > 0);
	if (!lpszBuf || (nBufSize == 0))
		return;

	memset(lpszBuf, 0, nBufSize*sizeof(TCHAR));

	BYTE r = GetRValue(GetRGB());
	BYTE g = GetGValue(GetRGB());
	BYTE b = GetBValue(GetRGB());

	_sntprintf(lpszBuf, nBufSize-1, _T("#%02X%02X%02X"), r, g, b);
}

///////////////////////////////////////////////////////////////////////////////
COLORREF CXNamedColors::GetRGB() 
{ 
	COLORREF rc = m_Color;
	if (IsSystemColor())
		rc = GetSysColor(m_Color & 0x7FFFFFFFL);
	return rc;
}

///////////////////////////////////////////////////////////////////////////////
void CXNamedColors::GetName(LPTSTR lpszBuf, DWORD nBufSize)	// nBufSize in TCHARs
{
	_ASSERTE(lpszBuf);
	_ASSERTE(nBufSize > 0);
	if (!lpszBuf || (nBufSize == 0))
		return;

	memset(lpszBuf, 0, nBufSize*sizeof(TCHAR));

	for (int i = 0; i < m_nNamedColors; i++)
	{
		if (m_Color == m_aColorNames[i].color)
		{
			_tcsncpy(lpszBuf, m_aColorNames[i].pszName, nBufSize-1);
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
void CXNamedColors::GetRGBString(LPTSTR lpszBuf, DWORD nBufSize) // nBufSize in TCHARs
{
	_ASSERTE(lpszBuf);
	_ASSERTE(nBufSize > 0);
	if (!lpszBuf || (nBufSize == 0))
		return;

	memset(lpszBuf, 0, nBufSize*sizeof(TCHAR));

	_sntprintf(lpszBuf, nBufSize-1, _T("%u,%u,%u"), GetR(), GetG(), GetB());
}

///////////////////////////////////////////////////////////////////////////////
// #RRGGBB
void CXNamedColors::SetHex(LPCTSTR lpszHex)
{
	_ASSERTE(lpszHex);
	if (!lpszHex)
		return;

	COLORREF rgb = RGB(0,0,0);
	LPCTSTR cp = lpszHex;

	if ((*cp == _T('#')) && (_tcslen(lpszHex) == 7))
	{
		TCHAR s[3] = { _T('\0') };
		cp++;

		s[0] = *cp++;
		s[1] = *cp++;
		BYTE r = (BYTE)_tcstoul(s, NULL, 16);

		s[0] = *cp++;
		s[1] = *cp++;
		BYTE g = (BYTE)_tcstoul(s, NULL, 16);

		s[0] = *cp++;
		s[1] = *cp++;
		BYTE b = (BYTE)_tcstoul(s, NULL, 16);

		rgb = RGB(r,g,b);
	}
	m_Color = rgb;
}

///////////////////////////////////////////////////////////////////////////////
void CXNamedColors::SetName(LPCTSTR lpszColorName)
{
	_ASSERTE(lpszColorName);
	if (!lpszColorName)
		return;

	COLORREF rgb = RGB(0,0,0);

	for (int i = 0; i < m_nNamedColors; i++)
	{
		if (_tcsicmp(lpszColorName, m_aColorNames[i].pszName) == 0)
		{
			rgb = m_aColorNames[i].color;
			break;
		}
	}
	m_Color = rgb;
}

///////////////////////////////////////////////////////////////////////////////
// lpszColor:  "red" or "255,0,0" or "#0000FF"
void CXNamedColors::SetColorFromString(LPCTSTR lpszColor)
{
	_ASSERTE(lpszColor);
	if (!lpszColor)
		return;

	m_Color = RGB(0,0,0);		// initialize to black
	BYTE r = 0;
	BYTE g = 0;
	BYTE b = 0;
	TCHAR *cp = 0;

	if ((cp = (TCHAR*)_tcschr(lpszColor, _T(','))) != NULL)
	{
		// "255,0,0"
		r = (BYTE) _ttoi(lpszColor);
		cp++;
		g = (BYTE) _ttoi(cp);
		cp = _tcschr(cp, _T(','));
		if (cp)
		{
			cp++;
			b = (BYTE) _ttoi(cp);
		}
		m_Color = RGB(r,g,b);
	}
	else if ((cp = (TCHAR*)_tcschr(lpszColor, _T('#'))) != NULL)
	{
		// "#0000FF"
		if (_tcslen(lpszColor) == 7)
		{
			TCHAR s[3] = { _T('\0') };
			cp++;
			s[0] = *cp++;
			s[1] = *cp++;
			r = (BYTE)_tcstoul(s, NULL, 16);
			s[0] = *cp++;
			s[1] = *cp++;
			g = (BYTE)_tcstoul(s, NULL, 16);
			s[0] = *cp++;
			s[1] = *cp++;
			b = (BYTE)_tcstoul(s, NULL, 16);
			m_Color = RGB(r,g,b);
		}
	}
	else
	{
		// "red"
		for (int i = 0; i < m_nNamedColors; i++)
		{
			if (_tcsicmp(lpszColor, m_aColorNames[i].pszName) == 0)
			{
				m_Color = m_aColorNames[i].color;
				break;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
void CXNamedColors::SetRGB(BYTE r, BYTE g, BYTE b) 
{ 
	m_Color = RGB(r, g, b);
}

///////////////////////////////////////////////////////////////////////////////
// nSysColorIndex is one of the values used with GetSysColor()
void CXNamedColors::SetSysColor(int nSysColorIndex)
{
	_ASSERTE((nSysColorIndex >= 0) && (nSysColorIndex <= COLOR_MENUBAR));

	if ((nSysColorIndex >= 0) && (nSysColorIndex <= COLOR_MENUBAR))
		m_Color = (DWORD) (nSysColorIndex | 0x80000000);
}

#ifdef _DEBUG
///////////////////////////////////////////////////////////////////////////////
//
// Dumps the color table in a form suitable for a HTML table, e.g.:
//
// <tr>
// <td style="background-color:#F0F8FF; color:black" align="center">AliceBlue<br>(#F0F8FF)</td>
// <td style="background-color:#FAEBD7; color:black" align="center">AntiqueWhite<br>(#FAEBD7)</td>
// <td style="background-color:#00FFFF; color:black" align="center">Aqua<br>(#00FFFF)</td>
// <td style="background-color:#7FFFD4; color:black" align="center">Aquamarine<br>(#7FFFD4)</td>
// <td style="background-color:#F0FFFF; color:black" align="center">Azure<br>(#F0FFFF)</td>
// </tr>
//
void CXNamedColors::Dump(LPCTSTR lpszFile)
{
	_ASSERTE(lpszFile);
	if (!lpszFile)
		return;

	FILE * f = _tfopen(lpszFile, _T("w"));
	if (f)
	{
		_ftprintf(f, _T("<html><body>\n"));
		_ftprintf(f, _T("<center><table bgcolor=\"gray\" border=1 cellspacing=1 cellpadding=3 summary=\"named colors\">"));

		TCHAR szBuf[100];
		for (int j = 0; j < m_nNamedColors; )
		{
			_ftprintf(f, _T("<tr>\n"));
			int cols = (j >= 140) ? 4 : 5;
			for (int k = 0; k < cols; k++)
			{
				if (m_aColorNames[j].color & 0x80000000)
				{
					DWORD index = m_aColorNames[j].color;
					index = index & 0x7FFFFFFF;
					SetSysColor(index);
				}
				else
				{
					SetRGB(m_aColorNames[j].color);
				}
				GetHex(szBuf, 99);
				TCHAR *text = (_TCHAR*)_T("black");
				if (_tcscmp(szBuf, _T("#000000")) == 0)
					text = (_TCHAR*)_T("white");
				_ftprintf(f, 
					_T("<td style=\"background-color:%s; color:%s\" align=\"center\">%s<br>(%s)</td>\n"),
					szBuf,
					text,
					CXNamedColors::m_aColorNames[j].pszName, 
					szBuf);
				j++;
				if (j >= CXNamedColors::m_nNamedColors)
					break;
			}
			_ftprintf(f, _T("</tr>\n\n"));
		}
		_ftprintf(f, _T("</table></center></body></html>\n"));
		fclose(f);
	}
}
#endif
