#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
int i, len;
    
len = strlen(name);
for (i = 0; environ[i]; i++)
{
if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
return (&environ[i][len + 1]);
}
return (NULL);
}