#include <stdio.h>
#include <stdarg.h>

int variadicSummation(int numOfIntsToSum, ...);

int numOfIntsToSum;

int main(void)
{
    printf("\n1 + 2 = %d ", variadicSummation(2, 1, 2));
 
    printf("\n3 + 4 + 5 = %d ", variadicSummation(3, 3, 4, 5));
 
    printf("\n6 + 7 + 8 + 9 = %d ", variadicSummation(4, 6, 7, 8, 9));

    return 0;
}

int variadicSummation(int numOfIntsToSum, ...)
{
    int sum = 0;

    va_list intArgPtr;
    va_start(intArgPtr, numOfIntsToSum);

    for(int i = 0; i < numOfIntsToSum; i++)
    {
        sum += va_arg(intArgPtr, int);
    }

    va_end(intArgPtr);

    return sum;
}