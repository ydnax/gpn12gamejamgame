#ifndef objects_test_hpp
#define objects_test_hpp
#include <pic-gl/Gameflow/Level.hpp>
#include <pic-gl/Ui/gfx_object.hpp>
namespace picppgl{
class ObTest:public levelObject, gfxobject{
private:
    Image img;
    float x=50;
    float y=50;
    float sp=50;

public:
    ObTest(Level*lvl);
    virtual void draw(Image&);
    virtual void update(int);
    virtual ~ObTest();
};

}
#endif