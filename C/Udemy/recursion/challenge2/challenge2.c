/*  Recursive GCD tool
 *
 *  Finds the GCD of a user-specified value using recursion
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

int input1 = 0;
int input2 = 0;

int gcd(int num1, int num2);

int main(void)
{
    printf("\nGCD takes two integer inputs and finds their greatest common denominator");
    
    while(input1 == 0)
    {
        printf("\nPlease enter the first integer: ");
        scanf("%d", &input1);
    }
    while(input2 == 0)
    {
        printf("\nPlease enter the second integer: ");
        scanf("%d", &input2);
    }

    printf("The greatest common denominator of %d and %d is %d", input1, input2, gcd(input1, input2));

    return 0;
}

int gcd(int num1, int num2)
{
    if(num2 != 0)
    {
        return gcd(num2, num1 % num2);
    }
    else
    {
        return num1;
    }
}