#include<stdio.h>
#include<conio.h>
void main() 
{
    int x, y, z, temp;
    clrscr();
    printf("Enter the values of x, y, and z: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Before rotation: \nx = %d \ny = %d, \nz = %d\n", x, y, z);
    
    temp = x;    // Store the value of x in a temporary variable
    x = y;       // Assign the value of y to x
    y = z;       // Assign the value of z to y
    z = temp;    // Assign the value of the temporary variable to z
    
    printf("After rotation: \nx = %d\ny = %d\nz = %d\n", x, y, z);
    getch();
}
