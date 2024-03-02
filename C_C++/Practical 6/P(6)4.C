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
    
    printf("The elements in reverse order are: ");
    for (int i = n - 1; i >= 0; i--) 
    {
        printf("%d ", arr[i]);
    }
    
    getch();
}
