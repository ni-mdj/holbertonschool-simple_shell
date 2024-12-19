#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char *line = NULL;
size_t len = 0;
size_t read;

while (1)
{
printf("$ ");
read = getline(&line, &len, stdin);
if (read == -1)
{
free(line);
exit(0);
}
printf("%s", line);
}
free(line);
return (0);
}