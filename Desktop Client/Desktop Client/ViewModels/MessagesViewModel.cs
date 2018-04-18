using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Runtime.CompilerServices;

namespace Desktop_Client {
    class MessagesViewModel : INotifyPropertyChanged
    {
        private String _connectionStatus { get; set; }
        public String ConnectionStatus
        {
            get
            {
                return _connectionStatus;
            }
            set
            {
                if (_connectionStatus != value)
                {

                }

                _connectionStatus = value;
                onPropertyChanged();
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        protected void onPropertyChanged([CallerMemberName] String propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }




        public MessagesViewModel()
        {

        }

    }
}

