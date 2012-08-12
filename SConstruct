VariantDir('build/game_name', 'game_name')
VariantDir('build/pic-gl', 'pic-gl')
env = Environment()
ragel_s=Builder( action     = 'ragel $SOURCE -o $TARGET', 
                 suffix     = '.cpp',
                 src_suffix = '.ragel.cpp')
ragel_i=Builder( action     = 'ragel -p -V $SOURCE | dot -Tpng > $TARGET', 
                 suffix     = '.png',
                 src_suffix = '.ragel.cpp')

env.Append(  BUILDERS = {'Ragel' : ragel_s, 'RagelImage': ragel_i})
env.Replace( CXX      = "clang++" )
env.Append(  CXXFLAGS = "-stdlib=libc++ -fcolor-diagnostics")
env.Append(  CCFLAGS  = '-pedantic -Wall -Wextra -Werror -std=c++11 -ferror-limit=2' )
env.Append(  LIBS     = ['c++','SDL', 'SDL_image', 'SDL_gfx', 'SDL_mixer', 'SDL_ttf',] )
env.Append(  CPPPATH  = '.' )
debug = ARGUMENTS.get('debug', 0)
if int(debug)==1:
    env.SetOption('num_jobs', 1)
    env.Append(LINKFLAGS='-faddress-sanitizer ')
    env.Append(CCFLAGS = '-faddress-sanitizer -fcatch-undefined-behavior -g -ggdb -O0')  
else:
    env.SetOption('num_jobs', 4)
    env.Append(CCFLAGS = '-O3  -mmmx  -msse  -msse2 -msse3')
parserpath='build/game_name/LevelLoader/LevelLoader'
parser=env.Ragel(parserpath)
env.RagelImage(parserpath)
env.Program("game_name.bin", [  env.Object(Glob('build/game_name/*.cpp')),
                                env.Object(Glob('build/game_name/GameLogic/*.cpp')),
                                env.Object(Glob('build/game_name/Objects/*.cpp')),
                                parser,
                                env.Object(Glob('build/pic-gl/Util/*.cpp')),
                                env.Object(Glob('build/pic-gl/Ui/*.cpp')),
                                env.Object(Glob('build/pic-gl/Resources/*.cpp')),
                                env.Object(Glob('build/pic-gl/Gameflow/*.cpp')),
                            ] )
