#pragma once
#include "afxcmn.h"
#include "DlgTransferManualNew.h"
#include "DlgTransferManualAdvanced.h"

// CDlgTransferManual 对话框

class CDlgTransferManual : public CDialog
{
	DECLARE_DYNAMIC(CDlgTransferManual)



/************************************************ public functions ***********************************************/
public:
	// 对话框ID
	enum { IDD = IDD_DLG_TRANSFER_MANUAL };

	/*
	** @Name: CDlgTransferManual
	** @Function: 构造函数
	** @Input: 主操作类指针，默认参数为空；父窗口指针，默认参数为NULL
	** @Output: NULL
	*/
	CDlgTransferManual(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数

	/*
	** @Function: 虚析构函数
	*/
	virtual ~CDlgTransferManual();


	/*
	** @name: Cancel
	** @function: 覆盖Cancel函数销毁窗口和子窗口
	** @ Input: NULL
	** @Output: NULL
	*/
	void Cancel();   //销毁窗口及子窗口


	/*
	** @name: InitDlgCtrl
	** @Function: 初始化控件
	** @Input: NULL
	** @Output: NULL
	*/
	void InitDlgCtrl();

	/*
	** @name: UpdateList
	** @Function: 添加内容后刷新list控件显示
	** @Input: NULL
	** @Output: NULL
	*/
	void UpdateList();


	int GetSelProduct();


	/*
	** @name: ReadCtrlValue
	** @Function: 读取EDIT控件中的X、Y、Angle
	** @Input: NULL
	** @Output: NULL
	*/
	void ReadCtrlValue();



/********************************************************* protected functions *****************************************************/
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();





/********************************************************* private functions *******************************************************/
private:

		void InitWindowHandle();		//初始化Pic控件显示窗口

	/*
	** @name: Release
	** @Function: 手动释放该类中在堆上分配的内存
	** @Input: NULL
	** @Output: NULL
	*/
	void Release();        //释放本窗口中其他堆内存
	


	/*
	** @name: StepRun
	** @Function: 主动变形情况下单步运行函数
	** @Input: NULL
	** @Output: NULL
	*/
	void StepRun();



	/*
	** @name: PositiveStepRun
	** @Function: 主动变形情况下单步运行函数
	** @Input: NULL
	** @Output: NULL
	*/
	void PositiveStepRun();



	/*
	** @name: PositiveStepRun
	** @Function: 被动变形情况下单步运行函数
	** @Input: NULL
	** @Output: NULL
	*/
	void NegtiveStepRun();




	/*
	** @name: StepRunEnableCtrl
	** @Function: 单步运行情况下，使能控件管理，防止运行过程中，转印方式发生切换或者自动被开启
	** @Input: bool变量，true表示使能使用，false表示使不能使用
	** @Output: NULL
	*/
	void StepRunEnableCtrl(bool);



	/*主动转印，单步运行相关函数*/
	BOOL PositiveStep1();
	BOOL PositiveStep2();
	BOOL PositiveStep3();
	BOOL PositiveStep4();
	BOOL PositiveStep5();
	BOOL PositiveStep6();
	BOOL PositiveStep7();
	BOOL PositiveStep8();
	BOOL PositiveStep9();
	BOOL PositiveStep10();
	BOOL PositiveStep11();
	BOOL PositiveStep12();
	BOOL PositiveStep13();
	BOOL PositiveStep14();

	/*
	** @name: GoHome
	** @Function: 转印模块电机回零
	** @Input: NULL
	** @Output: NULL
	*/
	BOOL GoHome();


	/*
	** @name: UpDateTips
	** @Function: 更新提示信息
	** @Input: NULL
	** @Output: NULL
	*/
	BOOL UpDateTips(int num);


	/*
	** @name: UpDateTips
	** @Function: 刷新设为透明模式的静态文本控件，用于更新显示信息后使用
	** @Input: NULL
	** @Output: NULL
	*/
	void RefreshStatic();






/**************************************************************** private members **********************************************************/
private:

	/* 用于提示的枚举常量 */
	enum Tips { GO_HOME, TO_TRANSCAM_VIEW, ANGLE_LOCA, POSY_LOCA, TO_PICK_POS, PICK, SUCTION, 
		ROD_RUN,  TO_UPCAM_VIEW, PLACE_LOCA, TO_PLACE_POSE, SURFACE_ROTATE, PLACE, BLOW, END, INIT };


	/* 枚举代替宏定义，对单步调试步数的代替 */
	enum Step { STEP1 = 1, STEP2, STEP3, STEP4, STEP5, STEP6, STEP7, STEP8, STEP9, STEP10, STEP11, STEP12, STEP13, STEP14};


	CProcessCore     *m_pProCore;      //主操作类指针
	CXPGroupBox			m_GB1;
	CXPGroupBox			m_GB2;
	CXPGroupBox			m_GB3;
	CXPGroupBox			m_GB4;

	CBmpBtn               m_bmpBtn[9];
	CListCtrlCl             m_cListObject;

	//CDlgTransferManualNew*           m_DlgNewObject;                 //新建对象窗口
	//CDlgTransferManualAdvanced* m_DlgAdvancedSetting;      //高级设置窗口

	//控件关联变量
	int m_cTransTypeRadio;   //转印方式单选按钮绑定参数

	int m_cCamNum;                //相机单选按钮绑定参数

	CString m_strTips;              //转印提示文本信息
	
	static int m_NextBtnCount;     //下一步按钮计数

	/**单步运行相关变量**/
	static int m_iClickNum;         //按钮点击次数



	//图像相关变量
	HalconCpp::HObject m_hoImage;

	HTuple	m_windowHandle_Pic;	//Pic控件关联的Halcon窗口句柄
	Size			m_winSize_Pic;					//Pic窗口大小




/************************************************************** respond functions *******************************************************/
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnChangeTips(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedTransferMNewBtn();
	afx_msg void OnBnClickedTransferMAdvancedBtn();
	afx_msg void OnBnClickedTransferMDeleteBtn();
    afx_msg void OnBnClickedTransferMStartBtn();
	afx_msg void OnBnClickedTransferMNextBtn();	
	afx_msg void OnBnClickedTransferMStepdebugBtn();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedTransferMCameraTransDownRadio();
	afx_msg void OnBnClickedTransferMCameraTransUpRadio();
};


