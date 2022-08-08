/*  Formatting Functions Exercise
 *
 *  Reads in integer values from a file and categorizes them into even, odd, and prime
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include "integerClassifications.h"

int main(void)
{
    //set up file pointer to be later assigned numbers.txt
    FILE* filePtr = NULL;

    int num;
    int readSuccessful;

    //attempt to create file pointer from numbers.txt
    filePtr = fopen("numbers.txt", "r");

    //check if file pointer creation was successful
    if(filePtr == NULL)
    {
        //if it wasn't, print error output and end program execution
        printf("Cannot open file!\n");
        exit(EXIT_FAILURE);
    }

    //read an integer and store read status in readSuccessful (first read only)
    readSuccessful = fscanf(filePtr, "%d", &num);

    //(readSuccessful == -1) on failure to read or end of
    while(readSuccessful != -1)
    {
        if(isPrime(num))
        {
            //all prime numbers are also odd
            printf("%8d is prime and odd\n", num);
        }
        if(isEven(num))
        {
            printf("%8d is even\n", num);
        }
        //all primes are odd, but not all odds are prime.
        //check isNotPrime here to make sure results aren't printed twice for prime numbers
        if(isOdd(num) && isNotPrime(num))
        {
            printf("%8d is odd\n", num);
        }

        //pull in the next integer before restarting the while loop
        readSuccessful = fscanf(filePtr, "%d", &num);
    }

    fclose(filePtr);

    return 0;
}