#ifndef GRID_H
#define GRID_H


#include "definitions.h"

#include <array>
#include <iostream>
#include <string>
#include <cstring>

class Grid
{
    public:

        Grid();
        virtual ~Grid();

        void set_value(int x , int y , COLOR value);
        void clear_value(int x , int y);

        int simplifyGrid();

        COLOR get_value(int x , int y);
        bool isFree(int x , int y);

        static const int  DIM_X = 10;
        static const int  DIM_Y = 20;



    private:
        void shiftGrid(int h);
        COLOR data[DIM_X * DIM_Y];

        int to1D(int x , int y);



};

#endif
