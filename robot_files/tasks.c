#include "defs.h"

/*
 * moveToHeight
 * move the arm to the needed height
 */
task moveToHeight(){
    while(true){
        motor[armUDMotor] = -127;
        if(SensorValue[heightSwitch] != 0.0){
            motor[armUDMotor] = 0;
            break;
        }
    }
}