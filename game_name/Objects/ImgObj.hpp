#ifndef objects_imgobj_hpp
#define objects_imgobj_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
#include <pic-gl/Ui/main_window.hpp>
#include <game_name/GameLogic/Players.hpp>
namespace picppgl{
class ImgObj:public levelObject, gfxobject{
    Image img;
    int x,y;
public:
    ImgObj(int x, int y, Image obj, Level*lvl):levelObject(lvl),img(obj),x(x),y(y){
        mwindow->addLay(this, mainwindow::layer::helptext);
    }
    virtual void draw(Image &target){
        target.apply(img,x,y);
    }
    virtual void update(int){}
    virtual ~ImgObj(){
        mwindow->remLay(this, mainwindow::layer::helptext);
    }
};

}
#endif