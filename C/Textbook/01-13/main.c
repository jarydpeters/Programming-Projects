/*  Word Length Histogram Generator
 *
 *  Reads in user input from stdin and outputs a horizontal histogram of word length frequency
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

//max length of any given word is capped at 16
#define MAXWORDLENGTH     17
//max length of input from stdin is 256
#define MAXLENGTHOFINPUT 256

//set to 1 to print out debug statements during execution
#define DEBUG 0

//word length will hold the frequency of words' lengths.
//i.e. 3 2-letter words would appear as a value of 3 in the 2nd index of the array
//index 0 is unused
char wordLength[MAXWORDLENGTH] = {0};
//array to hold userInput from stdin
char userInput[MAXLENGTHOFINPUT] = {0};

int  getLenOfInput(void);
void countWordLenFreq(int lenOfInput);
void displayWordLenFreqHistogram(void);

//helper functions to print first and last line formatting so histogram appears in a "box"
void printTopBorder(void);
void printBottomBorder(void);

int main(void)
{
    //prompt user input
    printf("Enter text to be analyzed for word length frequency:\n");
    //store user input from stdin to userInput char array
    fgets(userInput, MAXLENGTHOFINPUT, stdin);

    //call countWordLenFreq() function with getLenOfInput() as its parameter
    countWordLenFreq(getLenOfInput());

    //call displayWordLenFreqHistogram() to print results
    displayWordLenFreqHistogram();

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

void countWordLenFreq(int lenOfInput)
{
    //reset currentWordLength for each word (each function call)
    int currentWordLength = 0;

    //traverse through entire userInput array
    for(int i = 0; i < lenOfInput; i++)
    {
        //within a word. if statement is formatted to be on multiple lines, but is actually one logical statement
        //e.g.: if(X && X && X && ...)
        if((userInput[i] != ' ') && (userInput[i] != '\0') && (userInput[i] != '\n') 
                                 && (userInput[i] != '.')  && (userInput[i] != '!') 
                                 && (userInput[i] != ','))
        {     
            //increment current word length counter
            currentWordLength++;

            if(DEBUG)
            {
                printf("\nuserInput[%i]: %c", i, userInput[i]);
                printf("\ncurrentWordLength: %i", currentWordLength);
            }
        }
        //found a space, tab, or newline
        else
        {
            if(DEBUG)
            {
                printf("\nIncrementing index %i of wordLength array", currentWordLength);
            }
            
            //increment that word length's index in wordLength
            if(currentWordLength < 16)
            {
                wordLength[currentWordLength] += 1;
            }
            //prevent overflow with extra long words by putting them with 16
            else
            {
                wordLength[16] += 1;
            }

            //clear counter for next iteration
            currentWordLength = 0;
        }
    }
    if(DEBUG)
    {
        for(int i = 0; i < 17; i++)
        {
            printf("\nindex: %2d, contents: %2d", i, wordLength[i]);
        }
    }
}

void displayWordLenFreqHistogram(void)
{
    //call top border function to print out top line's formatting
    printTopBorder();

    for(int i = 1; i < MAXWORDLENGTH; i++)
    {
        //print number label
        printf("\n|%2d: ", i);

        //print histogram bars based off of size of wordLength[i]
        for(int j = 0; j < wordLength[i]; j++)
        {
            printf("X");
        }

        //round off each line with the remaining spaces needed
        for(int j = wordLength[i]; j < MAXWORDLENGTH; j++)
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
    for(int i = 0; i < (MAXWORDLENGTH + 4); i++)
    {
        printf("_");
    }
}

void printBottomBorder(void)
{
    //print vertical bar that appears on the left side of the bottom row
    printf("\n|");

    //print 4 extra underscores to cover the number labels on the beginning of each row
    for(int i = 0; i < (MAXWORDLENGTH + 4); i++)
    {
        printf("_");
    }

    //print vertical bar that appears on the right side of the bottom row
    printf("|");
}