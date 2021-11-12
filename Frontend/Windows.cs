using System;
using System.Runtime.InteropServices;

namespace Stand
{
	class Windows
	{
		[DllImport("User32.dll", CharSet = CharSet.Ansi, BestFitMapping = false, ThrowOnUnmappableChar = true)]
		public static extern IntPtr LoadCursorFromFile(string str);

		[DllImport("user32.dll")]
		public static extern bool SetSystemCursor(IntPtr hcur, OCR_SYSTEM_CURSORS id);

		[DllImport("user32.dll", SetLastError = true)]
		public static extern bool DestroyIcon(IntPtr hIcon);
	}
}
