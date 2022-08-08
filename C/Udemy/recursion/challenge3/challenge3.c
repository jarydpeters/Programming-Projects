/*  Recursive Reverse tool
 *
 *  Reverses a user-defined string using recursion
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

char str[128] = "";
char *rev     = NULL;

char* reverse(char* str);

int main(void)
{
    printf("Enter a string of characters to be reversed:\n");
    scanf("%s", &str);

    rev = reverse(str);

    printf("The reverse of the input string is:\n%s", rev);

    return 0;
}

char* reverse(char* str)
{
    static int reverseIndex = 0;
    static char rev[128]    = "";

    if(*str)
    {
        reverse(str + 1);
        rev[reverseIndex++] = *str;
    }

    return rev;
}