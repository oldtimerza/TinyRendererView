#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "geometry.h"
#include "matrix.h"

Vec2i world_space_to_screen_space(Vec3f world_coord, int width, int height)
{
    return Vec2i((world_coord.x + 1.) * width / 2, (world_coord.y + 1.) * height / 2);
};

Vec3f transform_rotate_y(float degrees, Vec3f v)
{
    float c = cos(degrees);
    float s = sin(degrees);

    Matrix3f m = Matrix3f(c, 0.0f, s,
             0.0f, 1.0f, 0.0f,
             -s, 0.0f, c);

    return m * v;
};

#endif