#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LONGUEUR_MAX_COMMANDE 100
#define NOMBRE_MAX_ARGUMENTS 10

/**
 * executer_commande - Exécute la commande avec ses arguments
 * @args: Tableau de chaînes contenant la commande et ses arguments
 *
 * Return: 1 si la commande a été exécutée avec succès, 0 sinon
 */

int executer_commande(char **args)
{
pid_t pid;
int statut;

 pid = fork();
if (pid == 0)
{
/* Processus enfant */
if (execvp(args[0], args) == -1)
{
perror("shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Erreur de fork */
perror("shell");
}
else
{
/* Processus parent */
do {
waitpid(pid, &statut, WUNTRACED);
} while (!WIFEXITED(statut) && !WIFSIGNALED(statut));
}

return (1);
}

/**
 * main - Programme de shell simple
 *
 * Return: Toujours 0
 */
int main(void)
{
char commande[LONGUEUR_MAX_COMMANDE];
char *arguments[NOMBRE_MAX_ARGUMENTS];
char *token;
int i;

while (1)
{
printf("shell> ");
if (fgets(commande, LONGUEUR_MAX_COMMANDE, stdin) == NULL)
break;

/* Supprimer le caractère de nouvelle ligne */
commande[strcspn(commande, "\n")] = 0;

/* Découper la commande */
token = strtok(commande, " ");
i = 0;
while (token != NULL && i < NOMBRE_MAX_ARGUMENTS - 1)
{
arguments[i] = token;
token = strtok(NULL, " ");
i++;
}
arguments[i] = NULL;

if (arguments[0] != NULL)
{
if (strcmp(arguments[0], "exit") == 0)
break;
executer_commande(arguments);
}
}

return (0);
}
 