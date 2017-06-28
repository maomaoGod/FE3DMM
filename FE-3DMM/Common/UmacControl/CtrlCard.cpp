#include "StdAfx.h"
#include "CtrlCard.h"


CCtrlCard::CCtrlCard(void)
{
	m_bConnectPmacFlag = FALSE;
	m_lCard	= 0;

	//调用PcommServer组件
	/*CoInitialize(NULL);
	BOOL bSuccess = m_pmacDevice.CreateDispatch(_T("PcommServer.PmacDevice.1"));
	if (!bSuccess)
	{
	AfxMessageBox(_T("Can Not Connect PcommServer Interface "));
	}*/
}


CCtrlCard::~CCtrlCard(void)
{
	if (m_bConnectPmacFlag)
		m_pmacDevice.Close(m_lCard);
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlCard::ConfigCard(long card)
{
	m_lCard = card;
}


void CCtrlCard::ConnectPmacCard()
{
	m_pmacDevice.Open(m_lCard, &m_bConnectPmacFlag);  //dwDevice=0对应Pmac00
	if (!m_bConnectPmacFlag)
	{
		AfxMessageBox(_T("Unable to communicate to PMAC!"));
	}
}


BOOL CCtrlCard::IsConnectPmac()
{
	return m_bConnectPmacFlag;
}


void CCtrlCard::Save()
{
	CString strCommand = _T("save");
	BSTR answer = ::SysAllocString(L"");
	long status;
	m_pmacDevice.GetResponseEx(m_lCard, /*(LPCTSTR)*/strCommand, FALSE, &answer, &status);
	SysFreeString(answer);
}