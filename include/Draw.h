#ifndef DRAW_H
#define DRAW_H

#include "Grid.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

class Draw
{
    public:
        Draw();
        virtual ~Draw();

        void draw_grid(Grid& grid);

    protected:

    private:
        const int WINDOW_X = 400;
        const int WINDOW_Y = 800;
        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;


};

#endif // DRAW_H
