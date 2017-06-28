#include "StdAfx.h"
#include "ProcessCore.h"
#include "FE-3DMMDlg.h"


CProcessCore::CProcessCore(void)
{
	m_pMainDlg	= NULL;
}


CProcessCore::~CProcessCore(void)
{
	Release();
}


CProcess3DMeasure* CProcessCore::GetPro3DMeasure()
{
	return &m_Pro3DMeasure;
}


CProcessLaserStrip* CProcessCore::GetProLaserStrip()
{
	return &m_ProLaserStrip;
}


CProcessTransfer* CProcessCore::GetProTransfer()
{
	return &m_ProTransfer;
}


CProcessPrint* CProcessCore::GetProPrint()
{
	return &m_ProPrint;
}


void CProcessCore::SetMainDlgPointer(CFE3DMMDlg* pDlg)
{
	m_pMainDlg = pDlg;
}


CParamData* CProcessCore::GetParamData()	
{
	return &m_ParamData;
}


void CProcessCore::Init()
{
	//加载配置参数
	m_ParamData.LoadMeasurePa();
	m_ParamData.LoadLaserStripPa();
	m_ParamData.LoadTransferPa();
	m_ParamData.LoadPrintPa();
	m_ParamData.LoadCameraPa();
	m_Pro3DMeasure.SetParamData(&m_ParamData);
	m_ProLaserStrip.SetParamData(&m_ParamData);
	m_ProTransfer.SetParamData(&m_ParamData);
	m_ProPrint.SetParamData(&m_ParamData);

	m_Pro3DMeasure.SetMainDlgPointer(m_pMainDlg);
	m_ProLaserStrip.SetMainDlgPointer(m_pMainDlg);
	m_ProTransfer.SetMainDlgPointer(m_pMainDlg);
	m_ProPrint.SetMainDlgPointer(m_pMainDlg);
	m_Pro3DMeasure.Init();
	m_ProLaserStrip.Init();
	m_ProTransfer.Init();
	m_ProPrint.Init();

	//相机初始化
	m_CameraLaserView.Init(m_ParamData.GetParamCamera()->strCamNameLaser);
	m_CameraTransDown.Init(m_ParamData.GetParamCamera()->strCamNameTransDown);
	m_CameraTransUp.Init(m_ParamData.GetParamCamera()->strCamNameTransUp);
	m_CameraPrintLoc.Init(m_ParamData.GetParamCamera()->strCamNamePrintLoc);
 	m_CameraPrintHoriz.Init(m_ParamData.GetParamCamera()->strCamNamePrintHoriz);
 	m_CameraPrintAskant.Init(m_ParamData.GetParamCamera()->strCamNamePrintAskant);

	//初始化控制卡
// 	m_umacCard.ConfigCard(0);       //by jsb
// 	m_umacCard.ConnectPmacCard();
// 	//初始化电机
// 	m_MotorX.ConfigMotor(0, 1, "X轴电机");					
// 	m_MotorY.ConfigMotor(0, 2, "Y轴电机");					
// 	m_MotorZ.ConfigMotor(0, 3, "Z轴电机");	
// 	m_MotorA.ConfigMotor(0, 4, "A轴电机");					
// 	m_MotorC.ConfigMotor(0, 5, "C轴电机");	
// 	#ifndef FE_DEBUG_OFFLINE
// 		m_MotorX.Enable();
// 		m_MotorY.Enable();
// 		m_MotorZ.Enable();
// 		m_MotorA.Enable();
// 		m_MotorC.Enable();
// 	#endif
}


void CProcessCore::Release()
{
	m_CameraLaserView.Exit();
	m_CameraTransUp.Exit();
	m_CameraTransDown.Exit();
	m_CameraPrintLoc.Exit();
	m_CameraPrintHoriz.Exit();
	m_CameraPrintAskant.Exit();
}


PylonCamera* CProcessCore::GetCameraLaserView()
{
	return &m_CameraLaserView;
}


PylonCamera* CProcessCore::GetCameraTransUp()
{
	return &m_CameraTransUp;
}


PylonCamera* CProcessCore::GetCameraTransDown()
{
	return &m_CameraTransDown;
}


PylonCamera* CProcessCore::GetCameraPrintLoc()
{
	return &m_CameraPrintLoc;
}


PylonCamera* CProcessCore::GetCameraPrintHoriz()
{
	return &m_CameraPrintHoriz;
}


PylonCamera* CProcessCore::GetCameraPrintAskant()
{
	return &m_CameraPrintAskant;
}


void CProcessCore::SetShowInfo(const CameraType &camtype, const HTuple &winHandle, const Size &winSize)
{
	m_showinfo.cameratype = camtype;
	m_showinfo.windowHandle = winHandle;
	m_showinfo.windowSize = winSize;
}


SHOWINFO CProcessCore::GetShowInfo()
{
	return m_showinfo;
}


void CProcessCore::SwitchCamera(const CameraType camtype)
{
	switch(camtype)
	{
	case LASER_VIEW:
		m_CameraLaserView.StartGrab();
		m_CameraTransUp.StopGrab();
		m_CameraTransDown.StopGrab();
		m_CameraPrintLoc.StopGrab();
		m_CameraPrintHoriz.StopGrab();
		m_CameraPrintAskant.StopGrab();
		break;
	case TRANS_UP:
		m_CameraLaserView.StopGrab();
		m_CameraTransUp.StartGrab();
		m_CameraTransDown.StopGrab();
		m_CameraPrintLoc.StopGrab();
		m_CameraPrintHoriz.StopGrab();
		m_CameraPrintAskant.StopGrab();
		break;
	case TRANS_DOWN:
		m_CameraLaserView.StopGrab();
		m_CameraTransUp.StopGrab();
		m_CameraTransDown.StartGrab();
		m_CameraPrintLoc.StopGrab();
		m_CameraPrintHoriz.StopGrab();
		m_CameraPrintAskant.StopGrab();		
		break;
	case PRINT_LOCAL:
		m_CameraLaserView.StopGrab();
		m_CameraTransUp.StopGrab();
		m_CameraTransDown.StopGrab();
		m_CameraPrintLoc.StartGrab();
		m_CameraPrintHoriz.StopGrab();
		m_CameraPrintAskant.StopGrab();
		break;
	case PRINT_HORIZONTAL:
		m_CameraLaserView.StopGrab();
		m_CameraTransUp.StopGrab();
		m_CameraTransDown.StopGrab();
		m_CameraPrintLoc.StopGrab();
		m_CameraPrintHoriz.StartGrab();
		m_CameraPrintAskant.StopGrab();
		break;
	case PRINT_ASKANT:
		m_CameraLaserView.StopGrab();
		m_CameraTransUp.StopGrab();
		m_CameraTransDown.StopGrab();
		m_CameraPrintLoc.StopGrab();
		m_CameraPrintHoriz.StopGrab();
		m_CameraPrintAskant.StartGrab();
		break;
	default:
		break;
	}
}


//by jsb
// CCtrlMotor* CProcessCore::GetMotorX()
// {
// 	return &m_MotorX;
// }
// 
// 
// CCtrlMotor* CProcessCore::GetMotorY()
// {
// 	return &m_MotorY;
// }
// 
// 
// CCtrlMotor* CProcessCore::GetMotorZ()
// {
// 	return &m_MotorZ;
// }
// 
// 
// CCtrlMotor* CProcessCore::GetMotorA()
// {
// 	return &m_MotorA;
// }
// 
// 
// CCtrlMotor* CProcessCore::GetMotorC()
// {
// 	return &m_MotorC;
// }