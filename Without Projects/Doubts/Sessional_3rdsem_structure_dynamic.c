#include<stdio.h>

typedef struct
{
    int a;
    char *ptr;
    int b;
}ab;

void main()
{
    ab abc;
    abc.ptr=(char *)calloc(20,sizeof(char));//wont work!!!
    abc.ptr='asd';
    abc.a=0;
    abc.b=0;

    printf("%d %d %s",abc.a,abc.b,abc.ptr);
}
