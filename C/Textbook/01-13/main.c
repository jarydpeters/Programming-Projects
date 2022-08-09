/*  Word Length Histogram Generator
 *
 *  Reads in user input from stdin and outputs a horizontal histogram of word length frequency
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

#define MAXWORDLENGTH     17
#define MAXLENGTHOFINPUT 256

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

void printTopBorder(void);
void printBottomBorder(void);

int main(void)
{
    printf("Enter text to be analyzed for word length frequency:\n");
    fgets(userInput, MAXLENGTHOFINPUT, stdin);

    countWordLenFreq(getLenOfInput());

    displayWordLenFreqHistogram();

    return 0;
}

int getLenOfInput(void)
{
    int lenOfInput = 0;
    int index = 0;

    while(userInput[index] != '\0')
    {
        if(DEBUG)
        {
            printf("\nuserInput[%2i]: %c", index, userInput[index]);
        }
        lenOfInput++;
        index++;
    }

    return lenOfInput;
}

void countWordLenFreq(int lenOfInput)
{
    int currentWordLength = 0;

    //traverse through entire userInput array
    for(int i = 0; i < lenOfInput; i++)
    {
        //within a word
        if((userInput[i] != ' ') && (userInput[i] != '\0') && (userInput[i] != '\n') && (userInput[i] != '.'))
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

        for(int j = wordLength[i]; j < MAXWORDLENGTH; j++)
        {
            printf(" ");
        }
        printf("|");
    }

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
    printf("\n|");
    //print 4 extra underscores to cover the number labels on the beginning of each row
    for(int i = 0; i < (MAXWORDLENGTH + 4); i++)
    {
        printf("_");
    }
    printf("|");
}