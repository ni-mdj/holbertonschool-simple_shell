#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

/* Structure pour stocker les informations de l'environnement */
typedef struct {
char **env;
char **argv;
int argc;
}
/*prototypes utilisés dans les fichiers*/
int main(int ac, char **av);
int main(void);
int main(void);
int main(int ac, char **av, char **env);
int main(void);
char **split_string(char *str);
char *_getenv(const char *name);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int main(void);





