#pragma once
class CDlgLaserStripSubWin;


// CDlgLaserStripSWScanPathMultiRow 对话框
typedef struct st_ParamMultiScan
{
	double  dScanLen;			//扫描长度
	double	dScanSpace;			//扫描间距
	double  dScanSpeed;			//扫描速度
	double	dTransRowSpeed;		//换行速度
	int		nScanNum;			//扫描次数

	st_ParamMultiScan()
	{
		dScanLen = 0.0;
		dScanSpace = 0.0;
		dScanSpeed = 0.0;
		dTransRowSpeed = 0.0;
		nScanNum = 0;
	}
}ParamMultiScan;


class CDlgLaserStripSWScanPathMultiRow : public CDialog
{
	DECLARE_DYNAMIC(CDlgLaserStripSWScanPathMultiRow)

public:
	CDlgLaserStripSWScanPathMultiRow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLaserStripSWScanPathMultiRow();

// 对话框数据
	enum { IDD = IDD_DLG_LASERSTRIP_SUB_SCANPATH_MultiRow };

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();
	void ApplyScanParamToMultiPathWin();  //应用扫描参数至多行路径设置窗口

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();

public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedLaserstripSubSpMrScanpathsetBtn();


private:
	void Release();				//释放本窗口中其他new堆内存


private:
	CDlgLaserStripSubWin*		m_pDlgLaserStripSubWinMain;		 //主窗口SubWin
	CBmpBtn						m_bmpBtn[1];
	
};
