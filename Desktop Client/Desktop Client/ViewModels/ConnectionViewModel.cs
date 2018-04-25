using System;
using PropertyChanged;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace Desktop_Client
{

    

    class ConnectionViewModel : INotifyPropertyChanged
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

        public event PropertyChangedEventHandler PropertyChanged; //= (sender, e) => { };

        protected void onPropertyChanged([CallerMemberName] String propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }




        public ConnectionViewModel() {
           
        }

    }
}
