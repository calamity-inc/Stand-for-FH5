using System.Runtime.InteropServices;
using System.Text;

namespace Stand
{
	class Backend
	{
		// main

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		[return: MarshalAs(UnmanagedType.I1)]
		public static extern bool checkProcess();

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void mainloop(StringBuilder a1, long a2);

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void die();

		// patternscan

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void patternscanInit();

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int patternscanStatus();

		// getSpin

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void getSpinRegular(int amount);

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void getSpinSuper(int amount);

		// ...

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void autoshowAllfree();

		[DllImport(@"Backend.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void autoshowAvailableSet(int mode);
	}
}
