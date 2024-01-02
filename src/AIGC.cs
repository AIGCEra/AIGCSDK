using System;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Policy;

namespace AIGC
{
    static public class AIGCApp
    {
        [DllImport("kernel32.dll")]
        public static extern IntPtr LoadLibrary(string dllToLoad);

        [DllImport("kernel32.dll")]
        public static extern IntPtr GetProcAddress(IntPtr hModule, string procedureName);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void InitWebRT(IntPtr IUnkPtr, IntPtr IUnkWndPtr);

        public static bool InitCosmos(object StartObj, object MainWndObj = null)
        {
            IntPtr initDll = LoadLibrary(@"universe.DLL");
            if (initDll != IntPtr.Zero)
            {
                IntPtr fnInitWebRT = GetProcAddress(initDll, "InitWebRT");
                if (fnInitWebRT != IntPtr.Zero)
                {
                    InitWebRT InitWebRT = (InitWebRT)Marshal.GetDelegateForFunctionPointer(fnInitWebRT, typeof(InitWebRT));
                    InitWebRT((StartObj != null) ? Marshal.GetIUnknownForObject(StartObj) : IntPtr.Zero, (MainWndObj != null) ? Marshal.GetIUnknownForObject(MainWndObj) : IntPtr.Zero);
                    return true;
                }
            }
            return false;
        }
    }
}
