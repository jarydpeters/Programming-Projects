/*  Multiplication Test Exercise
 *
 *  Provides the user with a timed multiplication test using signals
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

typedef struct {
	int si_signo;
	int si_code;
	union sigval si_value;
	int si_errno;
	pid_t si_pid;
	uid_t si_uid;
	void *si_addr;
	int si_status;
	int si_band;
} siginfo_t;

struct sigaction 
{
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};

void end_game() 
{
    printf("\nFinal score: %d\n", score);
    exit(0); 
}

int catch_signal(int signal, void(*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return signaction(signal, &action, NULL);
}

void times_up()
{
    puts("\nTIME EXPIRED!");
    raise(SIGINT);
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main() 
{
    catch_signal(SIGALRM, times_up); //SIGALRM = 5 second timer
    catch_signal(SIGINT,  end_game); //SIGINT  = CTRL + C

    srand(time(NULL));
   
    while(1) 
    {
        int a = rand() % 11;
        int b = rand() % 11;

        char txt[4];

        //sets alarm timer to raise SIGALRM if use takes more than 5 seconds
        alarm(5);
    
        printf("\nWhat is %d times %d: ", a, b);
        fgets(txt, 4, stdin);
        int answer = atoi(txt);

        if(answer == a * b)
        {
            score++;
        }
        else
        {
            printf("\nIncorrect Answer! Score: %d\n", score);
        }
    }
    return 0;
} 