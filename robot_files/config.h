#ifndef H_CONFIG
#define H_CONFIG
#define DEADBAND_THRESHOLD 10.0

#define DEADBAND(x)((abs(x) >= DEADBAND_THRESHOLD) ? x : 0.0)

#define BTN_MOTOR_SPEED 127
#define BTN_MOVE_SPEED 128

#define SLOW_SPEED_MULTIPLIER 0.65

#define JOY_AXIS_MOTOR_LEFT Ch3
#define JOY_AXIS_MOTOR_RIGHT Ch2
#define JOY_AXIS_DRIVE Ch3
#define JOY_AXIS_ROTATE Ch1

#define JOY_BTN_SLOW Btn5U
#define JOY_BTN_MOVE_POINT Btn5D
#define JOY_BTN_TOGGLE_DRIVEMODE Btn6U
#define JOY_BTN_FORWARD Btn6U
#define JOY_BTN_REVERSE Btn6D
#define JOY_BTN_CLAMP_OPEN Btn7U
#define JOY_BTN_CLAMP_CLOSE Btn7D
#define JOY_BTN_CLAW_OPEN Btn7R
#define JOY_BTN_CLAW_CLOSE Btn7L
#define JOY_BTN_ARM_UP Btn8U
#define JOY_BTN_ARM_DOWN Btn8D
#define JOY_BTN_ARM_RIGHT Btn8R
#define JOY_BTN_ARM_LEFT Btn8L

float slow;

typedef enum TDriveMode {
    DRIVE_ARCADE = 1,
    DRIVE_TANK = 2,
    DRIVE_MAX = 3
} TDriveMode;

TDriveMode currentDrivemode = DRIVE_ARCADE;

bool moveHeightTaskRunning = false;

#endif
