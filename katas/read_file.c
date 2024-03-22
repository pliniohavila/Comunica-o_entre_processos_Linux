#include <stdio.h> // perror
#include <stdlib.h> // EXIT_FAILURE
#include <string.h> // strerror
#include <unistd.h> // read
#include <fcntl.h> // open
#include <errno.h> // errno status
#include <assert.h>

#define BUF_SIZE 1024

int     main(int argc, char **argv)
{
    int     fd;
    int     open_flags;
    char    buf[BUF_SIZE];

    open_flags = O_RDONLY;
    fd = open(argv[1], open_flags);
    assert(fd);
    if ((read(fd, buf, BUF_SIZE)) < 0)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("Read: ");
    printf("%s\n", buf);
    close(fd);
    return (0);
}