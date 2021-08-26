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
void Engine::confirmMove()
{

    std::vector<v2d> data = active_piece->get_data();
    for(unsigned int i=0;i<data.size();i++)
    {
        v2d point = data.at(i);
        grid->set_value(point.x , point.y , active_piece->get_color());
    }
    draw->draw_content(*grid , score ,level,(int)seconds);
}


bool Engine::isValid()
{
    clearGridPiece(COLOR::BLACK);
    std::vector<v2d> data = active_piece->get_data();
    for(unsigned int i=0;i<data.size();i++)
    {
        v2d point = data.at(i);

        if(point.x < 0 || point.x >= Grid::DIM_X || point.y >= Grid::DIM_Y) return false;
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
            score++;
        }
        else{
            clearGridPiece(active_piece->get_color());
            active_piece->~Piece();
            active_piece = new Piece();
            score += grid->simplifyGrid();
            level = (int)(score / 1000) + 1;
            if(!isValid())
            {
                int a = 0;
                std::cout << "Game over" << "\n";
                isRunning = false;
            }
            else{
                confirmMove();
            }
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
            confirmMove();
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
            active_piece->undoRotation();
            confirmMove();
        }
    }
}


void Engine::logic()
{

    KEYS KEY = get_key();
    doMove(KEY);
    wait();

}

KEYS Engine::get_key()
{
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
    return KEY;
}

void Engine::wait()
{
    float dt = 1.05 - 0.05 * level;
    if (level > 15) dt = 0.25;
    if(ELAPSED > dt * 1000000)
    {
        ELAPSED -= dt * 1000000;
        doMove(KEYS::DOWN);
        seconds += dt;
    }
    int var = (int)(1000000 / FPS);
    std::this_thread::sleep_for(std::chrono::microseconds(var));
    ELAPSED += var;
    draw->draw_content(*grid , score ,level,(int)seconds);
}
void Engine::run()
{
    init();
    while(isRunning)
    {
        logic();


    }

}

void Engine::init()
{
    grid = new Grid();
    draw = new Draw();

    active_piece = new Piece();

    confirmMove();

}
