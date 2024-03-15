#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int     main(void) 
{
    pid_t   cpid;
    int     x;

    x = 100;
    printf("Initial x value: %d\n", x);
    cpid = fork();
    if (cpid == 0)
    {
        close(STDOUT_FILENO);
        printf("Child x value: %d\n", x);
    }
    else 
    {
        wait(NULL);
        printf("Parent x value: %d\n", x);
    }
     exit(EXIT_SUCCESS);
}