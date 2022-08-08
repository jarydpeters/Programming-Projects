/*  Temperature Unit Converter Tool
 *
 *  Converts Fahrenheit to Celsius or Celsius to Fahrenheit
 *  Displays values from 300 to 0 degrees in descending order
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include "temperatureConversion.h"

char startingUnit;

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

        for(float fahr = 3000; fahr >= 0; fahr -= 20)
        {
            printf("%3.0fF %6.1fC\n", fahr, fahrToCels(fahr));
        }
    }
    else if(startingWithCels(startingUnit))
    {
        printf("Celsius to Fahrenheit conversion table:\n");

        for(float cels = 150; cels >= 0; cels -= 10)
        {
            printf("%3.0fC %6.1fF\n", cels, celsToFahr(cels));
        }
    }
    else
    {
        printf("\nAn unrecoverable error has occurred!\nStarting Units input unrecognized!\nExiting program...");
    }
    return 0;
}