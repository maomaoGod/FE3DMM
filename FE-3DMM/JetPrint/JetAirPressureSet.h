#pragma once

#include "JetAirPressurePort.h"

//模拟量输入类型 MA_0_20: 0-20mA, MA_4_20: 4-20mA, V_0_5: 0-5V, V_0_10: 0-10V
enum AnalogType{ EMPTY_TYPE = -1, MA_0_20,  MA_4_20, V_0_5, V_0_10};

class CJetAirPressureSet
{
public:
	CJetAirPressureSet(void);
	virtual ~CJetAirPressureSet(void);

public:
	BOOL Init(unsigned long xPort,//串口号
		      unsigned long xBabd = 9600,//波特率
			  unsigned char xDataSize = 8, //数据位
		      unsigned char xParity = 0, //校验位
		      unsigned char xStopBit = 0);//停止位

	BOOL UnInit();
	BOOL SetAnalogInputType(int type);				//设置模拟量输入类型 0: 0-20mA, 1: 4-20mA, 2: 0-5V, 3: 0-10V
	BOOL WriteData(int channel, float voltage);  //向模拟量第channel输出通道写值, channel=0:3
	BOOL ReadData(int channel, float *pVal);		//向模拟量第channel输入通道读取值, channel=0:3
		
private:
	BOOL CheckConnect();
	BOOL WriteData(unsigned char regLoc_H, unsigned char regLoc_L, float val, AnalogType analogtype);      //向保存寄存器写值
	BOOL ReadData(unsigned char regLoc_H, unsigned char regLoc_L, float *pVal, AnalogType analogtype);	  //读取输入寄存器的值
	unsigned short CalcCrcFast(unsigned char* puchMsg, unsigned short usDataLen);

private:
	CJetAirPressurePort m_comm;
	AnalogType m_enumAnalogType;     //模拟量输入类型
};

