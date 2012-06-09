#ifndef gamejam_gamecore_hpp
#define gamejam_gamecore_hpp
#include <functional>
#include <vector>
#include <pic-gl/Util/gametimer.hpp>
namespace picppgl{
class mainwindow;
class Level;
class gamecore{
private:
    GameTimer timer;
    mainwindow* window;
    typedef std::function<Level*()> LvlFun;
    std::vector<LvlFun> levels;
public:
    gamecore();
    void gameloop();
};

}
#endif