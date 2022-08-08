#include <stdio.h>
#include <ctype.h>

char startingUnit;

float lower = 0;
float upper;
float step;

float fahr;
float cels;

float fahrToCels(float fahr);
float celsToFahr(float cels);

int startingWithFahr(char startingUnit);
int startingWithCels(char startingUnit);

int validUnitInput(char startingUnit);

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