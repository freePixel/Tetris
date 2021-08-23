#include "Piece.h"

Piece::Piece(TYPE type)
{
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




Piece::~Piece()
{

}

COLOR Piece::get_color()
{
    return color;
}

