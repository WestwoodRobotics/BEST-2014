#pragma config(Sensor, in1,    rotPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  heightSwitch,   sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           armUDMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           servoClamp,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           servoClaw,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           armLRMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed, driveRight)

/*
 * Copyright (c) 2014 Westwood Robotics <code.westwoodrobotics@gmail.com>.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 */

#include "config.h"
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
        tankDrive();
        moveBtns();

        //Call the Arm control method
        runArm();
        //Call the Calw control method
        runClaw();

        //If we are pushing our special button
        //Set the arm motor to move to the pre-defined position
        if(vexRT[JOY_BTN_MOVE_POINT]) startTask(task_move_to_height, kDefaultTaskPriority);

    }
}
