#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() 
{
    float price;
    int rupees, paisa;
    clrscr();
    printf("Enter the price of the item in decimal form: ");
    scanf("%f", &price);
    
    rupees = (int) price; // Type cast the price to an integer to get the rupees
    paisa = round((price - rupees) * 100); // Subtract the rupees to get paisa, and round off to the nearest integer
    
    printf("%d rupees and %d paisa\n", rupees, paisa);
    getch();
}
