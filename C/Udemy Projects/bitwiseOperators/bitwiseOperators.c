#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "baseConversion.h"
#include "boolDefines.h"

int firstInteger;
int secondInteger;

int firstIntegerBinary;
int secondIntegerBinary;

int main(void)
{
    printf("Input first integer:\n");
    scanf("%d", &firstInteger);

    printf("Input second integer:\n");
    scanf("%d", &secondInteger);

    firstIntegerBinary  = decimalToBinary(firstInteger);
    secondIntegerBinary = decimalToBinary(secondInteger);

    printf("Result of applying ~ operator on number %d (%d) is %d\n", firstInteger,  firstIntegerBinary, decimalToBinary(~firstInteger));
    printf("Result of applying ~ operator on number %d (%d) is %d\n", secondInteger, secondIntegerBinary, decimalToBinary(~secondInteger));

    printf("Result of applying & operator on number %d (%d) and number %d (%d) is %d\n", 
        firstInteger, firstIntegerBinary, secondInteger, secondIntegerBinary, (firstIntegerBinary & secondIntegerBinary));

    printf("Result of applying | operator on number %d (%d) and number %d (%d) is %d\n", 
        firstInteger, firstIntegerBinary, secondInteger, secondIntegerBinary, (firstIntegerBinary | secondIntegerBinary));

    printf("Result of applying ^ operator on number %d (%d) and number %d (%d) is %d\n", 
        firstInteger, firstIntegerBinary, secondInteger, secondIntegerBinary, (firstIntegerBinary ^ secondIntegerBinary));

    printf("Result of applying the << operator on number %d (%d) by 2 places is %d (%d)",
        firstInteger, firstIntegerBinary, decimalToBinary(firstInteger << 2), (firstInteger << 2));
    
    return 0;
}