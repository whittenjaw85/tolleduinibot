#ifndef _motor_h_
#define _motor_h_

#include <stdint.h>

#include "Arduino.h"

#define FWDDIR 1
#define REVDIR 0
#define FWDBASE 215 
#define REVBASE 40 

class Motor {
public:
    Motor(uint8_t dirPin, uint8_t stepPin);
    void stop();
    // speeds range between -128 and 127
    void forward(uint8_t speed);
    void reverse(uint8_t speed);
    void setSpeedAndDir(uint8_t speed, uint8_t dir);
private:
    uint8_t _dirPin;
    uint8_t _stepPin;
};

#endif
