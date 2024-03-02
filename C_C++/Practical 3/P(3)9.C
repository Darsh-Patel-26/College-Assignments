#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() 
{
    float a, b, c, D, root1, root2;
    clrscr();
    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    D = b*b - 4*a*c;

    if (D > 0) 
    {
        root1 = (-b + sqrt(D)) / (2*a);
        root2 = (-b - sqrt(D)) / (2*a);
        printf("Roots are real and different.\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    }
    else if (D == 0) 
    {
        root1 = root2 = -b / (2*a);
        printf("Roots are real and same.\n");
        printf("Root 1 = Root 2 = %.2f\n", root1);
    }
    else 
    {
        float realPart = -b / (2*a);
        float imaginaryPart = sqrt(-D) / (2*a);
        printf("Roots are complex and different.\n");
        printf("Root 1 = %.2f+%.2fi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2f-%.2fi\n", realPart, imaginaryPart);
    }

    getch();
}
