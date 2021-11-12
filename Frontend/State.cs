using System;
using System.Windows.Forms;

namespace Stand
{
	class State
	{
		public static bool game_focused = false;
		public static IntPtr cursor_og = IntPtr.Zero;
		public static Cursor cursor_replacement = null;
	}
}
