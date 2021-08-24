#ifndef DRAW_H
#define DRAW_H

#include "Grid.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <SDL_ttf.h>
class Draw
{
    public:
        Draw();
        virtual ~Draw();

        void draw_grid(Grid& grid , int score);

    protected:

    private:
        const int WINDOW_X = 600;
        const int WINDOW_Y = 800;
        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;
        std::string score_info;
        void draw_border();
        void reload_score();
        std::string get_score_string(int score);
        TTF_Font *font = nullptr;
        SDL_Texture* text = nullptr;
        bool renderScore = false;


};

#endif // DRAW_H
