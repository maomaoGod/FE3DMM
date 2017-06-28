#include "StdAfx.h"
#include "CtrlProg.h"


CCtrlProg::CCtrlProg(void)
{
	m_lCard = 0;
	m_nCoordNO = -1;
	m_nProgNO = -1;
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


CCtrlProg::~CCtrlProg(void)
{
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlProg::ConfigProg(long card, int coordNo, int progNo, CString descri)
{
	m_lCard = card;
	m_nCoordNO = coordNo;
	m_nProgNO = progNo;
	m_strDescri = descri;
}


void CCtrlProg::SendCommand()
{
	BSTR answer = ::SysAllocString(L"");
	long status;
	m_pmacDevice.GetResponseEx(m_lCard, /*(LPCTSTR)*/m_strCommand, FALSE, &answer, &status);
	SysFreeString(answer);
}


void CCtrlProg::Run()
{
	m_strCommand.Format("&%dB%dR", m_nCoordNO, m_nProgNO);
	SendCommand();
}


void CCtrlProg::Stop()
{
	m_strCommand.Format("&%dA", m_nCoordNO);
	SendCommand();
}