#ifndef GRID_H
#define GRID_H


#include <array>
#include <string>
#include <cstring>

class Grid
{
    public:
        static const int  DIM_X = 10;
        static const int  DIM_Y = 20;


        Grid();
        virtual ~Grid();
        int get_value(int x , int y);
        void set_value(int x , int y , int value);
        void clear_value(int x , int y);




    private:
        int data[DIM_X * DIM_Y];

        int to1D(int x , int y);

};

#endif // GRID_H
