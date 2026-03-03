#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    int n = strlen(s);
    char stack[n];
    int top = -1;

    for(int i = 0; i < n; i++) {
        char c = s[i];

        // Opening brackets
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        // Closing brackets
        else {
            if(top == -1) return false;

            char open = stack[top--];

            if((c == ')' && open != '(') ||
               (c == '}' && open != '{') ||
               (c == ']' && open != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}