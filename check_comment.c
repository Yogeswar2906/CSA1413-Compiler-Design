// check_comment.c
#include <stdio.h>
#include <string.h>

int main() {
    // Sample input (You can change this line)
    char line[] = "/* This is a multi-line comment */";

    printf("Input: %s\n", line);

    int len = strlen(line);

    // Check single-line comment //
    if (line[0] == '/' && line[1] == '/') {
        printf("Result: It is a single-line comment.\n");
    }
    // Check multi-line comment /* ... */
    else if (line[0] == '/' && line[1] == '*' &&
             line[len-2] == '*' && line[len-1] == '/') {
        printf("Result: It is a multi-line comment.\n");
    }
    else {
        printf("Result: It is NOT a comment.\n");
    }

    return 0;
}
