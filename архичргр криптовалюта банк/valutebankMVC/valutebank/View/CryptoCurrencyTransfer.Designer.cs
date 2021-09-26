
namespace valutebank.View
{
    partial class CryptoCurrencyTransfer
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
            this.ListFrom = new System.Windows.Forms.ListBox();
            this.ListUsers = new System.Windows.Forms.ListBox();
            this.ListTo = new System.Windows.Forms.ListBox();
            this.TextAmount = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.Button = new System.Windows.Forms.Button();
            this.LabelSelected = new System.Windows.Forms.Label();
            this.labal3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // ListFrom
            // 
            this.ListFrom.FormattingEnabled = true;
            this.ListFrom.Location = new System.Drawing.Point(202, 58);
            this.ListFrom.Name = "ListFrom";
            this.ListFrom.Size = new System.Drawing.Size(128, 147);
            this.ListFrom.TabIndex = 0;
            // 
            // ListUsers
            // 
            this.ListUsers.FormattingEnabled = true;
            this.ListUsers.Location = new System.Drawing.Point(47, 58);
            this.ListUsers.Name = "ListUsers";
            this.ListUsers.Size = new System.Drawing.Size(130, 316);
            this.ListUsers.TabIndex = 1;
            this.ListUsers.SelectedIndexChanged += new System.EventHandler(this.listBoxListToTrans_SelectedIndexChanged);
            // 
            // ListTo
            // 
            this.ListTo.FormattingEnabled = true;
            this.ListTo.Location = new System.Drawing.Point(202, 227);
            this.ListTo.Name = "ListTo";
            this.ListTo.Size = new System.Drawing.Size(128, 147);
            this.ListTo.TabIndex = 2;
            // 
            // TextAmount
            // 
            this.TextAmount.Location = new System.Drawing.Point(358, 207);
            this.TextAmount.Name = "TextAmount";
            this.TextAmount.Size = new System.Drawing.Size(100, 20);
            this.TextAmount.TabIndex = 3;
            this.TextAmount.TextChanged += new System.EventHandler(this.TextAmount_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(358, 188);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(106, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Сколько перевести";
            // 
            // Button
            // 
            this.Button.Location = new System.Drawing.Point(370, 232);
            this.Button.Name = "Button";
            this.Button.Size = new System.Drawing.Size(75, 23);
            this.Button.TabIndex = 5;
            this.Button.Text = "Перевести";
            this.Button.UseVisualStyleBackColor = true;
            this.Button.Click += new System.EventHandler(this.button1_Click);
            // 
            // LabelSelected
            // 
            this.LabelSelected.AutoSize = true;
            this.LabelSelected.Location = new System.Drawing.Point(45, 21);
            this.LabelSelected.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.LabelSelected.Name = "LabelSelected";
            this.LabelSelected.Size = new System.Drawing.Size(62, 13);
            this.LabelSelected.TabIndex = 6;
            this.LabelSelected.Text = "placeholder";
            // 
            // labal3
            // 
            this.labal3.AutoSize = true;
            this.labal3.Location = new System.Drawing.Point(200, 41);
            this.labal3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labal3.Name = "labal3";
            this.labal3.Size = new System.Drawing.Size(43, 13);
            this.labal3.TabIndex = 7;
            this.labal3.Text = "Откуда";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(200, 210);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(31, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Куда";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(47, 41);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(33, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Кому";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(358, 281);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 11;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(355, 265);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(149, 13);
            this.label2.TabIndex = 12;
            this.label2.Text = "Получит после конвертации";
            // 
            // CryptoCurrencyTransfer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(506, 423);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.labal3);
            this.Controls.Add(this.LabelSelected);
            this.Controls.Add(this.Button);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.TextAmount);
            this.Controls.Add(this.ListTo);
            this.Controls.Add(this.ListUsers);
            this.Controls.Add(this.ListFrom);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "CryptoCurrencyTransfer";
            this.Text = "Перевод криптовалют";
            this.Load += new System.EventHandler(this.CryptoCurrencyTransfer_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox ListFrom;
        private System.Windows.Forms.ListBox ListUsers;
        private System.Windows.Forms.ListBox ListTo;
        private System.Windows.Forms.TextBox TextAmount;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Button;
        private System.Windows.Forms.Label LabelSelected;
        private System.Windows.Forms.Label labal3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label label2;
    }
}