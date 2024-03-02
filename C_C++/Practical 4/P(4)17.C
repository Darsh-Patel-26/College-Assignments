#include<stdio.h>
#include<conio.h>
void swap(int *x, int *y);
void permute(int *arr, int start, int end);
void main() 
{
    int n;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    permute(arr, 0, n - 1);
    getch();
}

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *arr, int start, int end) 
{
    if (start == end) 
    {
        // Base case: all elements have been swapped, print permutation
        for (int i = 0; i <= end; i++) 
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } 
    else 
    {
        // Recursive case: swap each element with the first element and permute the rest
        for (int i = start; i <= end; i++) 
        {
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end);
            swap(&arr[start], &arr[i]);  // backtrack by swapping again
        }
    }
}

