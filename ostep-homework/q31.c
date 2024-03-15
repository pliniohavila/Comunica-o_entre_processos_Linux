// USING SIGNAL 
// IMPLEMENT OTHER WITH PIPES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>
#include <signal.h>

void    handler(int signal)
{
    if (signal == SIGCHLD)
        printf("Goodbye!\n");
    exit(0);
}

int     main(void) 
{
    pid_t       cpid;
    struct      sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("Error setting up signal handler");
        exit(1);
    }
    if ((cpid = fork()) == -1) 
    {
        perror("Fork error\n");
        exit(1);
    }
    if (cpid == 0) 
    {
        printf("Hello!\n");
        exit(0);
    }
    else 
    {
        while(1)
        {
            int sig = pause();
            if (sig == SIGCHLD)
                break;
        }
    }
    return (0);
}