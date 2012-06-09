#include "Image.hpp"
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
using namespace std;

namespace picppgl{
namespace sdl_util{

ImageData *loadImage(const std::string path){
    SDL_Surface  *raw = NULL;
    SDL_Surface  *imp = NULL;
    raw = IMG_Load(path.c_str()); 
    if( raw != NULL ){
        imp=SDL_DisplayFormatAlpha(raw);
        SDL_FreeSurface(raw);
    } 
    if(!imp)
        std::cerr<<"img load error: "<<IMG_GetError()<<std::endl;
    //return imp;
    return reinterpret_cast<ImageData*>(imp);
}

ImageData *create_blank_surface (const int width, const int height ){
    auto basis = SDL_GetVideoSurface();
    auto ret = SDL_CreateRGBSurface (   basis->flags, width, height,
                                        basis->format->BitsPerPixel,
                                        basis->format->Rmask,
                                        basis->format->Gmask,
                                        basis->format->Bmask,
                                        basis->format->Amask);
    return reinterpret_cast<ImageData*>(ret);
}

void matchColorKeys(SDL_Surface *src, SDL_Surface *dest ){
    if( src->flags & SDL_SRCCOLORKEY ){
        Uint32 colorkey = src->format->colorkey;
        SDL_SetColorKey( dest, SDL_SRCCOLORKEY, colorkey );
    }
}

void resizeImage( ImageData*& dimg, const double newwidth, const double newheight ){
    auto img=reinterpret_cast<SDL_Surface*>(dimg);
    double zoomx = newwidth  / (float)img->w;
    double zoomy = newheight / (float)img->h;
    auto sized = zoomSurface( img, zoomx, zoomy, SMOOTHING_OFF );
    matchColorKeys( img, sized );
    SDL_FreeSurface( img );
    img  = sized;
    dimg = reinterpret_cast<ImageData*>(img);
}


}


Image::Image(string path){
    data = sdl_util::loadImage(path);
}

Image::Image( int w, int h){
    data = sdl_util::create_blank_surface(w,h);
}

Image::Image(ImageData *d){
    data = d;
}

Image::Image(string text,int, Color fg, Color bg){
    static TTF_Font *font = TTF_OpenFont( "game_name/font/terminal-grotesque.ttf", 18);
    if(!font){
        std::cout<<"couldn't load font game_name/font/terminal-grotesque.ttf"<<std::endl;
        std::exit(1);
    }
    SDL_Color textColor = { static_cast<Uint8>(fg.r), static_cast<Uint8>(fg.g), static_cast<Uint8>(fg.b), 0 };
    SDL_Color bgColor = { static_cast<Uint8>(bg.r),static_cast<Uint8>(bg.g),static_cast<Uint8>(bg.b), 0 };
    data = reinterpret_cast<ImageData*>(TTF_RenderText_Shaded(font, text.c_str(), textColor,bgColor));
    
}

Image::Image(const Image& other){
    auto src = reinterpret_cast<SDL_Surface*>(other.getSurface());
    data = reinterpret_cast<ImageData*>(SDL_ConvertSurface(src, src->format, src->flags));
}

Image& Image::operator= (const Image &other){
    auto src = reinterpret_cast<SDL_Surface*>(other.getSurface());
    data = reinterpret_cast<ImageData*>(SDL_ConvertSurface(src, src->format, src->flags));
    return *this;
}

Image::Image(string path, int w, int h){
    data=sdl_util::loadImage(path);
    resize(w,h);
}

Image::Image(int w, int h, int r, int b, int g, ImageData *context){
    data=sdl_util::create_blank_surface(w,h);
    SDL_FillRect(   reinterpret_cast<SDL_Surface*>(data), 
                    NULL, 
                    SDL_MapRGB(reinterpret_cast<SDL_Surface*>(context)->format, 
                    r, b, g));
}



Image::~Image(){
    SDL_FreeSurface(reinterpret_cast<SDL_Surface*>(data));
    data=0;
}

void Image::resize( int width, int height){
    sdl_util::resizeImage(data, width, height);
}

void Image::apply(Image &what, int x, int y){
    SDL_Rect offset; 
    offset.x = x; offset.y = y;
    SDL_BlitSurface( reinterpret_cast<SDL_Surface*>(what.getSurface()), 
        NULL, 
        reinterpret_cast<SDL_Surface*>(data), 
        &offset ); 
}

int Image::w()const{
    return reinterpret_cast<SDL_Surface*>(data)->w;
}

int Image::h()const{
    return reinterpret_cast<SDL_Surface*>(data)->h;
}

ImageData *Image::getSurface()const{
    return data;
}

void Image::flip(){
    SDL_Flip(reinterpret_cast<SDL_Surface*>(data));
}

}