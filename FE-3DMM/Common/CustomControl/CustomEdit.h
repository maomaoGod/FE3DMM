#pragma once

#include <ctype.h>	//isalpha, isalnum and so on...
#include <locale.h>	// localeconv

/////////////////////////////////////////////////////////////////////////////
// CCustomEdit window

class CCustomEdit : public CEdit
{
// Construction
public:
	CCustomEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomEdit)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool SetToolTipText(const CString& sText, bool bActivate = true);
	bool ActivateToolTip(bool bEnable = true);
	bool SetFontBold( bool bBold = true);
	bool SetFontItalic( bool bItalic = true);
	bool SetFontHeight( int nHeight );
	bool SetFontFaceName( const CString& sFaceName );
	bool GetTextFont( LOGFONT* plgfnt);
	bool SetTextFont( LONG nHeight, bool bBold, bool bItalic, const CString& sFaceName );
	bool SetTextFont( const LOGFONT& lgfnt );
	bool EnableEditing(bool bEditing = true);
	bool GetTextClrFocus(COLORREF &clr);
	bool SetTextClrFocus( COLORREF clr );
	bool GetBkClrFocus(COLORREF &clr);
	bool SetBkClrFocus( COLORREF clr );
	bool GetTextClr(COLORREF &clr);
	bool SetTextClr( COLORREF clr );
	bool GetBkClr(COLORREF &clr);
	bool SetBkClr( COLORREF clr );
	virtual ~CCustomEdit();

	// Generated message map functions
protected:
	bool InitToolTip();
	CToolTipCtrl m_tt;
	bool m_bHasFocus;
	CFont m_fntText;
	bool m_bEnableEditing;
	COLORREF m_clrTextFocus;
	COLORREF m_clrBkGndFocus;
	COLORREF m_clrText;
	COLORREF m_clrBkGnd;
	CBrush m_brsBkGnd;
	CBrush m_brsBkGndFocus;
	//{{AFX_MSG(CCustomEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnKillFocus();
	afx_msg void OnSetFocus();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////