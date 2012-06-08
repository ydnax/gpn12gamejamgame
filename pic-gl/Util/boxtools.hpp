#ifndef picppgl_Util_boxtools_hpp
#define picppgl_Util_boxtools_hpp
namespace picppgl{
struct point{
    int x;
    int y;
};
struct objinfo{
    point p;
    int h;
    int w;
};
bool boxCollide(const objinfo &A, const objinfo &B);

bool boxInsideBox(const objinfo &area, const objinfo &obj);
bool boxOutsideBox(const objinfo &area, const objinfo &obj);
}
#endif