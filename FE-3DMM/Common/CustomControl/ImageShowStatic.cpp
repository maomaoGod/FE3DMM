// StaticDisplayImage.cpp : implementation file
//

#include "stdafx.h"
#include "ImageShowStatic.h"
#include "../../resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageShowStatic

CImageShowStatic::CImageShowStatic()
{
	m_pYellowPen = new CPen(PS_SOLID, 1, RGB(255, 255, 0));
	m_iplImage = NULL;
	m_iChangeSizeX = 30;
	m_iChangeSizeY = 30;
	m_bIsInit = true;
	m_bIsDrawTickMark = false;
}

CImageShowStatic::~CImageShowStatic()
{
	if (NULL != m_pYellowPen)
	{
		m_pYellowPen->DeleteObject();
		delete m_pYellowPen;
		m_pYellowPen = NULL;
	}
}


BEGIN_MESSAGE_MAP(CImageShowStatic, CStatic)
	//{{AFX_MSG_MAP(CImageShowStatic)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


void CImageShowStatic::OnPaint() 
{
	CPaintDC dc(this);    //对话框DC
		
	CRect rect;
	GetClientRect(rect);
	int iWinWidth, iWinHeight, iWinCenterX, iWinCenterY;
	iWinWidth = rect.right - rect.left;
	iWinHeight = rect.bottom - rect.top;
	iWinCenterX = rect.left + iWinWidth / 2;
	iWinCenterY = rect.top + iWinHeight / 2;

	if (m_bIsInit)
	{
		m_rcInitWin.left = iWinCenterX - m_iChangeSizeX;
		m_rcInitWin.right = iWinCenterX + m_iChangeSizeX;
		m_rcInitWin.bottom = iWinCenterY + m_iChangeSizeY;
		m_rcInitWin.top = iWinCenterY - m_iChangeSizeY;
		m_tracker.Initial(m_rcInitWin, rect);
		m_tracker.m_nStyle = CRectTracker::solidLine;
		m_bIsInit = false;
	}

	CFont font;
	font.CreatePointFont(65, _T("Arial"), &dc);
	CFont* oldFont = dc.SelectObject(&font);
	CPen* oldPen = dc.SelectObject(m_pYellowPen);

	//画图像
	if (NULL != m_iplImage)
	{
		CvvImage cvvImg;
		cvvImg.CopyOf(m_iplImage);
		HDC hdc = dc.GetSafeHdc();
		cvvImg.DrawToHDC(hdc, &rect);
		cvvImg.Destroy();
	}
	else
	{
		CDC memDC;
		CBitmap bitmap, *pOldBitmap;
		bitmap.LoadBitmap(IDB_BITMAP_BACKGROUND);
		memDC.CreateCompatibleDC(NULL);
		pOldBitmap = (CBitmap*)(memDC.SelectObject(&bitmap));
// 		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,rect.Width(),rect.Height(),SRCCOPY);
		dc.BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
		memDC.SelectObject(pOldBitmap);
		memDC.DeleteDC();
	}
	
	//画矩形
	m_tracker.DrawRect(&dc);
	
	//画箭头和中心十字线
	dc.MoveTo(rect.left, iWinCenterY);
	dc.LineTo(rect.right, iWinCenterY);
	dc.MoveTo(iWinCenterX, rect.top);
	dc.LineTo(iWinCenterX, rect.bottom);

	dc.MoveTo(rect.left + 8, rect.bottom - 8);
	dc.LineTo(rect.left + 30, rect.bottom - 8);
	dc.LineTo(rect.left + 25, rect.bottom - (INT)5.5);
	dc.MoveTo(rect.left + 30, rect.bottom - 8);
	dc.LineTo(rect.left + 25, rect.bottom - (INT)10.5);
	dc.MoveTo(rect.left + 8, rect.bottom - 8);
	dc.LineTo(rect.left + 8, rect.bottom - 30);
	dc.LineTo(rect.left + (INT)5.5, rect.bottom - 25);
	dc.MoveTo(rect.left + 8, rect.bottom - 30);
	dc.LineTo(rect.left + (INT)10.5, rect.bottom - 25);

	if (m_bIsDrawTickMark)
	{
		dc.SetTextColor(RGB(255, 0, 0));
		dc.SetBkMode(TRANSPARENT);
		dc.ExtTextOut(rect.left+35, rect.bottom-13, ETO_OPAQUE, NULL, _T("X(um)"), NULL);
		dc.ExtTextOut(rect.left+5, rect.bottom-43, ETO_OPAQUE, NULL, _T("Y(um)"), NULL);

		//画刻度线
		DrawTickMark(&dc, iWinCenterX, iWinCenterY);
	}
	else
	{
		dc.SetTextColor(RGB(255, 255, 0));
		dc.SetBkMode(TRANSPARENT);
		dc.ExtTextOut(rect.left+35, rect.bottom-13, ETO_OPAQUE, NULL, _T("X"), NULL);
		dc.ExtTextOut(rect.left+5, rect.bottom-43, ETO_OPAQUE, NULL, _T("Y"), NULL);
	}

	dc.SelectObject(oldFont);
	dc.SelectObject(oldPen);
	font.DeleteObject();
}


void CImageShowStatic::DrawTickMark(CDC* pDC, int iCenterX, int iCenterY)
{
	int iXStepLen = 10;			//X方向步长(即每个刻度的像素数)
	int iYStepLen = 4;			//Y方向步长(即每个刻度的像素数)
	int iXScaleCnt = iCenterX / iXStepLen;	//X方向每侧的刻度数
	int iYScaleCnt = iCenterY / iYStepLen;  //Y方向每侧的刻度数

	for(int i=1; i<= iXScaleCnt; i++)
	{
		//左侧
		if(0 == i%5)
		{
			pDC->MoveTo(iCenterX-10*i, iCenterY);
			pDC->LineTo(iCenterX-10*i, iCenterY+20);

			pDC->MoveTo(iCenterX-10*i, iCenterY);
			pDC->LineTo(iCenterX-10*i, iCenterY-20);

			int iTextXLPos = iCenterX-10*i-10;
			iTextXLPos = iTextXLPos>0 ? iTextXLPos : 0; 
			if(0 == i%2)
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), -150*(i/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iTextXLPos, iCenterY-28, rulerLabel);
			}
			else
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), -150*(i/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iTextXLPos, iCenterY+22, rulerLabel);
			}
		}
		else
		{
			pDC->MoveTo(iCenterX-10*i, iCenterY);
			pDC->LineTo(iCenterX-10*i, iCenterY+10);

			pDC->MoveTo(iCenterX-10*i, iCenterY);
			pDC->LineTo(iCenterX-10*i, iCenterY-10);
		}

		//右侧
		if(0 == i%5)
		{
			pDC->MoveTo(iCenterX+10*i, iCenterY);
			pDC->LineTo(iCenterX+10*i, iCenterY+20);

			pDC->MoveTo(iCenterX+10*i, iCenterY);
			pDC->LineTo(iCenterX+10*i, iCenterY-20);

			int iTextXRPos = iCenterX+10*i-7;
			iTextXRPos = iTextXRPos<2*iCenterX-15 ? iTextXRPos : 2*iCenterX-15; 
			if(0 == i%2)
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), 150*(i/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iTextXRPos, iCenterY-28, rulerLabel);
			}
			else
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), 150*(i/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iTextXRPos, iCenterY+22, rulerLabel);
			}
		}
		else
		{
			pDC->MoveTo(iCenterX+10*i, iCenterY);
			pDC->LineTo(iCenterX+10*i, iCenterY+10);

			pDC->MoveTo(iCenterX+10*i, iCenterY);
			pDC->LineTo(iCenterX+10*i, iCenterY-10);
		}
	}

	for(int j=1; j<= iYScaleCnt; j++)
	{
		//上侧
		if(0 == j%5)
		{
			pDC->MoveTo(iCenterX, iCenterY-4*j);
			pDC->LineTo(iCenterX+20, iCenterY-4*j);

			pDC->MoveTo(iCenterX, iCenterY-4*j);
			pDC->LineTo(iCenterX-20, iCenterY-4*j);

			int iTextYTPos = iCenterY-4*j-5;
			iTextYTPos = iTextYTPos>0 ? iTextYTPos : 0; 
			if(0 == j%2)
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), 60*(j/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iCenterX-38, iTextYTPos, rulerLabel);
			}
			else
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), 60*(j/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iCenterX+24, iTextYTPos, rulerLabel);
			}
		}
		else
		{
			pDC->MoveTo(iCenterX, iCenterY-4*j);
			pDC->LineTo(iCenterX+10, iCenterY-4*j);

			pDC->MoveTo(iCenterX, iCenterY-4*j);
			pDC->LineTo(iCenterX-10, iCenterY-4*j);
		}

		//下侧
		if(0 == j%5)
		{
			pDC->MoveTo(iCenterX, iCenterY+4*j);
			pDC->LineTo(iCenterX+20, iCenterY+4*j);

			pDC->MoveTo(iCenterX, iCenterY+4*j);
			pDC->LineTo(iCenterX-20, iCenterY+4*j);

			int iTextYBPos = iCenterY+4*j-5;
			iTextYBPos = iTextYBPos<2*iCenterY-10 ? iTextYBPos : 2*iCenterY-10; 
			if(0 == j%2)
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), -60*(j/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iCenterX-41, iTextYBPos, rulerLabel);
			}
			else
			{
				CString rulerLabel = _T("");
				rulerLabel.Format(_T("%d"), -60*(j/5));
				pDC->SetTextColor(RGB(255,0,0));
				pDC->TextOut(iCenterX+24, iTextYBPos, rulerLabel);
			}
		}
		else
		{
			pDC->MoveTo(iCenterX, iCenterY+4*j);
			pDC->LineTo(iCenterX+10, iCenterY+4*j);

			pDC->MoveTo(iCenterX, iCenterY+4*j);
			pDC->LineTo(iCenterX-10, iCenterY+4*j);
		}
	}
}


void CImageShowStatic::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rectSave;
	//获取图形区域矩形对象的大小
	m_tracker.GetTrueRect(rectSave);
	//如果没有点中图形,这时候HitTest将返回-1.这时候产生橡皮条.
	
	if (0 > m_tracker.HitTest(point))
	{		
	}
	else if (m_tracker.Track(this, point, TRUE))
	{
		this->Invalidate();
	} 
	CStatic::OnLButtonDown(nFlags, point);
}


BOOL CImageShowStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if (pWnd == this && m_tracker.SetCursor(this, nHitTest)) 
    return TRUE; 
	return CStatic::OnSetCursor(pWnd, nHitTest, message);
}


void CImageShowStatic::SetShowImage(IplImage* pImg)
{
	m_iplImage = pImg;
	this->Invalidate();
}


BOOL CImageShowStatic::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;   //为解决刷新时闪烁问题
}


void CImageShowStatic::SetDrawRect(bool bFlag)
{
	m_bIsInit = true;
	m_tracker.Enable(bFlag);
	this->Invalidate();
}


void CImageShowStatic::SetDrawTickMark(bool bFlag)
{
	m_bIsDrawTickMark = bFlag;
	this->Invalidate();
}


CRect CImageShowStatic::GetTrackerRect()
{
	return m_tracker.m_rect;
}
