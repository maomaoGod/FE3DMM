#include "StdAfx.h"
#include "CtrlMotor.h"


CCtrlMotor::CCtrlMotor(void)
{
	m_lCard = 0;
	m_nMotorID = -1;
	m_strDescri = _T("");
	m_strCommand = _T("");
	m_strAnswer = _T("");

	/*调用PcommServer组件
	CoInitialize(NULL);
	BOOL bSuccess = m_pmacDevice.CreateDispatch(_T("PcommServer.PmacDevice.1"));
	if (!bSuccess)
	{
	AfxMessageBox(_T("Can Not Connect PcommServer Interface "));
	}*/
}


CCtrlMotor::~CCtrlMotor(void)
{
	m_pmacDevice.ReleaseDispatch();
	CoUninitialize();
}


void CCtrlMotor::ConfigMotor(long card, int motorID, CString descri)
{
	m_lCard = card;
	m_nMotorID = motorID;
	m_strDescri = descri;
}


void CCtrlMotor::SendCommand()
{
	BSTR answer = ::SysAllocString(L"");
	long status;
	m_pmacDevice.GetResponseEx(m_lCard, /*(LPCTSTR)*/m_strCommand, FALSE, &answer, &status);
	m_strAnswer = answer;
	SysFreeString(answer);
}


void CCtrlMotor::Jog(UINT nDir)
{
	if (nDir == 0)
		m_strCommand.Format("#%dj-", m_nMotorID);
	else if (nDir == 1)
		m_strCommand.Format("#%dj+", m_nMotorID);
	else return;

	SendCommand();
}


void CCtrlMotor::MoveTo(double dPos)
{
	m_strCommand.Format("#%dj=%f", m_nMotorID, dPos);
	SendCommand();
}


void CCtrlMotor::Move(double dDis)
{
	m_strCommand.Format("#%dj^%f", m_nMotorID, dDis);
	SendCommand();
}


void CCtrlMotor::JogStop()
{
	Enable();
}


void CCtrlMotor::Enable()
{
	m_strCommand.Format("#%dj/", m_nMotorID);
	SendCommand();
}


void CCtrlMotor::Disable()
{
	m_strCommand.Format("#%dk", m_nMotorID);
	SendCommand();
}


void CCtrlMotor::Home()
{
	m_strCommand.Format("homez %d", m_nMotorID);
	SendCommand();
}


float CCtrlMotor::GetMotorPostion()
{
	m_strCommand.Format("m%d62", m_nMotorID);
	SendCommand();
	float fPos = atof(m_strAnswer) / 3072.0;
	return fPos;
}


void CCtrlMotor::SetSpeed(double dSpeed)
{
	if (dSpeed <= 0.0)
	{
		return;
	}
	else
	{
		m_strCommand.Format("I%d22=%f", m_nMotorID, dSpeed);
		SendCommand();
	}
}