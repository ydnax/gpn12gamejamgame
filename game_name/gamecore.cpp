#include "gamecore.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <pic-gl/Gameflow/Level.hpp>
#include <game_name/Objects/Unit.hpp>
#include <game_name/Objects/Node.hpp>
#include <game_name/Objects/ImgObj.hpp>
#include <game_name/GameLogic/UnitCtrl.hpp>
#include <game_name/GameLogic/Players.hpp>
#include <iostream>
namespace picppgl{
gamecore::gamecore(){
    window=new mainwindow(800, 500);

    levels.emplace_back(
        #include <game_name/levels/level1.cpp>
    );
        return lvl;
    });
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