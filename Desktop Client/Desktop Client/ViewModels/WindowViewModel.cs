using System;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Input;

namespace Desktop_Client
{
    /// <summary>
    /// The View Model for the Main Window
    /// </summary>
    class WindowViewModel : BaseViewModel
    {
        #region Private Member 
        
        //The Window this view controls.
        private Window _window;

        private int _outerMarginSize = 0;
        private int _windowRadius = 10;

        private WindowDockPosition _DockPosition = WindowDockPosition.Undocked;
        #endregion

        #region Public Properties

        public double WindowMiniumWidth { set; get; } = 400;

        public double WindowMiniumHeight { set; get; } = 400;

        public bool Borderless { get { return (_window.WindowState == WindowState.Maximized || _DockPosition != WindowDockPosition.Undocked); } }

        public int ResizeBorder { get { return Borderless ? 0 : 6; } }

        public Thickness ResizeBorderThickness { get { return new Thickness(ResizeBorder + OuterMarginSize); }}

        //The padding of the inner content of the main window
        public Thickness InnerContentPadding { get; set; } = new Thickness(0);

        public int OuterMarginSize
        {
            get
            {
                return _window.WindowState == WindowState.Maximized ? 0 : _outerMarginSize;
            }
            set
            {
                _outerMarginSize = value;
            }
        }

        public Thickness OuterMarginSizeThickness { get { return new Thickness(OuterMarginSize); }}

        public int WindowRadius
        {
            get
            {
                return _window.WindowState == WindowState.Maximized ? 0 : _windowRadius;
            }
            set
            {
                _windowRadius = value;
            }
        }

        public CornerRadius WindowCornerRadius { get { return new CornerRadius(WindowRadius); } }

        public int TitleHeight { get; set; } = 42;

        public GridLength TitleHeightGridLength { get { return new GridLength(TitleHeight + ResizeBorder); }}

        public ApplicationPage CurrentPage { get; set; } = ApplicationPage.MessageListPage;


        #endregion

        #region commands
        
        public ICommand MinimizeCommand { get; set; }

        public ICommand MaximizeCommand { get; set; }

        public ICommand CloseCommand { get; set; }

        public ICommand MenuCommand { get; set; }

        #endregion


        public WindowViewModel(Window window)
        {
            _window = window;

            //Listen for window resize
            _window.StateChanged += (sender, e) =>
            {
                onPropertyChanged(nameof(ResizeBorderThickness));
                onPropertyChanged(nameof(OuterMarginSize));
                onPropertyChanged(nameof(OuterMarginSizeThickness));
                onPropertyChanged(nameof(WindowRadius));
                onPropertyChanged(nameof(WindowCornerRadius));
            };

            //Create Commands
            MinimizeCommand = new RelayCommand(() => _window.WindowState = WindowState.Minimized);
            MaximizeCommand = new RelayCommand(() => _window.WindowState ^= WindowState.Maximized);
            CloseCommand = new RelayCommand(() => _window.Close());
            MenuCommand = new RelayCommand(() => SystemCommands.ShowSystemMenu(_window, GetMousePosition()));

            //Fix Window Resize issue
            var resizer = new WindowResizer(_window);

            resizer.WindowDockChanged += (dock) =>
            {
                // Store last position
                _DockPosition = dock;

                // Fire off resize events
                WindowResized();
            };

        }

        private Point GetMousePosition()
        {
            // Position of the mouse relative to the window
            var position = Mouse.GetPosition(_window);

            // Add the window position
            return new Point(position.X + _window.Left, position.Y + _window.Top);
        }

        private void WindowResized()
        {
            // Fire off events for all properties that are affected by a resize
            onPropertyChanged(nameof(Borderless));
            onPropertyChanged(nameof(ResizeBorderThickness));
            onPropertyChanged(nameof(OuterMarginSize));
            onPropertyChanged(nameof(OuterMarginSizeThickness));
            onPropertyChanged(nameof(WindowRadius));
            onPropertyChanged(nameof(WindowCornerRadius));
        }
    }
}
