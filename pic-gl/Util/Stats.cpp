#include "Stats.hpp"
#include <sstream>
namespace picppgl{
using std::stringstream;
Stats::InfoFun Stats::getStatFun(string key){
    return [&]()->string{
        stringstream tmp;
        tmp<<key<<": "<<data[key];
        return tmp.str();
    };
}
Stats::SetFun  Stats::addStatFun(string key){
    return [&](float val)->void{
        data[key]+=val;
    };
}
Stats::SetFun  Stats::setStatFun(string key){
    return [&](float val)->void{
        data[key]=val;
    };
}

}