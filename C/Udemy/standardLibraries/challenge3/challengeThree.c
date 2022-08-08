/*  Time Exercise
 *
 *  Uses standard library functions to obtain and display system time
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t currentTime;
    char*  currentTimeString;

    currentTime = time(NULL);

    //failure to retrieve current time
    if(currentTime == ((time_t) - 1))
    {
        (void)fprintf(stderr, "Failure to get the current time.\n");
        exit(EXIT_FAILURE);
    }

    //converts current time to local format
    currentTimeString = ctime(&currentTime);

    //failure to convert time to local format
    if(currentTimeString == NULL)
    {
        (void)fprintf(stderr, "Failure to convert to local time.\n");
        exit(EXIT_FAILURE);
    }

    (void)printf("\nThe current time is: %s\n", currentTimeString);
    exit(EXIT_SUCCESS);
}