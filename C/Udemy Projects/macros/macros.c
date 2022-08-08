#include <stdio.h>

//define SUM macro
#define SUM(a, b) (a + b)

//define SQUARE macro
#define SQUARE(a) (a * a)

//define CUBE macro
#define CUBE(a) (a * a * a)

//define IS_UPPER macro
#define IS_UPPER(a)(a >= 'A' && a <= 'Z')

//define IS_LOWER macro
#define IS_LOWER(a)(a >= 'a' && a <= 'z')

int main(void)
{
    //challenge 1
    printf("__LINE__ = %d\n",   __LINE__);
    printf("__FILE__ = %s\n",   __FILE__);
    printf("__DATE__ = %s\n",   __DATE__);
    printf("__TIME__ = %s\n",   __TIME__);
    printf("__STDC__ = %d\n\n", __STDC__);

    //challenge 2
    int addend1 = 0;
    int addend2 = 0;

    printf("Enter first number to be summed:  ");
    scanf("%d", &addend1);

    printf("Enter second number to be summed: ");
    scanf("%d", &addend2);

    printf("Sum of both numbers: %d\n\n", SUM(addend1, addend2));

    //challenge 3
    int base = 0;

    printf("Enter first number to be squared and cubed: ");
    scanf("%d", &base);

    printf("%d squared is: %d\n",   base, SQUARE(base));
    printf("%d cubed is:   %d\n\n", base, CUBE(base));

    //challenge 4
    char inputChar;

    printf("Enter any character: ");
    scanf(" %c", &inputChar);

    if(IS_UPPER(inputChar))
    {
        printf("'%c' is uppercase\n", inputChar);
    }
    else if(IS_LOWER(inputChar))
    {
        printf("'%c' is lowercase\n", inputChar);
    }
    else
    {
        printf("'%c' is not part of the alphabet\n", inputChar);
    }

    return 0;
}