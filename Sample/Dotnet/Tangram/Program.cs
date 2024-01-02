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
            Form startForm = new Form1();
            if (!AIGC.AIGCApp.InitCosmos(startForm))
                Application.Run(startForm);
        }
    }
}
