using Microsoft.Win32;
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Runtime.InteropServices;
using System.Security;
using System.Windows;
using System.Windows.Media.Imaging;
using TinyRendererView.Models;
using TinyRendererView.Utilities;

namespace TinyRendererView
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        const double DRAG_THRESHOLD = 1.0;
        RGBBuffer buffer = new RGBBuffer();
        double mouseX = 0;
        int mouseY = 0;

        public MainWindow()
        {
            InitializeComponent();
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

            int success = TinyRendererWrapper.init(800, 800, 3, buffer);
            if (success > 0)
            {
                success = TinyRendererWrapper.load_model(filePath);
                if (success > 0)
                {
                    Draw();
                }
            }
        }

        private void Draw()
        {
            TinyRendererWrapper.render();
            byte[] pixels = buffer.GetData();
            Chart.Source = ImageFactory.GetBitmap(pixels, 800, 800, 2400, PixelFormat.Format24bppRgb);
        }

        private void Chart_MouseMove(object sender, System.Windows.Input.MouseEventArgs e)
        {
            if(e.LeftButton == System.Windows.Input.MouseButtonState.Pressed)
            {
                double currentMouseX = e.GetPosition(this).X;
                double difference = Math.Abs(currentMouseX - mouseX);
                bool right = currentMouseX > mouseX;
                float amount = right ? 0.1f : -0.1f;
                if (difference  > DRAG_THRESHOLD)
                {
                    TinyRendererWrapper.clear();
                    TinyRendererWrapper.rotate_about_y(amount);
                    Draw();
                }
                mouseX = e.GetPosition(this).X;
            }

        }
    }
}
