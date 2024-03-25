#include <stdio.h>
#include <stdlib.h> // exit / EXIT_FAILURE
#include <unistd.h> // read / write
#include <fcntl.h> // open
#include <errno.h> // errno status
#include <assert.h>


int     main(int argc, char **argv)
{
    char    *c;
    int     l;
    int     fd;
    int     len_read;

    fd = open(argv[1], O_RDONLY);
    assert(fd);
    l = 0;
    while ((len_read = read(fd, c, 1)) > 0)
    {
        if (*c == '\n')
            l++;
    }
    if (len_read == -1)
    {
        printf("Error\n");
        close(fd);
        return (1);
    }
    printf("File: %s Lines: %d\n", argv[1], l);
    close(fd);
    return (0);
}