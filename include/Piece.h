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
        void undoRotation();
        void doRotation();

        COLOR get_color();

        std::vector<v2d> get_data();
        std::vector<v2d> get_lastPosition();

    private:
        std::vector<v2d> data;
        std::vector<v2d> last;
        std::vector<v2d> base;
        std::vector<std::vector<v2d>> rotation_list;

        static int pieceCounter;
        int rotation_value = 0;
        int type;
        COLOR color;
        v2df center;


};

#endif // PIECE_H
