#ifndef DRAW_H
#define DRAW_H

#include "Grid.h"
#include <SDL2/SDL.h>

#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <SDL2/SDL_ttf.h>
class Draw
{
    public:
        Draw();
        virtual ~Draw();

        void draw_content(Grid& grid , int score , int level , int time);

    protected:

    private:
        void loadTextures();
        void loadTexture(std::string path , int id);

        void draw_grid(Grid& grid);
        void draw_text();

        void load_text_texture(std::string text , int id);

        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;
        TTF_Font *font = nullptr;

        std::string text_arr[3];
        void update_text(int score , int level , int time);
        std::string fixed_string(int value , int digits);

        std::map<int , SDL_Texture*> textures;

        const int WINDOW_X = 600;
        const int WINDOW_Y = 800;

};

#endif // DRAW_H
