#ifndef _irsensor_h
#define _irsensor_h

#include <stdint.h>

#include "Arduino.h"

#define DELAYUSVAL 10

class IRSensor{
    public:
        //Object constructor
        IRSensor(uint8_t pin);

        //Read value from sensor
        int readSensor();

    private:
        uint8_t _pin;
};

#endif
