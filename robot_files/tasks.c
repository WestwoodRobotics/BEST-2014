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
            break;
        }
    }
}

task task_flag_mode_chicken(){

}

task task_flag_mode_blade(){
    
}