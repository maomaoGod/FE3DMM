#pragma once
class CFE3DMMDlg;
class CParamData;

class CProcessLaserStrip
{
public:
	CProcessLaserStrip(void);
	~CProcessLaserStrip(void);

	void SetMainDlgPointer(CFE3DMMDlg* pDlg);		    //设置主窗口指针
	void Init();
	void Release();
	void Home();										//回零
	void SetParamData(CParamData* pData);				//设置配置参数类指针

	//CCtrlMotor* GetMotorLaserStripX();
	//CCtrlMotor* GetMotorLaserStripY();

//2017.03.23 Edited By Zhoulaoboyang
	void TransferPara(double ScanLen,double ScanSpace,double ScanSpeed,double TransRowSpeed,int ScanNum);		//传递P变量到下位机
	bool GetProgStatus();																						//程序运行状态，无程序运行=0，有程序运行=1；
	void RunProgram();																						    //启动下位机程序

private:
	CFE3DMMDlg*					m_pMainDlg;					//主对话框指针
	CParamData*					m_pParamData;				//配置参数类指针


	//运动电机
// 	CCtrlMotor				m_MotorLaserStripX;
// 	CCtrlMotor				m_MotorLaserStripY;

// 2017.03.23 Edited By Zhoulaoboyang
	//下位机程序
	CCtrlProg				m_Prog200;					//行扫描自动程序

	//P变量
	CCtrlParam				m_P200;						// 下位机>>上位机 程序开始=1，程序结束=0
	CCtrlParam				m_P201;						// 上位机>>下位机 扫描长度 L
	CCtrlParam				m_P202;						// 上位机>>下位机 扫描间距 D
	CCtrlParam				m_P203;						// 上位机>>下位机 扫描速度 Vl
	CCtrlParam				m_P204;						// 上位机>>下位机 换行速度 Vd
	CCtrlParam				m_P205;						// 上位机>>下位机 扫描列数 N
//
};

