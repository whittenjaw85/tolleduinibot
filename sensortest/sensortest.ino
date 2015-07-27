#include "IRSensor.h"

#define IRLEFT 2
#define IRRIGHT 3

IRSensor lsensor = IRSensor(IRLEFT);
IRSensor rsensor = IRSensor(IRRIGHT);

void setup(){
  Serial.begin(9600);  
}

void loop(){
  //read sensors
 int left = lsensor.readSensor();
 int right = rsensor.readSensor();
 
 //print value
 Serial.print("R: ");
 Serial.println(right);
 Serial.print("L: ");
 Serial.println(left);

 delay(1000); 
}
