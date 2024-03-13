#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

int     main(void) 
{
    pid_t   cpid;
    int     x;

    x = 100;
    printf("Initial x value: %d\n", x);
    cpid = fork();
    // assert(cpid);
    if (cpid == 0)
    {
        x = 50;
        printf("Child x value: %d\n", x);
    }
    else 
    {
        x = 500;
        printf("Parent x value: %d\n", x);
    }
    printf("Final x value: %d\n", x);
    return (0);
}