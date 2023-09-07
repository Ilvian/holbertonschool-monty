#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
* main - Main function.
* @argc: input
* @argv: input
* Return: EXIT SUCCESS.
*/
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

		opcode = strtok(line, " \n");
		if (!opcode || *opcode == '#')
			continue;
		arg = strtok(NULL, " \n");
		if (!arg)
                {
                        fprintf(stderr, "L%d: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                }
		x_ins(&stack, opcode, arg, line_number);
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
