#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

enum KEYS
        {
            LEFT = 1 , DOWN , RIGHT , ROTATE
        };


 enum COLOR
        {
            REG = 1, GREEN , BLUE , BLACK
        };
enum TYPE
        {
            S , Z , L , J , SQUARE , I , T
        };

struct v2d
{
    int x = 0;
    int y = 0;
};

#endif // DEFINITIONS_H_INCLUDED
