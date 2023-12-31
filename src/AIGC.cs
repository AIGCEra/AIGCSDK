using System;
using System.Runtime.InteropServices;

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

        public static bool InitCosmos(object StartObj, object MainWndObj)
        {
            IntPtr initDll = LoadLibrary(@"universe.DLL");
            if (initDll != IntPtr.Zero)
            {
                IntPtr fnInitWebRT = GetProcAddress(initDll, "InitWebRT");
                if (fnInitWebRT != IntPtr.Zero)
                {
                    InitWebRT InitWebRT = (InitWebRT)Marshal.GetDelegateForFunctionPointer(fnInitWebRT, typeof(InitWebRT));
                    if (MainWndObj != null)
                        InitWebRT(Marshal.GetIUnknownForObject(StartObj), Marshal.GetIUnknownForObject(MainWndObj));
                    else
                        InitWebRT(Marshal.GetIUnknownForObject(StartObj), IntPtr.Zero);
                    return true;
                }
            }
            return false;
        }
    }
}
