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
        static const int  DIM_X = 10;
        static const int  DIM_Y = 20;

        int simplifyGrid();
        Grid();
        virtual ~Grid();
        COLOR get_value(int x , int y);
        void set_value(int x , int y , COLOR value);
        void clear_value(int x , int y);
        bool isFree(int x , int y);




    private:
        COLOR data[DIM_X * DIM_Y];
        void shiftGrid();
        int to1D(int x , int y);



};

#endif
