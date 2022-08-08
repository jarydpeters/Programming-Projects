/*  One Word Per Line Output
 *  
 *  reads in user input from stdin and outputs the input one word per line to stdout
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

//used to track if traversal is inside of a word of not. Removes printouts of consecutive spaces
#define OUTSIDE 0
#define INSIDE  1

int state = OUTSIDE;
int buffer;

int main(void)
{
    printf("Enter text to be printed one word per line:\n");

    while((buffer = getchar()) != EOF)
    {
        if(buffer == ' ')
        {
            if(state == INSIDE)
            {
                putchar('\n');
                state = OUTSIDE;
            }
        }
        else if(state == OUTSIDE)
        {
            state = INSIDE;
            putchar(buffer);
        }
        else
        {
            putchar(buffer);
        }
    }
    
    return 0;
}