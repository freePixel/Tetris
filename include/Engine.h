#ifndef ENGINE_H
#define ENGINE_H

#include "Draw.h"
#include "Grid.h"


class Engine
{
    public:
        void run();
        virtual ~Engine();

    private:

        void render();
        void logic();
        void init();



        Grid* grid;
        Draw* draw;

        bool isRunning = true;

        SDL_Event event;

};

#endif
