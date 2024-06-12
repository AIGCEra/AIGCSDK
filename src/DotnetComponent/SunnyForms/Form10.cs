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
    public partial class Form10 : Form
    {
        public Form10()
        {
            InitializeComponent();
        }

        private void Form10_Load(object sender, EventArgs e)
        {
            Xobj hostXobj = null;
            hostXobj = WebRT.GetXobjFromControl(this);
            if (hostXobj != null)
                hostXobj.OnCloudMessageReceived += HostXobj_OnCloudMessageReceived; ;
        }

        private void HostXobj_OnCloudMessageReceived(Wormhole cloudSession)
        {
            //throw new NotImplementedException();
        }
    }
}
