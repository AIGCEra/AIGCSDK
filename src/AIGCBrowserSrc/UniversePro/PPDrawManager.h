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

#ifndef _PPDRAWMANAGER_H_
#define _PPDRAWMANAGER_H_

#define USE_SHADE

#ifdef USE_SHADE
#include "CeXDib.h"
#endif

#define PPDRAWMANAGER_SHADOW_XOFFSET	4	// 
#define PPDRAWMANAGER_SHADOW_YOFFSET	4	//
#define PPDRAWMANAGER_SHADOW_XDEPTH		7	// 
#define PPDRAWMANAGER_SHADOW_YDEPTH		7	//
#define PPDRAWMANAGER_SHADOW_COLOR		RGB(128, 128, 128)

//Image Effects
#define IMAGE_EFFECT_NONE				0x0000 //No effect
#define IMAGE_EFFECT_GRAYEN				0x0001 //An image will grayen
#define IMAGE_EFFECT_DARKEN				0x0002 //An image will darken
#define IMAGE_EFFECT_LIGHTEN			0x0004 //An image will lighten
#define IMAGE_EFFECT_MONOCHROME			0x0008 //An Image will monochrome
#define IMAGE_EFFECT_MONO_SHADOW		0x0100
#define IMAGE_EFFECT_GRADIENT_SHADOW	0x0200
#define IMAGE_EFFECT_INVERT				0x8000

#define IMAGE_EFFECT_MASK				(IMAGE_EFFECT_MONOCHROME | IMAGE_EFFECT_INVERT)
#define IMAGE_EFFECT_SHADOW				(IMAGE_EFFECT_MONO_SHADOW | IMAGE_EFFECT_GRADIENT_SHADOW)

class CPPDrawManager  
{
public:
	CPPDrawManager();
	virtual ~CPPDrawManager();

	enum {	EFFECT_SOLID = 0,
			EFFECT_HGRADIENT,
			EFFECT_VGRADIENT,
			EFFECT_HCGRADIENT,
			EFFECT_VCGRADIENT,
			EFFECT_3HGRADIENT,
			EFFECT_3VGRADIENT,
#ifdef USE_SHADE
			EFFECT_NOISE,
			EFFECT_DIAGSHADE,
			EFFECT_HSHADE,
			EFFECT_VSHADE,
			EFFECT_HBUMP,
			EFFECT_VBUMP,
			EFFECT_SOFTBUMP,
			EFFECT_HARDBUMP,
			EFFECT_METAL,
#endif

			MAX_EFFECTS
		};

	enum	{ 
			PEN_NULL = 0,
			PEN_SOLID,
			PEN_DASH,
			PEN_DOT,
			PEN_DASHDOT,
			PEN_DASHDOTDOT,
			PEN_DOUBLE,

			MAX_PEN_STYLES
			};

public:
	void  DrawLine(HDC hDC, int xStart, int yStart, int xEnd, int yEnd, COLORREF color, int nStyle = PEN_SOLID, int nSize = 1) const;
	void  DrawRectangle(HDC hDC, LPRECT lpRect, COLORREF crLight, COLORREF crDark, int nStyle = PEN_SOLID, int nSize = 1);
	void  DrawRectangle(HDC hDC, int left, int top, int right, int bottom, COLORREF crLight, COLORREF crDark, int nStyle = PEN_SOLID, int nSize = 1);
	void  GetSizeOfIcon(HICON hIcon, LPSIZE pSize) const;
	void  GetSizeOfBitmap(HBITMAP hBitmap, LPSIZE pSize) const;
	
	void  AlphaBitBlt(HDC hDestDC, int nDestX, int nDestY, DWORD dwWidth, DWORD dwHeight, HDC hSrcDC, int nSrcX, int nSrcY, int percent = 100);
	void  AlphaChannelBitBlt(HDC hDestDC, int nDestX, int nDestY, DWORD dwWidth, DWORD dwHeight, HDC hSrcDC, int nSrcX, int nSrcY);
	void  DrawShadow(HDC hDestDC, int nDestX, int nDestY, DWORD dwWidth, DWORD dwHeight, HBITMAP hMask, BOOL bGradient = false, DWORD dwDepthX = PPDRAWMANAGER_SHADOW_XOFFSET, DWORD dwDepthY = PPDRAWMANAGER_SHADOW_YOFFSET);
	void  MaskToDepth(HDC hDC, DWORD dwWidth, DWORD dwHeight, HBITMAP hMask, double * pDepth, BOOL bGradient = false, DWORD dwDepthX = PPDRAWMANAGER_SHADOW_XOFFSET, DWORD dwDepthY = PPDRAWMANAGER_SHADOW_YOFFSET);
	void  DarkenByDepth(HDC hDC, int x, int y, DWORD dwWidth, DWORD dwHeight, double * pDepth);

	void  SmoothMaskImage(const int ImageWidth, 
				    const int ImageHeight,
                    const COLORREF* const pInitImg,
			        const int KerWidth,
			        const int KerHeight,
					double* const pResImg_R = NULL);

	void GetPartialSums(const double* const pM,
					unsigned int nMRows,
					unsigned int nMCols,
					unsigned int nPartRows,
					unsigned int nPartCols,
					double* const pBuff,
					double* const pRes);
	
	void  DrawBitmap(HDC hDC, int x, int y, DWORD dwWidth, DWORD dwHeight, HBITMAP hSrcBitmap,
					BOOL bUseMask, COLORREF crMask, 
					DWORD dwEffect = IMAGE_EFFECT_NONE, 
					BOOL bShadow = false, 
					DWORD dwCxShadow = PPDRAWMANAGER_SHADOW_XOFFSET, 
					DWORD dwCyShadow = PPDRAWMANAGER_SHADOW_YOFFSET,
					DWORD dwCxDepth = PPDRAWMANAGER_SHADOW_XDEPTH, 
					DWORD dwCyDepth = PPDRAWMANAGER_SHADOW_YDEPTH,
					COLORREF clrShadow = PPDRAWMANAGER_SHADOW_COLOR);

	void  DrawIcon( HDC hDC, int x, int y, DWORD dwWidth, DWORD dwHeight, HICON hSrcIcon, 
					DWORD dwEffect = IMAGE_EFFECT_NONE, 
					BOOL bShadow = false, 
					DWORD dwCxShadow = PPDRAWMANAGER_SHADOW_XOFFSET, 
					DWORD dwCyShadow = PPDRAWMANAGER_SHADOW_YOFFSET,
					DWORD dwCxDepth = PPDRAWMANAGER_SHADOW_XDEPTH, 
					DWORD dwCyDepth = PPDRAWMANAGER_SHADOW_YDEPTH,
					COLORREF clrShadow = PPDRAWMANAGER_SHADOW_COLOR);

	void  DrawImageList(HDC hDC, int x, int y, DWORD dwWidth, DWORD dwHeight, HBITMAP hSrcBitmap,
					int nIndex, int cx, int cy,
					BOOL bUseMask, COLORREF crMask, 
					DWORD dwEffect = IMAGE_EFFECT_NONE, 
					BOOL bShadow = false, 
					DWORD dwCxShadow = PPDRAWMANAGER_SHADOW_XOFFSET, 
					DWORD dwCyShadow = PPDRAWMANAGER_SHADOW_YOFFSET,
					DWORD dwCxDepth = PPDRAWMANAGER_SHADOW_XDEPTH, 
					DWORD dwCyDepth = PPDRAWMANAGER_SHADOW_YDEPTH,
					COLORREF clrShadow = PPDRAWMANAGER_SHADOW_COLOR);

	HBITMAP CreateImageEffect(HBITMAP hBitmap, DWORD dwWidth, DWORD dwHeight, DWORD dwEffect, BOOL bUseMask = true, COLORREF clrMask = RGB(255, 0, 255), COLORREF clrMono = RGB(255, 255, 255));

	COLORREF GrayMirrorColor(COLORREF clrColor);
	COLORREF GrayColor(COLORREF clrColor);
	COLORREF DarkenColor(COLORREF clrColor, double darken);
	COLORREF LightenColor(COLORREF clrColor, double lighten);
	COLORREF InvertColor(COLORREF clrColor);
	COLORREF PixelAlpha (COLORREF clrSrc, double src_darken, COLORREF clrDest, double dest_darken);
	
	HICON StretchIcon(HICON hIcon, DWORD dwWidth, DWORD dwHeight);

	void FillEffect(HDC hDC, DWORD dwEffect, LPCRECT lpRect, COLORREF clrBegin, COLORREF clrMid = 0, COLORREF clrEnd = 0,  BYTE granularity = 0, BYTE coloring = 0);
	void FillGradient(HDC hDC, LPCRECT lpRect, COLORREF colorStart, COLORREF colorFinish, BOOL bHorz = true);
	void MultipleCopy(HDC hDestDC, int nDestX, int nDestY, DWORD dwDestWidth, DWORD dwDestHeight, HDC hSrcDC, int nSrcX, int nSrcY, DWORD dwSrcWidth, DWORD dwSrcHeight);
#ifdef USE_SHADE
	void SetShade(LPCRECT lpRect, UINT shadeID = 0, BYTE granularity = 8, BYTE coloring = 0, COLORREF hicr = 0, COLORREF midcr = 0, COLORREF locr = 0);
	CCeXDib m_dNormal/*,m_dh,m_dv*/;
#endif

	static short GetVersionI()		{return 0x13;}
//	static LPCTSTR GetVersionC()	{return (LPCTSTR)_T("1.3");}

protected:
	BOOL m_bIsAlpha;
};

#endif //_PPDRAWMANAGER_H_
