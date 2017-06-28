#ifndef HARVARD_PUMP_H_H
#define HARVARD_PUMP_H_H

#include "JetFlowPort.h"

class CJetHarvardPump
{
public:
	CJetHarvardPump(void);
	virtual ~CJetHarvardPump(void);

	BOOL Init(const int nPort);

	BOOL Run();
	BOOL RunBack();
	BOOL Stop();
	BOOL SwitchRunAndStop();

	BOOL SetInfuseRate(const int nRate);
	BOOL SetWithdrawRate(const int nRate);
	BOOL SetMaxInfuseRate();
	BOOL SetMaxWithdrawRate();
	BOOL SetMinInfuseRate();
	BOOL SetMinWithdrawRate();
	int GetInfuseRate();
	int GetWithdrawRate();
	double GetSyringeVolume();

	BOOL SetSyringeDiameter(const double dbDiameter=4.608);
	BOOL SetSyringeVolume(double dbVolume);
	bool IsHarvardOpen()
	{
		return m_comm.IsOpen()?true:false;
	}
	void CloseHarvardPump();

public:
	CJetFlowPort m_comm;
	int m_nInfuseRate;
private:
	
	CString m_strSend;
	CString m_strReceive;
};

#endif
