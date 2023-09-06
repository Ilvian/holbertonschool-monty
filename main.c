#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
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
