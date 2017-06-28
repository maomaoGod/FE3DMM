#include "StdAfx.h"
#include "CtrlParam.h"


CCtrlParam::CCtrlParam(void)
{
	m_lCard = 0;
	m_strName = _T("");
	m_strDescri = _T("");
	m_strCommand = _T("");
	m_strAnswer = _T("");

	////调用PcommServer组件
	//CoInitialize(NULL);
	//BOOL bSuccess = m_pmacDevice.CreateDispatch(_T("PcommServer.PmacDevice.1"));
	//if (!bSuccess) 
	//{
	//	AfxMessageBox(_T("Can Not Connect PcommServer Interface "));
	//}
}


CCtrlParam::~CCtrlParam(void)
{
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlParam::ConfigParam(long card, CString name, CString descri)
{
	m_lCard = card;
	m_strName = name;
	m_strDescri = descri;
}


void CCtrlParam::SendCommand()
{
	BSTR answer = ::SysAllocString(L"");
	long status;
	m_pmacDevice.GetResponseEx(m_lCard, /*(LPCTSTR)*/m_strCommand, FALSE, &answer, &status);
	m_strAnswer = answer;
	SysFreeString(answer);
}


void CCtrlParam::SetParamValue(float fValue)
{
	CString strVal = _T("");
	strVal.Format("=%f", fValue);
	m_strCommand = m_strName + strVal;
	SendCommand();
}


long CCtrlParam::GetParamValue()
{
	m_strCommand = m_strName;
    SendCommand();
	return atol(m_strAnswer);
}