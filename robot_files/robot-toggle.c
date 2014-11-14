#pragma config(Sensor, dgtl1,  bottomHeightSwitch,   sensorTouch)
#pragma config(Sensor, dgtl2,  leftArmSwitch,        sensorTouch)
#pragma config(Sensor, dgtl3,  rightArmSwitch,       sensorTouch)
#pragma config(Sensor, dgtl4,  clampHitSwitch,       sensorTouch)
#pragma config(Motor,  port2,           leftMotor,       tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port3,           armUDMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           servoFlagDrive,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           servoClamp,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           servoHitch,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           servoFlagMode,   tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           armLRMotor,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           rightMotor,      tmotorServoContinuousRotation, openLoop, driveRight)

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
    initFlags();
    initClamp();
    initHitch();
    startTask(task_run_drivemode);
    while(true){

        //Check if we should drive with slow sleeds.
        slow_multiplier = 1.0 - (vexRT[JOY_BTN_SLOW] * SLOW_SPEED_MULTIPLIER);

        //Check if we should switch the drivemode
        checkSwitchDrivemode();

        checkSwitchFlagMode();

        //Call the Arm control method
        runArm();
        //Call the Claw control method
        runClamp();
		//Call the Hitch control method
        runHitch();
		//Call the task handling method
        checkRunModeTask();
    }
}
