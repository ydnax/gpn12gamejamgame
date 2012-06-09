#include "gamecore.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <pic-gl/Gameflow/Level.hpp>
#include <game_name/Objects/Unit.hpp>
#include <game_name/Objects/Node.hpp>
#include <game_name/Objects/ImgObj.hpp>
#include <game_name/Objects/MoneyInfo.hpp>
#include <game_name/GameLogic/UnitCtrl.hpp>
#include <game_name/GameLogic/Players.hpp>
#include <iostream>
#include <SDL/SDL_mixer.h>
namespace picppgl{
gamecore::gamecore(){
    window=new mainwindow(800, 500);

    levels.emplace_back(
        #include <game_name/levels/level1.cpp>
    );
    levels.emplace_back(
        #include <game_name/levels/level2.cpp>
    );
}
    
void gamecore::gameloop(){
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    auto music=Mix_LoadMUS( "game_name/music/jan_rst_chillout_seed.wav" );
    Mix_PlayMusic( music, -1 );

    timer.start();
    for(auto &&lgen:levels){
        auto level=lgen();
        while(!level->hasWon()){
            window->render();
            level->update(timer.get_dticks());
            clickctrl->handleInput();
        }
        delete level;
    }
    std::cout<<"all levels played. game over"<<std::endl;
}

}