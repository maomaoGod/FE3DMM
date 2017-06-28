#pragma once
class CDlgPrintMotionControl;

// CDlgPrintMotionLinkLearn 对话框

//点位置信息X、Y
typedef struct st_PointPos
{
	float fPosX;
	float fPosY;
	st_PointPos()
	{
		fPosX = 0.0;
		fPosY = 0.0;
	}
}PointPos;

//点角度信息A、C
typedef struct st_PointAngle
{
	float fAngleA;
	float fAngleC;
	st_PointAngle()
	{
		fAngleA = 0.0;
		fAngleC = 0.0;
	}
}PointAngle;

//直线信息(两端点两角度)
typedef struct st_StraightLine
{
	PointPos	beginpoint;
	PointPos	endpoint;
	PointAngle	angle;
}StraightLine;


class CDlgPrintMotionLinkLearn : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrintMotionLinkLearn)

public:
	CDlgPrintMotionLinkLearn(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPrintMotionLinkLearn();

// 对话框数据
	enum { IDD = IDD_DLG_PRINT_MOTION_LINES };

	void Cancel();				//销毁窗口及子窗口

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedPrintMLBeginpointBtn();
	afx_msg void OnBnClickedPrintMLEndpointBtn();
	afx_msg void OnBnClickedPrintMLLinklineBtn();
	afx_msg void OnRclickPrintMLLinesList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnUMLineDelete();
	afx_msg void OnUMLineClear();

private:
	void Release();									//释放本窗口中其他new堆内存
	void InitDlgCtrl();
	void UpdateLineNum();							//更新线条数


private:
	CProcessCore*				m_pProCore;			//主操作类指针
	CDlgPrintMotionControl*		m_pDlgMotionMain;	//运动控制窗口
	CBmpBtn					    m_bmpBtn[3];
	CListCtrl					m_listLines;

	StraightLine				m_straightline;

public:
	vector<StraightLine>		m_vecLine;			//直线vector
	float						m_fPrintLinesSpeed;	//打印直线速度

};
