/*  Base Conversion Tool
 *
 *  Converts numbers between base-10 and base-2
 *  Allows user choice in conversion type and amount of conversions
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "baseConverter.h"
#include "boolDefines.h"

#define decToBin !binToDec //verify behavior works as intended

bool binToDec;
bool debug = FALSE;
bool userContinue = TRUE;

int decision;
int numToConv;
int convertedNum; 
int digitToConv;
int runningRemainder;
int convertedResult;
int digitsPlace;
int userResponse;

int binaryToDecimal(int numToConv) //Binary to Decimal
{
    int numOfDigits = floor(log10(abs(numToConv))) + 1;

    if(debug)
    {
        printf("Number of digits in number to be converted: %d\n", numOfDigits);
    }

    for(int i = 0; i < numOfDigits; i++)
    {
        digitToConv = numToConv % 10;
        numToConv   = numToConv / 10;

        if(debug)
        {
            printf("Current digit being evaluated: %d\n", digitToConv);
        }

        convertedResult += (digitToConv * pow(2, i));
    }
    if(debug)
    {
        printf("Computed Result at end of method: %d\n", convertedResult);
    }
    return convertedResult;
}

int decimalToBinary(int numToConv) //Decimal to Binary
{
    convertedNum     = 0;
    runningRemainder = 1;
    convertedResult  = 0;
    digitsPlace      = 1;

    bool negativeInput = FALSE;

    if(numToConv < 0)
    {
        numToConv = abs(numToConv);
        negativeInput = TRUE;
        if(debug)
        {
            printf("Input is negative\n");
        }
    }
    while(numToConv)
    {
        runningRemainder = numToConv % 2;
        numToConv        = numToConv / 2;
        convertedResult += runningRemainder * digitsPlace;
        digitsPlace      = digitsPlace * 10;

        if(debug)
        {
            printf("Running Remainder: %d\n", runningRemainder);
        }

        if(debug)
        {
            printf("Running Quotient: %d\n", numToConv);
        }
    }
    if(!negativeInput)
    {
        if(debug)
        {
            printf("Computed Positive Result at end of method: %d\n", convertedResult);
        }
        return convertedResult;
    }
    else
    {
        if(debug)
        {
            printf("Computed Negative Result at end of method: %d\n", -convertedResult);
        }
        return -convertedResult;
    }
}
