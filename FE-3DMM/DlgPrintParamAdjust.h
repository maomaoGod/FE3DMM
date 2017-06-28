#pragma once
#include "DlgPrintParamDataRecord.h"
#include "DlgPrintParamCameraWatch.h"

// CDlgPrintParamAdjust 对话框


class CDlgPrintParamAdjust : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrintParamAdjust)

public:
	CDlgPrintParamAdjust(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPrintParamAdjust();

// 对话框数据
	enum { IDD = IDD_DLG_PRINT_PARAM };

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPrintPaVoltageAirOpenBtn();
	afx_msg void OnBnClickedPrintPaPumpmodeRadio();
	afx_msg void OnBnClickedPrintPaFeedAirPressmodeRadio();
	afx_msg void OnBnClickedPrintPaDataRecordBtn();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnUMCameraWatchShow();
	afx_msg void OnBnClickedPrintPaDcModeRadio();
	afx_msg void OnBnClickedPrintPaAcModeRadio();
	afx_msg void OnBnClickedPrintPaFlowstartBtn();
	afx_msg void OnBnClickedPrintPaFlowstopBtn();
	afx_msg void OnDeltaposPrintPaAmplitudeSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposPrintPaFreqSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposPrintPaOffsetSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposPrintPaDutyratioSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposPrintPaAuxiairpressSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposPrintPaFlowsetSpin(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedPrintPaCamerawatchRadio();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();																		//释放本窗口中其他new堆内存
	void InitFlowAdjustCtrlState(bool bEnabled);				//初始化流量调节控件状态
	void InitVoltageAirAdjustCtrlState(bool bEnabled);	//初始化电压气压调节控件状态	
	void SetFlowComponentState(bool bEdit,bool bForward,bool bBackward,bool bStart,bool bStop); //设置流量调节组件状态
	void SetVoltageComponentState(bool bOffset,bool bAmplitude,bool bFreq,bool bDutyRatio);			//设置电压调节组件状态			
	void InitWindowHandle();													//初始化Pic控件显示窗口

public:
	void AddPrintParamTable();												//添加打印参数表
	void ApplyPrintParamTable();											//应用打印参数表


private:
	CXPGroupBox				m_GB1;
	CXPGroupBox				m_GB2;
	CBmpBtn						m_bmpBtn[6];
	CProcessCore				*m_pProCore;								//主操作类指针
	bool								m_bVoltageAirOpen;		
	bool								m_bParamDataShow;					//参数数据是否显示
	bool								m_bCameraWatchShow;			//墨滴观测相机是否单独显示
	bool								m_bForwardOrBackwardFlag;	//快进快退被按下标志
	VoltageMode				m_enumVolMode;						//电压模式
	FlowAdjustPattern		m_enumFlowAdjPattern;			//流量调节方式
	double							m_dDcOffset;								//直流偏置
	double							m_dAcOffset;								//交流偏置
	double							m_dAcFreq;									//交流频率
	double							m_dAcAmplitude;						//交流幅值
	double							m_dAcRatio;									//交流占空比
	double							m_dAuxiAirPress;							//辅助气压值
	double							m_dPumpFlowRate;					//流量泵流量率
	double							m_dFeedAirFlowRate;					//进给气压流量率
	
	HTuple							m_windowHandle_Pic;				//Pic控件关联的Halcon窗口句柄
	Size									m_winSize_Pic;								//Pic窗口大小
	CDlgPrintParamDataRecord*	m_pDlgPrintParamDataRecord;			//记录参数数据
	CDlgPrintParamCameraWatch*	m_pDlgPrintParamCameraWatch;	//墨点观测相机
};
