#pragma once
class CDlgLaserStripSubWin;


// CDlgLaserStripSWScanPathSingleRow 对话框
typedef struct st_ParamSingleScan
{
	double  dScanLen;		//扫描长度
	double  dScanSpeed;		//扫描速度
	int		nScanNum;		//扫描次数

	st_ParamSingleScan()
	{
		dScanLen = 0.0;
		dScanSpeed = 0.0;
		nScanNum = 0;
	}
}ParamSingleScan;


class CDlgLaserStripSWScanPathSingleRow : public CDialog
{
	DECLARE_DYNAMIC(CDlgLaserStripSWScanPathSingleRow)

public:
	CDlgLaserStripSWScanPathSingleRow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLaserStripSWScanPathSingleRow();

// 对话框数据
	enum { IDD = IDD_DLG_LASERSTRIP_SUB_SCANPATH_SingleRow };

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();
	void ApplyScanParamToSinglePathWin();  //应用扫描参数至单行路径设置窗口

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedLaserstripSubSpSrScanpathsetBtn();

private:
	void Release();				//释放本窗口中其他new堆内存


private:
	CDlgLaserStripSubWin*		m_pDlgLaserStripSubWinMain;		 //主窗口SubWin
	CBmpBtn						m_bmpBtn[1];

};
