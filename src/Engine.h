#ifndef ENGINE_H
#define ENGINE_H

#include <time.h>
#include <thread>


#include "Draw.h"
#include "Grid.h"
#include "Audio.h"
#include "Piece.h"

class Engine
{
    public:
        void run();
        virtual ~Engine();

    private:

        void logic();
        void init();

        bool isValid();
        bool isRunning = true;

        void confirmMove();
        void clearGridPiece(COLOR color);
        void doMove(KEYS direction);
        void wait();

        Grid* grid          = nullptr;
        Draw* draw          = nullptr;
        Piece* active_piece = nullptr;
        KEYS get_key();
        SDL_Event event;


        int level = 1;
        int score = 0;
        int ELAPSED = 0;
        float seconds = 0;
        const float FPS = 30.0;

        Audio audio;


};

#endif
