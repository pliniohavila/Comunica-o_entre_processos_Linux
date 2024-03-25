#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

static int         get_qtd_tokens(char *input);

char    **parser(char *str) {
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
    free(str_cp);
    return tokens;
}

int main(void) {
    char    str[] = "cat -a -b -c < ls.log | sort -b -d | wc -v";
    char    **tokens;
    int     i;

    tokens = parser(str);
    i = 0;
    while (tokens[i] != NULL)
    {
        printf("%s ", tokens[i]);
        i++;
    }
    free(tokens);
    return (0);
}

static int         get_qtd_tokens(char *input)
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
