/**
 * Create two childs 
 * Child two execute `ps aux`
 * Child one execute `grep 'zsh'`
 * >  ps aux | grep 'zsh' | wc
 * Parente process wait childs finished
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pipe / close / read / dup2 / fork
#include <sys/types.h>
#include <sys/wait.h> // waitpid


int     main(void)
{
    pid_t       cpid1;
    pid_t       cpid2;
    pid_t       cpid3;
    int         status;
    int         fd[2];
    char        *cmd[3];
    

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if ((cpid1 = fork()) == -1)
    {
        perror("cpid1");
        exit(EXIT_FAILURE);
    }
    if (cpid1 == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        // dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        // close(fd[1]);
        cmd[0] = "grep";
        cmd[1] = "zsh";
        cmd[2] = NULL;
        execvp(cmd[0], cmd);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    if ((cpid2 = fork()) == -1)
    {
        perror("cpid2");
        exit(EXIT_FAILURE);
    }
    if (cpid2 == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        cmd[0] = "ps";
        cmd[1] = "aux";
        cmd[2] = NULL;
        execvp(cmd[0], cmd);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    if ((cpid3 = fork()) == -1)
    {
        perror("cpid3");
        exit(EXIT_FAILURE);
    }
    if (cpid3 == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        cmd[0] = "wc";
        cmd[2] = NULL;
        execvp(cmd[0], cmd);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(cpid1, &status, 0);
    waitpid(cpid2, &status, 0);
    waitpid(cpid3, &status, 0);
    return (EXIT_SUCCESS);
}


