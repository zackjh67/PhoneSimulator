using PropertyChanged;
using System.ComponentModel;

namespace Desktop_Client
{

    /// <summary>
    /// The base view model. Fires Property Changed events as needed.
    /// </summary>
    public class BaseViewModel : INotifyPropertyChanged
    {

        /// <summary>
        /// The event that is fired when any child property changes.
        /// </summary>
        public event PropertyChangedEventHandler PropertyChanged = (sender, e) => { };

        public void onPropertyChanged(string name)
        {
            PropertyChanged(this, new PropertyChangedEventArgs(name));
        }
    }
}
