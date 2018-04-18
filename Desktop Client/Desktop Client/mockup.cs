using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Desktop_Client
{
    public class mockup
    {

        public List<MessageListItemViewModel> list { get; set; }

        public mockup()
        {
            list = new List<MessageListItemViewModel>
            {
                new MessageListItemViewModel
                {
                    Name = "Mike Ames",
                    Initials = "MA",
                    MessageText = "Somebody once told me the world is gonna roll me.",
                    Status = "Sent",
                    Time = "Just Now",
                    ProfilePictureRGB = "#FF75715E"
                },
                 new MessageListItemViewModel
                {
                    Name = "Zach Hern",
                    Initials = "ZH",
                    MessageText = "I ain't the sharpest tool in the shed.",
                    Status = "",
                    Time = "1 Minute",
                    ProfilePictureRGB = "#FF66D9EF"
                },
                  new MessageListItemViewModel
                {
                    Name = "Phil Garza",
                    Initials = "PG",
                    MessageText = "Well she was looking kinda dumb with her fingers and her thumb in the shape of an L on her forehead.",
                    Status = "",
                    Time = "15 Minutes",
                    ProfilePictureRGB = "#FFA6E22E"
                }
            };
        }


    }
}
