#ifndef picppgl_Gameflow_Level_hpp
#define picppgl_Gameflow_Level_hpp
#include <string>
#include <vector>
#include <functional>
#include <pic-gl/Util/lazy_delete_vector.hpp>
using std::string;
namespace picppgl{
class Level;

class levelObject;
class Level{
public:
    typedef std::function<bool()> winCondition;
private:
    lazyDeleteVector<levelObject*> objects;
    winCondition winfun;
public:
    Level(winCondition wc):winfun(wc){}
    void update(int);
    void addObj(levelObject*);
    void delObj(levelObject*);
    bool hasWon();
    ~Level();
};
class levelObject{
private:
    Level* lvl;
public:
    levelObject(Level *l):lvl(l){
        lvl->addObj(this);
    }
    virtual void update(int)=0;
    virtual ~levelObject(){
        lvl->delObj(this);
    }
};

}
#endif