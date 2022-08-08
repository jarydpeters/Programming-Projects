#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define TRUE  1
#define FALSE 0
#define decToBin !binToDec; //verify behavior works as intended

bool debug = TRUE;
bool binToDec;
bool userContinue = TRUE;

int decision;
int numToConv;
int convertedNum; 
int digitToConv;
int runningRemainder;
int convertedResult;
int digitsPlace;
int userResponse;

int binaryToDecimal(int numToConv);
int decimalToBinary(int numToConv);

int main()
{
    while(userContinue)
    {
        convertedNum     = 0;
        runningRemainder = 1;
        convertedResult  = 0;
        digitsPlace      = 1;

        printf("Binary to Decimal? 1 for Yes, 0 for Decimal to Binary:\n");
        scanf("%d", &decision);

        if(decision)
        {
            printf("Input binary number to be converted to decimal:\n");
        }
        else
        {
            printf("Input decimal number to be converted to binary:\n");
        }
        
        scanf("%d", &numToConv);

        if(decision)
        {
            binaryToDecimal(numToConv);
        }
        else
        {
            decimalToBinary(numToConv);
        }

        printf("Converted Number: %d\n", convertedResult);

        printf("Begin another conversion? 1 for Yes, 0 for No \n");
        scanf("%d", &userResponse);

        if(!userResponse)
        {
            userContinue = FALSE;
        }
    }
    return 0;
}

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
    if(debug)
    {
        printf("Computed Result at end of method: %d\n", convertedResult);
    }
    return convertedResult;
}
