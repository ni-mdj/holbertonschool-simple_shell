#include <stdio.h>
#include <unistd.h>

int main(void)
{
pid_t parent_pid;

parent_pid = getppid();
printf("PID du processus parent : %d\n", parent_pid);
return (0);
}