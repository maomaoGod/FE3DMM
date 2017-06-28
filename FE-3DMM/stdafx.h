
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持


#define	FE_DEBUG_OFFLINE		//离线调试使用
#define UM_INITIALIZE													WM_USER+10		//初始化自定义消息
#define UM_IDM_PRINT_CAMERAWATCH_SHOW   WM_USER+50		//墨点观测相机弹出式菜单自定义显示消息
#define UM_IDM_MOTION_LINE_DELETE					WM_USER+51      //连线学习中右键弹出式菜单自定义删除消息
#define UM_IDM_MOTION_LINE_CLEAR						WM_USER+52      //连线学习中右键弹出式菜单自定义清空消息

#define _DEBUGE_VISA 0

//数据库组件及头文件
#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "adoEOF")
#include "./Common/Database/AdoRecordset.h"

//主操作类头文件
#include "ProcessCore.h" 

//自定义控件头文件
#include "./Common/CustomControl/BmpBtn.h"		
#include "./Common/CustomControl/CustomEdit.h"
#include "./Common/CustomControl/ListCtrlCl.h"
#include "./Common/CustomControl/XPGroupBox.h"
#include "./Common/CustomControl/D2DCustomeTable.h"
#include "./Common/CustomControl/PanelWnd.h"
#include "./Common/CustomControl/GridCtrl/GridCtrl.h"
#include "./Common/CustomControl/GradientProgressCtrl.h"
#include "./Common/CustomControl/ImageShowStatic.h"
#include "./Common/CustomControl/ReadOnlyEdit.h"
#include "./Common/CustomControl/mySliderControl.h"

#import "./3DMeasure/LaserCOM.tlb" no_namespace//程序根目录下
extern CString m_gAppExePath;	 //.Exe路径


/**************************转印加的内容**********************************/

//自定义控件头文件

#define NEGATIVE 0  //电机方向-反转
#define POSITIVE 1   //正转


//转印自定义消息
#define WM_CHANGETIPS WM_USER+1
/************************************************************************/



#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


