#pragma once


// CPanelWnd

#define  PANELWND _T("PanelWnd")

class CPanelWnd : public CWnd
{
	DECLARE_DYNAMIC(CPanelWnd)

public:
	enum {RECT_WIDTH = 3};

	CPanelWnd();
	virtual ~CPanelWnd();

	//Get The Device Context;
	CDC * GetDC();

	void SetBackColor(COLORREF newColor);
	void DrawBackground(CDC *pDc,CRect panelRect);
	void DrawBackEdge(CDC *pDc,CRect panelRect);
	//Refresh The PrintPanel;
	void RefreshPanel();

	//Create the Window
	bool Create(CWnd *pParent,const RECT &rect,UINT nID,DWORD dwStyle = WS_VISIBLE);

	void drawRect(CPoint centerPos,CClientDC *pDc);
	void setIndicatorPoint(CPoint rectPos);
	void drawCoordinate(CDC *pDc);
	void TextCoordinate(const CPoint& pt,const CString& text);
	void updateIndicatorPoint(CPoint pos);

	CPoint GetMousePos() const
	{
		return mousePosInDevice;
	}

	void SetPanelSize(double &db_x,double &db_y);
	void DevicePointToLogicPoint(const float &fpt_x,const float &fpt_y,int& npt_x,int &npt_y);
	int DevicePointToLogicPointX(float &pt_x);
	int DevicePointToLogicPointY(float &pt_y);
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()

private:
    bool RegisterWindowClass();

private:
	CDC m_backgroundDC;
	COLORREF m_backgroundColor;
	COLORREF m_borderColor;
	CSize m_LogicalSize;
	CSize m_PanelSize;

	CPoint mousePosInLogic;
	CPoint mousePosInDevice;
	CPoint indicatorPoint;      //指示点的位置
	CRect indicatorRect;
	CString mousePosString;

	bool m_bMemDcCreated;
	bool m_bMouseInWnd;
	int n_TextHeight;
	int n_TextWidth;

	CPoint m_startPos;
	CPoint m_endPos;
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseLeave();
};


