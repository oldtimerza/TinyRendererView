using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TinyRendererView
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport("TinyRenderer.dll")]
        static extern int init(int width, int height, int channels);

        [DllImport("TinyRenderer.dll", CharSet = CharSet.Ansi)]
        static extern int load_model(String file_name);

        [StructLayout(LayoutKind.Sequential)]
        public class RGBBuffer
        {
            public IntPtr data;
            public int width;
            public int height;
            public int channels;
            public byte[] GetData()
            {
                int dataSize = width * height * channels;
                var bytes = new byte[dataSize];
                Marshal.Copy(data, bytes, 0, dataSize);
                return bytes;
            }
        }

        [DllImport("TinyRenderer.dll")]
        static extern RGBBuffer render();

        [DllImport("TinyRenderer.dll")]
        static extern void rotate_about_y(float degrees);

        [DllImport("TinyRenderer.dll")]
        static extern void clear();

        public MainWindow()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Creates a bitmap based on data, width, height, stride and pixel format.
        /// </summary>
        /// <param name="sourceData">Byte array of raw source data</param>
        /// <param name="width">Width of the image</param>
        /// <param name="height">Height of the image</param>
        /// <param name="stride">Scanline length inside the data</param>
        /// <param name="pixelFormat">Pixel format</param>
        /// <param name="palette">Color palette</param>
        /// <param name="defaultColor">Default color to fill in on the palette if the given colors don't fully fill it.</param>
        /// <returns>The new image</returns>
        public static BitmapImage BuildImage(Byte[] sourceData, Int32 width, Int32 height, Int32 stride, PixelFormat pixelFormat)
        {
            Bitmap newImage = new Bitmap(width, height, pixelFormat);
            BitmapData targetData = newImage.LockBits(new System.Drawing.Rectangle(0, 0, width, height), ImageLockMode.WriteOnly, newImage.PixelFormat);
            Int32 newDataWidth = ((System.Drawing.Image.GetPixelFormatSize(pixelFormat) * width) + 7) / 8;
            // Compensate for possible negative stride on BMP format.
            Boolean isFlipped = stride < 0;
            stride = Math.Abs(stride);
            // Cache these to avoid unnecessary getter calls.
            Int32 targetStride = targetData.Stride;
            Int64 scan0 = targetData.Scan0.ToInt64();
            for (Int32 y = 0; y < height; y++)
                Marshal.Copy(sourceData, y * stride, new IntPtr(scan0 + y * targetStride), newDataWidth);
            newImage.UnlockBits(targetData);
            // Fix negative stride on BMP format.
            if (isFlipped)
                newImage.RotateFlip(RotateFlipType.Rotate180FlipX);
            BitmapImage bitmapimage = new BitmapImage();
            using (MemoryStream memory = new MemoryStream())
            {
                newImage.Save(memory, ImageFormat.Bmp);
                memory.Position = 0;
                bitmapimage.BeginInit();
                bitmapimage.StreamSource = memory;
                bitmapimage.CacheOption = BitmapCacheOption.OnLoad;
                bitmapimage.EndInit();

            }
            return bitmapimage;
        }

        private void SetText(string text)
        {
            label_filePath.Content = text;
        }

        private void button_Load_Click(object sender, RoutedEventArgs e)
        {
            string filePath = "";
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            { 
                try
                {
                    filePath = openFileDialog.FileName;
                    label_filePath.Content = openFileDialog.FileName;
                }
                catch (SecurityException ex)
                {
                    MessageBox.Show($"Security error.\n\nError message: {ex.Message}\n\n" +
                    $"Details:\n\n{ex.StackTrace}");
                }
            }

            int success = init(800, 800, 3);
            if (success > 0)
            {
                success = load_model(filePath);
                if (success > 0)
                {
                    Draw();
                }
            }
        }

        private void Draw()
        {
            RGBBuffer buffer = render();
            byte[] pixels = buffer.GetData();
            Chart.Source = BuildImage(pixels, 800, 800, 2400, PixelFormat.Format24bppRgb);//This could do with an optimisation                 
        }

        private void button_rotateY_Click(object sender, RoutedEventArgs e)
        {
            clear();
            rotate_about_y(30.0f);
            Draw();
        }
    }
}
