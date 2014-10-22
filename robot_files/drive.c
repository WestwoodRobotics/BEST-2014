#include "config.h"

float move, rot;
float ud6;

/*
 * tank
 * drive the robot in tank mode.
 */
void tankDrive(){
    motor[leftMotor] = DEADBAND(vexRT[JOY_AXIS_MOTOR_LEFT]) * slow;
    motor[rightMotor] = DEADBAND(vexRT[JOY_AXIS_MOTOR_RIGHT]) * slow;
}

/*
 * arcade
 * drive the robot in arcade mode.
 */
void arcadeDrive(){
    move = DEADBAND(vexRT[JOY_AXIS_DRIVE]) * slow;
    rot = DEADBAND(vexRT[JOY_AXIS_ROTATE]) * slow;

    motor[leftMotor] = move + rot;
    motor[rightMotor] = move - rot;
}

/*
 * moveBtns
 * drive the robot with buttons.
 */
void moveBtns(){
    ud6 = vexRT[JOY_BTN_FORWARD] - vexRT[JOY_BTN_REVERSE];

    if(ud6 != 0.0){
        motor[leftMotor] = ud6 * BTN_MOVE_SPEED * slow;
        motor[rightMotor] = ud6 * BTN_MOVE_SPEED * slow;
    }
}