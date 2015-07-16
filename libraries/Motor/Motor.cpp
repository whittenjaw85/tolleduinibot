#include "Motor.h"

Motor::Motor(uint8_t dirPin, uint8_t stepPin)
{
    _dirPin = dirPin;
    _stepPin = stepPin;
    _flower = 25;
    _fupper = 70;
    _blower = 25;
    _bupper = 70;
    _frange = _fupper - _flower;
    _brange = _bupper - _blower;

    pinMode(_dirPin, OUTPUT);
    pinMode(_stepPin, OUTPUT);
}

void Motor::setLimits(uint8_t flower, uint8_t fupper, uint8_t blower, uint8_t bupper){
    _flower = flower;
    _fupper = fupper;
    _frange = fupper - flower;
    _blower = blower;
    _bupper = bupper;
    _brange = bupper - blower;
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
    /* it was important to set the value of the FWDDIR to 0 and
     * REVDIR to 1 in order to ensure that the logic made sense
     * for the analogWrite functions. When one Hbridge pin is low,
     * the natural effect is for power to be delivered at the high
     * pulse of the paired leg. When the Hbridge pin is high, power
     * is delivered at the lowside of the pulse.
     * Speed is an absolute value because direction is set with a
     * separate variable. Speed at zero is NOT stopped, is the minimum
     * amount of motion. Stopping the driver should be done with the
     * stop() funtion.  */
    switch (dir) {
        case FWDDIR:
            if(speed > _frange)
                speed = _frange;

            digitalWrite(_dirPin, FWDDIR);
            analogWrite(_stepPin,  _flower + speed);
            break;
        case REVDIR:

            if(speed > _brange)
                speed = _brange;

            digitalWrite(_dirPin, REVDIR);
            analogWrite(_stepPin, 255 - _blower - speed);
            break;
        default:
            break;
    }
}
