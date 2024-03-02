#include<stdio.h>

int main() 
{
    int rows, cols, i, j;
    int matrix[10][10], transpose[10][10];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix: \n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose the matrix
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("The transpose of the matrix is:\n");
    for (i = 0; i < cols; i++) 
    {
        for (j = 0; j < rows; j++) 
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
