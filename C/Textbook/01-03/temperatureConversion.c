/*  Temperature Unit Converter Library
 *
 *  Contains functions that convert Fahrenheit to Celsius or Celsius to Fahrenheit
 * 
 *  Author: Jaryd Peters
 */

#include <ctype.h>
#include "temperatureConversion.h"

float fahrToCels(float fahr)
{
    return((5.0 / 9.0) * (fahr - 32));
}

float celsToFahr(float cels)
{
    return((cels * (9.0/5.0)) + 32);
}

int startingWithFahr(char startingUnit)
{
    return(tolower(startingUnit) == 'f');
}

int startingWithCels(char startingUnit)
{
    return(tolower(startingUnit) == 'c');
}

int validUnitInput(char startingUnit)
{
    return(startingWithFahr(startingUnit) || startingWithCels(startingUnit));
}