#ifndef _motorcontrollaw_h_
#define _motorcontrollaw_h_
#include "Motor.h"
#include "Photosensor.h"

//Speed adjustment variables per bot 
#define RNEGADJUST 0
#define LNEGADJUST 0

#include <stdint.h>

class MotorControlLaw{

public:
    MotorControlLaw(Motor leftMotor, Motor rightMotor, Photosensor leftSensor, Photosensor rightSensor);

    void stop();
    void update();
private:
    Motor _leftMotor;
    Motor _rightMotor;
    Photosensor _leftSensor;
    Photosensor _rightSensor;
};

#endif
