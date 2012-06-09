#ifndef objects_node_hpp
#define objects_node_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
#include <game_name/GameLogic/UnitCtrl.hpp>
#include <game_name/GameLogic/Players.hpp>
namespace picppgl{
class Node:public levelObject, gfxobject, clickable{
public:
    enum player{user, ki};
private:
    Image img;
    int x,y;
    Level *l;
    int unitcnt=0;
    Player owner;
protected:
    void real_event(char ev);
public:
    Node(int x, int y, Level*lvl);
    int unitcount()const{return unitcnt;}
    void unitcount(int nval){unitcnt=nval;}
    Player Owner()const{return owner;}
    void Owner(Player nowner){owner=nowner;}
    virtual void draw(Image&);
    virtual void update(int);
    virtual void clicked();
    virtual void event(char);
    virtual objinfo getBox();
    virtual ~Node();
};

}
#endif