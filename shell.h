#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void display_shell(void);
int execute_command(char *command);
char *read_line(void);

#endif
