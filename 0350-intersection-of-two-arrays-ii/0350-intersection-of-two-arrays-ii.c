#include <stdlib.h>

int* intersect(int* nums1, int nums1Size,
               int* nums2, int nums2Size,
               int* returnSize) {

    int max = nums1Size < nums2Size ? nums1Size : nums2Size;

    int* res = (int*)malloc(max * sizeof(int));

    int k = 0;

    for (int i = 0; i < nums1Size; i++) {

        for (int j = 0; j < nums2Size; j++) {

            if (nums1[i] == nums2[j]) {

                res[k++] = nums1[i];

                nums2[j] = -10001; // mark used
                break;
            }
        }
    }

    *returnSize = k;
    return res;
}
