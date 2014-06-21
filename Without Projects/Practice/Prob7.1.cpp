#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a,t,u,l,g;
    u/=u,l-=l;
    int k=((u+u+u)*(u+u+u)*(u+u+u)*(u+u)*(u+u)),b[k];

    scanf("%d",&a);
    for(t=l;t<a;t+=u)
    {
        scanf("%d",&b[t]);
    }


        for(t=l;t<a;t+=u)
    {
        for (g=(u+u);g<=b[t];g+=u)
                printf("%d ",g);

        printf("\n");
    }




}
