
```shel 

// `cat -a -b -c  <  ls.log  |  sort -b -d  |  wc -v > wc.log` 
cat -a -b -c  <  ls.log  |  sort -b -d  |  wc -v > wc.log

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
```


CMD_S *init_cmd(const str )
{

}

Max command count is 8; 

for p_str in parsed:
    if (p_str + 1 == '>')
        commands[i] = init_commands(p_str);
    
    
    
     || '<' || '|')
