#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>
#include "geometry.h"
#include "face.h"

class Model
{
private:
    std::vector<Vec3f> verts_;
    std::vector<Face *> faces_;

public:
    Model(const char *filename);
    ~Model();
    int nverts(); // number of vertices
    int nfaces(); // number of faces
    Vec3f vert(int i);
    Face *face(int idx);
};

#endif //__MODEL_H__