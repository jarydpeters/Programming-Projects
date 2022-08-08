/*  
 *  Input to Output Copy
 *  
 *  elementary function that copies input stream to output stream
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>

int main(void)
{
    int c;

    //1-7
    //printf("%i\n", EOF);

    while((c = getchar()) != EOF)
    {
        putchar(c);
    }

    return 0;
}