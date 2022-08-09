/*  Word Length Histogram Generator
 *
 *  Reads in user input from stdin and outputs a horizontal histogram of character frequency
 *  This program DOES account for capital and lowercase letters and counts them as the same letter
 *  This program does NOT count punctuation, spaces, or formatting characters.
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <ctype.h>

//max length of input from stdin is 256
#define MAXLENGTHOFINPUT 256
//number of character kept track of. Index 0 is unused
#define NUMOFCOUNTEDCHAR 27

//set to 1 to print out debug statements during execution
#define DEBUG 0

//word length will hold the frequency of characters
//i.e. 3 B's would appear as a value of 3 in the 2nd index of the array
char charFreq[NUMOFCOUNTEDCHAR] = {0};
//array to hold userInput from stdin
char userInput[MAXLENGTHOFINPUT] = {0};

int  getLenOfInput(void);
void countCharFreq(int lenOfInput);
void displayCharFreqHistogram(void);

//helper functions to print first and last line formatting so histogram appears in a "box"
void printTopBorder(void);
void printBottomBorder(void);

int main(void)
{
    //prompt user input
    printf("Enter text to be analyzed for character frequency:\n");
    //store user input from stdin to userInput char array
    fgets(userInput, MAXLENGTHOFINPUT, stdin);

    if(DEBUG)
    {
        printf("\nUser Input: %s", userInput);
    }

    //call countCharFreq() function with getLenOfInput() as its parameter
    countCharFreq(getLenOfInput());

    //call displayCharFreqHistogram() to print results
    displayCharFreqHistogram();

    return 0;
}

int getLenOfInput(void)
{
    //index = length of input
    int index = 0;

    //as long as the considered index is NOT the null terminator
    while(userInput[index] != '\0')
    {
        if(DEBUG)
        {
            printf("\nuserInput[%2i]: %c", index, userInput[index]);
        }
        //increment index for traversal and for use as return value
        index++;
    }

    //index = length of input
    return index;
}

void countCharFreq(int lenOfInput)
{
    //traverse through entire userInput array
    for(int i = 0; i < lenOfInput; i++)
    {
        if((userInput[i] != ' ') && (userInput[i] != '\0') && (userInput[i] != '\n') 
                                 && (userInput[i] != '\t') && (userInput[i] != '\b') 
                                 && (userInput[i] != '.')  && (userInput[i] != ',')
                                 && (userInput[i] != '!'))
        {
            //change userInput[i] to lowercase
            //subtract 'a' (97) from userInput[i] to offset ASCII values of characters from 97-122 to 0-25
            //add 1 to change bounds from 0-25 to 1-26
            charFreq[tolower(userInput[i]) - 'a' + 1] += 1;
        }
    }
    if(DEBUG)
    {
        for(int i = 0; i < NUMOFCOUNTEDCHAR; i++)
        {
            printf("\nindex: %2d, contents: %2d", i, charFreq[i]);
        }
    }
}

void displayCharFreqHistogram(void)
{
    //call top border function to print out top line's formatting
    printTopBorder();

    for(int i = 1; i < NUMOFCOUNTEDCHAR; i++)
    {
        //print letter labels
        //add 'A' to change bounds from 1-26 to 66-91
        //subtract 1 to change bounds from 66-91 to 65-90 (A through Z in ASCII)
        printf("\n|%2c: ", (i + 'A' - 1));

        //print histogram bars based off of size of wordLength[i]
        for(int j = 0; j < charFreq[i]; j++)
        {
            printf("X");
        }

        //round off each line with the remaining spaces needed
        for(int j = charFreq[i]; j < NUMOFCOUNTEDCHAR; j++)
        {
            printf(" ");
        }
        //cap off each line with a vertical bar
        printf("|");
    }

    //call bottom border function to print out bottom line's formatting
    printBottomBorder();
}

void printTopBorder(void)
{
    printf("\nWord Length Frequency Histogram:\n ");
    //print 4 extra underscores to cover the number labels on the beginning of each row
    for(int i = 0; i < (NUMOFCOUNTEDCHAR + 4); i++)
    {
        printf("_");
    }
}

void printBottomBorder(void)
{
    //print vertical bar that appears on the left side of the bottom row
    printf("\n|");

    //print 4 extra underscores to cover the number labels on the beginning of each row
    for(int i = 0; i < (NUMOFCOUNTEDCHAR + 4); i++)
    {
        printf("_");
    }

    //print vertical bar that appears on the right side of the bottom row
    printf("|");
}