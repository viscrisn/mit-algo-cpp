#include<stdio.h>

int main()
{
    //int *fptr;
    char *func();

    //fptr=func();
    printf("%u  ",func());
    printf("%c  ",*func());
    printf("%u  ",sizeof(func()));
}

char *func()
{
    static char a='B';
    return (&a);
}
