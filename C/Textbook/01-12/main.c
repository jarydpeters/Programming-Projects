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

//state flag to mark if currently "inside" (within letters) or "outside" (within spaces) of a word
int state = OUTSIDE;
//buffer to hold stdin while its evaluated to be pushed to stdout
int buffer;

int main(void)
{
    printf("Enter text to be printed one word per line:\n");

    //keep pulling from stdin until EOF
    while((buffer = getchar()) != EOF)
    {
        //found a space
        if(buffer == ' ')
        {
            //only the first space after a word is important
            if(state == INSIDE)
            {
                //push newline to stdout
                putchar('\n');
                //set state to outside so repeated spaces don't get their own newlines
                state = OUTSIDE;
            }
        }
        //first letter after spaces
        else if(state == OUTSIDE)
        {
            //set state to inside a word
            state = INSIDE;
            //release first letter of word to stdout
            putchar(buffer);
        }
        //repeated letters
        else
        {
            //release to stdout
            putchar(buffer);
        }
    }
    return 0;
}