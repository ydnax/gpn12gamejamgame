#ifndef objects_moneyinfo_hpp
#define objects_moneyinfo_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
#include <functional>
#include <sstream>
namespace picppgl{
class MoneyInfo:public levelObject, gfxobject{
public:
    typedef std::function<int()> t_ifun;
private:
    int x,y;
    t_ifun fun;
public:
    MoneyInfo(int x, int y, t_ifun fun, Level*lvl):levelObject(lvl),x(x),y(y),fun(fun){
        mwindow->addLay(this, mainwindow::layer::overlay);
    }
    virtual void draw(Image &target){
        std::stringstream out;
        out<<"Money: "<<fun();
        Image img(out.str(), 12);
        target.apply(img,x,y);
    }
    virtual void update(int){}
    virtual ~MoneyInfo(){
        mwindow->remLay(this, mainwindow::layer::overlay);
    }
};

}
#endif