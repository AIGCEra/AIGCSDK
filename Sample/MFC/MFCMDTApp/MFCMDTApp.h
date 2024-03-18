
// MFCApplication2.h : main header file for the MFCApplication2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMDTApp:
// See MFCApplication2.cpp for the implementation of this class
//

class CMFCMDTApp
	: public CAIGCWinApp
{
public:
	CMFCMDTApp() noexcept;

protected:
	CMultiDocTemplate* m_pDocTemplate;
public:

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMDTApp theApp;
