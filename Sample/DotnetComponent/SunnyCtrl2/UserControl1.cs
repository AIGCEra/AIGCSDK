/********************************************************************************
*					Sunny - version 1.0.0.202101010001							*
*********************************************************************************
* Copyright (C) 2002-2020 by Tangram Team.   All Rights Reserved.				*
*
* This SOURCE CODE is governed by a BSD - style license that can be
* found in the LICENSE file.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangram.dev
********************************************************************************/

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
    public partial class UserControl1 : UserControl
    {
        Xobj hostXobj = null;
        public UserControl1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (hostXobj != null)
            {
                hostXobj.Wormhole.InsertString("msgID", "UserControl1_testButton1_click");
                hostXobj.Wormhole.InsertString("testVal", "this is a test for Usercontrol1");
                hostXobj.Wormhole.SendMessage();
            }
        }

        private void UserControl1_Load(object sender, EventArgs e)
        {
            if (WebRT.CreatingXobj != null)
            {
                hostXobj = WebRT.CreatingXobj;
                hostXobj.OnCloudMessageReceived += HostXobj_OnCloudMessageReceived;
            }
        }

        private void HostXobj_OnCloudMessageReceived(Wormhole cloudSession)
        {
            string strMsgID = cloudSession.GetString("msgID");
            switch (strMsgID)
            {
                case "UserControl6_testButtonClickCallback":
                    string strVal = cloudSession.GetString("callbackval");
                    if (!string.IsNullOrEmpty(strVal))
                    {
                        MessageBox.Show(strVal + "  CloudMessage Process by UserControl1");
                        button1.Text = strVal+" Modify button text";
                    }
                    break;
            }
        }
    }
}
