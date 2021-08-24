#include "Draw.h"

Draw::Draw()
{
    window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_X,WINDOW_Y,SDL_WINDOW_RESIZABLE);
    render = SDL_CreateRenderer(window , -1 , 0);
}

Draw::~Draw()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
}

void Draw::draw_grid(Grid& grid)
{
    int dx = WINDOW_X / Grid::DIM_X;
    int dy = WINDOW_Y / Grid::DIM_Y;
    SDL_RenderClear(render);
    for(int y=0;y<Grid::DIM_Y;y++)
    {

        for(int x=0;x<Grid::DIM_X;x++)
        {
            switch(grid.get_value(x , y))
            {
            case COLOR::BLACK:
                SDL_SetRenderDrawColor(render, 0,0,0,0);
                break;
            case COLOR::RED:
                SDL_SetRenderDrawColor(render, 255,0,0,0);
                break;
            case COLOR::GREEN:
                SDL_SetRenderDrawColor(render, 0,255,0,0);
                break;
            case COLOR::BLUE:
                SDL_SetRenderDrawColor(render, 0,0,255,0);
                break;
            }
            SDL_FRect* rect = new SDL_FRect{(float)dx*x , (float)dy*y , (float)dx , (float)dy};
            SDL_RenderFillRectF(render,rect);
            delete rect;


        }
    }
    SDL_SetRenderDrawColor(render, 0,0,0,0);
    SDL_RenderPresent(render);
}
