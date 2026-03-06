#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int calculate(char * s) {
    int len = strlen(s);
    if (len == 0) return 0;

    // Stack to store numbers for final summation
    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;
    
    long currentNumber = 0;
    char lastOperator = '+';

    for (int i = 0; i <= len; i++) {
        char c = (i < len) ? s[i] : '\0'; // Virtual char to process last number

        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        }

        // If it's an operator or the end of the string (ignoring spaces)
        if ((!isdigit(c) && !isspace(c)) || i == len) {
            if (lastOperator == '+') {
                stack[++top] = currentNumber;
            } else if (lastOperator == '-') {
                stack[++top] = -currentNumber;
            } else if (lastOperator == '*') {
                stack[top] = stack[top] * currentNumber;
            } else if (lastOperator == '/') {
                stack[top] = stack[top] / currentNumber;
            }
            lastOperator = c;
            currentNumber = 0;
        }
    }

    int result = 0;
    while (top != -1) {
        result += stack[top--];
    }

    free(stack);
    return result;
}