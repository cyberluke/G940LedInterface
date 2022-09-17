Logitech G940 Throttle LED interface for C++ and C#
Copyright (C) 2020 CyberLuke No Rights Reserved


Introduction
--------------------------------------------------------------------------

This package enables developers to control the LEDs on the throttle of
the G940 joystick. The button colors can be set to off, green, amber
or red.

The environment for use of the package
--------------------------------------------------------------------------

1. Microsoft DirectX 9 SDK or higher
   (http://msdn.microsoft.com/downloads)

2. DirectX Runtime 9.0c or higher (October 2006 update or higher).

3. Visual Studio 2015 to build and run the demo program (should work in VS2005 as well)

4. Drivers installed for G940 joystick (Logitech Gaming Software 5.06
   or newer).


Example use in C# (.NET, tested in .NET 4.0 and VS2015, x86 32-bit)
--------------------------------------------------------------------------
1) Right click your project -> References -> add G940LedInterface.dll 

2) Example of declaration in C# to enable functionality

        public enum LogiPanelButton
        {
            LOGI_UNDEFINED = -1, LOGI_P1, LOGI_P2, LOGI_P3, LOGI_P4, LOGI_P5, LOGI_P6, LOGI_P7, LOGI_P8
        }


        public enum LogiColor
        {
            LOGI_OFF, LOGI_GREEN, LOGI_AMBER, LOGI_RED
        }


        [DllImport("G940LedInterface.dll", CallingConvention = CallingConvention.StdCall, EntryPoint = "_ButtonSetColor")]
        public extern static ulong ButtonSetColor(IntPtr device, LogiPanelButton button, LogiColor color);

        [DllImport("G940LedInterface.dll", CallingConvention = CallingConvention.StdCall, EntryPoint = "_SetAllButtonsColor")]
        public extern static ulong SetAllButtonsColor(IntPtr device, LogiColor color);

        [DllImport("G940LedInterface.dll", CallingConvention = CallingConvention.StdCall, EntryPoint = "_IsButtonColor")]
        public extern static bool IsButtonColor(IntPtr device, LogiPanelButton button, LogiColor color);

3) Example of actual call with SlimDX (FreePIE)
		// joystick.InternalPointer is from SlimDX
		ButtonSetColor((IntPtr)joystick.InternalPointer, LogiPanelButton.LOGI_P1, LogiColor.LOGI_AMBER);