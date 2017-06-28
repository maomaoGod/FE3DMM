// PylonCamera.h: interface for the PylonCamera class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include <pylonc/PylonC.h>
#include <pylon/PylonIncludes.h>
#pragma comment(lib, "PylonC_MD_VC120.lib")
#include "HalconCpp.h"
using namespace HalconCpp;

#define CHECK( errc ) if ( S_OK != errc ) pressEnterToExit()							//错误显示宏
#define NUM_BUFFERS 5																						//用于抓图结果存放的buffer数目

class PylonCamera  
{
public:
	PylonCamera();
	virtual ~PylonCamera();
	void Init(const CString &strCamName);															//初始化
	void Exit();																												//退出
	void StartGrab();																									//开始采集
	void StopGrab();																									//停止采集	
	HObject* GetSingleLocal();																				//获取一帧图像用于定位
	HObject* GetSingleShow();																				//获取一帧图像用于显示
	HObject* GetSingleSave();																					//获取一帧图像用于存储

private:
	void pressEnterToExit();																						//告知用户出错，退出
	void loadCamera() ;																								//加载相机
	void unloadCamera() ;																							//卸载相机
	void loadStreamGrabber() ;																				//加载数据流抓取对象																							
	void unloadStreamGrabber() ;																			//卸载数据流抓取对象																											
	static UINT GrabThreadProc(LPVOID pVoid);													//采集线程
	void GrabFunc();																									//采集函数		
	void BalserToHalcon(const PylonGrabResult_t &pylonGrabRes, HObject *pHobjectImage);   //Balser->Halcon

private:
	GENAPIC_RESULT										res;														//函数执行结果，用于错误验证
	CString														m_strCameraName;							//相机名称
	size_t															m_numDevices;								//相机数目           
	BOOL															m_isOpenDev;									//相机是否已经打开
	BOOL															m_isOpenStream;							//是否已经打开数据流抓取对象
    int32_t														m_payloadSize;								//抓取数据的大小
    unsigned char											*m_buffers[NUM_BUFFERS];			//数据流内存指针
	PYLON_DEVICE_HANDLE						m_hDev;												//相机对象句柄
	PYLON_STREAMGRABBER_HANDLE	m_hGrabber;										//数据流抓取对象句柄
	PYLON_WAITOBJECT_HANDLE				m_hWait;											//用于数据流抓取对象的同步对象
    PYLON_STREAMBUFFER_HANDLE		m_bufHandles[NUM_BUFFERS];	//注册过的内存的指针对象
    PylonGrabResult_t									m_grabResult;									//抓取结果

	CWinThread												*m_pThread ;									//采图线程
	HANDLE														m_hEvent[2];										//采图事件
	CRITICAL_SECTION									m_criticalsection;								//临界区,实现图像的同步操作
	HObject														m_hoImage;										//Halcon存储的图像
	HObject														m_hoSingleLocal;								//单帧图像用于定位
	HObject														m_hoSingleShow;							//单帧图像用于显示
	HObject														m_hoSingleSave;								//单帧图像用于存储
};