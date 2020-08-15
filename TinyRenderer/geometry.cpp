#include <stdio.h>
#include <vector>

#include "buffer.h"
#include "geometry.h"

void line(Vec2f v0, Vec2f v1, Buffer &buffer, Color color)
{
    int x0 = v0.x;
    int x1 = v1.x;
    int y0 = v0.y;
    int y1 = v1.y;
    bool steep = false;
    //Transpose the line when working with "steep" lines to make then shallow
    //then flip the x,y in the buffer set if steep=true
    //otherwise gaps in the lines appear if the angle is too steep
    if (std::abs(x0 - x1) < std::abs(y0 - y1))
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    //Swap points to always draw from left to right
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1 - x0;
    int dy = y1 - y0;
    int derror = std::abs(dy) * 2;
    int error = 0;
    int y = y0;
    for (float x = x0; x <= x1; x++)
    {
        //if steep we need to de-transpose
        if (steep)
        {
            buffer.set(y, x, color);
        }
        else
        {
            buffer.set(x, y, color);
        }
        error += derror;
        if (error > dx)
        {
            y += (y1 > y0 ? 1 : -1);
            error -= dx * 2;
        }
    }
}


Vec3f barycentric(Vec3f A, Vec3f B, Vec3f C, Vec3f P) 
{
    Vec3f s[2];
    for (int i = 2; i--; ) 
    {
        s[i].x = C.raw[i] - A.raw[i];
        s[i].y = B.raw[i] - A.raw[i];
        s[i].z = A.raw[i] - P.raw[i];
    }
    Vec3f u = s[0] ^ s[1];
    if (std::abs(u.raw[2]) > 1e-2) // dont forget that u[2] is integer. If it is zero then triangle ABC is degenerate
        return Vec3f(1.f - (u.x + u.y) / u.z, u.y / u.z, u.x / u.z);
    return Vec3f(-1, 1, 1); // in this case generate negative coordinates, it will be thrown away by the rasterizator
};

void triangle(Vec3f *pts, float *zbuffer, Buffer &buffer, Color color)
{
    int width = buffer.get_width();
    int height = buffer.get_height();
    Vec2f bboxmin(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
    Vec2f bboxmax(-std::numeric_limits<float>::max(), -std::numeric_limits<float>::max());
    Vec2f clamp(width - 1,height - 1);
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            bboxmin.raw[j] = std::fmax(0.f, std::fmin(bboxmin.raw[j], pts[i].raw[j]));
            bboxmax.raw[j] = std::fmin(clamp.raw[j], std::fmax(bboxmax.raw[j], pts[i].raw[j]));
        }
    }
    Vec3f P;
    for (P.x = bboxmin.x; P.x <= bboxmax.x; P.x++) 
    {
        for (P.y = bboxmin.y; P.y <= bboxmax.y; P.y++) 
        {
            Vec3f bc_screen = barycentric(pts[0], pts[1], pts[2], P);
            if (bc_screen.x < 0 || bc_screen.y < 0 || bc_screen.z < 0) continue;
            P.z = 0;
            for (int i = 0; i < 3; i++) P.z += pts[i].z * bc_screen.raw[i];
            if (zbuffer[int(P.x + P.y * width)] < P.z) 
            {
                zbuffer[int(P.x + P.y * width)] = P.z;
                buffer.set(P.x, P.y, color);
            }
        }
    }
}