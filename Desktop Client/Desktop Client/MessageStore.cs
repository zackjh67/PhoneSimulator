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

        public void test() {

            string sample = "{\"nActions\":\"[{\"mChoices\":[\"OK\",\"Give me a minute\",\"On my way\",\"Thanks\",\"Sounds good\",\"What\\u0027s up?\",\"Yes\",\"No\",\"??\",\"??\",\"??\"],\"mExtras\":{\"mAllowFds\":true,\"mFdsKnown\":true,\"mHasFds\":false,\"mParcelledData\":{\"mOwnsNativeParcelObject\":true,\"mNativePtr\":-1386159824}},\"mLabel\":\"Reply\",\"mResultKey\":\"android.intent.extra.TEXT\",\"mFlags\":1}]\"," +
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
