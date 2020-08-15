#ifndef __LIB_H__
#define __LIB_H__
#define EXPORT __declspec(dllexport)

#include "buffer.h"
#include "geometry.h"

extern "C"
{
    EXPORT int init(int width, int height, int channels, Buffer *managed_buffer);
    EXPORT int load_model(const char *file_name);
    EXPORT int load_texture(const char* file_name);
    EXPORT void rotate(Vec3f rotation_vector);
    EXPORT void clear();
    EXPORT int render();
}

#endif //_LIB_H__