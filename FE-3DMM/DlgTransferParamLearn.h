#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "DlgTransferParamCoordCalib.h"

using HalconCpp::HObject;


// CDlgTransferParamLearn 对话框
class CDlgTransferParamLearn : public CDialog
{
	DECLARE_DYNAMIC(CDlgTransferParamLearn)

	//public class members
public:
	CDlgTransferParamLearn(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransferParamLearn();

    // 对话框数据
	enum { IDD = IDD_DLG_TRANSFER_PARAM };

	// 真空单选按钮
	enum {FILMNEGETIVE = 0, FILEPOSITIVE, RODVACUUM, PLATVACUUM};

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();

	//protect class members
protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);     // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
	virtual void PostNcDestroy();
	virtual void OnCancel();
	

	//private class members
private:
	void Release();							//释放本窗口中其他new堆内存
	void InitWindowHandle();		//初始化Pic控件显示窗口
	void RefreshLocalRegion(const int & ID);//重绘控件局部

	//public class variable
public:
	CXPGroupBox			m_GB1;   //控件变量
	CXPGroupBox			m_GB2;	//控件变量
	CXPGroupBox			m_GB3;
	CBmpBtn				    m_bmpBtn[27];
	CComboBox             m_cPISizeComBox;

	CmySliderControl    m_cSliderPace;
	CEdit m_cEditPace;
	CSpinButtonCtrl m_cSpinPace;

	CEdit                          m_cEditVacuum;
	CSpinButtonCtrl      m_cSpinVacuum;

	CmySliderControl  m_cSldV;
	CEdit                         m_cEditV;
	CSpinButtonCtrl     m_cSpinV;

	CmySliderControl m_cSldF;
	CEdit                        m_cEditF;
	CSpinButtonCtrl    m_cSpinF;

	//private class variable
private:
	bool                           m_bFilmNegOpen;     //真空开启标志
	bool                           m_bFilmPosiOpen;
	bool                           m_bRodVacuumOpen;
	bool                           m_bPlatVacuumOpen;

	bool			                m_bElecStaticOpen;   //真空开启标志lecStaticOpen
	CProcessCore*		    m_pProCore;  //主操作类指针
	
	int m_iTransferType;             //转印方式单选按钮绑定的int值
	int m_iPushRodNum;            //直线推杆单选按钮绑定的int值           
	int m_iRadioVacuum;            //正压负压选择单选按钮
	int m_iRadioCamera;             //相机单选按钮绑定的int值

	bool   m_bIsContinueSnap;
	int m_iPace;           //电机运动步长

	//图像处理相关变量
	HObject m_hoImage;

	HTuple		m_windowHandle_Pic;	//Pic控件关联的Halcon窗口句柄
	Size				m_winSize_Pic;					//Pic窗口大小

	//child window
	CDlgTransferParamCoordCalib* m_pDlgCoordCalib;

public:
	//消息响应函数
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);	
	afx_msg void OnBnClickedTransferPVacuumOpenBtn();
	afx_msg void OnBnClickedTransferPElecstaticOpenBtn();
	afx_msg void OnBnClickedTransferPXlBtn();
	afx_msg void OnBnClickedTransferPPickupviewBtn();
	afx_msg void OnBnClickedTransferPXrBtn();
	afx_msg void OnBnClickedTransferPZupBtn();
	afx_msg void OnBnClickedTransferPZdownBtn();
	afx_msg void OnBnClickedTransferPPushrodleftBtn();
	afx_msg void OnBnClickedTransferPPushrodrightBtn();
	afx_msg void OnBnClickedTransferPMecharmpickBtn();
	afx_msg void OnBnClickedTransferPCameraTransDownRadio();
	afx_msg void OnBnClickedTransferPCameraTransUpRadio();
	afx_msg void OnEnChangeTransferPVacuumEdit();
	afx_msg void OnDeltaposTransferPVacuumSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureTransferPVoltageSlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeTransferPVoltageEdit();
	afx_msg void OnDeltaposTransferPVoltageSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureTransferPFrequencySlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeTransferPFrequencyEdit();
	afx_msg void OnDeltaposTransferPFrequencySpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedTransferPVacuumSaveBtn();
	afx_msg void OnBnClickedTransferPActivemodeRadio();
	afx_msg void OnBnClickedTransferPPassivemodeRadio();
	afx_msg void OnBnClickedTransferPUpviewBtn();
	afx_msg void OnBnClickedTransferPFouraxleupviewBtn();
	afx_msg void OnBnClickedTransferPCoordcalibBtn();
	afx_msg void OnBnClickedTransferPNewLearnposBtn();
	afx_msg void OnNMReleasedcaptureTransferPPaceSlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposTransferPPaceSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeTransferPPaceEdit();
	afx_msg void OnBnClickedTransferPVacuumCloseBtn();
	afx_msg void OnBnClickedTransferPVacuumnegRadio();
	afx_msg void OnBnClickedTransferPVacuumposiRadio();
	afx_msg void OnBnClickedTransferPVacuumrodRadio();
	afx_msg void OnBnClickedTransferPVacuumplatRadio();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

};
