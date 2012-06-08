#include "Level.hpp"
namespace picppgl{
Level::Level(){}

void Level::update(int ticks){
    for(auto &&obj: objects.data()){
        obj->update(ticks);
    }
    objects.realDelete();
}
void Level::addObj(levelObject *o){
    objects.add(o);
}
void Level::delObj(levelObject *o){
    objects.element_delete(o);
}
Level::~Level(){
    objects.realDelete();
    for(auto &&obj: objects.data()){
        delete obj;
    }
}

}