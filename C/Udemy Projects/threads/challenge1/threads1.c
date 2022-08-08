#include <stdio.h>
#include <pthread.h>

#define NUMOFTHREADS 10

int counter = 0;

void* threadFunction(void* data);

int main(void)
{
    pthread_t thread_id[NUMOFTHREADS];
    int values[NUMOFTHREADS];

    for(int i = 0; i < NUMOFTHREADS; i++)
    {
        values[i] = i;
        pthread_create(&thread_id[i], NULL, threadFunction(), &values[i]);
    }

    for(int i = 0; i < NUMOFTHREADS; i++)
    {
        pthread_join( thread_id[i], NULL);
        pthread_exit(&thread_id[i]);
    }

    return 0;
}

void* threadFunction(void* data)
{
    int *x = (int*) data;

    counter++;

    printf("message is %d, thread id = %lud modified the counter to %d\n", *x, pthread_self(), counter);
    printf("message is %d, thread id = %lud read the counter %d\n", *x, pthread_self(), counter); 
}