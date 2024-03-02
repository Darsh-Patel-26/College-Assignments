#include<stdio.h>
#include<conio.h>
void main() 
{
    int correct_number = 42;
    int input_number;
    int attempts = 0;
    clrscr();

    do{
        printf("Enter the correct number(Hint: 7*3*2): ");
        scanf("%d", &input_number);
        attempts++;
      } while (input_number != correct_number);

    printf("Congratulations! You entered the correct number in %d attempts.\n", attempts);

    getch();
}
