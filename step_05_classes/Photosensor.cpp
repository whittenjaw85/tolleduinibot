#include "Photosensor.h"

Photosensor::Photosensor(uint8_t pin){
    _pin = pin;
}

uint16_t Photosensor::read(){
    return ((uint16_t)(analogRead(_pin)));
}
