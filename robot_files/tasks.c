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
