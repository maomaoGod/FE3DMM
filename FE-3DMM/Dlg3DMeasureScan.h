#pragma once


// CDlg3DMeasureScan 对话框
class CDlg3DMeasureScan : public CDialog
{
	DECLARE_DYNAMIC(CDlg3DMeasureScan)

public:
	CDlg3DMeasureScan(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg3DMeasureScan();

// 对话框数据
	enum { IDD = IDD_DLG_3DMEASURE_SCAN };

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();


public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked3dmeasureSConnectBtn();
	afx_msg void OnBnClicked3dmeasureSStartBtn();
	afx_msg void OnBnClicked3dmeasureSStopBtn();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT nIDEvent);
	void OnChangeLens();
	void OnChangeProbes();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();				//释放本窗口中其他new堆内存

private:
	CXPGroupBox			m_GB1;
	CBmpBtn				m_bmpBtn[3];
	CProcessCore		*m_pProCore;	//主操作类指针

public:
	CComboBox	m_cbLens;
	CSliderCtrl	m_sliderPower;
	CComboBox	m_CBProbes;
	CComboBox	m_CBProbeType;
	CString	m_sDisMin;
	CString	m_sDisMax;
	CString	m_sDistance;
	CString	m_sSNR;
	CString m_Freq;
	CString	m_sQuality;
	CString	m_sSliderPower;
	unsigned int timer1,timer2;
	afx_msg void OnCbnSelchange3dmeasureSLensmaxdisCombox();
	afx_msg void OnEnChange3dmeasureSPointfreqEdit();
};
