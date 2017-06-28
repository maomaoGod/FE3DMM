#include "StdAfx.h"
#include "ProcessPrint.h"
#include "FE-3DMMDlg.h"
#include "ParamData.h"


CProcessPrint::CProcessPrint(void)
{
	m_pMainDlg				= NULL;
	m_pThreadPrint			= NULL;
	m_bPrintLinesFlag		= false;
	m_bDownProgFlag			= false;
	m_bThreadExit			= false;
	m_bRemainDownLoadFlag	= false;
	m_nDownLoadCount		= 0;
	m_bIsLinesPrint			= false;
}


CProcessPrint::~CProcessPrint(void)
{
	Release();
}


void CProcessPrint::SetMainDlgPointer(CFE3DMMDlg* pDlg)
{
	m_pMainDlg = pDlg;
}


void CProcessPrint::Init()
{
// 	//初始化函数发生器
// 	if (false == m_JetAglientFunc.Connect())
// 	{
// 		AfxMessageBox("函数发生器连接失败!");
// 	}
// 	//初始化流量泵
// 	if (FALSE == m_JetHarvardPump.Init(11))
// 	{
// 		AfxMessageBox("流量泵初始化失败!");
// 	}
// 	//初始化气压调节
// 	if (TRUE == m_JetAirPress.Init(1))
// 	{
// 		m_JetAirPress.SetAnalogInputType(3);
// 	}
// 	else
// 	{
// 		AfxMessageBox("气压调节初始化失败!");
// 	}


	//初始化墨滴观测相机
// 	m_CameraWatch.SetCameraInfo("GigEVision", "dianjiao");
// 	m_CameraWatch.SetCameraType(DISP);
// 	m_CameraWatch.Init();
// 	m_CameraWatch.StartCapture(); 

	//初始化打印定位相机
// 	m_CameraLocate.SetCameraInfo("GigEVision", "dianjiao");
// 	m_CameraLocate.SetCameraType(DISP);
// 	m_CameraLocate.Init();
// 	m_CameraLocate.StartCapture(); 

	//P变量
// 	m_P400.ConfigParam(0,"P400","直线条数");	
// 	m_P401.ConfigParam(0,"P401","直线开始点X");	
// 	m_P402.ConfigParam(0,"P402","直线开始点Y");	
// 	m_P403.ConfigParam(0,"P403","直线结束点X");	
// 	m_P404.ConfigParam(0,"P404","直线结束点Y");	
// 	m_P405.ConfigParam(0,"P405","直线角度A");
// 	m_P406.ConfigParam(0,"P406","直线角度C");
// 	m_P407.ConfigParam(0,"P407","直线打印状态");
// 	m_P408.ConfigParam(0,"P408","直线打印速度");
//	m_P409.ConfigParam(0,"P409","监测下位机Prog运行");

//  	//下位机自动程序
//  	m_Prog4.ConfigProg(0, 1, 4, "直线打印自动程序");


 	//IO
// 	m_IO_m7912.ConfigIO(0,"M7912","贴装真空吸附");		//贴装真空吸附（on/off开关）
// 	m_IO_m7913.ConfigIO(0,"M7913","贴装真空快排");		//贴装真空快排

	//创建旋转缓冲区
// 	CCtrlCommand cmd(0);
// 	cmd.GiveCommand("CLOSE");
// 	cmd.GiveCommand("&1A");
// 	cmd.GiveCommand("END GATHER");						//结束数据采集缓冲区，以免冲突
// 	cmd.GiveCommand("DELETE GATHER");					//删除数据采集缓冲区
// 	cmd.GiveCommand("&1 DELETE ROT");					//删除&1其余的旋转缓冲区
// 	cmd.GiveCommand("&1 DEFINE ROT 40000");				//定义旋转缓冲区大小为40000
// 	cmd.GiveCommand("&1 BO");							//准备运行旋转缓冲区命令
// 	cmd.GiveCommand("&1 CLEAR");						//清空里面的内容	
// 	cmd.GiveCommand("&1 R");							//运行

	m_pThreadPrint = AfxBeginThread(PrintThreadProc, this);
	ASSERT(m_pThreadPrint);

	m_hEventPrint[0] = CreateEventA(NULL, TRUE, FALSE, NULL);  //直线打印的事件
	m_hEventPrint[1] = CreateEventA(NULL, TRUE, FALSE, NULL);  //整体打印程序的下载事件
	m_hEventPrint[2] = CreateEventA(NULL, TRUE, FALSE, NULL);  //线程退出的事件

}


void CProcessPrint::Release()
{
// 	if (m_JetAglientFunc.IsDeviceConnect())
// 	{
// 		m_JetAglientFunc.SetAmplitude(1);
// 		m_JetAglientFunc.SetOffset(1);
// 		m_JetAglientFunc.SetOutput(FALSE);
// 		m_JetAglientFunc.Disconnect();
// 	}  
// 
// 	if (m_JetHarvardPump.IsHarvardOpen())
// 	{
// 		m_JetHarvardPump.Stop();
// 		m_JetHarvardPump.CloseHarvardPump();
// 	}
// 
// 	m_JetAirPress.UnInit();
}


void CProcessPrint::Home()
{

}


void CProcessPrint::SetParamData(CParamData* pData)
{
	m_pParamData = pData;
}


UINT CProcessPrint::PrintThreadProc(LPVOID pVoid)
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	CProcessPrint* pThis = (CProcessPrint*)pVoid;

	while(1)
	{
		switch (WaitForMultipleObjects(3, pThis->m_hEventPrint, FALSE, INFINITE))
		{
		case WAIT_OBJECT_0:
			ResetEvent(pThis->m_hEventPrint[0]);
			/////电压开启
			pThis->StraightLinePrint();
			/////电压关闭
			break;

		case WAIT_OBJECT_0+1:
			ResetEvent(pThis->m_hEventPrint[1]);
			pThis->DownLoadProg(pThis->m_gcodeAnalysis.m_vecStrGCode, pThis->m_nDownLoadCount);		
			break;

		case WAIT_OBJECT_0+2:
			ResetEvent(pThis->m_hEventPrint[2]);
 			DWORD dwExitCode;
			GetExitCodeThread(pThis->m_pThreadPrint->m_hThread, &dwExitCode);
			AfxEndThread(dwExitCode, TRUE);
			break;

		default:
			break;
		}		
	}

	CoUninitialize();
	return 0;
}


void CProcessPrint::StraightLinePrint()
{
	m_bPrintLinesFlag = true;

// 	int nLineNum = m_pMainDlg->m_pDlgPrint->m_pDlgPrintMotionControl->m_pDlgPrintMotionLinkLearn->m_vecLine.size();
// 	float fPrintLineSpeed = m_pMainDlg->m_pDlgPrint->m_pDlgPrintMotionControl->m_pDlgPrintMotionLinkLearn->m_fPrintLinesSpeed;
// 	m_P400.SetParamValue(nLineNum);
// 	m_P408.SetParamValue(fPrintLineSpeed);    //打印速度
// 	m_Prog4.Run();   //启动程序
// 
// 	StraightLine lineTemp;
// 	for (int i = 0; i < nLineNum; i++)
// 	{
// 		lineTemp =  m_pMainDlg->m_pDlgPrint->m_pDlgPrintMotionControl->m_pDlgPrintMotionLinkLearn->m_vecLine[i];
// 		m_P401.SetParamValue(lineTemp.beginpoint.fPosX);
// 		m_P402.SetParamValue(lineTemp.beginpoint.fPosY);
// 		m_P403.SetParamValue(lineTemp.endpoint.fPosX);
// 		m_P404.SetParamValue(lineTemp.endpoint.fPosY);
// 		m_P405.SetParamValue(lineTemp.angle.fAngleA);
// 		m_P406.SetParamValue(lineTemp.angle.fAngleC);
// 		m_P407.SetParamValue(1);
// 		while (m_P407.GetParamValue() == 1)  //等待P407为0时continue
// 		{
// 			if (m_bThreadExit) break;		 //线程退出
// 		}
// 	}
// 
// 	m_Prog4.Stop(); 

	m_bPrintLinesFlag = false;
}


void CProcessPrint::ExitPrintThread()
{
	//退出打印线程
	m_bThreadExit = true;
	ResetEvent(m_hEventPrint[0]);
	ResetEvent(m_hEventPrint[1]);
	SetEvent(m_hEventPrint[2]);
}


void CProcessPrint::PausePrint()	
{
	////此处发送命令"-h"////

	if (m_bIsLinesPrint)
	{
		//直线打印
		//m_Prog4.Stop();   
	}
	else
	{
		//整体打印,下载Prog
		m_bRemainDownLoadFlag = false;
	}	
}


void CProcessPrint::ContinuePrint()
{
	if (m_bIsLinesPrint)
	{
		//直线打印
		//m_Prog4.Run();   
	}
	else
	{
		//整体打印,下载Prog
		m_bRemainDownLoadFlag = true;
	}	
}


void CProcessPrint::StartPrint()
{
	if (m_bIsLinesPrint)
	{
		//直线打印
		if (m_bPrintLinesFlag) return;
		m_bThreadExit = false;
		SetEvent(m_hEventPrint[0]); 
	}
	else
	{
		//整体打印,下载Prog
		if (m_bDownProgFlag) return;
		////首先向下位机发送P1P2P3三个P变量的值
		SetEvent(m_hEventPrint[1]);
	}
}


void CProcessPrint::StopPrint()
{
	if (m_bIsLinesPrint)
	{
		//直线打印
		m_bThreadExit = true;
	}
	else
	{
		//整体打印,下载Prog
		m_bRemainDownLoadFlag = false;
		m_nDownLoadCount = 0;
	}
}


void CProcessPrint::DownLoadProg(vector<CString> &vecCode, int &nDownLoadCnt)
{
	m_bDownProgFlag = true;

// 	int nSize = vecCode.size();
// 	int nDownedRows = nDownLoadCnt * ROT_PROG_ROWS;		//已下载行数
// 	int nRemainRows = nSize - nDownedRows;				//剩余行数
// 	if (nRemainRows <= 0) return;
// 
// 	CCtrlCommand cmd(0);
// 	cmd.GiveCommand("&1 OPEN ROT");						//打开旋转缓冲区
// 	int nDowningRows = 0;								//即将下载的行数
// 
// 	if (nRemainRows > ROT_PROG_ROWS)
// 	{
// 		m_bRemainDownLoadFlag = true;
// 		nDowningRows = ROT_PROG_ROWS;
// 	}
// 	else
// 	{
// 		m_bRemainDownLoadFlag = false;
// 		nDowningRows = nRemainRows;
// 	}
// 
// 	for (int i = 0; i < nDowningRows; i++)
// 	{
// 		CString strCmd = vecCode[nDownedRows + i];
// 		cmd.GiveCommand(strCmd);
// 		if (i == ROT_PROG_ROWS/2)
// 		{
// 			cmd.GiveCommand("P101=1");
// 		}
// 	}
// 
// 	cmd.GiveCommand("CLOSE");							//关闭旋转缓冲区
// 	nDownLoadCnt++;										//下载次数,即调用DownLoadProg计数

	m_bDownProgFlag = false;
}


void CProcessPrint::MonitorProg()
{
	if (m_bRemainDownLoadFlag)
	{
// 		if (1 == m_P409.GetParamValue())
// 		{
// 			m_P409.SetParamValue(0);
// 
// 			SetEvent(m_hEventPrint[1]);
// 		}
	}
}


void CProcessPrint::OpenGCodeFile(CString strPath)
{
	m_gcodeAnalysis.ReadGCodeFile(strPath);
}