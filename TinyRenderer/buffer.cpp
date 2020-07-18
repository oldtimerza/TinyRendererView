#include <stdio.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "buffer.h"
#include "color.h"

Buffer::Buffer() : data(NULL), width(0), height(0), channels(0){};

Buffer::Buffer(int _width, int _height, int _channels) : data(NULL), width(_width), height(_height), channels(_channels)
{
    unsigned long nbytes = width * height * channels;
    data = new unsigned char[nbytes];
    memset(data, 0, nbytes);
}

Buffer::Buffer(unsigned char *_data) : data(_data){};

Buffer::~Buffer()
{
    delete[] data;
};

unsigned char *Buffer::get()
{
    return data;
};

Color Buffer::get(int x, int y)
{
    if (!data || x < 0 || y < 0 || x >= width || y >= height)
    {
        return Color();
    }
    return Color(data + (x + y * width) * channels, channels);
};

bool Buffer::set(int x, int y, Color c)
{
    if (!data || x < 0 || y < 0 || x >= width || y >= height)
    {
        return false;
    }
    memcpy(data + (x + y * width) * channels, c.raw, channels);
    return true;
};

bool Buffer::flip_vertically()
{
    if (!data)
        return false;
    unsigned long bytes_per_line = width * channels;
    unsigned char *line = new unsigned char[bytes_per_line];
    int half = height >> 1;
    for (int j = 0; j < half; j++)
    {
        unsigned long l1 = j * bytes_per_line;
        unsigned long l2 = (height - 1 - j) * bytes_per_line;
        memmove((void *)line, (void *)(data + l1), bytes_per_line);
        memmove((void *)(data + l1), (void *)(data + l2), bytes_per_line);
        memmove((void *)(data + l2), (void *)line, bytes_per_line);
    }
    delete[] line;
    return true;
};

bool Buffer::flip_horizontally()
{
    if (!data)
        return false;
    int half = width >> 1;
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Color c1 = get(i, j);
            Color c2 = get(width - 1 - i, j);
            set(i, j, c2);
            set(width - 1 - i, j, c1);
        }
    }
    return true;
};

void Buffer::clear()
{
    memset((void *)data, 0, width * height * channels);
};

bool Buffer::scale(int w, int h)
{
    if (w <= 0 || h <= 0 || !data)
        return false;
    unsigned char *tdata = new unsigned char[w * h * channels];
    int nscanline = 0;
    int oscanline = 0;
    int erry = 0;
    unsigned long nlinebytes = w * channels;
    unsigned long olinebytes = width * channels;
    for (int j = 0; j < height; j++)
    {
        int errx = width - w;
        int nx = -channels;
        int ox = -channels;
        for (int i = 0; i < width; i++)
        {
            ox += channels;
            errx += w;
            while (errx >= (int)width)
            {
                errx -= width;
                nx += channels;
                memcpy(tdata + nscanline + nx, data + oscanline + ox, channels);
            }
        }
        erry += h;
        oscanline += olinebytes;
        while (erry >= (int)height)
        {
            if (erry >= (int)height << 1) // it means we jump over a scanline
                memcpy(tdata + nscanline + nlinebytes, tdata + nscanline, nlinebytes);
            erry -= height;
            nscanline += nlinebytes;
        }
    }
    delete[] data;
    data = tdata;
    width = w;
    height = h;
    return true;
}

int Buffer::get_width()
{
    return width;
};

int Buffer::get_height()
{
    return height;
};

int Buffer::get_channels()
{
    return channels;
};