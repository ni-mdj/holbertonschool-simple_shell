#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
int i, len;
char *new_var;
    
if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
return (-1);
    
len = strlen(name) + strlen(value) + 2;
new_var = malloc(len);
if (new_var == NULL)
return (-1);
    
snprintf(new_var, len, "%s=%s", name, value);
    
for (i = 0; environ[i]; i++)
{
if (strncmp(name, environ[i], strlen(name)) == 0 && environ[i][strlen(name)] == '=')

{
if (!overwrite)
{
free(new_var);
return (0);
}
environ[i] = new_var;
return (0);
}
}
    
environ[i] = new_var;
environ[i + 1] = NULL;
    
return (0);
}