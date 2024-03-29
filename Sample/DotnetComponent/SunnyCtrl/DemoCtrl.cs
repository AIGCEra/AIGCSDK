﻿/********************************************************************************
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

namespace SunnyCtrl
{
    public partial class DemoCtrl : UserControl
    {
        public DemoCtrl()
        {
            InitializeComponent();
        }

        private void StartBtn_Click(object sender, EventArgs e)
        {
            Button bt = sender as Button;
            WebRT.Observe(panel1, bt.Name, "..\\xml\\" + bt.Name + ".xml");
        }

        private void StartBtn1_Click(object sender, EventArgs e)
        {
            Button bt = sender as Button;
            WebRT.Observe(panel1, bt.Name, "..\\xml\\"+bt.Name+".xml");
        }

        private void StartBtn2_Click(object sender, EventArgs e)
        {
            Button bt = sender as Button;
            WebRT.Observe(panel1, bt.Name, "..\\xml\\" + bt.Name + ".xml");
        }
    }
}
