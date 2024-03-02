#include<stdio.h>
#include<conio.h>
void main() 
{
    int n;
    int arr[n];
    clrscr();
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array in ascending order
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("The elements in ascending order are: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array in descending order
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] < arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("The elements in descending order are: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    getch();
}
