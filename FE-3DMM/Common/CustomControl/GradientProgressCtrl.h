#pragma once
#include "CustomMemDC.h"

#ifndef _MaX(a,b)
#define _MaX(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef _MiN(a,b)
#define _MiN(a,b)  (((a) < (b)) ? (a) : (b))
#endif

// GradientProgressCtrl.h : header file
//
// Written by matt weagle (matt_weagle@hotmail.com)
// Copyright (c) 1998.
//
// This code may be used in compiled form in any way you desire. This
// file may be redistributed unmodified by any means PROVIDING it is 
// not sold for profit without the authors written consent, and 
// providing that this notice and the authors name is included. If 
// the source code in  this file is used in any commercial application 
// then a simple email would be nice.
//
// This file is provided "as is" with no expressed or implied warranty.
// The author accepts no liability if it causes any damage whatsoever.
//
// Thanks to Chris Maunder (Chris.Maunder@cbr.clw.csiro.au) for the 
// foregoing disclaimer.



/////////////////////////////////////////////////////////////////////////////
// CGradientProgressCtrl window

class CGradientProgressCtrl : public CProgressCtrl
{
// Construction
public:
	CGradientProgressCtrl();

// Attributes
public:
// Attributes
	
	void SetRange(int nLower, int nUpper);
	void SetRange32( int nLower, int nUpper );
	int SetPos(int nPos);
	int SetStep(int nStep);
	int StepIt(void);

// Operations
public:
	
	// Set Functions
	void SetTextColor(COLORREF color)	{m_clrText = color;}
	void SetBkColor(COLORREF color)		 {m_clrBkGround = color;}
	void SetStartColor(COLORREF color)	{m_clrStart = color;}
	void SetEndColor(COLORREF color)	{m_clrEnd = color;}

	// Show the percent caption
	void ShowPercent(BOOL bShowPercent = TRUE)	{m_bShowPercent = bShowPercent;}
	
	// Get Functions
	COLORREF GetTextColor(void)	{return m_clrText;}
	COLORREF GetBkColor(void)		 {return m_clrBkGround;}
	COLORREF GetStartColor(void)	{return m_clrStart;}
	COLORREF GetEndColor(void)	{return m_clrEnd;}


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGradientProgressCtrl)
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGradientProgressCtrl();

	// Generated message map functions
protected:
	void DrawGradient(CPaintDC *pDC, const RECT &rectClient, const int &nMaxWidth, const BOOL &bVertical);	
	int m_nLower, m_nUpper, m_nStep, m_nCurrentPosition;
	COLORREF	m_clrStart, m_clrEnd, m_clrBkGround, m_clrText;
	BOOL m_bShowPercent;
	//{{AFX_MSG(CGradientProgressCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
