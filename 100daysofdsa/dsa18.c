//Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>
void rotate(int arr[], int n, int k) {
    k = k % n; // Handle cases where k is greater than n
    int temp[n];
    
    // Copy the last k elements to the temporary array
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    
    // Shift the first n-k elements to the right
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    
    // Copy the temporary array back to the original array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}