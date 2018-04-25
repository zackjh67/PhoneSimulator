

namespace Desktop_Client
{
    /// <summary>
    /// The design-time data for a <see cref="MessageListItemViewModel"/>
    /// </summary>
    public class MessageListItemDesignModel : MessageListItemViewModel
    {

        //A single instance of the design model.
        #region Singleton

        public static MessageListItemDesignModel Instance => new MessageListItemDesignModel(); 
        
        #endregion



        #region Constructor

        /// <summary>
        /// Default Constructor
        /// </summary>
        public MessageListItemDesignModel ()
        {
            Name = "Mike Ames";
            Initials = "MA";
            MessageText = "Somebody once told me the world is gonna roll me. I ain\'t the sharpest tool in the shed.";
            Time = "Just Now";
            Status = "Sent";
            ProfilePictureRGB = "#FF75715E";
        }

        #endregion
    }
}
