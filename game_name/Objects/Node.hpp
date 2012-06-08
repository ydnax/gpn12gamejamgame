#ifndef objects_movtest_hpp
#define objects_test_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
namespace picppgl{
class Node:public levelObject, gfxobject{
private:
    Image img;
    int x,y;

public:
    Node(int x, int y,Level*lvl);
    virtual void draw(Image&);
    virtual void update(int);
    virtual ~Node();
};

}
#endif