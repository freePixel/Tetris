/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include "Draw.h"

int main(int argc , char* argv[])
{
    Grid* grid = new Grid();

    Draw draw;
    while(true)
    {
        draw.draw_grid(*grid);
        SDL_Delay(1000);

    }
    delete grid;
    return 0;

}
