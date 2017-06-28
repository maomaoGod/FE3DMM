#pragma once
class CDlgPrintParamAdjust;


// CDlgPrintParamDataRecord 对话框
enum VoltageMode{DcMode = 0, AcMode};							//电压模式
enum FlowAdjustPattern{PumpPattern = 0, FeedAirPressPattern};	//流量调节方式


typedef struct st_DataCollect
{
	VoltageMode			enumVolMode;			//电压模式
	FlowAdjustPattern	enumFlowAdjPattern;		//流量调节方式
	double				dDcOffset;				//直流偏置
	double				dAcOffset;				//交流偏置
	double				dAcFreq;				//交流频率
	double				dAcAmplitude;			//交流幅值
	double				dAcRatio;				//交流占空比
	double				dAuxiAirPress;			//辅助气压值
	double				dPumpFlowRate;			//流量泵流量率
	double				dFeedAirFlowRate;		//进给气压流量率
}DataCollect;


class CDlgPrintParamDataRecord: public CDialog
{
	DECLARE_DYNAMIC(CDlgPrintParamDataRecord)

public:
	CDlgPrintParamDataRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPrintParamDataRecord();

// 对话框数据
	enum { IDD = IDD_DLG_PRINT_PARAM_DATARECORD };

	void Cancel();				//销毁窗口及子窗口

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedPrintPaDataApplyBtn();
	afx_msg void OnBnClickedPrintPaDataAddBtn();
	afx_msg void OnBnClickedPrintPaDataModifyBtn();
	afx_msg void OnBnClickedPrintPaDataDeleteBtn();
	virtual BOOL PreTranslateMessage(MSG* pMsg);


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();

private:
	void Release();				//释放本窗口中其他new堆内存
	void InitDlgCtrl();
	void InitGridListData();
	void ShowGridListData(CAdoRecordset* pRecordSet);

private:
	CDlgPrintParamAdjust*	m_pDlgParamMain;		//参数调节窗口
	CBmpBtn					m_bmpBtn[4];
	CGridCtrl				m_gridlistData;	
	CString					m_strDatabasePath;
	CAdoDatabase			m_adoDatabase;

public:
	DataCollect				m_PrintParamTable;		//打印参数表

	
};