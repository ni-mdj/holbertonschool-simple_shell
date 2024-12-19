#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);

void print_path_directories(void)
{
char *path = _getenv("PATH");
char *token;
    
if (path == NULL)
return;
    
token = strtok(path, ":");
while (token != NULL)
{
printf("%s\n", token);
token = strtok(NULL, ":");
}
}