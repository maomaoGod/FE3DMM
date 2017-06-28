#pragma once
#include "GCodeAnalysis.h"
#include "./JetPrint/JetAglientFunction.h"
#include "./JetPrint/JetHarvardPump.h"
#include "./JetPrint/JetAirPressureSet.h"
class CFE3DMMDlg;
class CParamData;

#define ROT_PROG_ROWS  600		//每次下载旋转缓冲区程序行数

class CProcessPrint
{
public:
	CProcessPrint(void);
	~CProcessPrint(void);

	void SetMainDlgPointer(CFE3DMMDlg* pDlg);		//设置主窗口指针
	void Init();
	void Release();
	void Home();																	//回零
	void SetParamData(CParamData* pData);				//设置配置参数类指针

	static UINT	PrintThreadProc(LPVOID pVoid);			//打印线程函数
	void ExitPrintThread();												//退出打印线程
	void PausePrint();															//暂停
	void ContinuePrint();													//继续
	void StartPrint();															//开始
	void StopPrint();															//停止
	void MonitorProg();													//监视下位机程序
	void OpenGCodeFile(CString strPath);					//读取并解析G代码文件

private:
	void StraightLinePrint();												//直线打印
	void DownLoadProg(vector<CString> &vecCode, 
		int &nDownLoadCnt);												//下载运动程序
						

public:
	bool								m_bIsLinesPrint;					//判断: true直线打印,false整体打印
// 	CJetAglientFunction   m_JetAglientFunc;				//函数发生器
// 	CJetHarvardPump		m_JetHarvardPump;			//流量泵
// 	CJetAirPressureSet		m_JetAirPress;						//气压调节

private:
	CFE3DMMDlg*			m_pMainDlg;							//主对话框指针
	CParamData*				m_pParamData;						//配置参数类指针
	CWinThread*			m_pThreadPrint;						//打印线程
	HANDLE						m_hEventPrint[3];						//打印事件
	bool							m_bPrintLinesFlag;					//直线打印标志
	bool							m_bDownProgFlag;					//Prog下载标志
	bool							m_bThreadExit;						//线程退出标志
	CGCodeAnalysis		m_gcodeAnalysis;					//G代码解析
    bool							m_bRemainDownLoadFlag;	//剩余下载标志
	int								m_nDownLoadCount;				//下载次数计数
// 
// 	//P变量
// 	CCtrlParam				m_P400;										//直线条数
// 	CCtrlParam				m_P401;										//直线开始点X
// 	CCtrlParam				m_P402;										//直线开始点Y
// 	CCtrlParam				m_P403;										//直线结束点X
// 	CCtrlParam				m_P404;										//直线结束点Y
// 	CCtrlParam				m_P405;										//直线角度A
// 	CCtrlParam				m_P406;										//直线角度C
// 	CCtrlParam				m_P407;										//直线打印状态  1:开始 0:结束	
// 	CCtrlParam				m_P408;										//直线打印速度
// 	CCtrlParam				m_P409;										//监测下位机Prog运行
// 
// 	//下位机自动程序
// 	CCtrlProg					m_Prog4;									//直线打印自动程序
// 
//  	//IO
// 	CCtrlIO						m_IO_m7912;							//真空吸附
// 	CCtrlIO						m_IO_m7913;							//真空快排
 
	
};

