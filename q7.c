//wap to do linear search using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, search;
    int *array;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter value to find: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (array[i] == search) {
            printf("%d found at index %d\n", search, i);
            break;
        }
    }

    if (i == n) {
        printf("%d not found in the array\n", search);
    }

    // Free the allocated memory
    free(array);

    return 0;
}
