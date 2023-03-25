#include <kipr/wombat.h>
#include "constants.h"

void open_claw()
{
    set_servo_position(CLAW, CLAW_OPEN);
    msleep(750);
}

void close_claw()
{
    set_servo_position(CLAW, CLAW_CLOSED);
    
    msleep(750);
}

void arm_up()
{
    set_servo_position(ARM, ARM_UP);
    msleep(750);
}

void arm_down()
{
    set_servo_position(ARM, ARM_DOWN);
    msleep(750);
}

void move_servo_slowly(int port, int end_pos)
{
  int current_pos;
    
    current_pos = get_servo_position(port);
    
    if (current_pos < end_pos)
    {
      while (current_pos < end_pos)
      {
          current_pos += 10;
          set_servo_position(port, current_pos);
          msleep(30);
      }
    }
    else
    {
        while (current_pos > end_pos)
        {
            current_pos -= 10;
            set_servo_position(port, current_pos);
            msleep(30);
        }
    }
    set_servo_position(port, end_pos);
}
      
    
    
    
    
    
    
    
    
    
    
    
    
    
    
