#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct simple_command 
{
    int     number_commands;
    int     number_args;
    char    **arguments;

}               SIMPLE_COMMAND;

enum redirect_e
{
	INFILE, 
	OUTFILE, 
	PIPE_INT,
	PIPE_OUT, 
}

typedef struct command 
{
	char	**cmd; // get_tokens();
	int 	infile; // 0
	int 	outfile; // 0
	int 	outfile_append; // 0 
	int 	pipe_out; // 0
	int 	pipe_int; // 0
}		s_command; // 0


int         get_qtd_cmd(char *input)
{
    int      qtd_cmd;

    qtd_cmd = 2;
    while (*input != '\0')
    {
        if (*input == '>' || (*input == '>' && *input + 1 == '>' ) || *input == '<' || *input == '|')
            qtd_cmd++;
        input++;
    }
    return(qtd_cmd);
}


char **get_cmds(const char *raw_cmd)
{
    int     i;
    int     qtd_cmd;
    char    *cmd;
    char    **cmds;

    i = 0;
    qtd_cmd = get_qtd_cmd(raw_cmd) * 2 + 2;
    cmds = malloc(sizeof(cahr*) * qtd_cmd);
    assert(cmds != NULL);

    cmds[0] = raw_cmd + i;
    int old_i = i;
    cmds[1] = 
    while (raw_cmd[i] != '\0')
    {

    }
    // "cat < _wc.c" 
    // {"cat", "<", "_wc.c"}


}

int     main(void)
{
    char *raw_cmd = "cat < _wc.c";

    return (0);
}
