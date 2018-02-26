﻿/***************************************** 
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

        public AsynchSocketListener() {
            
        }

        public static void StartListening() {
            //Data buffer for incoming data.
            byte[] bytes = new Byte[4096];

            //Establish the local endpoint for the socket.
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            IPEndPoint localEndPoint = new IPEndPoint(ipAddress, port);

            //Create a TCP/IP socket.
            Socket listener = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            //Bind the socket to the local endpoint and listen for incoming connections.
            try
            {
                listener.Bind(localEndPoint);
                listener.Listen(100);

                while (true)
                {
                    //Set the event to nonsignaled state.
                    allDone.Reset();

                    //Start an asynch socket to listen for connections.              
                    Console.WriteLine("Waiting for a connection . . .");

                    //Invoke UI thread.
                    App.Current.Dispatcher.Invoke( () => {
                        Label conStatusBox = (Label) App.Current.MainWindow.FindName("connectionStatus");
                        conStatusBox.Content = "Waiting for a connection . . .";                      
                    });
      
                    listener.BeginAccept(
                        new AsyncCallback(AcceptCallback), 
                        listener);

                    //Wait until a connection is made before continuing.
                    allDone.WaitOne();
                }
            }
            catch (Exception e) {
                Console.WriteLine(e.ToString());
            }

            Console.WriteLine("\nPress ENTER to continue . . .");
            Console.Read();

        }

        public static void AcceptCallback(IAsyncResult ar) {
            //Signal the main thread to continue.
            allDone.Set();

            //Get the socket that handles the client request.
            Socket listener = (Socket)ar.AsyncState;
            Socket handler = listener.EndAccept(ar);

            //Create the state object.
            StateObject state = new StateObject();
            state.workSocket = handler;
            handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0, new AsyncCallback(ReadCallback), state);
        }

        public static void ReadCallback(IAsyncResult ar) {
            String content = String.Empty;

            //Retrieve the state object and the handler socket
            //from the asynch state object.
            StateObject state = (StateObject)ar.AsyncState;
            Socket handler = state.workSocket;

            //Read data from the client socket.
            int bytesRead = handler.EndReceive(ar);

            if (bytesRead > 0) {
                //There might be more data, so store the data received so far.
                state.sb.Append(Encoding.ASCII.GetString(
                    state.buffer, 0, bytesRead));

                //Check for end-of-file tag. If is is not there, read
                //more data.
                content = state.sb.ToString();
                if (content.IndexOf("<EOF>") > -1)
                {
                    //All the data has been read from the
                    //client. Display it on the console.
                    Console.WriteLine("Read {0} bytes from socket. \n Data : {1}",
                        content.Length, content);
                    //Echo the data back to the client.
                    Send(handler, content);
                } else {
                    handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
                        new AsyncCallback(ReadCallback), state);
                }
                                                
            }
                                    
        }

        private static void Send(Socket handler, String data) {
            //Convert the string data to byte data using ASCII encoding.
            byte[] byteData = Encoding.ASCII.GetBytes(data);

            //Begin sending the data to the remote device.
            handler.BeginSend(byteData, 0, byteData.Length, 0,
                new AsyncCallback(SendCallback), handler);
        }

        private static void SendCallback(IAsyncResult ar) {
            try {
                //Retrieve the socket from the state object.
                Socket handler = (Socket)ar.AsyncState;

                //Complete sending the data to the remote device.
                int bytesSent = handler.EndSend(ar);
                Console.WriteLine("Sent {0} bytes to client.", bytesSent);

                handler.Shutdown(SocketShutdown.Both);
                handler.Close();
            }
            catch (Exception e) {
                Console.WriteLine(e.ToString());
            }
        }

        private void updateConStatus() {

            
        }
      
    }
}
