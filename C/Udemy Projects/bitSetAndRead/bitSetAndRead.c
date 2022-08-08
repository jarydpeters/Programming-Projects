/*  Bit Set and Read Exercise
 *
 *  Takes in user's input integer value and bit number to be flipped
 *  Returns new integer based off of binary value created by flipping selected bit
 *  
 *  Author: Jaryd Peters
 */

#include <stdio.h>

int integerValue;
int bitNumber;
int bitValue;
int newBitValue;

int main(void)
{
    printf("Input integer value:\n");
    scanf("%d", &integerValue);
    printf("Input bit number to check and flip (Little-Endian):\n");
    scanf("%d", &bitNumber);

    bitValue = ((integerValue >> bitNumber) & 1);

    printf("Bit %d is set to %d\n", bitNumber, bitValue);

    if(!bitValue)
    {
        printf("Setting bit %d to 1...\n", bitNumber);
        integerValue = integerValue | (1 << bitNumber);
        printf("Bit Set Successfully!\nNew value of integer: %d\n", integerValue);
    }
    else
    {
        printf("Bit set unnecessary. Bit already set to 1\nInteger value unchanged: %d\n", integerValue);
    }

    return 0;
}