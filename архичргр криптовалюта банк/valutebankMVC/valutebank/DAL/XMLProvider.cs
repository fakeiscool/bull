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
    public static class XMLProvider
    {
        const string ValutePath = "C:\\Users\\FaKe\\source\\repos\\valutebank\\valutebank\\Content\\valutes.xml";
        const string UsersPath = "C:\\Users\\FaKe\\source\\repos\\valutebank\\valutebank\\Content\\users.xml";
        public static List<Valute> LoadValutes()
        {
            if (!File.Exists(ValutePath)) return null;

            using (var aFile = new FileStream(ValutePath, FileMode.Open))
            {
                XmlSerializer formatter = new XmlSerializer(typeof(List<Valute>));
                byte[] buffer = new byte[aFile.Length];
                aFile.Read(buffer, 0, (int)aFile.Length);
                using (var stream = new MemoryStream(buffer))
                {
                    List<Valute> data;
                    try
                    {
                        data = (List<Valute>)formatter.Deserialize(stream);
                    }
                    catch
                    {
                        data = null;
                    }
                    return data;
                }
            }
        }

        public static void SaveValutes(List<Valute> valutes)
        {
            using (var outFile = File.Create(ValutePath))
            {
                XmlSerializer formatter = new XmlSerializer(typeof(List<Valute>));
                formatter.Serialize(outFile, valutes);
            }
        }

        public static List<User> LoadUsers()
        {
            if (!File.Exists(UsersPath)) return null;

            using (var aFile = new FileStream(UsersPath, FileMode.Open))
            {
                XmlSerializer formatter = new XmlSerializer(typeof(List<User>));
                byte[] buffer = new byte[aFile.Length];
                aFile.Read(buffer, 0, (int)aFile.Length);
                using (var stream = new MemoryStream(buffer))
                {
                    List<User> data;
                    try
                    {
                        data = (List<User>)formatter.Deserialize(stream);
                    }
                    catch
                    {
                        data = null;
                    }
                    return data;
                }
            }
        }

        public static void SaveUsers(List<User> users)
        {
            using (var outFile = File.Create(UsersPath))
            {
                XmlSerializer formatter = new XmlSerializer(typeof(List<User>));
                formatter.Serialize(outFile, users);
            }
        }
    }
}

