#ifndef objects_unit_hpp
#define objects_unit_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
#include <game_name/GameLogic/Players.hpp>
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
    Player owner;
public:
    Unit(Player owner, int startx, int starty, Node* target, Level*);
    Player Owner();
    virtual void draw(Image&);
    virtual void update(int);
    virtual ~Unit();
};

}
#endif