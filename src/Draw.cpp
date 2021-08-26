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
    loadTextures();


}
void Draw::loadTexture(std::string path , int id)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == NULL)
    {
        std::cout << "error loading surface: " << path << "\n";
    }
    else{
        SDL_Texture* texture = SDL_CreateTextureFromSurface(render , surface);
        SDL_FreeSurface(surface);
        if(texture == NULL) std::cout << "error loading texture " << path << "\n";
        else{
            textures[id] = texture;
        }
    }
}
void Draw::loadTextures()
{
    loadTexture("textures/red.png", (int)COLOR::RED);
    loadTexture("textures/blue.png", (int)COLOR::BLUE);
    loadTexture("textures/green.png", (int)COLOR::GREEN);
    loadTexture("textures/black.png", (int)COLOR::BLACK);
    loadTexture("textures/orange.png", (int)COLOR::ORANGE);
}


Draw::~Draw()
{
    SDL_DestroyWindow(window);
    //dealocatte textures
    for(auto i = textures.begin();i != textures.end();i++)
    {
        SDL_DestroyTexture(i->second);
    }
    SDL_DestroyRenderer(render);


}

void Draw::draw_grid(Grid& grid , int score , int level , int time)
{
    int dx = (400) / Grid::DIM_X;
    int dy = (780) / Grid::DIM_Y;
    SDL_RenderClear(render);
    for(int y=0;y<Grid::DIM_Y;y++)
    {

        for(int x=0;x<Grid::DIM_X;x++)
        {
            COLOR color = grid.get_value(x , y);

            SDL_FRect* rect = new SDL_FRect{(float)dx*x , (float)dy*y , (float)dx , (float)dy};
            SDL_RenderCopyF(render , textures[color] , NULL , rect);
            delete rect;


        }
    }




    const SDL_FRect* rect = new SDL_FRect{425,25,150,100};
    SDL_SetRenderDrawColor(render, 158,18,0,0);
    delete rect;
    SDL_SetRenderDrawColor(render, 0,0,0,0);
    SDL_RenderPresent(render);
}

void Draw::update_text(int score , int level , int time)
{

    text[0] = fixed_string(score , 6);
    text[1] = fixed_string(level , 2);

    int minutes = (int)(time / 60);
    int seconds = time % 60;
    text[2] = fixed_string(minutes , 2) + ":" + fixed_string(seconds , 2);
}

std::string Draw::fixed_string(int value , int digits)
{
    int value_digits = 0;
    if(value != 0) value_digits = (int)log10(value);
    int s_left = digits - value_digits;
    std::string str = "";
    for(int i=0;i<s_left;i++) str += "0";
    return str + std::to_string(value);
}


