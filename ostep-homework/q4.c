#include <stdio.h>
#include <stdlib.h>
#include <string.h> // perror
#include <unistd.h> // exevpe
#include <sys/types.h> // waitpid
#include <sys/wait.h> // waitpid
#include <errno.h>

int     main(void) 
{
    pid_t       pid;
    int         status;
    char        *cmd[5];

    cmd[0] = "ls"; 
    // cmd[1] = "-l";
    if ((pid = fork()) < -1)
        exit(1);
    if (pid == 0) 
    {
        execvp(cmd[0], cmd);
    } 
    else  
    {
        if (waitpid(pid, &status, 0) < 0)
        {
            perror(strerror(errno));
            exit(1);
        }
        printf("Parent process ended\n");
         if (WIFEXITED(status)) {
            printf("exited, status=%d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("killed by signal %d\n", WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
            printf("stopped by signal %d\n", WSTOPSIG(status));
        } else if (WIFCONTINUED(status)) {
            printf("continued\n");
        }
    }
    return (0);
}