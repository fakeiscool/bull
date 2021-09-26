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
using valutebank.View;

namespace valutebank.View
{
    public partial class CryptoCurrencyTransfer : Form
    {
        private MainView mV = null;
        private User user;
        public CryptoCurrencyTransfer(Form callingForm, User u)
        {
            mV = callingForm as MainView;
            user = u;
            InitializeComponent();
            LabelSelected.Text = "Был выбран: " + user.Name;
        }

        private void CryptoCurrencyTransfer_Load(object sender, EventArgs e)
        {
            ListFrom.DataSource = user?.BalanceList?.ToList();
            var userList = MainController.GetUsers().Where(x => x != user).ToList();
            ListUsers.DataSource = userList;
        }

        private void listBoxListToTrans_SelectedIndexChanged(object sender, EventArgs e)
        {
            var user = ListUsers.SelectedItem as User;
            ListTo.DataSource = user?.BalanceList?.ToList();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MainController.Confirm() == true)
            {
                Balance from = ListFrom.SelectedItem as Balance, to = ListTo.SelectedItem as Balance;
                double amount = MainController.Transfer(from, to, TextAmount.Text);
                if (amount != -1)
                {
                    string note = user.Name + " перевел " + amount.ToString() +
                         " с " + from.valute.CharCode +
                         " юзеру " + (ListUsers.SelectedItem as User).ToString() + " на " + to.valute.CharCode +" (" + textBox3.Text + ")";
                    MainController.AddNote(user, note);
                    MainController.AddNote(ListUsers.SelectedItem as User, note);
                    mV.Update();
                    Close();
                }
            }
        }

        private void TextAmount_TextChanged(object sender, EventArgs e)
        {
            Balance from = ListFrom.SelectedItem as Balance, to = ListTo.SelectedItem as Balance;
            if (TextAmount.Text != null && TextAmount.Text != "")
            {
                double transaction = MainController.Calculate(from.valute, to.valute, TextAmount.Text);
                textBox3.Text = transaction.ToString();
            }
        }
    }
}
