#include <kipr/wombat.h>
#include "constants.h"

void forward_to_black(int speed, int port)
{
    mav(LM, speed);
    mav(RM, speed);

    while( analog(port) < BLACK )
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}

void backward_to_black(int speed, int port)
{
    mav(LM, -speed);
    mav(RM, -speed);

    while(analog(port) < BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}

void left_to_black(int speed, int port)
{
    mav(LM, -speed);
    mav(RM, speed);

    while(analog(port) < BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}

void right_to_black(int speed, int port)
{
    mav(LM, speed);
    mav(RM, -speed);

    while(analog(port) < BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}

void follow_line(int speed, int port, int dist)
{
    cmpc(LM);
    cmpc(RM);
    while( gmpc(LM) < dist)
    {
        if ( analog(port) < BLACK) //SEE WHITE
        {
            mav(LM, speed -200);
            mav(RM, speed +200);
        }
        else
        {
            mav(LM, speed +200);
            mav(RM, speed-200);
        }
    }// end while
    mav(LM, 0);
    mav(RM, 0);
}

















