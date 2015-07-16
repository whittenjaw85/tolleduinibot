#include "menu_helpers.h"
int valid_response(int response, int* valid_answers, int array_len)
{
    int i;
    for (i = 0; i < array_len; i++)
        if (valid_answers[i] == response)
            return 1; // found a valid response
    return 0; // invalid response found          
}

char prompt(char* p, int* valid_answers, int array_len)
{
    char response;
    do {
        Serial.print(p);
        while(!Serial.available() > 0); // wait for the user to input something
        response = Serial.read(); // get input
        Serial.println(response);
    } while (valid_response(response, valid_answers, array_len) != 1);
    return response;
}
