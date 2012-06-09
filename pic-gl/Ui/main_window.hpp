#ifndef picppgl_Ui_mainwindow_hpp
#define picppgl_Ui_mainwindow_hpp
#include <vector>
#include <map>
#include <pic-gl/Util/lazy_delete_vector.hpp>
#include <pic-gl/Resources/Image.hpp>

namespace picppgl{
struct winInfo{
    int h;
    int w;
};
struct gfxobject;
using std::vector;
class mainwindow{
    private:
        Image vsurface_;
        Image background;
        vector<lazyDeleteVector<gfxobject*> >layers;
        int h;
        int w;
    public:
        enum layer{bg=0, helptext=1, towns=2, units=3, overlay=4, __count=5};
        mainwindow(int h, int w, int bbp=32);
        void render();
        void addLay(gfxobject* obj, const layer lay){layers[lay].data().push_back(obj);}
        void remLay(gfxobject* obj, const layer lay);
        winInfo getInfo()const{return {h,w};}
};
extern mainwindow *mwindow;
}
#endif
