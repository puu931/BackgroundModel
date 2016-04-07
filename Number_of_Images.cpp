// Number_of_Images.cpp : implementation file
//

#include "stdafx.h"
#include "Background Model.h"
#include "Number_of_Images.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Number_of_Images dialog


Number_of_Images::Number_of_Images(CWnd* pParent /*=NULL*/)
	: CDialog(Number_of_Images::IDD, pParent)
{
	//{{AFX_DATA_INIT(Number_of_Images)
	m_number_of_images = 51;
	//}}AFX_DATA_INIT
}


void Number_of_Images::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Number_of_Images)
	DDX_Text(pDX, IDC_NUMBER_OF_IMAGES, m_number_of_images);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Number_of_Images, CDialog)
	//{{AFX_MSG_MAP(Number_of_Images)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Number_of_Images message handlers

void Number_of_Images::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CDialog::OnOK();
}
