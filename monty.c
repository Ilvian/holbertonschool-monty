#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

stack_t *stack = NULL;

void push(int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = stack;
    
    if (stack != NULL)
        stack->prev = new_node;
    
    stack = new_node;
}

void pall(void)
{
    stack_t *current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }
    
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file))
    {
    }
    
    fclose(file);
    return (EXIT_SUCCESS);
}

