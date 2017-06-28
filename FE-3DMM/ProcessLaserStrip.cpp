#include "StdAfx.h"
#include "ProcessLaserStrip.h"
#include "FE-3DMMDlg.h"
#include "ParamData.h"


CProcessLaserStrip::CProcessLaserStrip(void)
{
	m_pMainDlg = NULL;
}


CProcessLaserStrip::~CProcessLaserStrip(void)
{
	Release();
}


void CProcessLaserStrip::SetMainDlgPointer(CFE3DMMDlg* pDlg)
{
	m_pMainDlg = pDlg;
}


void CProcessLaserStrip::Init()
{

	//初始化剥离观察相机
// 	m_CameraView.SetCameraInfo("GigEVision", "dianjiao");
// 	m_CameraView.SetCameraType(DISP);
// 	m_CameraView.Init();
// 	m_CameraView.StartCapture(); 

	//电机初始化
// 	m_MotorLaserStripX.ConfigMotor(0, 9, "激光剥离X");
// 	m_MotorLaserStripY.ConfigMotor(0, 10, "激光剥离Y");
// 	m_MotorLaserStripX.Enable();
// 	m_MotorLaserStripY.Enable();

// 2017.03.23 Edited By Zhoulaoboyang
	//下位机自动程序
	m_Prog200.ConfigProg(0,0,200,"行扫描自动程序");

	//P变量
	m_P200.ConfigParam(0,"P200","程序开启标志");
	m_P201.ConfigParam(0,"P201","扫描长度L");
	m_P202.ConfigParam(0,"P202","扫描间距D");
	m_P203.ConfigParam(0,"P203","扫描速度Vl");
	m_P204.ConfigParam(0,"P204","换行速度Vd");
	m_P205.ConfigParam(0,"P205","扫描列数");
//
}


void CProcessLaserStrip::Release()
{

}


void CProcessLaserStrip::Home()
{
// 	m_MotorLaserStripX.Home();
// 	m_MotorLaserStripY.Home();
}


//2017.03.23 Edited By Zhoulaoboyang
void CProcessLaserStrip::TransferPara(double ScanLen,double ScanSpace,double ScanSpeed,double TransRowSpeed,int ScanNum)
{
	m_P201.SetParamValue(ScanLen);
	m_P202.SetParamValue(ScanSpace);
	m_P203.SetParamValue(ScanSpeed);
	m_P204.SetParamValue(TransRowSpeed);
	m_P205.SetParamValue(ScanNum);
}

bool CProcessLaserStrip::GetProgStatus()
{
	if(m_P200.GetParamValue() == 0)
		return FALSE;
	else 
		return TRUE;
}

void CProcessLaserStrip::RunProgram()
{
	m_Prog200.Run();
}

void CProcessLaserStrip::SetParamData(CParamData* pData)
{
	m_pParamData = pData;
}


// CCtrlMotor* CProcessLaserStrip::GetMotorLaserStripX()
// {
// 	return &m_MotorLaserStripX;
// }


// CCtrlMotor* CProcessLaserStrip::GetMotorLaserStripY()
// {
// 	return &m_MotorLaserStripY;
// }

