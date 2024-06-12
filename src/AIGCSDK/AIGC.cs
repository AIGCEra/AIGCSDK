using System;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
namespace AIGC
{
    static public class AIGCApp
    {
        static IntPtr initDll = IntPtr.Zero;
        [DllImport("kernel32.dll")]
        public static extern IntPtr LoadLibrary(string dllToLoad);

        [DllImport("kernel32.dll")]
        public static extern IntPtr GetProcAddress(IntPtr hModule, string procedureName);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        delegate void InitWebRT(IntPtr IUnkPtr, IntPtr IUnkWndPtr);
        private static string BuildConfigDataFile(string strExeName, string strProductName, string strCompanyPathName)
        {
            string _strProductName = strProductName.ToLower();
            string _strCompanyPathName = strCompanyPathName.ToLower();
            StringBuilder sb = new StringBuilder();
            sb.Append(Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData)).Append("\\TangramData\\").Append(strExeName).Append("\\");
            string _strConfigDataFile = sb.ToString().ToLower();
            if (Directory.Exists(_strConfigDataFile) == false)
                Directory.CreateDirectory(_strConfigDataFile);
            using (var md5 = MD5.Create())
            {
                StringBuilder sb2 = new StringBuilder();
                _ = sb2.Append(_strConfigDataFile).Append("@").Append(_strCompanyPathName).Append("@").Append(_strProductName);
                var result = md5.ComputeHash(Encoding.UTF8.GetBytes(sb2.ToString()));
                _strConfigDataFile += BitConverter.ToString(result).Replace("-", "");
            }
            _strConfigDataFile += "\\";
            if (Directory.Exists(_strConfigDataFile) == false)
                Directory.CreateDirectory(_strConfigDataFile);
            _strConfigDataFile += strExeName;
            _strConfigDataFile += ".tangram";
            return _strConfigDataFile;
        }

        public static bool InitCosmos(object StartObj, object MainWndObj = null)
        {
            initDll = LoadLibrary(@"universe.DLL");
            if (initDll == IntPtr.Zero)
            {
                String strCfgFile = BuildConfigDataFile("aigcbrowser", "aigcbrowser", "Tangram Team");
                if (File.Exists(strCfgFile) == false)
                    strCfgFile = BuildConfigDataFile("aigcbrowser", "aigcbrowser.109", "Tangram Team");
                if (File.Exists(strCfgFile))
                {
                    string strData = File.ReadAllText(strCfgFile);
                    String strTemp = strData.Substring(strData.IndexOf("Universe") + 8);
                    if (String.IsNullOrEmpty(strTemp) == false)
                    {
                        strTemp = strTemp.Substring(0, strTemp.IndexOf(".dll") + 4);
                        initDll = LoadLibrary(strTemp.Substring(strTemp.IndexOf(":") - 1));
                    }
                }
            }
            if (initDll == IntPtr.Zero)
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles)).Append("\\Tangram\\AIGCBrowser\\universe.dll");
                string strLib = sb.ToString();
                if (File.Exists(strLib))
                {
                    initDll = LoadLibrary(strLib);
                }
            }
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
