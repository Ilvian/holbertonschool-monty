#include "monty.h"
/**
* nop - Does nothing.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}
/**
* add - Adds the top two elements of the stack.
* @stack: Pointer to the stack.
* @line_number: Current line number in the Monty bytecode file.
*/
void add(stack_t **stack, unsigned int line_number)
{
        if (!stack || !*stack || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
}
