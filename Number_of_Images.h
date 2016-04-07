#if !defined(AFX_NUMBER_OF_IMAGES_H__E52EEA40_6B0B_4D0D_BA5F_BC129E7BC2C2__INCLUDED_)
#define AFX_NUMBER_OF_IMAGES_H__E52EEA40_6B0B_4D0D_BA5F_BC129E7BC2C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Number_of_Images.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Number_of_Images dialog

class Number_of_Images : public CDialog
{
// Construction
public:
	Number_of_Images(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Number_of_Images)
	enum { IDD = IDD_NUMBER_OF_IMAGES };
	int		m_number_of_images;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Number_of_Images)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Number_of_Images)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMBER_OF_IMAGES_H__E52EEA40_6B0B_4D0D_BA5F_BC129E7BC2C2__INCLUDED_)
