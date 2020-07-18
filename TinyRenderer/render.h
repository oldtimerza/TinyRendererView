#ifndef __RENDER_H__
#define __RENDER_H__

#include "face.h"
#include "geometry.h"
#include "model.h"
#include "buffer.h"

class Render
{
    const Vec3f light_dir = Vec3f(0, 0, -1.0f);
    const int delay = 0;
    int width;
    int height;
    int channels;
    static Render *singleton_;
    Model *model;
    Buffer *buffer;

protected:
    Render();
    Render(int _width, int _height, int _channels);
    ~Render();
    void draw(Face &face);

public:
    Render(Render &other) = delete;
    void operator=(const Render &) = delete;
    static Render *GetInstance();
    static Render *GetInstance(int width, int height, int channels);
    void load_model(const char *file_name);
    void draw();
    Buffer *get_buffer();
};

#endif