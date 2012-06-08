#ifndef fgengine_tools_hpp
#define fgengine_tools_hpp
#include <vector>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <assert.h>

namespace picppgl{

struct point{
    int x, y;
};

enum class corner{
    UL,
    UR,
    DL,
    DR
};

inline point getCornerPoint(const point a, const point b, const corner c){
    int nx, ny;
    //upper left is 0,0
    if(c==corner::UL||c==corner::DL)
    nx=(a.x<b.x)?a.x:b.x;
    else
    nx=(a.x>b.x)?a.x:b.x;
    
    if(c==corner::UL||c==corner::UR)
    ny=(a.y<b.y)?a.y:b.y;
    else
    ny=(a.y>b.y)?a.y:b.y;
    
    return {nx,ny};
}

using std::pow;
using std::sqrt;
using std::atan2;


inline float getPointDistance(const point a, const point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

inline float getAngle(const point pa, const point pb){
    float ret = atan2((pb.y*-1)-(pa.y*-1),pb.x-pa.x)*180/M_PI;
    if(ret<0.0){
        ret=360+ret;
    }
    return ret;
}


template<typename t>
void v_delete(std::vector<t> &container, t &item,bool chk=true, bool destroy=false){
    auto it=std::find(container.begin(), container.end(), item);
    if(chk){
        assert(it!=container.end());
        assert(*it);
    }    
    container.erase(it);
    if(destroy)
        delete item;
}

using std::abs;
template<class t>
bool cmp(const t a, const t b, const t diff){
    return abs(a-b)<=diff;
}


}

#endif
