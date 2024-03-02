#include<stdio.h>
#include<conio.h>

struct personal 
{
    char name[50];
    char join_date[20];
    float salary;
};

void main()
{
    struct personal p;
    clrscr();
    
    printf("Enter Employee Name:");
    fgets(p.name,50,stdin);
    
    printf("\nEnter Joining Date:");
    fgets(p.join_date,20,stdin);
    
    printf("\nEnter Salary:");
    scanf("%f",&p.salary);
    
    printf("The Input Values are:\n");
    puts(p.name);
    puts(p.join_date);
    printf("Salary: %.2f",p.salary);
    
    getch();
}