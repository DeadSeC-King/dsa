//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include <stdio.h>
int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i]; // Add primary diagonal element
    }
    
    printf("Sum of primary diagonal elements: %d\n", sum);
    
    return 0;
}