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