/*
 * moveToHeight
 * move the arm to the needed height
 */
task task_move_to_height(){
    while(true){
        motor[armUDMotor] = -127;
        if(SensorValue[heightSwitch] != 0.0){
            motor[armUDMotor] = 0;
            break;
        }
    }
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

task task_drive_arcade(){
    while(true){
        arcadeDrive();
    }
}

task task_drive_tank(){
    while(true){
        tankDrive();
    }
}