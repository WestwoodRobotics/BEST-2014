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
 * task_run_drivemode
 * run the robot in drive mode
 */
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

/*
 * task_flag_mode_chicken
 * run the robot in chicken handling mode
 */
task task_flag_mode_chicken(){
		taskRunning = true;

		taskRunning = false;
}

/*
 * task_flag_mode_blade
 * run the robot in blade pickup mode
 */
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
