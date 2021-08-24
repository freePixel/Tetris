#include "Draw.h"



Draw::Draw()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_X,WINDOW_Y,0);
    render = SDL_CreateRenderer(window , -1 , 0);
    const char* file = "Fairfax-MJ0J.ttf";
    font = TTF_OpenFont(file , 24);
    if(font == NULL)
    {
        std::cout << "error loading texture" << "\n";
    }
    reload_score();
}

Draw::~Draw()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(text);

}

void Draw::draw_grid(Grid& grid, int score)
{
    std::string last = score_info;
    score_info = get_score_string(score);
    if(last != score_info) renderScore = true;
    int dx = (400) / Grid::DIM_X;
    int dy = (780) / Grid::DIM_Y;
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
            case COLOR::ORANGE:
                SDL_SetRenderDrawColor(render, 255,165,0,0);
            }
            SDL_FRect* rect = new SDL_FRect{(float)dx*x , (float)dy*y , (float)dx , (float)dy};
            SDL_RenderFillRectF(render,rect);
            delete rect;


        }
    }

    draw_border();

    if(renderScore) reload_score();
    const SDL_FRect* rect = new SDL_FRect{425,25,150,100};
    SDL_SetRenderDrawColor(render, 158,18,0,0);
    SDL_RenderCopyF(render , text , NULL , rect);
    delete rect;
    SDL_SetRenderDrawColor(render, 0,0,0,0);
    SDL_RenderPresent(render);
}

std::string Draw::get_score_string(int score)
{
    int digits = 0;
    if(score != 0) digits = (int)log10(score);
    int left = 6 - digits;
    std::string str = "";
    for(int i=0;i<left;i++) str += "0";
    return str + std::to_string(score);
}

void Draw::reload_score()
{
    if(text != nullptr) SDL_DestroyTexture(text);
    SDL_Surface* surface = TTF_RenderText_Solid(font , score_info.c_str(), {127,127,255,0});
    text = SDL_CreateTextureFromSurface( render, surface );
    SDL_FreeSurface(surface);




    renderScore = false;
}

void Draw::draw_border()
{
    SDL_SetRenderDrawColor(render, 255,255,255,0);
    SDL_RenderDrawLineF(render , 0 , 780 , 400 , 780);
    SDL_RenderDrawLineF(render , 400 , 0 , 400 , 780);
}
