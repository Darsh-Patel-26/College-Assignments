#include<stdio.h>
#include<conio.h>
void main() 
{
    int n;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    printf("The elements in the array are: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    getch();
}
