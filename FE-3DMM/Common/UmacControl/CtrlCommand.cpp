#include "StdAfx.h"
#include "CtrlCommand.h"


CCtrlCommand::CCtrlCommand(long card)
{
	m_lCard	= card;

	//调用PcommServer组件
	/*CoInitialize(NULL);
	BOOL bSuccess = m_pmacDevice.CreateDispatch(_T("PcommServer.PmacDevice.1"));
	if (!bSuccess) 
	{
		AfxMessageBox(_T("Can Not Connect PcommServer Interface "));
	}*/
}


CCtrlCommand::~CCtrlCommand(void)
{
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlCommand::ConfigCommand(long card)
{
	m_lCard = card;
}


void CCtrlCommand::GiveCommand(LPCTSTR strCommand)
{
	BSTR answer = ::SysAllocString(L"");
	long status;
	m_pmacDevice.GetResponseEx(m_lCard, strCommand, FALSE, &answer, &status);
	SysFreeString(answer);
}