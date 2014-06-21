#include<stdio.h>

int add(int,int *,int **,int ***);
int main()
{
    int a,b,*c=&b,**d=&c,&t=**d;
    int &f=a;
    scanf("%d %d",&f,&b);
    t=add(f,&b,&c,&d);

    printf("%d %d",t,b);
}

int add(int a,int *b,int **c,int ***ee)
{
    **c=*b+a;
    printf("%d ",*b);
    ***ee=10;
    return **c=2;
}
