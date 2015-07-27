#include "IRSensor.h"

IRSensor::IRSensor(uint8_t pin){
    this->_pin = pin;
}

int IRSensor::readSensor(){
    pinMode(this->_pin, OUTPUT);
    digitalWrite(this->_pin, HIGH);
    delayMicroseconds(DELAYUSVAL);
    pinMode(this->_pin, INPUT);
    long time = micros();

    while(digitalRead(this->_pin) == HIGH && micros() - time < 3000);
    int diff = micros() - time;

    return diff;
}
