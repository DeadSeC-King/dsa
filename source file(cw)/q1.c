//find sum of all elements in a list(take n number of input by user) using recursion
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = sum(arr, n);
    printf("The sum of all elements is: %d\n", result);
    
    return 0;
}

int sum(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + sum(arr, n - 1);
}
