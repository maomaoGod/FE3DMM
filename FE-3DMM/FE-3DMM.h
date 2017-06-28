
// FE-3DMM.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

 #include "./JetPrint/JetAglientFunction.h"
 #include "./JetPrint/JetHarvardPump.h"
 #include "./JetPrint/JetAirPressureSet.h"
#include "InitializeThread.h"


// CFE3DMMApp:
// 有关此类的实现，请参阅 FE-3DMM.cpp
//

class CFE3DMMApp : public CWinApp
{
public:
	CFE3DMMApp();

// 重写
public:
	virtual BOOL InitInstance();


// 实现

	DECLARE_MESSAGE_MAP()
	
	static UINT InitThreadFunc(LPVOID pVoid);


public:
	CWinThread*				m_pInitWorkThread;		//初始化工作者线程
	CInitializeThread*			m_pInitUIThread;				//初始化用户界面线程
    CJetAglientFunction   m_JetAglientFunc;			//函数发生器
// 	CJetHarvardPump		m_JetHarvardPump;		//流量泵
// 	CJetAirPressureSet		m_JetAirPress;					//气压调节

	bool					m_bAglientInitState;
	bool					m_bHarvardInitState;
	bool					m_bWinMainBegin;    
	bool					m_bAppExit;
	
};

extern CFE3DMMApp theApp;