// Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int closestSum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }
    
    printf("Two elements whose sum is closest to zero: %d and %d\n", num1, num2);
    
    return 0;
}