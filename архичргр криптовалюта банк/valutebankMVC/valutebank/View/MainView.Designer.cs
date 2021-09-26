
namespace valutebank.View
{
    partial class MainView
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
            this.listBoxOfUsers = new System.Windows.Forms.ListBox();
            this.listBoxAccount = new System.Windows.Forms.ListBox();
            this.button2 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.listBoxHistory = new System.Windows.Forms.ListBox();
            this.button6 = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.действияToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.добавитьПользователяToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.удалитьПользователяToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.сохранитьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.создатьВалютуToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.button1 = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // listBoxOfUsers
            // 
            this.listBoxOfUsers.FormattingEnabled = true;
            this.listBoxOfUsers.Location = new System.Drawing.Point(25, 38);
            this.listBoxOfUsers.Name = "listBoxOfUsers";
            this.listBoxOfUsers.Size = new System.Drawing.Size(217, 524);
            this.listBoxOfUsers.TabIndex = 0;
            this.listBoxOfUsers.SelectedIndexChanged += new System.EventHandler(this.listBoxOfUsers_SelectedIndexChanged);
            // 
            // listBoxAccount
            // 
            this.listBoxAccount.FormattingEnabled = true;
            this.listBoxAccount.Location = new System.Drawing.Point(285, 38);
            this.listBoxAccount.Name = "listBoxAccount";
            this.listBoxAccount.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.listBoxAccount.ScrollAlwaysVisible = true;
            this.listBoxAccount.Size = new System.Drawing.Size(583, 134);
            this.listBoxAccount.TabIndex = 1;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(285, 247);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(114, 46);
            this.button2.TabIndex = 3;
            this.button2.Text = "Перевод валюты пользователю";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(525, 247);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(114, 46);
            this.button4.TabIndex = 5;
            this.button4.Text = "Пополнить валюту";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // listBoxHistory
            // 
            this.listBoxHistory.FormattingEnabled = true;
            this.listBoxHistory.Location = new System.Drawing.Point(285, 363);
            this.listBoxHistory.Name = "listBoxHistory";
            this.listBoxHistory.ScrollAlwaysVisible = true;
            this.listBoxHistory.Size = new System.Drawing.Size(583, 199);
            this.listBoxHistory.TabIndex = 6;
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(405, 247);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(114, 46);
            this.button6.TabIndex = 8;
            this.button6.Text = "Создать счёт";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.действияToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(880, 24);
            this.menuStrip1.TabIndex = 12;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // действияToolStripMenuItem
            // 
            this.действияToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.добавитьПользователяToolStripMenuItem,
            this.удалитьПользователяToolStripMenuItem,
            this.сохранитьToolStripMenuItem,
            this.создатьВалютуToolStripMenuItem});
            this.действияToolStripMenuItem.Name = "действияToolStripMenuItem";
            this.действияToolStripMenuItem.Size = new System.Drawing.Size(70, 20);
            this.действияToolStripMenuItem.Text = "Действия";
            // 
            // добавитьПользователяToolStripMenuItem
            // 
            this.добавитьПользователяToolStripMenuItem.Name = "добавитьПользователяToolStripMenuItem";
            this.добавитьПользователяToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
            this.добавитьПользователяToolStripMenuItem.Text = "Добавить пользователя";
            this.добавитьПользователяToolStripMenuItem.Click += new System.EventHandler(this.добавитьПользователяToolStripMenuItem_Click);
            // 
            // удалитьПользователяToolStripMenuItem
            // 
            this.удалитьПользователяToolStripMenuItem.Name = "удалитьПользователяToolStripMenuItem";
            this.удалитьПользователяToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
            this.удалитьПользователяToolStripMenuItem.Text = "Удалить пользователя";
            this.удалитьПользователяToolStripMenuItem.Click += new System.EventHandler(this.удалитьПользователяToolStripMenuItem_Click);
            // 
            // сохранитьToolStripMenuItem
            // 
            this.сохранитьToolStripMenuItem.Name = "сохранитьToolStripMenuItem";
            this.сохранитьToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
            this.сохранитьToolStripMenuItem.Text = "Сохранить";
            this.сохранитьToolStripMenuItem.Click += new System.EventHandler(this.сохранитьToolStripMenuItem_Click);
            // 
            // создатьВалютуToolStripMenuItem
            // 
            this.создатьВалютуToolStripMenuItem.Name = "создатьВалютуToolStripMenuItem";
            this.создатьВалютуToolStripMenuItem.Size = new System.Drawing.Size(204, 22);
            this.создатьВалютуToolStripMenuItem.Text = "Создать валюту";
            this.создатьВалютуToolStripMenuItem.Click += new System.EventHandler(this.создатьВалютуToolStripMenuItem_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(645, 247);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(114, 46);
            this.button1.TabIndex = 13;
            this.button1.Text = "Вывести со счёта";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // MainView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(880, 599);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.listBoxHistory);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.listBoxAccount);
            this.Controls.Add(this.listBoxOfUsers);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "MainView";
            this.Text = "Банк КриптоВалют";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxOfUsers;
        private System.Windows.Forms.ListBox listBoxAccount;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.ListBox listBoxHistory;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem действияToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem добавитьПользователяToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem удалитьПользователяToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem сохранитьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem создатьВалютуToolStripMenuItem;
        private System.Windows.Forms.Button button1;
    }
}