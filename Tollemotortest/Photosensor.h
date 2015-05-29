#ifndef _photosensor_h_
#define _photosensor_h_

#include <stdint.h>

class Photosensor{
public:
    Photosensor(uint8_t pin);
    
    uint16_t read();

private:
    uint8_t pin;
};
#endif
