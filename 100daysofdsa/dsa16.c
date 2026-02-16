//Given an array of integers, count the frequency of each distinct element and print the result
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Count frequency of each distinct element
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                // Mark the duplicate element
                arr[j] = -1; // Assuming -1 is not a valid input
            }
        }
        if (arr[i] != -1) {
            printf("Element: %d, Frequency: %d\n", arr[i], count);
        }
    }
    
    free(arr);
    return 0;
}