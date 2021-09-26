using System;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using valutebank.DOMAIN;

namespace valutebank.View
{
    public partial class AddNewUser : Form
    {
        private MainView mV = null;
        public AddNewUser(Form callingForm)
        {
            mV = callingForm as MainView;
            InitializeComponent();
            ActiveControl = textBox1;
        }

        private void Create()
        {
            Regex regex = new Regex(@"^[a-zA-Z0-9]+([._]?[a-zA-Z0-9]+)*$");
            User u = new User(textBox1.Text);
            if (regex.IsMatch(u.Name) == true)
            {
                if (MainController.AddUser(u) == true)
                {
                    mV.Update(false);
                    Close();
                }
                else
                    MessageBox.Show("Пользователь с таким именем уже существует");
            }
            else
                MessageBox.Show("Имя пользователя не удовлетворяет регулярному выражению", "Введены запрещенные символы");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MainController.Confirm() == true)
            {
                Create();
            }
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                if (MainController.Confirm() == true)
                {
                    Create();
                }
        }
    }
}
