#include "motor.h"

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
