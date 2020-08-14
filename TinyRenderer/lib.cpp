#include "lib.h"
#include "render.h"
#include <fstream>

EXPORT int init(int width, int height, int channels, Buffer* managed_buffer)
{
    Render *renderer = Render::GetInstance(width, height, channels);
    managed_buffer->set_width(renderer->get_buffer()->get_width());
    managed_buffer->set_height(renderer->get_buffer()->get_height());
    managed_buffer->set_channels(renderer->get_buffer()->get_channels());
    managed_buffer->set_data(renderer->get_buffer()->get_data());
    return 1;
};

EXPORT int load_model(const char *file_name)
{
    Render::GetInstance()->load_model(file_name);
    return 1;
};


EXPORT void rotate(Vec3f rotation_vector)
{
    Render::GetInstance()->rotate(rotation_vector);
};

EXPORT int render()
{
    Render::GetInstance()->draw();
    Render::GetInstance()->get_buffer()->flip_vertically();
    return 1;
};

EXPORT void clear()
{
    Render::GetInstance()->clear();
}