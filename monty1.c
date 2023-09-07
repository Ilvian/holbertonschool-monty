#include "monty.h"

void (*get_op(char *token))(stack_t **stack, unsigned int line_number)
{
    if (strcmp(token, "push") == 0)
        return (_push);
    else if (strcmp(token, "pall") == 0)
        return (_pall);
    return NULL; // Opcode not found
}

