#include "gamecore.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <pic-gl/Gameflow/Level.hpp>
#include <game_name/Objects/Test.hpp>
namespace picppgl{
gamecore::gamecore(){
    window=new mainwindow(800, 500);
}
void gamecore::gameloop(){
    timer.start();
    auto lvl=Level{};
    auto f=ObTest(&lvl);
    while(true){
        window->render();
        lvl.update(timer.get_dticks());
    }
}

}