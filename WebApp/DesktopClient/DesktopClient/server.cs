/***************************************** 
 CREDIT: This code is adapted from:
 https://docs.microsoft.com/en-us/dotnet/framework/network-programming/asynchronous-server-socket-example
 
 *****************************************/


using System;
using System.Net;
using System.Net.Sockets;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace DesktopClient
{


    public class StateObject
    {
        //Client socket.
        public Socket workSocket = null;

        //Size of the receive buffer;
        public const int BufferSize = 4096;

        //Receive buffer
        public byte[] buffer = new byte[BufferSize];

        //Received data string;
        public StringBuilder sb = new StringBuilder();
    }

    public class AsynchSocketListener
    {
        public const int port = 8417;

        //Thread signal.
        public static ManualResetEvent allDone = new ManualResetEvent(false);

        public AsynchSocketListener()
        {

        }

        public static void StartListening()
        {
            // running the listener is "host.contoso.com".  
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            foreach (IPAddress myIp in ipHostInfo.AddressList)
            {
                Console.WriteLine(string.Format("myIp: {0} myFam: {1}", myIp, myIp.AddressFamily));
            }
            IPAddress ipAddress = ipHostInfo.AddressList[2];
            IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, 8417);
            Console.WriteLine(string.Format("My IP ADDRESS: {0}", localEndPoint));
            Console.WriteLine(string.Format("My IP ADDRESS: {0}", ipAddress));

            TcpListener serverSocket = new TcpListener(localEndPoint);
            TcpClient clientSocket = default(TcpClient);
            int counter = 0;

            serverSocket.Start();
            Console.WriteLine(" >> " + "Server Started");
            App.Current.Dispatcher.Invoke(() => {
                Label conStatusBox = (Label)App.Current.MainWindow.FindName("connectionStatus");
                conStatusBox.Content = "Waiting for a connection . . .";
            });

            counter = 0;
            while (true)
            {
                counter += 1;
                clientSocket = serverSocket.AcceptTcpClient();
                Console.WriteLine(" >> " + "Client No:" + Convert.ToString(counter) + " started!");
                App.Current.Dispatcher.Invoke(() => {
                    Label conStatusBox = (Label)App.Current.MainWindow.FindName("connectionStatus");
                    conStatusBox.Content = " >> " + "Client No:" + Convert.ToString(counter) + " started!";
                });

                handleClinet client = new handleClinet();
                client.startClient(clientSocket, Convert.ToString(counter));
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
        public void startClient(TcpClient inClientSocket, string clineNo)
        {
            this.clientSocket = inClientSocket;
            this.clNo = clineNo;
            Thread ctThread = new Thread(DoChat);
            ctThread.Start();
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
                        do
                        {
                            numberOfBytesRead = networkStream.Read(myReadBuffer, 0, myReadBuffer.Length);
                            myCompleteMessage.AppendFormat("{0}", Encoding.UTF8.GetString(myReadBuffer, 0, numberOfBytesRead));
                        }
                        while (networkStream.DataAvailable);
                        if (numberOfBytesRead > 0)
                        {
                            string temp = myCompleteMessage.ToString();
                            Console.WriteLine(" >> " + "From client-" + temp + " " + DateTime.Now);
                            string[] myCommand = temp.Split(' ');
                            if (myCommand[0].Contains("Connect"))
                            {
                                Console.WriteLine("Client Connected " + clientSocket.Client.RemoteEndPoint + " " + DateTime.Now);
                                string serverResponse = "404 OK\r\n";
                                byte[] sendBytes = Encoding.UTF8.GetBytes(serverResponse);
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






    //public static void AcceptCallback(IAsyncResult ar) {
    //    //Signal the main thread to continue.
    //    allDone.Set();

    //    //Get the socket that handles the client request.
    //    Socket listener = (Socket)ar.AsyncState;
    //    Socket handler = listener.EndAccept(ar);

    //    //Create the state object.
    //    StateObject state = new StateObject();
    //    state.workSocket = handler;
    //    handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0, new AsyncCallback(ReadCallback), state);
    //}

    //public static void ReadCallback(IAsyncResult ar) {
    //    String content = String.Empty;

    //    //Retrieve the state object and the handler socket
    //    //from the asynch state object.
    //    StateObject state = (StateObject)ar.AsyncState;
    //    Socket handler = state.workSocket;

    //    //Read data from the client socket.
    //    int bytesRead = handler.EndReceive(ar);

    //    if (bytesRead > 0) {
    //        //There might be more data, so store the data received so far.
    //        state.sb.Append(Encoding.UTF8.GetString(
    //            state.buffer, 0, bytesRead));

    //        //Check for end-of-file tag. If is is not there, read
    //        //more data.
    //        content = state.sb.ToString();
    //        if (content.IndexOf("<EOF>") > -1)
    //        {
    //            //All the data has been read from the
    //            //client. Display it on the console.
    //            Console.WriteLine("Read {0} bytes from socket. \n Data : {1}",
    //                content.Length, content);
    //            //Echo the data back to the client.
    //            Send(handler, content);
    //        } else {
    //            handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
    //            new AsyncCallback(ReadCallback), state);
    //        }

    //    }

    //}

    //private static void Send(Socket handler, String data) {
    //    //Convert the string data to byte data using UTF8 encoding.
    //    byte[] byteData = Encoding.UTF8.GetBytes(data);

    //    //Begin sending the data to the remote device.
    //    handler.BeginSend(byteData, 0, byteData.Length, 0,
    //        new AsyncCallback(SendCallback), handler);
    //}

    //private static void SendCallback(IAsyncResult ar) {
    //    try {
    //        //Retrieve the socket from the state object.
    //        Socket handler = (Socket)ar.AsyncState;

    //        //Complete sending the data to the remote device.
    //        int bytesSent = handler.EndSend(ar);
    //        Console.WriteLine("Sent {0} bytes to client.", bytesSent);

    //        handler.Shutdown(SocketShutdown.Both);
    //        handler.Close();
    //    }
    //    catch (Exception e) {
    //        Console.WriteLine(e.ToString());
    //    }
    //}

    //private void updateConStatus() {


    //}

}

