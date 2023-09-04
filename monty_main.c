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
    int valid_command;

    while (fgets(opcode, sizeof(opcode), file) != NULL)
    {
        line_number++;

        opcode[strcspn(opcode, "\n")] = '\0';

        if (strncmp(opcode, "push", 4) == 0)
        {
            if (sscanf(opcode + 4, " %d", &value) == 1)
            {
                push(&stack, value);
                valid_command = 1; 
            }
            else
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                free_stack(&stack); 
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            if (!valid_command)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                free_stack(&stack); 
                exit(EXIT_FAILURE);
            }
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            free_stack(&stack);
            exit(EXIT_FAILURE);
        }

        valid_command = 0;
    }

    free_stack(&stack);

    fclose(file);
    return 0;
}

