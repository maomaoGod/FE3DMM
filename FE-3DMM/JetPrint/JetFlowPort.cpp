
#include <stdafx.h>
#include "JetFlowPort.h"

/**
 *功能:	构造函数，在此初始化各个通信同步对象
 *参数:	无
 *返回:	无
**/
CJetFlowPort::CJetFlowPort(): m_SendOverlapEvent(FALSE, TRUE),	
				  m_RecvOverlapEvent(FALSE, TRUE),
				  m_WaitOverlapEvent(FALSE, TRUE)
{
	m_hComm				= INVALID_HANDLE_VALUE;
	m_bIsOpen			= FALSE;
	m_commType			= CommSync;
	m_nSendBufferSize	= 0;
	m_nRecvBufferSize	= 0;
}

/**
 *功能:	析构函数，没有关闭串口会在此处自动关闭
 *参数:	无
 *返回:	无
**/
CJetFlowPort::~CJetFlowPort()
{
	Close();
}

/************************************************************************/
/************************************************************************/
/* 打开和关闭                                                                  */
/************************************************************************/
/************************************************************************/

/**
 *功能:	打开对应的串口并设置对应参数
 *参数:	nPort					--串口号，默认为1
		dwBaud					--波特率，默认为9600
		stopbits				--停止位，默认为1位
		commType				--通信类型，默认为同步通信
		parity					--奇偶检验位，默认无奇偶校验
		DataBits				--通信数据位，默认为8位
		fc						--流控制，默认无流控制
		nSendBufferSize			--发送数据缓冲区大小，默认为1024
		nReceiveBufferSize		--接收数据缓冲区大小，默认为1024
 *返回:	打开并设置成功为TRUE,否则为FALSE
 *说明：一般来说，发送和接收缓冲区设为1024，已经足够大，如果预先判断
		超过这一值可以设置为更大的值
**/
BOOL CJetFlowPort::Open( const int nPort				/*=1*/, 
				   const DWORD dwBaud			/*=9600*/,
				   const BYTE DataBits			/*=8*/,  
				   const StopBits stopbits		/*=OneStopBit*/, 
				   const CommType commType		/*=CommSync*/, 
				   const Parity parity			/*=NoParity*/, 
				   const FlowControl fc			/*=NoFlowControl*/, 
				   const int nSendBufferSize	/*=1024*/, 
				   const int nReceiveBufferSize /*=1024*/ )
{
	/************************************************************************/
	/* 打开串口                                                                     */
	/************************************************************************/
	//校验端口号输入
	ASSERT(nPort>0 && nPort<=255);

	//CreateFile打开相应串口
	CString sPort;
	sPort.Format(_T("\\\\.\\COM%d"), nPort);
	m_hComm = CreateFile(sPort, 
						 GENERIC_READ | GENERIC_WRITE, 
						 0, 
						 NULL, 
						 OPEN_EXISTING, 
						 CommSync==commType ? 0 :FILE_FLAG_OVERLAPPED, 
						 NULL);
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return m_bIsOpen = FALSE;
	}

	/************************************************************************/
	/* 设置串口波特率,校验位,数据位,停止位及流控制                          */
	/************************************************************************/
	//获得之前的参数列表以便修改指定的参数，保留其他参数
	DCB dcb;
	if (FALSE == GetState(dcb))
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;

		return m_bIsOpen = FALSE;
	}

	//波特率
	dcb.BaudRate = dwBaud; 

	//校验位
	switch (parity)
	{
	case EvenParity:  dcb.Parity = EVENPARITY;  break;
	case MarkParity:  dcb.Parity = MARKPARITY;  break;
	case NoParity:    dcb.Parity = NOPARITY;    break;
	case OddParity:   dcb.Parity = ODDPARITY;   break;
	case SpaceParity: dcb.Parity = SPACEPARITY; break;
	default:          ASSERT(FALSE);            break;
	}

	//数据位
	dcb.ByteSize = DataBits;

	//停止位
	switch (stopbits)
	{
	case OneStopBit:           dcb.StopBits = ONESTOPBIT;   break;
	case OnePointFiveStopBits: dcb.StopBits = ONE5STOPBITS; break;
	case TwoStopBits:          dcb.StopBits = TWOSTOPBITS;  break;
	default:                   ASSERT(FALSE);               break;
	}

	//流控制
	dcb.fDsrSensitivity = FALSE;
	switch (fc)
	{
	case NoFlowControl:
		{
			dcb.fOutxCtsFlow = FALSE;
			dcb.fOutxDsrFlow = FALSE;
			dcb.fOutX = FALSE;
			dcb.fInX = FALSE;
			break;
		}
	case RtsCtsFlowControl:
		{
			dcb.fOutxCtsFlow = TRUE;
			dcb.fOutxDsrFlow = FALSE;
			dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
			dcb.fOutX = FALSE;
			dcb.fInX = FALSE;
			break;
		}
	case DtrDsrFlowControl:
		{
			dcb.fOutxCtsFlow = FALSE;
			dcb.fOutxDsrFlow = TRUE;
			dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
			dcb.fOutX = FALSE;
			dcb.fInX = FALSE;
			break;
		}
	case XonXoffFlowControl:
		{
			dcb.fOutxCtsFlow = FALSE;
			dcb.fOutxDsrFlow = FALSE;
			dcb.fOutX = TRUE;
			dcb.fInX = TRUE;
			dcb.XonChar = 0x11;
			dcb.XoffChar = 0x13;
			dcb.XoffLim = 100;
			dcb.XonLim = 100;
			break;
		}
	default:
		{
			ASSERT(FALSE);
			break;
		}
	}

	//设置状态
	if (FALSE == SetState(dcb))
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;

		return m_bIsOpen = FALSE;
	}

	/************************************************************************/
	/* 设置发送数据和接收数据缓冲区大小,设置默认读写操作都是立即返回        */
	/************************************************************************/
	if (FALSE == SetupComm(m_hComm, nReceiveBufferSize, nSendBufferSize)
		|| FALSE == Set0Timeout())
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;

		return m_bIsOpen = FALSE;
	}

	m_commType			= commType;
	m_nSendBufferSize	= nSendBufferSize;
	m_nRecvBufferSize	= nReceiveBufferSize;
	return m_bIsOpen	= TRUE;
}

/**
 *功能:	判断当前串口是否已经打开成功
 *参数:	无
 *返回:	打开为TRUE，没有打开为FALSE
**/
BOOL CJetFlowPort::IsOpen()
{
	return m_bIsOpen;
}

/**
 *功能:	如果当前串口已经打开，关闭
 *参数:	无
 *返回:	串口已关闭为TRUE,否则为FALSE
**/
BOOL CJetFlowPort::Close()
{
	if (IsOpen())
	{
		BOOL bSuccess = CloseHandle(m_hComm);
		
		if (TRUE == bSuccess)
		{
			m_hComm = INVALID_HANDLE_VALUE;
			m_commType	= CommSync;
			return !(m_bIsOpen = FALSE);
		}
		else
		{
			return !(m_bIsOpen = TRUE);
		}
	}

	return TRUE;
}

/************************************************************************/
/************************************************************************/
/* 发送和接收                                                           */
/************************************************************************/
/************************************************************************/

/**
 *功能:	发送指定的数据,可以使字符串数组，也可以是各种进制数(2/8/10/16)
 *参数:	lpBuf			--具体的待发送数据缓冲区,可保存字符或数字
		dwCount			--缓冲区字节数,包括所有待发送字符(\n、\r等)
 *返回:	成功为TRUE，失败为FALSE
		注意，对于异步通信失败可能是当前正在发送中，需要检验GetLastError值
		是否为ERROR_IO_PENDING
 *说明：会自动根据当前打开串口时指定的通信类型来确认发送时的通信选择
**/
BOOL CJetFlowPort::Send(const void* lpBuf, const DWORD dwCount)
{
	ASSERT(IsOpen());

	DWORD dwBytesSend	= 0;		//成功发送的字节数
	BOOL bSuccess		= FALSE;

	switch(m_commType)
	{
	case CommSync:
		bSuccess = WriteFile(m_hComm, lpBuf, dwCount, &dwBytesSend, NULL);
		break;

	case CommAsync:
		//设置异步发送用的同步事件，开始置为“无信号”状态
		m_SendOverlapEvent.ResetEvent();
		ZeroMemory(&m_SendOverlap, sizeof(OVERLAPPED));
		m_SendOverlap.hEvent = m_SendOverlapEvent;

		//1.当发送完成后，同步事件会被置为“有信号”状态，可等待“有信号”状态来保证发送完成
		//  这就是WaitSendComplete的工作
		//2.如果发送不是立即完成，此时返回的bSuccess为FALSE，使用GetLastError得到的是
		//ERROR_IO_PENDING
		bSuccess = WriteFile(m_hComm, lpBuf, dwCount, &dwBytesSend, &m_SendOverlap);
		break;
	}

	return bSuccess;
}

/**
 *功能:	发送指定的MFC字符串内容
 *参数:	strSend			--MFC Ctring类型字符串
 *返回:	成功为TRUE，失败为FALSE
		注意，对于异步通信失败可能是当前正在发送中，需要检验GetLastError值
		是否为ERROR_IO_PENDING
 *说明：会自动根据当前打开串口时指定的通信类型来确认发送时的通信选择
**/
BOOL CJetFlowPort::Send( CString& strSend )
{
	CStringA strSendA;
	strSendA = strSend;//注意这里的Unicode到Ascll的转换

	return Send(strSendA.GetBuffer(0), strSendA.GetLength());
}

/**
 *功能:	配合Send函数使用，等待异步发送完成
 *参数:	无
 *返回:	无
**/
void CJetFlowPort::WaitSendComplete()
{
	ASSERT(IsOpen());
	ASSERT(m_commType==CommAsync);

	WaitForSingleObject(m_SendOverlapEvent, INFINITE);
}

/**
 *功能:	接收指定的数据,可以使字符串数组，也可以是各种进制数(2/8/10/16)
 *参数:	lpBuf			--具体的待接收数据缓冲区,可保存字符或数字
		dwCount			--缓冲区字节数,包括所有待接收字符(\n、\r等)
 *返回:	成功为TRUE，失败为FALSE
		注意，对于异步通信失败可能是当前正在接收中，需要检验GetLastError值
		是否为ERROR_IO_PENDING
 *说明：会自动根据当前打开串口时指定的通信类型来确认接收时的通信选择
**/
BOOL CJetFlowPort::Recv(void* lpBuf, const DWORD dwCount)
{
	ASSERT(IsOpen());

	DWORD dwBytesRecv	= 0;		//成功接收的字节数
	BOOL bSuccess		= FALSE;

	switch(m_commType)
	{
	case CommSync:
		bSuccess = ReadFile(m_hComm, lpBuf, dwCount, &dwBytesRecv, NULL);
		break;

	case CommAsync:
		//设置异步接收用的同步事件，开始置为“无信号”状态
		m_RecvOverlapEvent.ResetEvent();
		ZeroMemory(&m_RecvOverlap, sizeof(OVERLAPPED));
		m_RecvOverlap.hEvent = m_RecvOverlapEvent;

		//1.当接收完成后，同步事件会被置为“有信号”状态，可等待“有信号”状态来保证接收完成
		//  这就是WaitRecvComplete的工作
		//2.如果接收不是立即完成，此时返回的bSuccess为FALSE，使用GetLastError得到的是
		//ERROR_IO_PENDING
		bSuccess = ReadFile(m_hComm, lpBuf, dwCount, &dwBytesRecv, &m_RecvOverlap);
		break;
	}

	return bSuccess;
}

/**
 *功能:	接收指定的数据,填充到MFC字符串中
 *参数:	strRecv			--MFC Ctring类型字符串
 *返回:	成功为TRUE，失败为FALSE
		注意，对于异步通信失败可能是当前正在接收中，需要检验GetLastError值
		是否为ERROR_IO_PENDING
 *说明：会自动根据当前打开串口时指定的通信类型来确认接收时的通信选择
**/
BOOL CJetFlowPort::Recv( CString& strRecv )
{
	char* pRecvBuf = new char[m_nRecvBufferSize];
	ZeroMemory(pRecvBuf, m_nRecvBufferSize);

	if (FALSE == Recv(pRecvBuf, m_nRecvBufferSize))
	{
		return FALSE;
	}

	CStringA strRecvA;
	strRecvA = pRecvBuf;
	strRecv = strRecvA;//ASCLL转换成Unicode输出

	delete pRecvBuf;
	return TRUE;
}

/**
 *功能:	配合Recv函数使用，等待异步接收完成
 *参数:	无
 *返回:	无
**/
void CJetFlowPort::WaitRecvComplete()
{
	ASSERT(IsOpen());
	ASSERT(m_commType==CommAsync);

	WaitForSingleObject(m_RecvOverlapEvent, INFINITE);
}

/**
 *功能:	发送控制指令，同时获取接受到的返回值
 *参数:	strSend			-- 待发送的MFC Ctring类型字符串
		strRecv			-- 用于接收返回数据的MFC Ctring类型字符串
		nElapseTime		-- 接收到第一个字符后，等待一段时间以便接收完成
						   默认为100ms
 *返回:	成功为TRUE，失败为FALSE
 *说明：会自动根据当前打开串口时指定的通信类型来确认当前的通信选择
**/
BOOL CJetFlowPort::GetResponse( CString& strSend, CString& strRecv, 
						  UINT nElapseTime/*=100*/)
{
	switch (m_commType)
	{
		//同步
	case CommSync:
		//发送
		if (!Send(strSend))
		{
			return FALSE;
		}

		//等待读取字符消息到达
		SetEventToWait(EV_RXCHAR);
		StartWaitEvent();

		//读取
		Sleep(nElapseTime);//等待所有数据传输完成
		if (!Recv(strRecv))
		{
			return FALSE;
		}
		break;

		//异步
	case CommAsync:
		//发送
		if (!Send(strSend) && ERROR_IO_PENDING!=GetLastError())
		{
			return FALSE;
		}
		
		//等待读取字符
		SetEventToWait(EV_RXCHAR);
		StartWaitEvent();
		WaitEventArrive();

		//读取
		Sleep(nElapseTime);//等待所有数据传输完成
		if (!Recv(strRecv) && ERROR_IO_PENDING!=GetLastError())
		{
			return FALSE;
		}
		WaitRecvComplete();
		break;
	}

	return TRUE;
}

/************************************************************************/
/************************************************************************/
/* 等待指定事件发生                                                     */
/************************************************************************/
/************************************************************************/

/**
 *功能:	设置当前等待发生的事件，如有字符串到达、发送完成等
 *参数:	dwMask		--掩码，设置当前等待的事件，参见MSDN SetCommMask
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::SetEventToWait(DWORD dwMask)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);

	return SetCommMask(m_hComm, dwMask);
}

/**
 *功能:	获得当前等待发生的事件，如有字符串到达、发送完成等
 *参数:	dwMask		--设置用的掩码，参见MSDN GetCommMask
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::GetEventToWait(DWORD& dwMask)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);

	return GetCommMask(m_hComm, &dwMask);
}

/**
 *功能:	等待SetEventToWait中设置的事件发生
 *参数:	无
 *返回:	成功为TRUE，失败为FALSE
 *说明：1.这个函数其实有点晦涩，简单来说作用就是通知底层轮询当前事件
	     是否到达，一旦到达一个事件，m_EventMask设为对应事件掩码，
		  m_WaitOverlap设为有信号状态；
	   2.后续通过检测m_WaitOverlap信号状态判断是否有事件到达，
	     这就是WaitEventArrive函数的工作；
	   3.后续通过检测m_EventMask判断当前事件类型；
	   4.注意这个函数是非阻塞的，只通知底层轮询，本身并不等待。
**/
BOOL CJetFlowPort::StartWaitEvent()
{
	ASSERT(IsOpen());

	BOOL bSuccess		= FALSE;

	if (CommSync == m_commType)
	{
		//同步通信时线程阻塞直到等待事件完成
		bSuccess = WaitCommEvent(m_hComm, &m_EventMask, NULL);
	}
	else
	{
		m_WaitOverlapEvent.ResetEvent();//开始无信号，完成有信号
		ZeroMemory(&m_WaitOverlap, sizeof(OVERLAPPED));
		m_WaitOverlap.hEvent = m_WaitOverlapEvent;

		//异步通信时标记现在要等待事件，一旦事件到达，则event有信号
		bSuccess = WaitCommEvent(m_hComm, &m_EventMask, &m_WaitOverlap);
	}

	return bSuccess;	
}

/**
 *功能:	等待对应的事件发生，和SetEventToWait、StartWaitEvent配合
 *参数:	无
 *返回:	无
**/
void CJetFlowPort::WaitEventArrive()
{
	ASSERT(IsOpen());
	ASSERT(m_commType==CommAsync);

	WaitForSingleObject(m_WaitOverlapEvent, INFINITE);
}

/************************************************************************/
/************************************************************************/
/* set和get                                                             */
/************************************************************************/
/************************************************************************/

/**
 *功能:	设置当前串口参数
 *参数:	dcb		--串口参数结构体
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::SetState(DCB& dcb)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);

	return SetCommState(m_hComm, &dcb);
}

/**
 *功能:	获得当前串口参数
 *参数:	dcb		--串口参数结构体
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::GetState(DCB& dcb)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);

	return GetCommState(m_hComm, &dcb);
}

/**
 *功能:	设置当前通信超时
 *参数:	timeouts		--超时结构体
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::SetTimeouts(COMMTIMEOUTS& timeouts)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);

	return SetCommTimeouts(m_hComm, &timeouts);
}

/**
 *功能:	获取当前通信超时设置
 *参数:	timeouts		--超时结构体
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::GetTimeouts(COMMTIMEOUTS& timeouts)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);

	return GetCommTimeouts(m_hComm, &timeouts);
}

/**
 *功能:	发送和接收都是立即执行
 *参数:	无
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::Set0Timeout()
{
	COMMTIMEOUTS Timeouts;
	ZeroMemory(&Timeouts, sizeof(COMMTIMEOUTS));

	Timeouts.ReadIntervalTimeout = MAXDWORD;
	Timeouts.ReadTotalTimeoutMultiplier = 0;
	Timeouts.ReadTotalTimeoutConstant = 0;
	Timeouts.WriteTotalTimeoutMultiplier = 0;
	Timeouts.WriteTotalTimeoutConstant = 0;

	return SetTimeouts(Timeouts);
}

/**
 *功能:	发送立即执行
 *参数:	无
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::Set0WriteTimeout()
{
	COMMTIMEOUTS Timeouts;

	GetTimeouts(Timeouts);
	Timeouts.WriteTotalTimeoutMultiplier = 0;
	Timeouts.WriteTotalTimeoutConstant = 0;

	return SetTimeouts(Timeouts);
}

/**
 *功能:	接收立即执行
 *参数:	无
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetFlowPort::Set0ReadTimeout()
{
	COMMTIMEOUTS Timeouts;

	GetTimeouts(Timeouts);
	Timeouts.ReadIntervalTimeout = MAXDWORD;
	Timeouts.ReadTotalTimeoutMultiplier = 0;
	Timeouts.ReadTotalTimeoutConstant = 0;

	return SetTimeouts(Timeouts);
}
