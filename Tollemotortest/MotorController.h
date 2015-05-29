#ifndef _motorcontroller_h_
#define _motorcontroller_h_

//Speed adjustment variables per bot 
#define RNEGADJUST 0
#define LNEGADJUST 0

#define FWDDIR 1
#define REVDIR 0
#define FWDBASE 215 
#define REVBASE 40 

#include <stdint.h>

class MotorController{

public:
    MotorController(uint8_t motor1dir, uint8_t motor1step, uint8_t motor2dir, uint8_t motor2step);

    void stop();
    void stopMotor1();
    void stopMotor2();
    //Speeds range from -128 to 127
    void setMotor1(uint8_t speed, uint8_t dir);
    void setMotor2(uint8_t speed, uint8_t dir);

private:

    uint8_t motor1dir_pin;
    uint8_t motor1step_pin;
    uint8_t motor2dir_pin;
    uint8_t motor2step_pin;

    uint8_t speedL;
    uint8_t speedR;

};

#endif
