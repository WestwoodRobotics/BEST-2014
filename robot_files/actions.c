float ud7, lr7;

bool isTogglePressed = false;

/*
 * run drive switch
 * should we switch the drivemode?
 */
void checkSwitchDrivemode(){
    if(vexRT[JOY_BTN_TOGGLE_DRIVEMODE]){
        if(!isTogglePressed){
            isTogglePressed = true;
            currentDrivemode = DRIVE_MAX - currentDrivemode;
        }
    }else{
        isTogglePressed = false;
    }
}

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
