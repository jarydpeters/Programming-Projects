#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

#define MAXBUFFERSIZE 256

//create flag variable to better format results in the case of character not found
int characterFound = FALSE;

//create counter variable to keep track of currently evaluated line for more descriptive output
int currentlyEvaluatedLine = 0;

//parameters:
//searchedForChar - character to look for within provided line
//fileLine        - line of text to look for searchedForChar within
//return:
//TRUE/FALSE int value whether searchedForChar was found within fileLine
int lineHasChar(char searchedForChar, const char* fileLine);

//call "./main" to use stdin as input
//call "./main <filename>" to use specified file as input

//set up main function to take file input
//argc = number of arguments
//argv = the arguments themselves
int main(int argc, char* argv[])
{
    //set up file pointer to be later assigned data.txt
    FILE* filePtr = NULL;

    //the character that the user wishes to be found within the file's text
    char specifiedCharToSearchFor = '\0';

    //will hold the input file's or stdin's contents to be evaluated
    char inputLineBuffer[MAXBUFFERSIZE];

    //check first for invalid input...
    if(argc != 3)  
    {
        //...print API to user
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        //...and send error output and end file execution
        exit(EXIT_FAILURE);
    }
    
    //update specifiedCharToSearchFor with meaningful value
    specifiedCharToSearchFor = argv[1][0];

    //attempt to create file pointer from parameters
    filePtr = fopen(argv[2], "r");

    //check if file pointer creation was successful
    if(filePtr == NULL)
    {
        //if it wasn't, print error output and end program execution
        printf("Cannot open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    //while the file still has lines to be read...
    while(fgets(inputLineBuffer, MAXBUFFERSIZE, filePtr) != NULL)
    {
        //track which line character was found on, each while loop iteration checks one line
        currentlyEvaluatedLine++;

        //if the character is present within the buffered line...
        if(lineHasChar(specifiedCharToSearchFor, inputLineBuffer))
        {
            //...set characterFound flag to true so that "not found" results do not print
            characterFound = TRUE;

            //...print formatted output informing user what character was found and on what line...
            printf("\nSpecified character: \"%c\" found on line %d:\n", specifiedCharToSearchFor, currentlyEvaluatedLine);

            //...and use fputs to output the line itself to stdout
            fputs(inputLineBuffer, stdout);
        }
    }

    //if character was never found, inform user as such
    if(!characterFound)
    {
        fputs("\nCharacter not found within specified file!\n", stdout);
    }

    //all done. free file pointer
    fclose(filePtr);

    return 0;
}

int lineHasChar(char searchedForChar, const char* fileLine)
{
    //as long as fileLine does is not signalling the end with EOF...
    while(*fileLine)
    {
        //...check if each character within the line matches the searched for character
        //increment fileLine within the if statement to create traversal of fileLine as while(*fileLine) loops
        if(searchedForChar == *fileLine++)
        {
            //as soon as a character is found even once, cut short search and return results
            return TRUE;
        }
    }
    //character not found, return FALSE
    return FALSE;
}