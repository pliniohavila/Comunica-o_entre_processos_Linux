#include <stdio.h>
#include <stdlib.h> // exit / EXIT_FAILURE
#include <unistd.h> // read / write
#include <fcntl.h> // open
#include <errno.h> // errno status
#include <assert.h>
#include <stdarg.h>

#define BUF_SIZE 1024

int     _cat(int int_fd, int out_fd);
void    err_exit(char *msg);
void    close_fds(int count, ...);

int     main(int argc, char **argv)
{
    int     fd1, fd2, out_fd;
    int     open_flags, create_flags;

    if (argc < 4)
    {
        printf("./cat file1 file 2 output_file\n");
        return (1);
    }
    open_flags = O_RDONLY;
    create_flags = O_CREAT | O_WRONLY | O_APPEND;
    fd1 = open(argv[1], open_flags);
    assert(fd1);
    fd2 = open(argv[2], open_flags);
    if (fd2 == -1)
    {
        close(fd1);
        err_exit("Open file 2 error!");
    }
    out_fd = open(argv[3], create_flags, S_IRWXU);
    printf("out_fd: %d\n", out_fd);
    if (fd2 == -1)
    {
        close_fds(2, fd1, fd2);
        err_exit("Open output file error!\n");
    }
    if (_cat(fd1, out_fd) == -1)
    {
        close_fds(3, fd1, fd2, out_fd);
        err_exit("Write from file 1 error!\n");
    }
    if (_cat(fd2, out_fd) == -1)
    {
        close_fds(3, fd1, fd2, out_fd);
        err_exit("Write from file 2 error!\n");
    }
    close_fds(3, fd1, fd2, out_fd);
    return (0);
}

int     _cat(int input_fd, int out_fd)
{
    int     len_read;
    char    buf[BUF_SIZE];

    while ((len_read = read(input_fd, buf, BUF_SIZE)) > 0)
    {
        if (write(out_fd, buf, len_read) != len_read)
            return (-1);
    }
    if (len_read == -1)
        return (-1);
    return (0);
}

void    err_exit(char *msg)
{
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}

void    close_fds(int count, ...)
{
    va_list argp;
    int     i;
    
    va_start(argp, count);
    i = 0;
    while (i < 3)
    {
        close(va_arg(argp, int));
        i++;
    }
    va_end(argp);
}