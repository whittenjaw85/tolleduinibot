#include "calibration_functions.h"
#include "menu_helpers.h"
#include "motor.h"

// create motor structure instances
struct Motor leftMotor = { LEFTMOTORDIR, LEFTMOTORPWR };
struct Motor rightMotor = { RIGHTMOTORDIR, RIGHTMOTORPWR };

#define LEDPIN 7

void blinkLed()
{
    pinMode(LEDPIN, OUTPUT);
    int i;
    for(i = 0; i < 10; i++) {
        digitalWrite(LEDPIN, HIGH);
        delay(100);
        digitalWrite(LEDPIN, LOW);
        delay(100);
      }
}
void setup() {
    blinkLed();
    // put your setup code here, to run once:
    Serial.begin(9600);
    
    // slow PWM frequency down
    TCCR2B = TCCR2B & 0b1111100 | 0x02;
    
    motor_setup(leftMotor);
    motor_setup(rightMotor);
}

void loop() {
    int choice_array_length = 4;
    
    int motor_choices[4] = {'l','L','r','R'};
    int direction_choices[4] = {'f','F','r','R'};
    int min_max_choices[4] = {'u', 'U', 'l', 'L'};
    
    int motor_choice = 0;
    int direction_choice = 0;
    int min_max_choice = 0;
    
    motor_choice = prompt("Which motor to calibrate? [L(eft)/R(ight)]: ", motor_choices, choice_array_length);
    direction_choice = prompt("Which direction to calibrate? [F(orward)/R(everse)]: ", direction_choices, choice_array_length);
    min_max_choice = prompt("Calibrate upper or lower bound? [U(pper)/L(ower)]: ", min_max_choices, choice_array_length);
    
    // Left, Upper (Max), Forward
    if ( ((motor_choice == '1') ||(motor_choice == 'L')) &&
         ((min_max_choice == 'u') || (min_max_choice == 'U')) && 
         ((direction_choice == 'f') || (direction_choice == 'F'))) {
           calibrateMaxForward(leftMotor);
    }
    
    // Left, Lower (Min), Forward
    else if ( ((motor_choice == '1') || (motor_choice == 'L')) &&
         ((min_max_choice == 'l') || (min_max_choice == 'L')) && 
         ((direction_choice == 'f') || (direction_choice == 'F'))) {
           calibrateMinForward(leftMotor);
    }
    
    // Left, Upper (Max), Reverse
    else if ( ((motor_choice == '1') || (motor_choice == 'L')) &&
         ((min_max_choice == 'u') || (min_max_choice == 'U')) && 
         ((direction_choice == 'r') || (direction_choice == 'R'))) {
           calibrateMaxReverse(leftMotor);
    }
    
    // Left, Lower (Min), Reverse
    
    else if ( ((motor_choice == '1') || (motor_choice == 'L')) &&
         ((min_max_choice == 'l') || (min_max_choice == 'L')) && 
         ((direction_choice == 'r') || (direction_choice == 'R'))) {
           calibrateMinReverse(leftMotor);
    }
    
    // Right, Upper (Max), Forward
    else if ( ((motor_choice == 'r') || (motor_choice == 'R')) &&
         ((min_max_choice == 'u') || (min_max_choice == 'U')) && 
         ((direction_choice == 'f') || (direction_choice == 'F'))) {
           calibrateMaxForward(rightMotor);
    }
    
    // Right, Lower (Min), Forward
    else if ( ((motor_choice == 'r') || (motor_choice == 'R')) &&
         ((min_max_choice == 'l') || (min_max_choice == 'L')) && 
         ((direction_choice == 'f') || (direction_choice == 'F'))) {
           calibrateMinForward(rightMotor);
    }
    
    // Right, Upper (Max), Reverse
    else if ( ((motor_choice == 'r') || (motor_choice == 'R')) &&
         ((min_max_choice == 'u') || (min_max_choice == 'U')) && 
         ((direction_choice == 'r') || (direction_choice == 'R'))) {
           calibrateMaxReverse(rightMotor);
    }
    
    // Right, Lower (Min), Reverse
    
    else if ( ((motor_choice == 'r') || (motor_choice == 'R')) &&
         ((min_max_choice == 'l') || (min_max_choice == 'L')) && 
         ((direction_choice == 'r') || (direction_choice == 'R'))) {
           calibrateMinReverse(rightMotor);
    }
    
    else {
        Serial.print("Invalid menu choices ");
        Serial.print((char)motor_choice);
        Serial.print(",");
        Serial.print((char)direction_choice);
        Serial.print(",");
        Serial.println((char)min_max_choice);
    }
}
