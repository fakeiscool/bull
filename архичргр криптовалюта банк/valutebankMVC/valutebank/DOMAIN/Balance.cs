using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace valutebank.DOMAIN
{
    public class Balance
    {
        public Valute valute { get; set; }
        public double amount { get; set; }

        public Balance(double n, Valute u)
        {
            amount = n;
            valute = u;
        }
        public Balance() { 
           
        }

        public override string ToString()
        {
            return string.Format("{0} ({1})", valute.ToString(), amount);
        }

    }
}
