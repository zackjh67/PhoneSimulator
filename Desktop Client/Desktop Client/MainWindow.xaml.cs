using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
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

namespace Desktop_Client
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        MessageListPage messageListPage;
        MessageStore messageStore;
        Connection connectionPage;
        Devices devicesPage;
        Server server;
        

        public Connection ConnectionPage { get => connectionPage; set => connectionPage = value; }

        public MainWindow()
        {
            messageListPage = new MessageListPage();
            connectionPage = new Connection();
            devicesPage = new Devices();
            messageStore = new MessageStore();
            server = new Server(messageStore);
            this.DataContext = new WindowViewModel(this);
            InitializeComponent();
        }

        private void messageButton_click(object sender, RoutedEventArgs e)
        {
           // Main.Content = messageListPage;
        }


        private void connectionButton_click(object sender, RoutedEventArgs e)
        {
          if (server.client != null)
            {
                server.client.sendMesage("This is a test message from the desktop client");
            }
           
        }

        private void devicesButton_click(object sender, RoutedEventArgs e)
        {
            messageStore.test();
        }

        private void connectButton_click(object sender, RoutedEventArgs e)
        {

            Task.Factory.StartNew(() => { server.StartListening(); });

            //Dispatcher.Invoke(server.StartListening);
        }
    }
}
