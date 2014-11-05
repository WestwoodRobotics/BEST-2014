#pragma config(Sensor, dgtl1,  bottomHeightSwitch,   sensorTouch)
#pragma config(Sensor, dgtl2,  clampHitSwitch,       sensorTouch)
#pragma config(Motor,  port2,           leftMotor,       tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port3,           armUDMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           servoFlagDrive,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           servoClamp,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           servoFlagMode,   tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           armLRMotor,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           rightMotor,      tmotorServoContinuousRotation, openLoop, driveRight)

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
    startTask(task_run_drivemode);
    while(true){

        //Check if we should drive with slow sleeds.
        slow_multiplier = 1.0 - (vexRT[JOY_BTN_SLOW] * SLOW_SPEED_MULTIPLIER);

        //Check if we should switch the drivemode
        checkSwitchDrivemode();

        checkSwitchFlagMode();

        //Call the Arm control method
        runArm();
        //Call the Calw control method
        runClamp();

    }
}
