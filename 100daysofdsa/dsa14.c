#include <stdio.h>

int main() {
    int n;
    printf("Enter n x n order: ");
    scanf("%d", &n);

    int mat[n][n];
    printf("Enter the elements of the matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int isIdentity = 1;  
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(mat[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if(mat[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
    }

    if(isIdentity)
        printf("The matrix is an Identity Matrix");
    else
        printf("The matrix is NOT an Identity Matrix");

    return 0;
}
