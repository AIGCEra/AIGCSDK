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
    public partial class Form7 : Form
    {
        Xobj hostXobj = null;
        public Form7()
        {
            InitializeComponent();
        }

        private void Form7_Load(object sender, EventArgs e)
        {
            hostXobj = WebRT.GetXobjFromControl(this);
            if (hostXobj != null)
                hostXobj.OnCloudMessageReceived += HostXobj_OnCloudMessageReceived;
        }

        private void HostXobj_OnCloudMessageReceived(Wormhole cloudSession)
        {
        }
    }
}
