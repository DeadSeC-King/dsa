//wap to remove duplicate elements from a sorted array
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int i = 0; // Pointer for the position of the last unique element
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++; // Move to the next position for a unique element
            nums[i] = nums[j]; // Update the position with the new unique element
        }
    }
    return i + 1; // The length of the array with unique elements
}
int main() {
    int nums[] = {1, 1, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int newLength = removeDuplicates(nums, numsSize);
    
    printf("Length of array after removing duplicates: %d\n", newLength);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}
