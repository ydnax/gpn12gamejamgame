#ifndef gamejam_unitctrl_hpp
#define gamejam_unitctrl_hpp
#include <pic-gl/Util/lazy_delete_vector.hpp>
#include <pic-gl/Util/boxtools.hpp>
namespace picppgl{

struct clickable;

class ClickCtrl{
    lazyDeleteVector<clickable*> objects;
    void clickDispatch(int, int);
    clickable* last=nullptr;
    void sendSignal(char sig);
public:
    void handleInput();
    void addObj(clickable*);
    void delObj(clickable*);
};
extern ClickCtrl *clickctrl;

struct clickable{
    clickable(){clickctrl->addObj(this);}
    virtual objinfo getBox()=0;
    virtual void clicked()=0;
    virtual void event(char key)=0;
    virtual ~clickable(){clickctrl->delObj(this);}
};
}
#endif