/*  Character Functions Exercise
 *
 *  Reads in text data from a file and reports how many characters and words are in it using stdlib.h functions
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>

//call "./main" to use stdin as input
//call "./main <filename>" to use specified file as input

//set up main function to take file input
//argc = number of arguments
//argv = the arguments themselves
int main(int argc, char* argv[])
{
    //set up file pointer to be later assigned data.txt
    FILE* filePtr = NULL;

    //will hold the input file's or stdin's contents to be evaluated
    char inputCharBuffer = '\0';

    //the first word will not flag the detection methods, count it here
    int wordCount = 1;
    //the first char will flag the detection methods, start counting at zero
    int charCount = 0;

    //no arguments, copy standard input
    if(argc == 1)
    {
        filePtr = stdin;
    }
    //argument given, read from file
    else if(argc == 2)
    {
        //try to open file with given parameters
        filePtr = fopen(argv[1], "r");

        //if file is not found...
        if(filePtr == NULL)
        {
            //...send error output and end file execution
            fprintf(stderr, "Cannot open file!");
            exit(EXIT_FAILURE);
        }
    }
    //invalid input...
    else  
    {
        //...print API to user
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        //...and send error output and end file execution
        exit(EXIT_FAILURE);
    }

    //while file has contents to be read...
    while((inputCharBuffer = getc(filePtr)) != EOF)
    {
        //...look for markers that a word has finished
        if(inputCharBuffer == ' ' || inputCharBuffer == '\n')
        {
            wordCount++;
        }
        //...otherwise count each input towards the character count
        else
        {
            charCount++;
        }

        //get the next character for evaluation
        inputCharBuffer = getc(filePtr);
    }

    //print results
    printf("\nThe number of words in the file is:      %3d", wordCount);
    printf("\nThe number of characters in the file is: %3d", charCount);

    //close file
    fclose(filePtr);

    return 0;
}