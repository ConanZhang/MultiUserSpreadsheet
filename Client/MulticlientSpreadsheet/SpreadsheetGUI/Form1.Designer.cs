﻿namespace SS
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
            this.cInfo = new System.Windows.Forms.TableLayoutPanel();
            this.cValue = new System.Windows.Forms.TextBox();
            this.cContent = new System.Windows.Forms.TextBox();
            this.cName = new System.Windows.Forms.TextBox();
            this.newSheetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.closeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFile = new System.Windows.Forms.OpenFileDialog();
            this.saveFile = new System.Windows.Forms.SaveFileDialog();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.registerUserToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.undoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.sPanel = new SS.SpreadsheetPanel();
            this.cellName = new System.Windows.Forms.ToolStripStatusLabel();
            this.cellContent = new System.Windows.Forms.ToolStripStatusLabel();
            this.cellValue = new System.Windows.Forms.ToolStripStatusLabel();
            this.progessBar = new System.Windows.Forms.StatusStrip();
            this.ConnectionStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.registerScreen = new SS.RegisterScreen();
            this.cInfo.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.progessBar.SuspendLayout();
            this.SuspendLayout();
            // 
            // cInfo
            // 
            this.cInfo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.cInfo.ColumnCount = 3;
            this.cInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30.30303F));
            this.cInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 39.39394F));
            this.cInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30.30303F));
            this.cInfo.Controls.Add(this.cValue, 2, 0);
            this.cInfo.Controls.Add(this.cContent, 1, 0);
            this.cInfo.Controls.Add(this.cName, 0, 0);
            this.cInfo.Cursor = System.Windows.Forms.Cursors.Default;
            this.cInfo.Location = new System.Drawing.Point(2, 27);
            this.cInfo.Name = "cInfo";
            this.cInfo.RowCount = 1;
            this.cInfo.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.cInfo.Size = new System.Drawing.Size(575, 27);
            this.cInfo.TabIndex = 2;
            // 
            // cValue
            // 
            this.cValue.BackColor = System.Drawing.SystemColors.Window;
            this.cValue.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cValue.Location = new System.Drawing.Point(403, 3);
            this.cValue.Name = "cValue";
            this.cValue.ReadOnly = true;
            this.cValue.Size = new System.Drawing.Size(169, 20);
            this.cValue.TabIndex = 2;
            // 
            // cContent
            // 
            this.cContent.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cContent.Location = new System.Drawing.Point(177, 3);
            this.cContent.Name = "cContent";
            this.cContent.Size = new System.Drawing.Size(220, 20);
            this.cContent.TabIndex = 1;
            this.cContent.TextChanged += new System.EventHandler(this.content_TextChanged);
            this.cContent.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            // 
            // cName
            // 
            this.cName.BackColor = System.Drawing.SystemColors.Window;
            this.cName.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cName.Location = new System.Drawing.Point(3, 3);
            this.cName.Name = "cName";
            this.cName.ReadOnly = true;
            this.cName.Size = new System.Drawing.Size(168, 20);
            this.cName.TabIndex = 0;
            // 
            // newSheetToolStripMenuItem
            // 
            this.newSheetToolStripMenuItem.Name = "newSheetToolStripMenuItem";
            this.newSheetToolStripMenuItem.Size = new System.Drawing.Size(32, 19);
            // 
            // closeToolStripMenuItem
            // 
            this.closeToolStripMenuItem.Name = "closeToolStripMenuItem";
            this.closeToolStripMenuItem.Size = new System.Drawing.Size(32, 19);
            // 
            // openFile
            // 
            this.openFile.InitialDirectory = " ";
            this.openFile.RestoreDirectory = true;
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.registerUserToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F)));
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.newToolStripMenuItem.Size = new System.Drawing.Size(142, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // registerUserToolStripMenuItem
            // 
            this.registerUserToolStripMenuItem.Name = "registerUserToolStripMenuItem";
            this.registerUserToolStripMenuItem.Size = new System.Drawing.Size(142, 22);
            this.registerUserToolStripMenuItem.Text = "Register User";
            this.registerUserToolStripMenuItem.Click += new System.EventHandler(this.registerUserToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(142, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.closeToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.undoToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.E)));
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // undoToolStripMenuItem
            // 
            this.undoToolStripMenuItem.Name = "undoToolStripMenuItem";
            this.undoToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
            this.undoToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.undoToolStripMenuItem.Text = "Undo";
            this.undoToolStripMenuItem.Click += new System.EventHandler(this.undoToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.H)));
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            this.helpToolStripMenuItem.Click += new System.EventHandler(this.helpToolStripMenuItem_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(577, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.UseWaitCursor = true;
            // 
            // sPanel
            // 
            this.sPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.sPanel.Cursor = System.Windows.Forms.Cursors.Default;
            this.sPanel.Location = new System.Drawing.Point(0, 56);
            this.sPanel.Name = "sPanel";
            this.sPanel.Size = new System.Drawing.Size(577, 353);
            this.sPanel.TabIndex = 3;
            // 
            // cellName
            // 
            this.cellName.Name = "cellName";
            this.cellName.Size = new System.Drawing.Size(39, 17);
            this.cellName.Text = "Name";
            // 
            // cellContent
            // 
            this.cellContent.Name = "cellContent";
            this.cellContent.Overflow = System.Windows.Forms.ToolStripItemOverflow.Always;
            this.cellContent.Size = new System.Drawing.Size(50, 17);
            this.cellContent.Text = "Content";
            // 
            // cellValue
            // 
            this.cellValue.Name = "cellValue";
            this.cellValue.Overflow = System.Windows.Forms.ToolStripItemOverflow.Always;
            this.cellValue.Size = new System.Drawing.Size(36, 17);
            this.cellValue.Text = "Value";
            // 
            // progessBar
            // 
            this.progessBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.cellName,
            this.cellContent,
            this.cellValue,
            this.ConnectionStatus});
            this.progessBar.Location = new System.Drawing.Point(0, 412);
            this.progessBar.Name = "progessBar";
            this.progessBar.Size = new System.Drawing.Size(577, 22);
            this.progessBar.TabIndex = 0;
            this.progessBar.Text = "statusStrip1";
            // 
            // ConnectionStatus
            // 
            this.ConnectionStatus.Name = "ConnectionStatus";
            this.ConnectionStatus.Size = new System.Drawing.Size(65, 17);
            this.ConnectionStatus.Text = "Connected";
            // 
            // registerScreen
            // 
            this.registerScreen.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.registerScreen.Location = new System.Drawing.Point(185, 56);
            this.registerScreen.Name = "registerScreen";
            this.registerScreen.Size = new System.Drawing.Size(214, 73);
            this.registerScreen.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(577, 434);
            this.Controls.Add(this.cInfo);
            this.Controls.Add(this.progessBar);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.sPanel);
            this.Controls.Add(this.registerScreen);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.cInfo.ResumeLayout(false);
            this.cInfo.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.progessBar.ResumeLayout(false);
            this.progessBar.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel cInfo;
        private System.Windows.Forms.TextBox cValue;
        private System.Windows.Forms.TextBox cContent;
        private System.Windows.Forms.TextBox cName;
        private SpreadsheetPanel sPanel;
        private System.Windows.Forms.ToolStripMenuItem newSheetToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem closeToolStripMenuItem;
        private System.Windows.Forms.OpenFileDialog openFile;
        private System.Windows.Forms.SaveFileDialog saveFile;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem registerUserToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private RegisterScreen registerScreen;
        private System.Windows.Forms.ToolStripMenuItem undoToolStripMenuItem;
        private System.Windows.Forms.ToolStripStatusLabel cellName;
        private System.Windows.Forms.ToolStripStatusLabel cellContent;
        private System.Windows.Forms.ToolStripStatusLabel cellValue;
        private System.Windows.Forms.StatusStrip progessBar;
        private System.Windows.Forms.ToolStripStatusLabel ConnectionStatus;
    }
}


