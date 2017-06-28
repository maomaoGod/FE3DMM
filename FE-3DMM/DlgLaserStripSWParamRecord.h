#pragma once
class CDlgLaserStripSubWin;


// CDlgLaserStripSWParamRecord 对话框

class CDlgLaserStripSWParamRecord : public CDialog
{
	DECLARE_DYNAMIC(CDlgLaserStripSWParamRecord)

public:
	CDlgLaserStripSWParamRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLaserStripSWParamRecord();

// 对话框数据
	enum { IDD = IDD_DLG_LASERSTRIP_SUB_PARAMRECODE };

	void Cancel();				//销毁窗口及子窗口
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSelchangeLaserstripSubPRScanModeCombo();
	afx_msg void OnClickedLaserstripSubPrAddBtn();
	afx_msg void OnBnClickedLaserstripSubPrDeleteBtn();
	afx_msg void OnBnClickedLaserstripSubPrApplyBtn();

private:
	void Release();						//释放本窗口中其他new堆内存
	void InitDlgCtrl();
	void InitGridListData();
	void InitGridListSingleParam();
	void InitGridListMultiParam();
	void ShowGridListSingleParam(CAdoRecordset* pRecordSet);
	void ShowGridListMultiParam(CAdoRecordset* pRecordSet);
	void AddGridListSingleParam();      //将单行扫描参数添加至GridList中
	void AddGridListMultiParam();		//将多行扫描参数添加至GridList中
	void ApplyGridListSingleParam();    //应用GridList中数据至单行扫描参数结构体，并显示至剥离界面Static控件
	void ApplyGridListMultiParam();		//应用GridList中数据至多行扫描参数结构体，并显示至剥离界面Static控件
	
private:
	CDlgLaserStripSubWin*	m_pDlgLaserStripSubWinMain;		//主窗口SubWin
	CBmpBtn					m_bmpBtn[3];
	CGridCtrl				m_gridlistSingleParam;	
	CGridCtrl				m_gridlistMultiParam;	
	CString					m_strDatabasePath;
	CAdoDatabase			m_adoDatabase;
	CComboBox				m_comboboxScanMode;

};
