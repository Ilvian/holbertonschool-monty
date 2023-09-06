#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @value: The integer value to push onto the stack.
 */

void push(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = value;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
		new_node->next = NULL;
	*stack = new_node;
}
