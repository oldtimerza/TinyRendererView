﻿using Microsoft.Win32;
using System;
using System.Drawing.Imaging;
using System.Security;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
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
        private const double DRAG_THRESHOLD = 0.2;
        private const double MAX_DRAG_DISTANCE = 400.0;
        private RGBBuffer buffer = new RGBBuffer();
        private double mouseX = 0;
        private double mouseY = 0;
        private bool modelLoaded = false;
        private bool loadedSuccessfully = false;
        private bool paused = true;

        public MainWindow()
        {
            InitializeComponent();
            tickTimer.Tick += Render_Tick;
            tickTimer.Interval = TimeSpan.FromMilliseconds(SIXTY_FPS_MS);
            Paused.IsChecked = paused;
            stepButton.IsEnabled = paused;
            LoadTexture.IsEnabled = false;
        }

        private void Render_Tick(object sender, EventArgs e)
        {
            if (!loadedSuccessfully)
            {
                return;
            }

            if(paused)
            {
                return;
            }

            if (Mouse.LeftButton == MouseButtonState.Pressed)
            {
                double currentMouseX = Mouse.GetPosition(this).X;
                double differenceX = Math.Abs(currentMouseX - mouseX);
                bool right = currentMouseX > mouseX;
                float direction = right ? 1 : -1;
                if (differenceX  > DRAG_THRESHOLD && differenceX < MAX_DRAG_DISTANCE)
                {
                    float amount = direction * (float)differenceX / 100.0f;
                    TinyRendererWrapper.rotate(new Vector3(0.0f, amount, 0.0f));
                }

                double currentMouseY = Mouse.GetPosition(this).Y;
                double differenceY = Math.Abs(currentMouseY - mouseY);
                bool up = currentMouseY > mouseY;
                direction = up ? 1 : -1;
                if (differenceY > DRAG_THRESHOLD && differenceY < MAX_DRAG_DISTANCE)
                {
                    float amount = direction * (float)differenceY / 100.0f;
                    TinyRendererWrapper.rotate(new Vector3(amount, 0.0f, 0.0f));
                }
            }

            mouseX = Mouse.GetPosition(this).X;
            mouseY = Mouse.GetPosition(this).Y;

            Draw();
        }

        private void Draw()
        {
            TinyRendererWrapper.clear();
            TinyRendererWrapper.render();
            byte[] pixels = buffer.GetData();
            Chart.Source = ImageFactory.GetBitmap(pixels, 800, 800, 2400, PixelFormat.Format24bppRgb);
        }

        private void button_Load_Model_Click(object sender, RoutedEventArgs e)
        {
            string filePath = getFileNameFromDialog();

            int success = TinyRendererWrapper.init(800, 800, 3, buffer);
            if (success > 0)
            {
                success = TinyRendererWrapper.load_model(filePath);
                if (success > 0)
                {
                    ModelFilePath.Content = filePath;
                    modelLoaded = true;
                    LoadTexture.IsEnabled = true;
                }
            }
        }

        private void button_Load_Texture_Click(object sender, RoutedEventArgs e)
        {
            if (!modelLoaded) { return; }

            string filePath = getFileNameFromDialog();

            int success = TinyRendererWrapper.load_texture(filePath);
            if(success > 0)
            {
                TextureFilePath.Content = filePath;
                loadedSuccessfully = true;
                tickTimer.IsEnabled = true;
                Draw();
            }
        }

        private void stepButton_Click(object sender, RoutedEventArgs e)
        {
            if (paused)
            {
                Draw();
            }
        }

        private void pausedCheckbox_Checked(object sender, RoutedEventArgs e)
        {
            paused = true;
            stepButton.IsEnabled = true;
        }
        
        private void pausedCheckbox_Unchecked(object sender, RoutedEventArgs e)
        {
            paused = false;
            stepButton.IsEnabled = false;
        }

        private string getFileNameFromDialog()
        {
            string filePath = "";
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == true)
            { 
                try
                {
                    filePath = openFileDialog.FileName;
                }
                catch (SecurityException ex)
                {
                    MessageBox.Show($"Security error.\n\nError message: {ex.Message}\n\n" +
                    $"Details:\n\n{ex.StackTrace}");
                }
            }
            return filePath;
        }
    }
}
