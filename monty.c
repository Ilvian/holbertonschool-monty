#include "monty.h"
#include <stdbool.h>
void _push(stack_t **stack, unsigned int line_number) {
    char *arg = strtok(NULL, " \t\n");
    if (arg && (*arg == '-' || isdigit(*arg))) {
        int value = atoi(arg);
        stack_t *new_node = malloc(sizeof(stack_t));
        if (!new_node) {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *stack;
        if (*stack)
            (*stack)->prev = new_node;
        *stack = new_node;
    } else {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
}

void _pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    
    stack_t *current = *stack;
    while (current != NULL)
    {
	    printf("%d\n", current->n);
	    current = current->next;
    }
}

void free_stack(stack_t **stack)
{
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
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->n = result;
}
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
