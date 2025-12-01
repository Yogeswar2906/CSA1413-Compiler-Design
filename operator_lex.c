// operator_lex.c
#include <stdio.h>

int main() {
    // Sample input (you can change)
    char op = '+';

    printf("Input: %c\n", op);

    switch (op) {
        case '+':
            printf("Valid Operator: Addition (+)\n");
            break;
        case '-':
            printf("Valid Operator: Subtraction (-)\n");
            break;
        case '*':
            printf("Valid Operator: Multiplication (*)\n");
            break;
        case '/':
            printf("Valid Operator: Division (/)\n");
            break;
        default:
            printf("Invalid Operator\n");
    }

    return 0;
}
