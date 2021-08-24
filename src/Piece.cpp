#include "Piece.h"

void Piece::undoMove()
{
    data = last;
}

void Piece::undoRotation()
{
    data = last;
    rotation_value--;
}

int Piece::pieceCounter = rand() % 100;

std::vector<v2d> Piece::get_lastPosition()
{
    return last;
}

Piece::Piece()
{
    pieceCounter++;
    type = pieceCounter % 7;

    color = (COLOR)(pieceCounter % 4 + 1);
    switch(type)
    {
    case TYPE::S:
        data = {{0,1},{1,1},{1,0},{2,0}};
        rotation_list = {{{1,-1},{0,0},{1,1},{0,2}},
                        {{1,1},{0,0},{-1,1},{-2,0}},
                        {{-1,1},{0,0},{-1,-1},{0,-2}},
                        {{-1,-1},{0,0},{1,-1},{2,0}}};

        break;
        case TYPE::Z:
        data = {{0,0},{1,0},{1,1},{2,1}};
        rotation_list = {{{2,0},{1,1},{0,0},{-1,1}},
                        {{0,2},{-1,1},{0,0},{-1,-1}},
                        {{-2,0},{-1,-1},{0,0},{1,-1}},
                        {{0,-2},{1,-1},{0,0},{1,1}}};
        break;
    case TYPE::L:
        data = {{0,1},{0,0},{1,0},{2,0}};
        rotation_list = {{{0,-2},{1,-1},{0,0},{-1,1}},
                        {{2,0},{1,1},{0,0},{-1,-1}},
                        {{0,2},{-1,1},{0,0},{1,-1}},
                        {{-2,0},{-1,-1},{0,0},{1,1}}};
        break;
    case TYPE::J:
        data = {{0,0},{1,0},{2,0},{2,1}};
        rotation_list = {{{1,-1},{0,0},{-1,1},{-2,0}},
                        {{1,1},{0,0},{-1,-1},{0,-2}},
                        {{-1,1},{0,0},{1,-1},{2,0}},
                        {{-1,-1},{0,0},{1,1},{0,2}}};
        break;
    case TYPE::SQUARE:
        data = {{0,0},{0,1},{1,0},{1,1}};
        rotation_list = {{{0,0},{0,0},{0,0},{0,0}}};
        break;
    case TYPE::I:
        data = {{0,0},{1,0},{2,0},{3,0}};
        rotation_list = {{{2,-2},{1,-1},{0,0},{-1,1}},
                        {{-2,2},{-1,1},{0,0},{1,-1}}};
        break;
    case TYPE::T:
        data = {{0,1},{1,1},{1,0},{2,1}};
        rotation_list = {{{1,-1},{0,0},{1,1},{-1,1}},
                        {{1,1},{0,0},{-1,1},{-1,-1}},
                        {{-1,1},{0,0},{-1,-1},{1,-1}},
                        {{-1,-1},{0,0},{1,-1},{1,1}}};
        break;
    }

}
std::vector<v2d> Piece::get_data()
{
    return data;
}


void Piece::translate(KEYS dir)
{
    last.clear();
    v2d diff = {0,0};
    for(int i=0;i<data.size();i++) last.push_back(data.at(i));

    if(dir == KEYS::LEFT) diff = {-1,0};

    if(dir == KEYS::RIGHT) diff = {1,0};

    if(dir == KEYS::DOWN) diff = {0,1};

    for(int i=0;i<data.size();i++)
    {
        data.at(i).x += diff.x;
        data.at(i).y += diff.y;
    }

}


void Piece::doRotation()
{
    if(rotation_value > rotation_list.size() - 1)
    {
        rotation_value = 0;
    }
    last.clear();
    for(int i=0;i<data.size();i++) last.push_back(data.at(i));

    for(int i=0;i<data.size();i++)
    {

        data.at(i).x += rotation_list[rotation_value].at(i).x;
        data.at(i).y += rotation_list[rotation_value].at(i).y;
    }
    rotation_value++;


}

Piece::~Piece()
{

}

COLOR Piece::get_color()
{
    return color;
}

