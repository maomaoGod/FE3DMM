#pragma once


// CDlgPrintPrintOperate 对话框

class CDlgPrintPrintOperate : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrintPrintOperate)

public:
	CDlgPrintPrintOperate(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPrintPrintOperate();

// 对话框数据
	enum { IDD = IDD_DLG_PRINT_PRINTING };

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedPrintPrLoadUGfileBtn();
	afx_msg void OnBnClickedPrintPrStartprintBtn();
	afx_msg void OnBnClickedPrintPrStopprintBtn();
	afx_msg void OnBnClickedPrintPrLinkprintBtn();
	afx_msg void OnBnClickedPrintPrPauseprintBtn();
	afx_msg void OnBnClickedPrintPrContinueprintBtn();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedPrintPrCameraslopewatchRadio();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();																	//释放本窗口中其他new堆内存
	void InitGridList();															//初始化设备状态列表
	void UpdateGridList();													//刷新设备状态列表
	void InitProgress();
	void InitWindowHandle();												//初始化Pic控件显示窗口

private:
	CXPGroupBox					m_GB1;
	CXPGroupBox					m_GB2;
	CXPGroupBox					m_GB3;
	CBmpBtn							m_bmpBtn[6];
	CGridCtrl							m_gridListState;
	CGradientProgressCtrl	m_progressPrint;
	CProcessCore					*m_pProCore;						//主操作类指针
	CString								m_strUgFileName;
	CString								m_strUgFilePath;
	double								m_dPrintSpeed;	
	HTuple								m_windowHandle_Pic;		//Pic控件关联的Halcon窗口句柄
	Size										m_winSize_Pic;						//Pic窗口大小
};
