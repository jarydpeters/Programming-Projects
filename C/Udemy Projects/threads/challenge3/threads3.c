#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUMOFTHREADS 10
#define TRUE 1

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t evens_done = PTHREAD_COND_INITIALIZER;

int number_evens_finished = 0;
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

    sleep(1);

    while(TRUE)
    {
        if((number_evens_finished == NUMOFTHREADS) / 2)
        {
            pthread_cond_broadcast(&evens_done);
            break;
        }
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
    int *x = (int*)data;

    pthread_mutex_lock(&lock);

    if((*x % 2) == 0)
    {
        number_evens_finished++;
    }
    else
    {
        pthread_cond_wait(&evens_done, &lock);
    }

    counter++;
    printf("message is %d, thread id = %lud modified the counter to %d\n", *x, pthread_self(), counter);
    printf("message is %d, thread id = %lud read the counter %d\n", *x, pthread_self(), counter); 
    
    pthread_mutex_unlock( &lock );   
}