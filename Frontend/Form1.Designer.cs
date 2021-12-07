
namespace Stand
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
			this.statusStrip1 = new System.Windows.Forms.StatusStrip();
			this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
			this.lockcrToggle = new System.Windows.Forms.CheckBox();
			this.lockcrVal = new System.Windows.Forms.NumericUpDown();
			this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.getSpinSuperVal = new System.Windows.Forms.NumericUpDown();
			this.getSpinRegularVal = new System.Windows.Forms.NumericUpDown();
			this.getSpinRegularBtn = new System.Windows.Forms.Button();
			this.getSpinSuperBtn = new System.Windows.Forms.Button();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.autoshowAllfree = new System.Windows.Forms.Button();
			this.autoshowAvailableLabel = new System.Windows.Forms.Label();
			this.autoshowAvailableBox = new System.Windows.Forms.ComboBox();
			this.groupBox3 = new System.Windows.Forms.GroupBox();
			this.cursorToggle = new System.Windows.Forms.CheckBox();
			this.processWaitTimer = new System.Windows.Forms.Timer(this.components);
			this.patternscanTimer = new System.Windows.Forms.Timer(this.components);
			this.mainloopTimer = new System.Windows.Forms.Timer(this.components);
			this.processStartTimer = new System.Windows.Forms.Timer(this.components);
			this.statusStrip1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.lockcrVal)).BeginInit();
			this.flowLayoutPanel1.SuspendLayout();
			this.groupBox1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.getSpinSuperVal)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.getSpinRegularVal)).BeginInit();
			this.groupBox2.SuspendLayout();
			this.groupBox3.SuspendLayout();
			this.SuspendLayout();
			// 
			// statusStrip1
			// 
			this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
			this.statusStrip1.Location = new System.Drawing.Point(0, 155);
			this.statusStrip1.Name = "statusStrip1";
			this.statusStrip1.Size = new System.Drawing.Size(686, 22);
			this.statusStrip1.SizingGrip = false;
			this.statusStrip1.TabIndex = 1;
			this.statusStrip1.Text = "statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
			this.toolStripStatusLabel1.Size = new System.Drawing.Size(74, 17);
			this.toolStripStatusLabel1.Text = "Please wait...";
			// 
			// lockcrToggle
			// 
			this.lockcrToggle.AutoSize = true;
			this.lockcrToggle.Location = new System.Drawing.Point(6, 24);
			this.lockcrToggle.Name = "lockcrToggle";
			this.lockcrToggle.Size = new System.Drawing.Size(85, 17);
			this.lockcrToggle.TabIndex = 3;
			this.lockcrToggle.Text = "Lock Credits";
			this.lockcrToggle.UseVisualStyleBackColor = true;
			this.lockcrToggle.CheckedChanged += new System.EventHandler(this.lockcrToggle_CheckedChanged);
			// 
			// lockcrVal
			// 
			this.lockcrVal.Location = new System.Drawing.Point(97, 21);
			this.lockcrVal.Maximum = new decimal(new int[] {
            999999999,
            0,
            0,
            0});
			this.lockcrVal.Name = "lockcrVal";
			this.lockcrVal.Size = new System.Drawing.Size(164, 20);
			this.lockcrVal.TabIndex = 4;
			this.lockcrVal.Value = new decimal(new int[] {
            10000000,
            0,
            0,
            0});
			this.lockcrVal.ValueChanged += new System.EventHandler(this.lockcrVal_ValueChanged);
			// 
			// flowLayoutPanel1
			// 
			this.flowLayoutPanel1.Controls.Add(this.groupBox1);
			this.flowLayoutPanel1.Controls.Add(this.groupBox2);
			this.flowLayoutPanel1.Controls.Add(this.groupBox3);
			this.flowLayoutPanel1.Location = new System.Drawing.Point(12, 12);
			this.flowLayoutPanel1.Name = "flowLayoutPanel1";
			this.flowLayoutPanel1.Size = new System.Drawing.Size(662, 136);
			this.flowLayoutPanel1.TabIndex = 4;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.getSpinSuperVal);
			this.groupBox1.Controls.Add(this.getSpinRegularVal);
			this.groupBox1.Controls.Add(this.getSpinRegularBtn);
			this.groupBox1.Controls.Add(this.getSpinSuperBtn);
			this.groupBox1.Controls.Add(this.lockcrVal);
			this.groupBox1.Controls.Add(this.lockcrToggle);
			this.groupBox1.Location = new System.Drawing.Point(3, 3);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(269, 121);
			this.groupBox1.TabIndex = 2;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Self";
			// 
			// getSpinSuperVal
			// 
			this.getSpinSuperVal.Location = new System.Drawing.Point(6, 89);
			this.getSpinSuperVal.Maximum = new decimal(new int[] {
            999999999,
            0,
            0,
            0});
			this.getSpinSuperVal.Minimum = new decimal(new int[] {
            999999999,
            0,
            0,
            -2147483648});
			this.getSpinSuperVal.Name = "getSpinSuperVal";
			this.getSpinSuperVal.Size = new System.Drawing.Size(120, 20);
			this.getSpinSuperVal.TabIndex = 7;
			this.getSpinSuperVal.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
			// 
			// getSpinRegularVal
			// 
			this.getSpinRegularVal.Location = new System.Drawing.Point(6, 61);
			this.getSpinRegularVal.Maximum = new decimal(new int[] {
            999999999,
            0,
            0,
            0});
			this.getSpinRegularVal.Minimum = new decimal(new int[] {
            999999999,
            0,
            0,
            -2147483648});
			this.getSpinRegularVal.Name = "getSpinRegularVal";
			this.getSpinRegularVal.Size = new System.Drawing.Size(120, 20);
			this.getSpinRegularVal.TabIndex = 5;
			this.getSpinRegularVal.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
			// 
			// getSpinRegularBtn
			// 
			this.getSpinRegularBtn.Location = new System.Drawing.Point(131, 58);
			this.getSpinRegularBtn.Name = "getSpinRegularBtn";
			this.getSpinRegularBtn.Size = new System.Drawing.Size(130, 23);
			this.getSpinRegularBtn.TabIndex = 6;
			this.getSpinRegularBtn.Text = "Add Wheelspins";
			this.getSpinRegularBtn.UseVisualStyleBackColor = true;
			this.getSpinRegularBtn.Click += new System.EventHandler(this.getSpinRegularBtn_Click);
			// 
			// getSpinSuperBtn
			// 
			this.getSpinSuperBtn.Location = new System.Drawing.Point(131, 86);
			this.getSpinSuperBtn.Name = "getSpinSuperBtn";
			this.getSpinSuperBtn.Size = new System.Drawing.Size(130, 23);
			this.getSpinSuperBtn.TabIndex = 8;
			this.getSpinSuperBtn.Text = "Add Super Wheelspins";
			this.getSpinSuperBtn.UseVisualStyleBackColor = true;
			this.getSpinSuperBtn.Click += new System.EventHandler(this.getSpinSuperBtn_Click);
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.autoshowAllfree);
			this.groupBox2.Controls.Add(this.autoshowAvailableLabel);
			this.groupBox2.Controls.Add(this.autoshowAvailableBox);
			this.groupBox2.Location = new System.Drawing.Point(278, 3);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(200, 81);
			this.groupBox2.TabIndex = 9;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Autoshow";
			// 
			// autoshowAllfree
			// 
			this.autoshowAllfree.Location = new System.Drawing.Point(10, 42);
			this.autoshowAllfree.Name = "autoshowAllfree";
			this.autoshowAllfree.Size = new System.Drawing.Size(178, 23);
			this.autoshowAllfree.TabIndex = 7;
			this.autoshowAllfree.Text = "Make All Cars Free";
			this.autoshowAllfree.UseVisualStyleBackColor = true;
			this.autoshowAllfree.Click += new System.EventHandler(this.autoshowAllfree_Click);
			// 
			// autoshowAvailableLabel
			// 
			this.autoshowAvailableLabel.AutoSize = true;
			this.autoshowAvailableLabel.Location = new System.Drawing.Point(7, 19);
			this.autoshowAvailableLabel.Name = "autoshowAvailableLabel";
			this.autoshowAvailableLabel.Size = new System.Drawing.Size(54, 13);
			this.autoshowAvailableLabel.TabIndex = 1;
			this.autoshowAvailableLabel.Text = "Rare Cars";
			// 
			// autoshowAvailableBox
			// 
			this.autoshowAvailableBox.FormattingEnabled = true;
			this.autoshowAvailableBox.Items.AddRange(new object[] {
            "Hidden (Default)",
            "Shown",
            "Shown Exclusively"});
			this.autoshowAvailableBox.Location = new System.Drawing.Point(67, 15);
			this.autoshowAvailableBox.Name = "autoshowAvailableBox";
			this.autoshowAvailableBox.Size = new System.Drawing.Size(121, 21);
			this.autoshowAvailableBox.TabIndex = 0;
			this.autoshowAvailableBox.Text = "Hidden (Default)";
			this.autoshowAvailableBox.SelectedIndexChanged += new System.EventHandler(this.autoshowAvailableBox_SelectedIndexChanged);
			// 
			// groupBox3
			// 
			this.groupBox3.Controls.Add(this.cursorToggle);
			this.groupBox3.Location = new System.Drawing.Point(484, 3);
			this.groupBox3.Name = "groupBox3";
			this.groupBox3.Size = new System.Drawing.Size(172, 49);
			this.groupBox3.TabIndex = 10;
			this.groupBox3.TabStop = false;
			this.groupBox3.Text = "Game";
			// 
			// cursorToggle
			// 
			this.cursorToggle.AutoSize = true;
			this.cursorToggle.Location = new System.Drawing.Point(6, 19);
			this.cursorToggle.Name = "cursorToggle";
			this.cursorToggle.Size = new System.Drawing.Size(157, 17);
			this.cursorToggle.TabIndex = 0;
			this.cursorToggle.Text = "Hide Cursor When Focused";
			this.cursorToggle.UseVisualStyleBackColor = true;
			// 
			// processWaitTimer
			// 
			this.processWaitTimer.Tick += new System.EventHandler(this.processWaitTimer_Tick);
			// 
			// patternscanTimer
			// 
			this.patternscanTimer.Interval = 10;
			this.patternscanTimer.Tick += new System.EventHandler(this.patternscanTimer_Tick);
			// 
			// mainloopTimer
			// 
			this.mainloopTimer.Interval = 200;
			this.mainloopTimer.Tick += new System.EventHandler(this.mainloopTimer_Tick);
			// 
			// processStartTimer
			// 
			this.processStartTimer.Interval = 30000;
			this.processStartTimer.Tick += new System.EventHandler(this.processStartTimer_Tick);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(686, 177);
			this.Controls.Add(this.flowLayoutPanel1);
			this.Controls.Add(this.statusStrip1);
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Name = "Form1";
			this.Text = "Stand for FH5";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
			this.Load += new System.EventHandler(this.Form1_Load);
			this.Resize += new System.EventHandler(this.Form1_Resize);
			this.statusStrip1.ResumeLayout(false);
			this.statusStrip1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.lockcrVal)).EndInit();
			this.flowLayoutPanel1.ResumeLayout(false);
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.getSpinSuperVal)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.getSpinRegularVal)).EndInit();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			this.groupBox3.ResumeLayout(false);
			this.groupBox3.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion
		private System.Windows.Forms.StatusStrip statusStrip1;
		private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
		private System.Windows.Forms.CheckBox lockcrToggle;
		private System.Windows.Forms.NumericUpDown lockcrVal;
		private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Timer processWaitTimer;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.Timer patternscanTimer;
		private System.Windows.Forms.Button getSpinSuperBtn;
		private System.Windows.Forms.Timer mainloopTimer;
		private System.Windows.Forms.Button getSpinRegularBtn;
		private System.Windows.Forms.NumericUpDown getSpinRegularVal;
		private System.Windows.Forms.NumericUpDown getSpinSuperVal;
		private System.Windows.Forms.GroupBox groupBox3;
		private System.Windows.Forms.CheckBox cursorToggle;
		private System.Windows.Forms.Label autoshowAvailableLabel;
		private System.Windows.Forms.ComboBox autoshowAvailableBox;
		private System.Windows.Forms.Timer processStartTimer;
		private System.Windows.Forms.Button autoshowAllfree;
	}
}

