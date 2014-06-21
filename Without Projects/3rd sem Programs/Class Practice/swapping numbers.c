#include<stdio.h>

int swap(int *c,int *d)
{
    int temp;
    printf("c=%d, d=%d ",*c,*d);
    temp=*c;
    *c=*d;
    *d=temp;
    printf("c=%d, d=%d ",*c,*d);
}

int main()
{
    int a=2,b=3;
    int *p,*q;
    p=&a;
    q=&b;
    printf("a=%d, b=%d ",a,b);
    swap(p,q);
    printf("a=%d, b=%d ",a,b);
}
