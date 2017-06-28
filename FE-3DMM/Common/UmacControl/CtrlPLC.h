#pragma once
#include "PmacDevice.h"

class CCtrlPLC : private CPmacDevice
{
public:
	CCtrlPLC(void);
	~CCtrlPLC(void);


	void ConfigPLC(long card, int plcNo, CString descri);
	void SendCommand();
	void Enable();				  //Ê¹ÄÜPLC
	void Disable();				  //½ûÄÜPLC


private:
	CPmacDevice  m_pmacDevice;
	long		 m_lCard;         //¿¨ºÅ
	int 		 m_nPlcNO;		  //PLCÐòºÅ
	CString		 m_strDescri;     //PLCÃèÊö
	CString		 m_strCommand;	  //ÃüÁî
};

