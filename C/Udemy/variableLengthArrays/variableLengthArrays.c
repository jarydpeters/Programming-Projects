/*  Variable Length Array Exercise
 *
 *  Finds the sum of all integer values of a variable length array
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>

int sumOfArray(int* inputArray);

int main(void)
{
    int lengthOfArray;
    int sum = 0;
    int* array;

    printf("\nEnter length of array: ");
    scanf("%d", &lengthOfArray);

    //create space for ending '\0'
    lengthOfArray++;

    //since length of array is not known at compilation, dynamic allocation is necessary
    array = (int*)malloc(lengthOfArray * sizeof(int));

    //ensure array was properly allocated
    if(array == NULL)
    {
        printf("\nMemory not properly allocated!");
        return 1;
    }
    else
    {
        //request input for each array index
        for(int arrayIndex = 0; arrayIndex < lengthOfArray; arrayIndex++)
        {
            if((arrayIndex + 1) == lengthOfArray)
            {
                array[arrayIndex] = '\0';
            }
            else
            {
                printf("\nEnter value of index %d: ", arrayIndex);
                scanf("%d", &array[arrayIndex]);
                //save a for loop by running the sum as input is read
                sum += array[arrayIndex];
            }
        }

        printf("\nSum of array is: %d", sum);

        //release allocated memory for array
        free(array);

        return 0;
    }
}