// simple_lex.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isIdentifier(char *s) {
    if (!isalpha(s[0]) && s[0] != '_') return 0;
    for (int i = 1; s[i]; i++)
        if (!isalnum(s[i]) && s[i] != '_') return 0;
    return 1;
}

int main() {
    char input[] =
        "/* sample comment */\n"
        "int total = 50 + count;\n"
        "sum = total + 20; // another comment";

    char token[50];
    int i = 0, k = 0;

    printf("Input Code:\n%s\n\n", input);
    printf("Tokens:\n");

    while (input[i] != '\0') {

        // Ignore spaces, tabs, newlines
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            i++;
            continue;
        }

        // Ignore comments /* ... */
        if (input[i] == '/' && input[i+1] == '*') {
            i += 2;
            while (!(input[i] == '*' && input[i+1] == '/')) i++;
            i += 2;
            continue;
        }

        // Ignore single-line comments //
        if (input[i] == '/' && input[i+1] == '/') {
            while (input[i] != '\n' && input[i] != '\0') i++;
            continue;
        }

        // Operators
        if (strchr("+-*/=;", input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }

        // Identifiers or constants
        k = 0;
        while (isalnum(input[i]) || input[i] == '_') {
            token[k++] = input[i++];
        }
        token[k] = '\0';

        if (strlen(token) > 0) {
            if (isIdentifier(token))
                printf("Identifier: %s\n", token);
            else
                printf("Constant: %s\n", token);
        }
    }

    return 0;
}
