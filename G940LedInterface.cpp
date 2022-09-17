#include "stdafx.h"
#include "G940LedInterface.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern "C" {
	LGINTERFACE_API DWORD __cdecl _ButtonSetColor(UINT * device, LogiPanelButton button, LogiColor color)
	{
		return SetButtonColor((LPDIRECTINPUTDEVICE8)device, button, color);
	}
	LGINTERFACE_API DWORD __cdecl _SetAllButtonsColor(UINT * device, LogiColor color)
	{
		return SetAllButtonsColor((LPDIRECTINPUTDEVICE8)device, color);
	}
	LGINTERFACE_API BOOL __cdecl _IsButtonColor(UINT * device, LogiPanelButton button, LogiColor color)
	{
		return IsButtonColor((LPDIRECTINPUTDEVICE8)device, button, color);
	}
	LGINTERFACE_API DWORD __cdecl _SetLEDs(UINT * device, BYTE redLEDs, BYTE greenLEDs)
	{
		return SetLEDs((LPDIRECTINPUTDEVICE8)device, redLEDs, greenLEDs);
	}
	LGINTERFACE_API DWORD __cdecl _GetLEDs(UINT * device, BYTE& redLEDs, BYTE& greenLEDs)
	{
		return GetLEDs((LPDIRECTINPUTDEVICE8)device, redLEDs, greenLEDs);
	}

}
