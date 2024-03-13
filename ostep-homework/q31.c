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
    // if (signal == SIGCHLD)
    printf("Goodbye!\n");
}

int     main(void) 
{
    pid_t   cpid;

    // signal(SIGCHLD, handler);
    if ((cpid = fork()) == -1) 
    {
        perror("Fork error\n");
        exit(1);
    }
    if (cpid == 0) 
    {
        printf("Hello!\n");
    }
    else 
    {
        if (signal(SIGCHLD, handler) == SIGCHLD)
            printf("Goodbye!\n");
    }
    return (0);
}