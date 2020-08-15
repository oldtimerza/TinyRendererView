#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "geometry.h"
#include "matrix.h"

Vec3f world_space_to_screen_space(Vec3f world_coord, int width, int height)
{
    return Vec3f(int((world_coord.x + 1.) * width / 2. + .5), int((world_coord.y + 1.) * height / 2. + .5), world_coord.z);
};


Vec3f transform_rotate_x(float degrees, Vec3f v)
{
    float c = cos(degrees);
    float s = sin(degrees);

    Matrix3f m = Matrix3f(
        1.0f, 0.0f, 0.0f,
        0.0f, c, -s,
        0.0f, s, c
    );

    return m * v;
};

Vec3f transform_rotate_y(float degrees, Vec3f v)
{
    float c = cos(degrees);
    float s = sin(degrees);

    Matrix3f m = Matrix3f(
		c, 0.0f, s,
		0.0f, 1.0f, 0.0f,
		-s, 0.0f, c
    );

    return m * v;
};

Vec3f transform_rotate_z(float degrees, Vec3f v)
{
    float c = cos(degrees);
    float s = sin(degrees);

    Matrix3f m = Matrix3f(
        c, -s, 0.0f,
        s, c, 0.0f,
        0.0f , 0.0f, 1.0f
    );

    return m * v;
};

#endif