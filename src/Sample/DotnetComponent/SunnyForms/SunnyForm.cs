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

namespace SunnyForms
{
    public partial class SunnyForm : Form
    {
        public SunnyForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string xml = "<content1>" +
                "<layout>" +
                    "<grid style=\"13\">" +
                        "<grid id='tangramtabctrl_Page2 www' objid=\"nucleus\" caption='Page 1'></grid>" +
                        "<grid id='test1' caption='Page 2 eee'></grid>" +
                        "<grid id='test2' caption='Page 3'></grid>" +
                        "<grid id='test3' caption='Page 4'></grid>" +
                    "</grid>" +
                "</layout>" +
              "</content1>";
            Xobj node = WebRT.Observe(listView1, "test", xml);
            if(node!=null)
                node.OnTabChange += Node_OnTabChange;
            WebRT.CreateBrowser((IntPtr)1,"host:sunny2.html|host:WebPage/newweb.html"); 
        }

        private void Node_OnTabChange(Xobj ActiveXobj, Xobj OldXobj)
        {
            string s1 = ActiveXobj.Caption;
            string s2 = OldXobj.Caption;
            ActiveXobj.Caption = s1 + "test";
        }
    }
}
