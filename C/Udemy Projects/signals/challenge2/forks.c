#include <unistd.h>
#include <stdio.h>

int main(void)
{
    //parent starts executing from here ^^^
    pid_t child1 = fork(); 
    //child 1 starts executing from here ^^^

    pid_t child2 = fork();
    //child 2 starts executing from here ^^^
    //child 3 starts executing from here ^^^ (created by child 1)

    //occurs if process has passed lines 8 AND 11
    if(child1 > 0 && child2 > 0)
    {
        printf("***PARENT***\n");
        printf("%d %d", child1, child2);
        printf("My ID is:          %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }
    //occurs if process has passed ONLY line 11
    else if(child1 == 0 && child2 > 0)
    {
        printf("***FIRST CHILD***\n");
        printf("%d %d", child1, child2);
        printf("My ID is:          %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }
    //occurs if process has passed ONLY line 8
    else if(child1 > 0 && child2 == 0)
    {
        printf("***SECOND CHILD***\n");
        printf("%d %d", child1, child2);
        printf("My ID is:          %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }
    //occurs if process has not passed EITHER line 8 or line 11
    else //if(child1 == 0 && child2 == 0)
    {
        printf("***THIRD CHILD***\n");
        printf("%d %d", child1, child2);
        printf("My ID is:          %d\n", getpid());
        printf("My parent's ID is: %d\n", getppid());
    }
    return 0;
}