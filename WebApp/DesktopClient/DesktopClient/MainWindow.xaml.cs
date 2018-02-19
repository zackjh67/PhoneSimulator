﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace DesktopClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            String localIP = "?";

            InitializeComponent();

            //Credit: https://stackoverflow.com/questions/3253701/get-public-external-ip-address 
            localIP = new System.Net.WebClient().DownloadString("https://api.ipify.org");
            this.localIP.Content = localIP;

            
        }

       
    }
}
