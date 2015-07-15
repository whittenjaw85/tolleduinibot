#ifndef _calibration_functions_h_
#define _calibration_functions_h_
#include "Arduino.h"
#include "menu_helpers.h"
#include "motor.h"

void calibrateMinForward(struct Motor motor);
void calibrateMaxForward(struct Motor motor);
void calibrateMinReverse(struct Motor motor);
void calibrateMaxReverse(struct Motor motor);

#endif
