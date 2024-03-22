#include <stdio.h>
#include <stdlib.h> // STDOUT_FILENO
#include <string.h> // strlen
#include <unistd.h> // write dup dup2
// #include <fcntl.h> // open

int     main(void)
{
    int     fd;
    char    *buf = "Chet Baker in Tokyo\n";

    fd = dup(STDOUT_FILENO);
    printf("fd: %d\n", fd);
    write(fd, buf, strlen(buf));
    return (0);
}