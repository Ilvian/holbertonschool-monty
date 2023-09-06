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
	new_node->n = value;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
}
/**
* pall - Prints all the values on the stack.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
* pint - Prints the value at the top of the stack, followed by a new line.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
* pop - Removes the top element of the stack.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
/**
* swap - Swaps the top two elements of the stack.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *top = *stack;
	stack_t *second = top->next;
	top->next = second->next;
	top->prev = second;
	second->prev = NULL;
	second->next = top;
	*stack = second;
}
/**
* add - Adds the top two elements of the stack.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
* nop - Does nothing.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_len = 0;
	unsigned int line_number = 0;
	while (getline(&line, &line_len, file) != -1)
	{
		line_number++;
		char *opcode, *arg;
		int value;
		opcode = strtok(line, " \n");
		if (!opcode || *opcode == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \n");
			if (!arg)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				free(line);
				while (stack)
				{
					stack_t *temp = stack;
					stack = stack->next;
					free(temp);
				}
				return (EXIT_FAILURE);
			}
			char *endptr;
			value = strtol(arg, &endptr, 10);
			if (*endptr != '\0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				free(line);
				while (stack)
				{
					stack_t *temp = stack;
					stack = stack->next;
					free(temp);
				}
				return (EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free(line);
			while (stack)
			{
				stack_t *temp = stack;
				stack = stack->next;
				free(temp);
			}
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	free(line);
	while (stack)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
