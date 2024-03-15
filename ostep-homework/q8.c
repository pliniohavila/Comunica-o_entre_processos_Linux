#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int     main(void) 
{
    pid_t   cpid1;
    pid_t   cpid2;
    int     fd[2];
    char    *buf;

    pipe(fd);
    if (pipe(fd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cpid1 = fork();
    if (cpid1 == -1 ) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid1 == 0)
    {
        close(fd[0]);
        write(fd[1], "Starship!\n", 10);
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
    else 
    {
        cpid2 = fork();
        if (cpid2 == -1 ) 
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (cpid2 == 0)
        {
            close(fd[1]);
            while (read(fd[0], &buf, 1) > 0)
                write(STDOUT_FILENO, &buf, 1);
            close(fd[0]);
            exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_SUCCESS);
}