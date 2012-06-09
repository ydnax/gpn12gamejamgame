#include "Node.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <game_name/Objects/Unit.hpp>
#include <iostream>
#include <string>
#include <sstream>
namespace picppgl{
Node *lastClicked=nullptr;
using namespace std;

Node::Node(int x, int y, Level *lvl): levelObject(lvl),
                                    img("game_name/gfx/town1.png",75, 60),
                                    x(x),y(y),l(lvl){
    mwindow->addLay(this, mainwindow::layer::towns);
}

void Node::draw(Image &target){
    stringstream txt;
    txt<<"units: "<<unitcnt;
    Image::Color fg={255,255,255};
    Image::Color bg={0,0,0};
    if(lastClicked==this){
        swap(fg, bg);
    }
    auto text=Image(txt.str(), 14, fg, bg);
    Image tmp=img;
    tmp.apply(img, 0, 0);
    tmp.apply(text, 0, 0);
    target.apply(tmp, x-(img.w()/2), y-(img.h()/2));
}

void Node::clicked(){
    //std::cout<<"recvd click "<<x<<" "<<y<<std::endl;
    if(lastClicked==nullptr){
        //cout<<"sel: "<<this<<endl;
        lastClicked=this;
    }else if(lastClicked==this){
        ///cout<<"double"<<endl;
        lastClicked=nullptr;
    }else if( (lastClicked->unitcount()>1)&&(lastClicked->Owner()==Player::User) ){
        //cout<<"SEND THE TROOPS"<<endl;
        auto ex=lastClicked->getBox().p.x;
        auto ey=lastClicked->getBox().p.y;
        lastClicked->unitcount(lastClicked->unitcount()-1);
        new Unit{lastClicked->Owner(), ex, ey, this,l};
        //lastClicked=nullptr; 
    }else{
        cout<<"You have no units to move there "<<this<<endl;
    }
}

objinfo Node::getBox(){
    return {{x-img.w()/2,y-img.h()/2}, img.w(), img.h()};
}

void Node::update(int){}
Node::~Node(){
    mwindow->remLay(this, mainwindow::layer::towns);
    if(lastClicked==this)
        lastClicked=nullptr;
}


}