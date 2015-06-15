#ifndef _botsupervisor_h_
#define _botsupervisor_h_

#include <stdint.h>

#include "Arduino.h"
#include "Motor.h"
#include "Photosensor.h"

//Speed adjustment variables per bot 
#define RNEGADJUST 0
#define LNEGADJUST 0

// define some constants to represent pins
#define MOTOR1DIR 12
#define MOTOR1STEP 9 //PWM
#define MOTOR2DIR 13
#define MOTOR2STEP 10 //PWM
#define LEFT_PHOTOSENSOR A0
#define RIGHT_PHOTOSENSOR A1



class BotSupervisor{

public:
    BotSupervisor();

    void stop();
    void update();
private:
    Motor _leftMotor;
    Motor _rightMotor;
    Photosensor _leftSensor;
    Photosensor _rightSensor;
};

#endif
