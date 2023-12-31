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
        private delegate void InitWebRT(IntPtr IUnkPtr);

        public static bool InitCosmos(object StartObj)
        {
            IntPtr initDll = LoadLibrary(@"universe.DLL");
            if (initDll != IntPtr.Zero)
            {
                IntPtr fnInitWebRT = GetProcAddress(initDll, "InitWebRT");
                if (fnInitWebRT != IntPtr.Zero)
                {
                    InitWebRT InitWebRT = (InitWebRT)Marshal.GetDelegateForFunctionPointer(fnInitWebRT, typeof(InitWebRT));
                    InitWebRT(Marshal.GetIUnknownForObject(StartObj));
                    return true;
                }
            }
            return false;
        }
    }
}
