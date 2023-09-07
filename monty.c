#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (arg && isdigit(arg[0]))
    {
        int value = atoi(arg);
        stack_t *new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *stack;
        if (*stack)
            (*stack)->prev = new_node;
        *stack = new_node;
    }
    else
    {
	    fprintf(stderr, "%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
}

void _pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; // Unused parameter

    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void free_stack(stack_t **stack)
{
    /* Implement this function to free the stack elements */
    while (*stack)
    {
        stack_t *temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

/* Add implementations for other opcode functions here */

