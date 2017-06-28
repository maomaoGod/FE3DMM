#pragma once
#include "ProcessCore.h"
#include "afxwin.h"
#include "afxcmn.h"
// CDlgTransferParamCoordCalib 对话框

class CDlgTransferParamLearn;

struct PickCamOffset
{
	double fOffsetX;    //机械手中心与相机中心X方向偏差
	double fOffsetY;     //机械手中心与相机中心Y方向偏差
};

class CDlgTransferParamCoordCalib : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTransferParamCoordCalib)

public:
	CDlgTransferParamCoordCalib(CProcessCore* pProCore,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransferParamCoordCalib();
	void Cancel();
	void InitCtrl();

protected:
	virtual void OnCancel();
	virtual void PostNcDestroy();
	void Release();
// 对话框数据
	enum { IDD = IDD_DLG_TRANSFER_P_COORDCALIB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

private:
	void SetParentWnd();
	DECLARE_MESSAGE_MAP()

private:
	CProcessCore* m_pProCore;
	CDlgTransferParamLearn* m_pParent;

	double m_fTransferPickPosX;     //打点时转印电机X位置
	double m_fTransCamPosX;         //转印相机观测位置X

	std::vector<PickCamOffset> m_vecOffset;

	//最终计算的平均偏差结果
	double m_fOffsetX;   
	double m_fOffsetY;

	BOOL LocateCircle(const HObject* hoImage, const double &, const double&);   //定位圆心

public:
	CBmpBtn m_bmpBtn[6];
	static int m_iPressCount;
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedTransferPCSavecenterBtn();
	afx_msg void OnBnClickedTransferPCClibBtn();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedTransferPCCalibpickercamBtn();
};
