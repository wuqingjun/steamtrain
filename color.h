#ifndef __COLOR_H__
#define __COLOR_H__
struct Color
{
    Color(float r1, float g1, float b1, float d) : r(r1), g(g1), b(b1), dim(d){}
    Color() : r(0), g(0), b(0), dim(0){}
    float r;
    float g;
    float b;
    float dim;
};
#endif //__COLOR_H__
