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
    public partial class BalanceWithdrawal : Form
    {

        private MainView mV = null;
        private User user;
        private Balance balance;
        public BalanceWithdrawal(Form callingForm, User u ,Balance b)
        {
            mV = callingForm as MainView;
            user = u;
            balance = b;
            InitializeComponent();
        }

        private void BalanceWithdrawal_Load(object sender, EventArgs e)
        {
            label2.Text = "Была выбрана валюта "+ balance.valute.ToString() + " на счету " + balance.amount.ToString(); 
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MainController.Confirm() == true)
            {
                double amount = double.Parse(textBox1.Text);
                if ((MainController.BalanceWithdrawal(balance, amount)) == true)
                {
                    string note = user.Name + " вывел с баланса " + amount.ToString() + " " + balance.valute.CharCode.ToString();
                    MainController.AddNote(user, note);
                    mV.Update();
                    Close();
                }
                else
                    return;
            }
        }

    }
}
