#include "Test.hpp"
namespace picppgl{
ObTest::ObTest(Level* lvl):levelObject(lvl), img("game_name/gfx/test.png",10, 10), x(50), y(50){

}
void ObTest::draw(Image &target){
    target.apply(img, x, y);
}
void ObTest::update(int ticks){
    if(x>100)
        x=0;
    if(y>100)
        y=0;
    x+=sp/1000*ticks;
    y+=sp/1000*ticks;
}

ObTest::~ObTest(){}
}