#include<stdio.h>
#include<conio.h>
void main() 
{
    int marks[5];
    int i, passCount = 0, failCount = 0;
    for (i = 0; i < 5; i++) 
    {
        printf("Enter the marks for subject %d: ", i+1);
        scanf("%d", &marks[i]);
        if (marks[i] >= 40) 
        {
            passCount++;
        } 
        else 
        {
            failCount++;
        }
    }
    
    if (passCount == 5) 
    {
        printf("PASS\n");
    } 
    else if (failCount <= 2) 
    {
        printf("ATKT\n");
    } 
    else 
    {
        printf("FAIL\n");
    }
    getch();
}
