#ifndef __LIB_H__
#define __LIB_H__
#define EXPORT __declspec(dllexport)

#include "buffer.h"

extern "C"
{
    EXPORT int init(int width, int height, int channels);
    EXPORT int load_model(const char *file_name);
    EXPORT void rotate_about_y(float degrees);
    EXPORT void clear();
    EXPORT Buffer *render();
}

#endif //_LIB_H__