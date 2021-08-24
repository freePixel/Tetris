#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
enum INVALID
{
    COLLIDE_LEFT , COLLIDE_RIGHT , COLLIDE_DOWN
};
enum KEYS
        {
            LEFT = 1 , DOWN , RIGHT , ROTATE , NONE
        };


 enum COLOR
        {
            BLACK , RED , GREEN , BLUE , ORANGE
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

struct v2df
{
    float x = 0;
    float y = 0;
};

#endif // DEFINITIONS_H_INCLUDED
