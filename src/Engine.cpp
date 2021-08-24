#include "Engine.h"

Engine::~Engine()
{
    SDL_Quit();
    delete draw;
    delete grid;
}
void Engine::clearGridPiece(COLOR color)
{
    std::vector<v2d> data = active_piece->get_lastPosition();
    for(unsigned int i=0;i<data.size();i++)
    {
        v2d point = data.at(i);
        grid->set_value(point.x, point.y, color);
    }
}
void Engine::confirmMove() // USE THIS FUNCTION IF AND ONLY IF THE MOVE IS VALID
{

    std::vector<v2d> data = active_piece->get_data();
    for(unsigned int i=0;i<data.size();i++)
    {
        v2d point = data.at(i);
        grid->set_value(point.x , point.y , active_piece->get_color());
    }
}


bool Engine::isValid()
{
    clearGridPiece(COLOR::BLACK);
    std::vector<v2d> data = active_piece->get_data();
    for(unsigned int i=0;i<data.size();i++)
    {
        v2d point = data.at(i);

        if(point.x < 0 || point.x >= Grid::DIM_X || point.y < 0 || point.y >= Grid::DIM_Y) return false;
        if(!grid->isFree(point.x , point.y))
        {
            return false;
        }

    }
    return true;

}

void Engine::doMove(KEYS direction)
{

    if(direction == KEYS::DOWN)
    {
        active_piece->translate(KEYS::DOWN);
        if(isValid())
        {
            confirmMove();
        }
        else{
            clearGridPiece(active_piece->get_color());
            active_piece->~Piece();
            active_piece = new Piece();
        }
    }
    if(direction == KEYS::LEFT || direction == KEYS::RIGHT)
    {

        active_piece->translate(direction);
        if(isValid())
        {
            confirmMove();
        }
        else{
            active_piece->undoMove();
            clearGridPiece(active_piece->get_color());
        }
    }
    if(direction == KEYS::ROTATE)
    {
        active_piece->doRotation();
        if(isValid())
        {
            confirmMove();
        }
        else{
            active_piece->undoMove();
        }
    }
}

void Engine::logic()
{

    //PROCESS EVENTS
    KEYS KEY = KEYS::NONE;
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

    doMove(KEY);

    if(ELAPSED % 1000 == 0 && KEY != KEYS::DOWN)
    {
        doMove(KEYS::DOWN);
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
        ELAPSED += DELAY;
        SDL_Delay(DELAY);
    }

}

void Engine::init()
{
    grid = new Grid();
    draw = new Draw();

    active_piece = new Piece();

}
