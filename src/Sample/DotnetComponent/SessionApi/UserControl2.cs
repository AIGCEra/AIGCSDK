using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SessionApi
{
    public partial class UserControl2 : UserControl
    {
        private Universe.Xobj thisNode = null;

        public class MyEventArgs : EventArgs
        {
            public string Value { get; set; }

            public MyEventArgs(string value)
            {
                this.Value = value;
            }
        }

        public event EventHandler<MyEventArgs> MyEvent;

        public UserControl2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MyEvent?.Invoke(this, new MyEventArgs(textBox1.Text));
        }

        private void UserControl2_Load(object sender, EventArgs e)
        {
            thisNode = Universe.Cosmos.CreatingXobj;
            thisNode.OnBindCLRObjToWebPage += ThisNode_OnBindCLRObjToWebPage;
        }

        private void ThisNode_OnBindCLRObjToWebPage(object SourceObj, Universe.Wormhole eventSession, string eventName)
        {
            switch (eventName)
            {
                case "OnMyEvent":
                    if (SourceObj is UserControl2 userControl2)
                    {
                        userControl2.MyEvent += UserControl2_MyEvent;
                    }
                    break;
                default:
                    break;
            }
        }

        private void UserControl2_MyEvent(object sender, MyEventArgs e)
        {
            if (Universe.Cosmos.Wormholes.TryGetValue(sender, out Universe.Wormhole session))
            {
                if (sender is UserControl2 userControl2)
                {
                    session.InsertString("msgID", "FIRE_EVENT");
                    session.InsertLong("message", 20201204);
                    session.InsertString("currentsubobj", userControl2.Name);
                    session.InsertString("currentevent", "OnMyEvent");
                    session.InsertString("value", e.Value);
                    session.SendMessage();
                }
            }
        }
    }
}
