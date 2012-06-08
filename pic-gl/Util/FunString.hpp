#ifndef picppgl_Util_FunString_hpp
#define picppgl_Util_FunString_hpp
#include <string>
#include <sstream>
#include <functional>
using std::string;
namespace picppgl{
template <class t>
std::function<string()> FunString(string Text, std::function<t()> drawFun){
    return [&]()->string{
        std::stringstream out;
        out<<Text<<drawFun();
        return out.str();
    };
}

}
#endif