/*  Space, tab, and newline counter tool
 *  
 *  reads in stdin from user and outputs the number of spaces, tabs, and newlines it contains
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

char inputText[128];

int spaces   = 0;
int tabs     = 0;
int newlines = 0;

int main(void)
{
    printf("Enter text to be analyzed:\n");
    //use fgets instead of fscan to prevent premature read stop at first whitespace
    fgets(inputText, 128, stdin);

    for(int index = 0; index < 128; index++)
    {
        if(inputText[index] == ' ')
        {
            spaces++;
        }
        else if(inputText[index] == '\t')
        {
            tabs++;
        }
        else if(inputText[index] == '\n')
        {
            newlines++;
        }
    }
    printf("\nText contains %d spaces, %d tabs, and %d newlines", spaces, tabs, newlines);

    return 0;
}