#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Pour éviter les warnings
extern char **environ;

/**
 * print_env - Affiche Var d'env, pour repondre a une
 */
void print_env(void)
{
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);

        env++;
    }
}

/**
 * find_command_in_path - Trouve le chemin complet d'une commande dans PATH
 * @command: La commande à chercher
 *
 * Return: Chemin complet si trouvé, NULL sinon
 */
char *find_command_in_path(char *command)
{
    char *path = getenv("PATH"); // GET PATH 
    char *path_copy, *dir, full_path[1024];

    if (!path)
        return NULL;

    // COPY DU PATH POUR PAS LE MODIFIER, erreur si on fait pas a ca la deuxieme commande tapé
    path_copy = strdup(path);
    if (!path_copy)
    {
        perror("strdup");
        return NULL;
    }
    // Parcourir chaque PATH 
    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return strdup(full_path); // Return PATH FIND 
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

/**
 * execute_command - Exécute une commande avec gestion du PATH
 * @command: La ligne de commande à exécuter
 *
 * Return: 0 en cas de succès, 1 si la commande est invalide
 */
int execute_command(char *command)
{
    char *argv[1024]; // Tableau pour stocker les arguments
    char *path = NULL;
    pid_t pid;
    int status;
    char *token;
    int i = 0;

    // Découpe la ligne en arg avec strtok
    token = strtok(command, " \n");
    while (token != NULL && i < 1023) {
        argv[i++] = token;
        token = strtok(NULL, " \n");
    }
    argv[i] = NULL; 


	// If Command == ENV
    if (strcmp(argv[0], "env") == 0) {
        print_env(); 
        return (0);  
    }

    // If Command == Exit
	if (strcmp(argv[0], "exit") == 0) {
    	free(command);
		printf("Vous avez tapé EXIT vous allez quitter le programme");
    	exit(0);
	} 

    // If Command == Vide 
    if (argv[0] == NULL)
        return (1);

    // Find in PATH
    path = find_command_in_path(argv[0]);

    if (!path) {
        fprintf(stderr, "%s: Command not found\n", argv[0]);
        return (1);
    }

    // Créer un processus c
    pid = fork();
    if (pid == 0) { // Processus c
        if (execve(path, argv, environ) == -1) {
            perror(argv[0]);
            _exit(EXIT_FAILURE);
        }
    } else if (pid > 0) { // Processus p
        // Wait end of child process
        wait(&status);
    } else { // Fail fork
        perror("fork");
    }

    free(path); // Libérer la mémoire allouée pour len
    return (0);
}
