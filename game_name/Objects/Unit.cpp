#include "Unit.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <pic-gl/Util/tools.hpp>
#include <game_name/Objects/Node.hpp>

#include <iostream>
namespace picppgl{
    using namespace std;
Unit::Unit(Player owner, Node *start , Node *target_, Level* lvl):
        levelObject(lvl),l(lvl),
        img("game_name/gfx/robo1.png",15, 30),
        target(target_), owner(owner){ 
    int startx=x=start->getBox().p.x;
    int starty=y=start->getBox().p.y;    
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
    int load=start->storage()%max_storage+1;
    start->storage(start->storage()-load);
    storage_=load;
}

Player Unit::Owner(){return owner;}

void Unit::draw(Image &target){
    target.apply(img, x+(img.w()/2), y+(img.h()/2));
}
void Unit::update(int ticks){
    x+=spx*ticks/1000;
    y+=spy*ticks/1000;
    if(cmp<float>(x, ex, 1)&&cmp<float>(y, ey,1)){
        if( target->unitcount()==0){
            target->unitcount(1);
            target->Owner(owner);
        }else if(target->Owner()==owner){
            target->unitcount(target->unitcount()+1);
            l->money(l->money()+storage_);
        }else{
            target->unitcount(target->unitcount()-1);
        }
        
        delete this;
    }
}

Unit::~Unit(){
    mwindow->remLay(this, mainwindow::layer::units);
}

}