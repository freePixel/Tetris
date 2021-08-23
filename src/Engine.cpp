#include "Engine.h"

Engine::~Engine()
{
    SDL_Quit();
    delete draw;
    delete grid;
}

void Engine::logic()
{

    //PROCESS EVENTS
    int KEY = 0;
    while(SDL_PollEvent(&event) > 0)
    {
        switch(event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_LEFT:
                    KEY = KEYS::LEFT;
                    break;
                case SDLK_RIGHT:
                    KEY = KEYS::RIGHT;
                    break;
                case SDLK_DOWN:
                    KEY = KEYS::DOWN;
                    break;
                case SDLK_r:
                    KEY = KEYS::ROTATE;
                    break;
            }
            break;
        }
    }

}
void Engine::render()
{
    draw->draw_grid(*grid);
}
void Engine::run()
{
    init();
    while(isRunning)
    {
        logic();
        render();
        SDL_Delay(100);
    }

}

void Engine::init()
{
    grid = new Grid();
    draw = new Draw();

}
