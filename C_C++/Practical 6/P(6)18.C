#include<stdio.h>
#include<conio.h>

void main() 
{
    int rows, columns;
    clrscr();
    
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &rows, &columns);
    
    int matrix[rows][columns];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("Matrix in zigzag order: ");
    for (int i = 0; i < rows; i++) 
    {
        if (i % 2 == 0) { // if row is even
            for (int j = 0; j < columns; j++) 
            {
                printf("%d ", matrix[i][j]);
            }
        } 
        else 
        { // if row is odd
            for (int j = columns - 1; j >= 0; j--) 
            {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    getch();
}
