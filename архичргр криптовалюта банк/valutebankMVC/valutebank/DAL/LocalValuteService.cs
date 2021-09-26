using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml.Linq;
using System.IO;
using valutebank.DOMAIN;

namespace valutebank.DAL
{ 
    public class LocalValuteService
    {
        public ValCurs Curs = null;
        public ValCurs GetValutes()
        {
            const string path = "./Content/daily.xml";
            if (!File.Exists(path)) return null;

            var xml = XDocument.Load(path);

            using (var stream = xml.CreateReader())
            {
                var ser = new XmlSerializer(typeof(ValCurs));
                Curs = (ValCurs)ser.Deserialize(stream);
                return Curs;
            }
        }
    }
}

