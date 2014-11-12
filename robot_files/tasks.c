task task_run_drivemode(){
   while(true){
     		if(!taskRunning){
	        //Call to the drive methods
	        switch (currentDrivemode) {
	        case DRIVE_ARCADE:
	            arcadeDrive();
	            break;
	        case DRIVE_TANK:
	            tankDrive();
	            break;
	        default:
	            tankDrive();
	            break;
	        }
	     }
    }
}

task task_flag_mode_chicken(){
		taskRunning = true;

		taskRunning = false;
}

task task_flag_mode_blade(){
		taskRunning = true;

		motor[servoClamp] = CLAMP_OPEN_DISTANCE;

		motor[armUDMotor] = -1 * BTN_MOTOR_SPEED;
		while(!SensorValue[bottomHeightSwitch]){
				if(vexRT[JOY_BTN_MODE_RUN])
						return;
		}
		motor[armUDMotor] = 0;

		motor[leftMotor] = BTN_MOVE_SPEED;
		motor[rightMotor] = -1 * BTN_MOVE_SPEED;
		while(SensorValue[bottomHeightSwitch]){
				if(vexRT[JOY_BTN_MODE_RUN])
						return;
		}
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;

		motor[armUDMotor] = -127;
		while(!SensorValue[bottomHeightSwitch]){
				if(vexRT[JOY_BTN_MODE_RUN])
						return;
		}
		motor[armUDMotor] = 0;

		motor[servoClamp] = -1 * CLAMP_OPEN_DISTANCE;

		taskRunning = false;
}
