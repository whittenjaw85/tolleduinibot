#include "motor.h"

void motor_setup(struct Motor motor)
{
    // here we configure pins for motor operation
    pinMode(motor.dir_pin, OUTPUT);
    pinMode(motor.step_pin,OUTPUT);
}
