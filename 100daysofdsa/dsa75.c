//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

int findMaxLength(int arr[], int n) {
    int maxLength = 0;
    int sum = 0;
    // Use a hash table to store the first occurrence of each cumulative sum
    // Here we'll use a simple approach with nested loops for demonstration
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
            }
        }
    }
    return maxLength;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = findMaxLength(arr, n);
    printf("The length of the longest contiguous subarray with sum zero is: %d\n", result);
    return 0;
}
