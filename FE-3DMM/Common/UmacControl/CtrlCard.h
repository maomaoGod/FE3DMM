#pragma once
#include "PmacDevice.h"
#include "CtrlCommand.h"
#include "CtrlMotor.h"
#include "CtrlParam.h"
#include "CtrlIO.h"
#include "CtrlDPR.h"
#include "CtrlPLC.h"
#include "CtrlProg.h"

class CCtrlCard : private CPmacDevice
{
public:
	CCtrlCard(void);
	~CCtrlCard(void);

	void ConfigCard(long card);
	void ConnectPmacCard();					//连接Pmac控制卡
	BOOL IsConnectPmac();					//是否连接Pmac
	void Save();							//向卡发送save指令

private:
	CPmacDevice  m_pmacDevice;
	BOOL		 m_bConnectPmacFlag;	//连接Pmac标志
	long		 m_lCard;				//卡序号	
};

