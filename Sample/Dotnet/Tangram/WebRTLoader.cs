using System;
using System.Reflection;
using System.Windows.Forms;

namespace WebRT
{
    static public class WebRTLoader
    {
        public static void Run(object StartObj)
        {
            try
            {
                Assembly am = Assembly.Load("cosmos");
                Type t = am.GetType("Universe.WebRT");
                t?.GetMethod("Run", BindingFlags.Public | BindingFlags.Static).Invoke(null, new object[] { StartObj });
            }
            catch (Exception)
            {
                if (StartObj != null)
                {
                    Type t = StartObj.GetType();
                    if (t.IsSubclassOf(typeof(Form)))
                        Application.Run(StartObj as Form);
                    else if (t.IsSubclassOf(typeof(ApplicationContext)))
                        Application.Run(StartObj as ApplicationContext);
                    else
                        Application.Run();
                }
                else
                    Application.Run();
            }
        }
    }
}
