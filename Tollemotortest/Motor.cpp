#include "Motor.h"

Motor::Motor(uint8_t dirPin, uint8_t stepPin)
{
    _dirPin = dirPin;
    _stepPin = stepPin;
    
    // if making a motor class, does it make sense to have this here?
    
    
    pinMode(_dirPin, OUTPUT);
    pinMode(_stepPin, OUTPUT);
}

void Motor::stop()
{
    digitalWrite(_dirPin, 0);
    analogWrite(_stepPin, 0);  
}

void Motor::forward(uint8_t speed)
{
    setSpeedAndDir(speed, FWDDIR);
}

void Motor::reverse(uint8_t speed)
{
    setSpeedAndDir(speed, REVDIR);
}

void Motor::setSpeedAndDir(uint8_t speed, uint8_t dir)
{
    if (speed > 100)
        return;
    
    switch (dir) {
        case FWDDIR:
            digitalWrite(_dirPin, FWDDIR);
            analogWrite(_stepPin, FWDBASE-speed);
            break;
        case REVDIR:
            digitalWrite(_dirPin, REVDIR);
            analogWrite(_stepPin, REVBASE-speed);
            break;
        default:
            break;
    }
}
