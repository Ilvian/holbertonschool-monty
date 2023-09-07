#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t line_size = 0;
    unsigned int line_number = 0;

    void (*get_op(char *token))(stack_t **stack, unsigned int line_number); // Move this here

    while (getline(&line, &line_size, file) != -1)
    {
        line_number++;
        char *token = strtok(line, " \t\n");
        if (token != NULL)
        {
            void (*opcode_func)(stack_t **, unsigned int) = get_op(token);
            if (opcode_func != NULL)
            {
                opcode_func(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
                free(line);
                fclose(file);
                free_stack(&stack); // Implement this function to free the stack
                return (EXIT_FAILURE);
            }
        }
    }

    free(line);
    fclose(file);
    free_stack(&stack); // Implement this function to free the stack
    return (EXIT_SUCCESS);
}

