using System;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Windows;

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

        public static void Run(System.Windows.Application app)
        {
            IntPtr pDll = LoadLibrary(@"universe.DLL");
            if (pDll != IntPtr.Zero)
            {
                IntPtr pAddressOfFunctionToCall = GetProcAddress(pDll, "InitWebRT");
                if (pAddressOfFunctionToCall != IntPtr.Zero)
                {
                    InitWebRT InitWebRT = (InitWebRT)Marshal.GetDelegateForFunctionPointer(pAddressOfFunctionToCall, typeof(InitWebRT));
                    InitWebRT(Marshal.GetIUnknownForObject(app));
                }
            }
            else
            {
                if (app != null)
                {
                    app.Run();
                }
            }
        }
    }
}
