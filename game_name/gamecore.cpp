#include "gamecore.hpp"
#include <pic-gl/Ui/main_window.hpp>
#include <pic-gl/Gameflow/Level.hpp>
#include <game_name/Objects/Unit.hpp>
#include <game_name/Objects/Node.hpp>
#include <game_name/GameLogic/UnitCtrl.hpp>
namespace picppgl{
gamecore::gamecore(){
    window=new mainwindow(800, 500);
}
void gamecore::gameloop(){
    timer.start();
    auto lvl=new Level{};
    new Unit(1, 1, 100, 100, lvl);
    new Unit(100, 100, 1, 1, lvl);
    new Unit(100, 100, 300, 10, lvl);
    new Unit(300, 10, 100, 100, lvl);
    new Node(50,50,lvl);
    new Node(200,100,lvl);
    new Node(100,200,lvl);

    while(true){
        window->render();
        lvl->update(timer.get_dticks());
        clickctrl->handleInput();
    }
}

}