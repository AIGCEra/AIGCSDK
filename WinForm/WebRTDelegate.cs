/********************************************************************************
*					Sunny - version 1.0.0.202101010001						    *
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
using System.Xml;
using Universe;
using System.Windows.Forms;

namespace WebRT
{
    static class WebDelegate
    {
        public static void Run(Object FormObj)
        {
            try
            {
                System.Reflection.Assembly am = System.Reflection.Assembly.Load("cosmos");
                if (am != null)
                {
                    Type t = am.GetType("Universe.WebRT");
                    if (t != null)
                    {
                        t.GetMethod("Run", BindingFlags.Public | BindingFlags.Static).Invoke(null, new object[] { FormObj });
                    }
                }

            }
            catch (FileNotFoundException ex)
            {
                if (FormObj != null)
                {
                    if (FormObj.GetType().IsSubclassOf(typeof(Form)))
                    {
                        Application.Run((Form)FormObj);
                    }
                    else if (FormObj.GetType().IsSubclassOf(typeof(ApplicationContext)))
                    {
                        Application.Run((ApplicationContext)FormObj);
                    }
                }
                else
                {
                    Application.Run();
                }
            }
        }

        private static int Init(string argument)
        {
            WebRT.OnBindCLRObjToWebPage += Tangram_OnBindCLRObjToWebPage;
            WebRT.OnGetSubObjForWebPage += Tangram_OnGetSubObjForWebPage;
            WebRT.OnWebRTMsg += Tangram_OnWebRTMsg;
            WebRT.OnCustomizedDOMElement += Tangram_OnCustomizedDOMElement;
            WebRT.OnWebRTMsgReceived += Tangram_OnWebRTMsgReceived;
            return 0;
        }

        private static void Tangram_OnWebRTMsgReceived(Wormhole cloudWormhole)
        {
            if (cloudWormhole != null)
            {
                string strMsgID = cloudWormhole.GetString("msgID");
                IntPtr nHandle = (IntPtr)cloudWormhole.GetInt64("nodehandle");
            }
        }

        private static object Tangram_OnGetSubObjForWebPage(object SourceObj, string subObjName)
        {
            return null;
        }

        private static void Tangram_OnWebRTMsg(IntPtr hWnd, string strType, string strParam1, string strParam2)
        {
        }

        private static void Tangram_OnCustomizedDOMElement(IntPtr hWnd, string strRuleName, string strHTML)
        {
        }

        private static void Tangram_OnBindCLRObjToWebPage(object SourceObj, Wormhole eventWormhole, string eventName)
        {
            switch (eventName)
            {
                case "SizeChanged":
                    {
                        Form thisForm = SourceObj as Form;
                        eventWormhole.AddEventInfo(SourceObj, eventName);
                        //string strData = "@" + thisForm.Handle.ToString() + "@";
                        //string strData = "@" + thisForm.Name + "@";
                        //eventWormhole.EventBindInfo += strData;
                        thisForm.SizeChanged += ThisForm_SizeChanged;
                    }
                    break;
                case "OnClick":
                case "onclick":
                    {
                        Button thisbtn = SourceObj as Button;
                        thisbtn.Click += Thisbtn_Click;
                        eventWormhole.AddEventInfo(SourceObj, eventName);
                        //string strData = "@" + thisbtn.Handle.ToString() + "@";
                        //eventWormhole.EventBindInfo += strData;
                    }
                    break;
                case "TextChanged":
                    {
                        TextBox textBox = SourceObj as TextBox;
                        if (textBox != null)
                        {
                            //eventWormhole.EventBindInfo = "@" + textBox.Handle.ToString() + "@";
                            eventWormhole.AddEventInfo(SourceObj, eventName);
                            textBox.TextChanged += TextBox_TextChanged;
                        }
                    }
                    break;
                case "OnAfterSelect":
                case "onafterselect":
                    {
                        TreeView thisTreeview = SourceObj as TreeView;
                        eventWormhole.AddEventInfo(SourceObj, eventName);
                        //string strData = "@" + thisTreeview.Handle.ToString() + "@";
                        thisTreeview.AfterSelect += ThisTreeview_AfterSelect;
                        //eventWormhole.EventBindInfo += strData;
                    }
                    break;
            }
        }

        private static void TextBox_TextChanged(object sender, EventArgs e)
        {
            if (WebRT.Wormholes.TryGetValue(sender, out Wormhole thisSession))
            {
                TextBox ctrl = sender as TextBox;
                if (ctrl != null)
                {
                    thisSession.InsertString("msgID", "FIRE_EVENT");
                    thisSession.InsertString("currentsubobj", ctrl.Name);
                    thisSession.InsertString("currentevent", "TextChanged@" + ctrl.Name);
                    thisSession.InsertString("text", ctrl.Text);
                    thisSession.SendMessage();
                }
            }
        }

        private static void ThisTreeview_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if (WebRT.Wormholes.TryGetValue(sender, out Wormhole thisSession))
            {
                if (e.Node.Tag != null)
                {
                    string strTag = e.Node.Tag.ToString();
                    XmlDocument xml = new XmlDocument();
                    xml.LoadXml(strTag);
                    foreach (XmlAttribute attribute in xml.ChildNodes[0].Attributes)
                    {
                        thisSession.InsertString(attribute.Name, attribute.Value);
                    }
                    thisSession.InsertString("OnAfterSelectXml", strTag);
                    thisSession.InsertString("OnAfterSelectTagName", xml.FirstChild.Name);
                }
                TreeView treeview = sender as TreeView;
                thisSession.InsertString("msgID", "FIRE_EVENT");
                thisSession.InsertInt64("subobjhandle", treeview.Handle.ToInt64());
                thisSession.InsertString("currentevent", "OnAfterSelect@" + treeview.Name);
                thisSession.InsertString("currentsubobj", treeview.Name);
                Control ctrl = sender as Control;
                if (ctrl != null && ctrl.Tag != null)
                {
                    string strTag = ctrl.Tag.ToString();
                    XmlDocument xml = new XmlDocument();
                    xml.LoadXml(strTag);
                    foreach (XmlAttribute attribute in xml.ChildNodes[0].Attributes)
                    {
                        thisSession.InsertString(attribute.Name, attribute.Value);
                    }
                }
                thisSession.SendMessage();
                //string strWebcontent = thisSession.GetString("webcontent");
                //if(string.IsNullOrEmpty(strWebcontent) ==false)
                //{
                //    thisSession.InsertString("msgID", "SHOW_APPCONTENT");
                //    thisSession.InsertString("content_show", strWebcontent);
                //    thisSession.InsertString("content_parent", "contents");
                //    thisSession.SendMessage();
                //}
            }
        }

        private static void Thisbtn_Click(object sender, EventArgs e)
        {
            if (WebRT.Wormholes.TryGetValue(sender, out Wormhole thisSession))
            {
                Control ctrl = sender as Control;
                thisSession.InsertString("msgID", "FIRE_EVENT");
                thisSession.InsertString("currentsubobj", ctrl.Name);
                thisSession.InsertString("currentevent", "OnClick@" + ctrl.Name);
                if (ctrl != null && ctrl.Tag != null)
                {
                    string strTag = ctrl.Tag.ToString();
                    XmlDocument xml = new XmlDocument();
                    xml.LoadXml(strTag);
                    foreach (XmlAttribute attribute in xml.ChildNodes[0].Attributes)
                    {
                        thisSession.InsertString(attribute.Name, attribute.Value);
                    }
                    //thisSession.InsertString("OnClickXml", strTag);
                    //thisSession.InsertString("OnClickTagName", xml.FirstChild.Name);
                }
                thisSession.SendMessage();
            }
        }

        private static void ThisForm_SizeChanged(object sender, EventArgs e)
        {
            if (WebRT.Wormholes.TryGetValue(sender, out Wormhole thisSession))
            {
                Form xform = sender as Form;
                thisSession.InsertString("msgID", "FIRE_EVENT");
                thisSession.InsertString("currentevent", "SizeChanged");
                thisSession.InsertString("currentsubobj", "SizeChanged");
                thisSession.InsertLong("width", xform.Width);
                thisSession.InsertLong("height", xform.Height);
                thisSession.SendMessage();
            }
        }
    }
}
