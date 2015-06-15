
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

void motor_setup(uint8_t motor_dir_pin, uint8_t motor_step_pin)
{
    // here we configure pins for motor operation
    pinMode(MOTOR1DIR, OUTPUT);
    pinMode(MOTOR1STEP,OUTPUT);
}

void motor_reverse(uint8_t motor_dir_pin, uint8_t motor_step_pin, uint8_t speed)
{
    if (speed > 100) {
        return;
    }
    
    digitalWrite(motor_dir_pin, REVDIR);
    analogWrite(motor_step_pin, REVBASE + speed);
}

void motor_forward(uint8_t motor_dir_pin, uint8_t motor_step_pin, uint8_t speed)
{
    if (speed > 100) {
        return;
    }
    
    digitalWrite(motor_dir_pin, FWDDIR);
    analogWrite(motor_step_pin, FWDBASE - speed);
}

void setup() {
    // slow PWM frequency down
    TCCR2B = TCCR2B & 0b1111100 | 0x02;
    
    motor_setup(MOTOR1DIR, MOTOR1STEP);
    motor_setup(MOTOR2DIR, MOTOR2STEP);
}

void loop() {
    // create variables to hold the values for the sensors
    uint16_t leftSensor, rightSensor;
    leftSensor = (uint16_t) analogRead(LEFT_PHOTOSENSOR);
    rightSensor = (uint16_t) analogRead(RIGHT_PHOTOSENSOR);
    if (rightSensor > leftSensor) {
        motor_forward(MOTOR1DIR, MOTOR1STEP, 30);
        motor_reverse(MOTOR2DIR, MOTOR2STEP, 30);
    } else {
        motor_reverse(MOTOR1DIR, MOTOR1STEP, 30);
        motor_forward(MOTOR2DIR, MOTOR2STEP, 30);
    }
    delay(100);
}
