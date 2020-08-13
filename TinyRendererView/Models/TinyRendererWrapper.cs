using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace TinyRendererView.Models
{
    class TinyRendererWrapper
    {
        [DllImport("TinyRenderer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int init(int width, int height, int channels, RGBBuffer buffer);

        [DllImport("TinyRenderer.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int load_model(String file_name);

        [DllImport("TinyRenderer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int render();

        [DllImport("TinyRenderer.dll")]
        public static extern void rotate_about_y(float degrees);

        [DllImport("TinyRenderer.dll")]
        public static extern void clear();
    }
}
