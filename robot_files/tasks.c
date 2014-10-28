/*
 * moveToHeight
 * move the arm to the needed height
 */
task task_move_to_height(){
    moveHeightTaskRunning = true;
    bool runTaskRun = true;
    while(runTaskRun){
        motor[armUDMotor] = -127;
        if(SensorValue[heightSwitch] != 0.0){
            motor[armUDMotor] = 0;
            runTaskRun = false;
        }
    }
    moveHeightTaskRunning = false;
}

task task_run_drivemode(){
    while(true){
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
        }
    }
}
