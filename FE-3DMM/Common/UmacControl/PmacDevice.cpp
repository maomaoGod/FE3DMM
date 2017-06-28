#include "stdafx.h"
#include "PmacDevice.h"

void CPmacDevice::Open(long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}
void CPmacDevice::Close(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
void CPmacDevice::DataStart(long dwDevice, long resolution, long period)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, resolution, period);
}
void CPmacDevice::DataStop(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
void CPmacDevice::DataCollect(long dwDevice, VARIANT * pvArray, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PBOOL ;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pvArray, pbSuccess);
}
void CPmacDevice::DPRBackGroundVar(long dwDevice, BOOL bOn)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bOn);
}
void CPmacDevice::DPRAddressRange(long dwDevice, BOOL bUpper, BOOL bPC, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL VTS_BOOL VTS_PI4 ;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bUpper, bPC, pVal);
}
void CPmacDevice::GetPmacType(long dwDevice, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 ;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::DPRVarBufRemove(long dwDevice, long index, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, index, pbSuccess);
}
void CPmacDevice::DPRVarBufRead(long dwDevice, long h, long entryNum, VARIANT * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PVARIANT VTS_PBOOL ;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, h, entryNum, pVal, pbSuccess);
}
void CPmacDevice::DPRGetFloat(long dwDevice, long offset, float * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PR4 VTS_PBOOL ;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, pVal, pbSuccess);
}
void CPmacDevice::DPRGetLong(long dwDevice, long offset, long * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, pVal, pbSuccess);
}
void CPmacDevice::DPRVarBufInit(long dwDevice, VARIANT& vAddressArray, VARIANT& vTypeArray, long * pHandle, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, &vAddressArray, &vTypeArray, pHandle, pbSuccess);
}
void CPmacDevice::DPRSetFloat(long dwDevice, long offset, float newVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R4 VTS_PBOOL ;
	InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, newVal, pbSuccess);
}
void CPmacDevice::DPRSetLong(long dwDevice, long offset, long newVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, newVal, pbSuccess);
}
void CPmacDevice::DPRVarBufWrite(long dwDevice, VARIANT& vData, VARIANT& vAddresses, VARIANT& vTypes, long * pWritten)
{
	static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_PI4 ;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, &vData, &vAddresses, &vTypes, pWritten);
}
void CPmacDevice::DPRFloat(__int64 d, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I8 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, parms, d, scale, pVal);
}
void CPmacDevice::GetRomVersion(long dwDevice, BSTR * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PBSTR ;
	InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::GetRomDate(long dwDevice, BSTR * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PBSTR ;
	InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::GetPmacLocation(long dwDevice, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 ;
	InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::GetResponse(long dwDevice, LPCTSTR question, BSTR * pAnswer)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR ;
	InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, pAnswer);
}
void CPmacDevice::SelectDevice(long hWindow, long * pDeviceNumber, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, hWindow, pDeviceNumber, pbSuccess);
}
long CPmacDevice::get_DPRSize(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_DPRAvailable(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::SetChecksums(long dwDevice, BOOL bActive)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bActive);
}
void CPmacDevice::GetControlResponse(long dwDevice, short question, BSTR * pAnswer)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_PBSTR ;
	InvokeHelper(0x1e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, pAnswer);
}
long CPmacDevice::get_LastCommError(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::GetLastCommErrorStr(long dwDevice, BSTR * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PBSTR ;
	InvokeHelper(0x20, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::GetMacroIVariableLong(long dwDevice, long node, long num, long def, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0x21, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, node, num, def, pVal);
}
BOOL CPmacDevice::get_DoChecksums(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_DoChecksums(long dwDevice, BOOL newValue)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0x25, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
void CPmacDevice::GetIVariableLong(long dwDevice, long num, long def, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0x26, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, num, def, pVal);
}
void CPmacDevice::GetIVariableDouble(long dwDevice, long num, double def, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x27, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, num, def, pVal);
}
void CPmacDevice::SetIVariableLong(long dwDevice, long num, long newVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
	InvokeHelper(0x28, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, num, newVal);
}
void CPmacDevice::SetIVariableDouble(long dwDevice, long num, double newVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 ;
	InvokeHelper(0x29, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, num, newVal);
}
void CPmacDevice::GetAsciiComm(long dwDevice, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 ;
	InvokeHelper(0x2a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::SetAsciiComm(long dwDevice, long newVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x2b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, newVal);
}
void CPmacDevice::GetVariableLong(long dwDevice, short ch, long num, long def, long * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_I4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x2c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, ch, num, def, pVal, pbSuccess);
}
void CPmacDevice::GetVariableDouble(long dwDevice, short ch, long num, double def, double * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_R8 VTS_PR8 VTS_PBOOL ;
	InvokeHelper(0x2d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, ch, num, def, pVal, pbSuccess);
}
void CPmacDevice::SetVariableLong(long dwDevice, short ch, long num, long newVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x2e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, ch, num, newVal, pbSuccess);
}
void CPmacDevice::SetVariableDouble(long dwDevice, short ch, long num, double newVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_R8 VTS_PBOOL ;
	InvokeHelper(0x2f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, ch, num, newVal, pbSuccess);
}
BOOL CPmacDevice::get_InBootStrapMode(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_MotionBufferOpen(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_RotaryBufferOpen(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_IsTurbo(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::RestoreLinkList(LPCTSTR firmwareVersion, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0x34, DISPATCH_METHOD, VT_EMPTY, NULL, parms, firmwareVersion, pbSuccess);
}
void CPmacDevice::BackupLinkList(long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x35, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}
void CPmacDevice::SetCriticalIVars(long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x36, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}
void CPmacDevice::GetLocAndEnum(long dwDevice, long * pLoc, long * pEnum, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x39, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pLoc, pEnum, pbSuccess);
}
void CPmacDevice::GetProgramInfo(long dwDevice, BOOL bPlc, long num, long * pSAdr, long * pFAdr)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL VTS_I4 VTS_PI4 VTS_PI4 ;
	InvokeHelper(0x3a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bPlc, num, pSAdr, pFAdr);
}
void CPmacDevice::DownloadFile(long dwDevice, LPCTSTR filePath)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR ;
	InvokeHelper(0x3b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, filePath);
}
void CPmacDevice::AbortDownload(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x3c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
void CPmacDevice::DownloadFirmwareFile(long dwDevice, LPCTSTR filePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0x3d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, filePath, pbSuccess);
}
void CPmacDevice::Download(long dwDevice, LPCTSTR filePath, BOOL bMacro, BOOL bMap, BOOL bLog, BOOL bDnld, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0x3e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, filePath, bMacro, bMap, bLog, bDnld, pbSuccess);
}
BOOL CPmacDevice::get_Downloading(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x3f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
long CPmacDevice::get_MaxDownloadErrors()
{
	long result;
	InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}
void CPmacDevice::put_MaxDownloadErrors(long newValue)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x40, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}
void CPmacDevice::CompilePLCC(long dwDevice, LPCTSTR inFilePath, LPCTSTR outFilePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0x41, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, inFilePath, outFilePath, pbSuccess);
}
void CPmacDevice::SendCommand(long dwDevice, LPCTSTR cmd, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
	InvokeHelper(0x42, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, cmd, pstatus);
}
void CPmacDevice::GetPlcStatus(long dwDevice, long * pNumPlc, long * pNumPlcc, long * pI5)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 ;
	InvokeHelper(0x44, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pNumPlc, pNumPlcc, pI5);
}
void CPmacDevice::GetFirstPlcc(long dwDevice, BOOL * pbLoaded, BOOL * pbEnabled, long * pStartAdr, long * pLastAdr, long * pSize, BOOL * pbMore)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL VTS_PBOOL VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x45, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbLoaded, pbEnabled, pStartAdr, pLastAdr, pSize, pbMore);
}
void CPmacDevice::GetNextPlcc(long dwDevice, BOOL * pbLoaded, BOOL * pbEnabled, long * pStartAdr, long * pLastAdr, long * pSize, BOOL * pbMore)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL VTS_PBOOL VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x46, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbLoaded, pbEnabled, pStartAdr, pLastAdr, pSize, pbMore);
}
void CPmacDevice::GetFirstPlc(long dwDevice, BOOL * pbEnabled, long * pStartAdr, long * pLastAdr, long * pSize, BOOL * pbMore)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x47, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbEnabled, pStartAdr, pLastAdr, pSize, pbMore);
}
void CPmacDevice::GetNextPlc(long dwDevice, BOOL * pbEnabled, long * pStartAdr, long * pLastAdr, long * pSize, BOOL * pbMore)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x48, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbEnabled, pStartAdr, pLastAdr, pSize, pbMore);
}
BOOL CPmacDevice::get_IsAnyPlcRunning(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::GetGlobalStatus(long dwDevice, long * pStatusX, long * pStatusY, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x4a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pStatusX, pStatusY, pbSuccess);
}
void CPmacDevice::GetCoordStatus(long dwDevice, long dwCoord, long * pStatusX, long * pStatusY, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x4b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pStatusX, pStatusY, pbSuccess);
}
void CPmacDevice::GetMotorStatus(long dwDevice, long lMotor, long * pStatusX, long * pStatusY, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x4c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, lMotor, pStatusX, pStatusY, pbSuccess);
}
BOOL CPmacDevice::get_SysServoError(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x4d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_SysReEntryError(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x4e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_SysMemChecksumError(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x4f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_SysPromChecksumError(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_SysInposition(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x51, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_SysWarnFError(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x52, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_SysFatalFError(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x53, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_SysRuntimeError(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x54, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_SysCircleRadError(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x55, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_SysAmpFaultError(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x56, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
void CPmacDevice::GetCommandedPos(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x57, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetPosition(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x58, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetNetActualPosition(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x59, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetFollowError(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x5a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetVelocity(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x5b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetMasterPos(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x5c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetCompensationPos(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x5d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetTargetPos(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x5e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetBiasPos(long dwDevice, long mtr, double scale, double * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PR8 ;
	InvokeHelper(0x5f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, scale, pVal);
}
void CPmacDevice::GetProgExecPoint(long dwDevice, long dwCoord, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0x60, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pVal);
}
void CPmacDevice::GetRotBufFull(long dwDevice, long dwCoord, BOOL * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x61, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pVal);
}
BOOL CPmacDevice::get_ProgramRunning(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x62, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_ProgramStepping(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_ProgramContMotion(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_ProgramContRequest(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
long CPmacDevice::get_ProgramRemaining(long dwDevice, long dwCoord)
{
	long result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_MotionBufOpen(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
BOOL CPmacDevice::get_ProgramFeedMode(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_MotorAmpEnabled(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorWarnFError(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorFatalFError(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorAmpFault(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorOnPositionLimit(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorHomeComplete(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorInPosition(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
long CPmacDevice::get_TimRemInMove(long dwDevice, long dwCoord)
{
	long result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
long CPmacDevice::get_TimeRemInTATS(long dwDevice, long dwCoord)
{
	long result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice, dwCoord);
	return result;
}
BOOL CPmacDevice::get_MotorDataBlockError(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorPhased(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorEnabled(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorHandwheelEnabled(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorOpenLoop(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorOnNegLimit(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
BOOL CPmacDevice::get_MotorOnPosLimit(long dwDevice, long mtr)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, mtr);
	return result;
}
void CPmacDevice::SetJogReturn(long dwDevice, long mtr)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x7a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr);
}
void CPmacDevice::GetWhyMotorNotMoving(long dwDevice, long motor, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0x7b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, pVal);
}
void CPmacDevice::GetWhyMotorNotMovingStr(long err, BSTR * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PBSTR ;
	InvokeHelper(0x7c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, err, pVal);
}
void CPmacDevice::GetWhyCSNotMoving(long dwDevice, long cs, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0x7d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, cs, pVal);
}
void CPmacDevice::GetWhyCSNotMovingStr(long err, BSTR * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PBSTR ;
	InvokeHelper(0x7e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, err, pVal);
}
BOOL CPmacDevice::get_BufferOpen(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
long CPmacDevice::get_GatherPeriod(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_GatherPeriod(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
BOOL CPmacDevice::get_GatherEnabled(long dwDevice, long num)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice, num);
	return result;
}
void CPmacDevice::put_GatherEnabled(long dwDevice, long num, BOOL newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_BOOL ;
	InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, num, newValue);
}
long CPmacDevice::get_GatherMode(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_GatherMode(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
double CPmacDevice::get_GatherSampleTime(long dwDevice)
{
	double result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_GatherSampleTime(long dwDevice, double newValue)
{
	static BYTE parms[] = VTS_I4 VTS_R8 ;
	InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
void CPmacDevice::GetNumGatherSources(long dwDevice, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 ;
	InvokeHelper(0x84, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::GetNumGatherSamples(long dwDevice, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 ;
	InvokeHelper(0x85, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::SetGather(long dwDevice, long num, LPCTSTR str, BOOL bEnable, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0x86, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, num, str, bEnable, pbSuccess);
}
void CPmacDevice::SetQuickGather(long dwDevice, long lComMask, long lEncMask, long lDacMask, long lCurMask, BOOL bEnable, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0x87, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, lComMask, lEncMask, lDacMask, lCurMask, bEnable, pbSuccess);
}
void CPmacDevice::SetQuickGatherWithDirectCurrent(long dwDevice, long lComMask, long lEncMask, long lDacMask, long lCurMask, BOOL bEnable, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0x88, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, lComMask, lEncMask, lDacMask, lCurMask, bEnable, pbSuccess);
}
void CPmacDevice::GetGather(long dwDevice, long num, BSTR * pStr, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR VTS_PBOOL ;
	InvokeHelper(0x89, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, num, pStr, pbSuccess);
}
void CPmacDevice::ClearGather(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x8a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
void CPmacDevice::InitGather(long dwDevice, long size, double msec, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_R8 VTS_PBOOL ;
	InvokeHelper(0x8b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, size, msec, pbSuccess);
}
void CPmacDevice::ClearGatherData(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x8c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
void CPmacDevice::CollectGatherData(long dwDevice, long * pSources, long * pSamples, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pSources, pSamples, pbSuccess);
}
void CPmacDevice::GetGatherSamples(long dwDevice, long sourceNum, VARIANT * pVariant, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PVARIANT VTS_PBOOL ;
	InvokeHelper(0x8e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, sourceNum, pVariant, pbSuccess);
}
void CPmacDevice::GetGatherPoint(long dwDevice, long sourceNum, long sampleNum, double * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PR8 VTS_PBOOL ;
	InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, sourceNum, sampleNum, pVal, pbSuccess);
}
void CPmacDevice::StartGather(long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x90, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}
void CPmacDevice::StopGather(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x91, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
void CPmacDevice::InitPlotGather(long dwDevice, long size, long period, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x92, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, size, period, pbSuccess);
}
void CPmacDevice::ReadGatherFile(long dwDevice, LPCTSTR bsFilePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0x93, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bsFilePath, pbSuccess);
}
void CPmacDevice::WriteGatherFile(long dwDevice, LPCTSTR bsFilePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0x94, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bsFilePath, pbSuccess);
}
void CPmacDevice::strtod48f(LPCTSTR str, double * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_PR8 ;
	InvokeHelper(0x95, DISPATCH_METHOD, VT_EMPTY, NULL, parms, str, pVal);
}
void CPmacDevice::strtod48l(LPCTSTR str, double * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_PR8 ;
	InvokeHelper(0x96, DISPATCH_METHOD, VT_EMPTY, NULL, parms, str, pVal);
}
void CPmacDevice::strtod24(LPCTSTR str, double * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_PR8 ;
	InvokeHelper(0x97, DISPATCH_METHOD, VT_EMPTY, NULL, parms, str, pVal);
}
void CPmacDevice::strtod32dp(LPCTSTR str, double * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_PR8 ;
	InvokeHelper(0x98, DISPATCH_METHOD, VT_EMPTY, NULL, parms, str, pVal);
}
void CPmacDevice::strto32f(LPCTSTR str, double * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_PR8 ;
	InvokeHelper(0x99, DISPATCH_METHOD, VT_EMPTY, NULL, parms, str, pVal);
}
void CPmacDevice::UploadMacroConfig(long dwDevice, LPCTSTR bsFilePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0x9a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bsFilePath, pbSuccess);
}
void CPmacDevice::DownloadCurrentFeedbackTest(long dwDevice, short mtr, double pwmDutyCycle, short pwmFreq, BOOL bMacro, BOOL bUltra, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_R8 VTS_I2 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0x9b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, pwmDutyCycle, pwmFreq, bMacro, bUltra, pbSuccess);
}
void CPmacDevice::ReadResultsFromCurrentFeedbackTest(long dwDevice, short mtr, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_PI4 ;
	InvokeHelper(0x9c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, pVal);
}
void CPmacDevice::DownloadVoltageSixStepTest(long dwDevice, short mtr, double pwmDutyCycle, BOOL bMacro, BOOL bUltra, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_R8 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0x9d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mtr, pwmDutyCycle, bMacro, bUltra, pbSuccess);
}
void CPmacDevice::ReadResultsFromSixStepTest(long dwDevice, BOOL bSipFirstStep, VARIANT * pvStepArray, long * pResult)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL VTS_PVARIANT VTS_PI4 ;
	InvokeHelper(0x9e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bSipFirstStep, pvStepArray, pResult);
}
void CPmacDevice::DownloadCurrentSixStepTest(long dwDevice, short motor, double pwmDutyCycle, BOOL bMacro, BOOL bUltra, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_R8 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0x9f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, pwmDutyCycle, bMacro, bUltra, pbSuccess);
}
void CPmacDevice::DownloadOpenLoopTest(long dwDevice, short motor, short magnitude, short time, short reps, BOOL bGatherCurrents, BOOL bMacro, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xa0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, magnitude, time, reps, bGatherCurrents, bMacro, pbSuccess);
}
void CPmacDevice::DownloadOpenLoopTest1(long dwDevice, short motor, short magnitude, short time, short reps, BOOL bGatherCurrents, BOOL bMacro, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xa1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, magnitude, time, reps, bGatherCurrents, bMacro, pbSuccess);
}
void CPmacDevice::DownloadVelLimitPLC(long dwDevice, short motor, long maxspd, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xa2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, maxspd, pbSuccess);
}
void CPmacDevice::DownloadPosLimitPLC(long dwDevice, short motor, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_PBOOL ;
	InvokeHelper(0xa3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, pbSuccess);
}
void CPmacDevice::DownloadUVWSixStepTest(long dwDevice, short motor, double pwmDutyCycle, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_R8 VTS_PBOOL ;
	InvokeHelper(0xa4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, pwmDutyCycle, pbSuccess);
}
void CPmacDevice::ReadResultsFromUVWSixStepTest(long dwDevice, VARIANT * pvArray, long * pResult)
{
	static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PI4 ;
	InvokeHelper(0xa5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pvArray, pResult);
}
void CPmacDevice::SetIVarForFeedback(long dwDevice, short ivar, long address, long fbType, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xa6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, ivar, address, fbType, pbSuccess);
}
void CPmacDevice::DownloadAndRunRoughPhasePLC(long dwDevice, short motor, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_PBOOL ;
	InvokeHelper(0xa7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, pbSuccess);
}
void CPmacDevice::CreateIncrementalFinePhasePLC(long dwDevice, LPCTSTR filePath, short PLCNumber, short motor, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 VTS_I2 VTS_PBOOL ;
	InvokeHelper(0xa8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, filePath, PLCNumber, motor, pbSuccess);
}
void CPmacDevice::DoACurrentLoopStep(long dwDevice, short motor, short dwellTime, long magnitude, BOOL bAutoTune, BSTR * pbsCTSCurrent, double pwmDutyCycle, short divisor, BOOL bUltra)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I4 VTS_BOOL VTS_PBSTR VTS_R8 VTS_I2 VTS_BOOL ;
	InvokeHelper(0xa9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, dwellTime, magnitude, bAutoTune, pbsCTSCurrent, pwmDutyCycle, divisor, bUltra);
}
void CPmacDevice::DoACurrentLoopStepBrush(long dwDevice, short motor, short dwellTime, long magnitude, BOOL bAutoTune, BSTR * pbsCTSCurrent, double pwmDutyCycle, short divisor, BOOL bUltra)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I4 VTS_BOOL VTS_PBSTR VTS_R8 VTS_I2 VTS_BOOL ;
	InvokeHelper(0xaa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, dwellTime, magnitude, bAutoTune, pbsCTSCurrent, pwmDutyCycle, divisor, bUltra);
}
void CPmacDevice::DoAPositionLoopStep(long dwDevice, short motor, short stepSize, short stepTime, BOOL bBiDirectional, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xab, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, stepSize, stepTime, bBiDirectional, pbSuccess);
}
void CPmacDevice::DoAParabolicMove(long dwDevice, short motor, long stepSize, short stepTime, BOOL bBiDirectional, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_I2 VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xac, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, stepSize, stepTime, bBiDirectional, pbSuccess);
}
void CPmacDevice::DoAGantryPositionLoopStep(long dwDevice, short motor, short motor2, short stepSize, short stepTime, BOOL bBiDirectional, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xad, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, motor2, stepSize, stepTime, bBiDirectional, pbSuccess);
}
void CPmacDevice::DoAGantryParabolicMove(long dwDevice, short motor, short motor2, long stepSize, short stepTime, BOOL bBiDirectional, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I4 VTS_I2 VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xae, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, motor2, stepSize, stepTime, bBiDirectional, pbSuccess);
}
void CPmacDevice::DoAGantryParabolic(long dwDevice, short motor, short motor2, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_PBOOL ;
	InvokeHelper(0xaf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, motor2, pbSuccess);
}
void CPmacDevice::ConvertWordToStringFloat(LPCTSTR word, BSTR * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
	InvokeHelper(0xb0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, word, pVal);
}
void CPmacDevice::ConvertWordToShort(LPCTSTR word, short offset, short * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_I2 VTS_PI2 ;
	InvokeHelper(0xb1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, word, offset, pVal);
}
void CPmacDevice::ConvertWordToLong(LPCTSTR word, long * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_PI4 ;
	InvokeHelper(0xb2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, word, pVal);
}
void CPmacDevice::RestoreModifiedIVars(long dwDevice, short motor)
{
	static BYTE parms[] = VTS_I4 VTS_I2 ;
	InvokeHelper(0xb3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor);
}
void CPmacDevice::CalculateStepStatistics(VARIANT * pvData, long stepSize, long I10, long I19, BSTR * pbsRiseTime, BSTR * pbsPeakTime, BSTR * pbsNatFreq, BSTR * pbsOvershoot, BSTR * pbsDamping, BSTR * pbsSettleTime)
{
	static BYTE parms[] = VTS_PVARIANT VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR ;
	InvokeHelper(0xb4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pvData, stepSize, I10, I19, pbsRiseTime, pbsPeakTime, pbsNatFreq, pbsOvershoot, pbsDamping, pbsSettleTime);
}
void CPmacDevice::LowPassFilterTheData(VARIANT * pvData, LPCTSTR bsCurrent)
{
	static BYTE parms[] = VTS_PVARIANT VTS_BSTR ;
	InvokeHelper(0xb5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pvData, bsCurrent);
}
void CPmacDevice::DifferentiateTheData(VARIANT * pvData, long I10, long I19, long * pMinVal, long * pMaxVal)
{
	static BYTE parms[] = VTS_PVARIANT VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 ;
	InvokeHelper(0xb6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pvData, I10, I19, pMinVal, pMaxVal);
}
void CPmacDevice::DownloadAutoTuningPLC(long dwDevice, short motor, BOOL bCurrentLoop, BOOL bBypassJog, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xb7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, bCurrentLoop, bBypassJog, pbSuccess);
}
void CPmacDevice::DownloadGantryAutoTuningPLCP1(long dwDevice, short motor, short motor2, BOOL bCurrentLoop, BOOL bBypassJog, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xb8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, motor2, bCurrentLoop, bBypassJog, pbSuccess);
}
void CPmacDevice::DownloadGantryAutoTuningPLC(long dwDevice, short motor, short motor2, BOOL bCurrentLoop, BOOL bBypassJog, double MaxTravel, long time, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_BOOL VTS_BOOL VTS_R8 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xb9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, motor2, bCurrentLoop, bBypassJog, MaxTravel, time, pbSuccess);
}
void CPmacDevice::MagEstimation(long dwDevice, LPCTSTR filePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0xba, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, filePath, pbSuccess);
}
void CPmacDevice::SlopeEstimation(long dwDevice, LPCTSTR filePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0xbb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, filePath, pbSuccess);
}
void CPmacDevice::SetCurrentGather(long dwDevice, long mask, BOOL bEnable, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xbc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, mask, bEnable, pbSuccess);
}
void CPmacDevice::DownloadOpenLoopTestForPMAC1(long dwDevice, short motor, short magnitude, short time, short reps, BOOL bGatherCurrents, BOOL bMacro, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xbd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, magnitude, time, reps, bGatherCurrents, bMacro, pbSuccess);
}
void CPmacDevice::GetMacroNodes(long dwDevice, long * pNumMacroStations, long * pNumActiveNodes)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
	InvokeHelper(0xbe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pNumMacroStations, pNumActiveNodes);
}
void CPmacDevice::GetMacroNodeInfo(long dwDevice, long modeNum, BOOL * pbEnabled, BOOL * pbIsIONode, long * pID)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBOOL VTS_PBOOL VTS_PI4 ;
	InvokeHelper(0xbf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, modeNum, pbEnabled, pbIsIONode, pID);
}
void CPmacDevice::SetMacroIVariableString(long dwDevice, long node, long num, LPCTSTR bsMIVarValue, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0xc0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, node, num, bsMIVarValue, pbSuccess);
}
void CPmacDevice::GetMacroIVariableString(long dwDevice, long node, long num, LPCTSTR bsDefault, BSTR * pbsVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_PBSTR ;
	InvokeHelper(0xc1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, node, num, bsDefault, pbsVal);
}
void CPmacDevice::GetCommandLogging(long dwDevice, BOOL * pbON)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xc2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbON);
}
void CPmacDevice::SetCommandLogging(long dwDevice, BOOL bOn, LPCTSTR bsFilePath, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0xc3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bOn, bsFilePath, pbSuccess);
}
void CPmacDevice::GetEnumeration(long dwDevice, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 ;
	InvokeHelper(0xc4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::GetControlValues(long dwDevice, short ctrlCh, VARIANT * pVariant, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_PVARIANT VTS_PBOOL ;
	InvokeHelper(0xc5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, ctrlCh, pVariant, pbSuccess);
}
void CPmacDevice::MultiDownload(long dwDevice, LPCTSTR outFile, LPCTSTR iniFile, LPCTSTR userID, BOOL bMacro, BOOL bMap, BOOL bLog, BOOL bDnld, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_PBOOL ;
	InvokeHelper(0xc6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, outFile, iniFile, userID, bMacro, bMap, bLog, bDnld, pbSuccess);
}
void CPmacDevice::AddDownloadFile(long dwDevice, LPCTSTR iniFile, LPCTSTR userID, LPCTSTR dlFile, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0xc7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, iniFile, userID, dlFile, pbSuccess);
}
void CPmacDevice::RemoveDownloadFile(long dwDevice, LPCTSTR iniFile, LPCTSTR userID, LPCTSTR dlFile, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, iniFile, userID, dlFile, pbSuccess);
}
void CPmacDevice::RenumberFiles(long dwDevice, long fileNumber, LPCTSTR iniFile)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
	InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, fileNumber, iniFile);
}
void CPmacDevice::GetVariableStr(long dwDevice, short ch, long num, BSTR * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_I4 VTS_PBSTR VTS_PBOOL ;
	InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, ch, num, pVal, pbSuccess);
}
void CPmacDevice::DPRVarBufReadAll(long dwDevice, long h, VARIANT * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PVARIANT VTS_PBOOL ;
	InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, h, pVal, pbSuccess);
}
void CPmacDevice::UltraLightAnalyze(long dwDevice, VARIANT * pVal, long * pActiveNodes)
{
	static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PI4 ;
	InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal, pActiveNodes);
}
void CPmacDevice::GetPlcStatusStructure(long dwDevice, VARIANT * pVal, long * pPrograms)
{
	static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PI4 ;
	InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal, pPrograms);
}
void CPmacDevice::GetBitValue(LPCTSTR hexStr, short bit, BOOL * pVal)
{
	static BYTE parms[] = VTS_BSTR VTS_I2 VTS_PBOOL ;
	InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, parms, hexStr, bit, pVal);
}
void CPmacDevice::GetNumDeviceKeys(long * pVal)
{
	static BYTE parms[] = VTS_PI4 ;
	InvokeHelper(0xcf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pVal);
}
void CPmacDevice::DPRGetLongDouble(long dwDevice, long address, double * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PR8 VTS_PBOOL ;
	InvokeHelper(0xd0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, address, pVal, pbSuccess);
}
void CPmacDevice::DPRGetFixedDouble(long dwDevice, long address, double * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PR8 VTS_PBOOL ;
	InvokeHelper(0xd1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, address, pVal, pbSuccess);
}
void CPmacDevice::DPRGetShort(long dwDevice, long address, short * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI2 VTS_PBOOL ;
	InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, address, pVal, pbSuccess);
}
void CPmacDevice::DPRSetShort(long dwDevice, long address, short newVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I2 VTS_PBOOL ;
	InvokeHelper(0xd3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, address, newVal, pbSuccess);
}
void CPmacDevice::DPRDWordBitSet(long dwDevice, long offset, long bit, BOOL * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL VTS_PBOOL ;
	InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, bit, pVal, pbSuccess);
}
void CPmacDevice::DPRResetDWordBit(long dwDevice, long offset, long bit, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xd5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, bit, pbSuccess);
}
void CPmacDevice::DPRSetDWordBit(long dwDevice, long offset, long bit, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xd6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, bit, pbSuccess);
}
void CPmacDevice::GetFirmwareType(long dwDevice, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 ;
	InvokeHelper(0xd7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pVal);
}
void CPmacDevice::GetResponseEx(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR * pAnswer, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BOOL VTS_PBSTR VTS_PI4 ;
	InvokeHelper(0xd8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, bAddLF, pAnswer, pstatus);
}
void CPmacDevice::DPRVarBufWriteEx(long dwDevice, VARIANT& vData, long * pWritten)
{
	static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_PI4 ;
	InvokeHelper(0xd9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, &vData, pWritten);
}
void CPmacDevice::DPRGetDWordMask(long dwDevice, long offset, long mask, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0xda, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, mask, pVal);
}
void CPmacDevice::DPRSetDWordMask(long dwDevice, long offset, long mask, long Val)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
	InvokeHelper(0xdb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, mask, Val);
}
void CPmacDevice::DPRRotBufRemove(long dwDevice, long bufnum)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0xdd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bufnum);
}
void CPmacDevice::DPRRotBufInit(long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xde, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}
void CPmacDevice::DPRRotBufClr(long dwDevice, long bufnum)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0xdf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bufnum);
}
void CPmacDevice::DPRSetRotBuf(long dwDevice, BOOL on)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0xe0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, on);
}
void CPmacDevice::DPRAsciiStrToRotEx(long dwDevice, LPCTSTR inpstr, long bufnum, BOOL bSendRemaining, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BOOL VTS_PI4 ;
	InvokeHelper(0xe1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, inpstr, bufnum, bSendRemaining, pstatus);
}
void CPmacDevice::DPRAsciiStrToRot(long dwDevice, LPCTSTR inpstr, long bufnum, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 ;
	InvokeHelper(0xe2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, inpstr, bufnum, pstatus);
}
void CPmacDevice::GetProgramMode(long dwDevice, long dwCoord, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0xe3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pVal);
}
void CPmacDevice::GetProgramMotionMode(long dwDevice, long dwCoord, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0xe4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pVal);
}
void CPmacDevice::MapDeviceNumToEnum(long location, long enumeration, long * pDeviceNumber)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0xe6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, location, enumeration, pDeviceNumber);
}
void CPmacDevice::MapLocAndEnumFromDeviceNum(long dwDevice, long * pLocation, long * pEnumeration)
{
	static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
	InvokeHelper(0xe7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pLocation, pEnumeration);
}
void CPmacDevice::GetFeedRateAndMode(long dwDevice, long dwCoord, double * pRate, BOOL * pMode)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PR8 VTS_PBOOL ;
	InvokeHelper(0xe8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pRate, pMode);
}
void CPmacDevice::GetMotorMotionMode(long dwDevice, long dwMotor, long * pVal)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
	InvokeHelper(0xe9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwMotor, pVal);
}
void CPmacDevice::CommandLog(long dwDevice, LPCTSTR bStr, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBOOL ;
	InvokeHelper(0xea, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, bStr, pbSuccess);
}
void CPmacDevice::DPRGetMem(long dwDevice, long offset, long bytes, VARIANT * pVal, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PVARIANT VTS_PBOOL ;
	InvokeHelper(0xeb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, bytes, pVal, pbSuccess);
}
void CPmacDevice::DPRSetMem(long dwDevice, long offset, long bytes, VARIANT& Val, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_VARIANT VTS_PBOOL ;
	InvokeHelper(0xec, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, offset, bytes, &Val, pbSuccess);
}
void CPmacDevice::GetResponseProgress(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR * pAnswer, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BOOL VTS_PBSTR VTS_PI4 ;
	InvokeHelper(0xed, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, bAddLF, pAnswer, pstatus);
}
void CPmacDevice::Abort(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xee, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
BOOL CPmacDevice::get_InterruptsEnabled(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xef, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_InterruptsEnabled(long dwDevice, BOOL newValue)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0xef, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
long CPmacDevice::get_InterruptMask(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xf0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_InterruptMask(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0xf0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
void CPmacDevice::PmacSave(long dwDevice, LPCTSTR question, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
	InvokeHelper(0xf1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, pstatus);
}
void CPmacDevice::PmacReset(long dwDevice, LPCTSTR question, BOOL bAsciiRingComm, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BOOL VTS_PI4 ;
	InvokeHelper(0xf2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, bAsciiRingComm, pstatus);
}
void CPmacDevice::PhaseMotor(long dwDevice, LPCTSTR question, long * pStatuss)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
	InvokeHelper(0xf4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, pStatuss);
}
void CPmacDevice::GetControlResponseEx(long dwDevice, short question, BSTR * pAnswer, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_PBSTR VTS_PI4 ;
	InvokeHelper(0xf5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, pAnswer, pstatus);
}
BOOL CPmacDevice::get_USMonitoringEnabled(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xf6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_USMonitoringEnabled(long dwDevice, BOOL newValue)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0xf6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
long CPmacDevice::get_USMonitoringPeriod(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xf7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_USMonitoringPeriod(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0xf7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
void CPmacDevice::DPRTest(long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0xf8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}
void CPmacDevice::AbortTest(long dwDevice)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xf9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice);
}
void CPmacDevice::DPRGetMotorRpt(long dwDevice, long motor, DEVFGMOTOR * pStruct, long * pServo, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0xfa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, pStruct, pServo, pbSuccess);
}
void CPmacDevice::DPRGetMotorRptTurbo(long dwDevice, long motor, DEVFGMOTORTURBO * pStruct, long * pServo, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0xfb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, motor, pStruct, pServo, pbSuccess);
}
void CPmacDevice::DPRGetCoordRpt(long dwDevice, long coord, DEVBGCOORD * pStruct, long * pServo, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0xfc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, coord, pStruct, pServo, pbSuccess);
}
void CPmacDevice::DPRGetCoordRptTurbo(long dwDevice, long coord, DEVBGCOORDTURBO * pStruct, long * pServo, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PI4 VTS_PBOOL ;
	InvokeHelper(0xfd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, coord, pStruct, pServo, pbSuccess);
}
BOOL CPmacDevice::get_DPRMotorRptEnabled(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xfe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_DPRMotorRptEnabled(long dwDevice, BOOL newValue)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0xfe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
long CPmacDevice::get_DPRMotorRptMask(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0xff, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_DPRMotorRptMask(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0xff, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
long CPmacDevice::get_DPRMotorRptMSec(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x100, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_DPRMotorRptMSec(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x100, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
BOOL CPmacDevice::get_DPRCoordRptEnabled(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x101, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_DPRCoordRptEnabled(long dwDevice, BOOL newValue)
{
	static BYTE parms[] = VTS_I4 VTS_BOOL ;
	InvokeHelper(0x101, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
long CPmacDevice::get_DPRCoordRptMSec(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x102, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_DPRCoordRptMSec(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x102, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
long CPmacDevice::get_DPRCoordRptMax(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x103, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::put_DPRCoordRptMax(long dwDevice, long newValue)
{
	static BYTE parms[] = VTS_I4 VTS_I4 ;
	InvokeHelper(0x103, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, dwDevice, newValue);
}
void CPmacDevice::UltraLightAnalyzeStruct(long dwDevice, DEVULTRALIGHT_INFO * pStruct, long * pActiveNodes)
{
	static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_PI4 ;
	InvokeHelper(0x104, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pStruct, pActiveNodes);
}
void CPmacDevice::GetPlcStatusStruct(long dwDevice, DEVTOTAL_PLC_STATUS_STRUCT * pStruct, long * pPrograms)
{
	static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_PI4 ;
	InvokeHelper(0x105, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pStruct, pPrograms);
}
BOOL CPmacDevice::get_DPRTesting(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x106, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::RawGetResponseEx(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR * pAnswer, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BOOL VTS_PBSTR VTS_PI4 ;
	InvokeHelper(0x107, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, bAddLF, pAnswer, pstatus);
}
void CPmacDevice::RawGetControlResponseEx(long dwDevice, short question, BSTR * pAnswer, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_I2 VTS_PBSTR VTS_PI4 ;
	InvokeHelper(0x108, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, question, pAnswer, pstatus);
}
void CPmacDevice::ModBusCommand(long dwDevice, unsigned char command, VARIANT * counters, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_UI1 VTS_PVARIANT VTS_PBOOL ;
	InvokeHelper(0x109, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, command, counters, pbSuccess);
}
void CPmacDevice::ModbusAvailable(long dwDevice, unsigned char command, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_UI1 VTS_PBOOL ;
	InvokeHelper(0x10a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, command, pbSuccess);
}
void CPmacDevice::DPRSetupBuffers(unsigned long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_UI4 VTS_PBOOL ;
	InvokeHelper(0x10b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}
void CPmacDevice::DPRBackground(long dwDevice, long on, long period, long coord, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x10c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, on, period, coord, pbSuccess);
}
BOOL CPmacDevice::get_DataCollectionEnabled(long dwDevice)
{
	BOOL result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x10d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, dwDevice);
	return result;
}
long CPmacDevice::get_DataCollectionResolution(long dwDevice)
{
	long result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x10e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, dwDevice);
	return result;
}
void CPmacDevice::GetTurboMotorStatusEx(long dwDevice, long lMotor, DEVMSTURBO * pstatus, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PBOOL ;
	InvokeHelper(0x10f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, lMotor, pstatus, pbSuccess);
}
void CPmacDevice::GetNTMotorStatusEx(long dwDevice, long lMotor, DEVMSNONTURBO * pstatus, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PBOOL ;
	InvokeHelper(0x110, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, lMotor, pstatus, pbSuccess);
}
void CPmacDevice::GetTurboGlobalStatusEx(long dwDevice, DEVGSTURBO * pstatus, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_PBOOL ;
	InvokeHelper(0x112, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pstatus, pbSuccess);
}
void CPmacDevice::GetNTGlobalStatusEx(long dwDevice, DEVGSNONTURBO * pstatus, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_PBOOL ;
	InvokeHelper(0x111, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pstatus, pbSuccess);
}
void CPmacDevice::GetTurboCoordinateStatusEx(long dwDevice, long dwCoord, DEVCSTURBO * pstatus, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PBOOL ;
	InvokeHelper(0x113, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pstatus, pbSuccess);
}
void CPmacDevice::GetNTCoordinateStatusEx(long dwDevice, long dwCoord, DEVCSNONTURBO * pstatus, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_I4 VTS_UNKNOWN VTS_PBOOL ;
	InvokeHelper(0x114, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, dwCoord, pstatus, pbSuccess);
}
void CPmacDevice::DataGather(long dwDevice, SAFEARRAY * * pvArray, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_PBOOL ;
	InvokeHelper(0x115, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pvArray, pbSuccess);
}
void CPmacDevice::Upload(long dwDevice, DEVUPLOAD pUpload, BSTR * pData, long * pstatus)
{
	static BYTE parms[] = VTS_I4 VTS_UNKNOWN VTS_PBSTR VTS_PI4 ;
	InvokeHelper(0x116, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pUpload, pData, pstatus);
}
void CPmacDevice::ModbusActive(long dwDevice, BOOL * pbSuccess)
{
	static BYTE parms[] = VTS_I4 VTS_PBOOL ;
	InvokeHelper(0x117, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwDevice, pbSuccess);
}