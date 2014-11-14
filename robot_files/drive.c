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

/*
 * tank
 * drive the robot in tank mode.
 */
void tankDrive(){
    motor[leftMotor] = DEADBAND(vexRT[JOY_AXIS_MOTOR_LEFT]) * slow_multiplier;
    motor[rightMotor] = DEADBAND(vexRT[JOY_AXIS_MOTOR_RIGHT]) * slow_multiplier;
}

/*
 * arcade
 * drive the robot in arcade mode.
 */
void arcadeDrive(){
    float move = DEADBAND(vexRT[JOY_AXIS_DRIVE]) * slow_multiplier;
    float rot = DEADBAND(vexRT[JOY_AXIS_ROTATE]) * slow_multiplier;

    motor[leftMotor] = move + rot;
    motor[rightMotor] = move - rot;
}
