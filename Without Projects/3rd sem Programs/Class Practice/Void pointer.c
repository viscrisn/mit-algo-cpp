#include<stdio.h>

int main()
{
    int a=65;
    char k='b';
    void *vptr;
    int *iptr=&a;
    vptr=iptr;
    char *cptr=vptr;

    printf("%d  ",*iptr);
    printf("%d  ",*cptr);
    //printf("%d  ",*vptr);
}
