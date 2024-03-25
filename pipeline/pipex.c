/*
** pipex.c - multipipes support
** https://gist.github.com/aspatic/93e197083b65678a132b9ecee53cfe86
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void pipeline(char ***cmd)
{
	int fd[2];
	pid_t pid;
	int fdd = 0;				

	while (*cmd != NULL) {
		pipe(fd);				
		if ((pid = fork()) == -1) {
			perror("fork");
			exit(1);
		}
		else if (pid == 0) {
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL) 
            {
				dup2(fd[1], 1);
			}
			close(fd[0]);
			execvp((*cmd)[0], *cmd);
			exit(1);
		}
		else {
			wait(NULL);
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
}

int     main(int argc, char *argv[])
{
	char *ls[] = {"ls", "-al", NULL};
	char *rev[] = {"rev", NULL};
	char *nl[] = {"nl", NULL};
	char *cat[] = {"cat", "-e", NULL};
	char **cmd[] = {ls, rev, nl, cat, NULL};

	pipeline(cmd);
	return (0);
}