using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;


namespace valutebank.DOMAIN
{
    [XmlRoot("ValCurs")]
    public  class ValCurs
    {
        [XmlIgnore]
        public  DateTime Date { get; set; }

        [XmlAttribute("Date")]
        public  string StringDate
        {
            get { return Date.ToString(); }

            set { Date = DateTime.Parse(value); }
        }


        [XmlAttribute("name")]
        public  string Name { get; set; }

        [XmlElement("Valute")]
        public  List<Valute> Valutes { get; set; }
    }
}
