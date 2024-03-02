#include<stdio.h>
#include<conio.h>
void main() 
{
    int n = 10;
    int arr[n];
    int sum = 0;
    clrscr();
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    float mean = (float)sum / n;
    
    printf("Sum of the numbers is %d\n", sum);
    printf("Mean of the numbers is %.2f\n", mean);
    
    getch();
}
