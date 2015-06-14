#include "BotSupervisor.h"

BotSupervisor::BotSupervisor()
{
    // slow PWM frequency down
    TCCR2B = TCCR2B & 0b1111100 | 0x02;
    
    _leftMotor  = Motor(MOTOR1DIR, MOTOR1STEP);
    _rightMotor = Motor(MOTOR2DIR, MOTOR2STEP);
    
    _leftSensor = Photosensor(LEFT_PHOTOSENSOR);
    _rightSensor = Photosensor(RIGHT_PHOTOSENSOR);
}

void BotSupervisor::stop(){
    _leftMotor.stop();
    _rightMotor.stop();
}

void BotSupervisor::update() {
    // Read analog values to determine which 
    // is bigger
    if (_rightSensor.read() > _leftSensor.read()){
        _rightMotor.forward(30);
        _leftMotor.reverse(30);
    } else {
        _rightMotor.reverse(30);
        _leftMotor.forward(30);
    }
}

