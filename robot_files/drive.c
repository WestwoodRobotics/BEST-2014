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
