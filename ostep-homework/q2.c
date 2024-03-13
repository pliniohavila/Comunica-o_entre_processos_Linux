#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>


int     main(void) 
{
    pid_t   cpid;
    int     fd;

    fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd == -1) 
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    if ((cpid = fork()) == -1) 
    {
        perror("Fork error\n");
        exit(1);
    }
    if (cpid == 0) 
    {
        dprintf(fd, "Child writed!\n");
    }
    else 
    {
        dprintf(fd, "Parent writed!\n");
        close(fd);
    }
    // if (dprintf(fd, "Olá, mundo!\n") == -1) 
    // {
    //     perror("Erro ao escrever no arquivo");
    //     close(fd);
    //     return 1;
    // }
    return (0);
}