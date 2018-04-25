using System;
using System.Collections.Generic;
using System.Linq;
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

namespace Desktop_Client
{
    /// <summary>
    /// Interaction logic for Connection.xaml
    /// </summary>
    public partial class Connection : Page
    {

        ConnectionViewModel cvm;
        Server ts;

        public Connection()
        {

            cvm = new ConnectionViewModel();
            DataContext = cvm;
            //ts = new Server(messa);
            InitializeComponent();
        }

        private void connectButton_click(object sender, RoutedEventArgs e)
        {

            //cvm.ConnectionStatus = "THIS IS  A TEST";
            
            connectButton.IsEnabled = false;
            Task.Factory.StartNew(() => { ts.StartListening(); });
        }
    }
}
