/*  Sorting Exercise
 *
 *  Uses standard library functions to create an array of random numbers, sort them, and print them
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZEOFARRAY 10

//declare functions before main()
void fillArray(int emptyArray[], int sizeOfArray);
void showArray(const int inputArray[], int sizeOfArray);
//preceeded by "bespoke" to avoid using name of existing function
int  bespokeCompare(const void* pointer1, const void* pointer2);

int main(void)
{
    int testArray[SIZEOFARRAY];

    printf("Filling Test Array...\n");
    fillArray(testArray, SIZEOFARRAY);

    printf("Starting array:\n");
    showArray(testArray, SIZEOFARRAY);

    printf("Sorting array with qsort...\n");
    qsort(testArray, SIZEOFARRAY, sizeof(int), bespokeCompare);
    printf("Sorting successful\n");

    printf("Sorted array:\n");
    showArray(testArray, SIZEOFARRAY);

    return 0;
}

void fillArray(int emptyArray[], int sizeOfArray)
{
    //give srand seed value so subsequent rand values are as close to random as possible
    srand(time(NULL));

    for(int i = 0; i < sizeOfArray; i++)
    {
        //range: -100 to 100
        emptyArray[i] = ((rand() % 200) - 100);
    }
}

void showArray(const int inputArray[], int sizeOfArray)
{
    for(int i = 0; i < sizeOfArray; i++)
    {
        //formatting: new line every ten entries (but not the very first)
        if((i % 10 == 0) && i != 0)
        {
            printf("\n");
        }

        printf("%3.0i\t", inputArray[i]);
    }
    //formatting: new line at end of all entries
    printf("\n");
}

int  bespokeCompare(const void *pointer1, const void *pointer2)
{
    //must cast pointers to ints to access values properly
    const int* value1 = (const int *) pointer1;
    const int* value2 = (const int *) pointer2;

    if(*value1 < *value2)
    {
        return -1;
    }
    else if(*value1 == *value2)
    {
        return 0;
    }
    else //if (*value1 > *value2)
    {
        return 1;
    }
}