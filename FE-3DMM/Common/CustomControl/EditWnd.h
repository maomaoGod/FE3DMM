// EditWnd.h : header file
//

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CEditWnd window

class CEditWnd : public CWnd
{
// Construction
public:
	CEditWnd();
	DECLARE_DYNCREATE( CEditWnd )

// Attributes
public:

// Operations
public:
	void GetString(CString &strWnd);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditWnd)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEditWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEditWnd)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg UINT OnGetDlgCode();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
private:
	int PosFromChar(UINT nChar);		// 通过指定的字符获得其x轴的位置
	int CharFromPos(int nPosX);			// 通过给定的x轴的位置获得相应的字符
	void CutString();					// 剪切字符串
	void PasteString();					// 粘贴字符串
	void CopyString();					// 拷贝字符串
	void MakeBKGround(CDC *pDC, COLORREF clrBegin, COLORREF clrEnd, CRect rect);	// 生成窗口背景
	CString m_strEdit;		// 当前包含的文本。
	CString m_strSelect;	// 当前选择的文本。

	CPoint m_ptCursor;		// 当前光标的位置。
	CPoint m_ptTxtBegin;	// 文本的起始位置。
	CPoint m_ptFirst;		// 鼠标左键按下时的第一点位置。
	CPoint m_ptSecond;		// 鼠标当前的位置。

	int m_nCharPos;			// 当前光标处于第几个字符的后面，从0开始计数。
	int m_nShowChar;		// 在编辑框中第一个显示的字符，从0开始计数。
	int m_nMaxShowChars;	// 在编辑框中一次最多显示的字符数量	。
	int m_nSelectBegin;		// 选择的字符的起始位置。
	int m_nSelectEnd;		// 选择的字符的终止位置。

	CBitmap m_BmpBK;		// 背景图片。

	CFont m_TxtFont;		// 文本的字体。
	TEXTMETRIC m_tm;		// 文本字体的信息。

	CRect	m_rcWnd;		// 窗口的大小。

	bool	m_bLBtDown;		// 鼠标左键按下。
	int		m_nShiftBegin;	// shift键第一次时光标所在的字符的位置。
//extent 附加
	CString m_strTitle;		// 编辑框标题
	CString m_strUnit;		// 编辑框单位
	int m_iState;			// 状态 0-正常；1-风险；2-错误；3-禁用
	BOOL m_bBkneedchange;	// 背景是否需刷新
	struct _BKCOLOR 
	{
		COLORREF clrBegin;
		COLORREF clrEnd;
	};
	_BKCOLOR m_bkcolor0;		// 背景渐变颜色-正常
	_BKCOLOR m_bkcolor1;		// 背景渐变颜色-风险
	_BKCOLOR m_bkcolor2;		// 背景渐变颜色-错误
	_BKCOLOR m_bkcolor3;		// 背景渐变颜色-禁用

public:
	void SetTittleUnit(CString title ,CString unit);
	CString GetVal(){
	 return m_strEdit;		// 读取文本;
	}
	void SetVal(CString val){
	 m_strEdit = val;		// 设置文本;
	 Invalidate();			// 刷新
	}
	void Enable(BOOL bable,int state = 0){
	 EnableWindow(bable);		// 设置文本;
	}
	void SetState(int state){
	 m_iState = state;		// 设置文本;
	 m_bBkneedchange = 1;
	 Invalidate();
	}
};
