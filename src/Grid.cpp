#include "Grid.h"

Grid::Grid()
{
    std::memset(data , COLOR::BLACK , sizeof(data));

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

COLOR Grid::get_value(int x , int y)
{
    int pos = to1D(x,y);
    return data[pos];
}

void Grid::set_value(int x , int y , COLOR value)
{
    if(value <= 0 || value > 7) throw std::invalid_argument("Expected value between 1 and 7");
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
    return data[to1D(x,y)] == 0;
}
