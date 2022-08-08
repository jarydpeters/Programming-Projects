#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void errorRecovery(void);

int main(void)
{
    while(1)
    {
        if(setjmp(buf))
        {
            printf("Back in main function.\n");
            break;
        }
        else
        {
            errorRecovery();
        }
    }
    return 0;
}

void errorRecovery(void)
{
    printf("Unrecoverable error detected!\n");
    longjmp(buf, 1);
}