
namespace Desktop_Client
{
    /// <summary>
    /// A view model for each message item in the overview message list.
    /// </summary>
    public class MessageListItemViewModel : BaseViewModel
    {
        public string Name { get; set; }
        public string Initials { get; set; }
        public string MessageText { get; set; }
        public string Time { get; set; }
        public string Status { get; set; }
        /// <summary>
        /// The RGB values (in hex) for the background color of the profile picture.
        /// </summary>
        public string ProfilePictureRGB { get; set; }
    }
}
