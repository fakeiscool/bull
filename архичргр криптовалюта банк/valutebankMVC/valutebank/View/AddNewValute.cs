using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using valutebank.DOMAIN;

namespace valutebank.View
{
    public partial class AddNewValute : Form
    {
        public AddNewValute()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MainController.Confirm() == true)
            {
                double value;
                Regex regex = new Regex(@"^[a-zA-Z]*$");
                if (regex.IsMatch(textBox1.Text) == false || regex.IsMatch(textBox3.Text) == false)
                {
                    MessageBox.Show("Название валюты может содержать только латинские буквы");
                    return;
                }
                if (textBox1.Text.Length < textBox3.Text.Length)
                {
                    MessageBox.Show("Сокращенное название должно быть короче оригинального");
                    return;
                }
                try
                {
                    value = double.Parse(textBox2.Text);
                    Valute valute = new Valute(textBox1.Text, textBox3.Text, textBox2.Text);
                    MainController.AddValute(valute);
                    Close();
                }
                catch
                {
                    MessageBox.Show("Введено некорректное число");
                }
            }
        }
    }
}
