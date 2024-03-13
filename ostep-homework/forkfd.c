#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


int     main(void) 
{
    pid_t   child_pid;
    pid_t   cpid_wait;
    int     wstatus;
    char    *cmd[3];
    int     fdout;

    child_pid = fork();
    if (child_pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    if (child_pid == 0) 
    {
        close(STDOUT_FILENO);
        fdout = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC);
        // dup2(fdout, STDOUT_FILENO);
        // if (dup2(fdout, STDOUT_FILENO) == -1) 
        // {  
        //     perror("Error dup()") ;
        //     exit(1) ;
        // }
        // close(fdout);
        cmd[0] = strdup("wc");
        cmd[1] = strdup("fork1.c");
        cmd[2] = strdup(NULL);
        execvp(cmd[0], cmd);
    }
    else 
    {
        cpid_wait = wait(&wstatus);
        printf("Parent (pid:%d) - (rc_wait:%d) - Child (pid:%d)\n", 
            (int)getpid(), (int)cpid_wait, (int)child_pid);
    }
    return (0);
}