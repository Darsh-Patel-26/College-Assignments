#include<stdio.h>
#include<conio.h>

struct student
{
    int roll,m1,m2,m3;
    float avg;
    char sname[20];
}S[3];

void main()
{
    int i;
    clrscr();
    
    for(i=0;i<3;i++)
    {
        printf("\n Enter student name:");
        scanf("%s",&S[i].sname);
        
        printf("\n Enter Roll no:");
        scanf("%d",&S[i].roll);
        
        printf("\n Enter marks in 3 Subjects :");
        scanf("%d %d %d",&S[i].m1,&S[i].m2,&S[i].m3);
        
        S[i].avg= (S[i].m1+S[i].m2+S[i].m3)/3;
    }
    
    printf("\n Data Collected:\n");
    
    for(i=0;i<3;i++)
    {
        printf("\n Student Name     : %s",S[i].sname);
        printf("\n Roll No          : %d",S[i].roll);
        printf("\n Average of marks : %f",S[i].avg);
    }
    getch();
}