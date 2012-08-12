%%{
machine level_gen;
action number_start{number_start();}
action number_push{number_push(fc);}
action number_end{number_end();} 

action version_number{version_number();}

action xvar{xvar();}
action yvar{yvar();}

action str_start{str_start();}
action str_push{str_push(fc);}
action str_end{str_end();}

action message{message();}

action set_player{set_player();}
action set_enemy{set_enemy();}
action town{town();}
action level_end{level_finish();}
action line_incr{linecount++;}

action perr{error("Syntax Error");}
action end{end();}

number  = digit+ >number_start $number_push %number_end ;
eol     = ' '* . '\n';
xvar    = number %xvar;
yvar    = number %yvar;
pos     = xvar . ' '+ . yvar;
string  = '"'%str_start . any+$str_push :> '"'%str_end;

player  = 'PLAYER'%set_player;
enemy   = 'ENEMY' %set_enemy;
owner   = (player|enemy);

version = ('VERSION:' . ' '  . number)%version_number;
message = ('MESSAGE' . ' '+ . pos . ' '+ . string )%message;
town    = ('TOWN' . ' '+ . pos . ' '+ . number . ' '+ . owner)%town;
levelend = 'END LEVEL'%level_end;
comment = '--'.(any*--'\n');

line = (' '*.(message|town|comment|levelend)?.comment?.eol)%line_incr;

mainx=town;
main:=( version.eol+.
        line*
    )%/end %/level_end $!perr; 
}%%


#include <iostream>
#include <game_name/Objects/ImgObj.hpp>
#include <game_name/Objects/Node.hpp>
#include <pic-gl/Ui/main_window.hpp>
#include "LevelLoader.hpp"
using namespace std;

namespace game_name{
using namespace picppgl;
void levelLoader::number_start(){
    nbuf.str("");
}
void levelLoader::number_push(char c){
    nbuf<<c;
}
void levelLoader::number_end(){
    numcache=stoi(nbuf.str());
}
void levelLoader::xvar(){
    xcache=numcache;
}
void levelLoader::yvar(){
    ycache=numcache;
}
void levelLoader::str_start(){
    strbuf.str("");
}
void levelLoader::str_push(char c){
    strbuf<<c;
}
void levelLoader::str_end(){
    strcache=strbuf.str();
}
void levelLoader::version_number(){
    int levelversion=numcache;
    if(levelversion!=1){
        cerr<<"INVALID LEVEL VERSION"<<endl;
        exit(1);
    }
}
void levelLoader::message(){
    auto _xcache=xcache;
    auto _ycache=ycache;
    auto _strcache=strcache;
    auto fun = [=](Level *lvl, nodeCallback){
        new ImgObj(_xcache, _ycache, Image(_strcache, 12), lvl);
    };
    lcomps.push_back(fun);
}

void levelLoader::set_player(){owner=1;}
void levelLoader::set_enemy(){owner=2;}
void levelLoader::town(){
    auto _xcache=xcache;
    auto _ycache=ycache;
    auto _numcache=numcache;
    auto _owner=owner;
    auto fun = [=](Level *lvl, nodeCallback cb){
        auto n = new Node(_xcache, _ycache, lvl);
        n->unitcount(_numcache);
        n->Owner(_owner==1 ? Player::User : Player::Ki);
        cb(n);
    };
    lcomps.push_back(fun);
}


void levelLoader::error(string msg){
    cerr<<"PARSING ERROR: "<<msg<<endl<<"Line: "<<linecount<<endl;
    exit(1);
}

void levelLoader::end(){
    cout<<"parsed all levels :)"<<endl;
}

void levelLoader::level_finish(){
    cout<<"level finish"<<endl;
    if(lcomps.empty())
        return;
    auto _lcomps=lcomps;
    auto lgen =     [=]()->Level*{
        std::vector<Node*> towns;
        auto lvl=new Level{nullptr};
        for(auto &&element:_lcomps){
            element(lvl, [&](Node *town){
                towns.push_back(town);
            });
        }
        auto winfun=[=]()->bool{
            for(auto &&town:towns){
                if(town->unitcount()==0)
                    return false;
                if(town->Owner()!=Player::User)
                    return false;
            }
            return true;
        };
        lvl->setWinFun(winfun); 
        return lvl;
    };
    lcache.push_back(lgen);
    lcomps={};
}

levelLoader::T_Levels levelLoader::parse(string data){
//ignore warnings by ragel generated sourcecode.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
        auto d   = const_cast<char*>(data.c_str()); //fix to string iterators
        auto p   = d;
        auto pe  = d+data.length();
        auto eof = pe;
        int cs   = 0;
        %%write data;
        %%write init;
        %%write exec;
#pragma clang diagnostic pop
        return lcache;

}



}