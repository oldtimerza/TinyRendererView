#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "color.h"

class Buffer
{
protected:
    unsigned char *data;
    int width;
    int height;
    int channels;

public:
    Buffer();
    Buffer(unsigned char *_data);
    Buffer(int _width, int _height, int _channels);
    ~Buffer();
    unsigned char *get();
    bool set(int x, int y, Color c);
    Color get(int x, int y);
    bool flip_vertically();
    bool flip_horizontally();
    bool scale(int w, int h);
    void clear();
    int get_width();
    int get_height();
    int get_channels();
};

#endif