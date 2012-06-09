#include "Node.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <iostream>
namespace picppgl{
Node::Node(int x, int y, Level*lvl): levelObject(lvl),
                                    img("game_name/gfx/town1.png",75, 60),
                                    x(x),y(y){
    mwindow->addLay(this, mainwindow::layer::towns);
}

void Node::draw(Image &target){
    target.apply(img, x-(img.w()/2), y-(img.h()/2));
}

void Node::clicked(){
    std::cout<<"recvd click "<<x<<" "<<y<<std::endl;
}

objinfo Node::getBox(){
    return {{x-img.w()/2,y-img.h()/2}, img.w(), img.h()};
}

void Node::update(int){}
Node::~Node(){
    mwindow->remLay(this, mainwindow::layer::towns);
}


}