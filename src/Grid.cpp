#include "Grid.h"

Grid::Grid()
{
    std::memset(data , 0 , sizeof(data));
    set_value(0,0,5);

}

Grid::~Grid()
{

}

int Grid::to1D(int x , int y)
{
    if(x < 0 || x >= DIM_X || y < 0 || y >= DIM_Y)
    {
        std::string message = "invalid conversion: 0 < x < " + std::to_string(DIM_X) + " and 0 < y < " + std::to_string(DIM_Y) + ".";
        throw std::overflow_error(message);
    }
    else{
        return x + DIM_X * y;
    }

}

int Grid::get_value(int x , int y)
{
    int pos = to1D(x,y);
    return data[pos];
}

void Grid::set_value(int x , int y , int value)
{
    if(value <= 0 || value > 7) throw std::overflow_error("Expected value between 1 and 7");
    int pos = to1D(x,y);

    data[pos] = value;
}

void Grid::clear_value(int x , int y)
{
    int pos = to1D(x,y);
    data[pos] = 0;
}
