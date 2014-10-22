float ud7, lr7;

/*
 * runArm
 * control the arms
 */
void runArm(){
    motor[armLRMotor] = (vexRT[JOY_BTN_ARM_LEFT] - vexRT[JOY_BTN_ARM_RIGHT]) * BTN_MOTOR_SPEED;
    motor[armUDMotor] = (vexRT[JOY_BTN_ARM_UP] - vexRT[JOY_BTN_ARM_DOWN]) * BTN_MOTOR_SPEED;
}

/*
 * runClaw
 * control the claw
 */
void runClaw(){
    ud7 = vexRT[JOY_BTN_CLAMP_OPEN] - vexRT[JOY_BTN_CLAMP_CLOSE];
    lr7 = vexRT[JOY_BTN_CLAW_OPEN] - vexRT[JOY_BTN_CLAW_CLOSE];
    if(ud7 != 0.0) motor[servoClamp] = ud7 * 127;
    if(lr7 != 0.0) motor[servoClaw] = lr7 * 127;
}