#include "StdAfx.h"
#include "ProcessTransfer.h"
#include "FE-3DMMDlg.h"
#include "ParamData.h"


CProcessTransfer::CProcessTransfer()
	:m_BeModelLoad(false)
	,m_bStepAdjustRun(false)
{
	m_pProcessCore = NULL;
	m_pMainDlg = NULL;
}


CProcessTransfer::~CProcessTransfer(void)
{
	Release();
}


void CProcessTransfer::SetMainDlgPointer(CFE3DMMDlg* pDlg)
{
	ASSERT(pDlg);
	m_pMainDlg = pDlg;
}

void CProcessTransfer::SetParamData(CParamData* pData)
{
	ASSERT(pData);
	m_pParamData = pData;
}

void CProcessTransfer::SetProcessCore(CProcessCore* pProcesscore)
{
	ASSERT(pProcesscore);
	m_pProcessCore = pProcesscore;
}

void CProcessTransfer::SetRunMode(int Mode)
{
	if (Mode == CONTINUE)
	{
		m_RunMode = CONTINUE;
	}
	else if(Mode == STEP)
	{
		m_RunMode = STEP;
	}
	else
	{
		ASSERT(FALSE);
	}
}

void CProcessTransfer::Init()
{
	//电机
	m_MotorTransferX.ConfigMotor(0,11,"转印X");				    //电机X
	m_MotorTransferZ.ConfigMotor(0,12,"转印Z");					//电机Z
	m_MotorRod11.ConfigMotor(0, 16, "推杆11"); 
	m_MotorRod12.ConfigMotor(0, 17, "推杆12");     
	m_MotorRod13.ConfigMotor(0, 18, "推杆13");     
	m_MotorRod21.ConfigMotor(0, 19, "推杆21");     
	m_MotorRod22.ConfigMotor(0, 20, "推杆22");     
	m_MotorRod23.ConfigMotor(0, 21, "推杆23");     
	m_MotorRod31.ConfigMotor(0, 22, "推杆31");     
	m_MotorRod32.ConfigMotor(0, 23, "推杆32");
	m_MotorRod33.ConfigMotor(0, 24, "推杆33"); 

#ifndef FE_DEBUG_OFFLINE
	m_MotorTransferX.Enable();
	m_MotorTransferZ.Enable();
	m_MotorRod11.Enable();
	m_MotorRod12.Enable();
	m_MotorRod13.Enable();
	m_MotorRod21.Enable();
	m_MotorRod22.Enable();
	m_MotorRod23.Enable();
	m_MotorRod31.Enable();
	m_MotorRod32.Enable();
	m_MotorRod33.Enable();
#endif

	//下位机自动程序
	m_prog1.ConfigProg(0, 3, 1, "转印自动程序");

	//IO
	m_IO_VacAttach.ConfigIO(0,"M7912","贴装真空吸附");		//贴装真空吸附（on/off开关）
	m_IO_VacBlow.ConfigIO(0,"M7913","贴装真空快排");		    //贴装真空快排
	m_IO_RodAttach.ConfigIO(0, "Mxxxx", "推杆吸附");
	m_IO_PickPlatform.ConfigIO(0, "Mxxx", "拾取平台吸附");

	//P变量
	m_P301.ConfigParam(0, "P301", "");
	m_P302.ConfigParam(0, "P302", "");		
	m_P303.ConfigParam(0, "P303", "");
	m_P304.ConfigParam(0, "P304", "");
	m_P305.ConfigParam(0, "P305", "");
	m_P306.ConfigParam(0, "P306", "");
	m_P307.ConfigParam(0, "P307", "");
	m_P308.ConfigParam(0, "P308", "");
	m_P309.ConfigParam(0, "P309", "");
	m_P310.ConfigParam(0, "P310", "");
    m_P311.ConfigParam(0, "P311", "");
	m_P312.ConfigParam(0, "P312", "");
	m_P313.ConfigParam(0, "P313", "");
	m_P314.ConfigParam(0, "P314", "");
	m_P315.ConfigParam(0, "P315", "");
	m_P316.ConfigParam(0, "P316", "");
	m_P317.ConfigParam(0, "P317", "");
	m_P318.ConfigParam(0, "P318", "");
	m_P319.ConfigParam(0, "P319", "");
	m_P320.ConfigParam(0, "P320", "");

	m_P350.ConfigParam(0, "P350", "");
	m_P351.ConfigParam(0, "P351", "");

	m_P360.ConfigParam(0, "P360", "");
	m_P361.ConfigParam(0, "P361", "");

	//初始化线程
	ThreadInit();
}

void CProcessTransfer::Release()
{

}



/***************************************************************** 
** 函数功能: 开启转印实验，用于外部调用的函数
** 创建人:	 刘腾
** 参数:        无
** Version:1.0
****************************************************************/
void CProcessTransfer::Run()
{
	TRACE("Experiment starting...\n");

	//不同的对象需要加载不同的模板，只能在开始后才知道加载哪一个模板
	if (!LoadModel())
	{
		MessageBox(NULL, "模板加载失败", "提示", MB_ICONWARNING);
		return;
	}
	TRACE("模板加载成功");
	
	TransferPara();   //向下位机传送部分参数

	//启动
	SetEvent(m_hTransfer[1]);
	//计算旋转
	SetEvent(m_hTransfer[1]);
}

/***************************************************************** 
** 函数功能: 停止转印实验，用于外部调用的函数
** 创建人:	 刘腾
** 参数:        无
** Version:1.0
****************************************************************/
BOOL CProcessTransfer::Stop()
{
	//强制性KILL电机

	return TRUE;
}

/***************************************************************** 
** 函数名称: ThreadInit
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 初始化线程，创建线程，初始化事件
** 创建人:	 刘腾
** Version:1.0
****************************************************************/
BOOL CProcessTransfer::ThreadInit()
{
	//初始化标示量
	m_BeModelLoad = false;

	m_hTransfer[0] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hTransfer[1] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hTransfer[2] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hTransfer[3] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hTransfer[4] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hTransfer[5] = CreateEventA(NULL, TRUE, FALSE, NULL);

	m_hVariableInquire[0] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hVariableInquire[1] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hVariableInquire[2] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hVariableInquire[3] = CreateEventA(NULL, TRUE, FALSE, NULL);

 	m_hAssist[0] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hAssist[1] = CreateEventA(NULL, TRUE, FALSE, NULL);
	m_hAssist[2] = CreateEventA(NULL, TRUE, FALSE, NULL);

	//根据转印方式和对象加载对应的文件
	int iType = m_pParamData->GetParamTransfer()->TransferType;
	int iSize = m_pParamData->GetParamTransfer()->TransferSize;
	if ("" == m_pParamData->LoadTransferPa(iType, iSize))
	{
		MessageBox(NULL, _T("参数加载失败！\n"), _T("提示"), MB_OK |MB_ICONERROR);
		return FALSE;
	}

	//转印主线程
	m_pInitiativeTransferThread = AfxBeginThread(InitiativeTransferThread, this);
	if (NULL == m_pInitiativeTransferThread)
	{
		return FALSE;
	}
	//变量查询线程
	m_pVariableInquireThread = AfxBeginThread(VariableInquireThread, this);
	if (NULL == m_pVariableInquireThread)
	{
		return FALSE;
	}
	//辅助线程
	m_pAssistThread = AfxBeginThread(AssistThread, this);
	if (NULL == m_pAssistThread)
	{
		return FALSE;
	}

	//被动转印线程
	//m_pPassitivityTransferThread = AfxBeginThread(PassitivityTransferThread, this);
	//if (NULL == m_pPassitivityTransferThread)
	//{
	//	return FALSE;
	//}

	//单步调试线程
	m_pStepAdjustThread = AfxBeginThread(StepAdjustThread, this);
	if(NULL == m_pStepAdjustThread)
	{
		return FALSE;
	}

	return TRUE;
}

/***************************************************************** 
** 函数名称: ThreadExit
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 线程强制退出
** 创建人:	 刘腾
** Version:1.0
****************************************************************/
BOOL CProcessTransfer::ThreadExit()
{	
	SetEvent(m_hTransfer[0]);
	SetEvent(m_hVariableInquire[0]);
	SetEvent(m_hAssist[0]);
	SetEvent(m_hStepAdjust[0]);
	return TRUE;
}

/***************************************************************** 
** 函数名称: InitiativeTransferThread
** 输入参数: this
** 输出:	     0
** 函数功能: 主动转印方式的实验主线程
** 创建人:	 刘腾
** Version:1.0
****************************************************************/
UINT CProcessTransfer::InitiativeTransferThread(LPVOID lParam)
{
	bool bIsRunning = true;
	CProcessTransfer* pProcessTransfer = (CProcessTransfer*)lParam;
	while (bIsRunning)
	{
		switch(WaitForMultipleObjects(4, pProcessTransfer->m_hTransfer, FALSE, INFINITE))
		{
			//退出线程事件
		case  WAIT_OBJECT_0 :
			bIsRunning = false;		
			break;
			//启动下位机程序
		case  WAIT_OBJECT_0 + 1:
			ResetEvent(pProcessTransfer->m_hTransfer[1]);
			pProcessTransfer->Start();
			break;
		case WAIT_OBJECT_0 + 2:
			//定位角度
			pProcessTransfer->PickAngleLocation();
			break;
		case WAIT_OBJECT_0 + 3:
			//定位Y
			pProcessTransfer->PickPosYLocation();
			break;
		case WAIT_OBJECT_0 + 4:
			//定位X
			pProcessTransfer->PickPosXLocation();
			break;
		case WAIT_OBJECT_0 + 5:
			//上视相机定位
			pProcessTransfer->PlaceLocation();
			break;
			//拾取定位
		default:
			break;
		}
	}
	ResetEvent(pProcessTransfer->m_hTransfer[0]);
	ASSERT(_T("the main thread exit"));
	return 0;
}


/***************************************************************** 
** 函数名称: PassitivityTransferThread
** 输入参数: this
** 输出:	     0
** 函数功能: 被动方式转印的转印线程
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
UINT CProcessTransfer::PassitivityTransferThread(LPVOID lParam)
{
	return 0;
}



/***************************************************************** 
** 函数名称: VariableInquireThread
** 输入参数: this
** 输出:	     0
** 函数功能: 线程函数，变量查询线程，查询下位机的标志量
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
UINT CProcessTransfer::VariableInquireThread(LPVOID lParam)
{
	bool bRunning = true;
	CProcessTransfer* pProcessTransfer = (CProcessTransfer*)lParam;
	while (bRunning)
	{
		switch(WaitForMultipleObjects(2, pProcessTransfer->m_hVariableInquire, FALSE, INFINITE))
		{
		case WAIT_OBJECT_0:
			bRunning = false;
			break;
		case WAIT_OBJECT_0 + 1:
			if(pProcessTransfer->m_P350.GetParamValue())
			{
				ResetEvent(pProcessTransfer->m_hVariableInquire[1]);
				SetEvent(pProcessTransfer->m_hTransfer[2]);
			}
			break;
		case WAIT_OBJECT_0 +2:
			if (pProcessTransfer->m_P351.GetParamValue() && pProcessTransfer->m_P350.GetParamValue())
			{
				ResetEvent(pProcessTransfer->m_hVariableInquire[2]);
				SetEvent(pProcessTransfer->m_hAssist[2]);
			}
			break;
		case WAIT_OBJECT_0 + 3:
			if (pProcessTransfer->m_P350.GetParamValue())
			{
				ResetEvent(pProcessTransfer->m_hAssist[3]);
				SetEvent(pProcessTransfer->m_hTransfer[5]);
			}
		default:
			break;
		}
	}
	ResetEvent(pProcessTransfer->m_hVariableInquire[0]);
	ASSERT(_T("variable inquire thread exit!"));
	return 0;
}

/***************************************************************** 
** 函数名称: AssistThread
** 输入参数: this
** 输出:	     0
** 函数功能: 辅助转印过程线程函数，用于在主线程空闲期间计算曲面旋转信息
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
UINT CProcessTransfer::AssistThread(LPVOID lParam)
{
	bool bRunning = true;
	CProcessTransfer* pProcessTransfer = (CProcessTransfer*)lParam;
	while (bRunning)
	{
		switch(WaitForMultipleObjects(3, pProcessTransfer->m_hAssist, FALSE, INFINITE))
		{
		case WAIT_OBJECT_0:
			bRunning = false;
			break;
		case WAIT_OBJECT_0 + 1:
			ResetEvent(pProcessTransfer->m_hAssist[1]);
			pProcessTransfer->CalRotateInfo();
			break;
		case WAIT_OBJECT_0 + 2:
			ResetEvent(pProcessTransfer->m_hAssist[2]);
			pProcessTransfer->HandTransform();
			break;
		default:
			break;
		}
	}
	ResetEvent(pProcessTransfer->m_hAssist[0]);
	ASSERT(_T("assist thread exit!"));
	return 0;
}


void CProcessTransfer::TransferPara()
{
	//位置
	float fParam;
	fParam = (float)m_pParamData->GetParamTransfer()->fDisPickerCamX;
	m_P301.SetParamValue(fParam);
	m_P302.SetParamValue(0.0);
	m_P303.SetParamValue(0.0);
	m_P306.SetParamValue(0.0);
	m_P307.SetParamValue(0.0);
	m_P308.SetParamValue(0.0);
	m_P309.SetParamValue(0.0);
	m_P310.SetParamValue(0.0);
}

/***************************************************************** 
** 函数名称: Start
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 实验初始化完成后，开始运行函数，用于内部调用
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CProcessTransfer::Start()
{
	//启动下位机转印自动程序
	m_prog1.Run();
	return TRUE;
}

/***************************************************************** 
** 函数名称: LoadModel
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 根据转印方式和转移对象不同加载模板图像
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CProcessTransfer::LoadModel()
{
	//根据转印对象找到需要调用的对应模板
	CString strModelName;
	//转印方式
	if (INITIATIVE == m_pParamData->GetParamTransfer()->TransferType)
	{
		strModelName = _T("Initiative_TransCam_");
	} 
	else if(PASSITIVITY == m_pParamData->GetParamTransfer()->TransferType)
	{
		strModelName = _T("Passitivity_TransCam_");
	}
	//转印对象
	switch(m_pParamData->GetParamTransfer()->TransferSize)
	{
	case SIZE11:
		strModelName += _T("1mm X 1mm");
		break;
	case SIZE22:
		strModelName += _T("2mm X 2mm");
		break;
	case SIZE33:
		strModelName += _T("3mm X 3mm");
		break;
	case SIZE44:
		strModelName += _T("4mm X 4mm");
		break;
	case SIZE55:
		strModelName += _T("5mm X 5mm");
		break;
	case SIZE66:
		strModelName += _T("6mm X 6mm");
		break;
	}
	CString strDebugPath = m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1);
	CString strFileName = strDebugPath + "Model\\Ncc";
	CString strFullName = strFileName + "\\" + strModelName;
	//默认采用ncc匹配，加载ncc模板，后续可以根据需求修改
	//m_pProcessCore->GetCameraTransDown()->ReloadModel(strFullName);
	return TRUE;
}

/***************************************************************** 
** 函数名称: PickAngleLocation
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 拾取前进行角度定位，实时反馈给操作者进行手动调节
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CProcessTransfer::PickAngleLocation()
{
	//判断模板是否加载完毕
	if (m_BeModelLoad != true)
	{
		TRACE(_T("未成功加载模板！"));
		//可能存在模板还在加载的可能，等待加载
		Sleep(500);
		if (m_BeModelLoad != true)
		{
			return FALSE;
		}
	}
	//判断是否点击了下一步，完成了角度调整
	if (!m_BeAdjustAngle)
	{
		//进行模板匹配，找到对应值
		//GetCameraTrans()->SingleGrab();
		//相机匹配定位
		//GetCameraTrans()->Match();
		//发送自定义消息，让窗口更新显示
		HWND hwnd = ((CFE3DMMDlg*)AfxGetApp()->m_pMainWnd)->m_pDlgTransfer->m_pDlgTransferManual->m_hWnd;
		SendMessageA(hwnd, WM_CHANGETIPS,1, NULL);
	}
	else
	{
		ResetEvent(m_hTransfer[2]);
		SetEvent(m_hTransfer[3]);
	}

	return TRUE;
}

BOOL CProcessTransfer::PickPosYLocation()
{
	//判断是否点击了下一步，完成了Y向调整
	if (!m_BeAdjustPosY)
	{
		//进行模板匹配，找到对应值
		//GetCameraTrans()->SingleGrab();
		//相机匹配定位
		//GetCameraTrans()->Match();
		//发送自定义消息，让窗口更新显示
		HWND hwnd = ((CFE3DMMDlg*)AfxGetApp()->m_pMainWnd)->m_pDlgTransfer->m_pDlgTransferManual->m_hWnd;
		SendMessageA(hwnd, WM_CHANGETIPS,2, NULL);
	}
	else
	{
		ResetEvent(m_hTransfer[3]);
		SetEvent(m_hTransfer[4]);
	}	
	return TRUE;
}

BOOL CProcessTransfer::PickPosXLocation()
{
	ResetEvent(m_hTransfer[4]);

	//进行模板匹配，找到对应值
	//GetCameraTrans()->SingleGrab();
	//相机匹配定位
	//GetCameraTrans()->Match();

	//设置P变量给下位机传定位结果
	float fPos = (float)(m_pParamData->GetParamTransfer()->fXPosPickPicker);
	m_P303.SetParamValue(fPos);

	Sleep(50);
	//将信号标志量置0
	m_P350.SetParamValue(0);

	//发送自定义消息，让窗口更新显示
	HWND hwnd = ((CFE3DMMDlg*)AfxGetApp()->m_pMainWnd)->m_pDlgTransfer->m_pDlgTransferManual->m_hWnd;
	SendMessageA(hwnd, WM_CHANGETIPS,3, NULL);
	//拾取事件置位

	return TRUE;
}

BOOL CProcessTransfer::PlaceLocation()
{
	//m_CameraUp.SingleGrab();
	//m_CameraUp.Match();
	//给下位机传递参数

	Sleep(50);
	//将到位标志量置0
	m_P350.SetParamValue(0);
	return TRUE;
}


BOOL CProcessTransfer::CalRotateInfo()
{
	//初始化
	double x = m_pParamData->GetParamTransfer()->iPlacePos.fPosX;
	double y = m_pParamData->GetParamTransfer()->iPlacePos.fPosY;
	double z = m_pParamData->GetParamTransfer()->iPlacePos.fPosA;
	m_RotateCal.SetOriginPos(x, y, z);

	//计算旋转矩阵
	m_RotateCal.Rotate();

	//将计算结果传到参数类中
	std::vector<double> tmpVec(9);
	tmpVec = m_RotateCal.GetRodDisplacement();
	m_pParamData->GetParamTransfer()->RodStransform.fRod11 = tmpVec[0];
	m_pParamData->GetParamTransfer()->RodStransform.fRod12 = tmpVec[1];
	m_pParamData->GetParamTransfer()->RodStransform.fRod13 = tmpVec[2];
	m_pParamData->GetParamTransfer()->RodStransform.fRod21 = tmpVec[3];
	m_pParamData->GetParamTransfer()->RodStransform.fRod22 = tmpVec[4];
	m_pParamData->GetParamTransfer()->RodStransform.fRod23 = tmpVec[5];
	m_pParamData->GetParamTransfer()->RodStransform.fRod31 = tmpVec[6];
	m_pParamData->GetParamTransfer()->RodStransform.fRod32 = tmpVec[7];
	m_pParamData->GetParamTransfer()->RodStransform.fRod33 = tmpVec[8];

	m_pParamData->GetParamTransfer()->fAPosPlaceFourAxle = m_RotateCal.GetRotateAngleA();
	m_pParamData->GetParamTransfer()->fBPosPlaceFourAxle = m_RotateCal.GetRotateAngleB();

	return TRUE;
}

BOOL CProcessTransfer::HandTransform()
{
	//推杆变形
	m_MotorRod11.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod11);
	m_MotorRod12.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod12);
	m_MotorRod13.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod13);
	m_MotorRod21.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod21);
	m_MotorRod22.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod22);
	m_MotorRod23.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod23);
	m_MotorRod31.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod31);
	m_MotorRod32.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod32);
	m_MotorRod33.MoveTo(m_pParamData->GetParamTransfer()->RodStransform.fRod33);
	return TRUE;
}


/***************************************************************** 
** 函数名称: EnableTransMotor
** 输入参数: bool变量，true表示使能，FLASE表示不使能
** 输出:	     void
** 函数功能: 控制转印电机使能
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
void CProcessTransfer::EnableTransMotor(const bool bEnable)
{
	if (bEnable)
	{
		m_MotorTransferX.Enable();
		m_MotorTransferZ.Enable();
	}
	else
	{
		m_MotorTransferX.Disable();
		m_MotorTransferZ.Disable();
	}
}

/***************************************************************** 
** 函数名称: StepAdjustThread
** 输入参数: LPVOID 转印操作类的this指针
** 输出:	     UINT
** 函数功能: 单步调试时，调整角度和Y的线程函数
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
UINT CProcessTransfer::StepAdjustThread(LPVOID lParam)
{
	bool bRunning  = true;

	CProcessTransfer* pProcessTransfer = (CProcessTransfer*) lParam;

	TRACE("单步运行，角度与Y偏差调整线程启动 ");

	while(bRunning)
	{
		DWORD ret = WaitForMultipleObjects(2, pProcessTransfer->m_hStepAdjust, FALSE, INFINITE);
		switch(ret)
		{
		case 0:
			DWORD dwExitCode;
			GetExitCodeThread(pProcessTransfer->m_pStepAdjustThread->m_hThread, &dwExitCode);
			AfxEndThread(dwExitCode, TRUE);
			break;
		case 1:
			{
				//判断模板是否加载完毕
				if (pProcessTransfer->m_BeModelLoad != true)
				{
					TRACE(_T("未成功加载模板！"));
					//可能存在模板还在加载的可能，等待加载
					Sleep(100);
					break;
				}

				//进行模板匹配，找到对应值
				//pProcessTransfer->GetCameraTrans()->SingleGrab();
				//相机匹配定位
				//pProcessTransfer->GetCameraTrans()->Match();
				//发送自定义消息，让窗口更新显示
				HWND hwnd = ((CFE3DMMDlg*)AfxGetApp()->m_pMainWnd)->m_pDlgTransfer->m_pDlgTransferManual->m_hWnd;
				SendMessageA(hwnd, WM_CHANGETIPS,1, NULL);
				break;
			}
			
		case 2:
			{
				/*
				** 这个线程在角度调整线程的后面开启，前面可以保证模板已经加载完毕，故不再需要
				*/
				//进行模板匹配，找到对应值
				//pProcessTransfer->GetCameraTrans()->SingleGrab();
				//相机匹配定位
				//pProcessTransfer->GetCameraTrans()->Match();
				//发送自定义消息，让窗口更新显示
				HWND hwnd = ((CFE3DMMDlg*)AfxGetApp()->m_pMainWnd)->m_pDlgTransfer->m_pDlgTransferManual->m_hWnd;
				SendMessageA(hwnd, WM_CHANGETIPS,2, NULL);
				break;
			}
			
		default:
			break;
		}
	}

	return 0;
}

/***************************************************************** 
** 函数名称: StepRunInit
** 输入参数: NULL
** 输出:	     NULL
** 函数功能: 单步调试时，进行初始化，开启调整线程，创建事件
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
void CProcessTransfer::StepRunInit()
{
	//创建手动置位事件
	m_hStepAdjust[0] = CreateEventA(NULL, TRUE, FALSE, NULL);   //退出事件
	m_hStepAdjust[1] = CreateEventA(NULL, TRUE, FALSE, NULL);    //角度调整
	m_hStepAdjust[2] = CreateEventA(NULL, TRUE, FALSE, NULL);    //Y向调整
}



/***************************************************************** 
** 函数名称: StartAngleAdjust
** 输入参数: NULL
** 输出:	     BOOL
** 函数功能: 单步调试时，开始角度调整，事件置位
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CProcessTransfer::StartAngleAdjust()
{
	BOOL ret;

	ret = SetEvent(m_hStepAdjust[1]);

	return ret;
}



/***************************************************************** 
** 函数名称: EndAngleAdjust
** 输入参数: NULL
** 输出:	     BOOL
** 函数功能: 单步调试时，开始角度调整，事件置位
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CProcessTransfer::EndAngleAdjust()
{
	BOOL ret;

	ret = ResetEvent(m_hStepAdjust[1]);

	return ret;
}



/***************************************************************** 
** 函数名称: StartYAdjust
** 输入参数: NULL
** 输出:	     BOOL
** 函数功能: 单步调试时，开始角度调整，事件置位
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CProcessTransfer::StartYAdjust()
{
	BOOL ret;

	ret = SetEvent(m_hStepAdjust[2]);

	return ret;
}


/***************************************************************** 
** 函数名称: EndYAdjust
** 输入参数: NULL
** 输出:	     BOOL
** 函数功能: 单步调试时，开始角度调整，事件置位
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CProcessTransfer::EndYAdjust()
{
	BOOL ret;

	ret = ResetEvent(m_hStepAdjust[2]);

	return ret;
}

