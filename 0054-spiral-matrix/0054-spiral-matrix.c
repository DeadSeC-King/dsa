#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    // If matrix is empty
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Total elements
    int total = rows * cols;

    // Allocate result array
    int* result = (int*)malloc(sizeof(int) * total);

    // Boundary pointers
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    int index = 0;

    while (top <= bottom && left <= right) {

        // Left → Right
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;

        // Top → Bottom
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        // Right → Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Bottom → Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = total;
    return result;
}
