#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

enum KEYS
        {
            LEFT = 1 , DOWN , RIGHT , ROTATE
        };


 enum COLOR
        {
            REG = 1, GREEN , BLUE
        };
enum TYPE
        {
            L , S , T
        };

struct v2d
{
    int x = 0;
    int y = 0;
};

#endif // DEFINITIONS_H_INCLUDED
