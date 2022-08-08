/*  Space limiter
 *  
 *  reads in stdin and outputs to stdin with the number of adjacent spaces limited to one
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

#define MAXLENGTHOFINPUT 128

char inputText[MAXLENGTHOFINPUT];
char outputText[MAXLENGTHOFINPUT];

int inputIndex  = 0;
int outputIndex = 0;

int main(void)
{
    printf("Enter text to be space-limited:\n");
    //use fgets instead of fscan to prevent premature read stop at first whitespace
    fgets(inputText, MAXLENGTHOFINPUT, stdin);

    while(inputIndex < MAXLENGTHOFINPUT)
    {
        //detect spaces
        if(inputText[inputIndex] == ' ')
        {
            //first space
            if(inputText[inputIndex - 1] != ' ')
            {
                //first space after a character, copy directly to output
                //increment outputIndex with inputIndex
                outputText[outputIndex++] = inputText[inputIndex++];
            }
            //consecutive spaces
            else
            {
                //on consecutive spaces, outputText[outputIndex] needs to store the next non-space character
                while(inputText[inputIndex] == ' ')
                {
                    //for as long as the next character is a space, keep incrementing inputIndex
                    //this desyncs inputIndex and outputIndex, skipping (erasing) consecutive spaces in inputText
                    inputIndex++;
                }
                //once a non-space character is found, store it in outputText
                //now that outputText[outputIndex] has a value, increment outputIndex and inputIndex to prepare for the next iteration
                outputText[outputIndex++] = inputText[inputIndex++];
            }
        }
        //non-space character
        else
        {
            //copy non-space character to output string
            //increment outputIndex with inputIndex to stay synced
            outputText[outputIndex++] = inputText[inputIndex++];
        }
    }
    printf("\nResultant text:\n%s", outputText);

    return 0;
}