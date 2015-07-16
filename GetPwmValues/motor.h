#ifndef _motor_h_
#define _motor_h_

#include <stdint.h>
#include "Arduino.h"

// define some constants to represent pins
#define LEFTMOTORDIR 12
#define RIGHTMOTORDIR 13
#define LEFTMOTORPWR 9
#define RIGHTMOTORPWR 10

#define FWD_FULL_ON 255
#define FWD_OFF 0

#define REV_FULL_ON FWD_OFF
#define REV_OFF FWD_FULL_ON

#define FWDDIR 0
#define REVDIR 1

// declare a structure to hold motor pin values
struct Motor {
    uint8_t dir_pin;
    uint8_t step_pin;
};

void motor_setup(struct Motor motor);

#endif
