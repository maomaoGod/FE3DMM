#pragma once
#include "PmacDevice.h"

class CCtrlProg : private CPmacDevice
{
public:
	CCtrlProg(void);
	~CCtrlProg(void);

	void ConfigProg(long card, int coordNo, int progNo, CString descri);
	void SendCommand();
	void Run();					  //运行
	void Stop();				  //停止

private:
	CPmacDevice  m_pmacDevice;
	long		 m_lCard;         //卡号
	int			 m_nCoordNO;	  
	int 		 m_nProgNO;		  //自动程序序号
	CString		 m_strDescri;     //自动程序描述
	CString		 m_strCommand;	  //命令
};

