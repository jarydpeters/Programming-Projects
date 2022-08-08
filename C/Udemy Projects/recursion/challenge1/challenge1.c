/*  Recursive Sum tool
 *
 *  Sums every integer up to and including the user-specified value using recursion
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

int recursiveSum(int endingInteger);

int main(void)
{
    int input = 0;

    printf("\nRecursive Sum sums every integer up to and including the chosen integer.");
    printf("\nInput an integer to sum to: ");
    scanf("%d", &input);

    printf("Recursive Sum function return is: %d", recursiveSum(input));

    return 0;
}

int recursiveSum(int endingInteger)
{
    int result = 0;

    if(endingInteger == 1)
    {
        return 1;
    }
    else
    {
        result = endingInteger + recursiveSum(endingInteger - 1);
    }

    return result;
}