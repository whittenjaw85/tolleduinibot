#include "BotSupervisor.h"
 

 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#define LED 7

BotSupervisor botSupervisor;

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
    botSupervisor.update();
    delay(100);
}
  
