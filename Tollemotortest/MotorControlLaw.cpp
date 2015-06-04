#include "MotorControlLaw.h"
#include "Arduino.h"

MotorControlLaw::MotorControlLaw(Motor leftMotor, 
  Motor rightMotor, Photosensor leftSensor, 
  Photosensor rightSensor) : 
  _leftMotor(leftMotor), _rightMotor(rightMotor),
  _leftSensor(leftSensor), _rightSensor(rightSensor)
{
    // slow PWM frequency down
    TCCR2B = TCCR2B & 0b1111100 | 0x02;
}

void MotorControlLaw::stop(){
    _leftMotor.stop();
    _rightMotor.stop();
}

void MotorControlLaw::update() {
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

