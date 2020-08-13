using Microsoft.Win32;
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Runtime.InteropServices;
using System.Security;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using TinyRendererView.Models;
using TinyRendererView.Utilities;

namespace TinyRendererView
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        //This needs to be refactored into separate classes
        //For now it is fine
        private DispatcherTimer tickTimer = new DispatcherTimer();
        private const double SIXTY_FPS_MS = 1000 / 60;
        private const double DRAG_THRESHOLD = 0.1;
        private const float ROTATION_AMOUNT = 0.1f;
        private RGBBuffer buffer = new RGBBuffer();
        private double mouseX = 0;
        private int mouseY = 0;
        private bool loadedSuccessfully = false;

        public MainWindow()
        {
            InitializeComponent();
            tickTimer.Tick += Render_Tick;
            tickTimer.Interval = TimeSpan.FromMilliseconds(SIXTY_FPS_MS);
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
                    loadedSuccessfully = true;
                    tickTimer.IsEnabled = true;
                }
            }
        }

        private void Render_Tick(object sender, EventArgs e)
        {
            if (!loadedSuccessfully)
            {
                return;
            }
            if(Mouse.LeftButton == MouseButtonState.Pressed)
            {
                double currentMouseX = Mouse.GetPosition(this).X;
                double difference = Math.Abs(currentMouseX - mouseX);
                bool right = currentMouseX > mouseX;
                float amount = right ? ROTATION_AMOUNT : -1 * ROTATION_AMOUNT;
                if (difference  > DRAG_THRESHOLD)
                {
                    TinyRendererWrapper.rotate_about_y(amount);
                }
                mouseX = Mouse.GetPosition(this).X;
            }
            Draw();
        }

        private void Draw()
        {
            TinyRendererWrapper.clear();
            TinyRendererWrapper.render();
            byte[] pixels = buffer.GetData();
            Chart.Source = ImageFactory.GetBitmap(pixels, 800, 800, 2400, PixelFormat.Format24bppRgb);
        }
    }
}
