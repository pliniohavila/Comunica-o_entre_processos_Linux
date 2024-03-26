#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

void        free_tokens(char **tokens)
{
    int         i;

    if (tokens != NULL) 
    {
        i = 0;
        while (tokens[i + 1] != NULL) 
        {
            free(tokens[i]);
            i++;
        }
    }
}

int main(void) {
    char    str[] = "cat -a -b -c < ls.log | sort -b -d | wc -v > wc.log";
    char    **tokens;
    int     i;

    tokens = parser(str);
    i = 0;
    while (tokens[i] != NULL)
    {
        printf("%s, ", tokens[i]);
        i++;
    }
    free(tokens);
    return (0);
}
