#include "gamecore.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <pic-gl/Gameflow/Level.hpp>
#include <game_name/Objects/Unit.hpp>
#include <game_name/Objects/Node.hpp>
#include <game_name/GameLogic/UnitCtrl.hpp>
#include <iostream>
namespace picppgl{
gamecore::gamecore(){
    window=new mainwindow(800, 500);
    auto lvl1=[]()->Level*{
        auto lvl=new Level(nullptr);
        auto n1=new Node(50,50,lvl);
        n1->unitcount(4);
        auto n2=new Node(200,100,lvl);
        auto n3=new Node(100,200,lvl);
        lvl->setWinFun([=](){
            return  (n1->unitcount() && n2->unitcount() && n3->unitcount());
        });
        return lvl;
    };
    levels.push_back(lvl1);
}
    
void gamecore::gameloop(){
    timer.start();
    for(auto &&lgen:levels){
        auto level=lgen();
        while(!level->hasWon()){
            window->render();
            level->update(timer.get_dticks());
            clickctrl->handleInput();
        }
    }
    std::cout<<"all levels played. game over"<<std::endl;
}

}