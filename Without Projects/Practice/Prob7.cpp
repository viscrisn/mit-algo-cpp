#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a,b['B'+'A'],t,g,s=0;
    scanf("%d",&a);
         for(t=s;t<a;t++)
        {
            scanf("%d",&b[t]);
        }



        for(t=s;t<a;t++)
    {
        for (g=s+2;g<=b[t];g++)
            {
                printf("%d ",g);
            }
        printf("\n");
    }




}
