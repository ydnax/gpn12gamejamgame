#include "Unit.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <pic-gl/Util/tools.hpp>
#include <game_name/Objects/Node.hpp>

#include <iostream>
namespace picppgl{
    using namespace std;
Unit::Unit(int startx, int starty, Node* target_, Level* lvl):
        levelObject(lvl),
        img("game_name/gfx/robo1.png",15, 30),
        x(startx), y(starty), target(target_){
    ex=target->getBox().p.x;
    ey=target->getBox().p.y;
    ex=ex+(img.w()/2);
    ey=ey+(img.h()/2);
    mwindow->addLay(this, mainwindow::layer::units);
    const float angle=getAngle({startx, starty}, {ex, ey});
    const float distance = getPointDistance({startx, starty}, {ex, ey});
    
    float lx = cos(float(angle/180)*M_PI)*distance;
    float ly = sin(float(angle/180)*M_PI)*distance*-1;
    float ratiox=lx/distance;
    float ratioy=ly/distance;
    spx=speed*ratiox;
    spy=speed*ratioy;
}
void Unit::draw(Image &target){
    target.apply(img, x+(img.w()/2), y+(img.h()/2));
}
void Unit::update(int ticks){
    x+=spx*ticks/1000;
    y+=spy*ticks/1000;
    if(cmp<float>(x, ex, 1)&&cmp<float>(y, ey,1)){
        target->unitcount(target->unitcount()+1);
        delete this;
    }
}

Unit::~Unit(){
    mwindow->remLay(this, mainwindow::layer::units);
}

}