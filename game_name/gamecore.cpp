#include "gamecore.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <pic-gl/Ui/main_window.hpp>
#include <game_name/LevelLoader/LevelLoader.hpp>
#include <SDL/SDL_mixer.h>
using namespace std;
namespace picppgl{
gamecore::gamecore(){
    window=new mainwindow(800, 500);

}
    
void gamecore::gameloop(){
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    auto music=Mix_LoadMUS( "game_name/music/jan_rst_chillout_seed.wav" );
    Mix_PlayMusic( music, -1 );
    game_name::levelLoader L;
    ifstream t("levels.txt");
    string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
    auto levels = L.parse(str);
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