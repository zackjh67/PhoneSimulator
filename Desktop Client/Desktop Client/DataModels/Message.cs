using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Desktop_Client.Models
{
    class Message
    {
        private string messageText;
        private DateTime dateTime;
        public string sender;

        public string MessageText { get => messageText; set => messageText = value; }
        public DateTime DateTime { get => dateTime; set => dateTime = value; }
        public DateTime DateTime1 { get => dateTime; set => dateTime = value; }

        public Message(string messageText, DateTime dateTime, string sender)
        {
            this.messageText = messageText;
            this.dateTime = dateTime;
            this.sender = sender;
        }

    }

}
