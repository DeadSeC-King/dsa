#include <stdio.h>

int main() {

    int row1, col1, row2, col2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &row1, &col1);

    int matrix1[row1][col1];
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &row2, &col2);

    int matrix2[row2][col2];
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Check if multiplication is possible
    if (col1 != row2) {
        printf("Invalid format for multiplication\n");
        return 0;
    }

    int result[row1][col2];
    //acess elemets of matrix 1 and 2 using pointer and then multiply them and save in result matrix
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
            }
        }
    }
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }


    return 0;
}
