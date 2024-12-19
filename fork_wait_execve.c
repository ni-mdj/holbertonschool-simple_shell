#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
pid_t child_pid;
int status;
char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

for (int i = 0; i < 5; i++) {
child_pid = fork();
        
if (child_pid == -1) {
perror("Erreur lors de la création du processus enfant");
return (1);
}
        
if (child_pid == 0) {
// Code exécuté par le processus enfant
printf("Enfant %d (PID: %d) exécute ls -l /tmp\n", i + 1, getpid());
if (execve("/bin/ls", argv, NULL) == -1) {
perror("Erreur lors de l'exécution de la commande");
return (1);
}
} else {
// Code exécuté par le processus père
wait(&status);
printf("Enfant %d terminé\n", i + 1);
}
}

return (0);
}