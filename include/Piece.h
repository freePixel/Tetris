#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include "definitions.h"
#include <stdlib.h>
class Piece
{
    public:
        Piece();
        virtual ~Piece();
        void translate(KEYS dir);
        COLOR get_color();
        std::vector<v2d> get_data();
        v2d get_difference();
    protected:

    private:
        v2d difference = {0,0};
        int type;
        COLOR color;
        v2d position = {0,0};
        std::vector<v2d> data;


};

#endif // PIECE_H
