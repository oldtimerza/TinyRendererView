#ifndef __RENDER_H__
#define __RENDER_H__

#include "face.h"
#include "geometry.h"
#include "model.h"
#include "texture.h"
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
    Texture *texture;
    Buffer *buffer;

protected:
    Render();
    Render(int _width, int _height, int _channels);
    ~Render();
    void draw(Face &face, float *zbuffer);

public:
    Render(Render &other) = delete;
    void operator=(const Render &) = delete;
    static Render *GetInstance();
    static Render *GetInstance(int width, int height, int channels);
    void load_model(const char *file_name);
    void load_texture(const char* file_name);
    void rotate(Vec3f rotation_vector);
    void draw();
    void clear();
    Buffer *get_buffer();
};

#endif