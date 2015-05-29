#include "MotorController.h"
#include "Arduino.h"

MotorController::MotorController(uint8_t motor1dir, uint8_t motor1step, uint8_t motor2dir, uint8_t motor2step){
    this->motor1dir_pin = motor1dir;
    this->motor2dir_pin = motor2dir;
    this->motor1step_pin = motor1step;
    this->motor2step_pin = motor2step;

    //Configure pins
    pinMode(motor1dir, OUTPUT);
    pinMode(motor2dir, OUTPUT);
    pinMode(motor1step, OUTPUT);
    pinMode(motor2step, OUTPUT);

    TCCR2B = TCCR2B&0b1111100|0x02;//slow PWM frequency down

    //Set the initial direction of the wheels forward
    digitalWrite(this->motor1dir_pin, FWDDIR); 
    digitalWrite(this->motor2dir_pin, FWDDIR);
}//End object creation method


void MotorController::setMotor1(uint8_t speed, uint8_t dir){
    if(speed > 100){return;}

    if(dir == FWDDIR){
        digitalWrite(this->motor1dir_pin, FWDDIR);
        analogWrite(this->motor1step_pin, (FWDBASE-speed));
    }
    else if(dir == REVDIR){
        digitalWrite(this->motor1dir_pin, REVDIR);
        analogWrite(this->motor1step_pin, (REVBASE+speed));
    }//end else

    return; //default no action
}//end setMotor1()

void MotorController::setMotor2(uint8_t speed, uint8_t dir){
     if(speed > 100){return;}

    if(dir == FWDDIR){
        digitalWrite(this->motor2dir_pin, FWDDIR);
        analogWrite(this->motor2step_pin, (FWDBASE-speed));
    }
    else if(dir == REVDIR){
        digitalWrite(this->motor2dir_pin, REVDIR);
        analogWrite(this->motor2step_pin, (speed+REVBASE));
    }//end else

    return; //default no action
   
}//end setMotor2()

void MotorController::stop(){
    //set analog write output to zero
    digitalWrite(this->motor1dir_pin, 0);
    analogWrite(this->motor1step_pin, 0);
}//end stop()

