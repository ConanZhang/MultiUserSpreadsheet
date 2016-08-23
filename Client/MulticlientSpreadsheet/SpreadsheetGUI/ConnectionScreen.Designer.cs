namespace SS
{
    partial class ConnectionScreen
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ConnectPanel = new System.Windows.Forms.TableLayoutPanel();
            this.UserandSeverPanel = new System.Windows.Forms.TableLayoutPanel();
            this.SeverPort = new System.Windows.Forms.Label();
            this.ServerIp = new System.Windows.Forms.Label();
            this.SpreadsheetName = new System.Windows.Forms.Label();
            this.ServerPortText = new System.Windows.Forms.TextBox();
            this.ServerIpText = new System.Windows.Forms.TextBox();
            this.SpreadsheetNameText = new System.Windows.Forms.TextBox();
            this.UsernameText = new System.Windows.Forms.TextBox();
            this.Username = new System.Windows.Forms.Label();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.StatusMessage = new System.Windows.Forms.ToolStripStatusLabel();
            this.ConnectPanel.SuspendLayout();
            this.UserandSeverPanel.SuspendLayout();
            this.statusStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // ConnectPanel
            // 
            this.ConnectPanel.ColumnCount = 1;
            this.ConnectPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.ConnectPanel.Controls.Add(this.UserandSeverPanel, 0, 0);
            this.ConnectPanel.Controls.Add(this.ConnectButton, 0, 1);
            this.ConnectPanel.Controls.Add(this.statusStrip, 0, 2);
            this.ConnectPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ConnectPanel.Location = new System.Drawing.Point(0, 0);
            this.ConnectPanel.Name = "ConnectPanel";
            this.ConnectPanel.RowCount = 3;
            this.ConnectPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 73.00613F));
            this.ConnectPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 26.99387F));
            this.ConnectPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 23F));
            this.ConnectPanel.Size = new System.Drawing.Size(446, 324);
            this.ConnectPanel.TabIndex = 0;
            // 
            // UserandSeverPanel
            // 
            this.UserandSeverPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.UserandSeverPanel.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.OutsetPartial;
            this.UserandSeverPanel.ColumnCount = 2;
            this.UserandSeverPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 29.6173F));
            this.UserandSeverPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 70.3827F));
            this.UserandSeverPanel.Controls.Add(this.SeverPort, 0, 3);
            this.UserandSeverPanel.Controls.Add(this.ServerIp, 0, 2);
            this.UserandSeverPanel.Controls.Add(this.SpreadsheetName, 0, 1);
            this.UserandSeverPanel.Controls.Add(this.ServerPortText, 1, 3);
            this.UserandSeverPanel.Controls.Add(this.ServerIpText, 1, 2);
            this.UserandSeverPanel.Controls.Add(this.SpreadsheetNameText, 1, 1);
            this.UserandSeverPanel.Controls.Add(this.UsernameText, 1, 0);
            this.UserandSeverPanel.Controls.Add(this.Username, 0, 0);
            this.UserandSeverPanel.Location = new System.Drawing.Point(3, 3);
            this.UserandSeverPanel.Name = "UserandSeverPanel";
            this.UserandSeverPanel.RowCount = 4;
            this.UserandSeverPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.UserandSeverPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.UserandSeverPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.UserandSeverPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.UserandSeverPanel.Size = new System.Drawing.Size(440, 213);
            this.UserandSeverPanel.TabIndex = 0;
            // 
            // SeverPort
            // 
            this.SeverPort.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.SeverPort.AutoSize = true;
            this.SeverPort.Font = new System.Drawing.Font("Baskerville Old Face", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SeverPort.Location = new System.Drawing.Point(6, 172);
            this.SeverPort.Name = "SeverPort";
            this.SeverPort.Size = new System.Drawing.Size(121, 24);
            this.SeverPort.TabIndex = 11;
            this.SeverPort.Text = "Server Port";
            // 
            // ServerIp
            // 
            this.ServerIp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.ServerIp.AutoSize = true;
            this.ServerIp.Font = new System.Drawing.Font("Baskerville Old Face", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ServerIp.Location = new System.Drawing.Point(6, 119);
            this.ServerIp.Name = "ServerIp";
            this.ServerIp.Size = new System.Drawing.Size(121, 24);
            this.ServerIp.TabIndex = 10;
            this.ServerIp.Text = "Server IP";
            // 
            // SpreadsheetName
            // 
            this.SpreadsheetName.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.SpreadsheetName.AutoSize = true;
            this.SpreadsheetName.Font = new System.Drawing.Font("Baskerville Old Face", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SpreadsheetName.Location = new System.Drawing.Point(6, 55);
            this.SpreadsheetName.Name = "SpreadsheetName";
            this.SpreadsheetName.Size = new System.Drawing.Size(121, 48);
            this.SpreadsheetName.TabIndex = 9;
            this.SpreadsheetName.Text = "Spreadsheet Name";
            // 
            // ServerPortText
            // 
            this.ServerPortText.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.ServerPortText.Location = new System.Drawing.Point(136, 174);
            this.ServerPortText.Name = "ServerPortText";
            this.ServerPortText.Size = new System.Drawing.Size(298, 20);
            this.ServerPortText.TabIndex = 7;
            // 
            // ServerIpText
            // 
            this.ServerIpText.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.ServerIpText.Location = new System.Drawing.Point(136, 121);
            this.ServerIpText.Name = "ServerIpText";
            this.ServerIpText.Size = new System.Drawing.Size(298, 20);
            this.ServerIpText.TabIndex = 5;
            // 
            // SpreadsheetNameText
            // 
            this.SpreadsheetNameText.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.SpreadsheetNameText.Location = new System.Drawing.Point(136, 69);
            this.SpreadsheetNameText.Name = "SpreadsheetNameText";
            this.SpreadsheetNameText.Size = new System.Drawing.Size(298, 20);
            this.SpreadsheetNameText.TabIndex = 3;
            // 
            // UsernameText
            // 
            this.UsernameText.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.UsernameText.Location = new System.Drawing.Point(136, 17);
            this.UsernameText.Name = "UsernameText";
            this.UsernameText.Size = new System.Drawing.Size(298, 20);
            this.UsernameText.TabIndex = 1;
            // 
            // Username
            // 
            this.Username.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.Username.AutoSize = true;
            this.Username.Font = new System.Drawing.Font("Baskerville Old Face", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Username.Location = new System.Drawing.Point(6, 15);
            this.Username.Name = "Username";
            this.Username.Size = new System.Drawing.Size(121, 24);
            this.Username.TabIndex = 8;
            this.Username.Text = "Username";
            // 
            // ConnectButton
            // 
            this.ConnectButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ConnectButton.Font = new System.Drawing.Font("Baskerville Old Face", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ConnectButton.Location = new System.Drawing.Point(3, 222);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(440, 75);
            this.ConnectButton.TabIndex = 1;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            this.ConnectButton.Click += new System.EventHandler(this.ConnectButton_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusMessage});
            this.statusStrip.Location = new System.Drawing.Point(0, 302);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(446, 22);
            this.statusStrip.TabIndex = 2;
            this.statusStrip.Text = "statusStrip1";
            // 
            // StatusMessage
            // 
            this.StatusMessage.Name = "StatusMessage";
            this.StatusMessage.Size = new System.Drawing.Size(88, 17);
            this.StatusMessage.Text = "Not Connected";
            // 
            // ConnectionScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Controls.Add(this.ConnectPanel);
            this.Name = "ConnectionScreen";
            this.Size = new System.Drawing.Size(446, 324);
            this.ConnectPanel.ResumeLayout(false);
            this.ConnectPanel.PerformLayout();
            this.UserandSeverPanel.ResumeLayout(false);
            this.UserandSeverPanel.PerformLayout();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel ConnectPanel;
        private System.Windows.Forms.TableLayoutPanel UserandSeverPanel;
        private System.Windows.Forms.Label SeverPort;
        private System.Windows.Forms.Label ServerIp;
        private System.Windows.Forms.Label SpreadsheetName;
        private System.Windows.Forms.TextBox ServerPortText;
        private System.Windows.Forms.TextBox ServerIpText;
        private System.Windows.Forms.TextBox SpreadsheetNameText;
        private System.Windows.Forms.TextBox UsernameText;
        private System.Windows.Forms.Label Username;
        private System.Windows.Forms.Button ConnectButton;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel StatusMessage;

    }
}
