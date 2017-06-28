#include "StdAfx.h"
#include "JetAirPressurePort.h"


CJetAirPressurePort::CJetAirPressurePort(void)
{
	m_com = INVALID_HANDLE_VALUE;
}


CJetAirPressurePort::~CJetAirPressurePort(void)
{
}

BOOL CJetAirPressurePort::IsOpen()
{
	return m_com != INVALID_HANDLE_VALUE;
}



//设置读写超时结构
void CJetAirPressurePort::SetTimerOut( unsigned long dwTimerOut/*=5000*/ )
{
	if(!IsOpen())
	{
		return;
	}

	//读一次缓冲区的内容后立即返回
	CommTimerOuts.ReadIntervalTimeout = MAXWORD;
	CommTimerOuts.ReadTotalTimeoutConstant = 0;
	CommTimerOuts.ReadTotalTimeoutMultiplier = 0;

	//设置写超时常量
	CommTimerOuts.WriteTotalTimeoutConstant = dwTimerOut;
	CommTimerOuts.WriteTotalTimeoutMultiplier = 0;

	//设置超时
	SetCommTimeouts(m_com,&CommTimerOuts);
}

//设置dcb参数
BOOL CJetAirPressurePort::SetDBCParam( 
	unsigned long xBabd, 
	unsigned char xDataSize,
	unsigned char xParity,
	unsigned char xStopBit )
{
	if(!IsOpen())
	{
		return FALSE;
	}

	if(!GetCommState(m_com,&dcb))
	{
		ClosePort();
		return FALSE;
	}

	//设置通讯参数
	dcb.DCBlength = sizeof(DCB);
	dcb.BaudRate = xBabd;
	dcb.ByteSize = xDataSize;
	dcb.Parity = xParity;
	dcb.StopBits = xStopBit;

	if(!SetCommState(m_com,&dcb))
	{
		/*CString str;
		str.Format(TEXT("%d"),GetLastError());
		AfxMessageBox(str);*/
		ClosePort();
		return FALSE;
	}

	return TRUE;
}

//设置端口缓冲区大小
BOOL CJetAirPressurePort::SetPortBuffSize( unsigned long InputBuffSize, unsigned long OutputBuffSize )
{
	if(!IsOpen())
	{
		return FALSE;
	}
	if(! SetupComm(m_com,InputBuffSize,OutputBuffSize))
	{
		ClosePort();
		return FALSE;
	}

	return TRUE;
}

//清理缓冲区
void CJetAirPressurePort::ClearBuffer()
{
	if(! IsOpen())
	{
		return;
	}

	PurgeComm(m_com,PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
}

//当前接收缓冲区字节数目
unsigned long CJetAirPressurePort::GetInBufferCount()
{
	if(! IsOpen())
	{
		return (0);
	}

	DWORD dwErrorFlags;
	COMSTAT Comstat;

	ClearCommError(m_com,&dwErrorFlags,&Comstat);
	return Comstat.cbInQue;
}

//当前发送缓冲区字节数目
unsigned long CJetAirPressurePort::GetOutBufferCount()
{
	if(! IsOpen())
	{
		return (0);
	}

	DWORD dwErrorFlags;
	COMSTAT Comstat;

	ClearCommError(m_com,&dwErrorFlags,&Comstat);
	return Comstat.cbOutQue;
}

//打开串口
BOOL CJetAirPressurePort::OpenPort( unsigned long xPort, 
	/*串口号 */ unsigned long xBabd, 
	/*波特率 */ unsigned char xDataSize, 
	/*数据位*/ unsigned char xParity, 
	/*校验位*/ unsigned char xStopBit, 
	/*停止位*/ unsigned long InputBuffSize,
	/*输入buffer大小 */ unsigned long OutputBuffSize,
	/*输出buffer大小 */ unsigned long dwTimerOut )
{
	if(IsOpen())
	{
		ClosePort();
	}
	//设置事件
	memset(&m_overlappedRead,0,sizeof(OVERLAPPED));
	m_overlappedRead.hEvent = CreateEventA(NULL, FALSE, TRUE, TEXT("portread"));
	ASSERT(m_overlappedRead.hEvent != INVALID_HANDLE_VALUE);

	memset(&m_OverlappedWrite,0,sizeof(OVERLAPPED));
	m_OverlappedWrite.hEvent = CreateEventA(NULL, FALSE, TRUE, TEXT("portwrite"));
	ASSERT(m_OverlappedWrite.hEvent != INVALID_HANDLE_VALUE);

	//取得串口字符
	CString csPort;
	csPort.Format(TEXT("\\\\.\\COM%d"),xPort);

	m_com = CreateFile(csPort,
		               GENERIC_READ | GENERIC_WRITE,
		               0,    
		               NULL, 
		               OPEN_EXISTING, 
		               FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,    
		               NULL);
	if(m_com == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	SetPortBuffSize(InputBuffSize,OutputBuffSize);
	SetDBCParam(xBabd,xDataSize,xParity,xStopBit);
	SetTimerOut(dwTimerOut);

	//清理缓冲器
	PurgeComm(m_com, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

	return TRUE;

}

void CJetAirPressurePort::ClosePort()
{
	if(IsOpen())
	{
		CloseHandle(m_com);
		m_com = INVALID_HANDLE_VALUE;
	}

	if(m_overlappedRead.hEvent != NULL)
	{
		CloseHandle(m_overlappedRead.hEvent);
	}

	if(m_OverlappedWrite.hEvent != NULL)
	{
		CloseHandle(m_OverlappedWrite.hEvent);
	}
}


//异步读数据
unsigned long CJetAirPressurePort::ReadChar( unsigned long dwBufferLength, 
	                           char *buff,
	                           unsigned long dwWaitTime )
{
	if(!IsOpen())
	{
		return 0;
	}

	DWORD dwError;
	COMSTAT comStat;
	if(ClearCommError(m_com,&dwError,&comStat) && dwError > 0)  //清除错误
	{
		PurgeComm(m_com,PURGE_RXABORT | PURGE_RXCLEAR);  //清除输入缓冲区
		return 0;
	}
	if(! comStat.cbInQue)  //缓冲区无数据
	{
		return 0;
	}

	unsigned long uReadLength = 0;
	dwBufferLength = dwBufferLength-1 > comStat.cbInQue ? comStat.cbInQue : dwBufferLength-1;

	if(! ::ReadFile(m_com,buff,dwBufferLength,&uReadLength,&m_overlappedRead))
	{
		if(GetLastError() == ERROR_IO_PENDING)
		{
			WaitForSingleObject(m_overlappedRead.hEvent,dwWaitTime);
			if(! GetOverlappedResult(m_com,&m_overlappedRead,&uReadLength,FALSE))
			{
				if(GetLastError() != ERROR_IO_INCOMPLETE)
				{
					uReadLength = 0;
				}
			}
		}
		else
		{
			uReadLength = 0;
		}
	}

	return uReadLength;
}

unsigned long CJetAirPressurePort::WriteChar( unsigned long dwBufferLength, char *buff )
{
	if(! IsOpen())
	{
		return 0;
	}

	DWORD dwError;
	if(ClearCommError(m_com,&dwError,NULL) && dwError > 0)
	{
		PurgeComm(m_com, PURGE_TXABORT | PURGE_TXCLEAR);
	}

	unsigned long uWriteLength = 0;
	if(! WriteFile(m_com,buff,dwBufferLength,&uWriteLength,&m_OverlappedWrite))
	{
		if(GetLastError() ==ERROR_IO_PENDING )
		{
			DWORD tmp = 0;
			tmp = WaitForSingleObject(m_OverlappedWrite.hEvent,1000);
			if(tmp == WAIT_TIMEOUT || tmp == WAIT_ABANDONED)
			{
				return 0;
			}
			else if (tmp == WAIT_OBJECT_0)
			{
				if(! GetOverlappedResult(m_com,&m_OverlappedWrite,&uWriteLength,FALSE))
				{
					return 0;
				}
				else
				{
					return uWriteLength;
				}
			}

			uWriteLength = 0;
		}
	}

	return uWriteLength;
}



