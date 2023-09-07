#include "monty.h"

#include <stdbool.h>

// Function to check if a string is a valid integer (positive or negative)
bool is_valid_integer(const char *str)
{
    if (str == NULL || *str == '\0')
        return false;

    int i = 0;

    // Handle optional leading '-' for negative numbers
    if (str[i] == '-')
        i++;

    // Check for non-empty string with digits only
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return false; // Non-digit character found
    }

    return true; // Valid integer
}

// _push function with improved integer validation
void _push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (arg && is_valid_integer(arg))
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
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
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

