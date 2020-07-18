#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "geometry.h"

Vec2i world_space_to_screen_space(Vec3f world_coord, int width, int height)
{
    return Vec2i((world_coord.x + 1.) * width / 2, (world_coord.y + 1.) * height / 2);
}

#endif