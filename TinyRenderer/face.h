#ifndef __FACE_H__
#define __FACE_H__

#include "geometry.h"

struct Face
{
    Vec3f vertices[3];
    Vec2f texture_coords[3];
};

#endif