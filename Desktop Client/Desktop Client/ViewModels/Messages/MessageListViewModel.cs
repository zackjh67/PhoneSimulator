
using System.Collections.Generic;

namespace Desktop_Client
{
    /// <summary>
    /// A view model for the message list.
    /// </summary>
    public class MessageListViewModel : BaseViewModel
    {
        public List<MessageListItemViewModel> list { get; set; }
       
    }
}
