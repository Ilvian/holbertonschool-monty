#include "monty.h"
/**
* x_ins - Adds the top two elements of the stack.
* @stack: Pointer to the stack.
* @opcode: input
* @arg: input
* @line_number: Current line number in the Monty bytecode file.
*/
void x_ins(stack_t **stack, char *opcode, char *arg, unsigned int line_number)
{
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		char *endptr;

		value = strtol(arg, &endptr, 10);
		if (*endptr != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
