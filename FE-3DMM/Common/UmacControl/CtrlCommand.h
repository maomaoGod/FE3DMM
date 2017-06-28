#pragma once
#include "PmacDevice.h"

class CCtrlCommand : private CPmacDevice
{
public:
	CCtrlCommand(long card = 0);
	~CCtrlCommand(void);

	void ConfigCommand(long card);
	void GiveCommand(LPCTSTR strCommand);   //向下位机发送指定命令

private:
	CPmacDevice  m_pmacDevice;
	long		 m_lCard;					//卡序号	
};

