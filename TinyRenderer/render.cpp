#include <stdio.h>
#include "model.h"
#include "render.h"
#include "geometry.h"
#include "face.h"
#include "color.h"
#include "transform.h"

Render *Render::singleton_ = nullptr;

Render *Render::GetInstance()
{
    if (singleton_ == nullptr)
    {
        singleton_ = new Render(0, 0, 0);
    }
    return singleton_;
}

Render *Render::GetInstance(int width, int height, int channels)
{
    if (singleton_ == nullptr)
    {
        singleton_ = new Render(width, height, channels);
    }
    return singleton_;
};

Render::Render() : width(0), height(0), channels(0), buffer(nullptr){};

Render::Render(int _width, int _height, int _channels) : width(_width), height(_height), channels(_channels)
{
    buffer = new Buffer(width, height, channels);
};

Render::~Render()
{
    delete model;
    delete buffer;
};

void Render::load_model(const char *file_name)
{
    model = new Model(file_name);
}

void Render::draw(Face &face)
{
    Vec2i screen_coords[3];
    for (int j = 0; j < 3; j++)
    {
        screen_coords[j] = world_space_to_screen_space(face.vertices[j], width, height);
    }
    Vec3f normal = (face.vertices[2] - face.vertices[0]) ^ (face.vertices[1] - face.vertices[0]);
    normal.normalize();
    float intensity = (normal * light_dir) * 255;
    if (intensity > 0)
    {
        triangle(screen_coords[0], screen_coords[1], screen_coords[2], *buffer, Color(intensity, intensity, intensity, 255));
    }
};

void Render::draw()
{
    for (int i = 0; i < model->nfaces(); i++)
    {
        Face *face = model->face(i);
        draw(*face);
    };
}

Buffer *Render::get_buffer()
{
    return buffer;
};