#include<stdio.h>
#include<conio.h>
void main() 
{
    float salary, bonus;
    char gender;
    clrscr();
    printf("Enter the salary: ");
    scanf("%f", &salary);

    printf("Enter the gender (M/F): ");
    scanf(" %c", &gender);

    bonus = (gender == 'M') ? salary * 0.05 : salary * 0.10;
    if(salary<10000)
    {
        bonus+=salary*0.02;
        salary+=bonus;
        printf("Bonus : Rs. %.2f\n",bonus);
        printf("Salary: Rs. %.2f", salary);
    }
    else
    {
        salary += bonus;
        printf("Bonus : Rs. %.2f\n",bonus);
        printf("Salary: Rs. %.2f", salary);
    }
    getch();
}
