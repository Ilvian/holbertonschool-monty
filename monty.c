#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Current line number in the Monty bytecode file.
 * @value: The integer value to push onto the stack.
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 * @line_number: Current line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

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
        int value;

        opcode = strtok(line, " \n");
        if (!opcode || *opcode == '#')
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            arg = strtok(NULL, " \n");
            if (!arg)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                free(line);
                while (stack)
                {
                    stack_t *temp = stack;
                    stack = stack->next;
                    free(temp);
                }
                return (EXIT_FAILURE);
            }

            value = atoi(arg);
            if (value == 0 && *arg != '0')
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                free(line);
                while (stack)
                {
                    stack_t *temp = stack;
                    stack = stack->next;
                    free(temp);
                }
                return (EXIT_FAILURE);
            }

            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
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

