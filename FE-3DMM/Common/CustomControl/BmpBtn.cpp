// BmpBtn.cpp: implementation of the CBmpBtn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BmpBtn.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBmpBtn::CBmpBtn()
{
	
}

CBmpBtn::~CBmpBtn()
{

}

void CBmpBtn::SetFont(int size)
{
	//设置字体大小
	font.CreateFont(size, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, 
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS,
		"宋体" );
}

// Draw the appropriate bitmap
void CBmpBtn::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	GetClientRect(rect);
	ASSERT(lpDIS != NULL);
	// must have at least the first bitmap loaded before calling DrawItem
	ASSERT(m_bitmap.m_hObject != NULL);     // required

	// use the main bitmap for up, the selected bitmap for down
	CBitmap* pBitmap = &m_bitmap;
	UINT state = lpDIS->itemState;
	if ((state & ODS_SELECTED) && m_bitmapSel.m_hObject != NULL)
		pBitmap = &m_bitmapSel;
	else if ((state & ODS_FOCUS) && m_bitmapFocus.m_hObject != NULL)
		pBitmap = &m_bitmapFocus;   // third image for focused
	else if ((state & ODS_DISABLED) && m_bitmapDisabled.m_hObject != NULL)
		pBitmap = &m_bitmapDisabled;   // last image for disabled

	// draw the whole button
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap* pOld = memDC.SelectObject(pBitmap);
	if (pOld == NULL)
		return;     // destructors will clean up

	//test
	BITMAP bmp; 
	pBitmap->GetBitmap(&bmp); 
	int nWidth = bmp.bmWidth; 
	int nHeight = bmp.bmHeight;
	pDC->SetStretchBltMode(COLORONCOLOR);
	pDC->StretchBlt(0,0,rect.Width() ,rect.Height(),&memDC,0,0,
		nWidth,nHeight,SRCCOPY);
	//test

//	CRect rect;
//	rect.CopyRect(&lpDIS->rcItem);
//	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(),
// 		&memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOld);

	int nOldMode = pDC->SetBkMode(TRANSPARENT);
	COLORREF clrOld = pDC->SetTextColor(RGB(54,73,165));
	if ( m_strTitle.GetLength()>0 )		// 绘制窗体中的文本信息
	{
		int len = m_strTitle.GetLength();
		pDC->SelectObject(&font);

		//制造叠影效果
		pDC->TextOut(rect.left+rect.Width()/2 - len*4.5 +1,rect.top+rect.Height()/2-9 +1,m_strTitle);
		pDC->SetTextColor(RGB(212,212,212));
		pDC->TextOut(rect.left+rect.Width()/2 - len*4.5 ,rect.top+rect.Height()/2-9 ,m_strTitle);
	}
}

void CBmpBtn::SetBmp( UINT nIDBitmapResource, UINT nIDBitmapResourceDisabled,BOOL show)
{
	EnableWindow(1);
	ShowWindow(show);
	LoadBitmaps(nIDBitmapResource,nIDBitmapResource,nIDBitmapResourceDisabled,nIDBitmapResourceDisabled);
	Invalidate(0);
}