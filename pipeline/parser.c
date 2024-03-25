#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int         get_qtd_tokens(char *input)
{
    int      qtd_tokens;

    qtd_tokens = 2;
    while (*input != '\0')
    {
        if (*input == '>' || *input == '<' || *input == '|')
            qtd_tokens++;
        input++;
    }
    return(qtd_tokens);
}


int main() {
    char    str[] = "cat -a -b -c < ls.log | sort -b -d | wc -v";
    char    *str_cp;
    char    delim[] = "<>|";
    char    *token;
    char    **tokens;
    int     qtd_tokens;
    int     i;
    int     j;
    int     k;

    str_cp = malloc(sizeof(char) * strlen(str));
    assert(str_cp != NULL);
    strcpy(str_cp, str); 
    
    qtd_tokens = get_qtd_tokens(str);
    tokens = malloc(sizeof(char*) * (qtd_tokens * 2));
    assert(tokens != NULL);
    i = 0;
    token = strtok(str, delim);
    while (token != NULL)
    {
        tokens[i] = token;
        token = strtok(NULL, delim);
        i += 2;
    }
    tokens[i] = NULL;
    k = 0;
    j = 1;
    while (str_cp[k] != '\0')
    {
        if (str_cp[k] == '>')
        {
            tokens[j] = strdup(">");
            j += 2;
        }
        if (str_cp[k] == '<')
        {
            tokens[j] = strdup("<");
            j += 2;
        }
        if (str_cp[k] == '|')
        {
            tokens[j] = strdup("|");
            j += 2;
        }
        k++;
    }
    printf("\n");
    k = 0;
    while (tokens[k] != NULL)
    {
        printf("%s ", tokens[k]);
        k++;
    }
    free(str_cp);
    free(tokens);
    return 0;
}
