#include <kipr/wombat.h>
#include "movement.h"
#include "sensors.h"
#include "constants.h"
#include "effectors.h"
int main()
{
    printf("Hello World\n");
    enable_servos();
    //GET INTO START POSITION
	arm_up();
    close_claw();
    //wait_for_light();
    msleep(250);
    shut_down_in(119);
    
    //===============================================================================
    forward_to_black(1000, LINE);
    open_claw();
    left(1000,100);
    forward(1000,1080);// FORWARD TO BOTGAL 
    follow_line(1000, LINE, 4700);
    //readjust to botgall
    backward(1500,500);
    left(1500,250);
    forward(2000,500);
    close_claw(); //botgal grabbed
    right(1000,250);
    set_servo_position(ARM, 2048); // LIFT BOTGALL
    //GO SCORE BOTGAL
    backward(1500,2800);
    left(2000,900);
    forward(2000,1200);
    left(1500,1000); // TURN TO FACE DOUBLE RED POMS
    forward_to_black(2000, LINE);
    forward(2000,2350);
    move_servo_slowly(ARM, ARM_DOWN);
    move_servo_slowly(CLAW, CLAW_OPEN); // DROP AND SCORE BOTGAL
	arm_up();
    
    // ====================BOTGALL SCORED!!====================
    
    backward_to_black(1500,LINE);
    backward(2000,4200);//alignment against back bump
    
    right(1500,850);
    forward(2000,3900);
    left(1000,600);
    forward_to_black(1000,LINE);
    forward(1500,2000);//score first red pom
    close_claw();
    backward(1000,3150);
    right(500,750);
    forward(1000,3550);//get second red pom
    move_servo_slowly(ARM, ARM_MAX);
    right(500,2750);
    forward(1000,1700);
    right(500,750);
    forward(1000,1000);//score second red pom
    backward(1000,2000);
    left(500,1200);
    open_claw();
    forward(1000,2650);
    left(500,750);
    move_servo_slowly(ARM, ARM_UP);
    forward(1000,1500);
    backward(500,500);
    left(500,250);
    forward(500,500);
    move_servo_slowly(CLAW, 857);
    move_servo_slowly(ARM, ARM_MAX);
    //FIRST YELLOW CUBE
	backward(2000,2500);
    right(500,1775);
    forward(2000,665);
    right(1000,1000);
    forward(1000,500);
    move_servo_slowly(ARM, ARM_DOWN);
    move_servo_slowly(CLAW, CLAW_OPEN);
    arm_up();//place first yellow cube
    right(2000,1000);
    backward(2000,2000);
    right(1000,300);
    forward(2000,5500);
    right(1000,150);
    set_servo_position(ARM, 1298);
    move_servo_slowly(CLAW, 828);
    arm_up();
    backward(2000,2300);
    right(1000,1700);
    forward(1000,900);
    right(1000,1000);
    forward(1000,450);
    set_servo_position(ARM, 971);//place second yellow cube
    
    return 0;
    }