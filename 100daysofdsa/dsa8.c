//Given integers a and b, compute a^b using recursion without using pow() function.
#include <stdio.h>
int power(int a, int b) {
    if (b == 0) {
        return 1; // Base case: a^0 = 1
    }
    return a * power(a, b - 1); // Recursive case
}
int main() {
    int a, b;
    printf("Enter base (a): ");
    scanf("%d", &a);
    printf("Enter exponent (b): ");
    scanf("%d", &b);

    int result = power(a, b);
    printf("%d^%d = %d\n", a, b, result);
    return 0;
}