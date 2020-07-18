#include <stdio.h>

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

void triangle(Vec2i t0, Vec2i t1, Vec2i t2, Buffer &buffer, Color color)
{
    if (t0.y == t1.y && t0.y == t2.y)
        return; // I dont care about degenerate triangles
    // sort the vertices, t0, t1, t2 lower−to−upper (bubblesort yay!)
    if (t0.y > t1.y)
        std::swap(t0, t1);
    if (t0.y > t2.y)
        std::swap(t0, t2);
    if (t1.y > t2.y)
        std::swap(t1, t2);
    int total_height = t2.y - t0.y;
    for (int i = 0; i < total_height; i++)
    {
        bool second_half = i > t1.y - t0.y || t1.y == t0.y;
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y;
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height; // be careful: with above conditions no division by zero here
        Vec2i A = t0 + (t2 - t0) * alpha;
        Vec2i B = second_half ? t1 + (t2 - t1) * beta : t0 + (t1 - t0) * beta;
        if (A.x > B.x)
            std::swap(A, B);
        for (int j = A.x; j <= B.x; j++)
        {
            buffer.set(j, t0.y + i, color); // attention, due to int casts t0.y+i != A.y
        }
    }
}