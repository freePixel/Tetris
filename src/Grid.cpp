#include "Grid.h"

Grid::Grid()
{
    for(int i=0;i<DIM_X * DIM_Y ; i++)
    {
        data[i] = COLOR::BLACK;
    }

}

Grid::~Grid()
{

}

int Grid::to1D(int x , int y)
{
    if(x < 0 || x >= DIM_X || y < 0 || y >= DIM_Y)
    {
        std::string message = "invalid conversion: 0 < x < " + std::to_string(DIM_X) + " and 0 < y < " + std::to_string(DIM_Y) + ".";
        throw std::invalid_argument(message);
    }
    else{
        return x + DIM_X * y;
    }

}

void Grid::shiftGrid()
{
    for(int y = 1; y < DIM_Y; y++)
    {
        for(int x=0;x<DIM_X;x++)
        {
            data[to1D(x , y)] = data[to1D(x , y-1)];
        }
    }
}

int Grid::simplifyGrid()
{
    int score = 0;
    for(int y=0;y<DIM_Y;y++)
    {
        for(int x=0;x<DIM_X;x++)
        {
            if(data[to1D(x , y)] == COLOR::BLACK)
            {
                break;
            }
            if(x == DIM_X - 1)
            {
                for(int i=0;i<DIM_X;i++)
                {
                    data[to1D(i , y)] = COLOR::BLACK;
                }
                shiftGrid();
                score += 100;
            }
        }
    }
    return score;
}
COLOR Grid::get_value(int x , int y)
{
    int pos = to1D(x,y);
    return data[pos];
}

void Grid::set_value(int x , int y , COLOR value)
{
    if(value <  0 || value > 7) throw std::invalid_argument("Expected value between 1 and 7");
    int pos = to1D(x,y);

    data[pos] = value;
}

void Grid::clear_value(int x , int y)
{
    int pos = to1D(x,y);
    data[pos] = COLOR::BLACK;
}

bool Grid::isFree(int x , int y)
{
    if(data[to1D(x , y)] == COLOR::BLACK) return true;
    else{
        return false;
    }
}
