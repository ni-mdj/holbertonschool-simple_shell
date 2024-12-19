#include <stdlib.h>
#include <string.h>

char **split_string(char *str)
{
    char **result = NULL;
    char *token;
    int count = 0;

    token = strtok(str, " ");
    while (token != NULL)
    {
    result = realloc(result, sizeof(char *) * (count + 1));
    result[count] = token;
    count++;
    token = strtok(NULL, " ");
    }
    result = realloc(result, sizeof(char *) * (count + 1));
    result[count] = NULL;

    return (result);
}