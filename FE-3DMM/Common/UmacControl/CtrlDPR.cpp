#include "StdAfx.h"
#include "CtrlDPR.h"


CCtrlDPR::CCtrlDPR(void)
{
	m_lCard = 0;
	m_nOffset = 0;
	m_nBit = 0;
	m_strDescri = _T("");

	////调用PcommServer组件
	//CoInitialize(NULL);
	//BOOL bSuccess = m_pmacDevice.CreateDispatch(_T("PcommServer.PmacDevice.1"));
	//if (!bSuccess) 
	//{
	//	AfxMessageBox(_T("Can Not Connect PcommServer Interface "));
	//}
}


CCtrlDPR::~CCtrlDPR(void)
{
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlDPR::ConfigDPR(long card, UINT offset, UINT bit, CString descri)
{
	m_lCard = card;
	m_nOffset = offset;
	m_nBit = bit;
	m_strDescri = descri;
}


long CCtrlDPR::GetDprValue(UINT offset)
{
	long lVal = 0;
	BOOL bSuccess = FALSE;
	m_pmacDevice.DPRGetLong(m_lCard, offset*4, &lVal, &bSuccess);
	return lVal;
}


void CCtrlDPR::ResetDpr()
{
	BOOL bSuccess = FALSE;
	m_pmacDevice.DPRResetDWordBit(m_lCard, m_nOffset*4, m_nBit, &bSuccess);
}


void CCtrlDPR::ResetDpr(UINT offset, UINT bit)
{
	BOOL bSuccess = FALSE;
	m_pmacDevice.DPRResetDWordBit(m_lCard, offset*4, bit, &bSuccess);
}