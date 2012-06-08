#ifndef picppgl_Util_Stats_hpp
#define picppgl_Util_Stats_hpp
#include <map>
#include <string>
#include <functional>
using std::string;
namespace picppgl{
class Stats{
    private:
        typedef std::map<string, float> storage;
        storage data;
    public:
        typedef std::function<string()> InfoFun;
        typedef std::function<void(float)> SetFun;
        InfoFun getStatFun(string key);
        SetFun  addStatFun(string key);
};

}
#endif