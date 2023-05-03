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
namespace SunnyCtrl2
{
    public partial class UserControl10 : UserControl
    {
        Xobj hostXobj = null;
        public UserControl10()
        {
            InitializeComponent();
        }

        private void UserControl10_Load(object sender, EventArgs e)
        {
            if (WebRT.CreatingXobj != null)
            {
                hostXobj = WebRT.CreatingXobj;
                hostXobj.OnCloudMessageReceived += HostXobj_OnCloudMessageReceived;
            }
        }

        private void HostXobj_OnCloudMessageReceived(Wormhole cloudSession)
        {
        }
    }
}
