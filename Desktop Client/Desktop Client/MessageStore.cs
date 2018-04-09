using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Desktop_Client
{
    class MessageStore
    {
        public List<String> messages { get; set; }
        string message;

        public MessageStore()
        {
            messages = new List<String>();
        }

        public static void writeInfo(string message) {

            string entry = "";

            System.IO.File.AppendAllText(@"C:\Users\Mike\Desktop\WriteLines.txt", message);
        }

        public static string getMessage()
        {
            string line;
            string message = "This is not from file. ";

            StreamReader file = new StreamReader(@"C:\Users\Mike\Desktop\WriteLines.txt");
            while ((line = file.ReadLine()) != null)
            {
                //string message = ""; 
                message += line;
            }

            return message;
        }
    }
}
