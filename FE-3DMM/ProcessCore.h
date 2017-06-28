#pragma once
#include "./Common/Vision/PylonCamera.h"
#include "./Common/Vision/ImageOperate.h"
#include "./Common/UmacControl/CtrlCard.h"    //by jsb
#include "Process3DMeasure.h"
#include "ProcessLaserStrip.h"
#include "ProcessTransfer.h"
#include "ProcessPrint.h"
#include "ParamData.h"
class CFE3DMMDlg;


typedef struct st_SHOWINFO
{
	CameraType  cameratype;				//显示的相机类型
	HTuple			 windowHandle;		//显示的Halcon窗口句柄
	Size					 windowSize;				//显示窗口的大小
}SHOWINFO;


class CProcessCore
{
public:
	CProcessCore(void);
	~CProcessCore(void);
	void Init();
	void Release();
	void SetMainDlgPointer(CFE3DMMDlg* pDlg);			//设置主窗口指针
	CProcess3DMeasure* GetPro3DMeasure();				//获得测量操作类指针
	CProcessLaserStrip* GetProLaserStrip();					//获得剥离操作类指针
	CProcessTransfer* GetProTransfer();							//获得转印操作类指针
	CProcessPrint* GetProPrint();										//获得打印操作类指针
	CParamData* GetParamData();										//获取配置参数类指针

	PylonCamera* GetCameraLaserView();						//获取剥离观察相机指针
	PylonCamera* GetCameraTransUp();							//获取转印上视相机指针
	PylonCamera* GetCameraTransDown();						//获取转印下视相机指针
	PylonCamera* GetCameraPrintLoc();							//获取打印定位相机指针
	PylonCamera* GetCameraPrintHoriz();						//获取打印水平观测相机指针
	PylonCamera* GetCameraPrintAskant();						//获取打印斜视观测相机指针
	void SetShowInfo(const CameraType &camtype, const HTuple &winHandle, const Size &winSize);
	SHOWINFO GetShowInfo();
	void SwitchCamera(const CameraType camtype);	//切换相机

// 	CCtrlMotor* GetMotorX();											//获得电机X
// 	CCtrlMotor* GetMotorY();											//获得电机Y
// 	CCtrlMotor* GetMotorZ();											//获得电机Z
// 	CCtrlMotor* GetMotorA();										//获得电机A
// 	CCtrlMotor* GetMotorC();											//获得电机C

private:
	CFE3DMMDlg*					m_pMainDlg;						//主对话框指针
	CProcess3DMeasure		m_Pro3DMeasure;				//测量操作类对象
	CProcessLaserStrip			m_ProLaserStrip;					//剥离操作类对象
	CProcessTransfer				m_ProTransfer;						//转印操作类对象
	CProcessPrint					m_ProPrint;							//打印操作类对象
	CParamData						m_ParamData;						//配置参数对象
	SHOWINFO						m_showinfo;							//Pic控件显示信息
	PylonCamera						m_CameraLaserView;			//剥离观察相机
	PylonCamera						m_CameraTransUp;				//转印上视相机
	PylonCamera						m_CameraTransDown;		//转印下视相机
	PylonCamera						m_CameraPrintLoc;				//打印定位相机
	PylonCamera						m_CameraPrintHoriz;			//打印水平观测相机
	PylonCamera						m_CameraPrintAskant;		//打印斜视观测相机

//     CCtrlCard							m_umacCard;					//umac控制卡     //by jsb
// 	CCtrlMotor						m_MotorX;						//电机X
// 	CCtrlMotor						m_MotorY;						//电机Y
// 	CCtrlMotor						m_MotorZ;						//电机Z
// 	CCtrlMotor						m_MotorA;						//电机A
// 	CCtrlMotor						m_MotorC;						//电机C

public:
	//报警相关的P变量
// 	CCtrlParam						m_P3006;							//红灯
// 	CCtrlParam						m_P3007;							//黄灯
// 	CCtrlParam						m_P3008;							//绿灯
// 	CCtrlParam						m_P200;								//急停被按下
// 	CCtrlParam						m_P2001;							//设备故障
// 	CCtrlParam						m_M130;							//X轴电机正限位
// 	CCtrlParam						m_M131;							//X轴电机负限位
// 	CCtrlParam						m_M132;							//Y轴电机正限位
// 	CCtrlParam						m_M133;							//Y轴电机负限位
// 	CCtrlParam						m_M134;							//Z轴电机正限位
// 	CCtrlParam						m_M135;							//Z轴电机负限位
// 	CCtrlParam						m_M136;							//A轴电机正限位
// 	CCtrlParam						m_M137;							//A轴电机负限位
// 	CCtrlParam						m_M138;							//C轴电机正限位
// 	CCtrlParam						m_M139;							//C轴电机负限位
	
};

