// BmpBtn.h: interface for the CBmpBtn class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

class CBmpBtn : public CBitmapButton  
{
public:
	CBmpBtn();
	virtual ~CBmpBtn();
	void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	void SetFont(int size=15);
	void SetBmp( UINT nIDBitmapResource, UINT nIDBitmapResourceDisabled ,BOOL show = 1);
	
	void SetTitle(CString title)
	{
		m_strTitle = title;
	}
private:		
	CFont font;
	CRect rect;
	CString m_strTitle;
};
