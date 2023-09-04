#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

