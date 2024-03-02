#include<stdio.h>

int main() 
{
    int rows1, cols1, rows2, cols2, i, j, k;
    int mat1[10][10], mat2[10][10], sum[10][10], product[10][10];

    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < rows1; i++) 
    {
        for (j = 0; j < cols1; j++) 
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < rows2; i++) 
    {
        for (j = 0; j < cols2; j++) 
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Addition of matrices
    if (rows1 == rows2 && cols1 == cols2) 
    {
        for (i = 0; i < rows1; i++) 
        {
            for (j = 0; j < cols1; j++) 
            {
                sum[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        printf("The sum of the two matrices is:\n");
        for (i = 0; i < rows1; i++) 
        {
            for (j = 0; j < cols1; j++) 
            {
                printf("%d ", sum[i][j]);
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("Matrices cannot be added.\n");
    }

    // Multiplication of matrices
    if (cols1 == rows2) 
    {
        for (i = 0; i < rows1; i++) 
        {
            for (j = 0; j < cols2; j++) 
            {
                product[i][j] = 0;
                for (k = 0; k < cols1; k++) 
                {
                    product[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        printf("The product of the two matrices is:\n");
        for (i = 0; i < rows1; i++) 
        {
            for (j = 0; j < cols2; j++) 
            {
                printf("%d ", product[i][j]);
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("Matrices cannot be multiplied.\n");
    }

    return 0;
}
