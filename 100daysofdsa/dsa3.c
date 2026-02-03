//wap to find linear search in an array with comparison count
#include <stdio.h>
int linearSearch(int arr[], int size, int key) {
    int comparisons = 0;    
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            return i; 
        }
    }
    printf("Comparisons made: %d\n", comparisons);
    return -1; 
}
int main() {
    int arr[] = {4, 2, 3, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = linearSearch(arr, size, key);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}