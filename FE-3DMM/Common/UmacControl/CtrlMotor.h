#pragma once
#include "PmacDevice.h"

class CCtrlMotor : private CPmacDevice
{
public:
	CCtrlMotor(void);
	~CCtrlMotor(void);

	void ConfigMotor(long card, int motorID, CString descri);
	void SendCommand();
	void Jog(UINT nDir);		  //电机Jog
	void MoveTo(double dPos);	  //电机Jog至某位置
	void Move(double dDis);		  //电机Jog一段距离
	void JogStop();				  //电机停止Jog
	void Enable();				  //电机使能,同时能让电机停止Jog
	void Disable();				  //电机禁能
	void Home();				  //电机回零
	float GetMotorPostion();	  //获得电机位置
	void SetSpeed(double dSpeed); //设置电机速度

private:
	CPmacDevice  m_pmacDevice;
	long		 m_lCard;         //卡号
	int			 m_nMotorID;      //电机ID
	CString		 m_strDescri;     //电机描述
	CString		 m_strCommand;	  //命令
	CString		 m_strAnswer;	  //下位机对应变量值
};

