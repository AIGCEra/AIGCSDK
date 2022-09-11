
// MFCSDIApp.h : main header file for the MFCSDIApp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCSDIApp:
// See MFCSDIApp.cpp for the implementation of this class
//

class CMFCSDIApp : public CWebRTApp
{
public:
	CMFCSDIApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSDIApp theApp;
