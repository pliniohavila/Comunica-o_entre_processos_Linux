
```shel 

// `cat -a -b -c  <  ls.log  |  sort -b -d  |  wc -v > wc.log` 
cat -a -b -c  <  ls.log  |  sort -b -d  |  wc -v > wc.log


// primitive tokens
char **parsed = {"cat -a -b -c",  "<",  "ls.log",  "|",  "sort -b -d",  "|", " wc -v", NULL};

``` 

```c
// char        **get_tokens(char *input)

typedef struct cmd_s
{
    char    **cmd,  // get_tokens(parsed[i])
    int     PIPE,  // if pipe after actual command
    int     INFILE, 
	int     OUTFILE, 
    char    *infile, 
    char    *outfile
}               CMD_S;

CMD_S commands = (CMD_s)malloc(sizeof(CMD_S) * 8);


CMD_S init_command_s(const str input)
{
    // CMD_S command = (CMD_S)malloc(sizeof(CMD_S));
    CMD_S command;
    command.cmd = get_tokens(input);
    command.PIPE = 0
    command.INFILE = 0
    command.OUTFILE = 0
    command.infile = NULL;
    command.outfile = NULL;
}

Max command count is 8; 

for p_str in parsed:
    skip = 0;
    if (p_str + 1 == '>')
        commands[i] = init_commands(p_str);
        commands[i]->OUTFILE = 1;
        commands[i]->outfile = dup(p_str + 2);
        p_str += 2;
        skip = 1;
    else if 

    else if
    
    if p_str + 1 + skip == '|'

c < f | c   
_ _ _ _ _
0 1 2 3 4

c < f   
_ _ _ _ _
0 1 2 3 4

c | f | c   
_ _ _ _ _
0 1 2 3 4


     || '<' || '|')
```