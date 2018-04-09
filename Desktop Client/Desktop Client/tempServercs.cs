using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace Desktop_Client
{
    class tempServercs
    {

        public  void StartListening()
        {

            ConnectionViewModel connectionViewModel = new ConnectionViewModel();


            // Establish the local endpoint for the socket.  
            // The DNS name of the computer  
            // running the listener is "host.contoso.com".  
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            foreach (IPAddress myIp in ipHostInfo.AddressList)
            {
                Console.WriteLine(string.Format("myIp: {0} myFam: {1}", myIp, myIp.AddressFamily));
            }
            IPAddress ipAddress = ipHostInfo.AddressList[2];
            IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, 1337);
            Console.WriteLine(string.Format("My IP ADDRESS: {0}", localEndPoint));
            TcpListener serverSocket = new TcpListener(localEndPoint);
            TcpClient clientSocket = default(TcpClient);
            int counter = 0;

            serverSocket.Start();
            Console.WriteLine(" >> " + "Server Started");

            counter = 0;
            while (true)
            {
                counter += 1;
                clientSocket = serverSocket.AcceptTcpClient();
                Console.WriteLine(" >> " + "Client No:" + Convert.ToString(counter) + " started!");
                App.Current.Dispatcher.Invoke(() => {
                    Label conStatusBox = (Label)App.Current.MainWindow.FindName("conStatusBox");
                    conStatusBox.Content = " >> " + "Client No:" + Convert.ToString(counter) + " started!";
                });
                handleClinet client = new handleClinet();
                client.startClient(clientSocket, Convert.ToString(counter));
                client.receiveMessage();
            }

            clientSocket.Close();
            serverSocket.Stop();
            Console.WriteLine(" >> " + "exit");
            Console.ReadLine();
        }
    }

    //Class to handle each client request separatly
    public class handleClinet
    {
        TcpClient clientSocket;
        string clNo;

        public void receiveMessage()
        {
            Thread ctThread = new Thread(DoChat);
            ctThread.Start();
        }

        public void sendMesage(string message)
        {
            Thread ctThread = new Thread(() => sendToPhone(message));
            ctThread.Start(message);
        }



        public void startClient(TcpClient inClientSocket, string clineNo)
        {
            this.clientSocket = inClientSocket;
            this.clNo = clineNo;
            //Thread ctThread = new Thread(DoChat);
            //ctThread.Start();
        }

        


        private void DoChat()
        {
            int requestCount = 0;
            Boolean connected = true;

            while ((connected))
            {
                try
                {
                    if (clientSocket.Connected)
                    {
                        requestCount = requestCount + 1;
                        NetworkStream networkStream = clientSocket.GetStream();
                        byte[] myReadBuffer = new byte[1024];
                        StringBuilder myCompleteMessage = new StringBuilder();
                        int numberOfBytesRead = 0;
                        string myMessage;
                        do
                        {
                            byte[] getLenBytes = new byte[4];
                            networkStream.Read(getLenBytes, 0, 4);
                            numberOfBytesRead = BitConverter.ToInt32(getLenBytes, 0);
                            byte[] getBytes = new byte[numberOfBytesRead];
                            networkStream.Read(getBytes, 0, numberOfBytesRead);
                            //myCompleteMessage.AppendFormat("{0}", Encoding.UTF8.GetString(getBytes, 0, getBytes));
                            myMessage = Encoding.UTF8.GetString(getBytes);
                        }
                        while (networkStream.DataAvailable);
                        if (numberOfBytesRead > 0)
                        {
                            string temp = myMessage;
                            Console.WriteLine(" >> " + "From client-" + temp + " " + DateTime.Now);
                            string[] myCommand = temp.Split(' ');
                            if (myCommand[0].Contains("Connect"))
                            {
                                Console.WriteLine("Client Connected " + clientSocket.Client.RemoteEndPoint + " " + DateTime.Now);
                                string serverResponse = "404 OK";
                                byte[] sendBytes = Encoding.UTF8.GetBytes(serverResponse);
                                byte[] num = System.BitConverter.GetBytes(sendBytes.Length);
                                networkStream.Write(num, 0, 4);
                                networkStream.Write(sendBytes, 0, sendBytes.Length);
                            }
                            else if (myCommand[0].Contains("Disconnect"))
                            {
                                connected = false;
                                Console.Write("Client D/C " + clientSocket.Client.RemoteEndPoint + " " + DateTime.Now);
                            }
                            //networkStream.Flush();
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(" >> " + ex.ToString());
                }
            }
        }

        private void sendToPhone(string message)
        {
            int requestCount = 0;
            Boolean connected = true;

            while ((connected))
            {
                try
                {
                    if (clientSocket.Connected)
                    {
                        requestCount = requestCount + 1;
                        NetworkStream networkStream = clientSocket.GetStream();
                        byte[] myReadBuffer = new byte[1024];
                        StringBuilder myCompleteMessage = new StringBuilder();
                        int numberOfBytesRead = 0;
                        string myMessage;
                        do
                        {
                            byte[] getLenBytes = new byte[4];
                            networkStream.Read(getLenBytes, 0, 4);
                            numberOfBytesRead = BitConverter.ToInt32(getLenBytes, 0);
                            byte[] getBytes = new byte[numberOfBytesRead];
                            networkStream.Read(getBytes, 0, numberOfBytesRead);
                            //myCompleteMessage.AppendFormat("{0}", Encoding.UTF8.GetString(getBytes, 0, getBytes));
                            myMessage = Encoding.UTF8.GetString(getBytes);
                        }
                        while (networkStream.DataAvailable);
                        if (numberOfBytesRead > 0)
                        {
                            string temp = myMessage;
                            Console.WriteLine(" >> " + "From client-" + temp + " " + DateTime.Now);
                            string[] myCommand = temp.Split(' ');
                            if (myCommand[0].Contains("Connect"))
                            {
                                Console.WriteLine("Client Connected " + clientSocket.Client.RemoteEndPoint + " " + DateTime.Now);
                                string serverResponse = "404 OK";
                                byte[] sendBytes = Encoding.UTF8.GetBytes(serverResponse);
                                byte[] num = System.BitConverter.GetBytes(sendBytes.Length);
                                networkStream.Write(num, 0, 4);
                                networkStream.Write(sendBytes, 0, sendBytes.Length);
                            }
                            else if (myCommand[0].Contains("Disconnect"))
                            {
                                connected = false;
                                Console.Write("Client D/C " + clientSocket.Client.RemoteEndPoint + " " + DateTime.Now);
                            }
                            //networkStream.Flush();
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(" >> " + ex.ToString());
                }
            }
        }



    }
}
