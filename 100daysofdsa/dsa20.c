//Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int count = 0;
    
    // Iterate through all possible subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
            }
        }
    }
    
    printf("Number of subarrays with sum equal to zero: %d\n", count);
    
    return 0;
}