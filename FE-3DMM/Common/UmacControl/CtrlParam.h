#pragma once
#include "PmacDevice.h"

class CCtrlParam : private CPmacDevice
{
public:
	CCtrlParam(void);
	~CCtrlParam(void);

	void ConfigParam(long card, CString name, CString descri);
	void SendCommand();
	void SetParamValue(float fValue);    //设置P变量的值
	long GetParamValue();				 //获取P变量的值

private:
	CPmacDevice  m_pmacDevice;
	long		 m_lCard;         //卡号
	CString		 m_strName;       //P变量名
	CString		 m_strDescri;     //P变量描述
	CString		 m_strCommand;	  //命令
	CString		 m_strAnswer;	  //下位机对应变量值
};

