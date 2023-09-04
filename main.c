#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

stack_t *stack = NULL;

int main()
{
    char *opcode = "push";
    char *argument = "10";

    if (strcmp(opcode, "push") == 0)
    {
        if (!is_integer(argument))
        {
            fprintf(stderr, "L<number>: usage: push integer\n");
            exit(EXIT_FAILURE);
        }

        int value = atoi(argument);
        push(&stack, value);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(&stack);
    }

    return 0;
}

