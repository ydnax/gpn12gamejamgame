env = Environment()
env.Replace( CXX      = "clang++" )
env.Append(  CXXFLAGS = "-stdlib=libc++ -fcolor-diagnostics")
env.Append(  CCFLAGS  = '-pedantic -Wall -Wextra -Werror -std=c++11' )
env.Append(  LIBS     = ['c++','SDL', 'SDL_image', 'SDL_gfx', 'SDL_ttf',] )
env.Append(  CPPPATH  = '.' )
debug = ARGUMENTS.get('debug', 0)
if int(debug)==1:
    env.SetOption('num_jobs', 1)
    env.Append(LINKFLAGS='-faddress-sanitizer ')
    env.Append(CCFLAGS = '-faddress-sanitizer -fcatch-undefined-behavior -g -ggdb -O0')  
else:
    env.SetOption('num_jobs', 4)
    env.Append(CCFLAGS = '-O3  -mmmx  -msse  -msse2 -msse3')
env.Program("game_name.bin", [  env.Object(Glob('game_name/*.cpp')),
                                env.Object(Glob('game_name/Objects/*.cpp')),
                                env.Object(Glob('pic-gl/Util/*.cpp')),
                                env.Object(Glob('pic-gl/Ui/*.cpp')),
                                env.Object(Glob('pic-gl/Resources/*.cpp')),
                                env.Object(Glob('pic-gl/Gameflow/*.cpp')),
                            ] )
