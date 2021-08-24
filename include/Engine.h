#ifndef ENGINE_H
#define ENGINE_H

#include "Draw.h"
#include "Grid.h"
#include "Piece.h"

class Engine
{
    public:
        void run();
        virtual ~Engine();

    private:

        void render();
        void logic();
        void init();


        bool isValid();
        void confirmMove();
        void clearGridPiece(COLOR color);

        Grid* grid;
        Draw* draw;

        Piece* active_piece = nullptr;

        bool isRunning = true;

        SDL_Event event;

        int DELAY = 100;
        int ELAPSED = 0;


};

#endif
