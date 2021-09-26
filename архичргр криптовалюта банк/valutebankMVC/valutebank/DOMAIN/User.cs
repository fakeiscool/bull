using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace valutebank.DOMAIN
{
    public class User
    {
        public string Name { get; set; }
        
        public List<Balance> BalanceList;
        public List<String> History;
        private User()
        {

        }
        public User(string n) {
            Name = n;
            BalanceList = new List<Balance>();
            History = new List<String>();
        }

        public override string ToString()
        {
            return string.Format("{0}", Name);
        }
    }
}
