#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t currentTime;
    time(&currentTime);

    struct tm beginning_of_month;

    beginning_of_month = *localtime(&currentTime);

    beginning_of_month.tm_hour = 0;
    beginning_of_month.tm_min  = 0;
    beginning_of_month.tm_sec  = 0;
    beginning_of_month.tm_mday = 1;

    double secondsElapsed = difftime(currentTime, mktime(&beginning_of_month));

    printf("\n %.f seconds elapsed since the beginning of this month.\n", secondsElapsed);

    return 0;
}

