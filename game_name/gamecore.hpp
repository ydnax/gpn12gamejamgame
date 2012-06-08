#ifndef gamejam_gamecore_hpp
#define gamejam_gamecore_hpp
#include <pic-gl/Util/gametimer.hpp>
namespace picppgl{
class mainwindow;
class gamecore{
private:
    GameTimer timer;
    mainwindow* window;
public:
    gamecore();
    void gameloop();
};

}
#endif