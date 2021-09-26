using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using valutebank.DOMAIN;

namespace valutebank.View
{
    public partial class MainView : Form
    {
        public MainView()
        {
            InitializeComponent();
            MainController.SaveData();
            Update(false);
        }



        public void Update(bool ignore = true)
        {
            if (!ignore) {
                listBoxOfUsers.DataSource = null;
                listBoxOfUsers.DataSource = MainController.GetUsers();
            }
            listBoxAccount.DataSource = (listBoxOfUsers.SelectedItem as User)?.BalanceList?.ToList();
            listBoxHistory.DataSource = (listBoxOfUsers.SelectedItem as User)?.History?.ToList();
     
        }

        private void button4_Click(object sender, EventArgs e)
        {
            var cur = listBoxAccount.SelectedItem as Balance;
            if (cur == null)
            {
                MessageBox.Show("Валюта не выбрана");
                return;
            }
            var user = listBoxOfUsers.SelectedItem as User;
            if (user == null)
            {
                MessageBox.Show("Пользователь не выбран");
                return;
            }
            var bal = listBoxAccount.SelectedItem as Balance;
            var cryptoval = cur.valute.Rate;
            AddCryptoValute addform = new AddCryptoValute(this, cryptoval, user, bal);
            addform.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var user = listBoxOfUsers.SelectedItem as User;
            if (user == null)
            {
                MessageBox.Show("Пользователь не выбран");
                return;
            }
            var bal = listBoxAccount.SelectedItem as Balance;
            if (bal == null)
            {
                MessageBox.Show("Валюта не выбрана");
                return;
            }
            BalanceWithdrawal addform = new BalanceWithdrawal(this, user, bal);
            addform.Show();
        }

        public void button6_Click(object sender, EventArgs e)
        {
            var user = listBoxOfUsers.SelectedItem as User;
            if (user == null)
            {
                MessageBox.Show("Пользователь не выбран");
                return;
            }
            CreateBalance addform = new CreateBalance(this, user);
            addform.Show();
        }


        private void button2_Click(object sender, EventArgs e)
        {
            var user = listBoxOfUsers.SelectedItem as User;
            if (user == null)
            {
                MessageBox.Show("Пользователь не выбран");
                return;
            }
            CryptoCurrencyTransfer addform = new CryptoCurrencyTransfer(this, user);
            addform.Show();
        }




        private void добавитьПользователяToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddNewUser addform = new AddNewUser(this);
            addform.Show();
        }

        private void создатьВалютуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddNewValute addform = new AddNewValute();
            addform.Show();
        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MainController.SaveData();
        }

        private void удалитьПользователяToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var user = listBoxOfUsers.SelectedItem as User;
            if (user == null)
            {
                MessageBox.Show("Пользователь не выбран");
                return;
            }
            if (MainController.Confirm() == true)
            {
                MainController.DeleteUser(user);
            }
            Update(false);
        }

        private void listBoxOfUsers_SelectedIndexChanged(object sender, EventArgs e)
        {
            Update();
        }
    }
}
