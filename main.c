#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        char *argument = strtok(NULL, " \t\n");

        if (opcode == NULL)
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL || !is_integer(argument))
            {
                fprintf(stderr, "L%d: USAGE: push integer\n", line_number);
                free(line);
                fclose(file);
                exit(EXIT_FAILURE);
            }

            int value = atoi(argument);
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }

        free(line);
        line = NULL;
        len = 0;
    }

    fclose(file);
    if (line)
        free(line);

    return 0;
}

