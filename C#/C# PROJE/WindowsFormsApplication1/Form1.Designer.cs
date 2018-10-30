namespace WindowsFormsApplication1
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
            this.roketTimer = new System.Windows.Forms.Timer(this.components);
            this.ucakTimer = new System.Windows.Forms.Timer(this.components);
            this.kontrolTİmer = new System.Windows.Forms.Timer(this.components);
            this.eklemeTimer = new System.Windows.Forms.Timer(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // roketTimer
            // 
            this.roketTimer.Interval = 1;
            this.roketTimer.Tick += new System.EventHandler(this.roketTimer_Tick);
            // 
            // ucakTimer
            // 
            this.ucakTimer.Interval = 1;
            this.ucakTimer.Tick += new System.EventHandler(this.ucakTimer_Tick);
            // 
            // kontrolTİmer
            // 
            this.kontrolTİmer.Interval = 1;
            this.kontrolTİmer.Tick += new System.EventHandler(this.kontrolTİmer_Tick);
            // 
            // eklemeTimer
            // 
            this.eklemeTimer.Interval = 500;
            this.eklemeTimer.Tick += new System.EventHandler(this.eklemeTimer_Tick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(972, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Score :";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.label2.Location = new System.Drawing.Point(1031, 40);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 17);
            this.label2.TabIndex = 1;
            this.label2.Text = "   0000";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Cursor = System.Windows.Forms.Cursors.No;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label3.Location = new System.Drawing.Point(432, 206);
            this.label3.MaximumSize = new System.Drawing.Size(500, 100);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(200, 38);
            this.label3.TabIndex = 2;
            this.label3.Text = "OYUN BİTTİ";
            this.label3.Visible = false;
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.BlanchedAlmond;
            this.label4.Location = new System.Drawing.Point(278, 20);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(524, 69);
            this.label4.TabIndex = 3;
            this.label4.Text = "OYUNU BASLATMAK ICIN ENTER TUSUNA BASINIZ.\r\nUCAKSAVARI A/D TUSLARI ILE HAREKET ET" +
    "TIRINIZ.\r\nATES ETMEK ICIN SPACE TUSUNA BASINIZ.";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSlateGray;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(1182, 553);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.ForeColor = System.Drawing.Color.Crimson;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = " ";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer roketTimer;
        private System.Windows.Forms.Timer ucakTimer;
        private System.Windows.Forms.Timer kontrolTİmer;
        private System.Windows.Forms.Timer eklemeTimer;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}

