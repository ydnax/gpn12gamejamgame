#ifndef picppgl_Util_boxtools_hpp
#define picppgl_Util_boxtools_hpp
#include <pic-gl/Util/tools.hpp>
namespace picppgl{

/*
struct point{
    int x;
    int y;
};//*/
struct objinfo{
    point p;
    int w;
    int h;
};
bool boxCollide(const objinfo &A, const objinfo &B);

bool boxInsideBox(const objinfo &area, const objinfo &obj);
bool boxOutsideBox(const objinfo &area, const objinfo &obj);
}
#endif