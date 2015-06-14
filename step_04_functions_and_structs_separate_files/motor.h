#ifndef _motor_h_
#define _motor_h_

#include <stdint.h>

#include "Arduino.h"

// define some constants for motor direction and speed
#define FWDDIR 1
#define REVDIR 0
#define FWDBASE 215 
#define REVBASE 40 

// define some constants to represent pins
#define MOTOR1DIR 12
#define MOTOR1STEP 9 //PWM
#define MOTOR2DIR 13
#define MOTOR2STEP 10 //PWM

#define LEFT_PHOTOSENSOR A0
#define RIGHT_PHOTOSENSOR A1

// declare a structure to hold motor pin values
struct Motor {
    uint8_t dir_pin;
    uint8_t step_pin;
};

void motor_setup(struct Motor motor);
void motor_reverse(struct Motor motor, uint8_t speed);
void motor_forward(struct Motor motor, uint8_t speed);

#endif
