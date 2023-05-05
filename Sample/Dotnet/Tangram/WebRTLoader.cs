using System;
using System.Reflection;
using System.Windows.Forms;

namespace WebRT
{
    static public class WebRTLoader
    {
        public static void Run(Object StartObj)
        {
            try
            {
                Assembly am = Assembly.Load("cosmos");
                Type t = am.GetType("Universe.WebRT");
                t?.GetMethod("Run", BindingFlags.Public | BindingFlags.Static).Invoke(null, new object[] { StartObj });
            }
            catch (Exception) { 
                if (StartObj != null)
                {
                    Type t = StartObj.GetType();
                    if (t.IsSubclassOf(typeof(Form)))
                    {
                        Application.Run((Form)StartObj);
                    }
                    else if (t.IsSubclassOf(typeof(ApplicationContext)))
                    {
                        Application.Run((ApplicationContext)StartObj);
                    }
                }
                else
                {
                    Application.Run();
                }
            }
        }
    }
}
