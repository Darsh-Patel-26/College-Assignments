#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *revStr(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }

    return str;
}

int main(int argc, char const *argv[])
{
    char *str = (char *)malloc(5*sizeof(char));
    int i;
    for(i=0;i<4;i++)
    {
        str[i] = 97+i;
    }
    str[i] = '\0';
    printf("%s\n",str);

    str =revStr(str);
    printf("%s\n",str);
    return 0;
}
