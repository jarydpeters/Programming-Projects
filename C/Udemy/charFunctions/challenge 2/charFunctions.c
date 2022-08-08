/*  Character Functions Exercise
 *
 *  Edits a text file by swapping the case of all letters
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertCase(FILE* filePtr, const char* filePath);

int main(void)
{
    //set up file pointer to be assigned to the read file
    FILE* filePtr = NULL;

    //set up oversized path variable to hold user response without need of malloc()
    char filePath[128];

    printf("Enter path of source file: ");
    scanf("%s", &filePath);

    //attempt to open file of chosen path for read
    filePtr = fopen(filePath, "r");

    //if file open was unsuccessful...
    if(filePtr == NULL)
    {
        //...output failure messages, clean up, and end program execution
        printf("\nUnable to open file!");
        printf("\nPlease verify that the file exists at the designated path and that you have the correct read privileges.\n");
        fclose(filePtr);
        exit(EXIT_FAILURE);
    }

    convertCase(filePtr, filePath);

    return 0;
}

void convertCase(FILE* filePtr, const char* filePath)
{
    //set up temporary file to put results into before renaming to replace the original file
    FILE* destFile = NULL;

    //set up char variable to hold currently read and evaluated character from file
    char inputCharBuffer = '\0';

    //attach destFile pointer to temp.txt which will be created by fopen()
    destFile = fopen("temp.txt", "w");

    //if file open was unsuccessful...
    if(destFile == NULL)
    {
        //...output failure messages, clean up, and end program execution
        printf("\nUnable to create temporary file!");
        fclose(destFile);
        exit(EXIT_FAILURE);
    }

    //simultaneously assign next character in file to inputCharBuffer and evaluate if it's the EOF marker
    while((inputCharBuffer = fgetc(filePtr)) != EOF)
    {
        //check for case of input buffer and set it to the opposite
        if(isupper(inputCharBuffer))
        {
            inputCharBuffer = tolower(inputCharBuffer);
        }
        //cannot be just an else in the case that the file contains characters that are not letters.
        else if(islower(inputCharBuffer))
        {
            inputCharBuffer = toupper(inputCharBuffer);
        }

        //take newly-case-swapped char and write it to the temporary destination file
        fputc(inputCharBuffer, destFile);
    }

    //close all files to free resources and allow files to be removed and renamed
    fclose(filePtr);
    fclose(destFile);

    //erase original input file, it will be replaced
    remove(filePath);

    //temporary destFile contains the output text, it needs to be renamed to the original file name
    rename("temp.txt", filePath);

    //announce to user that the process is complete
    printf("Case swap complete. Resultant file is of same name as input file: \"%s\"", filePath);
}