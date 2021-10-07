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
        std::cout << "error loading font" << "\n";
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
    loadTexture("textures/audio.png" , 75);
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

void Draw::draw_content(Grid& grid , int score , int level , int time)
{

    update_text(score , level , time);

    SDL_RenderClear(render);

    draw_grid(grid);
    draw_text();

    SDL_FRect* r = new SDL_FRect{435 , 250 , 40 , 40};
    SDL_RenderCopyF(render , textures[75] , NULL , r);
    delete r;

    SDL_RenderPresent(render);
}
void Draw::load_text_texture(std::string text , int id)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font , text.c_str(), {255,255,200,0});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render , surface);
    SDL_FreeSurface(surface);
    if(textures[id] != nullptr)
    {
        SDL_DestroyTexture(textures[id]);
    }
    textures[id] = texture;
}
void Draw::draw_text()
{
    //draw text_arr[0] (score)
    SDL_FRect* score_r = new SDL_FRect{415,0,180,78};
    SDL_FRect* level_r = new SDL_FRect{415,600,180,78};
    SDL_FRect* time_r = new SDL_FRect{435,700,125,78};

    SDL_RenderCopyF(render , textures[50] , NULL , score_r);
    SDL_RenderCopyF(render , textures[51] , NULL , level_r);
    SDL_RenderCopyF(render , textures[52] , NULL , time_r);

    delete score_r;
    delete level_r;
    delete time_r;


}

void Draw::draw_grid(Grid& grid)
{
    int dx = (400) / Grid::DIM_X;
    int dy = (780) / Grid::DIM_Y;
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
}

void Draw::update_text(int score , int level , int time)
{
    std::string  last_t0 = text_arr[0];
    std::string  last_t1 = text_arr[1];
    std::string  last_t2 = text_arr[2];
    text_arr[0] = fixed_string(score , 6);
    text_arr[1] = "Level:" + fixed_string(level , 2);

    int minutes = (int)(time / 60);
    int seconds = time % 60;
    text_arr[2] = fixed_string(minutes , 2) + ":" + fixed_string(seconds , 2);

    if(last_t0 != text_arr[0]) load_text_texture(text_arr[0] , 50);
    if(last_t1 != text_arr[1]) load_text_texture(text_arr[1] , 51);
    if(last_t2 != text_arr[2]) load_text_texture(text_arr[2] , 52);


}

std::string Draw::fixed_string(int value , int digits)
{
    int value_digits = 0;
    if(value != 0) value_digits = (int)log10(value);
    int s_left = digits - value_digits - 1;
    std::string str = "";
    for(int i=0;i<s_left;i++) str += "0";
    return str + std::to_string(value);
}


