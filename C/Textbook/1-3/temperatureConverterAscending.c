/*  Temperature Unit Converter Tool
 *
 *  Converts Fahrenheit to Celsius or Celsius to Fahrenheit
 *  Displays values from 300 to 0 degrees in ascending order
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <ctype.h>
#include "temperatureConversion.h"

char startingUnit;

float lower = 0;
float upper;
float step;

float fahr;
float cels;

int main(void)
{
    printf("Temperature Unit Converter.\n");
    while(!validUnitInput(startingUnit))
    {
        printf("Select starting unit:\n(F for fahrenheit, C for celsius)\n");
        scanf("%c", &startingUnit);
    }

    if(startingWithFahr(startingUnit))
    {
        printf("Fahrenheit to Celsius conversion table:\n");
        fahr = lower;
        upper = 300;
        step  = 20;

        while(fahr <= upper)
        {
            printf("%3.0fF %6.1fC\n", fahr, fahrToCels(fahr));
            fahr += step;
        }
    }
    else if(startingWithCels(startingUnit))
    {
        printf("Celsius to Fahrenheit conversion table:\n");
        cels = lower;
        upper = 150;
        step  = 10;

        while(cels <= upper)
        {
            printf("%3.0fC %6.1fF\n", cels, celsToFahr(cels));
            cels += step;
        }
    }
    else
    {
        printf("\nAn unrecoverable error has occurred!\nStarting Units input unrecognized!\nExiting program...");
    }
    return 0;
}