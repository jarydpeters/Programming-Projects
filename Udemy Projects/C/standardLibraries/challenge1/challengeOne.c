#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define amountOfNumGen 50

int main(void)
{
    float randNum = 0;

    //give srand seed value so subsequent rand values are as close to random as possible
    srand(time(NULL));

    printf("Amount of random numbers generated: %d\n", amountOfNumGen);

    for(int i = 0; i < amountOfNumGen; i++)
    {
        //formatting break every tenth number
        if(i % 10 == 0)
        {
            printf("\n");
        }

        //modulo operator determines maximum value of rand()       (range: 0 to 1000)
        //subtract 500                                             (range: -500 to 500)
        //divide by (float)1000 (float cast prevents integer math) (range: -0.5 to 0.5)
        randNum = ((rand() % 1000) - 500) / (float)1000;

        //format output
        if(randNum > 0)
        {
            printf(" ");
        }

        //leading number for %f determines amount of decimal places to display
        printf("%0.3f\t", randNum);
    }

    return 0;
}