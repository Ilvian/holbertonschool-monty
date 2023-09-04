#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char opcode[100];
    int value;
    stack_t *stack = NULL;
    int line_number = 0;

    while (fgets(opcode, sizeof(opcode), file) != NULL)
    {
        line_number++;

        if (sscanf(opcode, "push %d", &value) == 1)
        {
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall\n") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}

