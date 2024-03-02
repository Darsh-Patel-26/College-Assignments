#include<stdio.h>

#define ROWS 3
#define COLS 3

int main() 
{
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int evenIndex = 0, oddIndex = ROWS * COLS - 1;
    
    while (evenIndex < oddIndex) 
    {
        // Find the next even element starting from the beginning of the matrix
        while (matrix[evenIndex / COLS][evenIndex % COLS] % 2 == 0 && evenIndex < ROWS * COLS) 
        {
            evenIndex++;
        }
        
        // Find the next odd element starting from the end of the matrix
        while (matrix[oddIndex / COLS][oddIndex % COLS] % 2 == 1 && oddIndex >= 0) 
        {
            oddIndex--;
        }
        
        // Swap the even and odd elements if they haven't already passed each other
        if (evenIndex < oddIndex) 
        {
            int temp = matrix[evenIndex / COLS][evenIndex % COLS];
            matrix[evenIndex / COLS][evenIndex % COLS] = matrix[oddIndex / COLS][oddIndex % COLS];
            matrix[oddIndex / COLS][oddIndex % COLS] = temp;
        }
    }
    
    // Print the matrix after rearrangement
    printf("The matrix after rearranging even elements first and odd elements later:\n");
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
