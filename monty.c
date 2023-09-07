#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (arg)
    {
        // Check if it's a valid integer or a negative integer
        int is_negative = (arg[0] == '-' && isdigit(arg[1]));

        if ((is_negative && is_valid_integer(arg + 1)) || (!is_negative && is_valid_integer(arg)))
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
            return;
        }
    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        return;
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
int is_valid_integer(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    int i = 0;

    // Handle optional leading '-' for negative numbers
    if (str[i] == '-')
        i++;

    // Check for non-empty string with digits only
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0; // Non-digit character found
    }

    return 1; // Valid integer
}
