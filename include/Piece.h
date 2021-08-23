#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "definitions.h"

class Piece
{
    public:

        Piece(TYPE type);
        virtual ~Piece();

        COLOR get_color();
    protected:

    private:
        int type;
        COLOR color;
        std::vector<v2d> data;


};

#endif // PIECE_H
