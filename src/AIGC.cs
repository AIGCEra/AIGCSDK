using System;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace AIGC
{
    static public class AIGCApp
    {
        [DllImport("kernel32.dll")]
        public static extern IntPtr LoadLibrary(string dllToLoad);

        [DllImport("kernel32.dll")]
        public static extern IntPtr GetProcAddress(IntPtr hModule, string procedureName);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void InitWebRT(IntPtr IUnkPtr);

        public static void Run(object StartObj)
        {
            IntPtr pDll = LoadLibrary(@"universe.DLL");
            if (pDll != IntPtr.Zero)
            {
                IntPtr pAddressOfFunctionToCall = GetProcAddress(pDll, "InitWebRT");
                if (pAddressOfFunctionToCall != IntPtr.Zero)
                {
                    InitWebRT InitWebRT = (InitWebRT)Marshal.GetDelegateForFunctionPointer(pAddressOfFunctionToCall, typeof(InitWebRT));
                    InitWebRT(Marshal.GetIUnknownForObject(StartObj));
                }
            }
            else
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
