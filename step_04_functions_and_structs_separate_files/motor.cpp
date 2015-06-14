#include "motor.h"

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
