#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a1[100]; 

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }
    int i, elmt;
    printf("Enter position to insert and element: ");
    scanf("%d %d", &i, &elmt);

    // insertion
    for (int k = n; k > i; k--) {
        a1[k] = a1[k - 1];
    }
    a1[i] = elmt;
    n++;

    printf("Array after insertion:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", a1[k]);
    }}