/*  Goto Triangle Exercise/Tool
 *
 *  prints out a hollow asterisk "triangle" or "tree" using goto statements and no loops
 * 
 *  Author: Jaryd Peters
 */

//Note: this is the nastiest "solution" to the asterisk triangle problem that I've ever done. goto's are are the bane of readability and maintainability.

#include <stdio.h>

//define number of lines at compilation to avoid dynamic memory allocation. Can be set anywhere between 1 and __INT_MAX__
#define NUMOFLINES 5

int main(void)
{
    //check for invalid value for NUMOFLINES
    if((NUMOFLINES < 1) || (NUMOFLINES > __INT_MAX__))
    {
        printf("\nInvalid value for NUMOFLINES!\n");
        //end program execution if invalid value assigned to NUMOFLINES
        return 1;
    }

    //keeps track of what line is being produced
    int currentLineNumber = 1;

    //keeps track of spaces to be printed in between asterisks
    int interiorSpacesForThisLine = 1;
    //keeps track of spaces left to be printed for THIS line.
    int interiorSpacesLeftForThisLine = 1;

    //keeps track of preceeding spaces to be printed before any asterisks. Decremented with each new line to keep an accurate value of spaces needed
    //synced with preceedingSpacesLeftForThisLine at end of each line
    int preceedingSpacesForThisLine = (NUMOFLINES - 1);
    //keeps track of preceeding spaces left to be printed for THIS line. Decremented with each iteration of OuterLoop until it reaches zero.
    //synced with preceedingSpacesForThisLine at end of each line
    int preceedingSpacesLeftForThisLine = preceedingSpacesForThisLine;

    //determine number of endline asterisks needed based off of number of total lines
    int numOfEndLineAsterisks = ((NUMOFLINES * 2) - 1);
    
    lineBeginning:
        //prints spaces before asterisks
        // XXXX*
        // XXX* *
        // XX*   *
        // X*     *
        // *********
        if(preceedingSpacesLeftForThisLine != 0)
        {
            //print a space, decrement preceedingSpacesLeftForThisLine and go back to lineBeginning to evaluate if a following iteration is needed
            printf(" ");
            preceedingSpacesLeftForThisLine--;
            goto lineBeginning;
        }
        //set up for next line's iteration
        preceedingSpacesForThisLine--;

        //prints leading (or only) asterisk per line
        //     X
        //    X *
        //   X   *
        //  X     *
        // *********
        printf("*");

        //final line logic
        if(currentLineNumber == NUMOFLINES)
        {
            goto finalLine;
        }
        //interior line (2 to (NUMOFLINES - 1)) logic
        else if(currentLineNumber > 1)
        {
            //first asterisk is printed, go to lineInterior to print interior spaces before printing second asterisk
            goto lineInterior;
        }
        //first line logic
        else
        {
            //First (and only) asterisk is already printed. jump to end of program
            goto lineFinish;
        }
        //finalLine goto is evaluated at the end of lineFinish

    finalLine:
        //prints endline asterisks
        //     *
        //    * *
        //   *   *
        //  *     *
        // XXXXXXXXX
        if(numOfEndLineAsterisks != 0)
        {
            printf("*");
            numOfEndLineAsterisks--;
            goto finalLine;
        }
            
        //end program after printing final line
        return 0;

    lineInterior:
        //prints spaces in between asterisks
        //     *
        //    *X*
        //   *XXX*
        //  *XXXXX*
        // *********
        if(interiorSpacesLeftForThisLine != 0)
        {
            printf(" ");
            interiorSpacesLeftForThisLine--;
            //go back to lineInterior and evaluate if another space should be printed
            goto lineInterior;
        }
        //after all interior spaces are printed, print second (following) asterisk
        //     *
        //    * X
        //   *   X
        //  *     X
        // *********
        printf("*");
    
    lineFinish:
        //update currentLineNumber so behavior can be decided based off of current line to output
        currentLineNumber++;

        //set up line counter for next line's iteration with new decremented preceedingSpacesForThisLine value
        preceedingSpacesLeftForThisLine = preceedingSpacesForThisLine;

        //set up interior spaces counter for next line's iteration based off of new currentLineNumber value
        interiorSpacesForThisLine = ((currentLineNumber * 2) - 3);
        //sync interiorSpacesLeftForThisLine to interiorSpacesForThisLine to be decremented within next line's iteration
        interiorSpacesLeftForThisLine = interiorSpacesForThisLine;

        //prints newline and effectively handles spaces following second asterisk per line
        //     *\n
        //    * *\n
        //   *   *\n
        //  *     *\n
        // *********
        printf("\n");

        //determine if all lines (except the last) have been printed
        if(currentLineNumber == NUMOFLINES)
        {
            goto finalLine;
        }
        //start another line if pattern is NOT complete
        else
        {
            goto lineBeginning;
        }

        //return 0 is at the end of finalLine
}