#include "stdafx.h"
#include "JetAglientFunction.h"

#if _DEBUGE_VISA
#pragma comment(lib,"visa32.lib")
#endif

CJetAglientFunction::CJetAglientFunction()
{
	m_bIsConn = false;
}


CJetAglientFunction::~CJetAglientFunction()
{
	//自动关闭连接
	Disconnect();
}

bool CJetAglientFunction::Connect()
{
	ViString intFName[512];
	ViUInt16 intFType;

	//先关闭已经连接的后重新打开连接
	if (m_bIsConn == true)
	{
		Disconnect();
	}

	//打开并初始化总资源管理器
#if _DEBUGE_VISA
	viOpenDefaultRM(&m_drms);
#endif
	//FullName is USB0::0x0957::0x2C07::MY52814499::0::INSTR,
	//To make this more portable ,use UsbDevice1 Instead
	//打开并初始化一指定的资源会话
#if _DEBUGE_VISA
	viOpen(m_drms, 
		   "USB0::0x0957::0x2C07::MY52814499::0::INSTR",
		   VI_NULL, 
		   VI_NULL, 
		   &Function_Generator_33500B);   

	//确认默认的函数发生器命令是否以\n结束，这里定义的SCPI语言是必须以\n结尾的  
	ViBoolean termDefaultFunction_Generator_33500B = VI_FALSE;
	if ((VI_SUCCESS == viGetAttribute(Function_Generator_33500B, 
									  VI_ATTR_RSRC_CLASS, 
									  intFName))
		&& (0 == strcmp("SOCKET", (ViString)intFName)))
	{
		termDefaultFunction_Generator_33500B = VI_TRUE;
	}
	else if ((VI_SUCCESS == viGetAttribute(Function_Generator_33500B, 
										   VI_ATTR_INTF_TYPE, 
										   &intFType)) 
		&& (intFType == VI_INTF_USB))
	{
		termDefaultFunction_Generator_33500B = VI_TRUE;
	}

	if (VI_TRUE == termDefaultFunction_Generator_33500B)
	{ 
		viSetAttribute(Function_Generator_33500B, 
					   VI_ATTR_TERMCHAR_EN, 
					   termDefaultFunction_Generator_33500B);

		//默认为DC
		//SetDCFunction();
		//SetOffset(0);
		//SetOutput(false);

		 m_bIsConn = true;
	}
	else
	{
		 m_bIsConn = false;
	}
#endif

	return m_bIsConn;
}

bool CJetAglientFunction::Disconnect()
{
	if (m_bIsConn == true)
	{
		//关闭到指定的USB接口控制的函数发生器的连接
#if _DEBUGE_VISA
		viClose(Function_Generator_33500B);

		//关闭总的资源管理器
		if (VI_SUCCESS == viClose(m_drms))
		{
			m_bIsConn = false;
			return true;
		}
		else
		{
			m_bIsConn = true;
			return false;
		}
#endif
	}

	return true;
}

//设置波形为直流输出
//offset为默认初始电压
void CJetAglientFunction::SetDCMode(double offset/*=0*/)
{
	//DC波形
#if _DEBUGE_VISA
	viPrintf(Function_Generator_33500B, ":SOURce:FUNCtion %s\n", "DC");

	//设置电压单位为V
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:UNIT VPP\n");

	//电压上下限位-5~+5V
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:LIMit:HIGH %@3lf\n", 5.0); //最大输出电压 
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:LIMit:LOW %@3lf\n", -5.0); //最小输出电压 
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:LIMit:STATe %@1d\n", 1);
#endif
	SetOffset(offset);
}

//设置波形为方波
void CJetAglientFunction::SetACMode()
{
	//方波波形
#if _DEBUGE_VISA
	viPrintf(Function_Generator_33500B, ":SOURce:FUNCtion %s\n", "SQUare");

	//设置电压单位为V
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:UNIT VPP\n");

	//电压上下限位-5~+5V
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:LIMit:HIGH %@3lf\n", 5.0); //最大输出电压 
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:LIMit:LOW %@3lf\n", -5.0); //最小输出电压 
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:LIMit:STATe %@1d\n", 1); 

	//方波开启触发，门控模式
	viPrintf(Function_Generator_33500B, ":SOURce:BURSt:MODE GATed\n"); 
	viPrintf(Function_Generator_33500B, ":SOURce:BURSt:STATe %@1d\n", 1);

	//上升沿触发
	viPrintf(Function_Generator_33500B, ":TRIGger:SLOPe POSitive\n");
#endif
}

//电压偏执为offset mV，范围为-5000~5000
void CJetAglientFunction::SetOffset( double offset )
{
#if _DEBUGE_VISA
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage:OFFSet %@3lf mV\n", offset);
#endif
}

//频率(kHz) 
void CJetAglientFunction::SetFrequency( double freq )
{
#if _DEBUGE_VISA
	viPrintf(Function_Generator_33500B, ":SOURce:FREQuency %@3lf HZ\n", freq);       
#endif
}

//幅值,单位为V
void CJetAglientFunction::SetAmplitude( double amp )
{
#if _DEBUGE_VISA
	viPrintf(Function_Generator_33500B, ":SOURce:VOLTage %@3lf mV\n", amp);
#endif
}

//方波波形占空比,%多少
void CJetAglientFunction::SetRatio( double dCycle )
{
#if _DEBUGE_VISA
	viPrintf(Function_Generator_33500B, ":SOURce:FUNCtion:SQUare:DCYCle %@3lf\n", dCycle);
#endif
}

//是否输出电压信号
void CJetAglientFunction::SetOutput( bool isOutput )
{
#if _DEBUGE_VISA
	viPrintf(Function_Generator_33500B, ":OutPut %@1d\n", isOutput==true ? 1 : 0);
#endif
}

bool CJetAglientFunction::IsDeviceConnect() const
{
	return m_bIsConn;
}