#include "monty.h"
#include <stdbool.h>
/**
 * _push - pushes an element onto the stack
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: The current line number in the script
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arig = strtok(NULL, " \t\n");

	if (arg)
	{
		int i = 0;

		if (arg[0] == '-')
		{
			i = 1;
		}
		while (arg[i] != '\0')
		{
			if (!isdigit(arg[i]))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		int value = atoi(arg);
		stack_t *new_node = malloc(sizeof(stack_t));

		if (!new_node)
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
	}
}
/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: The current line number in the script
 */
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
/**
 * free_stack - frees all the elements of a stack_t stack
 * @stack: A pointer to a pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	while (*stack)
	{
		stack_t *temp = (*stack)->next;

		free(*stack);
		*stack = temp;
	}
}
/**
 * _pint - prints the value at the top of the stack
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: The current line number in the script
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - removes the top element of the stack
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: The current line number in the script
 */
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
/**
 * _swap - swaps the top two elements of the stack
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: The current line number in the script
 */
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
/**
 * _add - adds the top two elements of the stack
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: The current line number in the script
 */
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
/**
 * _nop - does nothing
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: The current line number in the script
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
