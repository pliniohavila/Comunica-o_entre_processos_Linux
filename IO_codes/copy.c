#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUF_SIZE /* Allow "cc -D" to override definition */
#define BUF_SIZE 1024
#endif

void    errExit(char *msg)
{
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}

int     main(int argc, char **argv)
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    size_t numRead;
    char buf[BUF_SIZE];

    if ((argc != 3) || strcmp(argv[1], "--help") == 0)
    {
        fprintf(stderr, "%s old-file new-file\n", argv[0]);
        exit(1);
    }
    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
        errExit("Error in open input file\n");
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH; /* rw-rw-rw- */
    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1)
        errExit("Error in open output file\n");
    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
    {
        if ((write(outputFd, buf, numRead)) != numRead)
            errExit("couldn't write whole buffer\n");
    }
    if (numRead == -1)
        errExit("Read error\n");
    if (close(inputFd) == -1)
        errExit("Close input error\n");
    if (close(outputFd) == -1)
        errExit("Close output error\n");

    exit(EXIT_SUCCESS);
}