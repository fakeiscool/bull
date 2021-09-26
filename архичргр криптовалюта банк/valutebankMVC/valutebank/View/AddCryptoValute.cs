using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization;
using System.Windows.Forms;
using valutebank.DOMAIN;
using valutebank.View;

namespace valutebank.View
{
    public partial class AddCryptoValute : Form
    {
        private MainView mV = null;
        private double rate;
        private User user;
        private Balance balance;
        public AddCryptoValute(Form callingForm, double cv, User u, Balance b)
        {
            mV = callingForm as MainView;
            rate = cv;
            user = u;
            balance = b;
            InitializeComponent();
        }

        private double Calculate()
        {
            return MainController.Calculate(ListValutes.SelectedItem as Valute, balance.valute, textBox1.Text, textBox2);
        }

        private void ValuteView_Load(object sender, EventArgs e)
        {
            ListValutes.DataSource = MainController.GetValutes();
            textBox1.Text = "1";
            textBox2.Text = "1";
            label1.Text = "Цена вашей " + balance.valute.CharCode + " валюты";
            Calculate();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MainController.Confirm() == true)
            {
                double amount = Calculate();
                MainController.AddToBalance(balance, amount);
                string note = user.Name + " пополнил баланс на " + amount.ToString()+ " " + balance.valute.CharCode + " с помощью " + (ListValutes.SelectedItem as Valute).Name.ToString() + " (" + textBox1.Text + ")";
                MainController.AddNote(user, note);
                mV.Update();
                Close();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox3.Text = Convert.ToString(Calculate());
            textBox4.Text = (ListValutes.SelectedItem as Valute).Rate.ToString();
        }

        private void listBoxOfCryptoIndValute_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox3.Text = Convert.ToString(Calculate());
            textBox4.Text = (ListValutes.SelectedItem as Valute).Rate.ToString();
        }
    }
}
