#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main(void)
{
    char command[MAX_COMMAND_LENGTH];
    pid_t child_pid;
    int status;

    while (1) {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("\n");
            break;  // Sortir si EOF (Ctrl+D)
        }
 // Supprimer le caractère newline à la fin
        command[strcspn(command, "\n")] = 0;

        if (strlen(command) == 0) {
            continue;  // Ignorer les lignes vides
        }

        child_pid = fork();

        if (child_pid == -1) {
            perror("Erreur lors de la création du processus");
            continue;
        }

        if (child_pid == 0) {
            // Processus enfant
            char *args[] = {command, NULL};
            if (execve(command, args, NULL) == -1) {
                perror("Erreur lors de l'exécution de la commande");
                exit(1);
            }
        } else {
            // Processus parent
            wait(&status);
        }
 }

    return (0);
}