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
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Universe;

namespace SunnyForms2
{
    public partial class Form1 : Form
    {
        Xobj hostXobj = null;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(hostXobj!=null)
            {
                hostXobj.Wormhole.InsertString("msgID", "testButton1_click");
                hostXobj.Wormhole.InsertString("testVal", "this is a test");
                hostXobj.Wormhole.SendMessage();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            if(WebRT.CreatingXobj!=null)
            {
                hostXobj= WebRT.CreatingXobj;
                hostXobj.OnCloudMessageReceived += HostXobj_OnCloudMessageReceived;
            }
        }

        private void HostXobj_OnCloudMessageReceived(Wormhole cloudSession)
        {
            string strMsgID = cloudSession.GetString("msgID");
            switch(strMsgID)
            {
                case "testButtonClickCallback":
                    string strVal = cloudSession.GetString("callbackval");
                    if(!string.IsNullOrEmpty(strVal))
                        MessageBox.Show(strVal);
                    break;
            }
        }
    }
}
