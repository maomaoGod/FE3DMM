#pragma once
#include "PmacDevice.h"

class CCtrlDPR : private CPmacDevice
{
public:
	CCtrlDPR(void);
	~CCtrlDPR(void);

	void ConfigDPR(long card, UINT offset, UINT bit, CString descri);
	long GetDprValue(UINT offset);           //获取dpr变量的值
	void ResetDpr();						 //清零dpr变量的值
	void ResetDpr(UINT offset, UINT bit);	 //清零dpr变量的值

private:
	CPmacDevice  m_pmacDevice;
	long		 m_lCard;         //卡号
	UINT 		 m_nOffset;	
	UINT		 m_nBit;
	CString		 m_strDescri;     //DPR描述
};

