#include "monty.h"

void (*get_op(char *token))(stack_t **stack, unsigned int line_number)
{
    if (strcmp(token, "push") == 0)
        return (_push);
    else if (strcmp(token, "pall") == 0)
        return (_pall);
    else if (strcmp(token, "pint") == 0)
        return (_pint);
    else if (strcmp(token, "pint") == 0)
        return (_pop);
    else if (strcmp(token, "swap") == 0)
        return (_swap);
    else if (strcmp(token, "add") == 0)
        return (_add);
    else if (strcmp(token, "nop") == 0)
        return (_nop);
    return NULL; // Opcode not found
}

