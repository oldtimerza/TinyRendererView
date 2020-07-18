#include "lib.h"
#include "render.h"
#include <fstream>

EXPORT int init(int width, int height, int channels)
{
    Render::GetInstance(width, height, channels);
    return 1;
};

EXPORT int load_model(const char *file_name)
{
    Render::GetInstance()->load_model(file_name);
    return 1;
};

EXPORT Buffer *render()
{
    Render *renderer = Render::GetInstance();
    renderer->draw();
    return renderer->get_buffer();
};