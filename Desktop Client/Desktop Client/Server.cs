using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace Desktop_Client
{
    class Server
    {

        int listeningPort = 1337;
      
        public handleClient client { get; set; }

        public TcpClient clientSocket;

        public void startServer()
        {
            Thread thread = new Thread(StartListening);
        }


        public void StartListening()
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
            IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, listeningPort);
            Console.WriteLine(string.Format("My IP ADDRESS: {0}", localEndPoint));
            TcpListener serverSocket = new TcpListener(localEndPoint);
            clientSocket = default(TcpClient);
            int counter = 0;

            serverSocket.Start();
            Console.WriteLine(" >> " + "Server Started");

            counter = 0;
            // Listen for incoming connections
            while (true)
            {
                counter++;
                //Blocks until a connection arrives, then creates a TcpClient socket
                clientSocket = serverSocket.AcceptTcpClient();
                Console.WriteLine("Client Socket: " + clientSocket.ToString());
                Console.WriteLine(" >> " + "Client No:" + Convert.ToString(counter) + " started!");
             
                // Instantiate Class to process the message.
                //Thread clientSocketThread = new Thread(new handleClient());
                client = new handleClient();
                // Set Class fields.
                client.startClient(clientSocket, Convert.ToString(counter));
                // Start Thread to receive messages
                client.receiveMessage();
                //Start Thread to send messages
                
            }

        }

        public void disconnect(TcpListener serverSocket, TcpClient clientSocket)
        {
            client.networkStream.Close();
            clientSocket.Close();
            serverSocket.Stop();
            Console.WriteLine(" >> " + "exit");
            //Thread.CurrentThread.Abort();
        }
    }

    //Class to handle each client request separatly
    public class handleClient
    {
        TcpClient clientSocket;
        public NetworkStream networkStream { get; set; }
        string clNo;

        public void receiveMessage()
        {
            Thread ctThread = new Thread(DoChat);
            ctThread.Start();
        }

        public void sendMesage(string message)
        {
            var thread = new Thread( () => sendToPhone(message));
            thread.Start();
        }



        public void startClient(TcpClient inClientSocket, string clineNo)
        {
            this.clientSocket = inClientSocket;
            this.clNo = clineNo;
            this.networkStream = clientSocket.GetStream();
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
                        requestCount++;
        
                        byte[] myReadBuffer = new byte[1024];
                        StringBuilder myCompleteMessage = new StringBuilder();
                        int numberOfBytesRead = 0;
                        string myMessage;
                        do
                        {
                            byte[] getLenBytes = new byte[4];
                            //Get the length of the message in number of byters (Method returns number of bytes successfully read)
                            networkStream.Read(getLenBytes, 0, 4);
                            numberOfBytesRead = BitConverter.ToInt32(getLenBytes, 0);
                            byte[] getBytes = new byte[numberOfBytesRead];
                            //Read the message
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
         

            byte[] messageBytes = Encoding.UTF8.GetBytes(message);
            byte[] numMessageBytes = BitConverter.GetBytes(messageBytes.Length);

            try
            {
                if (clientSocket.Connected)
                {
                    networkStream.Write(numMessageBytes, 0, 4);
                    networkStream.Write(messageBytes, 0, BitConverter.ToInt32(numMessageBytes, 0));                 
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(" >> " + ex.ToString());
            }

            return;
          
        }

    }
}
