#ifndef _motor_h_
#define _motor_h_

#include <stdint.h>

#include "Arduino.h"

#define FWDDIR 0
#define REVDIR 1
#define FWDBASE 215
#define REVBASE 40

class Motor {
public:
    //Constructor function (builds the object)
    Motor(uint8_t dirPin, uint8_t stepPin);

    //Sets the limits for speed, upper and lower
    void setLimits(uint8_t flower, uint8_t fupper, uint8_t blower, uint8_t bupper);

    //Motor commands
    void stop();

    // speeds range between 0 and 255
    void forward(uint8_t speed);
    void reverse(uint8_t speed);

private:
    void setSpeedAndDir(uint8_t speed, uint8_t dir);
    uint8_t _dirPin; //direction variable
    uint8_t _stepPin; //speed or power variable
    uint8_t _flower; //FWD lower speed
    uint8_t _fupper; //FWD upper speed
    uint8_t _blower; //BKWD lower speed
    uint8_t _bupper; //BKWD upper speed
    uint8_t _frange;
    uint8_t _brange;
};

#endif
