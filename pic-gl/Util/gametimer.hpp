#ifndef fgengine_gametimer_hpp
#define fgengine_gametimer_hpp


namespace picppgl{
typedef int ticks;
class GameTimer{
    private:
    //The clock time when the timer started
    ticks startTicks;
    ticks oticks;

    //The ticks stored when the timer was paused
    ticks pausedTicks;

    //The timer status
    bool paused;
    bool started;

    public:
    //Initializes variables
    GameTimer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    ticks get_ticks();
    ticks get_dticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};

}

#endif
