#include "main_window.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <pic-gl/Resources/Image.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
#include <pic-gl/Util/tools.hpp>
namespace picppgl{

mainwindow::mainwindow(int w, int h, int bbp):
        vsurface_(reinterpret_cast<ImageData*>(SDL_SetVideoMode(w, h, bbp, SDL_SWSURFACE ))),
        background( w, h, 0, 255, 255, reinterpret_cast<ImageData*>(SDL_SetVideoMode(w, h, bbp, SDL_SWSURFACE )) ),
        layers(layer::__count),
        h(h), w(w){
    SDL_Init( SDL_INIT_EVERYTHING );
    TTF_Init();
    SDL_WM_SetCaption( "fastgame", NULL );
    mwindow=this;
}

void mainwindow::render(){
    vsurface_.apply(background,0,0);
    for(auto &&layer: layers){
        layer.realDelete();
        for(auto &&obj: layer.data()){
            obj->draw(vsurface_);
        }
    }
    vsurface_.flip();
    //SDL_Flip(vsurface_.getSurface());
}

void mainwindow::remLay(gfxobject* obj, const layer lay){
    layers[lay].element_delete(obj);
}

mainwindow *mwindow=NULL;

}
