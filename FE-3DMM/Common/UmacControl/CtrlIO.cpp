#include "StdAfx.h"
#include "CtrlIO.h"


CCtrlIO::CCtrlIO(void)
{
	m_lCard = 0;
	m_strName = _T("");
	m_strDescri = _T("");
	m_strCommand = _T("");
	m_strAnswer = _T("");

	//调用PcommServer组件
	/*CoInitialize(NULL);
	BOOL bSuccess = m_pmacDevice.CreateDispatch(_T("PcommServer.PmacDevice.1"));
	if (!bSuccess) 
	{
		AfxMessageBox(_T("Can Not Connect PcommServer Interface "));
	}*/
}


CCtrlIO::~CCtrlIO(void)
{
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlIO::ConfigIO(long card, CString name, CString descri)
{
	m_lCard = card;
	m_strName = name;
	m_strDescri = descri;
}


void CCtrlIO::SendCommand()
{
	BSTR answer = ::SysAllocString(L"");
	long status;
	m_pmacDevice.GetResponseEx(m_lCard, /*(LPCTSTR)*/m_strCommand, FALSE, &answer, &status);
	m_strAnswer = answer;
	SysFreeString(answer);
}


void CCtrlIO::On()
{
	m_strCommand = m_strName + _T("=1");
	SendCommand();
}


void CCtrlIO::Off()
{
	m_strCommand = m_strName + _T("=0");
	SendCommand();
}


int CCtrlIO::GetIoState()
{
	m_strCommand = m_strName;
	SendCommand();
	return atoi(m_strAnswer);
}