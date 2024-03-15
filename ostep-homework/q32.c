#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) 
{
    int     fd[2];
    pid_t   pid;
    char    msg[2];
    char    buf[20];

    if (pipe(fd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) 
    { 
        close(fd[0]); 
        printf("prompt > ");
        scanf("%s", msg);
        write(fd[1], msg, strlen(msg)); 
        close(fd[1]); 
        exit(EXIT_SUCCESS);
    } 
    else 
    { 
        close(fd[1]);
        read(fd[0], &buf, 8);
        printf("From child: %s\n", buf);
        close(fd[0]); 
        wait(NULL); 
    }
    return (0);
}
