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

namespace Sunny
{
    public partial class NtpCtrl : UserControl
    {
        Xobj thisNode = null;
        public NtpCtrl()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //if (thisNode.ParentNode != null)
            //{
            //    string xml = "<content1 target=\"mainworkclient\">" +
            //        "<layout>" +
            //            "<grid id='properties' rows='2' cols='2' height='300,250,100,' width='300,200,100,' middlecolor='RGB(255,224,192)'>" +
            //                "<grid id='tangramtabctrl_Page2' objid="nucleus" caption=''></grid>" +
            //                "<grid id='test1'></grid>" +
            //                "<grid id='test2'></grid>" +
            //                "<grid id='test3'></grid>" +
            //            "</grid>" +
            //        "</layout>" +
            //      "</content1>";

            //    thisNode.ParentNode.OpenChild(0, 0, button1.Name, xml);
            //}
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //if (thisNode.ParentNode != null)
            //{
            //    string xml = "<content1>" +
            //        "<layout>" +
            //            "<grid style=\"18\">" +
            //                "<grid id='tangramtabctrl_Page2' objid="nucleus" caption='Page 1'></grid>" +
            //                "<grid id='test1' caption='Page 2'></grid>" +
            //                "<grid id='test2' caption='Page 3'></grid>" +
            //                "<grid id='test3' caption='Page 4'></grid>" +
            //            "</grid>" +
            //        "</layout>" +
            //      "</content1>";

            //    thisNode.ParentNode.OpenChild(0, 0, button2.Name, xml);
            //}
        }

        private void NtpCtrl_Load(object sender, EventArgs e)
        {
            thisNode = WebRT.CreatingXobj;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string xml = "<content1>" +
            "<fission>" +
                "<grid style=\"23\">" +
                    "<grid id='tangramtabctrl_Page2' objid=\"nucleus\" caption='Page 1'></grid>" +
                    "<grid id='test1' caption='Page 2'></grid>" +
                    "<grid id='test2' caption='Page 3'></grid>" +
                    "<grid id='test3' caption='Page 4'></grid>" +
                "</grid>" +
            "</fission>" +
            "</content1>";
            Xobj grid = WebRT.Observe(this, "test", xml);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string xml = "<content1>" +
                "<fission>" +
                    "<grid style=\"43\">" +
                        "<grid id='tangramtabctrl_Page2' objid=\"nucleus\" caption='Page 1'></grid>" +
                        "<grid id='test1' caption='Page 2'></grid>" +
                        "<grid id='test2' caption='Page 3'></grid>" +
                        "<grid id='test3' caption='Page 4'></grid>" +
                    "</grid>" +
                "</fission>" +
              "</content1>";
            Xobj grid = WebRT.Observe(treeView1, "test", xml);
        }
    }

}
