/*  Longest Input Line Calculator
 *
 *  Reads in lines of text from the user and outputs the longest one
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

//maximum length of input line
#define MAXLINELEN 8

int  getLine(char line[], int maxLine);
void copyLine(char to[], char from[]);

int main(void)
{
    //currently evaluated line's length
    int length;
    //longest line seen so far
    int max = 0;

    //currently evaluated line
    char line[MAXLINELEN];
    //longest line seen so far
    char longest[MAXLINELEN];

    while((length = getLine(line, MAXLINELEN)) > 0)
    {
        if(length > max)
        {
            max = length;
            copyLine(longest, line);
        }
    }
    if(max > 0)
    {
        printf("\nLongest String:\n%s\n", longest);
        printf("\nLength of Longest String: %d", max);
    }

    return 0;
}

//reads in a lin, stores it in line[], and returns its length
int getLine(char line[], int maxLine)
{
    //holds one character at a time from getchar() to be evaluated and potentially saved to line[]
    int inputBuffer;

    //declare index here so it can be used after the loop to insert a null terminator at the end of the string
    int index;

    for(index = 0; ((inputBuffer = getchar()) != EOF) && (inputBuffer != '\n'); ++index)
    {
        //save one spot at the end for the null terminator to be inserted
        if(index < (maxLine - 1))
        {
            //save inputBuffer to line[i] IFF traversal hasn't gone past end of line, getchar() isn't returning EOF, and the read input isn't a newline
            line[index] = inputBuffer;
            index++;
        }
        //incoming buffer characters have no space in line[], count them but do nothing with them
        else
        {
            index++;
        }
    }

    line[index] = '\0';
    return index;
}

//copies from[] to to[], assumes that to[] is large enough
void copyLine(char to[], char from[])
{
    //traversal index of arrays
    int index = 0;

    //copying occurs in while statement. Will terminate when copied value from from[] is '\0'
    while(to[index] = from[index])
    {
        //copying already done, only incrementation needs to occur within the loop
        index++;
    }
}