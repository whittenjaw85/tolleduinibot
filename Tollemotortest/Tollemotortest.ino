/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
 #define MOTOR1DIR 12
 #define MOTOR1STEP 9
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 7;
int val = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  pinMode(MOTOR1DIR, OUTPUT);
  TCCR2B = TCCR2B &0b1111100|0x02;
  digitalWrite(MOTOR1DIR, LOW); 
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
  val = 35;
  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  //digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(500);               // wait for a second
  //digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //delay(500); 
/*  // wait for a second
  char r = 0;
  if(Serial.available()){
    r = Serial.read();
    if(r == 'u')
      val += 1;
    else if(r=='d')
      val -= 1;
      */
    val = (val+1)%140;
    if(val == 0) val = 40;
    analogWrite(MOTOR1STEP, val);
    delay(50);
  
}
  
