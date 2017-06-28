#pragma once
#include "PmacDevice.h"

class CCtrlIO : private CPmacDevice
{
public:
	CCtrlIO(void);
	~CCtrlIO(void);

	void ConfigIO(long card, CString name, CString descri);
	void SendCommand();
	void On();				//IO打开			
	void Off();				//IO关闭
	int GetIoState();		//获取IO状态

private:
	CPmacDevice  m_pmacDevice;
	long		 m_lCard;         //卡号
	CString		 m_strName;		  //IO名
	CString		 m_strDescri;     //IO描述
	CString		 m_strCommand;	  //命令
	CString		 m_strAnswer;	  //下位机对应变量值
};

