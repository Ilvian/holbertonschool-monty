#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the pointer to the stack.
 * @value: The integer value to push onto the stack.
 * @line_number: The line number in the file where the instruction appears.
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
    stack_t *new_node;

    if (!isdigit(value))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(value);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

