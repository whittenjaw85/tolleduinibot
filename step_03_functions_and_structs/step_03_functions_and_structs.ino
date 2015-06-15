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

// declare a structure to hold motor pin values
struct Motor {
    uint8_t dir_pin;
    uint8_t step_pin;
};

// motor control functions
void motor_setup(struct Motor motor)
{
    // here we configure pins for motor operation
    pinMode(motor.dir_pin, OUTPUT);
    pinMode(motor.step_pin,OUTPUT);
}

void motor_reverse(struct Motor motor, uint8_t speed)
{
    if (speed > 100) {
        return;
    }
    
    digitalWrite(motor.dir_pin, REVDIR);
    analogWrite(motor.step_pin, REVBASE + speed);
}

void motor_forward(struct Motor motor, uint8_t speed)
{
    if (speed > 100) {
        return;
    }
    
    digitalWrite(motor.dir_pin, FWDDIR);
    analogWrite(motor.step_pin, FWDBASE - speed);
}

// create motor structure instances
struct Motor motor1 = { MOTOR1DIR, MOTOR1STEP };
struct Motor motor2 = { MOTOR2DIR, MOTOR2STEP };


void setup() {
    // slow PWM frequency down
    TCCR2B = TCCR2B & 0b1111100 | 0x02;    
    
    motor_setup(motor1);
    motor_setup(motor2);
}

void loop() {
    // create variables to hold the values for the sensors
    uint16_t leftSensor, rightSensor;
    leftSensor = (uint16_t) analogRead(LEFT_PHOTOSENSOR);
    rightSensor = (uint16_t) analogRead(RIGHT_PHOTOSENSOR);
    if (rightSensor > leftSensor) {
        motor_forward(motor1, 30);
        motor_reverse(motor2, 30);
    } else {
        motor_reverse(motor1, 30);
        motor_forward(motor2, 30);
    }
    delay(100);
}
