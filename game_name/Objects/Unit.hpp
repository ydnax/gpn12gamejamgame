#ifndef objects_unit_hpp
#define objects_unit_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
namespace picppgl{
class Node;
class Unit:public levelObject, gfxobject{
private:
    Image img;
    float x;
    float y;
    int ex, ey;
    int speed=50;
    float spx;
    float spy;
    Node *target;
public:
    Unit(int startx, int starty, Node* target, Level*);
    virtual void draw(Image&);
    virtual void update(int);
    virtual ~Unit();
};

}
#endif