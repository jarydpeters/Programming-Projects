/*  Unambiguous Output
 *  
 *  reads in stdin and outputs to stdin with ambiguous character replaced
 *  tab       -> \t
 *  backspace -> \b
 *  backslash -> \\
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

#define MAXLENGTHOFINPUT 128

char inputText[MAXLENGTHOFINPUT];
//ouptut will balloon in size as single characters are replaced with four characters
char outputText[MAXLENGTHOFINPUT * 4];

int inputIndex  = 0;
int outputIndex = 0;

int main(void)
{
    printf("Enter text to be clarified:\n");
    //use fgets instead of fscan to prevent premature read stop at first whitespace
    fgets(inputText, MAXLENGTHOFINPUT, stdin);

    printf("\nInput text:\n%s", inputText);

    while(inputIndex < MAXLENGTHOFINPUT)
    {
        //tab
        if(inputText[inputIndex] == '\t')
        {
            //replace tab character with un-ambiguous output one character/index at a time
            outputText[outputIndex++] = '(';
            outputText[outputIndex++] = '\\';
            outputText[outputIndex++] = 't';
            outputText[outputIndex++] = ')';
            //increment inputIndex past the tab character
            inputIndex++;
        }
        //backspace
        else if(inputText[inputIndex] == '\b')
        {
            //replace backspace character with un-ambiguous output one character/index at a time
            outputText[outputIndex++] = '(';
            outputText[outputIndex++] = '\\';
            outputText[outputIndex++] = 'b';
            outputText[outputIndex++] = ')';
            //increment inputIndex past the backspace character
            inputIndex++;
        }
        //backslash
        else if(inputText[inputIndex] == '\\')
        {
            //replace backslash character with un-ambiguous output one character/index at a time
            outputText[outputIndex++] = '(';
            outputText[outputIndex++] = '\\';
            outputText[outputIndex++] = '\\';
            outputText[outputIndex++] = ')';
            //increment inputIndex past the backslash character
            inputIndex++;
        }
        //not searched for character
        else
        {
            //copy character directly to output string
            //increment outputIndex with inputIndex to stay synced
            outputText[outputIndex++] = inputText[inputIndex++];
        }
    }
    printf("\nResultant text:\n%s", outputText);

    return 0;
}