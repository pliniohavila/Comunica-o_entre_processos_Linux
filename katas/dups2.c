#include <stdio.h>
#include <stdlib.h> // STDOUT_FILENO
#include <string.h> // strlen
#include <unistd.h> // write dup dup2
#include <fcntl.h> // open
#include <assert.h>

#define BUF_SIZE 1024

int     main(void)
{
    int     fd;
    char    buf[BUF_SIZE];
    int     len_read;

    fd = open("result.txt", O_RDONLY);
    assert(fd);
    printf("STDIN_FILENO before call dup2: %d\n", STDIN_FILENO);
    dup2(fd, STDIN_FILENO);
    printf("fd: %d\n", fd);
    printf("STDIN_FILENO after call dup2: %d\n", STDIN_FILENO);
    while ((len_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, len_read) != len_read)
            return (-1);
    }
    if (len_read == -1)
        return (-1);
    close(fd);
    return (0);
}

