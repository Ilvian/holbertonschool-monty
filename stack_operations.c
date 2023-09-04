#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
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

int is_integer(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    int i = 0;

    if (str[i] == '-')
        i++;

    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
            return 0;
        i++;
    }

    return 1;
}

