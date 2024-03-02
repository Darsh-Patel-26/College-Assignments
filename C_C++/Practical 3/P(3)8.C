#include<stdio.h>
#include<conio.h>
void main() 
{
    int sub1, sub2, sub3, sub4;
    float total, aggregate;

    // Get marks in four subjects from user
    printf("Enter marks in four subjects:\n");
    scanf("%d%d%d%d", &sub1, &sub2, &sub3, &sub4);

    // Calculate total marks and aggregate percentage
    total = sub1 + sub2 + sub3 + sub4;
    aggregate = total / 4.0;

    // Display the total and aggregate
    printf("Total marks: %.2f\n", total);
    printf("Aggregate percentage: %.2f%%\n", aggregate);

    // Display the grade obtained using if-else ladder
    if (aggregate >= 80) 
    {
        printf("Grade: Outstanding\n");
    } 
    else if (aggregate >= 70 && aggregate < 80) 
    {
        printf("Grade: A+\n");
    } 
    else if (aggregate >= 60 && aggregate < 70) 
    {
        printf("Grade: A\n");
    } 
    else if (aggregate >= 50 && aggregate < 60) 
    {
        printf("Grade: B+\n");
    } 
    else if (aggregate >= 40 && aggregate < 50) 
    {
        printf("Grade: B\n");
    } 
    else
    {
        printf("Fail;(/n");
    }

    // Display the grade obtained using switch case
    switch ((int)aggregate / 10) 
    {
        case 10:
        case 9:
        case 8:
            printf("Grade: Outstanding\n");
            break;
        case 7:
            printf("Grade: A+\n");
            break;
        case 6:
            printf("Grade: A\n");
            break;
        case 5:
            printf("Grade: B+\n");
            break;
        case 4:
            printf("Grade: B\n");
            break;
        default:
            printf("Grade: Fail\n");
            break;
    }

    getch();
}
