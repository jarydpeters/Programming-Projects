/*  Double Pointers Exercise
 *
 *  Performs various operations on linked pointers to demonstrate the connections and similarities between them
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <malloc.h>

void allocateMemory(int **ptr)
{
    *ptr = (int*)malloc(sizeof(int));
}

int main(void)
{   
    int var = 5;
    int *ptr     = &var;
    int **ptrPtr = &ptr;

    //find var value
    printf("First variable value with var:       %d\n",   var);
    printf("First variable value with *ptr:      %d\n",   *ptr);
    printf("First variable value with **ptrPtr:  %d\n\n", **ptrPtr);

    //find var address
    printf("First variable address with &var:    %d\n",   &var);
    printf("First variable address with ptr:     %d\n",   ptr);
    printf("First variable address with *ptrPtr: %d\n\n", *ptrPtr);

    //find ptr value
    printf("First pointer value with ptr:        %d\n",   ptr);
    printf("First pointer value with *ptrPtr:    %d\n\n", *ptrPtr);

    //find ptr address
    printf("First pointer address with &ptr:     %d\n",   &ptr);
    printf("First pointer address with ptrPtr:   %d\n\n", ptrPtr);

    //find ptrPtr value
    printf("Second pointer value with ptrPtr:    %d\n\n", ptrPtr);

    //find ptrPtr address
    printf("Second pointer address with &ptrPtr: %d\n\n", &ptrPtr);

    int *ptr2 = NULL;
    int **ptr3 = &ptr2;

    allocateMemory(&ptr2); //allocateMemory(ptr3);

    *ptr2 = 13;

    printf("Value of ptr2: %d\n", *ptr2);

    free(ptr2);

    return 0;
}