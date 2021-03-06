#include <stdio.h>
#include <vector>

#include "buffer.h"
#include "geometry.h"
#include "texture.h"

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
    //Checking if the point P lies on a triangle involves checking if the u,v coords on the non-orthoganl basis created 
    //by basis vectors: C-A and B-A from origin A, i.e A + u(C-A) + v(B-A) = P. After some simplification it requires that
    //(1-u-v)A+vB+uC = P => (A-P) + u(C - A) + v(B - A) = 0(the zero vector) which requires both x,y (screen co-ords) are 0. After some solving
    //we require [u v 1][(B-A)x (C-A)x (A-P)x]^T = 0, [u v 1][(B-A)y (C-A)y (A-P)y]^T = 0. In other words to solve for u,v we just need to find 
    //a vector that is a cross product of s0 = [(B-A)x (C-A)x (A-P)x] and s1 = [(B-A)y (C-A)y (A-P)y], since the cross product will be orthoganal to both
    //i.e the dot product of [u v 1] with s0 and s1 will be 0. Once we have this cross product vector then we can return the co-ords for P: [ 1-u-v, v,u].
    Vec3f s[2];
    for (int i = 2; i--; ) 
    {
        s[i].x = C.raw[i] - A.raw[i];
        s[i].y = B.raw[i] - A.raw[i];
        s[i].z = A.raw[i] - P.raw[i];
    }
    Vec3f cross = s[0] ^ s[1];
    if (std::abs(cross.raw[2]) <= 1e-2) // dont forget that cross.z is an integer. If it is zero(or in error range) then triangle ABC is degenerate
		return Vec3f(-1, 1, 1); // in this case generate negative coordinates, it will be thrown away by the rasterizator
    cross = cross * (1.0f / cross.z);// We do this to set  the z value to 1 so we get the form [u v 1]
    float w = 1.f - (cross.x + cross.y);
    float v = cross.y;
    float u = cross.x;
	return Vec3f(w, v, u);
};

void triangle(Vec3f *pts, float *zbuffer, Buffer &buffer, Color color, Texture &texture, Vec2f *texture_coords)
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
            //We interpolate the Z values of the 3 points using the weighted coords from barycentric calc to get the Z value of P on the triangle.
            for (int i = 0; i < 3; i++) P.z += pts[i].z * bc_screen.raw[i];
            if (zbuffer[int(P.x + P.y * width)] < P.z) 
            {
                //Interpolate texture coords
                Vec2f interpolated_texture_coord;
				for (int i = 0; i < 3; i++)
				{
                    interpolated_texture_coord = interpolated_texture_coord +  (texture_coords[i] * bc_screen.raw[i]);
				}
                int texture_u = int(texture.get_width() * interpolated_texture_coord.u);
                int texture_v = int(texture.get_height() * interpolated_texture_coord.v);
                TGAColor tga_color = texture.get(texture_u, texture_v);
                int red = tga_color[2] * (color.r / 255.f);
                int green = tga_color[1] * (color.g / 255.f);
                int blue = tga_color[0] * (color.b / 255.f);
                int alpha = tga_color[3];
                Color final_color = Color(red, blue, green, alpha);
                zbuffer[int(P.x + P.y * width)] = P.z;
                buffer.set(P.x, P.y, final_color);
            }
        }
    }
}