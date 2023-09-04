#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    top++;
    stack[top] = value;
}

void pall() {
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[256];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        line[strcspn(line, "\n")] = '\0';

        if (strncmp(line, "push", 4) == 0) {
            int value = atoi(line + 5);
            if (value == 0 && line[5] != '0') {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                return EXIT_FAILURE;
            }
            push(value);
        } else if (strcmp(line, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, line);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

