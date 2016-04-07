// Background Model.h : main header file for the BACKGROUND MODEL application
//

#if !defined(AFX_BACKGROUNDMODEL_H__3BE1C60C_F12C_403F_8C97_B38810FC9023__INCLUDED_)
#define AFX_BACKGROUNDMODEL_H__3BE1C60C_F12C_403F_8C97_B38810FC9023__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelApp:
// See Background Model.cpp for the implementation of this class
//

class CBackgroundModelApp : public CWinApp
{
public:
	CBackgroundModelApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackgroundModelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBackgroundModelApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKGROUNDMODEL_H__3BE1C60C_F12C_403F_8C97_B38810FC9023__INCLUDED_)
