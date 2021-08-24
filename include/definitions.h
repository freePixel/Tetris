#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
enum INVALID
{
    COLLIDE_LEFT , COLLIDE_RIGHT , COLLIDE_DOWN
};
enum KEYS
        {
            LEFT = 1 , DOWN , RIGHT , ROTATE
        };


 enum COLOR
        {
            RED = 1, GREEN , BLUE , BLACK
        };
enum TYPE
        {
            S = 0 , Z , L , J , SQUARE , I , T
        };

struct v2d
{
    int x = 0;
    int y = 0;
};

#endif // DEFINITIONS_H_INCLUDED
