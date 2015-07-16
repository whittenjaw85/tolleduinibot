#include "calibration_functions.h"

void calibrateMinForward(struct Motor motor)
{
    uint8_t hard_stop = FWD_OFF;
    uint8_t stopped = FWD_OFF;
    uint8_t distance = 255;
    uint8_t last_yes = 0;
    int valid_responses[4] = {'y','Y','n','N'};
    int response_array_length = 4;
    int response = 0;
    uint8_t pwm_value;
    digitalWrite(motor.dir_pin, FWDDIR);
    do {
        distance >>= 1; // divide by 2
        pwm_value = stopped + distance;
        analogWrite(motor.step_pin, pwm_value);
        delay(1000);
        analogWrite(motor.step_pin, hard_stop);
        response = prompt("Did motor move? [Y(es)/N(o)]: ",valid_responses, response_array_length);
        if (response == 'y' || response == 'Y') {
            last_yes = pwm_value;
        } else if (response == 'n' || response == 'N') {
            stopped = pwm_value;
        }
        delay(1000);
    } while (distance > 0);
    
    Serial.print("Pwm value: ");
    Serial.println(last_yes);
}

void calibrateMaxForward(struct Motor motor)
{
    int i;
    digitalWrite(motor.dir_pin, FWDDIR);
    for (i = 128; i < 256; i++) {
      Serial.print("Pwm value: ");
      Serial.println(i);
      analogWrite(motor.step_pin, i);
      delay(1500);
    }
    analogWrite(motor.step_pin, 255);
}

void calibrateMinReverse(struct Motor motor)
{
    uint8_t hard_stop = REV_OFF;
    uint8_t stopped = REV_OFF;
    uint8_t distance = 255;
    uint8_t last_yes = 0;
    int valid_responses[4] = {'y','Y','n','N'};
    int response_array_length = 4;
    int response = 0;
    uint8_t pwm_value;
    digitalWrite(motor.dir_pin, REVDIR);
    do {
        distance >>= 1; // divide by 2
        pwm_value = stopped - distance;
        analogWrite(motor.step_pin, pwm_value);
        delay(1000);
        analogWrite(motor.step_pin, hard_stop);
        response = prompt("Did motor move? [Y(es)/N(o)]: ",valid_responses, response_array_length);
        if (response == 'y' || response == 'Y') {
            last_yes = pwm_value;
        } else if (response == 'n' || response == 'N') {
            stopped = pwm_value;
        }
    } while (distance > 0);
    
    Serial.print("Pwm value: ");
    Serial.println(last_yes);
}

void calibrateMaxReverse(struct Motor motor)
{
    int i;
    digitalWrite(motor.dir_pin, REVDIR);
    for (i = 128; i > -1; i--) {
      Serial.print("Pwm value: ");
      Serial.println(i);
      analogWrite(motor.step_pin, i);
      delay(1500);
    }
    analogWrite(motor.step_pin, 0);
}
