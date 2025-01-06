#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dir_node
{
char *dir;
struct dir_node *next;
}

struct dir_node *build_path_list(void)
{
char *path = _getenv("PATH");
char *token;
struct dir_node *head = NULL, *current = NULL, *new_node;  
if (path == NULL)
return (NULL); 
token = strtok(path, ":");
while (token != NULL)
{
new_node = malloc(sizeof(struct dir_node));
if (new_node == NULL)
return (NULL);
new_node->dir = strdup(token);
new_node->next = NULL;   
if (head == NULL)
head = new_node;
else
current->next = new_node;       
current = new_node;
token = strtok(NULL, ":");
}   
return (head);
}