#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char ** tokens, int tokensSize) {
    // Create a stack large enough for all operands
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* s = tokens[i];

        // Check if the token is an operator (and not a negative number)
        if ((strlen(s) == 1) && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) {
            int b = stack[top--]; // Second operand
            int a = stack[top--]; // First operand
            
            switch (s[0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break; // C naturally truncates toward zero
            }
        } else {
            // Token is a number, convert string to integer
            stack[++top] = atoi(s);
        }
    }

    int result = stack[top];
    free(stack);
    return result;
}