#include "Piece.h"

Piece::Piece()
{
    type = rand() % 7;
    switch(type)
    {
    case TYPE::L:
        data = {{0,1},{0,0},{1,0},{2,0},{3,0}};
        break;
    case TYPE::S:
        data = {{0,1},{0,0},{1,0},{2,0},{3,0}}; //undone
        break;
    case TYPE::T:
        data = {{0,1},{0,0},{1,0},{2,0},{3,0}}; //undone
        break;
    }
}
std::vector<v2d> Piece::get_data()
{
    std::vector<v2d> vec;
    for(int i=0;i<data.size();i++)
    {
        v2d point = data.at(i);
        vec.push_back({point.x + position.x , point.y + position.y});
    }
    return vec;
}

v2d Piece::get_difference()
{
    return difference;
}

void Piece::translate(KEYS dir)
{
    if(dir == KEYS::LEFT)
    {
        difference = {-1 , 0};
        position.x--;
    }
    if(dir == KEYS::RIGHT)
    {
        difference = {1 , 0};
        position.x++;
    }
    if(dir == KEYS::DOWN)
    {
        difference = {0 , 1};
        position.y++;
    }
}




Piece::~Piece()
{

}

COLOR Piece::get_color()
{
    return color;
}

