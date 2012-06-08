#include "Unit.hpp"
#include <pic-gl/Ui/main_window.hpp>
namespace picppgl{
Unit::Unit(Level* lvl):levelObject(lvl), img("game_name/gfx/robo1.png",15, 30), x(50), y(50){
    mwindow->addLay(this, mainwindow::layer::bullets);
}
void Unit::draw(Image &target){
    target.apply(img, x, y);
}
void Unit::update(int ticks){
    if(x>500)
        x=100;
    if(y>500)
        y=100;
    x+=spx/1000*ticks;
    y+=spy/1000*ticks;
}

Unit::~Unit(){}
}