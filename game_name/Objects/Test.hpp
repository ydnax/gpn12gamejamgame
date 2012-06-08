#ifndef objects_test_hpp
#define objects_test_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
namespace picppgl{
class ObTest:public levelObject, gfxobject{
private:
    Image img;
    float x=200;
    float y=200;
    float spx=50;
    float spy=100;

public:
    ObTest(Level*lvl);
    virtual void draw(Image&);
    virtual void update(int);
    virtual ~ObTest();
};

}
#endif