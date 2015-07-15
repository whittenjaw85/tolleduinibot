#ifndef _menu_helpers_h_
#define _menu_helpers_h_
#include "Arduino.h"

int valid_response(int response, int* valid_answers, int array_len);
char prompt(char* p, int* valid_answers, int array_len);

#endif
