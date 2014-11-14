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

#ifndef H_CONFIG
#define H_CONFIG
#define DEADBAND_THRESHOLD 10.0

#define DEADBAND(x)((abs(x) >= DEADBAND_THRESHOLD) ? x : 0.0)

#define BTN_MOTOR_SPEED 127
#define BTN_MOVE_SPEED 128

#define CLAMP_OPEN_DISTANCE 110

#define SLOW_SPEED_MULTIPLIER 0.65

#define JOY_AXIS_MOTOR_LEFT Ch3
#define JOY_AXIS_MOTOR_RIGHT Ch2
#define JOY_AXIS_DRIVE Ch3
#define JOY_AXIS_ROTATE Ch1

#define JOY_BTN_SLOW Btn5U
#define JOY_BTN_MODE_RUN Btn5D
#define JOY_BTN_TOGGLE_DRIVEMODE Btn6U
#define JOY_BTN_TOGGLE_FLAGMODE Btn6D
#define JOY_BTN_CLAMP_OPEN Btn7U
#define JOY_BTN_CLAMP_CLOSE Btn7D
#define JOY_BTN_HITCH_UP Btn7R
#define JOY_BTN_HITCH_DOWN Btn7L
#define JOY_BTN_ARM_UP Btn8U
#define JOY_BTN_ARM_DOWN Btn8D
#define JOY_BTN_ARM_RIGHT Btn8R
#define JOY_BTN_ARM_LEFT Btn8L

float slow_multiplier;

typedef enum TDriveMode {
    DRIVE_NONE = 0,
    DRIVE_ARCADE = 1,
    DRIVE_TANK = 2,
    DRIVE_MAX = 3
} TDriveMode;

TDriveMode currentDrivemode = DRIVE_ARCADE;

typedef enum TFlagMode {
    FLAG_NONE = 0,
    FLAG_CHICKEN = 1,
    FLAG_BLADE = 2,
    FLAG_MAX = 3
} TFlagMode;

float flagModeServo[FLAG_MAX] = {0, 50, 100};
float flagDriveServo[DRIVE_MAX] = {0, 50, 110};

bool taskRunning = false;

TFlagMode currentFlagMode = FLAG_CHICKEN;

#endif
