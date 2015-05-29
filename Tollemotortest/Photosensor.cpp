#include "Photosensor.h"
#include "Arduino.h"


Photosensor::Photosensor(uint8_t pin){
    this->pin = pin;
}

uint16_t Photosensor::read(){
    return ((uint16_t)(analogRead(this->pin)));
}
