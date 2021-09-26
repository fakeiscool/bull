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
    public partial class CreateBalance : Form
    {
        private MainView mV = null;
        private User user;
        public CreateBalance(Form callingForm, User u)
        {
            mV = callingForm as MainView;
            user = u;
            InitializeComponent();
        }

        private void ValuteView_Load(object sender, EventArgs e)
        {
            listBoxOfCryptoValutes.DataSource = MainController.GetValutes();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            if (MainController.Confirm() == true)
            {
                MainController.CreateNewBalance(user, listBoxOfCryptoValutes.SelectedItem as Valute);
                mV.Update();
                Close();
            }
        }
    }
}
