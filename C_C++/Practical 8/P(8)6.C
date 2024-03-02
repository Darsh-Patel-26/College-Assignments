#include<stdio.h>
#include<conio.h>

int stringLength(char *str) 
{
  int length = 0;
  while (*str != '\0') 
  {
    length++;
    str++;
  }
  return length;
}

void main() 
{
  char str[] = "Hello World";
  int length = stringLength(str);
  clrscr();

  printf("The length of the string \"%s\" is %d.\n", str, length);
  getch();
}
    