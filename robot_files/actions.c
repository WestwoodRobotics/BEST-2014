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
		float ud8 = vexRT[JOY_BTN_ARM_UP] - vexRT[JOY_BTN_ARM_DOWN];
    if(!SensorValue[bottomHeightSwitch] && ud8 < 0) ud8 = 0;
    //if(!SensorValue[topHeightSwitch && ud8 > 0) ud8 = 0;
    motor[armUDMotor] = ud8 * BTN_MOTOR_SPEED;
}

/*
 * runClaw
 * control the claw
 */
void runClaw(){
	  float ud7, lr7;
    ud7 = vexRT[JOY_BTN_CLAMP_OPEN] - vexRT[JOY_BTN_CLAMP_CLOSE];
    lr7 = vexRT[JOY_BTN_CLAW_OPEN] - vexRT[JOY_BTN_CLAW_CLOSE];
    if(ud7 != 0.0) motor[servoClamp] = ud7 * 110;
    if(lr7 != 0.0) motor[servoClaw] = lr7 * 127;
}
