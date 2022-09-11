namespace SunnyCtrl2
{
    partial class DemoCtrl
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.StartBtn2 = new System.Windows.Forms.Button();
            this.StartBtn1 = new System.Windows.Forms.Button();
            this.StartBtn = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.panel1.Controls.Add(this.StartBtn2);
            this.panel1.Controls.Add(this.StartBtn1);
            this.panel1.Controls.Add(this.StartBtn);
            this.panel1.Location = new System.Drawing.Point(46, 125);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(690, 308);
            this.panel1.TabIndex = 0;
            // 
            // StartBtn2
            // 
            this.StartBtn2.Location = new System.Drawing.Point(440, 56);
            this.StartBtn2.Name = "StartBtn2";
            this.StartBtn2.Size = new System.Drawing.Size(130, 72);
            this.StartBtn2.TabIndex = 2;
            this.StartBtn2.Text = "PressMe 2";
            this.StartBtn2.UseVisualStyleBackColor = true;
            this.StartBtn2.Click += new System.EventHandler(this.StartBtn2_Click);
            // 
            // StartBtn1
            // 
            this.StartBtn1.Location = new System.Drawing.Point(239, 56);
            this.StartBtn1.Name = "StartBtn1";
            this.StartBtn1.Size = new System.Drawing.Size(130, 72);
            this.StartBtn1.TabIndex = 1;
            this.StartBtn1.Text = "PressMe 1";
            this.StartBtn1.UseVisualStyleBackColor = true;
            this.StartBtn1.Click += new System.EventHandler(this.StartBtn1_Click);
            // 
            // StartBtn
            // 
            this.StartBtn.Location = new System.Drawing.Point(40, 56);
            this.StartBtn.Name = "StartBtn";
            this.StartBtn.Size = new System.Drawing.Size(130, 72);
            this.StartBtn.TabIndex = 0;
            this.StartBtn.Text = "PressMe!";
            this.StartBtn.UseVisualStyleBackColor = true;
            this.StartBtn.Click += new System.EventHandler(this.StartBtn_Click);
            // 
            // DemoCtrl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.Controls.Add(this.panel1);
            this.Name = "DemoCtrl";
            this.Size = new System.Drawing.Size(791, 478);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button StartBtn;
        private System.Windows.Forms.Button StartBtn2;
        private System.Windows.Forms.Button StartBtn1;
    }
}
