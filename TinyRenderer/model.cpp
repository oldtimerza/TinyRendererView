#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "model.h"
#include "face.h"

Model::Model(const char *filename) : verts_(), faces_()
{
    std::ifstream in;
    in.open(filename, std::ifstream::in);
    if (in.fail())
        return;
    std::string line;
    while (!in.eof())
    {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v "))
        {
            iss >> trash;
            Vec3f v;
            for (int i = 0; i < 3; i++)
                iss >> v.raw[i];
            verts_.push_back(v);
        }
        else if (!line.compare(0, 3, "vt "))
        {
            iss >> trash;//the v
            iss >> trash;//the t
            Vec2f  vt;
            for (int i = 0; i < 2; i++)
                iss >> vt.raw[i];
            texture_coords_.push_back(vt);
        }
        else if (!line.compare(0, 2, "f "))
        {
            std::vector<int> f;
            std::vector<int> f_texture;
            int itrash, idx, textureidx;
            iss >> trash;
            while (iss >> idx >> trash >> textureidx >> trash >> itrash)// idx/textureidx/itrash 
            {
                idx--; // in wavefront obj all indices start at 1, not zero
                f.push_back(idx);
                textureidx--;
                f_texture.push_back(textureidx);
            }
            Face *face = new Face();
            for (int i = 0; i < 3; i++)
            {
                face->vertices[i] = vert(f[i]);
                face->texture_coords[i] = texture_coord(f_texture[i]);
            };
            faces_.push_back(face);
        }
    }
};

Model::~Model(){};

int Model::nverts()
{
    return (int)verts_.size();
};

int Model::nfaces()
{
    return (int)faces_.size();
};

Face *Model::face(int idx)
{
    return faces_[idx];
};

Vec3f Model::vert(int i)
{
    return verts_[i];
};

Vec2f Model::texture_coord(int i)
{
    return texture_coords_[i];
};