#include <stdio.h>

int main() {
    int n, r, rev = 0, temp;

    scanf("%d", &n);
    temp = n;

    while (n) {
        r = n % 10;
        rev = rev * 10 + r;
        n /= 10;
    }

    printf(temp == rev ? "Palindrome" : "Not Palindrome");

    return 0;
}
