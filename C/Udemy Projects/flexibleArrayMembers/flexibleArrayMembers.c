/*  Flexible Array Members Exercise
 *
 *  Creates, fills, and displays a flexible array
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct myArray
{
    int length;
    //flexible array member, must be declared last in struct
    int array[];
};

int main(void)
{
    struct myArray *myArrayInstance = NULL;
    int arrayLength;

    printf("Enter size of flexible array: ");
    scanf("%d", &arrayLength);

    //memory needs to be allocated not only for the array itself, but also the structure that contains it
    myArrayInstance = malloc(sizeof(struct myArray) + (sizeof(int)* arrayLength));

    myArrayInstance -> length = arrayLength;

    srand(time(NULL));

    printf("\nArray contents:");

    for(int arrayIndex = 0; arrayIndex < arrayLength; arrayIndex++)
    {
        myArrayInstance -> array[arrayIndex] = rand() % 10;
        //formatting break
        if(!(arrayIndex % 10))
        {
            printf("\n");
        }
        //save a for loop by printing array as it's filled
        printf("%d\t", myArrayInstance -> array[arrayIndex]);
    }

    return 0;
}