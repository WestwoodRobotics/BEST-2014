#pragma config(Sensor, in1,    rotPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  heightSwitch,   sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           armUDMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           servoClamp,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           servoClaw,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           armLRMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed, driveRight)

#include "defs.h"
#include "drive.c"
#include "tasks.c"
#include "actions.c"

/*
 * main
 * main function of the robot
 */
task main(){
    while(true){

        //Check if we should drive with slow sleeds.
        slow = 1.0 - (vexRT[JOY_BTN_SLOW] * SLOW_SPEED_MULTIPLIER);

        //Call to the drive methods
        arcadeDrive();
        moveBtns();

        //Call the Arm control method
        runArm();
        //Call the Calw control method
        runClaw();

        //If we are pushing our special button
        //Set the arm motor to move to the pre-defined position
        if(vexRT[JOY_BTN_MOVE_POINT]) startTask(moveToHeight, kDefaultTaskPriority);

    }
}
