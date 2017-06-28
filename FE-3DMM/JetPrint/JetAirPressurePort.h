#pragma once
class CJetAirPressurePort
{
public:
	CJetAirPressurePort(void);
	~CJetAirPressurePort(void);

public:
	BOOL IsOpen();
	BOOL OpenPort(unsigned long xPort,          //串口号
				  unsigned long xBabd,          //波特率
				  unsigned char xDataSize,      //数据位
				  unsigned char xParity,        //校验位
				  unsigned char xStopBit,       //停止位
				  unsigned long InputBuffSize,  //输入buffer大小
				  unsigned long OutputBuffSize, //输出buffer大小
				  unsigned long dwTimerOut);    //延迟时间
	void ClosePort();
	unsigned long ReadChar(unsigned long dwBufferLength, char *buff, unsigned long dwWaitTime = 20);
	unsigned long WriteChar(unsigned long dwBufferLength, char *buff);
	void SetTimerOut(unsigned long dwTimerOut=5000);  
	BOOL SetDBCParam(unsigned long xBabd,
		             unsigned char xDataSize, 
		             unsigned char xParity, 
					 unsigned char xStopBit);
	BOOL SetPortBuffSize(unsigned long InputBuffSize, unsigned long OutputBuffSize);
	void ClearBuffer();
	unsigned long GetInBufferCount();
	unsigned long GetOutBufferCount();
private:
	DCB dcb;
	COMMTIMEOUTS CommTimerOuts;
	HANDLE m_com;
	OVERLAPPED m_overlappedRead;
	OVERLAPPED m_OverlappedWrite;
};

