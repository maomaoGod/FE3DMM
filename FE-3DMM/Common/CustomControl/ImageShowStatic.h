// StaticDisplayImage.h : header file

#pragma once
#include "MyRectTracker.h"
#include "CvvImage.h"


class CImageShowStatic : public CStatic
{
// Construction
public:
	CImageShowStatic();
	virtual ~CImageShowStatic();

	void SetShowImage(IplImage* pImg);		//设置图像并显示
	void SetDrawRect(bool bFlag);					//设置画矩形
	void SetDrawTickMark(bool bFlag);			//设置画刻度线
	CRect GetTrackerRect();								//获得橡皮筋区域CRect

protected:
	//{{AFX_MSG(CImageShowStatic)
	// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()

private:
	void DrawTickMark(CDC* pDC, int iCenterX, int iCenterY);  //画刻度线


private:
	CMyRectTracker m_tracker;
	CPen* m_pYellowPen;
	IplImage* m_iplImage;
	int m_iChangeSizeX;
	int m_iChangeSizeY;
	CRect m_rcInitWin;
	bool m_bIsInit;												//是否初始化橡皮筋
	bool m_bIsDrawTickMark;							//是否画刻度线
};

