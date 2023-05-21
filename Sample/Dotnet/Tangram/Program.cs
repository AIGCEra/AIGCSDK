using System;
using System.Windows.Forms;

namespace Tangram
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            AIGC.AIGCApp.Run(new Form1());
        }
    }
}
