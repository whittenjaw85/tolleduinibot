/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

#include "MotorControlLaw.h"
 
#define MOTOR1DIR 12
#define MOTOR1STEP 9 //PWM
#define MOTOR2DIR 13
#define MOTOR2STEP 10 //PWM
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#define LED 7

Motor leftMotor(MOTOR1DIR, MOTOR1STEP);
Motor rightMotor(MOTOR2DIR, MOTOR2STEP);
Photosensor leftSensor(A0);
Photosensor rightSensor(A1);
MotorControlLaw controlLaw(leftMotor, rightMotor, leftSensor, rightSensor);

// the setup routine runs once when you press reset:
void setup() {                
    // initialize the digital pin as an output.
    pinMode(LED, OUTPUT);  
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
    controlLaw.update();
    delay(100);
}
  
