using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Universe;

namespace SunnyForms
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void Form5_Load(object sender, EventArgs e)
        {
            hostXobj = WebRT.GetXobjFromControl(this);
            if (hostXobj != null)
                hostXobj.OnCloudMessageReceived += HostXobj_OnCloudMessageReceived;
        }

        private void HostXobj_OnCloudMessageReceived(Wormhole cloudSession)
        {
            string strMsgID = cloudSession.GetString("msgID");
            switch (strMsgID)
            {
                case "testButtonClickCallback":
                    string strVal = cloudSession.GetString("callbackval");
                    if (!string.IsNullOrEmpty(strVal))
                    {
                        MessageBox.Show(strVal+ " CloudMessage Process by Form5");
                        button1.Text = strVal;
                    }
                    break;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
