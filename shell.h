#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

void display_shell(void);
int execute_command(void);
int read_line(void);
int main(void);


#endif
