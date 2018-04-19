using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Desktop_Client
{
    


    class Message
    {
        public string who { get; set; }
        public string message { get; set; }
        //public DateTime Time { get; set; }

        public Message(string Sender, string Text)
        {
            this.who = Sender;
            this.message = Text;
        }
    }
}
