// PylonCamera.cpp: implementation of the PylonCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PylonCamera.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PylonCamera::PylonCamera()
{
	m_isOpenDev			= FALSE ;
	m_isOpenStream		= FALSE ;
	m_strCameraName	= "";
	m_numDevices			= 0;
	m_hDev						= NULL;

	m_pThread				= NULL;
	InitializeCriticalSection(&m_criticalsection);
}


PylonCamera::~PylonCamera()
{
	DeleteCriticalSection(&m_criticalsection);
}


/************************************************************************/
/*功能:告知用户程序发生错误，即将关闭程序,增强界面友好型
**时间:2012.5.5
**作者:文洲@1.0*/
/************************************************************************/
void PylonCamera::pressEnterToExit()
{
	::MessageBox(NULL, TEXT("Pylon程序错误,即将关闭程序\n按<确定>关闭程序"), TEXT("程序错误"), MB_OK) ;
	
	//若是打开抓取图像对象则先关闭
	if (TRUE == m_isOpenStream)
	{
		unloadStreamGrabber() ;
	}

	//若打开设备则关闭
	if (TRUE == m_isOpenDev)
	{
		PylonDeviceClose(m_hDev) ;
		PylonTerminate();
	}

	exit(EXIT_FAILURE);
}


/************************************************************************/
/*功能:加载相机, 使用相机前必须调用该函数
**输入:无
**时间:2012.5.5
**作者:文洲@1.0
**修改:刘腾@1.1，2016.10  **** 修改:by jiang 2017/3 */
/************************************************************************/
void PylonCamera::loadCamera()
{
	/************************************************************************/
	/*打开相机对象*/
	/************************************************************************/
    //在用Pylon的方法前，要加载Pylon的动态运行库
    PylonInitialize(); 

    //检测所有的相机，必须在创建相机对象前调用该函数
	res = PylonEnumerateDevices( &m_numDevices );
	CHECK(res);
	if ( 0 == m_numDevices )
	{
		::MessageBox(NULL, TEXT("没有发现任何相机设备"), TEXT("错误"), MB_OK) ;
		//退出程序
		//pressEnterToExit();
	}

	if (FALSE == m_isOpenDev)
	{
		//创建相机对象，根据相机名称判断打开哪个相机
		for (size_t i = 0; i < m_numDevices; i++)
		{
			PylonDeviceInfo_t Pdi;		//相机信息结构体
			PylonGetDeviceInfo(i, &Pdi);
			if (Pdi.FriendlyName == m_strCameraName)
			{
				res = PylonCreateDeviceByIndex( i, &m_hDev );
				CHECK(res);
				break;
			}
		}
		
		if (NULL != m_hDev)
		{
			//打开相机对象
			res = PylonDeviceOpen( m_hDev, PYLONC_ACCESS_MODE_CONTROL | PYLONC_ACCESS_MODE_STREAM );
			CHECK(res);
			m_isOpenDev = TRUE ;
		}
		else
		{
			::MessageBox(NULL, TEXT("该相机没有被检测到, 请检查相机连接"), TEXT("错误"), MB_OK) ;
			//退出程序
			//pressEnterToExit();
		}
	}
}


/************************************************************************/
/*功能:卸载相机，使用完相机必须调用该函数
**时间:2012.5.5
**作者:文洲@1.0*/
/************************************************************************/
void PylonCamera::unloadCamera()
{	
	//若是打开抓取图像对象则先关闭
	if (TRUE == m_isOpenStream)
	{
		unloadStreamGrabber() ;
	}
	
	/************************************************************************/
	/*关闭相机*/
	/************************************************************************/
	if (TRUE == m_isOpenDev)
	{
		//关闭相机对象
		res = PylonDeviceClose( m_hDev );
		//CHECK(res);
		m_isOpenDev = FALSE ;
		
		//销毁相机对象
		res = PylonDestroyDevice ( m_hDev );
		//CHECK(res);
		
		//释放动态系统资源
		PylonTerminate(); 
	}
}


/************************************************************************/
/*功能:加载图像抓取对象，抓图前必须调用该函数
**时间:2012.5.5
**作者:文洲@1.0*/
/************************************************************************/
void PylonCamera::loadStreamGrabber()
{
	/************************************************************************/
	/*打开数据流抓取对象(Stream Grabber)*/
	/************************************************************************/
	//获取这个相机支持的stream数目, 一个相机可以有多个不同流抓取通道
	UINT nStreams ;
	res = PylonDeviceGetNumStreamGrabberChannels( m_hDev, &nStreams );
	CHECK(res);
	if ( nStreams < 1 )
	{
		::MessageBox(NULL, TEXT("这个相机不支持数据流对象采集"), TEXT("错误"), MB_OK) ;

		return ;
	}

	if (FALSE == m_isOpenStream)
	{
		//获得和打开stream grab，用默认的第一个通道打开
		res = PylonDeviceGetStreamGrabber( m_hDev, 0, &m_hGrabber );
		CHECK(res);
		res = PylonStreamGrabberOpen( m_hGrabber );
		CHECK(res);
		m_isOpenStream = TRUE ;
		
		//获取用于同步的wait object，其用于等待buffers被填满
		res = PylonStreamGrabberGetWaitObject( m_hGrabber, &m_hWait );
		CHECK(res);
	}
	else
	{
		::MessageBox(NULL, TEXT("数据流抓取对象已经打开"), TEXT("错误"), MB_OK) ;
		return ;
	}

	/************************************************************************/
	/*数据流抓取对象(Stream Grabber)抓图资源准备*/
	/************************************************************************/
	//设置采图参数
	res = PylonDeviceGetIntegerFeatureInt32( m_hDev,"PayloadSize",&m_payloadSize ); //获得采集芯片像素大小
	CHECK(res) ;
	PylonStreamGrabberSetMaxBufferSize(m_hGrabber, m_payloadSize );							 //最大采图像素数目
	PylonStreamGrabberSetMaxNumBuffer( m_hGrabber, NUM_BUFFERS );						 //最大采图buffer数目
	
	//分配采图内存
	UINT i ;
	for ( i = 0; i < NUM_BUFFERS; ++i )
	{
		m_buffers[i] = new unsigned char[m_payloadSize];
		if ( NULL == m_buffers[i] )
		{
			::MessageBox(NULL, TEXT("分配采图内存时，内存不足"), TEXT("错误"), MB_OK);
		}
	}
	
	//分配采图要的资源，此函数后参数不可再更改,直到FinishGrab()
	PylonStreamGrabberPrepareGrab( m_hGrabber );							
	
	//buffer必须注册才能用于采图，每个buffer都返回对应的句柄
	for ( i = 0; i < NUM_BUFFERS; ++i )
	{
		res = PylonStreamGrabberRegisterBuffer( m_hGrabber, m_buffers[i], 
			m_payloadSize, &m_bufHandles[i] );
	}
	
	//将buffer依次放入采图队列, 此时还没有开始采集
	//buffer分输入和输出两种队列，准备用于采集的buffer放于输入队列，采集完成的buffer放于输出队列。
	for ( i = 0; i < NUM_BUFFERS; ++i )
	{
		res = PylonStreamGrabberQueueBuffer( m_hGrabber, m_bufHandles[i], (void *) i );
	}
}


/************************************************************************/
/*功能:卸载图像抓取对象，抓图后必须调用该函数
**时间:2012.5.5
**作者:文洲@1.0*/
/************************************************************************/
void PylonCamera::unloadStreamGrabber()
{
	if (TRUE == m_isOpenStream)
	{
		/************************************************************************/
		/*数据流抓取对象(Stream Grabber)抓图资源释放*/
		/************************************************************************/
		//保证所有buffer都位于输出队列上
		res = PylonStreamGrabberCancelGrab( m_hGrabber );
		//CHECK(res);
		
		//将输出队列上的数据全部取出
		bool isReady ;
		do 
		{
			res = PylonStreamGrabberRetrieveResult( m_hGrabber, &m_grabResult, &isReady );
			//CHECK(res);
		} while ( isReady && (res == S_OK));
		
		//取消buffer的注册
		UINT i ;
		for ( i = 0; i < NUM_BUFFERS; ++i )   
		{
			res = PylonStreamGrabberDeregisterBuffer( m_hGrabber, m_bufHandles[i] );
			//CHECK(res);
			free( m_buffers[i] );
		}
		
		//释放相关的资源,此函数后影响payloadsize的参数(如AOI的宽度和高度)被解锁，可以更改
		res = PylonStreamGrabberFinishGrab( m_hGrabber );
		//CHECK(res);
		
		/************************************************************************/
		/*关闭数据流抓取对象(Stream Grabber)*/
		/************************************************************************/
		PylonStreamGrabberClose(m_hGrabber) ;
		//CHECK(res);
		m_isOpenStream = FALSE ;
	}
}


/************************************************************************/
/*功能:将basler采集的图像转化为halcon的图像类型指针
**时间:2016.10
**作者:刘腾@1.0   修改:by jiang 2017/3*/
/************************************************************************/
void PylonCamera::BalserToHalcon(const PylonGrabResult_t &pylonGrabRes, HObject *pHobjectImage)
{
	ASSERT(pylonGrabRes.pBuffer);
	HTuple hv_Error, hv_ErrorText;
	try
	{
		hv_Error = 2;
		GenImage1(pHobjectImage, "byte", (HTuple)pylonGrabRes.SizeX, 
			(HTuple)pylonGrabRes.SizeY, (Hlong)((unsigned char *)pylonGrabRes.pBuffer));	
	}
	catch(HalconCpp::HException e)
	{
		hv_Error = (int)e.ErrorCode();
		int errnotmp = hv_Error;
		hv_ErrorText  = e.ErrorMessage();
		CString strtmp = hv_ErrorText.ToString();
		strtmp = "转为halcon图像失败: "+strtmp;
		::MessageBox(NULL, strtmp, TEXT("异常"), MB_OK) ;
	}
}


void PylonCamera::Init(const CString &strCamName)
{
	m_strCameraName = strCamName; 
	loadCamera();

	m_pThread = AfxBeginThread(GrabThreadProc, this);
	ASSERT(m_pThread);
	
	m_hEvent[0] = CreateEventA(NULL, TRUE, FALSE, NULL);    //采集事件
	m_hEvent[1] = CreateEventA(NULL, TRUE, FALSE, NULL);    //线程退出事件
}


void PylonCamera::Exit()
{
	ResetEvent(m_hEvent[0]);
	SetEvent(m_hEvent[1]);
	Sleep(200);     //等待采图线程退出

	unloadCamera();
}


UINT PylonCamera::GrabThreadProc(LPVOID pVoid)
{
	PylonCamera* pThis = (PylonCamera*)pVoid;
	pThis->GrabFunc();
	return 0;	
}


void PylonCamera::GrabFunc()
{
	//进行采集前的准备工作
	if (TRUE == m_isOpenStream)
	{
		res = PylonDeviceExecuteCommandFeature( m_hDev, "AcquisitionStop") ;	//停止采图
		CHECK(res) ;
	}
	else
	{
		loadStreamGrabber() ;
	}

	res = PylonDeviceFeatureFromString( m_hDev, "AcquisitionMode", "Continuous" );	 //采集模式为"连续"
	CHECK(res) ;

	res = PylonDeviceExecuteCommandFeature( m_hDev, "AcquisitionStart") ;	 //开启连续采图模式
	CHECK(res) ;

	bool isReady;	 //超时标识变量

	while (1)
	{
		switch(WaitForMultipleObjects(2, m_hEvent, FALSE, INFINITE))
		{
		case WAIT_OBJECT_0:
			//ResetEvent(m_hEvent[0]);
			if (TRUE == m_isOpenStream)
			{
				int bufferIndex;														//buffer标志

				//等待下一个buffer被填充
				res = PylonWaitObjectWait( m_hWait, 2000, &isReady );
				if (GENAPI_E_OK == res && !isReady )
				{	//超时
					::MessageBox(NULL, TEXT("采集超时，退出采集"), TEXT("超时"), MB_OK) ;
					break; //停止采集
				}
				//CHECK(res) ;

				//填充完毕后获取采集结果
				res = PylonStreamGrabberRetrieveResult( m_hGrabber, &m_grabResult, &isReady );
				if (GENAPI_E_OK == res && !isReady )
				{
					::MessageBox(NULL, TEXT("获取采集结果超时，退出采集"), TEXT("超时"), MB_OK) ;
					break;
				}
				//CHECK(res) ;

				//当前抓取成功，则更新显示
				if ( (m_grabResult.Status == Grabbed))
				{	
					EnterCriticalSection(&m_criticalsection);
					BalserToHalcon(m_grabResult, &m_hoImage);	
					LeaveCriticalSection(&m_criticalsection);
				}

				//显示完，将buffer重新放回队列用于接收采图结果
				//获取当前buffer
				bufferIndex = (int) m_grabResult.Context;
				res = PylonStreamGrabberQueueBuffer( m_hGrabber, m_grabResult.hBuffer, (void*) bufferIndex );
			}	
			continue;

		case WAIT_OBJECT_0+1:
			ResetEvent(m_hEvent[1]);
			// 停止采集 
			res = PylonDeviceExecuteCommandFeature(m_hDev, "AcquisitionStop");
			//CHECK(res);
			DWORD dwExitCode;
			GetExitCodeThread(m_pThread->m_hThread, &dwExitCode);
			AfxEndThread(dwExitCode, TRUE);
			break;
		}
	}
}


void PylonCamera::StartGrab()
{
	SetEvent(m_hEvent[0]);
}


void PylonCamera::StopGrab()
{
	ResetEvent(m_hEvent[0]);
}


HObject* PylonCamera::GetSingleLocal()
{
	EnterCriticalSection(&m_criticalsection);
	if (m_hoImage.IsInitialized())
	{
			CopyImage(m_hoImage, &m_hoSingleLocal);
	}
	LeaveCriticalSection(&m_criticalsection);
	return &m_hoSingleLocal;
}


HObject* PylonCamera::GetSingleShow()
{
	EnterCriticalSection(&m_criticalsection);
	if (m_hoImage.IsInitialized())
	{
		CopyImage(m_hoImage, &m_hoSingleShow);
	}
	LeaveCriticalSection(&m_criticalsection);
	return &m_hoSingleShow;
}


HObject* PylonCamera::GetSingleSave()
{
	EnterCriticalSection(&m_criticalsection);
	if (m_hoImage.IsInitialized())
	{
		CopyImage(m_hoImage, &m_hoSingleSave);
	}
	LeaveCriticalSection(&m_criticalsection);
	return &m_hoSingleSave;
}
