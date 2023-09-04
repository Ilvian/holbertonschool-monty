#include "monty.h"

/**
 * push_stack - Pushes a new node onto the stack.
 * @stack: Pointer to the head of the stack
 * @n: Value to push onto the stack
 * Return: Pointer to the new node, or NULL on failure
 */
stack_t *push_stack(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
        return NULL;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
    return new_node;
}

/**
 * pop_stack - Pops the top element off the stack.
 * @stack: Pointer to the head of the stack
 * Return: Value of the popped element
 */
int pop_stack(stack_t **stack)
{
    int n;
    stack_t *temp;

    if (!*stack)
        return 0;

    temp = *stack;
    n = temp->n;
    *stack = temp->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
    return n;
}

/**
 * free_stack - Frees all nodes in the stack.
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
    stack_t *current, *next;

    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}

