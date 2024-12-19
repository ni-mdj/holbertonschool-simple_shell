#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
int i, j;
size_t len;
    
if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
return (-1);
    
len = strlen(name);
    
for (i = 0; environ[i]; i++)
{
if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
        {
for (j = i; environ[j]; j++)
environ[j] = environ[j + 1];
return (0);
}
}
    
return (0);
}