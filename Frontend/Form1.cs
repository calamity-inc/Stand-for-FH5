using Stand.Properties;
using System;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace Stand
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			processInit();
		}

		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			Backend.die();
		}

		private void processInit()
		{
			if (Backend.checkProcess())
			{
				processFound();
			}
			else
			{
				toolStripStatusLabel1.Text = "Please open Forza Horizon 5.";
				processWaitTimer.Start();
			}
		}

		private void Form1_Resize(object sender, EventArgs e)
		{
			var lpsize = flowLayoutPanel1.Size;
			lpsize.Width = Size.Width - 40;
			lpsize.Height = Size.Height - 76;
			flowLayoutPanel1.Size = lpsize;
		}

		private void processWaitTimer_Tick(object sender, EventArgs e)
		{
			if (Backend.checkProcess())
			{
				processWaitTimer.Stop();
				processStartTimer.Start();
			}
		}

		private void processStartTimer_Tick(object sender, EventArgs e)
		{
			processStartTimer.Stop();
			processFound();
		}

		private void processFound()
		{
			toolStripStatusLabel1.Text = "Scanning patterns...";
			Backend.patternscanInit();
			patternscanTimer.Start();
		}

		private void patternscanTimer_Tick(object sender, EventArgs e)
		{
			var status = Backend.patternscanStatus();
			if (status != 0)
			{
				patternscanTimer.Stop();
				if (status == 1)
				{
					toolStripStatusLabel1.Text = "Ready.";
				}
				else
				{
					toolStripStatusLabel1.Text = "Failed to find all patterns. (Code: " + status + ")";
				}
				mainloopTimer.Start();
			}
		}

		private void mainloopTimer_Tick(object sender, EventArgs e)
		{
			var data = new StringBuilder(20);
			Backend.mainloop(data, data.Capacity);
			var msg = data.ToString();
			if (msg.Length != 0)
			{
				switch (msg)
				{
					case "reset":
						mainloopTimer.Stop();
						processInit();
						break;

					case "focus":
						State.game_focused = true;
						break;

					case "unfocus":
						State.game_focused = false;
						break;
				}
			}

			if (cursorToggle.Checked && State.game_focused)
			{
				if (State.cursor_og == IntPtr.Zero)
				{
					State.cursor_og = Cursor.CopyHandle();
					if (State.cursor_replacement == null)
					{
						var file = Path.GetTempPath() + Guid.NewGuid() + ".cur";
						using (var fileStream = File.Open(file, FileMode.Create))
						{
							using (var ms = new MemoryStream(Resources.Blank))
							{
								ms.WriteTo(fileStream);
							}
							fileStream.Flush();
							fileStream.Close();
						}
						State.cursor_replacement = new Cursor(Windows.LoadCursorFromFile(file));
					}
					Windows.SetSystemCursor(State.cursor_replacement.CopyHandle(), OCR_SYSTEM_CURSORS.OCR_NORMAL);
				}
			}
			else
			{
				if (State.cursor_og != IntPtr.Zero)
				{
					Windows.SetSystemCursor(State.cursor_og, OCR_SYSTEM_CURSORS.OCR_NORMAL);
					Windows.DestroyIcon(State.cursor_og);
					State.cursor_og = IntPtr.Zero;
				}
			}
		}

		private void getSpinRegularBtn_Click(object sender, EventArgs e)
		{
			Backend.getSpinRegular((int)getSpinRegularVal.Value);
		}

		private void getSpinSuperBtn_Click(object sender, EventArgs e)
		{
			Backend.getSpinSuper((int)getSpinSuperVal.Value);
		}

		private void lockcrToggle_CheckedChanged(object sender, EventArgs e)
		{
			if (lockcrToggle.Checked)
			{
				Backend.lockcrSet((int)lockcrVal.Value);
			}
			else
			{
				Backend.lockcrUnset();
			}
		}

		private void lockcrVal_ValueChanged(object sender, EventArgs e)
		{
			if (lockcrToggle.Checked)
			{
				Backend.lockcrSet((int)lockcrVal.Value);
			}
		}

		private void autoshowAvailableBox_SelectedIndexChanged(object sender, EventArgs e)
		{
			Backend.autoshowAvailableSet(autoshowAvailableBox.SelectedIndex);
		}

		private void autoshowAllfree_Click(object sender, EventArgs e)
		{
			Backend.autoshowAllfree();
		}
	}
}
