#ifndef gamejam_levelLoader_hpp
#define gamejam_levelLoader_hpp
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <game_name/Objects/Node.hpp>

namespace game_name{

class levelLoader{
    private:
        typedef std::function<void(picppgl::Node*)> nodeCallback;
        typedef std::function<void(picppgl::Level*, nodeCallback)> lvlElement;
        typedef std::vector<lvlElement> lvlComponents;
        typedef std::function<picppgl::Level*()> LvlFun;
    public:
        typedef std::vector<LvlFun> T_Levels;
    private:
        std::stringstream nbuf;
        std::stringstream strbuf;
        int numcache;
        int xcache, ycache;
        int linecount=1;
        std::string strcache;
        lvlComponents lcomps;
        T_Levels lcache;
        int owner=0;
        void number_start();
        void number_push(char c);
        void number_end();
        void xvar();
        void yvar();
        void str_start();
        void str_push(char c);
        void str_end();
        void version_number();
        void message();
        void set_player();
        void set_enemy();
        void town();
        void error(string msg);
        void end();
        void level_finish();
    public:
        T_Levels parse(std::string data);
};
};

#endif