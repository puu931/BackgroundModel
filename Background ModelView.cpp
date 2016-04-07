// Background ModelView.cpp : implementation of the CBackgroundModelView class
//

#include "stdafx.h"
#include "Background Model.h"

#include "Background ModelDoc.h"
#include "Background ModelView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelView

IMPLEMENT_DYNCREATE(CBackgroundModelView, CScrollView)

BEGIN_MESSAGE_MAP(CBackgroundModelView, CScrollView)
	//{{AFX_MSG_MAP(CBackgroundModelView)
	ON_COMMAND(ID_INITIALIZATION, OnInitialization)
	ON_COMMAND(ID_FOREGROUND_DETECTION, OnForegroundDetection)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelView construction/destruction

CBackgroundModelView::CBackgroundModelView()
{
	// TODO: add construction code here
	flag = -1;
	background_image_number = 50;
	background_model_parameter.alpha = 0.6;
	background_model_parameter.beta = 1.0 / background_model_parameter.alpha;
	background_model_parameter.background_threshold = 0.7 * background_image_number;

	int i,j,k;

	for(i = 0;i < 256;i++)
		for(j = 0;j < 256;j++)
			for(k = 0;k < 256;k++)
				RGB_to_Yuv(i,j,k,&Yuv[i][j][k][0],&Yuv[i][j][k][1],&Yuv[i][j][k][2]);

	for(i = 0;i < 92;i++)
		for(j = 0;j < 140;j++)
		{
			if(i == 0 && j == 0) radius[i][j] = 0;
			else
			{
				if(i == 0) radius[i][j] = j;
				else
				{
					if(j == 0) radius[i][j] = i;
					else radius[i][j] = sqrt((pow(i,2) + pow(j,2)));
				}
			}
		}

// Threshold Setting
	for(i = 0;i < 256;i++)
	{
		if((i >= 0) && (i < 50)) background_model_parameter.deviation_threshold[i] = 4.24;
		else
		{
			if((i >= 50) && (i < 100)) background_model_parameter.deviation_threshold[i] = 4;
			else
			{
				if((i >= 100) && (i < 150)) background_model_parameter.deviation_threshold[i] = 3.24;
				else
				{
					if((i >= 150) && (i < 200)) background_model_parameter.deviation_threshold[i] = 3;
					else background_model_parameter.deviation_threshold[i] = 2.24;
				}
			}
		}
	}
}

CBackgroundModelView::~CBackgroundModelView()
{
}

BOOL CBackgroundModelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelView drawing

void CBackgroundModelView::OnDraw(CDC* pDC)
{
	CBackgroundModelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int i,j;

	switch(flag)
	{
	case -1:
		pDC->TextOut(10,10,"There is no Background Model");
		pDC->TextOut(10,25,"The system must learn a Background Model");
		break;
	case 0:
		{
			pDC->TextOut(10,10,"The Initial Background Model has existed");
		}
		break;
	case 1:
		{
			pDC->TextOut(10,10,"The result of Foreground Detection");
			for(i = 0;i < BITMAPINFOHEADER.biHeight;i++)
				for(j = 0;j < BITMAPINFOHEADER.biWidth;j++)
					pDC->SetPixel(10+j,30+i,RGB(foreground_binary_image[i][j],foreground_binary_image[i][j],foreground_binary_image[i][j]));
		}
		break;
	}

}

void CBackgroundModelView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelView printing

BOOL CBackgroundModelView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBackgroundModelView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBackgroundModelView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelView diagnostics

#ifdef _DEBUG
void CBackgroundModelView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBackgroundModelView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBackgroundModelDoc* CBackgroundModelView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBackgroundModelDoc)));
	return (CBackgroundModelDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBackgroundModelView message handlers

void CBackgroundModelView::RGB_to_Yuv(int R, int G, int B, unsigned char *Y, unsigned char *u, unsigned char *v)
{
	int yy,xx,xyz,xyzh,uv;
	/* RGB -> CIE's XYZ */
	yy = 77 * R + 150 * G + 29 * B;    /* CIE's Y * 256 */
	*Y = yy / 256;                      /* CIE's Y */ 
	if (*Y == 0)
	{
#define UGRAY	43
#define VGRAY	44
		*u = UGRAY;                    /* (UGRAY, VGRAY) is "white" */
		*v = VGRAY;
		return;
	}
	xx = 147 * R + 42 * G + 49 * B;    /* CIE's X * 256 */
	xyz = 55 * R + 50 * G + 87 * B;    /* CIE's (X + Y + Z) * 256 */
	xyzh = xyz / 2;
	xx = (xx * 100 + xyzh) / xyz;      /* CIE's x * 100 = X/(X+Y+Z) * 100 */
	yy = (yy * 100 + xyzh) / xyz;      /* CIE's y * 100 = Y/(X+Y+Z) * 100 */

	/* For all visible color,
	* XN <= x <= XM
	* YN <= y <= YM
	*/
#define XN	56
#define XM	267
#define YN	32
#define YM	284

	xx -= XN;
	if (xx < 0) xx = 0;
	else if (xx > XM - XN) xx = XM - XN;

	yy -= YN;
	if (yy < 0) yy = 0;
	else if (yy > YM - YN) yy = YM - YN;

    /* Use a table look up to convert (x,y) to Farthworth's
	* (uf,vf)
	*/
	uv = xy_to_uv[yy][xx];
	*v = uv / 256;
	*u = uv % 256;
}

void CBackgroundModelView::Initial_Background_Model()
{
	FILE *stream;
	CString ImageName;
	unsigned char R,G,B;
	int i,j,image_count;

	for(image_count = 0;image_count < background_image_number;image_count++)
	{
		ImageName.Format("%d%s",image_count,".bmp");
		if((stream=fopen(ImageName,"rb"))!=NULL)
		{
			fread(&BITMAPFILEHEADER.bfType,1,2,stream);
			if(BITMAPFILEHEADER.bfType == 'MB')    // Reverse 'BM'
			{
				fread(&BITMAPFILEHEADER.bfSize,1,4,stream);
				fread(&BITMAPFILEHEADER.bfReserved1,1,2,stream);
				fread(&BITMAPFILEHEADER.bfReserved2,1,2,stream);
				fread(&BITMAPFILEHEADER.bfOffBits,1,4,stream);

				fread(&BITMAPINFOHEADER.biSize,1,4,stream);
				fread(&BITMAPINFOHEADER.biWidth,1,4,stream);
				fread(&BITMAPINFOHEADER.biHeight,1,4,stream);
				fread(&BITMAPINFOHEADER.biPlanes,1,2,stream);
				fread(&BITMAPINFOHEADER.biBitCount,1,2,stream);
				fread(&BITMAPINFOHEADER.biCompression,1,4,stream);
				fread(&BITMAPINFOHEADER.biSizeImage,1,4,stream);
				fread(&BITMAPINFOHEADER.biXPelsPerMeter,1,4,stream);
				fread(&BITMAPINFOHEADER.biYPelsPerMeter,1,4,stream);
				fread(&BITMAPINFOHEADER.biClrUsed,1,4,stream);
				fread(&BITMAPINFOHEADER.biClrImportant,1,4,stream);

				if(BITMAPFILEHEADER.bfOffBits != 54)
				{
				}

				for(i = (BITMAPINFOHEADER.biHeight - 1);i >= 0;i--)
					for(j = 0;j < BITMAPINFOHEADER.biWidth;j++)
					{
						fread(&B,1,1,stream);
						fread(&G,1,1,stream);
						fread(&R,1,1,stream);

						background_model[image_count].Y[i][j] = Yuv[R][G][B][0];
						background_model[image_count].u[i][j] = Yuv[R][G][B][1];
						background_model[image_count].v[i][j] = Yuv[R][G][B][2];
					}
			}
			fclose(stream);
		}
	}
}

void CBackgroundModelView::OnInitialization() 
{
	// TODO: Add your command handler code here
	flag = 0;

	Initial_Background_Model();

	Invalidate();
}

void CBackgroundModelView::Foreground_Detection()
{
	FILE *stream,*stream2;
	CString ImageName;
	char BorF;
	unsigned char R,G,B,Y,u,v;
	int i,j,k,image_count,background_count,image_name;

	for(image_count = background_image_number;image_count < _number_of_images;image_count++)
	{
		ImageName.Format("%d%s",image_count,".bmp");
		if((stream=fopen(ImageName,"rb"))!=NULL)
		{
			fread(&BITMAPFILEHEADER.bfType,1,2,stream);
			if(BITMAPFILEHEADER.bfType == 'MB')    // Reverse 'BM'
			{
				fread(&BITMAPFILEHEADER.bfSize,1,4,stream);
				fread(&BITMAPFILEHEADER.bfReserved1,1,2,stream);
				fread(&BITMAPFILEHEADER.bfReserved2,1,2,stream);
				fread(&BITMAPFILEHEADER.bfOffBits,1,4,stream);

				fread(&BITMAPINFOHEADER.biSize,1,4,stream);
				fread(&BITMAPINFOHEADER.biWidth,1,4,stream);
				fread(&BITMAPINFOHEADER.biHeight,1,4,stream);
				fread(&BITMAPINFOHEADER.biPlanes,1,2,stream);
				fread(&BITMAPINFOHEADER.biBitCount,1,2,stream);
				fread(&BITMAPINFOHEADER.biCompression,1,4,stream);
				fread(&BITMAPINFOHEADER.biSizeImage,1,4,stream);
				fread(&BITMAPINFOHEADER.biXPelsPerMeter,1,4,stream);
				fread(&BITMAPINFOHEADER.biYPelsPerMeter,1,4,stream);
				fread(&BITMAPINFOHEADER.biClrUsed,1,4,stream);
				fread(&BITMAPINFOHEADER.biClrImportant,1,4,stream);

				if(BITMAPFILEHEADER.bfOffBits != 54)
				{
				}

				for(i = (BITMAPINFOHEADER.biHeight - 1);i >= 0;i--)
					for(j = 0;j < BITMAPINFOHEADER.biWidth;j++)
					{
						fread(&B,1,1,stream);
						fread(&G,1,1,stream);
						fread(&R,1,1,stream);
						
						Y = Yuv[R][G][B][0];
						u = Yuv[R][G][B][1];
						v = Yuv[R][G][B][2];

						background_count = 0;

						for(k = 0;k < background_image_number;k++)
						{
							if((background_model_parameter.alpha * (double)background_model[k].Y[i][j]) <= Y && Y <= (background_model_parameter.beta * (double)background_model[k].Y[i][j]))
							{
								if(radius[abs((int)u - (int)background_model[k].u[i][j])][abs((int)v - (int)background_model[k].v[i][j])] < background_model_parameter.deviation_threshold[Y])
									background_count++;
							}
						}

						if(background_count < background_model_parameter.background_threshold)
						{
							foreground_binary_image[i][j] = 255;
							BorF = 'F';
						}
						else
						{
							foreground_binary_image[i][j] = 0;
							BorF = 'B';
						}
					//	Update_Background_Model(BorF,R,G,st,i,j);
					}
				
				image_name = (image_count - background_image_number) + 1;

				ImageName.Format("%d%s",image_name,"FRs.bmp");
				stream2 = fopen(ImageName,"wb");
				fwrite(&BITMAPFILEHEADER.bfType,1,2,stream2);
				fwrite(&BITMAPFILEHEADER.bfSize,1,4,stream2);
				fwrite(&BITMAPFILEHEADER.bfReserved1,1,2,stream2);
				fwrite(&BITMAPFILEHEADER.bfReserved2,1,2,stream2);
				fwrite(&BITMAPFILEHEADER.bfOffBits,1,4,stream2);

				fwrite(&BITMAPINFOHEADER.biSize,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biWidth,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biHeight,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biPlanes,1,2,stream2);
				fwrite(&BITMAPINFOHEADER.biBitCount,1,2,stream2);
				fwrite(&BITMAPINFOHEADER.biCompression,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biSizeImage,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biXPelsPerMeter,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biYPelsPerMeter,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biClrUsed,1,4,stream2);
				fwrite(&BITMAPINFOHEADER.biClrImportant,1,4,stream2);

				for(i = (BITMAPINFOHEADER.biHeight - 1);i >= 0;i--)
					for(j = 0;j < BITMAPINFOHEADER.biWidth;j++)
						for(k = (BITMAPINFOHEADER.biBitCount / 8) - 1;k >= 0;k--)
							fwrite(&foreground_binary_image[i][j],1,1,stream2);
				fclose(stream2);
			}
			fclose(stream);
		}
	}
}

void CBackgroundModelView::OnForegroundDetection() 
{
	// TODO: Add your command handler code here
	flag = 1;

	Number_of_Images number_of_images;
	number_of_images.DoModal();
	_number_of_images = number_of_images.m_number_of_images;

	Foreground_Detection();

	Invalidate();
}
