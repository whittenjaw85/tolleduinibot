/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

#include "MotorController.h"
#include "Photosensor.h"
 
#define MOTOR1DIR 12
#define MOTOR1STEP 9 //PWM
#define MOTOR2DIR 13
#define MOTOR2STEP 10 //PWM
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 7;
int val = 0;

MotorController mc = MotorController(MOTOR1DIR, MOTOR1STEP, MOTOR2DIR, MOTOR2STEP);

Photosensor lps = Photosensor(A0);
Photosensor rps = Photosensor(A1);

// the setup routine runs once when you press reset:
void setup() {                
    // initialize the digital pin as an output.
    pinMode(led, OUTPUT);  
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);


}

// the loop routine runs over and over again forever:
void loop() {
    //Read analog values to determine which 
    //is bigger
    static uint16_t right, left;
    right = rps.read();
    left = lps.read();
    if(right > left){
        mc.setMotor1(30, 1);
        mc.setMotor2(30, 0);
    }
    else{
        mc.setMotor1(30, 0);
        mc.setMotor2(30, 1);
    }
    delay(100);
}
  
