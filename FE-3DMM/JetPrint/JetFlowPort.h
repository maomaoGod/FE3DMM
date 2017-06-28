#ifndef CJetFlowPort_H
#define CJetFlowPort_H

#include <afxmt.h>

class CJetFlowPort
{
// 常量定义
public:
	enum FlowControl			//流控制
	{
		NoFlowControl,			//无流控制
		RtsCtsFlowControl,		//Rts/Cts硬件流控制
		DtrDsrFlowControl,		//Dtr/Dsr硬件流控制
		XonXoffFlowControl		//Xon/Xoff软件流控制
	};

	enum Parity					//奇偶校验
	{    
		EvenParity,				//偶校验
		MarkParity,				//标记
		NoParity,				//无奇偶校验
		OddParity,				//奇校验
		SpaceParity				//空格
	};

	enum StopBits				//停止位
	{		
		OneStopBit,				//1
		OnePointFiveStopBits,	//1.5
		TwoStopBits				//2
	};

	enum
	{
		NoHandshaking = 0,
		XonXoff = 1,
		RtsCts = 2,
		XonXoffAndRtsCts = 3
	}HandshakeConstants;

	enum CommType				//通信类型
	{	
		CommSync = 0,			//同步发送
		CommAsync = 1,			//异步发送
	};

// 方法
public:
	CJetFlowPort();
	~CJetFlowPort();
	BOOL Open(const int nPort				=1, 
		      const DWORD dwBaud			=9600, 
			  const BYTE DataBits				=6,
			  const StopBits stopbits		=OneStopBit,
			  const CommType commType		=CommSync,
			  const Parity parity			=NoParity,   
			  const FlowControl fc			=NoFlowControl, 
			  const int nSendBufferSize		=1024,
			  const int nReceiveBufferSize	=1024);
	BOOL IsOpen();
	BOOL Close();

	BOOL Send(const void* lpBuf, const DWORD dwCount);
	BOOL Recv(void* lpBuf, const DWORD dwCount);
	BOOL Send(CString& strSend);
	BOOL Recv(CString& strRecv);
	void WaitSendComplete();
	void WaitRecvComplete();
	BOOL GetResponse(CString& strSend, CString& strRecv, UINT nElapseTime=100);

	BOOL SetEventToWait(DWORD dwMask);
	BOOL GetEventToWait(DWORD& dwMask);
	BOOL StartWaitEvent();
	void WaitEventArrive();

	BOOL SetState(DCB& dcb);
	BOOL GetState(DCB& dcb);
	BOOL SetTimeouts(COMMTIMEOUTS& timeouts);
	BOOL GetTimeouts(COMMTIMEOUTS& timeouts);
	BOOL Set0Timeout();
	BOOL Set0WriteTimeout();
	BOOL Set0ReadTimeout();

protected:
	HANDLE		m_hComm;			//串口句柄
	BOOL		m_bIsOpen;			//串口是否打开
	CommType	m_commType;			//当前通讯类型
	int			m_nSendBufferSize;
	int			m_nRecvBufferSize;

	OVERLAPPED	m_SendOverlap;		//发送异步结构体
	CEvent		m_SendOverlapEvent;	//发送异步结构体事件
	OVERLAPPED	m_RecvOverlap;		//接收异步结构体
	CEvent		m_RecvOverlapEvent;	//接收异步结构体事件
	OVERLAPPED	m_WaitOverlap;		//等待异步结构体
	CEvent		m_WaitOverlapEvent;	//等待异步结构体事件
	DWORD		m_EventMask;		//等待事件Mask
};

#endif