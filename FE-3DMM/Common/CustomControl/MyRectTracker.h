// MyRectTracker.h: interface for the CMyRectTracker class.
//

#pragma once

#ifndef _MaX(a,b)
#define _MaX(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef _MiN(a,b)
#define _MiN(a,b)  (((a) < (b)) ? (a) : (b))
#endif

class CMyRectTracker : public CRectTracker  
{
public:
	CMyRectTracker();
	virtual ~CMyRectTracker();
	void Initial(RECT& rect, RECT &maxRect);
	void Enable(BOOL bEnable = TRUE);
	virtual void AdjustRect(int nHandle, LPRECT lpRect);
	virtual void OnChangedRect(const CRect& rectOld);
	void DrawRect(CDC* pDC);
	virtual BOOL Track( CWnd* pWnd, CPoint point, BOOL bAllowInvert = FALSE, CWnd* pWndClipTo = NULL );

private:
	RECT m_rectOld;
	BOOL m_bEnable;	
	CRect m_maxRect;
};
