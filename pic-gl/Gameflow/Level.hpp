#ifndef picppgl_Gameflow_Level_hpp
#define picppgl_Gameflow_Level_hpp
#include <string>
#include <vector>
#include <pic-gl/Util/lazy_delete_vector.hpp>
using std::string;
namespace picppgl{
class Level;

class levelObject;
class Level{
private:
    lazyDeleteVector<levelObject*> objects;
public:
    Level();
    void update(int);
    void addObj(levelObject*);
    void delObj(levelObject*);
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