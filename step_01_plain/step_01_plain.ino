
#include "Arduino.h"
#include <stdint.h>

// define some constants for motor direction and speed
#define FWDDIR 1
#define REVDIR 0
#define FWDBASE 215 
#define REVBASE 40 

// define some constants to represent pins
#define MOTOR1DIR 12
#define MOTOR1STEP 9 //PWM
#define MOTOR2DIR 13
#define MOTOR2STEP 10 //PWM

#define LEFT_PHOTOSENSOR A0
#define RIGHT_PHOTOSENSOR A1

void setup() {
    // slow PWM frequency down
    TCCR2B = TCCR2B&0b1111100|0x02;
    
    // here we configure pins for motor operation
    pinMode(MOTOR1DIR, OUTPUT);
    pinMode(MOTOR1STEP,OUTPUT);
    pinMode(MOTOR2DIR, OUTPUT);
    pinMode(MOTOR2STEP,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    // create variables to hold the values for the sensors
    uint16_t leftSensor, rightSensor;
    leftSensor = (uint16_t) analogRead(LEFT_PHOTOSENSOR);
    rightSensor = (uint16_t) analogRead(RIGHT_PHOTOSENSOR);
    if (rightSensor > leftSensor) {
        // make motor 1 go forward
        digitalWrite(MOTOR1DIR, FWDDIR);
        analogWrite(MOTOR1STEP, FWDBASE - 30);
        
        // make motor 2 go in reverse
        digitalWrite(MOTOR2DIR, REVDIR);
        analogWrite(MOTOR2STEP, REVBASE + 30);
    } else {
        // make motor 1 go in reverse
        digitalWrite(MOTOR1DIR, REVDIR);
        analogWrite(MOTOR1STEP, REVBASE + 30);
        
        // make motor 2 go forward
        digitalWrite(MOTOR2DIR, FWDDIR);
        analogWrite(MOTOR2STEP, FWDBASE - 30);
    }
    delay(100);
}
