#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// #include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <string.h>


int     main(void) 
{
    pid_t       cpid;
    int         status;

    if ((cpid = fork()) == -1) 
    {
        perror("Fork error\n");
        exit(1);
    }
    if (cpid == 0) 
    {
        // wait(&status);
        if (wait(&status) < 0)
        {
            // strerror(errno);
            perror(strerror(errno));
            exit(1);
        }
        printf("Hello!\n");
    }
    else 
    {
        wait(&status);
        printf("Goodbye!\n");
    }
    return (0);
}