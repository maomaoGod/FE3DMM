#include "StdAfx.h"
#include "JetHarvardPump.h"

CJetHarvardPump::CJetHarvardPump(void)
{
	m_nInfuseRate = 0;
}

CJetHarvardPump::~CJetHarvardPump(void)
{
}

/**
 *功能:	初始化流量泵
 *参数:	nPort		--流量泵占用的串口号
 *返回:	成功为TRUE，失败为FALSE
**/
BOOL CJetHarvardPump::Init(const int nPort)
{
	//打开和初始化串口
	if (FALSE == m_comm.Open(nPort, 115200, 8, CJetFlowPort::TwoStopBits))
	{
		return FALSE;
	}

	//建立PC到流量泵连接，连接正常时发送\r->返回:
	m_strSend = TEXT("\r");
	m_comm.GetResponse(m_strSend, m_strReceive);
	if (m_strReceive.GetAt(1) == TEXT(':'))//实际返回内容为"\n:"
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 *功能:	流量泵开始自动注射
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::Run()
{
	m_strSend = TEXT("irun\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	流量泵开始反向自动注射
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::RunBack()
{
	m_strSend = TEXT("wrun\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	流量泵停止自动注射
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::Stop()
{
	m_strSend = TEXT("stop\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	流量泵切换自动注射状态，和手动点击流量泵控制面板上的开始/停止按钮效果一样
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::SwitchRunAndStop()
{
	m_strSend = TEXT("run\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	设置当前注射流量
 *参数:	nRate		--流量，nl/min
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::SetInfuseRate( const int nRate )
{
	m_strSend.Format(TEXT("irate %d nl/min\r"), nRate);
	m_comm.GetResponse(m_strSend, m_strReceive);

	m_nInfuseRate = nRate;
	return TRUE;
}

/**
 *功能:	设置当前反向注射流量
 *参数:	nRate		--流量，nl/min
 *返回:	始终为TRUE，保留实现
 **/
BOOL CJetHarvardPump::SetWithdrawRate( const int nRate )
{
	m_strSend.Format(TEXT("wrate %d nl/min\r"), nRate);
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	设置当前注射流量为最大
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::SetMaxInfuseRate()
{
	m_strSend = TEXT("irate max\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	设置当前反向注射流量为最大
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::SetMaxWithdrawRate()
{
	m_strSend = TEXT("wrate max\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	设置当前注射流量为最小
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::SetMinInfuseRate()
{
	m_strSend = TEXT("irate min\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	设置当前反向注射流量为最小
 *参数:	无
 *返回:	始终为TRUE，保留实现
**/
BOOL CJetHarvardPump::SetMinWithdrawRate()
{
	m_strSend = TEXT("wrate min\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

/**
 *功能:	获得注射器正向注射流量
 *参数:	无
 *返回:	正向注射流量，nl/min
**/
int CJetHarvardPump::GetInfuseRate()
{
	int iRate=0;

	m_strSend = TEXT("irate\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	iRate = _ttoi(m_strReceive);
	return iRate;
}

double CJetHarvardPump::GetSyringeVolume()
{
	double dbVolume = 0;
	m_strSend = TEXT("svolume\r");
	m_comm.GetResponse(m_strSend,m_strReceive);

	dbVolume = _ttof(m_strReceive);

	return dbVolume;

}

/**
 *功能:	获得注射器反向注射流量
 *参数:	无
 *返回:	反向注射流量，nl/min
**/
int CJetHarvardPump::GetWithdrawRate()
{
	int wRate=0;

	m_strSend = TEXT("wrate\r");
	m_comm.GetResponse(m_strSend, m_strReceive);

	sscanf_s(m_strReceive, TEXT("\n%d "), &wRate);//safe function
	//_stscanf(m_strReceive, TEXT("\n%d "), &wRate);
	return wRate;
}

/**
 *功能:	设置注射器直径
 *参数:	dbDiameter		--直径，mm,默认为4.608mm
 *返回:	始终为TRUE，保留实现
 *说明： 注意重新设置注射器直径后，相关流量会变成0，需要重新设置
**/
BOOL CJetHarvardPump::SetSyringeDiameter( const double dbDiameter/*=4.608*/ )
{
	m_strSend.Format(TEXT("diameter %f mm\r"), dbDiameter);
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

BOOL CJetHarvardPump::SetSyringeVolume(double dbVolume)
{
	m_strSend.Format(TEXT("svolume %f ul\r"), dbVolume);
	m_comm.GetResponse(m_strSend, m_strReceive);

	return TRUE;
}

void CJetHarvardPump::CloseHarvardPump()
{
	m_comm.Close();
}