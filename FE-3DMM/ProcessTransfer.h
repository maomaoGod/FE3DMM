#pragma once
#include "TransferRotateCal.h"

class CFE3DMMDlg;
class CParamData;
class CProcessCore;

enum Mode {CONTINUE = 0, STEP}; 

class CProcessTransfer
{
public:
	CProcessTransfer(void);
	~CProcessTransfer(void);

	void SetProcessCore(CProcessCore* pProcesscore);
	void SetMainDlgPointer(CFE3DMMDlg* pDlg);		//设置主窗口指针
	void SetParamData(CParamData* pData);              //设置配置参数类指针

	void Init();
	void Release();
	void Run();										//自动运行
	void TransferPara();						//向下位机传递参数	
	void RestoreModel();					//导入匹配模板


	//获得转印电机X
	inline CCtrlMotor* GetMotorTransferX(){ return &m_MotorTransferX;}		
	//获得转印电机Z
	inline CCtrlMotor* GetMotorTransferZ(){ return &m_MotorTransferZ;};		
	//获得四轴电机X
	inline CCtrlMotor* GetMotorFourX()      { return &m_MotorFourX;}
	//获得四轴电机Z
	inline CCtrlMotor* GetMotorFourY()      { return &m_MotorFourY;}
	//获得四轴角度A
	inline CCtrlMotor* GetMotorFourAngleA(){ return &m_MotorFourAngleA;}
	//获得四轴角度B
	inline CCtrlMotor* GetMotorFourAngleB(){ return &m_MotorFourAngleB;}
	//获得四轴角度C
	inline CCtrlMotor* GetMotorFourAngleC(){ return &m_MotorFourAngleC;}

	//获得直线推杆电机1-9
	inline CCtrlMotor* GetMotorRod11()    { return &m_MotorRod11;}	                        
	inline CCtrlMotor* GetMotorRod12()    { return &m_MotorRod12;}	
	inline CCtrlMotor* GetMotorRod13()    { return &m_MotorRod13;}	
	inline CCtrlMotor* GetMotorRod21()    { return &m_MotorRod21;}	
	inline CCtrlMotor* GetMotorRod22()    { return &m_MotorRod22;}	
	inline CCtrlMotor* GetMotorRod23()    { return &m_MotorRod23;}	
	inline CCtrlMotor* GetMotorRod31()    { return &m_MotorRod31;}	
	inline CCtrlMotor* GetMotorRod32()    { return &m_MotorRod32;}	
	inline CCtrlMotor* GetMotorRod33()    { return &m_MotorRod33;}	

	//机械手膜的吸附
	inline CCtrlIO* GetIoVacAttach()    { return &m_IO_VacAttach;}
	//机械手膜的吹气
	inline CCtrlIO* GetIoVacBlow()       { return &m_IO_VacBlow;}
	//机械手九根推杆上吸附
	inline CCtrlIO* GetIoRodAttach()   {return &m_IO_RodAttach;}
	//拾取平台真空吸附
	inline CCtrlIO* GetIoPickPlatform() {return &m_IO_PickPlatform;}
	
	void SetRunMode(int Mode);


/************************************************************************/
/*  多种转印方式公用接口
/************************************************************************/
public:
	/*
	** 控制转印电机是否使能，避免意外
	*/
	void EnableTransMotor(const bool);

	/* 计算旋转信息 */
	BOOL CalRotateInfo();

	//加载模板
	BOOL LoadModel();

/************************************************************************/
/*  自动主动转印部分参数与接口函数
/************************************************************************/
	//public functions
public:
	//thread function
	static UINT InitiativeTransferThread(LPVOID lParam);        //主动变形方式转印主线程
	static UINT VariableInquireThread(LPVOID lParam);            //查询下位机变量线程
	static UINT AssistThread(LPVOID lParam);                             //辅助转印线程

	//操作函数
	BOOL ThreadInit();      //线程初始化
	BOOL ThreadExit();     //正常退出失败则强制结束线程

	BOOL Start();	
	BOOL PickAngleLocation();
	BOOL PickPosYLocation();
	BOOL PickPosXLocation();
	BOOL Pick();
	
	BOOL HandTransform();
	BOOL PlaceLocation();
	BOOL Place();
    BOOL Stop();
	

private:
	//Thread Pointer
	CWinThread* m_pInitiativeTransferThread;         //主动变形转印线程指针	
	CWinThread* m_pVariableInquireThread;
	CWinThread* m_pAssistThread;

	/***************主线程事件***************/
	
	//退出事件
	//主线程开始事件
	//角度定位事件
	//Y向定位
	//X定位
	//贴装定位
	
	HANDLE m_hTransfer[6];

	/************变量查询事件**************/
	//退出事件
	//到达下视相机采图位置
	//可以进行九轴变形
	//到达上视相机采图位置，且九轴完成变形	
	HANDLE m_hVariableInquire[4];

	/************辅助线程事件*************/
	//退出事件
	//九轴旋转信息计算
	//九轴变形	
	HANDLE m_hAssist[3];

	//旋转计算
	CTransferRotateCal m_RotateCal;

public:
	//Mark Varible
	bool m_BeModelLoad;         //模板加载是否完成
	bool m_BeAdjustAngle;
	bool m_BeAdjustPosY;


/************************************************************************/
/*  被动转印部分参数与接口函数
/************************************************************************/
public:

	static UINT PassitivityTransferThread(LPVOID lParam);      //被动变形方式转印主线程

private:
	CWinThread* m_pPassitivityTransferThread;       //被动变形线程指针


/************************************************************************/
/* 供单步运行调用的接口函数
/************************************************************************/
public:

	/*
	** 单步运行初始化函数
	*/
	void StepRunInit();


	/*
	** 单步运行开始角度调整，接口函数
	*/
	BOOL StartAngleAdjust();   


	/*
	** 单步运行结束角度调整，接口函数
	*/
	BOOL EndAngleAdjust();


	/*
	** 单步运行开始Y方向位置调整，接口函数
	*/
	BOOL StartYAdjust();


	/*
	** 单步运行结束Y方向位置调整，接口函数
	*/
	BOOL EndYAdjust();


	/*
	** 单步调试运行辅助线程函数
	*/
	static UINT StepAdjustThread(LPVOID lParam);      //单步运行过程中，手动调整偏差线程


/************************************************************************/
/*  单步运行相关私有成员变量
/************************************************************************/
private:
	/*
	** 控制单步运行调整线程是否退出的控制变量
	*/
	bool m_bStepAdjustRun;


	/*
	*单步调试的辅助线程
	*/
	CWinThread* m_pStepAdjustThread;   /*角度调整线程*/


	/*
	** 单步运行事件句柄数组
	*/
	HANDLE m_hStepAdjust[3];



private:
	CProcessCore       *m_pProcessCore;
	CFE3DMMDlg		*m_pMainDlg;				    //主对话框指针
	CParamData			*m_pParamData;				//配置参数类指针
	Mode                      m_RunMode;                   //运行模式，单步还是连续


	//电机
	CCtrlMotor			m_MotorTransferX;					//转印电机X
	CCtrlMotor			m_MotorTransferZ;					//转印电机Z
	CCtrlMotor           m_MotorFourX;
	CCtrlMotor           m_MotorFourY;
	CCtrlMotor           m_MotorFourAngleA;           //绕X轴旋转
	CCtrlMotor           m_MotorFourAngleB;           //绕Y轴旋转
	CCtrlMotor           m_MotorFourAngleC;           //绕Z轴旋转
	/*********直线推杆电机分布**********/
	/*11 12 13*/
	/*21 22 23*/
	/*31 32 33*/
	CCtrlMotor           m_MotorRod11;                      //直线推杆11
	CCtrlMotor           m_MotorRod12;  
	CCtrlMotor           m_MotorRod13;  
	CCtrlMotor           m_MotorRod21;  
	CCtrlMotor           m_MotorRod22;  
	CCtrlMotor           m_MotorRod23;  
	CCtrlMotor           m_MotorRod31;  
	CCtrlMotor           m_MotorRod32;  
	CCtrlMotor           m_MotorRod33;  

	// 下位机转印自动程序
	CCtrlProg          m_prog1;                       //回零程序，标志位P100，开始为1，结束为0

	//IO
	CCtrlIO				m_IO_VacAttach;				//真空吸附
	CCtrlIO				m_IO_VacBlow;					//真空快排
	CCtrlIO               m_IO_RodAttach;
	CCtrlIO               m_IO_PickPlatform;

	/*位置量*/
	CCtrlParam            m_P301;		//P301转印机械手X11平面采图位置（学习）
	CCtrlParam			m_P302;		//P302转印机械手Z12平面采图位置（学习）
	CCtrlParam			m_P303;		//P303转印机械手X11拾取位置
	CCtrlParam			m_P304;	    //P304转印机械手Z12拾取位置
	CCtrlParam			m_P305;		//P305转印机械手Z12拾取后上升的位置（学习）
	CCtrlParam			m_P306;		//P306转印机械手Z11曲面状态采图位置（学习）
	CCtrlParam			m_P307;		//P307转印机械手Z12曲面状态采图位置（学习）
	CCtrlParam			m_P308;		//P308五轴机械臂X1曲面状态采图位置（学习）
	CCtrlParam			m_P309;		//P309五轴机械臂Y2曲面状态采图位置（学习）
	CCtrlParam			m_P310;		//P310转印机械手Z12采图完成后上升位置（学习）

	/*如果旋转采用计算值*/
	CCtrlParam			m_P311;		//P311五轴机械臂X1贴装位置
	CCtrlParam			m_P312;		//P312五轴机械臂Y2贴装位置
	CCtrlParam			m_P313;		//P313五轴机械臂A旋转角度
	CCtrlParam			m_P314;		//P314五轴机械臂B旋转角度
	CCtrlParam			m_P315;		//P315五轴机械臂C旋转角度

	/*如果旋转采用UG模拟值*/
	CCtrlParam			m_P316;		//P316五轴X1位置
	CCtrlParam			m_P317;		//P317五轴Y2位置
	CCtrlParam			m_P318;		//P318五轴A位置
	CCtrlParam			m_P319;		//P319五轴B位置
	CCtrlParam			m_P320;		//P320贴装是机械臂Z12位置

	/*到位信息标志量*/
	CCtrlParam			m_P350;		//P350串行过程中到位标志量
	CCtrlParam			m_P351;		//P351九个机械手到位标志量

	/*速度量*/
	CCtrlParam			m_P360;		//P360转印机械手X11速度
	CCtrlParam			m_P361;		//P361转印机械手Z12速度
};
