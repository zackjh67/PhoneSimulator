using System;
using System.Windows.Input;

namespace Desktop_Client
{
    class RelayCommand : ICommand
    {
        #region Private Members
        private Action _action;
        #endregion




        #region Public Events

        public event EventHandler CanExecuteChanged = (sender, e) => { };

        #endregion


        #region Constructor

        public RelayCommand(Action action)
        {
            _action = action;
        }

        #endregion




        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {
            _action();
        }
    }
}
