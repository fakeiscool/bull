using System.Xml.Serialization;

namespace valutebank.DOMAIN
{
    [XmlRoot("ValCurs")]
    public class Valute
    {
        public string CharCode { get; set; }

        public string Name { get; set; }

        public double Rate { get; set; }

        private Valute()
        {

        }
        public Valute(string name, string ccode, string rate)
        {
            CharCode = ccode;
            Name = name;
            Rate = double.Parse(rate);
        }

        public override string ToString()
        {
            return string.Format("{0} ({1})", Name, CharCode);
        }
    }
}