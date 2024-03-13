#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int     main(void) 
{
    pid_t   child_pid;
    pid_t   cpid_wait;
    int     wstatus;

    printf("MAIN (pid:%d)\n", (int) getpid());
    child_pid = fork();
    if (child_pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }

    if (child_pid == 0) 
    {
        printf("Child (pid:%d)\n", (int)getpid());
    }
    else 
    {
        cpid_wait = wait(&wstatus);
        printf("Parent (pid:%d) - (rc_wait:%d) - Child (pid:%d)\n", 
            (int)getpid(), (int)cpid_wait, (int)child_pid);
    }
    return (0);
}