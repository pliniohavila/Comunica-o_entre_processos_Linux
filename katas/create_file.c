#include <stdio.h> // perror
#include <stdlib.h> // exit
#include <string.h> // strcpy
#include <unistd.h> // write
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int     main(void)
{
    int     fd;
    int     open_flags;
    int     l;
    char    msg[BUF_SIZE];

    strcpy(msg, "Você aprende, você falha\n");
    l = strlen(msg);
    open_flags = O_CREAT | O_WRONLY | O_TRUNC;
    fd = open("file", open_flags, S_IRWXU);
    if ((write(fd, msg, l)) < l)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    close(fd);
    return (0);
}