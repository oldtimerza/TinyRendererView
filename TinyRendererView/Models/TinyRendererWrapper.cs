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

        [DllImport("TinyRenderer.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int load_texture(String file_name);

        [DllImport("TinyRenderer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int render();

        [DllImport("TinyRenderer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void rotate(Vector3 rotation_vector);

        [DllImport("TinyRenderer.dll")]
        public static extern void clear();
    }
}
