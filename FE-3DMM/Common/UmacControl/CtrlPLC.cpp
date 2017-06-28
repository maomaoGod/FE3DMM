#include "StdAfx.h"
#include "CtrlPLC.h"


CCtrlPLC::CCtrlPLC(void)
{
	m_lCard = 0;
	m_nPlcNO = -1;
	m_strDescri = _T("");
	m_strCommand = _T("");

	////调用PcommServer组件
	//CoInitialize(NULL);
	//BOOL bSuccess = m_pmacDevice.CreateDispatch(_T("PcommServer.PmacDevice.1"));
	//if (!bSuccess) 
	//{
	//	AfxMessageBox(_T("Can Not Connect PcommServer Interface "));
	//}
}


CCtrlPLC::~CCtrlPLC(void)
{
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlPLC::ConfigPLC(long card, int plcNo, CString descri)
{
	m_lCard = card;
	m_nPlcNO = plcNo;
	m_strDescri = descri;
}


void CCtrlPLC::SendCommand()
{
	BSTR answer = ::SysAllocString(L"");
	long status;
	m_pmacDevice.GetResponseEx(m_lCard, /*(LPCTSTR)*/m_strCommand, FALSE, &answer, &status);
	SysFreeString(answer);
}


void CCtrlPLC::Enable()
{
	m_strCommand.Format("enable PLC %d", m_nPlcNO);
	SendCommand();
}


void CCtrlPLC::Disable()
{
	m_strCommand.Format("disable PLC %d", m_nPlcNO);
	SendCommand();
}