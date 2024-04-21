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
        private delegate void InitWebRT(IntPtr IUnkPtr, IntPtr IUnkWndPtr);
        static string BuildConfigDataFile(string strExeName, string strProductName, string strCompanyPathName)
        {
            string _strProductName = strProductName.ToLower();
            string _strCompanyPathName = strCompanyPathName.ToLower();
            StringBuilder sb = new StringBuilder();
            sb.Append(Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData)).Append("\\TangramData\\").Append(strExeName).Append("\\");
            string _strConfigDataFile = sb.ToString().ToLower();
            if (!Directory.Exists(_strConfigDataFile))
                Directory.CreateDirectory(_strConfigDataFile);
            using (var md5 = MD5.Create())
            {
                StringBuilder sb2 = new StringBuilder();
                _ = sb2.Append(_strConfigDataFile).Append("@").Append(_strCompanyPathName).Append("@").Append(_strProductName);
                var result = md5.ComputeHash(Encoding.UTF8.GetBytes(sb2.ToString()));
                _strConfigDataFile += BitConverter.ToString(result).Replace("-", "");
            }
            _strConfigDataFile += "\\";
            if (!Directory.Exists(_strConfigDataFile))
                Directory.CreateDirectory(_strConfigDataFile);
            _strConfigDataFile += strExeName;
            _strConfigDataFile += ".tangram";
            return _strConfigDataFile;
        }

        public static bool InitCosmos(object StartObj, object MainWndObj = null)
        {
            string strCfgDataFile = BuildConfigDataFile("aigcbrowser", "aigcbrowser", "Tangram Team");
            string strData = File.ReadAllText(strCfgDataFile);
            string strUniverseFilePath = "";
            //string strChromeRTFilePath = "";
            int nPos = strData.IndexOf("Universe");
            if (nPos != -1)
            {
                String strTemp = strData.Substring(nPos + 8);
                nPos = strTemp.IndexOf(".dll");
                strTemp = strTemp.Substring(0, nPos + 4);
                nPos = strTemp.IndexOf(":");
                strUniverseFilePath = strTemp.Substring(nPos - 1);
                if (!File.Exists(strUniverseFilePath)) { strUniverseFilePath = ""; }
            }
            //nPos = strData.IndexOf("AIGCAgent");
            //if (nPos != -1)
            //{
            //    String strTemp = strData.Substring(nPos + 9);
            //    nPos = strTemp.IndexOf(".dll");
            //    strTemp = strTemp.Substring(0, nPos + 4);
            //    nPos = strTemp.IndexOf(":");
            //    strChromeRTFilePath = strTemp.Substring(nPos - 1);
            //    if (!File.Exists(strChromeRTFilePath)) { strChromeRTFilePath = ""; }
            //}
            initDll = LoadLibrary(@"universe.DLL");
            if (initDll == IntPtr.Zero && strUniverseFilePath != "")
            {
                initDll = LoadLibrary(strUniverseFilePath);
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
