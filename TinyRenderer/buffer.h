#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "color.h"

class Buffer
{
protected:
    int width;
    int height;
    int channels;
    unsigned char *data;

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
    void set_width(int _width);
    int get_height();
    void set_height(int _height);
    int get_channels();
    void set_channels(int _channels);
    unsigned char* get_data();
    void set_data(unsigned char* _data);
};

#endif