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
#include <map>
class Draw
{
    public:
        Draw();
        virtual ~Draw();

        void draw_grid(Grid& grid , int score , int level , int time);

    protected:

    private:
        void loadTextures();
        void loadTexture(std::string path , int id);


        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;
        TTF_Font *font = nullptr;

        std::string text[3];
        void update_text(int score , int level , int time);
        std::string fixed_string(int value , int digits);

        std::map<int , SDL_Texture*> textures;

        const int WINDOW_X = 600;
        const int WINDOW_Y = 800;

};

#endif // DRAW_H
