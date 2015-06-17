#include "Motor.h"
#include "Photosensor.h"

#define LEFTSENSOR A0
#define RIGHTSENSOR A1 

#define LEFTMOTORDIR 12
#define LEFTMOTORSTEP 9 //PWM
#define RIGHTMOTORDIR 13
#define RIGHTMOTORSTEP 10 //PWM

uint16_t leftsensor_base;
uint16_t rightsensor_base;

Photosensor ps_left = Photosensor(LEFTSENSOR);
Photosensor ps_right = Photosensor(RIGHTSENSOR);

Motor motor_right = Motor(RIGHTMOTORDIR, RIGHTMOTORSTEP);
Motor motor_left = Motor(LEFTMOTORDIR, LEFTMOTORSTEP);

void setup(){
    //Slow PWM frequency down
    TCCR2B = TCCR2B&0b1111100|0x02; //from arduino

    //set pin modes
    pinMode(LEFTMOTORDIR, OUTPUT);
    pinMode(LEFTMOTORSTEP, OUTPUT);
    pinMode(RIGHTMOTORDIR, OUTPUT);
    pinMode(RIGHTMOTORSTEP, OUTPUT);

    leftsensor_base = ps_left.read() + 50;
    rightsensor_base = ps_right.read() + 50;
}

void loop(){
    if( ps_right.read() > rightsensor_base){
        motor_right.reverse(20);
    }else{
        motor_right.forward(10);
    }

    if(ps_left.read() > leftsensor_base){
        motor_left.reverse(20);
    }else{
        motor_left.forward(10);
    }
    delay(10);
}
