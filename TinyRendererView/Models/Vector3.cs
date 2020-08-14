using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace TinyRendererView.Models
{
    [StructLayout(LayoutKind.Sequential)]
    class Vector3
    {
        public Vector3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        public float x;
        public float y;
        public float z;
    }
}
