// Background ModelDoc.cpp : implementation of the CBackgroundModelDoc class
//

#include "stdafx.h"
#include "Background Model.h"

#include "Background ModelDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelDoc

IMPLEMENT_DYNCREATE(CBackgroundModelDoc, CDocument)

BEGIN_MESSAGE_MAP(CBackgroundModelDoc, CDocument)
	//{{AFX_MSG_MAP(CBackgroundModelDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelDoc construction/destruction

CBackgroundModelDoc::CBackgroundModelDoc()
{
	// TODO: add one-time construction code here

}

CBackgroundModelDoc::~CBackgroundModelDoc()
{
}

BOOL CBackgroundModelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelDoc serialization

void CBackgroundModelDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelDoc diagnostics

#ifdef _DEBUG
void CBackgroundModelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBackgroundModelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelDoc commands
