#include <stdio.h>

int main(int ac, char **av)
{
(void)ac; // Pour éviter l'avertissement de variable non utilisée
    
for (int i = 0; av[i] != NULL; i++)
{
printf("%s\n", av[i]);
}
return (0);
}