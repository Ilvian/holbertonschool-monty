#include "monty.h"

#include <stdbool.h>

void _push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (arg)
    {
        bool is_valid = true;
        int value = 0;

        // Handle negative sign if present
        int sign = 1;
        if (arg[0] == '-')
        {
            sign = -1;
            arg++;
        }

        // Check if each character is a digit
        for (int i = 0; arg[i] != '\0'; i++)
        {
            if (!isdigit(arg[i]))
            {
                is_valid = false;
                break;
            }
        }

        if (is_valid)
        {
            value = atoi(arg) * sign;
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
void _pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
void _pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
void _swap(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
void _add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int result = (*stack)->n + (*stack)->next->n;
    
    // Pop the top element
    stack_t *temp = *stack;
    *stack = (*stack)->next;
    free(temp);

    // Update the second top element with the result
    (*stack)->n = result;
}
void _nop(stack_t **stack, unsigned int line_number)
{
    (void)stack; // Suppress unused variable warning
    (void)line_number; // Suppress unused variable warning
    // This function does nothing
}

