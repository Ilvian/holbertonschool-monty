#include "monty.h"
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
