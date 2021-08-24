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
        void undoMove();
        std::vector<v2d> get_lastPosition();
        COLOR get_color();
        std::vector<v2d> get_data();
        void doRotation();
    protected:

    private:
        int type;
        COLOR color;
        std::vector<v2d> data;
        std::vector<v2d> last;
        std::vector<v2d> base;
        std::vector<std::vector<v2d>> rotation_list;
        v2df center;
        int rotation_value = 0;


};

#endif // PIECE_H
