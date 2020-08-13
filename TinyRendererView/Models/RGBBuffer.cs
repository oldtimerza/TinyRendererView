using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace TinyRendererView.Models
{
        [StructLayout(LayoutKind.Sequential)]
        public class RGBBuffer
        {
            public int width;
            public int height;
            public int channels;
            public IntPtr data;

            public byte[] GetData()
            {
                int dataSize = width * height * channels;
                var bytes = new byte[dataSize];
                Marshal.Copy(data, bytes, 0, dataSize);
                return bytes;
            }
        }
}
