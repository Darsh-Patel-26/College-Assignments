#include<stdio.h>
#include<conio.h>
void main() 
{
    int choice;
    float radius, base, height, length, width, area;
    printf("Enter: \n1 for circle\n2 for triangle  \n3 for rectangle ");
    scanf("%d", &choice);

    switch(choice) 
    {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            area = 3.14 * radius * radius;
            printf("The area of the circle is %.2f\n", area);
            break;
        case 2:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            area = 0.5 * base * height;
            printf("The area of the triangle is %.2f\n", area);
            break;
        case 3:
            printf("Enter the length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            area = length * width;
            printf("The area of the rectangle is %.2f\n", area);
            break;
        default:
            printf("Invalid choice\n");
    }

    getch();
}
