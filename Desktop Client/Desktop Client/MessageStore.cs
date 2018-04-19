using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
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
        public List<Message> messages { get; set; }


        public MessageStore()
        {
            messages = new List<Message>();
        }

        public static void writeInfo(string message) {

            string entry = "";

            System.IO.File.AppendAllText(@"C:\Users\Mike\Desktop\WriteLines.txt", message);
        }

        public void SerializeJSONAndStore(String text, DateTime time)
        {
            
            var deSerialized = JsonConvert.DeserializeObject(text);
            JObject serialized = JObject.FromObject(deSerialized);
            JToken message;
            JToken sender;
            serialized.TryGetValue("nText", out message);
            serialized.TryGetValue("nTitle", out sender);

            Message msg = new Message(sender.ToString(), message.ToString());

            Console.WriteLine(msg.who + ": " + msg.message);

            foreach (Message i in messages)
            {
                string senderName = i.who;
                if (msg.who.Equals(sender.ToString())) {

                }
            }

            messages.Add(msg);
          
        }

        public string getJSON(string who, string message)
        {
            Message outMsg = new Message(who, message);
            
            JObject outJSON = (JObject)JToken.FromObject(outMsg);

            return outJSON.ToString();

             
        }

        public void test() {

            string sample = "{\"nActions\":\"[{\"mChoices\":[\"OK\",\"Give me a minute\",\"On my way\",\"Thanks\",\"Sounds good\",\"What up\",\"Yes\",\"No\",\"??\",\"??\",\"??\"],\"mExtras\":{\"mAllowFds\":true,\"mFdsKnown\":true,\"mHasFds\":false,\"mParcelledData\":{\"mOwnsNativeParcelObject\":true,\"mNativePtr\":-1386159824}},\"mLabel\":\"Reply\",\"mResultKey\":\"android.intent.extra.TEXT\",\"mFlags\":1}]\"," +
                            "\"nPackage\":\"com.google.android.talk\"," +
                            "\"nText\":\"This is hangouts\"," +
                            "\"nTicker\":\"Phil Garza: This is hangouts\"," +
                            "\"nTitle\":\"Phil Garza\"}";

            var JSON = JsonConvert.DeserializeObject(sample);

            JObject serialized = JObject.FromObject(JSON);
            JToken message;
            serialized.TryGetValue("nText", out message);
            Console.WriteLine(message.ToString());


        }

        //public static string getMessage(EnvironmentVariableTarget JSONMessage)
        //{
        //    //dynamic message = JObject.Parse


        //   // string line;


        //    StreamReader file = new StreamReader(@"C:\Users\Mike\Desktop\WriteLines.txt");
        //    //while ((line = file.ReadLine()) != null)
        //    {
        //        //string message = ""; 
        //        //message += line;
        //    }

        //    //return message;
        //}
    }
}
