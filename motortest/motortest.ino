#include "Motor.h"
#include "IRSensor.h"

#define LEFTSENSOR 3
#define RIGHTSENSOR 2 

#define LEFTMOTORDIR 12
#define LEFTMOTORSTEP 9 //PWM
#define RIGHTMOTORDIR 13
#define RIGHTMOTORSTEP 10 //PWM

uint16_t leftsensor_base;
uint16_t rightsensor_base;

IRSensor ps_left = IRSensor(LEFTSENSOR);
IRSensor ps_right = IRSensor(RIGHTSENSOR);

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

    leftsensor_base = ps_left.readSensor()+200;
    rightsensor_base = ps_right.readSensor()+200;
}

void loop(){
    if( ps_right.readSensor() > rightsensor_base){
        motor_right.reverse(20);
    }else{
        motor_right.forward(10);
    }

    if(ps_left.readSensor() > leftsensor_base){
        motor_left.reverse(20);
    }else{
        motor_left.forward(10);
    }
    delay(10);
}
