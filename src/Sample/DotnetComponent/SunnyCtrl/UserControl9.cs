using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Universe;
namespace SunnyCtrl
{
    public partial class UserControl9 : UserControl
    {
        Xobj hostXobj = null;
        public UserControl9()
        {
            InitializeComponent();
        }

        private void UserControl9_Load(object sender, EventArgs e)
        {
            hostXobj = WebRT.CreatingXobj;
            if (hostXobj != null)
                hostXobj.OnCloudMessageReceived += HostXobj_OnCloudMessageReceived;
        }

        private void HostXobj_OnCloudMessageReceived(Wormhole cloudSession)
        {
        }
    }
}
