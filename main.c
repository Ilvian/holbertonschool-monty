#include "monty.h"
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments as strings.
 * Return: 0 upon success, other values for errors.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	char *filename = argv[1];
	FILE *script_file = fopen(filename, "r");

	if (script_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, script_file) != -1)
	{
		line_number++;
		char *token = strtok(line, " \t\n");

		if (token == NULL || token[0] == '#')
			continue;
		void (*op_func)(stack_t **, unsigned int) = get_op(token);

		if (op_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
			free(line), fclose(script_file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
		op_func(&stack, line_number);
	}
	free(line);
	fclose(script_file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
