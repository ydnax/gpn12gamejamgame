#ifndef fgengine_gfxobject_hpp
#define fgengine_gfxobject_hpp
#include <pic-gl/Resources/Image.hpp>
namespace picppgl{
struct gfxobject{
    virtual void draw(Image&)=0;
    virtual ~gfxobject(){};
};
}
#endif
