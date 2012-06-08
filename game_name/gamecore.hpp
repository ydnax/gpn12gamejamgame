#ifndef gamejam_gamecore_hpp
#define gamejam_gamecore_hpp
#include <pic-gl/Util/gametimer.hpp>
namespace picppgl{
class gamecore{
private:
    GameTimer t;
public:
    gamecore();
    void gameloop();
};

}
#endif